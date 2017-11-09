;; コンパイラであそんでみる
(load "./code_from_text/ch5-compiler.scm")
(compile
 '(define (factorial n)
    (if (= n 1)
        (* (factorial (- n 1)) n)))
 'val
 'next)

;; 悲惨なかたまりがでてきた
;; ((env) (val) ((assign val (op make-compiled-procedure) (label entry1) (reg env)) (goto (label after-lambda2)) entry1 (assign env (op compiled-procedure-env) (reg proc)) (assign env (op extend-environment) (const (n)) (reg argl) (reg env)) (save continue) (save env) (assign proc (op lookup-variable-value) (const =) (reg env)) (assign val (const 1)) (assign argl (op list) (reg val)) (assign val (op lookup-variable-value) (const n) (reg env)) (assign argl (op cons) (reg val) (reg argl)) (test (op primitive-procedure?) (reg proc)) (branch (label primitive-branch6)) compiled-branch7 (assign continue (label after-call8)) (assign val (op compiled-procedure-entry) (reg proc)) (goto (reg val)) primitive-branch6 (assign val (op apply-primitive-procedure) (reg proc) (reg argl)) after-call8 (restore env) (restore continue) (test (op false?) (reg val)) (branch (label false-branch4)) true-branch3 (assign proc (op lookup-variable-value) (const *) (reg env)) (save continue) (save proc) (assign val (op lookup-variable-value) (const n) (reg env)) (assign argl (op list) (reg val)) (save argl) (assign proc (op lookup-variable-value) (const factorial) (reg env)) (save proc) (assign proc (op lookup-variable-value) (const -) (reg env)) (assign val (const 1)) (assign argl (op list) (reg val)) (assign val (op lookup-variable-value) (const n) (reg env)) (assign argl (op cons) (reg val) (reg argl)) (test (op primitive-procedure?) (reg proc)) (branch (label primitive-branch9)) compiled-branch10 (assign continue (label after-call11)) (assign val (op compiled-procedure-entry) (reg proc)) (goto (reg val)) primitive-branch9 (assign val (op apply-primitive-procedure) (reg proc) (reg argl)) after-call11 (assign argl (op list) (reg val)) (restore proc) (test (op primitive-procedure?) (reg proc)) (branch (label primitive-branch12)) compiled-branch13 (assign continue (label after-call14)) (assign val (op compiled-procedure-entry) (reg proc)) (goto (reg val)) primitive-branch12 (assign val (op apply-primitive-procedure) (reg proc) (reg argl)) after-call14 (restore argl) (assign argl (op cons) (reg val) (reg argl)) (restore proc) (restore continue) (test (op primitive-procedure?) (reg proc)) (branch (label primitive-branch15)) compiled-branch16 (assign val (op compiled-procedure-entry) (reg proc)) (goto (reg val)) primitive-branch15 (assign val (op apply-primitive-procedure) (reg proc) (reg argl)) (goto (reg continue)) after-call17 false-branch4 (assign val (op lookup-variable-value) (const false) (reg env)) (goto (reg continue)) after-if5 after-lambda2 (perform (op define-variable!) (const factorial) (reg val) (reg env)) (assign val (const ok))))

;; pretty printはないのかな。
(use slib)
(require 'pretty-print)
(define pp pretty-print)
(pp (compile
    '(define (factorial n)
       (if (= n 1)
           (* (factorial (- n 1)) n)))
    'val
    'next))

;; いいかんじになった
;; ((env)
;;  (val)
;;  ((assign
;;     val
;;     (op make-compiled-procedure)
;;     (label entry18)
;;     (reg env))
;;   (goto (label after-lambda19))
;;   entry18
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
;;   (save continue)
;;   (save env)
;;   (assign
;;     proc
;;     (op lookup-variable-value)
;;     (const =)
;;     (reg env))
;;   (assign val (const 1))
;;   (assign argl (op list) (reg val))
;;   (assign
;;     val
;;     (op lookup-variable-value)
;;     (const n)
;;     (reg env))
;;   (assign argl (op cons) (reg val) (reg argl))
;;   (test (op primitive-procedure?) (reg proc))
;;   (branch (label primitive-branch23))
;;   compiled-branch24
;;   (assign continue (label after-call25))
;;   (assign
;;     val
;;     (op compiled-procedure-entry)
;;     (reg proc))
;;   (goto (reg val))
;;   primitive-branch23
;;   (assign
;;     val
;;     (op apply-primitive-procedure)
;;     (reg proc)
;;     (reg argl))
;;   after-call25
;;   (restore env)
;;   (restore continue)
;;   (test (op false?) (reg val))
;;   (branch (label false-branch21))
;;   true-branch20
;;   (assign
;;     proc
;;     (op lookup-variable-value)
;;     (const *)
;;     (reg env))
;;   (save continue)
;;   (save proc)
;;   (assign
;;     val
;;     (op lookup-variable-value)
;;     (const n)
;;     (reg env))
;;   (assign argl (op list) (reg val))
;;   (save argl)
;;   (assign
;;     proc
;;     (op lookup-variable-value)
;;     (const factorial)
;;     (reg env))
;;   (save proc)
;;   (assign
;;     proc
;;     (op lookup-variable-value)
;;     (const -)
;;     (reg env))
;;   (assign val (const 1))
;;   (assign argl (op list) (reg val))
;;   (assign
;;     val
;;     (op lookup-variable-value)
;;     (const n)
;;     (reg env))
;;   (assign argl (op cons) (reg val) (reg argl))
;;   (test (op primitive-procedure?) (reg proc))
;;   (branch (label primitive-branch26))
;;   compiled-branch27
;;   (assign continue (label after-call28))
;;   (assign
;;     val
;;     (op compiled-procedure-entry)
;;     (reg proc))
;;   (goto (reg val))
;;   primitive-branch26
;;   (assign
;;     val
;;     (op apply-primitive-procedure)
;;     (reg proc)
;;     (reg argl))
;;   after-call28
;;   (assign argl (op list) (reg val))
;;   (restore proc)
;;   (test (op primitive-procedure?) (reg proc))
;;   (branch (label primitive-branch29))
;;   compiled-branch30
;;   (assign continue (label after-call31))
;;   (assign
;;     val
;;     (op compiled-procedure-entry)
;;     (reg proc))
;;   (goto (reg val))
;;   primitive-branch29
;;   (assign
;;     val
;;     (op apply-primitive-procedure)
;;     (reg proc)
;;     (reg argl))
;;   after-call31
;;   (restore argl)
;;   (assign argl (op cons) (reg val) (reg argl))
;;   (restore proc)
;;   (restore continue)
;;   (test (op primitive-procedure?) (reg proc))
;;   (branch (label primitive-branch32))
;;   compiled-branch33
;;   (assign
;;     val
;;     (op compiled-procedure-entry)
;;     (reg proc))
;;   (goto (reg val))
;;   primitive-branch32
;;   (assign
;;     val
;;     (op apply-primitive-procedure)
;;     (reg proc)
;;     (reg argl))
;;   (goto (reg continue))
;;   after-call34
;;   false-branch21
;;   (assign
;;     val
;;     (op lookup-variable-value)
;;     (const false)
;;     (reg env))
;;   (goto (reg continue))
;;   after-if22
;;   after-lambda19
;;   (perform
;;     (op define-variable!)
;;     (const factorial)
;;     (reg val)
;;     (reg env))
;;   (assign val (const ok))))

;; いきなりfactはハイレベルすぎ もうちょっと簡単なのでためす
;; atom
(pp (compile
     '1
     '()
     'next))
;;  (() (()) ((assign () (const 1))))

;; define
(pp (compile
     '(define a 1)
     '()
     'next))
;; ((env)
;; (val ())
;; ((assign val (const 1))
;;  (perform
;;    (op define-variable!)
;;    (const a)
;;    (reg val)
;;    (reg env))
;;  (assign () (const ok))))
;; envが変更になるし、 valレジスタを使った。
;; lambda
(pp (compile
     '(lambda () ()) ;; なんもしない
     '()
     'next))
;; ERROR: Unknown expression type -- COMPILE () なんもしないのはできないのか。

;; lambda(atomを返す)
(pp (compile
     '(lambda () 1) ;; 1を返す
     '()
     'next))
 ;; ((env)
 ;; (())
 ;; ((assign
 ;;    ()
 ;;    (op make-compiled-procedure)
 ;;    (label entry51)
 ;;    (reg env))
 ;;  (goto (label after-lambda52))
 ;;  entry51
 ;;  (assign
 ;;    env
 ;;    (op compiled-procedure-env)
 ;;    (reg proc))
 ;;  (assign
 ;;    env
 ;;    (op extend-environment)
 ;;    (const ())
 ;;    (reg argl)
 ;;    (reg env))
 ;;  (assign val (const 1))
 ;;  (goto (reg continue))
 ;;  after-lambda52))
;; これ動く？

;; 1を返すlambdaを呼ぶ
(pp (compile
     '((lambda () 1)) ;; 1を返す
     '()
     'next))

;; ((env)
;;  (env proc val argl continue ())
;;  ((assign
;;     proc
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
;;     (const ())
;;     (reg argl)
;;     (reg env))
;;   (assign val (const 1))
;;   (goto (reg continue))
;;   after-lambda2
;;   (assign argl (const ()))
;;   (test (op primitive-procedure?) (reg proc))
;;   (branch (label primitive-branch3))
;;   compiled-branch4
;;   (assign continue (label proc-return6))
;;   (assign
;;     val
;;     (op compiled-procedure-entry)
;;     (reg proc))
;;   (goto (reg val))
;;   proc-return6
;;   (assign () (reg val))
;;   (goto (label after-call5))
;;   primitive-branch3
;;   (assign
;;     ()
;;     (op apply-primitive-procedure)
;;     (reg proc)
;;     (reg argl))
;;   after-call5))

;; 関数をdefine
(pp (compile
     '(define (function a) a)
     '()
     'next))

;; ((env)
;;  (val ())
;;  ((assign
;;     val
;;     (op make-compiled-procedure)
;;     (label entry13)
;;     (reg env))
;;   (goto (label after-lambda14))
;;   entry13
;;   (assign
;;     env
;;     (op compiled-procedure-env)
;;     (reg proc))
;;   (assign
;;     env
;;     (op extend-environment)
;;     (const (a))
;;     (reg argl)
;;     (reg env))
;;   (assign
;;     val
;;     (op lookup-variable-value)
;;     (const a)
;;     (reg env))
;;   (goto (reg continue))
;;   after-lambda14
;;   (perform
;;     (op define-variable!)
;;     (const function)
;;     (reg val)
;;     (reg env))
;;   (assign () (const ok))))

;;
;; 関数の中でschemeの基底関数を呼ぶ
(pp (compile
     '(define (function a)
        (+ a a))
     '()
     'next))

;; ((env)
;;  (val ())
;;  ((assign
;;     val
;;     (op make-compiled-procedure)
;;     (label entry15)
;;     (reg env))
;;   (goto (label after-lambda16))
;;   entry15
;;   (assign
;;     env
;;     (op compiled-procedure-env)
;;     (reg proc))
;;   (assign
;;     env
;;     (op extend-environment)
;;     (const (a))
;;     (reg argl)
;;     (reg env))
;;   (assign
;;     proc
;;     (op lookup-variable-value)
;;     (const +)
;;     (reg env))
;;   (assign
;;     val
;;     (op lookup-variable-value)
;;     (const a)
;;     (reg env))
;;   (assign argl (op list) (reg val))
;;   (assign
;;     val
;;     (op lookup-variable-value)
;;     (const a)
;;     (reg env))
;;   (assign argl (op cons) (reg val) (reg argl))
;;   (test (op primitive-procedure?) (reg proc))
;;   (branch (label primitive-branch17))
;;   compiled-branch18
;;   (assign
;;     val
;;     (op compiled-procedure-entry)
;;     (reg proc))
;;   (goto (reg val))
;;   primitive-branch17
;;   (assign
;;     val
;;     (op apply-primitive-procedure)
;;     (reg proc)
;;     (reg argl))
;;   (goto (reg continue))
;;   after-call19
;;   after-lambda16
;;   (perform
;;     (op define-variable!)
;;     (const function)
;;     (reg val)
;;     (reg env))
;;   (assign () (const ok))))

;; 関数を関数の中でdefine
(pp (compile
     '(define (function a)
        (define (internal b)
          b)
        (internal a))
     '()
     'next))

 ;; ((env)
 ;; (val ())
 ;; ((assign
 ;;    val
 ;;    (op make-compiled-procedure)
 ;;    (label entry20)
 ;;    (reg env))
 ;;  (goto (label after-lambda21))
 ;;  entry20
 ;;  (assign
 ;;    env
 ;;    (op compiled-procedure-env)
 ;;    (reg proc))
 ;;  (assign
 ;;    env
 ;;    (op extend-environment)
 ;;    (const (a))
 ;;    (reg argl)
 ;;    (reg env))
 ;;  (assign
 ;;    val
 ;;    (op make-compiled-procedure)
 ;;    (label entry22)
 ;;    (reg env))
 ;;  (goto (label after-lambda23))
 ;;  entry22
 ;;  (assign
 ;;    env
 ;;    (op compiled-procedure-env)
 ;;    (reg proc))
 ;;  (assign
 ;;    env
 ;;    (op extend-environment)
 ;;    (const (b))
 ;;    (reg argl)
 ;;    (reg env))
 ;;  (assign
 ;;    val
 ;;    (op lookup-variable-value)
 ;;    (const b)
 ;;    (reg env))
 ;;  (goto (reg continue))
 ;;  after-lambda23
 ;;  (perform
 ;;    (op define-variable!)
 ;;    (const internal)
 ;;    (reg val)
 ;;    (reg env))
 ;;  (assign val (const ok))
 ;;  (assign
 ;;    proc
 ;;    (op lookup-variable-value)
 ;;    (const internal)
 ;;    (reg env))
 ;;  (assign
 ;;    val
 ;;    (op lookup-variable-value)
 ;;    (const a)
 ;;    (reg env))
 ;;  (assign argl (op list) (reg val))
 ;;  (test (op primitive-procedure?) (reg proc))
 ;;  (branch (label primitive-branch24))
 ;;  compiled-branch25
 ;;  (assign
 ;;    val
 ;;    (op compiled-procedure-entry)
 ;;    (reg proc))
 ;;  (goto (reg val))
 ;;  primitive-branch24
 ;;  (assign
 ;;    val
 ;;    (op apply-primitive-procedure)
 ;;    (reg proc)
 ;;    (reg argl))
 ;;  (goto (reg continue))
 ;;  after-call26
 ;;  after-lambda21
 ;;  (perform
 ;;    (op define-variable!)
 ;;    (const function)
 ;;    (reg val)
 ;;    (reg env))
 ;;  (assign () (const ok))))

;; クロージャー的なもの
(pp (compile
     '(define (make-counter)
        (let ((count 0))
          (lambda ()
            (set! count (+ count 1))
            count)))
     '()
     'next))

;; ((env)
;;  (val ())
;;  ((assign
;;     val
;;     (op make-compiled-procedure)
;;     (label entry36)
;;     (reg env))
;;   (goto (label after-lambda37))
;;   entry36
;;   (assign
;;     env
;;     (op compiled-procedure-env)
;;     (reg proc))
;;   (assign
;;     env
;;     (op extend-environment)
;;     (const ())
;;     (reg argl)
;;     (reg env))
;;   (assign
;;     proc
;;     (op lookup-variable-value)
;;     (const let) ;; なんかうまくいってない気がする letが関数になってしまった
;;     (reg env))
;;   (save continue)
;;   (save proc)
;;   (assign
;;     val
;;     (op make-compiled-procedure)
;;     (label entry45)
;;     (reg env))
;;   (goto (label after-lambda46))
;;   entry45
;;   (assign
;;     env
;;     (op compiled-procedure-env)
;;     (reg proc))
;;   (assign
;;     env
;;     (op extend-environment)
;;     (const ())
;;     (reg argl)
;;     (reg env))
;;   (save continue)
;;   (save env)
;;   (assign
;;     proc
;;     (op lookup-variable-value)
;;     (const +)
;;     (reg env))
;;   (assign val (const 1))
;;   (assign argl (op list) (reg val))
;;   (assign
;;     val
;;     (op lookup-variable-value)
;;     (const count)
;;     (reg env))
;;   (assign argl (op cons) (reg val) (reg argl))
;;   (test (op primitive-procedure?) (reg proc))
;;   (branch (label primitive-branch47))
;;   compiled-branch48
;;   (assign continue (label after-call49))
;;   (assign
;;     val
;;     (op compiled-procedure-entry)
;;     (reg proc))
;;   (goto (reg val))
;;   primitive-branch47
;;   (assign
;;     val
;;     (op apply-primitive-procedure)
;;     (reg proc)
;;     (reg argl))
;;   after-call49
;;   (restore env)
;;   (perform
;;     (op set-variable-value!)
;;     (const count)
;;     (reg val)
;;     (reg env))
;;   (assign val (const ok))
;;   (restore continue)
;;   (assign
;;     val
;;     (op lookup-variable-value)
;;     (const count)
;;     (reg env))
;;   (goto (reg continue))
;;   after-lambda46
;;   (assign argl (op list) (reg val))
;;   (save argl)
;;   (assign
;;     proc
;;     (op lookup-variable-value)
;;     (const count)
;;     (reg env))
;;   (assign val (const 0))
;;   (assign argl (op list) (reg val))
;;   (test (op primitive-procedure?) (reg proc))
;;   (branch (label primitive-branch38))
;;   compiled-branch39
;;   (assign continue (label proc-return41))
;;   (assign
;;     val
;;     (op compiled-procedure-entry)
;;     (reg proc))
;;   (goto (reg val))
;;   proc-return41
;;   (assign proc (reg val))
;;   (goto (label after-call40))
;;   primitive-branch38
;;   (assign
;;     proc
;;     (op apply-primitive-procedure)
;;     (reg proc)
;;     (reg argl))
;;   after-call40
;;   (assign argl (const ()))
;;   (test (op primitive-procedure?) (reg proc))
;;   (branch (label primitive-branch42))
;;   compiled-branch43
;;   (assign continue (label after-call44))
;;   (assign
;;     val
;;     (op compiled-procedure-entry)
;;     (reg proc))
;;   (goto (reg val))
;;   primitive-branch42
;;   (assign
;;     val
;;     (op apply-primitive-procedure)
;;     (reg proc)
;;     (reg argl))
;;   after-call44
;;   (restore argl)
;;   (assign argl (op cons) (reg val) (reg argl))
;;   (restore proc)
;;   (restore continue)
;;   (test (op primitive-procedure?) (reg proc))
;;   (branch (label primitive-branch50))
;;   compiled-branch51
;;   (assign
;;     val
;;     (op compiled-procedure-entry)
;;     (reg proc))
;;   (goto (reg val))
;;   primitive-branch50
;;   (assign
;;     val
;;     (op apply-primitive-procedure)
;;     (reg proc)
;;     (reg argl))
;;   (goto (reg continue))
;;   after-call52
;;   after-lambda37
;;   (perform
;;     (op define-variable!)
;;     (const make-counter)
;;     (reg val)
;;     (reg env))
;;   (assign () (const ok))))
