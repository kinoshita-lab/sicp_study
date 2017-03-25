;; 5.2 レジスタマシンシミュレータ
;; これは実物があるっぽいので入れといた。
(define true #t)
(define false #f)
(load "./code_from_text/ch5-regsim.scm")

(define gcd-machine
  (make-machine
   '(a b t)
   (list (list 'rem remainder ) (list '= =))
   '(test-b (test (op =) (reg b) ( const 0))
			(branch (label gcd-done))
			(assign t (op rem) (reg a) (reg b))
			(assign a (reg b))
			(assign b (reg t))
			(goto (label test-b ))
			gcd-done)))
(set-register-contents! gcd-machine 'a 206)
(set-register-contents! gcd-machine 'b 40)
(start gcd-machine)
(get-register-contents gcd-machine 'a)
;; gosh> 2
;; おお動いた!


;; 5.6
(define recurcive-expt
  (make-machine
   '(b n continue val)
   (list (list '* *) (list '= =) (list '- -))
   '((assign continue (label expt-done)) 
	 expt-loop
	 (test (op =) (reg n) (const 0))
	 (branch (label base-case))
	 (save continue)
	 (save n)
	 (assign n (op -) (reg n) (const 1))
	 (assign continue (label after-expt))
	 (goto (label expt-loop))
	 after-expt
	 (restore n)
	 (restore continue)
	 (assign val (op *) (reg b) (reg val)) 
	 (goto (reg continue))
	 base-case
	 (assign val (const 1))
	 (goto (reg continue))
	 expt-done)))
(set-register-contents! recurcive-expt 'b 2)
(set-register-contents! recurcive-expt 'n 10)
(start recurcive-expt)
(get-register-contents recurcive-expt 'val)
;; gosh> 1024

(define expt-iter-machine
  (make-machine
   '(b counter product)
   (list (list '* *) (list '= =) (list '- -))
   '(
	 (assign product (const 1))
	 expt-iter-loop
	 (test (op =) (reg counter) (const 0))
	 (branch (label expt-done))
	 (assign product (op *) (reg b) (reg product))
	 (assign counter (op -) (reg counter) (const 1))
	(goto (label expt-iter-loop))
	expt-done
	)))
(set-register-contents! expt-iter-machine 'b 2)
(set-register-contents! expt-iter-machine 'counter 10)
(start expt-iter-machine)
(get-register-contents expt-iter-machine 'product)
;; gosh> 1024
