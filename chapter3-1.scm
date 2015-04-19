;; 3.1.1 局所状態変数

(define balance 100)
(define (withdraw amount)
  (if (>= balance amount)
      (begin (set! balance (- balance amount))
             balance)
      "Insufficient funds"))
;; これはすぐに用済みだけど使ってみる
(withdraw 10)
;; => 90
(withdraw 30)
;; => 60
(withdraw 100)
;; => "Insufficient funds"

(define new-withdraw
  (let ((balance 100))
    (lambda (amount)
      (if (>= balance amount)
          (begin (set! balance (- balance amount))
                 balance)
          "Insufficient funds"))))
;; これはどうやってつかえというのだろう？
(new-withdraw 10)
;; => 90
(new-withdraw 10)
;; => 80

;; 下のmake-withdrawが微妙にわかりづらいのは
(define (easy-make-withdraw arg-balance)
  (let ((balance arg-balance))
	(lambda (amount)
	  (if (>= balance amount)
		  (begin (set! balance (- balance amount))
				 balance)
		  "Insufficient funds"))))
;; という途中の段階が無いからかも。

(define (make-withdraw balance)
  (lambda (amount)
    (if (>= balance amount)
        (begin (set! balance (- balance amount))
               balance)
        "Insufficient funds")))

(define W1 (make-withdraw 100))
(define W2 (make-withdraw 100))

(W1 50)
;; => 50

(W2 70)
;; => 30

(W2 40)
;; => 10

(define (make-account balance)
  (define (withdraw amount)
    (if (>= balance amount)
        (begin (set! balance (- balance amount))
               balance)
        "Insufficient funds"))
  (define (deposit amount)
    (set! balance (+ balance amount))
    balance)
  (define (dispatch m)
    (cond ((eq? m 'withdraw) withdraw)
          ((eq? m 'deposit) deposit)
          (else (error "Unknown request -- MAKE-ACCOUNT"
                       m))))
  dispatch)

(define acc (make-account 100))
((acc 'withdraw) 50)
;; => 50
((acc 'withdraw) 60)
;; => "Insufficient funds"
((acc 'deposit) 40)
;; => 90
((acc 'withdraw) 60)
;; => 30

(define acc2 (make-account 100))
acc2
;; => #<procedure:dispatch>
((acc2 'withdraw) 20)
;; => 80

;; 3.1
(define (make-accumlator sum)
  (lambda (value)
	(begin (set! sum (+ sum value))
		   sum)))
(define a1 (make-accumlator 10))
(a1 10)
;; => 30
(define a2 (make-accumlator 30))
(a2 10)
;; => 40
;; よさげ

;; 3.2
(define (make-monitored function)
  (let ((counter 0)) ; letでくるめばいいのか謎
	;; カウンターをリセットする
	(define (reset-count)
	  (set! counter 0))
	;; カウンターを増やして登録してる関数を呼ぶ（てか返す)
	(define (call)
	  (begin (set! counter (+ 1 counter))
			 function))

	(define (dispatch m)
	  (cond ((eq? m 'reset-count) (reset-count))
			((eq? m 'how-many-calls?) counter)
			(else ((call) m))))
	dispatch))


(define (square x)
  (* x x))
(define s (make-monitored square))

(s 100)
;; => 10000
(s 'how-many-calls?)
;; => 1
(s 2)
;; => 4
(s 'how-many-calls?)
;; => 2
(s 'reset-count)
(s 'how-many-calls?)
;; => 0
;; letでくるめばいいっぽい


;; 3.3
(define (make-account balance password)
  (let ((pass password))
	(define (withdraw amount)
	  (if (>= balance amount)
		  (begin (set! balance (- balance amount))
				 balance)
		  "Insufficient funds"))
	(define (deposit amount)
	  (set! balance (+ balance amount))
	  balance)
	(define (check password)
	  (eq? password pass))
	(define (dispatch password m)
	  (if (check password)
		  (cond ((eq? m 'withdraw) withdraw)
				((eq? m 'deposit) deposit)
				(else (error "Unknown request -- MAKE-ACCOUNT"
							 m)))
		  (error "Incorrect password")))
	  dispatch))

(define acc (make-account 100 'secret-password))
((acc 'secret-password 'withdraw) 40)
;; => 60
((acc 'some-other-password 'deposit) 50)
;; Incorrect password
;; よさげ。

;; 3.4
;; pass passwordのletは本来不要
(define (make-account balance password)
  (let ((pass password) (error-counter 0))
	(define (withdraw amount)
	  (if (>= balance amount)
		  (begin (set! balance (- balance amount))
				 balance)
		  "Insufficient funds"))
	(define (deposit amount)
	  (set! balance (+ balance amount))
	  balance)
	(define (call-the-cops)
	  (print "calling cops.. please wait..."))

	(define (check password)
	  (eq? password pass))
	(define (dispatch password m)
	  (if (check password)
		  (cond ((eq? m 'withdraw) withdraw)
				((eq? m 'deposit) deposit)
				(else (error "Unknown request -- MAKE-ACCOUNT"
							 m)))
		  (begin (set! error-counter (+ 1 error-counter))
				 (if (= error-counter 7)
					 (call-the-cops)
					 (error "please be careful.")))))
	  dispatch))

(define acc (make-account 100 'secret-password))
((acc 'secret-password 'withdraw) 40)
;; => 60
((acc 'some-other-password 'deposit) 50)
((acc 'some-other-password 'deposit) 50)
((acc 'some-other-password 'deposit) 50)
((acc 'some-other-password 'deposit) 50)
((acc 'some-other-password 'deposit) 50)
((acc 'some-other-password 'deposit) 50)
((acc 'some-other-password 'deposit) 50)
;; "calling cops.. please wait..
;; ってでるのでよさげではあるけど、 そのあと　50に対して関数を適用しようとしてエラーで死ぬ。
;; 
;; Error: struct:exn:fail:contract
;; "calling cops.. please wait..."application: not a procedure;
;;  expected a procedure that can be applied to arguments
;;   given: #<void>
;;   arguments...:
;;    50
;; Expression evaluated was:
;; ((acc 'some-other-password 'deposit) 50)

  
