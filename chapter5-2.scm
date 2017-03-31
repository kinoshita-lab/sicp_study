;; 5.2 レジスタマシンシミュレータ
;; これは実物があるっぽいので入れといた。

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


;; 5.7
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

;; 5.8
;; 適当なmachineを作って、まわしてから考えるとわかりやすいかも。

(define ex58-machine
  (make-machine
   '(a)
   '()
   '(
	 start
	 (goto (label here))
	 here
	 (assign a (const 3))
	 (goto (label there))
	 where
	 (assign a (const 4))
	 (goto (label there))
	 there
	)))

(start ex58-machine)
(get-register-contents ex58-machine 'a) ;; 3だった
;; どこかの時点でラベルが複数あることを検出すればいい気がするがcpsで大変わかりづらい。
;; labelsに入ってるっぽい
;; ((here ((assign a (const 3))) ((goto (label there))) ((assign a (const 4))) ((goto (label there)))) (here ((assign a (const 4))) ((goto (label there)))) (there))
;; のでこんなかんじにした。
(define (extract-labels text receive)
  (if (null? text)
      (receive '() '())
      (extract-labels (cdr text)
       (lambda (insts labels)
         (let ((next-inst (car text)))
           (if (symbol? next-inst) ;; ここがlabelの時来るところ
			   (begin
				 (if (assoc next-inst labels) ;; labelは頭についてるのでそこひっかけて
					 (error "duplicate label name" next-inst) ;; かぶってたらerror
					 (receive insts
						 (cons (make-label-entry next-inst
												 insts)
							   labels))))
               (receive (cons (make-instruction next-inst)
                              insts)
				   labels)))))))


;; 5.9 本当にそうなの？ ってことで 5.8のmachineでためしてみる。
(define ex59-machine
  (make-machine
   '(a)
   (list (list '= =)) ;; これ足してみた
   '(
	 start
	 (goto (label here))
	 here
	 (assign a (const 3))
	 (test (op =) (label here) (label here)) ;; これ足してみた
	 (goto (label there))
	 where
	 (assign a (const 4))
	 (goto (label there))
	 there
	)))
;; > ex59-machine
;; できた。↑を作るときにミスったのでcall stack見えた
;;  1  (make-operation-exp condition machine labels operations)
;;        at "./code_from_text/ch5-regsim.scm":279。
(define (make-operation-exp exp machine labels operations)
  (let ((op (lookup-prim (operation-exp-op exp) operations))
        (aprocs
         (map (lambda (e)
				(if (label-exp? e)
					(error "cannot perform label operation!") ;; 5.9で足した
					(make-primitive-exp e machine labels)))
              (operation-exp-operands exp))))
    (lambda ()
      (apply op (map (lambda (p) (p)) aprocs)))))
;; こうやってから実行すると
;; gosh> *** ERROR: cannot perform label operation!

;; 5.10
;; 構文って何よ？
;; make-execution-procedureで定義してるやつだとおもう
;; レジスタの0クリアでもつくってみるか ってことで実装の方をいじった。
(define ex510-machine
  (make-machine
   '(a)
   (list (list '= =)) ;; これ足してみた
   '(
	 start
	 (assign a (const 3))
	 (clear a)
	 there
	)))
(start ex510-machine)
(get-register-contents ex510-machine 'a)
;; 0だった
