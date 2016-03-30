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

;; 動作しなくてイライラしてたのでreplまでのせてみた。
;; chapter4-repl.scm
;; windowsのemacs上でgosh -iするとreplが表示されないなあ
;; powershellでやるか
;; 4.3
;; データ主導ってなんだっけ
;; putとかgetとかのやつか
;; メッセージパッシングのほうが個人的にはいいな。
;; まあ問題だからとくか

(load "./chapter2_utility.scm") ;; 懐かしい・・
(load "./chapter4-repl.scm") ;; 標準品を読み込んでおいて定義を上書きする作戦

;; こんなのをつくればいいのかな。
(define (install-quote-package)
  ;; 内部手続き
  (define (text-of-quotation exp) (print exp) (cadr exp))
  ;; 外部とのインタフェース
  (put 'eval 'quote text-of-quotation)
  'ok)


(install-quote-package)
;; gosh> ok
put-lists
;; gosh> ((eval quote #<closure (install-quote-package text-of-quotation)>))
(use slib)
(require 'trace)
(trace get)
(get 'eval 'quote)
;; gosh> #<closure (install-quote-package text-of-quotation)>
(define q '('quote 1 2 3))
(car q)
(define f '('quote 1 2 3))
((get 'eval (car (car f)) f)

 ;; gosh> (1 2 3)
 ;; 欲しかったものなのかな。とりあえず。元々のtext-of-quatationは (cadr exp)で中身を取ってきていたけどそうもいかなさそう。

 ;; これに対応するパッケージ
 ;;  ((assignment? exp) (eval-assignment exp env)) 
 (define (install-assignment-package)
   ;; 内部手続たち
   (define (assignment-variable exp) (cadr exp))
   (define (assignment-value exp) (caddr exp))
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
   (define (eval-assignment exp env)
     (set-variable-value! (assignment-variable exp)
                          (eval (assignment-variable exp) env))
     'ok)
   ;; 外部とのインタフェース
   (put 'eval 'assignment eval-assignment)
   'ok)
 ;; definition ((definition? exp) (eval-definition exp env))
 (define (install-definition-package)
   (define (eval-definition exp env)
     (define-variable! (definition-variable exp)
       (eval (definition-value exp) env)
       env)
     'ok)

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
   
   ;; 外部とのインタフェース
   (put 'eval 'definition eval-definition)
   'ok)

 ;; if   ((if? exp) (eval-if exp env))
 (define (install-if-package)
   (define (eval-if exp env)
     (if (true? (eval (if-predicate exp) env))
         (eval (if-consequent exp) env)
         (eval (if-alternative exp) env)))

   (define (if-predicate exp) (cadr exp))
   (define (if-consequent exp) (caddr exp))
   (define (if-alternative exp)
     (if (not (null? (cdddr exp)))
         (cadddr exp)
         'false))
   (put 'eval 'if eval-if)
   'ok)
 ;; lambda    ((lambda? exp) (make-procedure (lambda-parameters exp)
 ;;                                       (lambda-body exp)
 ;;                                       env))
 (define (install-labmda-package)
   (define (make-procedure parameters body env)
     (list 'procedure parameters body env))
   (define (compound-procedure? p)
     (tagged-list? p 'procedure))
   (define (procedure-parameters p) (cadr p))
   (define (procedure-body p) (caddr p))
   (define (procedure-environment p) (cadddr p))
   
   ;; make-procedureを呼んでも lambda-parametersとlambda-bodyが実行できるタイミングはなくなっちゃうので、
   ;; 固めたのを返す関数が必要だと思う
   (define (make-make-procedure env exp) ;; 変な名前！
     (make-procedure (lambda-parameters exp)
                     (lambda-body exp)
                     env))

   (put 'eval 'procedure make-make-procedure)
   'ok)

 (define (install-begin-package)
   (define (begin-actions exp) (cdr exp))
   (define (last-exp? seq) (null? (cdr seq)))
   (define (first-exp seq) (car seq))
   (define (rest-exps seq) (cdr seq))
   (define (sequence->exp seq)
     (cond ((null? seq) seq)
           ((last-exp? seq) (first-exp seq))
           (else (make-begin seq))))
   (define (make-begin seq) (cons 'begin seq))

   ;; これもlambdaとおなじでmake-begin呼ぶようにするとこまりそう
   (define (make-make-begin exp env)
     (eval-sequence (begin-actions exp) env))
   
   (put 'eval 'begin make-make-begin)
   'ok)

 (define (install-cond-package)
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

   ;; 外部用
   (define (eval-cond exp env)
     (eval (cond->if exp) env))

   (put 'eval 'cond-cond)
   'ok)

 ;; applyは無理

 ;; 多分こんな感じだと思う
 ;; でこのパッケージ用のevalを作る
 ;; self-evaluating, variable, application? はタグがついてないので無理

 (define (eval exp env)
   (cond ((self-evaluating? exp) exp)
         ((variable? exp) (lookup-variable-value exp env))
         ;; パッケージあれば実行
         (else
          (let ((proc (get 'eval (car exp))))
            (if proc
                (proc (cdr exp))
                ;; なくてapplyだったら実行
                (if (application? exp)
                    (apply (eval (operator exp) env)
                           (list-of-values (operands exp) env))
                    (error "Unknown expression type: eval" exp)))))))
 ;; 使うときはこんな感じ
 (clear-putlist) ;; 全消し
 (install-quote-package)
 (install-assignment-package)
 (install-definition-package)
 (install-if-package)
 (install-labmda-package)
 (install-begin-package)
 (install-cond-package)


;;;;; 4.4
 (load "./chapter4-repl.scm")
 (define env the-global-environment)

 ;; evalを書きかえてこんな感じにする
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
         ;; ここに追加
         ((and? exp) (eval-and exp env))
         ((or? exp) (eval-or exp env))
         ;; 追加ココマデ
         
         ((begin? exp)
          (eval-sequence (begin-actions exp) env))
         ((cond? exp) (eval (cond->if exp) env))
         ((application? exp)
          (apply (eval (operator exp) env)
                 (list-of-values (operands exp) env)))
         (else
          (error "Unknown expression type: eval" exp))))

                                        ; 
 (define (and? exp) (tagged-list? exp 'and))
 (define (or? exp) (tagged-list? exp 'and))

 (define (eval-and exp env)
   (my-and (cdr exp) env))

 (define (eval-or exp env)
   (my-or (cdr exp) env))

 (define (my-and arg env)
   (cond ((eq? '() arg) #f) ;; nilだったら#f
         ((atom? arg) (eval arg env)) ;; atomだったらそいつを評価
         (let ((first-element (car arg))
               (rest-elements (cdr arg)))
           (if (eval first-element env) ;; 1個目評価して
               (my-and rest-elements env) ;; #tだったら次
               #f)))) ;; #fだったらその時点で#f返す

 (define (my-or arg env)
   (cond ((eq? '() arg) #f) ;; nilだったら#f
         ((atom? arg) (eval arg env)) ;; atomだったらそいつを評価
         (let ((first-element (car arg)) 
               (rest-elements (cdr arg)))
           (if (eval first-element) ;; 1個目評価して
               #t ;; #tだったらその時点で#t
               (my-or rest-elements env))))) ;; #fだったらさいごまでやる



 ;; その2　派生編 ifに変えてみよう
 ;; cond->ifと同じかんじで。
 ;; and
 (define (and-clauses exp) (cdr exp))
 (define (and->if exp) (expand-and-clauses (and-clauses exp)))
 (define (expand-and-clauses clauses)
   (define (iter clauses result)
     (if (null? clauses)
         result ;; これまでの結果
         (let ((first (car clauses))
               (rest (cdr clauses)))
           (make-if first ;; ここ#tだったら終了
                    (iter rest first) ;;　違ったら続き
                    #f))))
   (iter clauses #f))

 ;; or
 (define (or-clauses exp) (cdr exp))
 (define (or->if exp) (expand-or-clauses (or-clauses exp)))
 (define (expand-or-clauses clauses)
   (define (iter clauses)
     (if (null? clauses)
         #f
         (let ((first (car clauses))
               (rest (cdr clauses)))
           (make-if first
                    first
                    (iter rest)))))
   (iter clauses))

 ;; evalはこういう感じに書き換える
 ;; evalを書きかえてこんな感じにする
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
         ;; ここから
         ((and? exp) (eval (and->if exp) env))
         ((or? exp) (eval (or->if exp) env))
         ;; ここまで
         
         ((begin? exp)
          (eval-sequence (begin-actions exp) env))
         ((cond? exp) (eval (cond->if exp) env))
         ((application? exp)
          (apply (eval (operator exp) env)
                 (list-of-values (operands exp) env)))
         (else
          (error "Unknown expression type: eval" exp))))

 ;;　4.5
 (cond ((assoc 'b '((a 1) (b 2))) => cadr)
       (else false))
                                        ; gosh> 2
                                        ; へー
                                        ; expand clausesを改造すればいいよね
 (define (expand-clauses clauses)
   (if (null? clauses)
       'false
       (if (arrow-expression? clauses) ;; 4.5 こんな
           (arrow->if clauses) ;; 4.5 感じにした
           (let ((first (car clauses))
                 (rest (cdr clauses)))
             (if (cond-else-clause? first)
                 (if (null? rest)
                     (sequence->exp (cond-actions first))
                     (error "ELSE clause isn't last: COND->IF" clauses))
                 (make-if (cond-predicate first)
                          (sequence->exp (cond-actions first))
                          (expand-clauses rest)))))))

 ;; ということで2つ作るよ。
 (define (arrow-expression? clauses)
   (equal? (cadar clauses) '=>))

 (define test-case
   '('cond ((assoc 'b '((a 1) (b 2))) => cadr)
           (else false)))
 test-case
 ;; gosh> ('cond ((assoc 'b '((a 1) (b 2))) => cadr) (else false))
 (arrow-expression? (cond-clauses test-case))
 ;; #t
 ;; よさげ
 (define (predicate clauses) (caar clauses))
 (define (operator clauses) (caddar clauses))
 (define (arrow->if clauses)
   (make-if (predicate clauses)
            (list operator (predicate clauses))
            #f))


 (predicate (cond-clauses test-case))
 (operator (cond-clauses test-case))
 (arrow->if (cond-clauses test-case))
 ;; gosh> (if #0=(assoc 'b '((a 1) (b 2))) (#<closure operator> #0#) #f)
 ;; よさげ


 ;; 4.6

 (define test-case (list 'let '((v1 e1) (v2 e2)) 'body))
 test-case
 ;; >  (let ((v1 e1) '(v2 e2)) body)
 ;; こんな。



 (caddr test-case)
 ;; こんなかな。
 (define (let->combination sexp)
   (let ((vars-exps (cadr test-case))
         (body (caddr test-case)))
     ((make-lambda (vars sexp)
                   body
                   env) (exp sexp)))) 

 ;; ↑で必要なのを作る
 (define (vars s)
   (cond ((eq? s '()) '())
         (else  (cons (caar s) (vars (cdr s))))))
 (vars (cadr  test-case))
 ;; gosh> (v1 v2) ;; とれた
 (trace exp)
 (define (exp s)
   (cond ((eq? s '()) '())
         (else  (cons (cadar s) (exp (cdr s))))))
 (exp (cadr test-case))
 ;; (e1 e2)

 ;; evalに組み込む用
 (define (let? exp) (tagged-list? exp 'let))
 (define (eval-let let-clause env)
   (eval (let->combination let-clause) env))


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
         ;; ここから
         ((let? exp (eval-let exp env)))
         ;; ここまで
         ((begin? exp)
          (eval-sequence (begin-actions exp) env))
         ((cond? exp) (eval (cond->if exp) env))
         ((application? exp)
          (apply (eval (operator exp) env)
                 (list-of-values (operands exp) env)))
         (else
          (error "Unknown expression type: eval" exp))))


 ;; 4.7
 ;; (let* ((x 3) 
 ;;        (y (+ x 2)) 
 ;;        (z (+ x y 5)))
 ;;   (* x z)))
 ;; を
 ;; (let ((x 3))
 ;;   (let ((y (+ x 2)))
 ;;     (let ((z (+ x y 5)))
 ;;       (* x z))))
 ;; こう変形すしたい　という問題

 (define test-case  '(let* ((x 3) 
                            (y (+ x 2)) 
                            (z (+ x y 5)))
                       (* x z)))
 test-case
 ;; (let* ((x 3) (y (+ x 2)) (z (+ x y 5))) (* x z))

                                        ; evalに組み込む用
 (define (let*? exp) (tagged-list? exp 'let*))
 (let*? test-case)
 ;; #t
 (define (let*-clauses exp) (cdr exp))
 (let*-clauses test-case)
 ;; (((x 3) (y (+ x 2)) (z (+ x y 5))) (* x z))
 (define (let*-bindings clauses)
   (car clauses))
 (let*-bindings (let*-clauses test-case))
 ;; ((x 3) (y (+ x 2)) (z (+ x y 5)))


 (define (let*-body clauses) (cadr (let*-clauses test-case)))
 (let*-body (let*-clauses test-case))
 ;; gosh> (* x z)

 ;; letだらけに変形する
 (define (nested-let bind body)
   (if (null? bind) body
       (list 'let (list (car bind) (nested-let (cdr bind) body)))))
 (trace nested-let)
 (nested-let (let*-bindings (let*-clauses test-case)) (let*-body (let*-clauses test-case)))
 ;; > (let ((x 3) (let ((y (+ x 2)) (let ((z (+ x y 5)) (* x z)))))))

 ;; eval
 (define (eval-let* exp env)
   (let* ((clauses (let*-clauses exp))
          ((binding (let*-bindings exp)))
          ((body (let*-body exp))))
     (eval (nested-let binding body) env)))

 ;; evalに突っ込む
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
         ;; ここから
         ;; letは必要
         ((let? exp (eval-let exp env)))
         ((let*? exp (eval-let* exp env)))
         ;; ここまで
         ((begin? exp)
          (eval-sequence (begin-actions exp) env))
         ((cond? exp) (eval (cond->if exp) env))
         ((application? exp)
          (apply (eval (operator exp) env)
                 (list-of-values (operands exp) env)))
         (else
          (error "Unknown expression type: eval" exp))))
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; 4.8
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
 ;; named letの意味がぜんぜんわからない
 (define (fib n)
   (let fib-iter ((a 1)
                  (b 0)
                  (count n))
     (if (= count 0)
         b
         (fib-iter (+ a b) a (- count 1)))))
 (fib 10)
 ;; 55
 ;; 確かに動いているっぽい
 ;; これといっしょだよね。
 (define (fib n)
   (define (fib-iter a b count)
     (if (= count 0)
         b
         (fib-iter (+ a b) a (- count 1))))
   (fib-iter 1 0 n))
 ;; こう変えればいいのかな。
 ;; ほんとうは
 (define (fib n)
   (letrec ((fib-iter (lambda (a b count)
                        (if (= count 0)
                            b
                            (fib-iter (+ a b) a (- count 1))))))
     (fib-iter 1 0 n)))
 (fib 10)
 ;; こうすればいいのだろうけど・・むり

 (define test-case '(let fib-iter ((a 1)
                                   (b 0)
                                   (count n))
                      (if (= count 0)
                          b
                          (fib-iter (+ a b) a (- count 1)))))
 test-case
 ;; (let fib-iter ((a 1) (b 0) (count n)) (if (= count 0) b (fib-iter (+ a b) a (- count 1))))
 (define (let->combination sexp)
   (if (named-let? sexp) ;; ここと
       (named-let->function sexp)  ;; ここ増やした
       (let ((vars-exps (cadr test-case))
             (body (caddr test-case)))
         ((make-lambda (vars sexp)
                       body
                       env) (exp sexp)))))

 ;; implる
 (define (named-let? exp)
   (define atom? ;; scheme手習いのやつ
     (lambda (x)
       (and (not (pair? x)) (not (null? x)))))
   (atom? (cadr exp)))
 ;;(define not-ok '(let ((a 1) (b 0) (count n))))
 ;;(named-let? not-ok)
 ;; #f
 ;;(named-let? test-case)
 ;; #t

 (define (named-let-clauses exp)
   (cdr exp))
 ;; (named-let-clauses test-case)
 ;; gosh> (fib-iter ((a 1) (b 0) (count n)) (if (= count 0) b (fib-iter (+ a b) a (- count 1))))

 (define (named-let-name clause)
   (car clause))
 ;; (named-let-name (named-let-clauses test-case))
 ;; fib-iter

 (define (named-let-bindings clause)
   (cadr clause))
 ;; (named-let-bindings (named-let-clauses test-case))
 ;; gosh> ((a 1) (b 0) (count n))

 (define (named-let-initial-values bindings)
   (define (iter b)
     (if (null? b) '()
         (cons (cadr (car b)) (iter (cdr b)))))
   (iter bindings))
 ;; (named-let-initial-values (named-let-bindings (named-let-clauses test-case)))
 ;; gosh> (1 0 n)
 ;; これせっかくだからnamed letで書いてみると
 (define (named-let-initial-values bindings)
   (let iter ((b bindings))
     (if (null? b) '()
         (cons (cadr (car b)) (iter (cdr b))))))
 ;; (named-let-initial-values (named-let-bindings (named-let-clauses test-case)))
 ;; gosh> (1 0 n)
 ;; うごいた。

 (define (named-let-parameters bindings)
   (let iter ((b bindings))
     (if (null? b) '()
         (cons (caar b) (iter (cdr b))))))
 ;; (named-let-parameters (named-let-bindings (named-let-clauses test-case)))
 ;; (a b count)

 (define (named-let-function-body clause)
   (caddr clause))
 ;; (named-let-function-body (named-let-clauses test-case))
 ;; gosh> (if (= count 0) b (fib-iter (+ a b) a (- count 1)))

 ;; ここまでを合体
 (define (named-let->function sexp)
   (let* ((clauses (named-let-clauses sexp))
          (function-name (named-let-name clauses))
          (function-body (named-let-function-body clauses))
          (function-parameters (named-let-parameters (named-let-bindings clauses)))
          (initial-values (named-let-initial-values (named-let-bindings clauses))))
     (list (list 'define (list function-name function-parameters function-body)) ;; 関数を定義して
           (list function-name initial-values)))) ;; 呼ぶ
 (named-let->function test-case)
 ;; gosh> ((define (fib-iter (a b count) (if (= count 0) b (fib-iter (+ a b) a (- count 1))))) (fib-iter (1 0 n)))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; 4.9
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; 繰り返すfor
;; defineで書くとこんなかな。
(define (for start end func)
  (let loop ((s start) 
			 (e end)
			 (f func))
	(if (= s e) '()
		(begin (func)
			   (loop (+ 1 s) e func)))))
(for 1 10 (lambda () (print "Hoge")))
;; gosh> Hoge
;; Hoge
;; Hoge
;; Hoge
;; Hoge
;; Hoge
;; Hoge
;; Hoge
;; Hoge
;; ()

(define test-case 
  '(for 1 10 (lambda () (print "Hoge"))))
;; test-case
;; gosh> (for 1 10 (lambda () (print "Hoge")))

;; evalに組み込む用
(define (for? exp) (tagged-list? exp 'for))
;;(for? test-case)
;; #t

(define (for-clauses exp) (cdr exp))
;; (for-clauses test-case)
;; gosh> (1 10 (lambda () (print "Hoge")))

(define (for-start clause) (car clause))
;; (for-start (for-clauses test-case))
;; 1

(define (for-end clause) (cadr clause))
;; (for-end (for-clauses test-case))
;; 10

(define (for-func clause) (caddr clause))
(for-func (for-clauses test-case))
;; gosh> (lambda () (print "Hoge"))

(define (for->named-let exp)
  (let* ((clause (for-clauses exp))
		 (start (for-start clause))
		 (func (for-func clause))
		 (end (for-end clause)))
	(list 'let 'loop (list (list 's start)
						   (list 'e end)
						   (list 'f func))
		  (list 'if '(= s e) '()
				(list 'begin '(f)
					  (list 'loop '(+ 1 s) 'e 'f) )))))
(for->named-let test-case)
;; gosh> (let loop ((s 1) (e 10) (f (lambda () (print "Hoge")))) (if (= s e) () (begin (f) (loop (+ 1 s) e f))))
;; できた。

(define (eval-for exp env)
  (eval (for->named-let exp) env))

;; 入れる
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
		;; ここから
		((let? exp (eval-let exp env)))　;; letいる
		((for? exp (eval-for exp env))) ;;
		;; ここまで
		((begin? exp)
		 (eval-sequence (begin-actions exp) env))
		((cond? exp) (eval (cond->if exp) env))
		((application? exp)
		 (apply (eval (operator exp) env)
				(list-of-values (operands exp) env)))
		(else
		 (error "Unknown expression type: eval" exp))))


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; 4.10
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; なんでもいいのかな (1 + 1) -> 2 みたいなのつくってみる 2項までじゃないとめんどい
(define test-case '(1 + 1))
;; test-case
;; gosh> (1 + 1)

(define (my-math-operator exp)
  (cadr exp))
;;(my-math-operator test-case)
;; +

;; eval用
(define (my-math-expression? exp)
  (let ((op (my-math-operator exp)))
	(or (eq? '+ op)
		(eq? '- op)
		(eq? '* op)
		(eq? '/ op))))
;; #t


;; 変形用
(define (my-math->normal-function exp)
  (let ((first-operand (car exp))
		(operator (my-math-operator exp))
		(second-operand (caddr exp)))
	(list operator first-operand second-operand)))
(my-math->normal-function test-case)
;; (+ 1 1)
;; できた

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
		;; これを
		((my-math-expression? exp) (eval (my-math->normal-function exp)))
		;; 足した

		((begin? exp)
		 (eval-sequence (begin-actions exp) env))
		((cond? exp) (eval (cond->if exp) env))
		((application? exp)
		 (apply (eval (operator exp) env)
				(list-of-values (operands exp) env)))
		(else
		 (error "Unknown expression type: eval" exp))))
