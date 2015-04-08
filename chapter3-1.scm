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

;; *Geiser dbg* っていうバッファが表示されると非常に使いやすいが、
;; これを最初から開いておくことはできないのか？

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
