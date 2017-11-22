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
