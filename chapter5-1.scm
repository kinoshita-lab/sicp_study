;; 5.2
;; レジスタマシン言語を使って練習問題 5.1の反復階乗マシンを記述せよ。
(controller
 (assign p (const 1))
 (assign c (const 1))
 test-b
 (test (op >) (reg c) (reg n))
 (branch (label fact-done))
 (assign t1 (op *) (reg p) (reg c))
 (assign t2 (op +) (reg c) (const 1))
 (assign p (reg t1))
 (assign c (reg t2))
 (goto (label test-b))
 fact-done
 )
;; こんなかな。

;; 5.3
;; 1.1.7 節に示したニュートン法によって平方根を求めるマシンを設計せよ。
(define (sqrt x)
  (define (good-enough? guess)
	(< (abs (- (square guess) x)) 0.001))
  (define (improve guess)
	(average guess (/ x guess)))
  (define (sqrt-iter guess)
	(if (good-enough? guess)
		guess
		(sqrt-iter (improve guess))))
  (sqrt-iter 1.0))

;; good-enough?とimproveが使える版
(controller
 (assign guess (const 1.0))
 (assign x (op read))
 test-good-enough
 (test (op good-enough?) (reg guess))
 (goto (label sqrt-done))
 (assign (reg t) (op improve) (reg guess))
 (assign (reg guess) (reg t))
 (goto test-good-enough)
 sqrt-done
 )

;; good-enough?とimproveを自分で作る版
(controller
 (assign guess (const 1.0))
 (assign x (op read))
 test-good-enough
 ;; good enoughってただの計算じゃね？
 (assign t1 (op *) (reg guess) (reg guess)) ; square
 (assign t2 (op -) (reg t1) (reg x)) ;
 (assign t3 (op abs) (reg t2)) ;; absが使えることにした
 (test (op <) (reg t3) (const 0.001))
 (goto (label sqrt-done))
 ;; improveってただの計算じゃね?
 (assign (reg t) (op /) (reg x) (reg guess))
 (assign (reg guess) (reg t))
 (goto test-good-enough)
 sqrt-done
 )

;; 5.4: 次のそれぞれの手続きを実装するレジスタマシンを
;; 規定せよ。それぞれのマシンについて、コントローラ命令列を書
;; き、データパスを示す図を描け。
;; a. 再帰的指数計算
;; (define (expt b n)
;;   (if (= n 0)
;; 	  1
;; 	  (* b (expt b (- n 1)))))
;; factのをもとにした
(controller
 (assign b (op read))
 (assign n (op read))
 (assign continue (label expt-done)) 
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
 expt-done)
;; b. 反復的指数計算
;; (define (expt b n)
;;   (define (expt-iter counter product)
;; 	(if (= counter 0)
;; 		product
;; 		(expt-iter (- counter 1)
;; 					(* b product))))
;;   (expt-iter n 1))
(controller
 (assign b (op read))
 (assign counter (op read))
 (assign product (const 1))
 expt-iter-loop
 (test (op =) (reg counter) (const 0))
 (goto label expt-done)
 (assign product (op *) (reg b) (reg product))
 (assign counter (op -) (reg counter) (const 1))
 (goto (label expt-iter-loop))
 expt-done
 )


;; 5.5
;;  (fact 3)  くらいで。
;; fact-loop最初に突入して、 (goto (label fact-loop)にきたとき
n <- 3
val <- 未設定
stack <- 3
continue <- fact-done

;; test opが真になって base-caseへ飛ぶとき
n <- 1
val <- 未設定
stack <- 2,3 
continue <- after-fact, after-fact, fact-done

;; base-caseでgoto (reg continue) に来たとき
n <- 1
val <- 1
stack <- 2, 3
continue <- after-fact なので gotoはafter-factへ移動

;; after-factで (goto (reg continue))に来たとき
n <- 2
val <- 2
stack 3
continue <- after-fact, fact-done

;; もう1度after-factがまわって、 (goto (reg continue)) に来たとき
n <- 3
val <- 6
stack 空
continue <- fact-done
;; でfact-doneに飛んで終了。


(fib 4) ;; くらいで。
;; 最初に fib-loop入った時
continue <- fib-done
n <- 4
stack 空
val <= 未設定
;; (goto (label fib-loop)) に最初に来たとき
continue <- afterfib-n-1
stack 4,fib-done
n <- 3
val <- 未設定
;; (goto (label fib-loop)) に次に来たとき
continue <- afterfib-n-1
stack 3, afterfib-n-1, 4,fib-done
n <- 2
val <- 未設定
;; (goto (label fib-loop)) にその次に来たとき
continue <- afterfib-n-1
stack 2, afterfib-n-1, 3, afterfib-n-1, 4, fib-done
n <- 1
;; そのあと immediate-answerに行って (goto (reg continue))に来たとき
val <- 1
;; continue にはafterfib-n-1が入ってるので、 afterfib-n-1へ
;; (restore n)
;; (restore continue) すると
n <- 2
continue <- afterfib-n-1
stack 3, afterfib-n-1, 4, fib-done
n <- 0
continue <- afterfib-n-2
stack 1, afterfib-n-1, 3, afterfib-n-1, 4, fib-done
;; fib-loopへ
;; immediate-answerへ
continueはafterfib-n-2
;; afterfib-n-2
n <- 1
val <- 1
continue <- afterfib-n-1
val <- 2 ;; やっと足した
stack 3, afterfib-n-1, 4, fib-done
;; afterfib-n-1へ
;; ... というかんじで進む。


;; 5.6
afterfib-n-1
; リターン時に Fib(n − 1) は val に入って
(restore n)
(restore continue)
;; Fib(n − 2) を求める準備
(assign n (op -) (reg n) (const 2))
(save continue )
;; ここの restore continue/save continue は同じ値を入れて出してるので不要な操作
