;; 4.50
;; amb式の評価
;; (define (analyze-amb exp)
;;   (let ((cprocs (map analyze (amb-choices exp))))
;; 	(lambda (env succeed fail)
;; 	  (define (try-next choises)
;; 		(if (null? choises)
;; 			(fail)
;; 			((car choises) ;; ここで!!  randでnthなやつを持ってこれるようにして
;; 			 env
;; 			 succeed
;; 			 (lambda () (try-next (cdr choises)))))) ;; ここで！！ randなやつを削ったリストを送りつける
;;	  (try-next cprocs))))


;; リハビリもかねてフルスクラッチで書いてみる
(define (length l)
  (define (length-iter l n)
  (if (null? l)
	  n
	  (length-iter (cdr l) (+ 1 n))))
  (length-iter l 0))


(define (random-number-generator seed)
  (let ((a 27)
		(b 26)
		(m 16777216) ; 適当にデカい数字
		(x seed))
	(lambda ()
	  (set! x (remainder (+ (* a x) b) m))
	  x)))
(define (random-within rng max)
  (remainder (rng) max))

(define r (random-number-generator 0))
(random-within r 100)
;; 呼びまくるとこんな感じ
;; gosh> 12
;; gosh> 86
;; gosh> 72
;; gosh> 62
;; gosh> 24
;; gosh> 50
;; gosh> 40
;; gosh> 58
;; gosh> 64
;; gosh> 34

;; こんなんを作り
(define default-rng (random-number-generator 0))

(define (nth l n)
  (define (iter l n)
	(cond ((null? l) l)
		  ((= n 0) (car l))
		  (else
			 (iter (cdr l) (- n 1)))))
  (iter l n))
  
(define (choose-random-from l)
  (let ((n (random-within r (length l))))
	(nth  l n)))
(choose-random-from (list 1 2 3 4 5))
;; 呼びまくると全部出るのでよさげ
;; gosh> 4
;; gosh> 4
;; gosh> 1
;; gosh> 2
;; gosh> 2
;; gosh> 1
;; gosh> 5
;; gosh> 3

(define (remove l item)
  (define (iter r l item)
	(cond 
	 ((null? l) r)
	 ((equal? (car l) item)
	  (iter r (cdr l) item))
	 (else
	  (iter (append r (list (car l))) (cdr l) item))))
  (iter '() l item))

(remove (list 1 2 3 4) 5)
;; (1 2 3 4)


;; 試
(load "./chapter4-ambrepl.scm")

;; ramb?
(define (ramb? exp) (tagged-list? exp 'ramb))
(define (ramb-choices exp) (cdr exp))

;; analyze-ramb
(define (analyze-ramb exp)
  (let ((cprocs (map analyze (amb-choices exp))))
	(lambda (env succeed fail)
	  (define (try-next choises)
		(if (null? choises)
			(fail)
			(let ((choise (choose-random-from choises)))
			  (choise 
			   env
			   succeed
			   (lambda () (try-next (remove choises choise))))))) ;; ここで！！ randなやつを削ったリストを送りつける
	  (try-next cprocs))))

;; ディスパッチに追加
(define (analyze exp)
  (cond ((self-evaluating? exp) (analyze-self-evaluating exp))
		((quoted? exp) (analyze-quoted exp))
		((amb? exp) (analyze-amb exp))
		((ramb? exp) (analyze-ramb exp)) ;; これ足した　
		((variable? exp) (analyze-variable exp))
		((assignment? exp) (analyze-assignment exp))
		((definition? exp) (analyze-definition exp))
		((if? exp) (analyze-if exp))
		((lambda? exp) (analyze-lambda exp))
		((begin? exp) (analyze-sequence (begin-actions exp)))
		((cond? exp) (analyze (cond->if exp)))
		((let? exp) (analyze (let->combination exp))) ;; letあるバージョン　これを足してある
		((application? exp) (analyze-application exp))
		(else (error "Unknown expression type: ANALYZE" exp))))

;; repl突入
(driver-loop)
(list (ramb 1 2 3) (ramb 'a 'b))
;; (3 a)
;;; Amb-Eval input:
;;; Starting a new problem 
;;; Amb-Eval value:
;; (1 a)
;;; Amb-Eval input:
;;; Starting a new problem 
;;; Amb-Eval value:
;; (2 a)
;; なんとなくバラけたようなきがする
;; Alyssa の問題を解く というかtry-againした時に色々な単語が選ばれるので面白い

;; 連続で実行できないのでここでインタプリタ終了　---------------------

;; 4.51
;; permanent-set!はset!を元の評価器にしたみたいなものを作れば良さそう
;; analyzeに追加
(define (analyze exp)
  (cond ((self-evaluating? exp) (analyze-self-evaluating exp))
		((quoted? exp) (analyze-quoted exp))
		((amb? exp) (analyze-amb exp))
		((ramb? exp) (analyze-ramb exp)) 
		((variable? exp) (analyze-variable exp))
		((permanent-assignment? exp) (analyze-permanent-assignment exp)) ;; これ足した！
		((assignment? exp) (analyze-assignment exp))
		((definition? exp) (analyze-definition exp))
		((if? exp) (analyze-if exp))
		((lambda? exp) (analyze-lambda exp))
		((begin? exp) (analyze-sequence (begin-actions exp)))
		((cond? exp) (analyze (cond->if exp)))
		((let? exp) (analyze (let->combination exp))) 
		((application? exp) (analyze-application exp))
		(else (error "Unknown expression type: ANALYZE" exp))))

;; 代入
(define (permanent-assignment? exp) (tagged-list? exp 'permanent-set!))
(define (permanent-assignment-variable exp) (cadr exp))
(define (permanent-assignment-value exp) (caddr exp))

;; もともとのやつ
;; (define (analyze-assignment exp)
;;   (let ((var (assignment-variable exp))
;; 		(vproc (analyze (assignment-value exp))))
;; 	(lambda (env)
;; 	  (set-variable-value! var (vproc env) env)
;; 	  'ok)))

;; amb状態
;; (define (analyze-assignment exp)
;;   (let ((var (assignment-variable exp))
;; 		(vproc (analyze (assignment-value exp))))
;; 	(lambda (env succeed fail)
;; 	  (vproc env
;; 			 (lambda (val fail2)
;; 			   (let ((old-value
;; 					  (lookup-variable-value var env)))
;; 				 (set-variable-value! var val env)
;; 				 (succeed 'ok
;; 						  (lambda ()
;; 							(set-variable-value!
;; 							 var old-value env)
;; 							(fail2)))))
;; 			 fail))))
;; succeedとかfailがあるからそのままはできなさそう
(define (analyze-permanennt-assignment exp)
  (let ((var (assignment-variable exp))
		(vproc (analyze (assignment-value exp))))
	(lambda (env succeed fail)
	  (vproc env
			 (lambda (val fail2)
			   (begin
				 (set-variable-value! var val env)
				 (succeed 'ok
						  fail2)))
	  fail))))
;; こんなかな。
;; どんな値が出るか？　はambevalをset!で回せば出るよね。
(load "./chapter4-ambrepl.scm")
(define the-global-environment (setup-environment))
(driver-loop)
;;;;In the driver loop, do
(define (require p)
 (if (not p) (amb)))
;; loadからここまでは毎回実行する必要がある。

(define count 0)
;; an-element-of ってなんだ
;; 本文にあった
(define (an-element-of items)
  (require (not (null? items)))
  (amb (car items) (an-element-of (cdr items))))

(let ((x (an-element-of '(a b c)))
	  (y (an-element-of '(a b c))))
  (set! count (+ count 1))
  (require (not (eq? x y)))
  (list x y count))
;; (a b 1)
try-again
;; ;;; Amb-Eval value:
;; (a c 1)
;; ;;; Amb-Eval input:
;; ;;; Amb-Eval value:
;; (b a 1)
;; .
;; .
;; .
;; 最後まで１だった。

;; --------------------- ここでrepl終了

;; 4.52
;; 意味がわかりづらい
;; (if-fail (やってみようとすること　上手く行ったらこの中を返す)
;;          (ダメだった時返すもの))
;; みたいな感じ


(load "./chapter4-ambrepl.scm")
(use slib) 
(require 'trace)
(trace apply-primitive-procedure)

;; 上書きシリーズ
(define (if-fail-try exp)  (cadr exp))
(define (if-fail-fail exp) (caddr exp))

;; ifをちょっと変えたくらいでなんとかならないのか
(define (analyze-if-fail exp)
  (let ((tproc (analyze (if-fail-try exp)))
		(fproc (analyze (if-fail-fail exp))))
	(lambda (env succeed fail)
	  (tproc env
			 (lambda (value fail2) ;; ifのsuceedのとこ風
			   (succeed value fail2))
			 (lambda ()
			   (fproc env succeed fail)))))) ;; failそのままだと呼ばれなかったので実行してもらう感じ

;; analyzeに組み込む
(define (if-fail? exp) (tagged-list? exp 'if-fail))
(define (analyze exp)
  (cond ((self-evaluating? exp) (analyze-self-evaluating exp))
		((quoted? exp) (analyze-quoted exp))
		((amb? exp) (analyze-amb exp))
		((if-fail? exp) (analyze-if-fail exp)) ;; これ足した！
		((variable? exp) (analyze-variable exp))
		;;((permanent-assignment? exp) (analyze-permanent-assignment exp))
		((assignment? exp) (analyze-assignment exp))
		((definition? exp) (analyze-definition exp))
		((if? exp) (analyze-if exp))
		((lambda? exp) (analyze-lambda exp))
		((begin? exp) (analyze-sequence (begin-actions exp)))
		((cond? exp) (analyze (cond->if exp)))
		((let? exp) (analyze (let->combination exp))) 
		((application? exp) (analyze-application exp))
		(else (error "Unknown expression type: ANALYZE" exp))))

(define the-global-environment (setup-environment))

(driver-loop)

;;;;In the driver loop, do
(define (require p)
 (if (not p) (amb)))
(define (an-element-of items)
  (require (not (null? items)))
  (amb (car items) (an-element-of (cdr items))))
;; even? をprimitive-proceduresに入れても無視されるので自作

(if-fail (let ((x (an-element-of '(1 3 5))))
		   (require (even? x))
		   x)
		 'all-odd)

;; これでいい予定何だけど動かない・・

;; 4.53
;; prime-sum-paireをみつけたらpairsに追加、なかったらambでリトライという動きをする。

;; 4.54
;; むしろ特殊形式にして欲しいわ　まいかい定義するのめんどくさすぎ
(define (analyze-require exp)
  (let ((pproc (analyze (require-predicate exp))))
	(lambda (env succeed fail)
	  (pproc env
			 (lambda (pred-value fail2)
			   (if (false? pred-value)
				   (fail) 
				   (succeed 'ok fail2)))
			 fail))))
