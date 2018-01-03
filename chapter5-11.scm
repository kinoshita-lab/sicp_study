;; 5.5.7 コンパイル済みコードと評価器の接続
(load "./code_from_text/ch5-eceval-compiler.scm")
(compile-and-go
 '(define (factorial n)
    (if (= n 1)
        1
        (* (factorial (- n 1)) n))))
;; 5.45
;; --------------------------
;; 5.27ではこんな感じだった。
;; (define (factorial n)
;;   (if (= n 1) 1 (* (factorial (- n 1)) n)))
;; ;; (total-pushes = 3 maximum-depth = 3)
;; (factorial 1)
;; ;; (total-pushes = 16 maximum-depth = 8)
;; (factorial 2)
;; ;; (total-pushes = 48 maximum-depth = 13)
;; (factorial 3)
;; ;; (total-pushes = 80 maximum-depth = 18)
;; (factorial 4)
;; ;; (total-pushes = 112 maximum-depth = 23)
;; ;; push(n) = 16 + 32 * (n - 1)
;; ;; max(n) = 8 + 5 * (n - 1)
;; --------------------------
;; ラッキーなことに(？) code_from_textの eceval-compilerはstackのpushとmaxを表示してくれる。
;; 同じように実行して試してみる。
;; eceval-compilerでの実行結果
;; (factorial 1)
;; (total-pushes = 7 maximum-depth = 3)

;; (factorial 2)
;; (total-pushes = 13 maximum-depth = 5)

;; (factorial 3)
;; (total-pushes = 19 maximum-depth = 8)

;; (factorial 4)
;; (total-pushes = 25 maximum-depth = 11)

;; (factorial 5)
;; (total-pushes = 31 maximum-depth = 14)
push(n) = 7 + 6 * (n - 1)
max(n) = 3                  (n=1のとき)
max(n) = 5 + 3 * (n-2)      (n >= 2)



pushのほう

 lim        7 +  6(n - 1)
          ----------------   = 3/16       
n->inf     16 + 32(n - 1)

maxのほう

 lim        5 +  3(n - 2)
          ----------------   = 3/5
n->inf      8 +  5(n - 1)

というかんじになった。
コンパイラすげー。

;; b
;; 言ってることがよくわかんないし、そうする必要はまったくないのだけど、
;; 最適化してるとこをなくせばいいんだよね。
;; これまでやってきたことを全部なくせばいいのではないか。
;; 全部のレジスタを退避
;; 毎回stackを使いまくる
;; というのをlinkageにかかわらずやる
;; open codeとかもなし
;; ってやったらものすごく重いコンパイル結果が出るとおもう。

;; 5.46
;; fibもやるのね。
;; 5.29のときはこんなでした
;; (fib 2)
;; (total-pushes = 72 maximum-depth = 13)
;; (fib 3)
;; (total-pushes = 128 maximum-depth = 18)
;; (fib 4)
;; (total-pushes = 240 maximum-depth = 23)
;; (fib 5)
;; (total-pushes = 408 maximum-depth = 28)
;; a. max(n) = 13 + 5 * (n - 1)
;; b.
;; total(n) = total(n - 1) + total(n - 2) + k
;; n = 5 の場合だと、
;; total(5) = total(4) + total(3) + k
;; 408 = 240 + 128 + k
;; k = 40
;; n = 6で試してみる
;; (fib 6)
;; (total-pushes = 688 maximum-depth = 33)
;; 408 + 240 + 40 = 688
;; 肝心なとこ拾ってくると
;; a. max(n) = 13 + 5 * (n - 1)
;; b. total(n) = total(n - 1) + total(n - 2) + 40
(load "./code_from_text/ch5-eceval-compiler.scm")
(compile-and-go
 '(define (fib n)
  (if (< n 2)
      n
      (+ (fib (- n 1)) (fib (- n 2))))))

;; (fib 0) -> (total-pushes =   7 maximum-depth =  3)
;; (fib 1) -> (total-pushes =   7 maximum-depth =  3)
;; (fib 2) -> (total-pushes =  17 maximum-depth =  5)
;; (fib 3) -> (total-pushes =  27 maximum-depth =  8)
;; (fib 4) -> (total-pushes =  47 maximum-depth = 11)
;; (fib 5) -> (total-pushes =  77 maximum-depth = 14)
;; (fib 6) -> (total-pushes = 127 maximum-depth = 17)
;; (fib 7) -> (total-pushes = 207 maximum-depth = 20)
;; push n >= 2のとき push - 7は
;; 10 20 30 50 80... ;; fibだ
push(n) = push(n-1) + push(n-2) + 7 ;; これは線形にならない
max(n) = 5 + 3 * (n - 2)

;; 5.47
;;;; (3) support for compiled code to call interpreted code (exercise 5.47) --
;;;;     (new register and 1 new instruction at start)
;; もうやってあるやつかこれ ー> ecevalのとこだけやってあった
;; compile-procedure-callとかはcompilerの方だった
;; この段階でどうなるか？ をためした。
(load "./code_from_text/ch5-eceval-compiler.scm")
;; コードをテストするには、まず手続き g を呼ぶ手続き f を定義する。
;; はい。
(compile-and-go
 '(define (f x)
  (g x)))
;; (total-pushes = 0 maximum-depth = 0)
;;; EC-Eval value:
;; ok

;;; EC-Eval input:
(define (g x) x)

;; (total-pushes = 3 maximum-depth = 3)
;; ;;; EC-Eval value:
;; ok
;;; EC-Eval input:
;; (f 1)
;; *** ERROR: pair required, but got x
;; 0  (cdr inst)
;;       at "./code_from_text/ch5-regsim-orig.scm":212
;; 1  (instruction-execution-proc (car insts))
;;       at "./code_from_text/ch5-regsim-orig.scm":139
;; 2  ((instruction-execution-proc (car insts)))
;;       at "./code_from_text/ch5-regsim-orig.scm":139
;; 3  (eval expr env)
;;       at "/usr/share/gauche-0.9/0.9.6_pre2/lib/gauche/interactive.scm":284
;; だめだったということやな。
;; エラーがregsimの方で出てるのはなぜだろう。コンパイル結果が欲しいやつじゃなかったということだな。
;; compile-procedure-callはいつ呼ばれてるかというとcompile-and-goのとき。
(load "./code_from_text/ch5-eceval-compiler.scm") ;; ロードしといて
;; うわがき。
(define (compile-procedure-call target linkage)
  (let ((primitive-branch (make-label 'primitive-branch))
        (compiled-branch (make-label 'compiled-branch))
        (compound-branch (make-label 'compound-branch)) ;; これ足した
        (after-call (make-label 'after-call)))
    (let ((compiled-linkage
           (if (eq? linkage 'next) after-call linkage)))
      (append-instruction-sequences
       (make-instruction-sequence '(proc) '()
                                  `((test (op primitive-procedure?) (reg proc))
                                    (branch (label ,primitive-branch))
                                    (test (op compound-procedure?) (reg proc)) ;; これ足した
                                    (branch (label ,compound-branch))))         ;; これ足した
       (parallel-instruction-sequences
        (parallel-instruction-sequences             ;; これ必要だった
         (append-instruction-sequences
          compound-branch                                          ;; これ足した
          (compile-compound-proc-appl target compiled-linkage))    ;; これ足した
         (append-instruction-sequences
          compiled-branch
          (compile-proc-appl target compiled-linkage)))
        (append-instruction-sequences
         primitive-branch
         (end-with-linkage linkage
                           (make-instruction-sequence '(proc argl)
                                                      (list target)
                                                      `((assign ,target
                                                                (op apply-primitive-procedure)
                                                                (reg proc)
                                                                (reg argl))))))) 
                                  after-call))))
  
;; compile-compound-proc-applをこさえる 謎だったのでこちらまるごと参考にした
;; http://wat-aro.hatenablog.com/entry/2016/02/10/173919
(define (compile-compound-proc-appl target linkage)
  (cond ((and (eq? target 'val) (not (eq? linkage 'return)))
         (make-instruction-sequence
          '() all-regs
          `((assign continue (label ,linkage))
            (save continue)
            (goto (reg compapp)))))
        ((and (not (eq? target 'val))
              (not (eq? linkage 'return)))
         (let ((proc-return (make-label 'proc-return)))
           (make-instruction-sequence
            '(proc) all-regs
            `((assign continue (label ,proc-return))
              (save continue)
              (goto (reg compapp))
              ,proc-return
              (assign ,target (reg val))
              (goto (label ,linkage))))))
        ((and (eq? target 'val) (eq? linkage 'return))
         (make-instruction-sequence
          '(proc continue) all-regs
          `((save continue)
            (goto (reg compapp)))))
        ((and (not (eq? target 'val)) (eq? linkage 'return))
         (error "return linkage, target not val -- COMPILE" target))))

;; 試
(compile-and-go
 '(define (f x)
  (g x)))
;; (total-pushes = 0 maximum-depth = 0)
;;; EC-Eval value:
;; ok

;;; EC-Eval input:
(define (g x) x)

;; (total-pushes = 3 maximum-depth = 3)
;; ;;; EC-Eval value:
;; ok
;;; EC-Eval input:
;; (f 1)
;;; EC-Eval value:
1

;;;;;;;;;;; 5.48
;; compile-and-go的なものをEC-Evalの内部的にできるやつを作ればいいのだろう
;; これをつくっといて
(define (compile-and-run expression)
  (let ((instructions
         (assemble (statements
                    (compile expression 'val 'return))
                   eceval)))
    (set-register-contents! eceval 'val instructions)
    (set-register-contents! eceval 'flag true) ;; resume用と思ってfalseにしたら動かなくなった いみふ
    (start eceval)))

;; eval-dispatchから呼べるようにする
(define (compile-and-run? p)
  (tagged-list? p 'compile-and-run))

;; ロード
(load "./code_from_text/ch5-eceval-compiler.scm")
;;; EC-Eval input:
(compile-and-run
 '(define (factorial n)
    (if (= n 1) 1 (* (factorial (- n 1)) n))))

;;; EC-Eval value:
ok

;;; EC-Eval input:
(factorial 1)
;; (total-pushes = 7 maximum-depth = 3)
;;; EC-Eval value:
1


;;  5.49 問題の意味がよくわかりません!!
;; Read Eval Apply Loopじゃなくて
;; Read Compile Apply Loop的なことかしら？
;; 5.48に毛がはえたくらいでなんとかならないかな。
;; さすがに replにcompile-and-run入れただけだとだめだった。
;; てか呼ぶたびに環境resetしちゃうからだめなんだなこれは。
;; コンパイルするだけ みたいなのをつくってみた
(define (compile-and-assemble-only expression)
  (assemble (statements
             (compile expression 'val 'return))
            eceval))
(load "./code_from_text/ch5-eceval-compiler.scm")

(define eceval
  (make-machine
   '(exp env val proc argl continue unev
	 compapp			;*for compiled to call interpreted
	 )
   eceval-operations
  '(
;;SECTION 5.4.4, as modified in 5.5.7
;;*for compiled to call interpreted (from exercise 5.47)
  (assign compapp (label compound-apply))
;;*next instruction supports entry from compiler (from section 5.5.7)
  (branch (label external-entry))
read-eval-print-loop
  (perform (op initialize-stack))
  (perform
   (op prompt-for-input) (const ";;; EC-Eval input:"))
  (assign exp (op read))
  (assign env (op get-global-environment))
  (assign continue (label print-result))
  ;; (goto (label eval-dispatch)) ;; これやめて for 5.49
  (assign val (op compile-and-assemble-only) (reg exp));; こうしてみる for 5.49
  (assign continue (label print-result)) ;; こうしてみる for 5.49
  (goto (reg val))
print-result
;;**following instruction optional -- if use it, need monitored stack
  (perform (op print-stack-statistics))
  (perform
   (op announce-output) (const ";;; EC-Eval value:"))
  (perform (op user-print) (reg val))
  (goto (label read-eval-print-loop))

;;*support for entry from compiler (from section 5.5.7)
external-entry
  (perform (op initialize-stack))
  (assign env (op get-global-environment))
  (assign continue (label print-result))
  (goto (reg val))

unknown-expression-type
  (assign val (const unknown-expression-type-error))
  (goto (label signal-error))

unknown-procedure-type
  (restore continue)
  (assign val (const unknown-procedure-type-error))
  (goto (label signal-error))

signal-error
  (perform (op user-print) (reg val))
  (goto (label read-eval-print-loop))

;;SECTION 5.4.1
eval-dispatch
  (test (op self-evaluating?) (reg exp))
  (branch (label ev-self-eval))
  (test (op variable?) (reg exp))
  (branch (label ev-variable))
  (test (op quoted?) (reg exp))
  (branch (label ev-quoted))
  (test (op assignment?) (reg exp))
  (branch (label ev-assignment))
  (test (op definition?) (reg exp))
  (branch (label ev-definition))
  (test (op if?) (reg exp))
  (branch (label ev-if))
  (test (op lambda?) (reg exp))
  (branch (label ev-lambda))
  (test (op begin?) (reg exp))
  (branch (label ev-begin))
  (test (op application?) (reg exp))
  (branch (label ev-application))
  (goto (label unknown-expression-type))
ev-self-eval
  (assign val (reg exp))
  (goto (reg continue))
ev-variable
  (assign val (op lookup-variable-value) (reg exp) (reg env))
  (goto (reg continue))
ev-quoted
  (assign val (op text-of-quotation) (reg exp))
  (goto (reg continue))
ev-lambda
  (assign unev (op lambda-parameters) (reg exp))
  (assign exp (op lambda-body) (reg exp))
  (assign val (op make-procedure)
              (reg unev) (reg exp) (reg env))
  (goto (reg continue))

ev-application
  (save continue)
  (save env)
  (assign unev (op operands) (reg exp))
  (save unev)
  (assign exp (op operator) (reg exp))
  (assign continue (label ev-appl-did-operator))
  (goto (label eval-dispatch))
ev-appl-did-operator
  (restore unev)
  (restore env)
  (assign argl (op empty-arglist))
  (assign proc (reg val))
  (test (op no-operands?) (reg unev))
  (branch (label apply-dispatch))
  (save proc)
ev-appl-operand-loop
  (save argl)
  (assign exp (op first-operand) (reg unev))
  (test (op last-operand?) (reg unev))
  (branch (label ev-appl-last-arg))
  (save env)
  (save unev)
  (assign continue (label ev-appl-accumulate-arg))
  (goto (label eval-dispatch))
ev-appl-accumulate-arg
  (restore unev)
  (restore env)
  (restore argl)
  (assign argl (op adjoin-arg) (reg val) (reg argl))
  (assign unev (op rest-operands) (reg unev))
  (goto (label ev-appl-operand-loop))
ev-appl-last-arg
  (assign continue (label ev-appl-accum-last-arg))
  (goto (label eval-dispatch))
ev-appl-accum-last-arg
  (restore argl)
  (assign argl (op adjoin-arg) (reg val) (reg argl))
  (restore proc)
  (goto (label apply-dispatch))
apply-dispatch
  (test (op primitive-procedure?) (reg proc))
  (branch (label primitive-apply))
  (test (op compound-procedure?) (reg proc))  
  (branch (label compound-apply))
;;*next added to call compiled code from evaluator (section 5.5.7)
  (test (op compiled-procedure?) (reg proc))  
  (branch (label compiled-apply))
  (goto (label unknown-procedure-type))

;;*next added to call compiled code from evaluator (section 5.5.7)
compiled-apply
  (restore continue)
  (assign val (op compiled-procedure-entry) (reg proc))
  (goto (reg val))

primitive-apply
  (assign val (op apply-primitive-procedure)
              (reg proc)
              (reg argl))
  (restore continue)
  (goto (reg continue))

compound-apply
  (assign unev (op procedure-parameters) (reg proc))
  (assign env (op procedure-environment) (reg proc))
  (assign env (op extend-environment)
              (reg unev) (reg argl) (reg env))
  (assign unev (op procedure-body) (reg proc))
  (goto (label ev-sequence))

;;;SECTION 5.4.2
ev-begin
  (assign unev (op begin-actions) (reg exp))
  (save continue)
  (goto (label ev-sequence))

ev-sequence
  (assign exp (op first-exp) (reg unev))
  (test (op last-exp?) (reg unev))
  (branch (label ev-sequence-last-exp))
  (save unev)
  (save env)
  (assign continue (label ev-sequence-continue))
  (goto (label eval-dispatch))
ev-sequence-continue
  (restore env)
  (restore unev)
  (assign unev (op rest-exps) (reg unev))
  (goto (label ev-sequence))
ev-sequence-last-exp
  (restore continue)
  (goto (label eval-dispatch))

;;;SECTION 5.4.3

ev-if
  (save exp)
  (save env)
  (save continue)
  (assign continue (label ev-if-decide))
  (assign exp (op if-predicate) (reg exp))
  (goto (label eval-dispatch))
ev-if-decide
  (restore continue)
  (restore env)
  (restore exp)
  (test (op true?) (reg val))
  (branch (label ev-if-consequent))
ev-if-alternative
  (assign exp (op if-alternative) (reg exp))
  (goto (label eval-dispatch))
ev-if-consequent
  (assign exp (op if-consequent) (reg exp))
  (goto (label eval-dispatch))

ev-assignment
  (assign unev (op assignment-variable) (reg exp))
  (save unev)
  (assign exp (op assignment-value) (reg exp))
  (save env)
  (save continue)
  (assign continue (label ev-assignment-1))
  (goto (label eval-dispatch))
ev-assignment-1
  (restore continue)
  (restore env)
  (restore unev)
  (perform
   (op set-variable-value!) (reg unev) (reg val) (reg env))
  (assign val (const ok))
  (goto (reg continue))

ev-definition
  (assign unev (op definition-variable) (reg exp))
  (save unev)
  (assign exp (op definition-value) (reg exp))
  (save env)
  (save continue)
  (assign continue (label ev-definition-1))
  (goto (label eval-dispatch))
ev-definition-1
  (restore continue)
  (restore env)
  (restore unev)
  (perform
   (op define-variable!) (reg unev) (reg val) (reg env))
  (assign val (const ok))
  (goto (reg continue))
   )))


;;; EC-Eval input:
(+ 1 1)

(total-pushes = 0 maximum-depth = 0)
;;; EC-Eval value:
2
;; できた(気がする)
;; external-entry のときとやってることはほとんど同じ
