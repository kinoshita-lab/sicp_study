;; analyze版だった chapter4-04.scmベースっぽい

;; eval
;; http://www.serendip.ws/archives/1817
;; ↑eval の定義を apply の定義よりも先に行っていたために、eval の定義の中で使っていた apply 手続きが Gauche のシステムの apply 手続きを利用していたために動作しなかったらしい。
;; apply の定義を eval の定義よりも先に行うようにしたところ、正常に動作するようになった。

;; 基盤の apply への参照を apply-in-underlying-scheme へ退避させる（こうすることで、基盤の apply に apply-in-underlying-scheme という名前でアクセスできる）。
(define apply-in-underlying-scheme apply)
;; apply
(define (apply procedure arguments)
  (cond ((primitive-procedure? procedure)
         (apply-primitive-procedure procedure arguments))
        ((compound-procedure? procedure)
         (eval-sequence
          (procedure-body procedure)
          (extend-environment
           (procedure-parameters procedure)
           arguments
           (procedure-environment procedure))))
        (else
         (error
          "Unknownn procedure type: APPLY" procedure))))

(define (eval exp env)
  (cond ((self-evaluating? exp) exp)
        ((variable? exp) (lookup-variable-value exp env))
        ((quoted? exp) (text-of-quotation exp))
        ((assignment? exp) (eval-assignment exp env))
        ((definition? exp) (eval-definition exp env))
        ((if? exp) (eval-if exp env))
        ((lambda? exp) (make-procedure (lambda-parameters exp)
                                       (lambda-body exp)
                                       env))
        ((begin? exp)
         (eval-sequence (begin-actions exp) env))
        ((cond? exp) (eval (cond->if exp) env))
        ((application? exp)
         (apply (eval (operator exp) env)
                (list-of-values (operands exp) env)))
        (else
         (error "Unknown expression type: eval" exp))))

;; 中身
(define (list-of-values exps env)
  (if (no-operands? exps)
      '()
      (cons (eval (first-operand exps) env) ;; 1個ずつevalに入れる
            (list-of-values (rest-operands exps) env))))

(define (eval-if exp env)
  (if (true? (eval (if-predicate exp) env))
      (eval (if-consequent exp) env)
      (eval (if-alternative exp) env)))

(define (eval-sequence exps env)
  (cond ((last-exp? exps)
         (eval (first-exp exps) env))
         (else
          (eval (first-exp exps) env)
          (eval-sequence (rest-exps exps) env))))

(define (eval-assignment exp env)
  (set-variable-value! (assignment-variable exp)
                       (eval (assignment-variable exp) env)
                       env)
  'ok)

(define (eval-definition exp env)
  (define-variable! (definition-variable exp)
                    (eval (definition-value exp) env)
                    env)
  'ok)

;; 自己評価式
(define (self-evaluating? exp)
  (cond ((number? exp) true)
        ((string? exp) true)
        (else false)))

;; この後で使うtagged-listの定義
(define (tagged-list? exp tag)
  (if (pair? exp)
      (eq? (car exp) tag)
      false))

;; 変数
(define (variable? exp) (symbol? exp))

;; クオート式
(define (quoted? exp) (tagged-list? exp 'quote))
(define (text-of-quotation exp) (cadr exp))

;; 代入
(define (assignment? exp) (tagged-list? exp 'set!))
(define (assignment-variable exp) (cadr exp))
(define (assignment-value exp) (caddr exp))

;; 定義
(define (definition? exp) (tagged-list? exp 'define))
(define (definition-variable exp)
  (if (symbol? (cadr exp))
      (cadr exp)
      (caadr exp)))
(define (definition-value exp)
  (if (symbol? (cadr exp))
      (caddr exp)
      (make-lambda (cdadr exp)
                   (cddr exp))))

;; lambda式
(define (lambda? exp) (tagged-list? exp 'lambda))
(define (lambda-parameters exp) (cadr exp))
(define (lambda-body exp) (cddr exp))
(define (make-lambda parameters body)
  (cons 'lambda (cons parameters body)))

;; 条件式
(define (if? exp) (tagged-list? exp 'if))
(define (if-predicate exp) (cadr exp))
(define (if-consequent exp) (caddr exp))
(define (if-alternative exp)
  (if (not (null? (cdddr exp)))
      (cadddr exp)
      'false))
(define (make-if predicate consequent alternative)
  (list 'if predicate consequent alternative))

;; begin
(define (begin? exp) (tagged-list? exp 'begin))
(define (begin-actions exp) (cdr exp))
(define (last-exp? seq) (null? (cdr seq)))
(define (first-exp seq) (car seq))
(define (rest-exps seq) (cdr seq))
(define (sequence->exp seq)
  (cond ((null? seq) seq)
        ((last-exp? seq) (first-exp seq))
        (else (make-begin seq))))
(define (make-begin seq) (cons 'begin seq))

;; 手続き適用
(define (application? exp) (pair? exp))
(define (operator exp) (car exp))
(define (operands exp) (cdr exp))
(define (no-operands? ops) (null? ops))
(define (first-operand ops) (car ops))
(define (rest-operands ops) (cdr ops))

;; condの実装 派生式
(define (cond? exp) (tagged-list? exp 'cond))
(define (cond-clauses exp) (cdr exp))
(define (cond-else-clause? clause)
  (eq? (cond-predicate clause) 'else))
(define (cond-predicate clause) (car clause))
(define (cond-actions clause) (cdr clause))
(define (cond-if exp) (expand-clauses (cond-clauses exp)))
(define (expand-clauses clauses)
  (if (null? clauses)
      'false
      (let ((first (car clauses))
            (rest (cdr clauses)))
        (if (cond-else-clause? first)
            (if (null? rest)
                (sequence->exp (cond-actions first))
                (error "ELSE clause isn't last: COND->IF" clauses))
            (make-if (cond-predicate first)
                     (sequence->exp (cond-actions first))
                     (expand-clauses rest))))))

;; 述語のテスト
(define true #t) ;; これいる
(define false #f) ;; これいる
(define (true? x)
  (not (eq? x false)))

(define (false? x)
  (eq? x false))

;; 手続きの表現
(define (make-procedure parameters body env)
  (list 'procedure parameters body env))

(define (compound-procedure? p)
  (tagged-list? p 'procedure))

(define (procedure-parameters p) (cadr p))

(define (procedure-body p) (caddr p))

(define (procedure-environment p) (cadddr p))

;; 環境に対する操作
(define (enclosing-environment env) (cdr env))

(define (first-frame env) (car env))

(define the-empty-environment '())

(define (make-frame variables values)
  (cons variables values))

(define (frame-variables frame) (car frame))

(define (frame-values frame) (cdr frame))

(define (add-binding-to-frame! var val frame)
  (set-car! frame (cons var (car frame)))
  (set-cdr! frame (cons val (cdr frame))))

(define (extend-environment vars vals base-env)
  (if (= (length vars) (length vals))
      (cons (make-frame vars vals) base-env)
      (if (< (length vars) (length vals))
          (error "Too many arguments supplied" vars vals)
          (error "Too few arguments supplied" vars vals))))

(define (lookup-variable-value var env)
  (define (env-loop env)
    (define (scan vars vals)
      (cond ((null? vars)
             (env-loop (enclosing-environment env)))
            ((eq? var (car vars))
             (car vals))
            (else (scan (cdr vars) (cdr vals)))))
    (if (eq? env the-empty-environment)
        (error "Unbound variable" var)
        (let ((frame (first-frame env)))
          (scan (frame-variables frame)
                (frame-values frame)))))
  (env-loop env))


(define (set-variable-value! var val env)
  (define (env-loop env)
    (define (scan vars vals)
      (cond ((null? vars)
             (env-loop (enclosing-environment env)))
            ((eq? var (car vars))
             (set-car! vals val))
            (else (scan (cdr vars) (cdr vals)))))
    (if (eq? env the-empty-environment)
        (error "Unbound variable -- SET!" var)
        (let ((frame (first-frame env)))
          (scan (frame-variables frame)
                (frame-values frame)))))
  (env-loop env))

(define (define-variable! var val env)
  (let ((frame (first-frame env)))
    (define (scan vars vals)
      (cond ((null? vars)
             (add-binding-to-frame! var val frame))
            ((eq? var (car vars))
             (set-car! vals val))
            (else (scan (cdr vars) (cdr vals)))))
    (scan (frame-variables frame)
          (frame-values frame))))

;; 4.1.4 評価器をプログラムとして走らせる
(define (setup-environment)
  (let ((initial-env
         (extend-environment (primitive-procedure-names)
                             (primitive-procedure-objects)
                             the-empty-environment)))
    (define-variable! 'true true initial-env)
    (define-variable! 'false false initial-env)
    initial-env))

;; (define the-global-environment (setup-environment))

(define (primitive-procedure? proc)
  (tagged-list? proc 'primitive))

(define (primitive-implementation proc) (cadr proc))

(define primitive-procedures
  (list (list 'car car)
        (list 'cdr cdr)
        (list 'cons cons)
        (list 'null? null?)
		(list '+ +) ;; for 4.24
		(list '- -)
		(list '= =)
		(list 'list list) ;; これないと試しづらい
		(list 'not not)
		(list 'eq? eq?)
		(list 'even? even?)
        ))

(define (primitive-procedure-names)
  (map car
       primitive-procedures))

(define (primitive-procedure-objects)
  (map (lambda (proc) (list 'primitive (cadr proc)))
       primitive-procedures))

(define (apply-primitive-procedure proc args)
  (apply-in-underlying-scheme
   (primitive-implementation proc) args))

(define input-prompt ";;; M-Eval input:")
(define output-prompt ";;; M-Eval value:")

(define (driver-loop)
  (prompt-for-input input-prompt)
  (let ((input (read)))
    (let ((output (eval input the-global-environment)))
      (announce-output output-prompt)
      (user-print output)))
  (driver-loop))
;; for 4.24
(define (driver-loop)
  (prompt-for-input input-prompt)
  (let ((input (read)))
    ;; time マクロを組み込む
    (let ((output (time (eval input the-global-environment))))
      (announce-output output-prompt)
      (user-print output)))
  (driver-loop))

(define (prompt-for-input string)
  (newline) (newline) (display string) (newline))

(define (announce-output string)
  (newline) (display string) (newline))

(define (user-print object)
  (if (compound-procedure? object)
      (display (list 'compound-procedure
                     (procedure-parameters object)
                     (procedure-body object)
                     ))
      (display object)))

(define the-global-environment (setup-environment))

;; 4-04.scmからanalyze版
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


;; let足した版なので
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

;; 問題4.22からlet拾ってくる
 (define (let-vars expr) (map car (cadr expr))) 
 (define (let-inits expr) (map cadr (cadr expr))) 
 (define (let-body expr) (cddr expr)) 

 (define (let->combination expr) 
   (cons (make-lambda (let-vars expr) (let-body expr)) 
         (let-inits expr))) 

;; ↑で必要なのを作る
(define (vars s)
  (cond ((eq? s '()) '())
		(else  (cons (caar s) (vars (cdr s))))))
(define (vals s)
  (cond ((eq? s '()) '())
		(else  (cons (cadar s) (exp (cdr s))))))

;;; ==============================
;;; ここからがAMB実装
;;; ==============================
(define (amb? exp) (tagged-list? exp 'amb))
(define (amb-choices exp) (cdr exp))
;; ディスパッチに追加
(define (analyze exp)
  (cond ((self-evaluating? exp) (analyze-self-evaluating exp))
		((quoted? exp) (analyze-quoted exp))
		((amb? exp) (analyze-amb exp)) ;; これ足した　上の方にないとだめ
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

;; eval
(define (ambeval exp env succeed fail)
  ((analyze exp) env succeed fail))

;; 単純な式
;; 通常版だとこんな感じになってて、引数にsuceedとｆailが増えている (継続渡し CPSとかいうらしい)
;; (define (analyze-variable exp)
;;   (lambda (env) (lookup-variable-value exp env)))
(define (analyze-self-evaluating exp)
  (lambda (env succeed fail)
	(succeed exp fail)))
(define (analyze-quoted exp)
  (let ((qval (text-of-quotation exp)))
	(lambda (env succeed fail)
	  (succeed qval fail))))
(define (analyze-variable exp)
  (lambda (env succeed fail)
	(succeed (lookup-variable-value exp env) fail)))
(define (analyze-lambda exp)
  (let ((vars (lambda-parameters exp))
		(bproc (analyze-sequence (lambda-body exp))))
	(lambda (env succeed fail)
	  (succeed (make-procedure vars bproc env) fail))))

;; 条件式と列 (シーケンスのことだった)
(define (analyze-if exp)
  (let ((pproc (analyze (if-predicate exp)))
		(cproc (analyze (if-consequent exp)))
		(aproc (analyze (if-alternative exp))))
	(lambda (env succeed fail)
	  (pproc env
			 ;; pred-valueを得るための
			 ;; 述語の評価に対する成功継続
			 (lambda (pred-value fail2)
			   (if (true? pred-value)
				   (cproc env succeed fail2)
				   (aproc env succeed fail2)))
			 ;; 述語の評価に対する失敗継続
			 fail))))

(define (analyze-sequence exps)
  (define (sequentially a b)
	(lambda (env succeed fail)
	  (a env
		 ;; aの呼び出しの成功継続
		 (lambda (a-value fail2)
		   (b env succeed fail2))
		 fail)))
  (define (loop first-proc rest-procs)
	(if (null? rest-procs)
		first-proc
		(loop (sequentially first-proc
							(car rest-procs))
			  (cdr rest-procs))))
  (let ((procs (map analyze exps)))
	(if (null? procs)
		(error "Empty sequence: ANALYZE"))
	(loop (car procs) (cdr procs))))

;; 定義と代入
(define (analyze-definition exp)
  (let ((var (definition-variable exp))
		(vproc (analyze (definition-value exp))))
	(lambda (env succeed fail)
	  (vproc env
			 (lambda (val fail2)
			   (define-variable! var val env)
			   (succeed 'ok fail2))
			 fail))))
(define (analyze-assignment exp)
  (let ((var (assignment-variable exp))
		(vproc (analyze (assignment-value exp))))
	(lambda (env succeed fail)
	  (vproc env
			 (lambda (val fail2)
			   (let ((old-value
					  (lookup-variable-value var env)))
				 (set-variable-value! var val env)
				 (succeed 'ok
						  (lambda ()
							(set-variable-value!
							 var old-value env)
							(fail2)))))
			 fail))))

;; 手続きの適用
(define (analyze-application exp)
  (let ((fproc (analyze (operator exp)))
		(aprocs (map analyze (operands exp))))
	(lambda (env succeed fail)
	  (fproc env
			 (lambda (proc fail2)
			   (get-args aprocs
						 env
						 (lambda (args fail3)
						   (execute-application
							proc args succeed fail3))
						 fail2))
			 fail))))

(define (get-args aprocs env succeed fail)
  (if (null? aprocs)
	  (succeed '() fail)
	  ((car aprocs)
	   env
	   ;; このaprocの成功継続
	   (lambda (arg fail2)
		 (get-args
		  (cdr aprocs)
		  env
		  ;; get-argsの再帰的呼び出しのための
		  ;; 成功継続
		  (lambda (args fail3)
			(succeed (cons arg args) fail3))
		  fail2))
	   fail)))

(define (execute-application proc args succeed fail)
  (cond ((primitive-procedure? proc)
		 (succeed (apply-primitive-procedure proc args)
				  fail))
		((compound-procedure? proc)
		 ((procedure-body proc)
		  (extend-environment
		   (procedure-parameters proc)
		   args
		   (procedure-environment proc))
		  succeed
		  fail))
		(else
		 (error "Unknown procedure type: EXECUTE-APPLICATION"
				proc))))

;; amb式の評価
(define (analyze-amb exp)
  (let ((cprocs (map analyze (amb-choices exp))))
	(lambda (env succeed fail)
	  (define (try-next choises)
		(if (null? choises)
			(fail)
			((car choises)
			 env
			 succeed
			 (lambda () (try-next (cdr choises))))))
	  (try-next cprocs))))

(define input-prompt ";;; Amb-Eval input:")
(define output-prompt ";;; Amb-Eval value:")

(define (driver-loop)
  (define (internal-loop try-again)
	(prompt-for-input input-prompt)
	(let ((input (read)))
	  (if (eq? input 'try-again)
		  (try-again)
		  (begin
			(newline) (display ";;; Starting a new problem ")
			(ambeval
			 input
			 the-global-environment
			 ;; ambeval success
			 (lambda (val next-alternative)
			   (announce-output output-prompt)
			   (user-print val)
			   (internal-loop next-alternative))
			 ;; ambeval failure
			 (lambda ()
			   (announce-output
				";;; There are no more values of")
			   (user-print input)
			   (driver-loop)))))))
  (internal-loop
   (lambda ()
	 (newline) (display ";;; There is no current problem")
	 (driver-loop))))



;; これを解き放つとrepl
;;(driver-loop)
;; 試
;;(list (amb 1 2 3) (amb 'a b))
