;; 5.20 絵かいた。
;; freeはindex 3のところにいるとおもう。

;; 5.21 fibっぽくやればいいのかな。
;; ってところでfibをあんまり理解してないのが露呈した
;; せっかくなのでtraceして動きを確認。
(load "./code_from_text/ch5-regsim.scm")
(load "./chapter5-fib-machine.scm")

;; fib-machine
(fib-machine 'trace-on)
(set-register-trace-on fib-machine 'n)
(set-register-trace-off fib-machine 'continue)
(set-register-trace-on fib-machine 'val)
(set-register-contents! fib-machine 'n 4)

(start fib-machine)

;; start entry point
;; (trace: 1 (assign continue (label fib-done)))
;; 最後はfib-doneに飛びたいのでcontinueに入れておく。

;; fib-loop ;; fib(n-1) を求めようとするところ
;; (trace: 2 (test (op <) (reg n) (const 2)))
;; (trace: 3 (branch (label immediate-answer))) ;; 4だと求められないので
;; (trace: 4 (save continue)) ;; もどり先を保存した上で
;; (trace: 5 (assign continue (label afterfib-n-1))) ;; fib(n-1) を1回やりたい
;; (trace: 6 (save n)) ; nを保存
;; (trace: 7 (assign n (op -) (reg n) (const 1)))  ;; n-1ならもとめられるかも？
;(reg  n : 4  ->  3)
;; (trace: 8 (goto (label fib-loop))) ; ってことで再帰

;; fib-loop
;; (trace: 9 (test (op <) (reg n) (const 2)))
;; (trace: 10 (branch (label immediate-answer)))  ;; 3も求められない 
;; (trace: 11 (save continue))
;; (trace: 12 (assign continue (label afterfib-n-1))) ;; fib(n-1) を1回やりたい
;; (trace: 13 (save n)) ; nを保存
;; (trace: 14 (assign n (op -) (reg n) (const 1))) ; n-1ならもとめられるかも？
;(reg  n : 3  ->  2)
;; (trace: 15 (goto (label fib-loop)))

;; fib-loop
;; (trace: 16 (test (op <) (reg n) (const 2)))
;; (trace: 17 (branch (label immediate-answer))) ;; 2も求められない
;; (trace: 18 (save continue))
;; (trace: 19 (assign continue (label afterfib-n-1))) ;; fib(n-1) を1回やりたい
;; (trace: 20 (save n))
;; (trace: 21 (assign n (op -) (reg n) (const 1))) ;; n-1なら求められるかも？
;(reg  n : 2  ->  1)
;; (trace: 22 (goto (label fib-loop))) ;; 再帰

;; fib-loop
;; (trace: 23 (test (op <) (reg n) (const 2))) ;; いけた (@n=1)
;; (trace: 24 (branch (label immediate-answer)))

;; immediate-answer
;; (trace: 25 (assign val (reg n))) ;; n が答なので valに入れて
; (reg  val : *unassigned*  ->  1)
;; (trace: 26 (goto (reg continue))) ;; n=2のときに入れたafterfib-n-1へ

;; afterfib-n-1
;; (trace: 27 (restore n)) ;; nはn-1なので前の自分が呼ばれたときのnをstackから拾う
;(reg  n : 1  ->  2)
;; (trace: 29 (assign n (op -) (reg n) (const 2))) ;; n - 2 を求めたい
;(reg  n : 2  ->  0)
;; (trace: 31 (assign continue (label afterfib-n-2))) ;; fib(n-2)を求めておわったら fib(n-1) fib(n-2)を足したい
;; (trace: 32 (save val)) ;; fib(n-1) の答えが入ってるので保存
;; (trace: 33 (goto (label fib-loop))) fib(n-2) を求めるループヘ

;; fib-loop
;; (trace: 34 (test (op <) (reg n) (const 2))) ;; n = 0で呼ばれた
;; (trace: 35 (branch (label immediate-answer))) ;; ので答えある

;; immediate-answer
;; (trace: 36 (assign val (reg n))) ;; @n=0
; (reg  val : 1  ->  0) ;; fib(0) がvalに入った
;; (trace: 37 (goto (reg continue)))

;; afterfib-n-2                         ;; fib(1), fib(0) が求まってる
;; (trace: 38 (assign n (reg val))) ; nに fib(0) が入った
; (reg  n : 0  ->  0) 
;; (trace: 39 (restore val)) ; valはfib(1) になった
; (reg  val : 0  ->  1)
;; (trace: 40 (restore continue)) ; 戻るところを復活
;; (trace: 41 (assign val (op +) (reg val) (reg n)))  ; fib(2) = fib(0)+ fib(1)
(reg  val : 1  ->  1)
;; (trace: 42 (goto (reg continue)))

;; afterfib-n-1
;; (trace: 43 (restore n))
(reg  n : 0  ->  3) ;; fib(2) まで求まったのでfib(3)を求めたい
;; (trace: 45 (assign n (op -) (reg n) (const 2))) ;; その時はfib(3-1) だけわかればいい？ほんと？ => この下おいかけるとこれでよかった。
(reg  n : 3  ->  1)
;; (trace: 47 (assign continue (label afterfib-n-2))) ;; fib(n-2)を求めておわったら fib(n-1) fib(n-2)を足したい
;; (trace: 48 (save val)) ;; fib(2) を保存
;; (trace: 49 (goto (label fib-loop))) ;; fib(3-2) = fib(1) を求める


;; fib-loop
;; (trace: 50 (test (op <) (reg n) (const 2))) ;; 1なので求められる
;; (trace: 51 (branch (label immediate-answer)))

;; immediate-answer
;; (trace: 52 (assign val (reg n))) ; fib(1) = 1
(reg  val : 1  ->  1)
;; (trace: 53 (goto (reg continue)))

;; afterfib-n-2
;; (trace: 54 (assign n (reg val))) ;; nにfib(1) が入った
(reg  n : 1  ->  1)
;; (trace: 55 (restore val))
(reg  val : 1  ->  1) ;; valにfib(2) が入った
;; (trace: 56 (restore continue))
;; (trace: 57 (assign val (op +) (reg val) (reg n))) ;; fib(3) = fib(2) + fib(1) = 2
(reg  val : 1  ->  2)
;; (trace: 58 (goto (reg continue)))

;; afterfib-n-1
;; (trace: 59 (restore n))
(reg  n : 1  ->  4) ;; fib(3) が求められたのでfib(4) を求めたい
;; (trace: 61 (assign n (op -) (reg n) (const 2))) ;; そのためにfib(4-2) が欲しい
(reg  n : 4  ->  2)
;; (trace: 63 (assign continue (label afterfib-n-2))) 
;; (trace: 64 (save val)) ;; fib(3) を保存
;; (trace: 65 (goto (label fib-loop)))

;; fib-loop
;; (trace: 66 (test (op <) (reg n) (const 2))) ;; fib(2) を求めたいけど
;; (trace: 67 (branch (label immediate-answer))) ;; すぐに答えにならないので
;; (trace: 68 (save continue))
;; (trace: 69 (assign continue (label afterfib-n-1))) ;; 再帰が必要
;; (trace: 70 (save n))
;; (trace: 71 (assign n (op -) (reg n) (const 1))) ;; fib(1) を求める
(reg  n : 2  ->  1)
;; (trace: 72 (goto (label fib-loop))) ;; 再帰

;; fib-loop
;; (trace: 73 (test (op <) (reg n) (const 2)))
;; (trace: 74 (branch (label immediate-answer))) ;; 

;; immediate-answer
;; (trace: 75 (assign val (reg n))) ;; いけた(@n=1)
(reg  val : 2  ->  1)
;; (trace: 76 (goto (reg continue)))

;; afterfib-1
;; (trace: 77 (restore n))
(reg  n : 1  ->  2) ;; nを戻す(再帰から帰ってきた)
;; (trace: 79 (assign n (op -) (reg n) (const 2))) ;; fib(2 - 0) も必要
(reg  n : 2  ->  0)
;; (trace: 81 (assign continue (label afterfib-n-2))) ;; 終ったら足したい
;; (trace: 82 (save val)) ;; fib(1) を保存して
;; (trace: 83 (goto (label fib-loop))) ;; fib(2-2) を求める

;; fib-loop
;; (trace: 84 (test (op <) (reg n) (const 2)))  ;; n = 0
;; (trace: 85 (branch (label immediate-answer))) ;; いける

;; immediate-answer
;; (trace: 86 (assign val (reg n)))
(reg  val : 1  ->  0) ;; fib(0) が返る
;; (trace: 87 (goto (reg continue)))

;; afterfib-n-2
;; (trace: 88 (assign n (reg val))) ; n = fib(0)
(reg  n : 0  ->  0)
;; (trace: 89 (restore val)) ; val = fib(1)
(reg  val : 0  ->  1)
;; (trace: 90 (restore continue)) ;; もどりたかったところ(n=4のときの afterfib-n-2 へ行きたい)
;; (trace: 91 (assign val (op +) (reg val) (reg n))) ;; fib(2) ができた
(reg  val : 1  ->  1)
;; (trace: 92 (goto (reg continue))) 

;; afterfib-n-2
;; (trace: 93 (assign n (reg val))) ;; n = fib(2)
(reg  n : 0  ->  1)
;; (trace: 94 (restore val)) ;; val = fib(3)
(reg  val : 1  ->  2)
;; (trace: 95 (restore continue))
;; (trace: 96 (assign val (op +) (reg val) (reg n))) ;; fib(4) = fib(3) + fib(2)
(reg  val : 2  ->  3) ;; こたえがvalに入った
;; (trace: 97 (goto (reg continue)))
;; done おわり!

;; うん、たぶん完全にわかった。

;; てことで先へ。
(load "./code_from_text/ch5-regsim.scm")
(load "./chapter5-21-count-leave-machines.scm")
(set-register-contents! count-leave-machine 'tree '((a b) (c (d e f))))
(start count-leave-machine)
(get-register-contents count-leave-machine 'val)
;; gosh> 6

;; b
(define (count-leaves tree)
  (define (count-iter tree n)
    (cond ((null? tree) n )
          ((not (pair? tree)) (+ n 1))
          (else
           (count-iter (cdr tree)
                       (count-iter (car tree)
                                   n)))))
  (trace count-iter)
  (count-iter tree 0))

(load "./code_from_text/ch5-regsim.scm")
(load "./chapter5-21-count-leave-machines.scm")
(set-register-contents! count-leave-iter-machine 'tree '((a b) (c (d e f))))
(count-leave-iter-machine 'trace-on)
(set-register-trace-on count-leave-iter-machine 'val)
(start count-leave-iter-machine)
(get-register-contents count-leave-iter-machine 'val)

;; gosh> 6

;; 5.22
(load "./chapter5-22-append-machine.scm")
(append-machine 'trace-on)
(set-register-contents! append-machine 'x '(1 2))
(set-register-contents! append-machine 'y '(3 4))
(start append-machine)
(get-register-contents append-machine 'ans)
;; gosh> (1 2 3 4)

(append!-machine 'trace-on)
(set-register-contents! append!-machine 'x '(1 2))
(set-register-contents! append!-machine 'y '(3 4))
(set-register-trace-on append!-machine 'x)
(set-register-trace-on append!-machine 'y)
(set-register-trace-on append!-machine 'tmp)
(set-register-trace-on append!-machine 'tmp2)
(start append!-machine)
(get-register-contents append!-machine 'x)
