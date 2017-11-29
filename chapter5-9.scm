;; 5.37
;; また微妙に違うコンパイラをこさえるのか。 こさえた↓ 
(load "./code_from_text/ch5-compiler-do-not-optimize-preserving.scm")
(use slib)
(require 'pretty-print)
(define pp pretty-print)
(pp (compile
 '(define (f x)
    (+ x 1 2))
 'val
 'next))

;; 結果。
;; ((continue env)
;;  (val)
;;  ((save continue)
;;   (save env)
;;   (save continue)
;;   (assign
;;     val
;;     (op make-compiled-procedure)
;;     (label entry1)
;;     (reg env))
;;   (restore continue)
;;   (goto (label after-lambda2))
;;   entry1
;;   (assign
;;     env
;;     (op compiled-procedure-env)
;;     (reg proc))
;;   (assign
;;     env
;;     (op extend-environment)
;;     (const (x))
;;     (reg argl)
;;     (reg env))
;;   (save continue)
;;   (save env)
;;   (save continue)
;;   (assign
;;     proc
;;     (op lookup-variable-value)
;;     (const +)
;;     (reg env))
;;   (restore continue)
;;   (restore env)
;;   (restore continue)
;;   (save continue)
;;   (save proc)
;;   (save env)
;;   (save continue)
;;   (assign val (const 2))
;;   (restore continue)
;;   (assign argl (op list) (reg val))
;;   (restore env)
;;   (save env)
;;   (save argl)
;;   (save continue)
;;   (assign val (const 1))
;;   (restore continue)
;;   (restore argl)
;;   (assign argl (op cons) (reg val) (reg argl))
;;   (restore env)
;;   (save argl)
;;   (save continue)
;;   (assign
;;     val
;;     (op lookup-variable-value)
;;     (const x)
;;     (reg env))
;;   (restore continue)
;;   (restore argl)
;;   (assign argl (op cons) (reg val) (reg argl))
;;   (restore proc)
;;   (restore continue)
;;   (test (op primitive-procedure?) (reg proc))
;;   (branch (label primitive-branch3))
;;   compiled-branch4
;;   (assign
;;     val
;;     (op compiled-procedure-entry)
;;     (reg proc))
;;   (goto (reg val))
;;   primitive-branch3
;;   (save continue)
;;   (assign
;;     val
;;     (op apply-primitive-procedure)
;;     (reg proc)
;;     (reg argl))
;;   (restore continue)
;;   (goto (reg continue))
;;   after-call5
;;   after-lambda2
;;   (restore env)
;;   (perform
;;     (op define-variable!)
;;     (const f)
;;     (reg val)
;;     (reg env))
;;   (assign val (const ok))
;;   (restore continue)))
;; すごい数のsaveとrestoreができた! ということがわかったのでこれでいいのかな。

;; 5.38
;; また新しいコンパイラ作るのか。今回はちょい大変そう
;; ていうか a. の問題は意味があんま良くわからない
(+ (+ 1 2) (- 3 4))
;; みたいなのがあるときに、いいかんじにしてほしいってことだとは思う。
;; 結果はarg1とarg2に入れればいいので、任意の数のoperandには対応しなくてよさそう
;; こんなかな。
(define (spread-arguments operand1 operand2)
  (preserving '(env continue)
              (compile operand1 'arg1 'next)
              (compile operand2 'arg2 'next)))


;; b
;; 基底のschemeのやつ使える？ をこさえる
(define (open-code-operation? exp)
  (or (tagged-list? exp '=)
      (tagged-list? exp '*)
      (tagged-list? exp '-)
      (tagged-list? exp '+)))

;; compileに追加
(define (compile exp target linkage)
  (cond ((self-evaluating? exp)
         (compile-self-evaluating exp target linkage))
        ((quoted? exp) (compile-quoted exp target linkage))
        ((variable? exp)
         (compile-variable exp target linkage))
        ((assignment? exp)
         (compile-assignment exp target linkage))
        ;; なんとなくこのへんに追加 たぶんapplicationより前ならOK begin
        ((open-code-operation? exp)
         (compile-open-code exp target linkage))
        ;; なんとなくこのへんに追加 end
        ((definition? exp)
         (compile-definition exp target linkage))
        ((if? exp) (compile-if exp target linkage))
        ((lambda? exp) (compile-lambda exp target linkage))
        ((begin? exp)
         (compile-sequence (begin-actions exp)
                           target
                           linkage))
        ((cond? exp) (compile (cond->if exp) target linkage))
        ((application? exp)
         (compile-application exp target linkage))
        (else
         (error "Unknown expression type -- COMPILE" exp))))

;; んでその compile-open-codeをこさえる(compile-procedure-callから必要なところを拾ってくるかんじ)
;; ざっくり。
(define (compile-open-code exp target linkage)
  (let* ((op1 (cadr exp)) ;; めんどいので
         (op2 (caddr exp))
         (proc-code (compile (operator exp) 'proc 'next)))
    (end-with-linkage linkage
      (append-instruction-sequences
        (spread-arguments op1 op2)
        proc-code
        (make-instruction-sequence '(proc arg1 arg2)
                                    (list target)
                                    `((assign ,target
                                              (op apply-primitive-procedure)
                                              (reg proc)
                                              (reg arg1)
                                              (reg arg2))))))))

;; つーのを組みこんだやつをこさえた。
;; 組んでみたら色々理解してないことが判明したのでだいぶ戦った。
(load "./code_from_text/ch5-compiler-opencode.scm")
(use slib)
(require 'pretty-print)
(define pp pretty-print)
(pp (compile
 '(+ 1 2)
 'val
 'next))
;; こんなのが出たからいいようなきがする
;; ((env)
;;  (arg1 arg2 proc val)
;;  ((assign arg1 (const 1))
;;   (assign arg2 (const 2))
;;   (assign
;;     proc
;;     (op lookup-variable-value)
;;     (const +)
;;     (reg env))
;;   (assign
;;     val
;;     (op apply-primitive-procedure)
;;     (reg proc)
;;     (reg arg1)
;;     (reg arg2))))


;; c factorialる
(pp (compile
     '(define (factorial n)
        (if (= n 1)
            1
            (* (factorial (- n 1)) n)))
     'val
     'next ))
;; ((env)
;;  (val)
;;  ((assign
;;     val
;;     (op make-compiled-procedure)
;;     (label entry1)
;;     (reg env))
;;   (goto (label after-lambda2))
;;   entry1
;;   (assign
;;     env
;;     (op compiled-procedure-env)
;;     (reg proc))
;;   (assign
;;     env
;;     (op extend-environment)
;;     (const (n))
;;     (reg argl)
;;     (reg env))
;;   (assign
;;     arg1
;;     (op lookup-variable-value)
;;     (const n)
;;     (reg env))
;;   (assign arg2 (const 1))
;;   (assign
;;     proc
;;     (op lookup-variable-value)
;;     (const =)
;;     (reg env))
;;   (assign
;;     val
;;     (op apply-primitive-procedure)
;;     (reg proc)
;;     (reg arg1)
;;     (reg arg2))
;;   (test (op false?) (reg val))
;;   (branch (label false-branch4))
;;   true-branch3
;;   (assign val (const 1))
;;   (goto (reg continue))
;;   false-branch4
;;   (save continue)
;;   (save env)
;;   (assign
;;     proc
;;     (op lookup-variable-value)
;;     (const factorial)
;;     (reg env))
;;   (save proc)
;;   (assign
;;     arg1
;;     (op lookup-variable-value)
;;     (const n)
;;     (reg env))
;;   (assign arg2 (const 1))
;;   (assign
;;     proc
;;     (op lookup-variable-value)
;;     (const -)                            
;;     (reg env))                          
;;   (assign                                  
;;     val                                 ;;       たとえば
;;     (op apply-primitive-procedure)      ;;       こういうのが
;;     (reg proc)                          ;;       めちゃ
;;     (reg arg1)                          ;;       高速に
;;     (reg arg2))                         ;;       なってる
;;   (assign argl (op list) (reg val))
;;   (restore proc)
;;   (test (op primitive-procedure?) (reg proc)) ;; ここは factorialを再帰で呼ぶとこなのでしょうがない
;;   (branch (label primitive-branch6))
;;   compiled-branch7
;;   (assign continue (label proc-return9))
;;   (assign
;;     val
;;     (op compiled-procedure-entry)
;;     (reg proc))
;;   (goto (reg val))
;;   proc-return9
;;   (assign arg1 (reg val))
;;   (goto (label after-call8))
;;   primitive-branch6
;;   (assign
;;     arg1
;;     (op apply-primitive-procedure)
;;     (reg proc)
;;     (reg argl))
;;   after-call8
;;   (restore env)
;;   (assign
;;     arg2
;;     (op lookup-variable-value)
;;     (const n)
;;     (reg env))
;;   (assign
;;     proc
;;     (op lookup-variable-value)
;;     (const *)
;;     (reg env))
;;   (assign
;;     val
;;     (op apply-primitive-procedure)
;;     (reg proc)
;;     (reg arg1)
;;     (reg arg2))
;;   (restore continue)
;;   (goto (reg continue))
;;   after-if5
;;   after-lambda2
;;   (perform
;;     (op define-variable!)
;;     (const factorial)
;;     (reg val)
;;     (reg env))
;;   (assign val (const ok))))
