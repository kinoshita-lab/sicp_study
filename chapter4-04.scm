;; 4.1.7 構文解析を実行から分離する
(load "./chapter4-repl.scm")
(define (eval exp env) ((analyze exp) env))
(define (analyze exp)
  (cond ((self-evaluationg? exp) (analyze-self-evaluating exp))
		((quoted? exp) (analyze-quoted exp))
		((variable? exp) (analyze-variable exp))
		((assignment? exp) (analyze-assignment exp))
		((definition? exp) (analyze-definition exp))
		((if? exp) (analyze-if exp))
		((lambda? exp) (analyze-lambda exp))
		((begin? exp) (analyze-sequence (begin-actions exp)))
		((cond? exp) (analyze (cond->if exp)))
		((application? exp) (analyze-application exp))
		(else (error "Unknown expression type: ANALYZE" exp))))

(define (analyze-self-evaluating exp)
  (lambda (env) exp))

(define (analyze-quoted exp)
  (let ((qval (text-of-quotation exp)))
	(lambda (env) qval)))

(define (analyze-variable exp)
  (lambda (env) (lookup-variable-value exp env)))

(define (analyze-assignment exp)
  (let ((var (assignment-variable exp))
		(vproc (analyze (assignment-value exp))))
	(lambda (env)
	  (set-variable-value! var (vproc env) env)
	  'ok)))

(define (analyze-definition exp)
  (let ((var (definition-variable exp))
		(vproc (analyze (definition-value exp))))
	(lambda (env)
	  (define-variable! var (vproc env) env)
	  'ok)))

(define (analyze-if exp)
  (let ((pproc (analyze (if-predicate exp)))
		(cproc (analyze (if-consequent exp)))
		(aproc (analyze (if-alternative exp))))
	(lambda (env) (if (true? (pproc env))
					  (cproc env)
					  (aproc env)))))

(define (analyze-lambda exp)
  (let ((vars (lambda-parameters exp))
		(bproc (analyze-sequence (lambda-body exp))))
	(lambda (env) (make-procedure vars bproc env))))



