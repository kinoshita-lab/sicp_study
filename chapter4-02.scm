(use slib)
(require 'trace)
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; 4.11
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; ここまででFrameの感じは ((a b c) (1 2 3)) みたいになっているんだけど、これを
;; ((a . 1) (b . 2) (c . 3)) みたいにして動かしてね、という問題。　こっちのほうが個人的には自然。

;; envのほうはそのまま使って行きたい。
(define (enclosing-environment env) (cdr env))
(define (first-frame env) (car env))
(define the-empty-environment '())
(define (extend-environment vars vals base-env)
  (if (= (length vars) (length vals ))
	  (cons (make-frame vars vals) base-env)
	  (if (< (length vars) (length vals))
		  (error "Too many arguments supplied" vars vals)
		  (error "Too few arguments supplied" vars vals ))))


;; ここから変えていく必要ある
(define vars '(a b c))
(define vals '(1 2 3))

(define (make-frame variables values)
  (if (eq? '() variables) '() ;; variablesとvaluesの長さは同じ設定
	  (cons (cons (car variables) (car values))
			  (make-frame (cdr variables) (cdr values)))))
;; (make-frame vars vals)
;; gosh> ((a . 1) (b . 2) (c . 3))

(define (frame-variables frame)
  (if (eq? '() frame) '()


	  (cons (car (car frame)) 
			(frame-variables (cdr frame)))))
;; (frame-variables (make-frame vars vals))
;; (a b c)

(define (frame-values frame)
  (if (eq? '() frame) '()
	  (cons (cdr (car frame))
			(frame-values (cdr frame)))))
;; (frame-values (make-frame vars vals))
;; gosh> (1 2 3)

(define (add-binding-to-frame! var val frame)
  (set! frame (cons (cons var val) frame)))

(define test-frame '((a . 1) (b . 2) (c . 3)))
;; test-frame
;; (add-binding-to-frame! 'd 4 test-frame)
;; test-frame
;; gosh> ((d . 4) (a . 1) (b . 2) (c . 3))

(define (define-variable! var val env)
  (let ((frame (first-frame env)))
	(define (scan vars vals)
	  (cond ((null? vars)
			 (add-binding-to-frame! var val frame))
			((eq? var (car vars)) (set-car! vals val))
			(else (scan (cdr vars) (cdr vals)))))
	(set! frame (scan (frame-variables frame) (frame-values frame)))))
;; そのまま使えそう
(define test-env '(() ()))
test-env
(trace define-variable! add-binding-to-frame!)
(define-variable! 'a 1 test-env)
;; gosh> ((a . 1))

(define (set-variable-value! var val env)
  (define (env-loop env)
	(define (scan vars vals)
	  (cond ((null? vars)
			 (env-loop (enclosing-environment env)))
			((eq? var (car vars)) (set-car! vals val))
			(else (scan (cdr vars) (cdr vals)))))
	(if (eq? env the-empty-environment)
		(error "Unbound variable: SET!" var)
		(let ((frame (first-frame env)))
		  (scan (frame-variables frame)
				(frame-values frame)))))
  (env-loop env))
;; そのままつかえそう
(set-variable-value! 'a 2 test-env)
test-env
;; gosh> *** ERROR: Unbound variable: SET! a
;; lookup-variable-value var env
;; うーん・・

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; 4.12
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; scanが共通っぽい
(define (scan var vars vals)
  (cond ((null? vars) '()) ;; null かえしてみる
		((eq? var (car vars)) vals) ;; vals返すので適当につかってくれ
		(else
		 (scan var (cdr vars) (cdr  vals)))))

(define (set-variable-value! var val env)
  (define (env-loop env)
	(let* ((frame (first-frame env))
		   (scanned (scan var (frame-variables frame) (frame-values frame))))
	(if (eq? env the-empty-environment)
		(error "Unbound variable -- SET!" var)
		(if (null? scanned)
			(env-loop (enclosing-environment env))
			(car scanned)))))
	(env-loop env))

(define (define-variable! var val env)
  (let* ((frame (first-frame env))
		 (scanned (scan var (frame-variables frame) (frame-values frame))))
	(if (null? scanned)
		(add-binding-to-frame! var val frame)
		(set-car! scanned val))))

(define (lookup-variable-value var env)
  (define (env-loop env)
	(let* ((frame (first-frame env))
		   (scanned (scan var (frame-variables frame) (frame-values frame))))
	  (if (eq? env the-empty-environment)
		  (error "Unbound variable" var)
		  (car scanned))))
  (env-loop env))



