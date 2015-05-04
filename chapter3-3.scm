;;; 3.1.3 代入を取り入れた対価
(require racket/trace)


;; 3.7
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

	;; ここ書き換えて複数pass行けるようにする
	(define (check plist trial) 
	  (cond
	   ((not (list? pass)) (eq? pass trial))
	   ((eq? '() plist) #f)
	   (else (if (eq? (car plist) trial) #t
			  (check (cdr plist) trial)))))

	;; これ足して複数パスワードに対応できるようにする
	(define (join new-password)
	  (set! pass (list pass new-password))
	  dispatch)

	(define (dispatch password m)
	  (if (check pass password)
		  (cond ((eq? m 'withdraw) withdraw)
				((eq? m 'deposit) deposit)
				((eq? m 'join) join)
				(else (error "Unknown request -- MAKE-ACCOUNT"
							 m)))
		  (error "Incorrect password")))
	;; (trace dispatch)
	;; (trace join)
	;; (trace check)
	  dispatch))


(define peter-acc (make-account 100 'open-sesame))

(define (make-joint joint-target password-for-target password-for-new-account)
  ((joint-target password-for-target 'join) password-for-new-account))

(define paul-acc
  (make-joint peter-acc 'open-sesame 'rosebud))

;; 預けてみる
((paul-acc 'rosebud 'deposit) 20)
;; => 120
((peter-acc 'open-sesame 'deposit) 10)
;; => 130

;; どうでもいいけどこういうことができてしまう
((paul-acc 'open-sesame 'deposit) 30) ; 他人のパスワードでアクセス
;; => 160


;; 単純な手続きfを定義し, (+ (f 0) (f 1))が, +の引数を左から右へ評価すると0を返し, 右から左へ評価すると1を返すようにせよ. 

;; globalに書くのは簡単だけどこういう問題なのか謎
(define first-arg '())
(define (f arg)
  (if (eq? '() first-arg)
	  (begin
		(set! first-arg arg )
		arg)
	  first-arg))

;; 試
;; (trace f)
;; (+ (f 0) (f 1))
;; => 0
;; >(f 0)
;; <0
;; >(f 1)
;; <0

;; 3.11の準備
(define (make-withdraw initial-amount)
  (let ((balance initial-amount))
    (lambda (amount)
      (if (>= balance amount)
          (begin (set! balance (- balance amount))
                 balance)
          "Insufficient funds"))))
;; をletをlambdaにする
(define (make-withdraw initial-amount)
  ((lambda (balance initial-amount)
     (lambda (amount)
       (if (>= balance amount)
           (begin (set! balance (- balance amount))
                  balance)
           "Insufficient funds")))))
