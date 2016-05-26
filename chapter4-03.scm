;; 4. 1. 5 プログラムとしてのデータ
;; gaucheではuser-initial-environment的なものは
;; (interaction-environment) で拾える
(eval '(* 5 5) (interaction-environment))
;; > 25
(eval (cons '* (list 5 5)) (interaction-environment))
;; > 25


;; 4.15
;; 背理法だ
;; try を(try try)って呼ぶと
;; 止まる場合　run-foreverになって止まらない
;; 止まらない場合 'haltedが戻ってきて止まる
;; ので矛盾してる。


;; 4.16
;; a.
(define (lookup-variable-value var env)
  (define (env-loop env)
    (define (scan vars vals)
      (cond ((null? vars)
             (env-loop (enclosing-environment env)))
            ((eq? var (car vars))
             (if (eq? (car vals) '*unassigned*) ;; ここが
				 (error "Unassigned variable" var) ;; かわり
				 (car vals)))                      ;; ました
			 (else (scan (cdr vars) (cdr vals)))))
    (if (eq? env the-empty-environment)
        (error "Unbound variable" var)
        (let ((frame (first-frame env)))
          (scan (frame-variables frame)
                (frame-values frame)))))
  (env-loop env))

;; b. これを作る
;; (lambda ⟨vars⟩
;;   (define u ⟨e1⟩)
;;   (define v ⟨e2⟩)
;;   ⟨e3⟩)
;; ↓
;; (lambda ⟨vars⟩
;;   (let ((u '*unassigned*)
;; 		(v '*unassigned*))
;; 	(set! u ⟨e1⟩)
;; 	(set! v ⟨e2⟩)
;; 	⟨e3⟩))

;; (define test-case '(lambda (var1 var2)
;; 					(define u 1)
;; 					(define v 2)
;; 					(display (+ var1 var2 u v))))
;; を　↓
;; '(lambda (var1 var2)
;;    (let ((u '*unassigned*)
;; 		 (v '*unassigned*))
;; 		 (set! u 1)
;; 		 (set! v 2)
;;       (display (+ var1 var2 u v)))))
;; てしたい問題

(define test-case '(lambda (var1 var2)
					(define u 1)
					(define v 2)
					(display (+ var1 var2 u v))))

(load "./chapter4-repl.scm")

;; ばらすやつを作った
(define (make-unassigned-set!-pair definition)
  (let ((var (cadr definition))
		(val (caddr definition)))
	(cons (list var '*unassigned*)
		  (list 'set! var val))))

(make-unassigned-set!-pair '(define u 1))
;;gosh> ((u *unassigned*) set! u 1)
(car (make-unassigned-set!-pair '(define u 1)))
;;gosh> (u *unassigned*)
(cdr (make-unassigned-set!-pair '(define u 1)))
;;gosh> (set! u 1)

(define (scan-out-defines body)
  (let* ((vars (cadr body))
		(defines (filter definition? body))
		(definition-pairs (map make-unassigned-set!-pair defines))
		(unassigned-defs (map car definition-pairs))
		(set-values (map cdr definition-pairs)))
	(list 'lambda vars
		  (list 'let unassigned-defs set-values 'rest))))

(scan-out-defines test-case)
;; gosh> (lambda (var1 var2) (let ((u *unassigned*) (v *unassigned*)) ((set! u 1) (set! v 2)) rest))
;; set!を外に出したいけどやり方がわからず・・1ヶ月経過したのであきらめた
;; こうらしい
;; http://www.serendip.ws/archives/1973


;;; 4.17
;; 4.6で作ったletはこんなだった
;; (define (let->combination sexp)
;;   (let ((vars-exps (cadr test-case))
;; 		(body (caddr test-case)))
;; 	((make-lambda (vars sexp)
;; 				  body
;; 				  env) (exp sexp)))) 
;;
;; ので、let1回でlamda1回分のフレームが作られる。
;; 図書いた
;; フレームが出来ないようにしつつ、'*unassigned* にできるようにすればいいので、
(lambda ⟨vars⟩
  (begin ((u '*unassigned*)
		  (v '*unassigned*))
		 (set! u ⟨e1⟩)
		 (set! v ⟨e2⟩)
		 ⟨e3⟩))
;; こうすればいいかも。
