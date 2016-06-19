;; 4.2 Scheme の変異版 — 遅延評価
;; 素のunless
(define (unless condition usual-value exceptional-value)
  (if condition exceptional-value usual-value)) ;;   

(define a 1)
(define b 1)

(unless (= b 0)
  (/ a b)
  (begin (display "exception: returning 0") 0))
;; gosh> exception: returning 01
;; なぜかこうなる逆じゃない？
;; こう
(define (unless condition usual-value exceptional-value)
  (if condition usual-value exceptional-value)) ;;   
(unless (= b 0)
  (/ a b)
  (begin (display "exception: returning 0") 0))

(define a 1)
(define b 0)

(unless (= b 0)
  (/ a b)
  (begin (display "exception: returning 0") 0))
;; gosh> *** ERROR: attempt to calculate a division by zero
;; これはちゃんと（？）おこられた

;; 4.25
;; いきなりまわしてみる
(define (factorial n)
  (unless (= n 1)
	(* n (factorial (- n 1)))
	1))
;; (factorial 5) ;; ！！　動かすと大変
;; ヒープがこわれた！
;; 2番目の引数が適用順序だと評価される必要があって、と１番目の条件に合致していてもかならずfactorialが再帰的に呼びだされてしまい、処理が終わらなくなってしまうから。
;; 正規順序なら動作する。


;; 4.26

;; unless->if を作ればよい。これは特殊形式になってしまうけど。
(load "./chapter4-repl.scm")
(driver-loop)
(define test-case
  (list 'unless 
		'(= b 0) ;; condition
		'(/ a b) ;; usual
		'(begin (display "exception: returning 0") 0))) ;; exceptional
test-case
;; (unless (= b 0) (/ a b) (begin (display "exception: returning 0") 0))
(define (unless? exp)
  (tagged-list? exp 'unless))
(unless? test-case)
;; #t
(define (unless-condition exp)
  (cadr exp))
(unless-condition test-case)
;; (= b 0)
(define (unless-usual exp)
  (caddr exp))
(unless-usual test-case)
;; (/ a b)
(define (unless-exceptional exp)
  (cadddr exp))
(unless-exceptional test-case)
;; (begin (display "exception: returning 0") 0)
(define (unless->if exp)
  (let ((condition (unless-condition exp))
		(usual (unless-usual exp))
		(exceptional (unless-exceptional exp)))
	(make-if condition exceptional usual)))
(unless->if test-case)
;; (if (= b 0) (begin (display "exception: returning 0") 0) (/ a b))

;; unless を特殊形式でなく手続きとして持つほうが役に立つ状況の例
;; なんだろ filterとかmapとかに引数で入れられるってことかな。

;; L-Evalを作って chapter4-lreplって名前で置いといた。

;; 4.27 こうなった
;; gosh> (load "./chapter4-lrepl.scm")
;; ;;; L-Eval input:
;; (define count 0)
;; ;;; L-Eval value:
;; ok
;; ;;; L-Eval input:
;; (define (id x) (set! count (+ count 1)) x)
;; ;;; L-Eval value:
;; ok
;; ;;; L-Eval input:
;; (define w (id (id 10)))
;; ;;; L-Eval value:
;; ok
;; ;;; L-Eval input:
;; count
;; ;;; L-Eval value:
;; 0
;; ;;; L-Eval input:
;; w
;; ;;; L-Eval value:
;; 10
;; ;;; L-Eval input:
;; count
;; ;;; L-Eval value:
;; 0
;; 普通にやると
;; gosh> (define count 0)
;; count
;; gosh> (define (id x) (set! count (+ count 1)) x)
;; id
;; gosh> (define w (id (id 10)))
;; w
;; gosh> count
;; 2
;; gosh> w
;; 10
;; gosh> count
;; 2


;; 4.28
;; 「サンク」とかいうのがこの時点ではなくなっててほしいってことだとおもった。
;; applyの中でcompound-procedure? が呼ばれると thunkが生成されるので、
;; ここ入る例を考えれば良さそう。んでそれは引数がprocedureの時なので、
;; 適当な高階関数をつくってみればよさそう。
(define (f x)
  (* x 2))
(define (square-of func val)
  (* (func val) (func val)))
(square-of f 2)
;; 素のgauche
;; gosh> f
;; gosh> square-of
;; gosh> 16

;; ;; L-EVAL
;; ;;; L-Eval input:
;; (define (f x)
;; (* x 2))
;; ;;; L-Eval value:
;; ok
;; ;;; L-Eval input:
;; (define (square-of func val)
;; (* (func val) (func val)))
;; ;;; L-Eval value:
;; ok
;; ;;; L-Eval input:
;; (square-of f 2)
;; ;;; L-Eval value:
;; 16
;; L-EVALのevalをこんなふうに改造して・・
;; (define (eval exp env)
;;   (cond ((self-evaluating? exp) exp)
;;         ((variable? exp) (lookup-variable-value exp env))
;;         ((quoted? exp) (text-of-quotation exp))
;;         ((assignment? exp) (eval-assignment exp env))
;;         ((definition? exp) (eval-definition exp env))
;;         ((if? exp) (eval-if exp env))
;;         ((lambda? exp) (make-procedure (lambda-parameters exp)
;;                                        (lambda-body exp)
;;                                        env))
;;         ((begin? exp)
;;          (eval-sequence (begin-actions exp) env))
;;         ((cond? exp) (eval (cond->if exp) env))
;;         ((application? exp)                       ;; 
;;          (apply (eval (operator exp) env)         ;; ! こうする
;;                 (operands exp)                    ;; 
;; 				env))                                ;; 
;;         (else
;;          (error "Unknown expression type: eval" exp)))
;;; L-(mod EVAL) Eval input:
;; (define (f x)
;; (* x 2))
;; ;;; L-(mod EVAL) Eval value:
;; ok
;; ;;; L-(mod EVAL) Eval input:
;; (define (square-of func val)
;; (* (func val) (func val)))
;; ;;; L-(mod EVAL) Eval value:
;; ok
;; ;;; L-(mod EVAL) Eval input:
;; (square-of f 2)
;; *** ERROR: Unknown procedure type: APPLY (thunk f #0=(((square-of f false true car cdr cons null? + - = *) (procedure (func val) ((* (func val) (func val))) #0#) (procedure (x) ((* x 2)) #0#) #f #t (primitive #<subr car>) (primitive #<subr cdr>) (primitive #<subr cons>) (primitive #<subr null?>) (primitive #<subr +>) (primitive #<subr ->) (primitive #<subr =>) (primitive #<subr *>))))
;; サンクがきえなくて困るっていう例になって気がする。

;; 4.29
;; 前のメモ化で出てきたフィボナッチかな。
;; なんもしなければメモ化されてると思うのでまずまわしてみる
;; (define (fib n) (cond ((= n 0) 0) ((= n 1) 1) (else (+ (fib (- n 2)) (fib (- n 1))))))

;;; L-Eval input:
;; (fib 20)
;(time (actual-value input the-global-environment))
; real   0.488
; user   0.500
; sys    0.000
;;; L-Eval value:
;; 6765
;; メモ化してない版は'evaluated-thunkの出現をとめればよさげなので
;; force-itをこうしちゃう
(define (force-it obj)
  (cond ((thunk? obj)
		 (let ((result (actual-value (thunk-exp obj)
									 (thunk-env obj))))
		   result))
		(else obj)))

;(time (actual-value input the-global-environment))
; real   2.516
; user   2.580
; sys    0.010
;; おお、めちゃくちゃ差ができた。

;; 後半の

;; メモ化してあるばあい
;;; L-Eval value:
10
;;; L-Eval input:
count
;;; L-Eval value:
0

;; メモ化してない
;;; L-Eval value:
10
;;; L-Eval input:
count
;;; L-Eval value:
0
;; なんかおかしい。上はcountが1 したは2になるはずなんだけど・・・・






