;; 4.1.7 構文解析を実行から分離する
(load "./chapter4-repl.scm")
(define (eval exp env) ((analyze exp) env))
(define (analyze exp)
  (cond ((self-evaluationg? exp) (analyze-self-evaluating exp))
		((primitive-procedure? exp))
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

(define (analyze-sequence exps)
  (define (sequentially proc1 proc2)
	(lambda (env) (proc1 env) (proc2 env)))
  (define (loop first-proc rest-procs)
	(if (null? rest-procs)
		first-proc
		(loop (sequentially first-proc (car rest-procs))
			  (cdr rest-procs))))
  (let ((procs (map analyze exps)))
	(if (null? procs) (error "Empty sequence: ANALYZE"))
	(loop (car procs) (cdr procs))))

(define (analyze-application exp)
  (let ((fproc (analyze (operator exp)))
		(aprocs (map analyze (operands exp))))
	(lambda (env)
	  (execute-application
	   (fproc env)
	   (map (lambda (aproc) (aproc env))
			aprocs)))))
(define (execute-application proc args)
  (cond ((primitive-procedure? proc)
		 (apply-primitive-procedure proc args))
		((compound-procedure? proc)
		 ((procedure-body proc)
		  (extend-environment
		   (procedure-parameters proc)
		   args
		   (procedure-environment proc))))
		(else
		 (error "Unknown procedure type: EXECUTE-APPLICATION"
			  proc))))

;;  4.22

 
 

 ;; evalに組み込む用
 (define (let? exp) (tagged-list? exp 'let))
 

(define (analyze exp)
  (cond ((self-evaluating? exp) (analyze-self-evaluating exp))
		((quoted? exp) (analyze-quoted exp))
		((variable? exp) (analyze-variable exp))
		((assignment? exp) (analyze-assignment exp))
		((definition? exp) (analyze-definition exp))
		((if? exp) (analyze-if exp))
		((lambda? exp) (analyze-lambda exp))
		((begin? exp) (analyze-sequence (begin-actions exp)))
		((cond? exp) (analyze (cond->if exp)))
		((let? exp) (analyze (let->combination exp))) ;; これを足して
		((application? exp) (analyze-application exp))
		(else (error "Unknown expression type: ANALYZE" exp))))

;; 4.6から必要なのを持ってくる
;; これを削って
;; (define (eval-let let-clause env)
;;    (eval (let->combination let-clause) env))

(define (let->combination exp)
  (let ((vars-exps (cadr test-case))
		(body (caddr test-case)))
	((make-lambda (vars sexp)
				  body
				  env) (vals exp)))) 
;; ↑で必要なのを作る
(define (vars s)
  (cond ((eq? s '()) '())
		(else  (cons (caar s) (vars (cdr s))))))
(define (vals s)
  (cond ((eq? s '()) '())
		(else  (cons (cadar s) (exp (cdr s))))))


;; 4.23
;; sequentiallyがあるのはどうして？　っていう問題だと思った
;; Alyssaの方は解析が全部終わてない (execute-sequence...)が頭についたリストになってしまうところが
;; analyze感が無いみたい
;; http://community.schemewiki.org/?sicp-ex-4.23

;; 4.24
;; 時間を計測する方法　http://d.hatena.ne.jp/tmurata/20100423/1272021761
;; 問題のfibonazziをやろうとすると計算 (+ - = ) が無いのでprimitiveに追加して・・
;; driver-loopで↓を実行
;;; M-Eval input:
;;(define (fib n) (define (iter a b count) (if (= count 0) b (iter (+ a b) a (- count 1)))) (iter 1 0 n))
;; (fib 10000)

;; 普通版
;(time (eval input the-global-environment))
; real   0.214
; user   0.202
; sys    0.000

;; analyze版
;;(fib 10000)
;(time (eval input the-global-environment))
; real   0.148
; user   0.218
; sys    0.000
