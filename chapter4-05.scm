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
