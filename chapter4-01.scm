;; 4.1.1 評価器のコア

;; eval
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

;; apply
(define (apply procedure arguments)
  (cond ((primitive-procedure? procedure)
         (apply-primitive-procedure procedure argments))
        ((compound-procedure? procedure)
         (eval-sequence
          (procedure-body procedure)
          (extend-environment
           (procedure-parameters procedure)
           arguments
           (procedure-environment procedure))))
        (else
         (error
          "Unknown procedure type: APPLY" procedure))))

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

;; 4.1
;; fold-leftとかfold-rightとかだ 2章でやったけどすっかり忘れた
(define (list-of-values-left exps env) ;; ってこれそのままだ
  (if (no-operands? exps)
      '()
      (cons (eval (first-operand exps) env)
            (list-of-values-left (rest-operands exps) env))))

;;;; こうやると裏から評価してくれる
;; (define (rv lst)
;;   (if (eq? '() lst)
;;       lst
;;       (cons (rv (cdr lst)) (car lst))))
;; ので
(define (list-of-values-right exps env)
  (if (no-operands? exps)
      exps
      (cons (eval (list-of-values-right (rest-operands exps) env))
            (first-operand exps))))
;; こうかな。
;; cf. こうらしい　違ったかな って interaction-environmentってなんだ http://www.serendip.ws/archives/1808

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

;; ここまで作ってみたけど、これって動かせないのかな？
;; 4.2
;; a
;; でたLouis
;;     ((application? exp)
;;         (apply (eval (operator exp) env)
;;                (list-of-values (operands exp) env)))
;; こいつを割と上の方に持ってくるとどうなるか？ということね。
; application? は pair? で引っ掛けるので、
(pair? '(define x 3)) ;; が #tになるので application? に入っていってしまう。
; で "define" という名前の手続きを探しに行ってしまうから definition? が動かなくなってしまう。
;
;; b
; 手続き適用 のところを軒並み変更
(cddr '(call + 1 2))
(define (application? exp) (tagged-list? exp 'call))
(define (operator exp) (cadr exp))
(define (operands exp) (cddr exp))
(define (no-operands? ops) (null? ops)) ;; ここはそのまま
(define (first-operand ops) (car ops)) ;; ここもそのまま
(define (rest-operands ops) (cdr ops)) ;; ここもそのまま

;; evalの中身
;; ((application? exp)
;;  (apply (eval (operator exp) env)
;;         (list-of-values (operands exp) env)))
;; はこのままでよさげ
