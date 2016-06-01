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
  (begin (set! u '*unassigned*)
		 (set! v '*unassigned*)
		 (set! u ⟨e1⟩)
		 (set! v ⟨e2⟩)
		 ⟨e3⟩))
;; こうすればいいかも。
;; 違ったから直した

;; 4.18
;; なんでこの問題やってたのかを見失ってしまった。
;; 変数が同時に定義できるようにするためだった。
(define (solve f y0 dt)
  (define y (integral (delay dy) y0 dt))
  (define dy (stream-map f y))
  y)

;; 問題文の変形
(lambda (f y0 dt)
  (let ((y '*unassigned*) (dy '*unassigned*))
	(let ((a (integral (delay dy) y0 dt)) ;; let->combinationの中でdyの値が必要
		  (b (stream-map f y))  ;; let->combinationの中でyの値が必要
		  (set! u a) 
		  (set! v b))
	  y)))

;; 本文中の変形
(lambda (f y0 dt)
  (let ((y '*unassigned*)
		(dy '*unassigned*))
	(set! y (integral (delay dy) y0 dt)) ;; eval-assignmentの中で dyの値を使わない
	(set! dy (stream-map f y)) ;; eval-assignmentの中でyの値を使わない
	y))

;; ってことで本文の方は動くけど問題のはダメらしい。 http://d.hatena.ne.jp/rucifer_hacker/20090331/1238480075

;; 4.19
(let ((a 1))
  (define (f x)
	(define b (+ a x))
	(define a 5)
	(+ a b))
  (f 10))
;; (define b..)は (+ a x) という手続きの定義であって、評価がここでされているわけではないきがする
;; (+ a b) が実際に評価される時に必要になる。そのときにはaは5に確定しているので、 (+ 5 (+ 5 10)) で20になる
;; ・・のでEvaの見方が良いような気がするけど同時だから？というわけではない。
;; (define a (+ 1 2)) とおもったけどこれは3がかえってくる

;; gaucheでやったら20返ってきた。
;; ここに詳しく書いてある 本当は set! に置き換えているらしい。
;; http://practical-scheme.net/wiliki/wiliki.cgi?Scheme%3A%E5%86%85%E9%83%A8define%E3%81%AE%E8%A9%95%E4%BE%A1%E9%A0%86
;; 
;; 内部定義を実装するには　↑のメンタルモデルみたいに + をすぐに評価しないで使うときに評価すればいいと思う

;; 4.20
;; letrec試してみる
(letrec
	((fact (lambda (n) 
			 (if (= n 1) 1 (* n (fact (- n 1)))))))
  (fact 10))
;; gosh> 3628800
;; へー
;; ↑をletだけにするには・・？
(let ((fact '*unassigned*))
  (set! fact (lambda (n)
			   (if (= n 1) 1 (* n (fact (- n 1))))))
  (fact 10))
;; こうしたら動いた

(define letrec-test-case 
  '(letrec
	  ((fact (lambda (n)
				(if (= n 1) 1 (* n (fact (- n 1)))))))
	 (fact 10)))
letrec-test-case
;; gosh > (letrec ((fact (lambda (n) (if (= n 1) 1 (* n (fact (- n 1))))))) (fact 10))

(define (letrec->let lr)
  (let* ((letrec-names (map car (cadr lr))) ;; (fact)
		 (letrec-defines (map cadr (cadr lr))) ;; ((lambda (n) (if (= n 1) 1 (* n (fact (- n 1))))))
		 (letrec-body (cddr lr))) ;;  ((fact 10)) 
	(list 'let (map (lambda (li) (list li '*unassigned*)) letrec-names)
		  (append (map (lambda (var val) (list 'set! (cons var val))) letrec-names letrec-defines)))))

(letrec->let letrec-test-case)
;; gosh> (let ((fact *unassigned*)) ((set! (fact lambda (n) (if (= n 1) 1 (* n (fact (- n 1))))))))
;; よさげ。評価機に組み込むのは略

;; b. 絵をかいた。
;; 1個環境増えるけど再帰的な定義ができるって感じだと思った。

;; 4.21
((lambda (n)
   ((lambda (fact) (fact fact n))
	(lambda (ft k) (if (= k 1) 1 
					   (* k (ft ft (- k 1)))))))
 10)
;; gosh> 3628800 ;; なった

;; a. fib
((lambda (n)
   ((lambda (fib) (fib fib n))
	(lambda (fb k) 
	  (cond ((= k 0) 0)
			((= k 1) 1)
			(else (+ (fb fb (- k 2))
					 (fb fb (- k 1))))))))
 10)
;; gosh> 55

;; b. 元はこれ
(define (f x)
  (define (even? n)
	(if (= n 0) true (odd? (- n 1))))
  (define (odd? n)
	(if (= n 0) false (even? (- n 1))))
  (even? x))



(define (f x)
  ((lambda (even? odd?) (even? even? odd? x))
   (lambda (ev? od? n) ;; evenぽい方
	 (if (= n 0) true (od? ev? od? (- n 1)))) ;; ここで先頭2つ入れ替えるとodd呼ばれる
   (lambda (ev? od? n) ;; oddぽい方
	 (if (= n 0) false (ev? od? od? (- n 1))))))　;; ここで先頭2つ入れ替えるとeven呼ばれる
(f 10)
(f 11)
  
