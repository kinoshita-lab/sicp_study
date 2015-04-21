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
