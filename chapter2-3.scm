; 2.3.1
'(a b c)
(car '(a b c))
(cdr '(a b c))

(define (memq item x)
  (cond ((null? x) false)
        ((eq? item (car x)) x)
        (else (memq item (cdr x)))))

(memq 'apple '(pear banana prune))

(memq 'apple '(x (apple sauce) y apple pear))

;わかんね
(memq 'apple '(pear banana prune)) ; => #f
(memq 'apple '(apple pear banana prune)) ; => (apple pear banana prune) 
                                        ; 一致したらそこから先を全部表示するというものみたい

;; 2.53
(list 'a 'b 'c)
; => (a b c)

(list (list 'george))
; => ((george))

(cdr '((x1 x2) (y1 y2)))
; => ((y1 y2))

(cadr '((x1 x2) (y1 y2)))
; => (y1 y2)

(pair? (car '(a short list)))
; => #f
(pair? '(a b c)) ; リストか？
(memq 'red '((red shoes) (blue socks)))
; => #f

(memq 'red '(red shoes blue socks))
; =>  (red shoes blue socks)

;; 2.54
(define (equal? a b)
  (cond 
   ((and (null? a) (null? b)) #t)
   ((and (not (pair? a)) (not (pair? b)))
    (eq? a b))
   ((or (not (pair? a)) (not (pair? b))) #f)
   (else (and (equal? (car a) (car b))
              (equal? (cdr a) (cdr b))))))

(use slib)
(require 'trace) 
(trace equal?)   
(equal? '(this is a list) '(this is a list))
(equal? '(this is a list) '(this (is a) list))

;; 2.55
(car ''abracadabra)
;gosh> quote
'
;gosh> quote
; 'はquoteに変わっているっぽいから、
(car ''abracadabra)
;は
(car (quote (quote abracadabra)))
;で、
;quoteと表示される。

;2.3.2 記号微分
(define (variable? x) (symbol? x))

(define (same-variable? v1 v2)
  (and (variable? v1) (variable? v2) (eq? v1 v2)))

(define (make-sum a1 a2)
  (list '+ a1 a2))

(define (make-product m1 m2)
  (list '* m1 m2))

(define (sum? x)
  (and (pair? x) (eq? (car x) '+)))

(define (addend s) (cadr s))

(define (augend s) (caddr s))

(define (product? x)
  (and (pair? x) (eq? (car x) '*)))

(define (multiplier p) (cadr p))

(define (multiplicand p) (caddr p))

(define (deriv exp var)
  (cond ((number? exp) 0)
        ((variable? exp)
         (if (same-variable? exp var) 1 0))
        ((sum? exp)
         (make-sum (deriv (addend exp) var)
                   (deriv (augend exp) var)))
        ((product? exp)
         (make-sum
          (make-product (multiplier exp)
                        (deriv (multiplicand exp) var))
          (make-product (deriv (multiplier exp) var)
                        (multiplicand exp))))
        (else
         (error "unknown expression type -- DERIV" exp))))


(deriv '(+ x 3) 'x)
(deriv '(* x y) 'x)

(deriv '(* (* x y) (+ x 3)) 'x)

(define (=number? exp num)
  (and (number? exp) (= exp num)))

(define (make-sum a1 a2)
  (cond ((=number? a1 0) a2)
        ((=number? a2 0) a1)
        ((and (number? a1) (number? a2)) (+ a1 a2))
        (else (list '+ a1 a2))))

(define (make-product m1 m2)
  (cond ((or (=number? m1 0) (=number? m2 0)) 0)
        ((=number? m1 1) m2)
        ((=number? m2 1) m1)
        ((and (number? m1) (number? m2)) (* m1 m2))
        (else (list '* m1 m2))))

(deriv '(+ x 3) 'x)
(deriv '(* x y) 'x)
(deriv '(* (* x y) (+ x 3)) 'x)

; 2.56
(define (exponentiation? x)
  (and (pair? x) (eq? (car x) '**)))

(define (base x)
  (cadr x))

(define (exponent x)
  (caddr x))

(define (make-exponentiation base exponent)
  (cond ((=number? exponent 0) 1)
        ((=number? exponent 1) base)
        (else (list '** base exponent))))

(define testvalue (make-exponentiation 'x 2))
(base testvalue)
(exponent testvalue)
        
; 書き換える
(define (deriv exp var)
  (cond ((number? exp) 0)
        ((variable? exp)
         (if (same-variable? exp var) 1 0))
        ((sum? exp)
         (make-sum (deriv (addend exp) var)
                   (deriv (augend exp) var)))
        ((product? exp)
         (make-sum
          (make-product (multiplier exp)
                        (deriv (multiplicand exp) var))
          (make-product (deriv (multiplier exp) var)
                        (multiplicand exp))))
        ((exponentiation? exp)
         (make-product (make-product (exponent exp) 
                                     (make-exponentiation (base exp) (- (exponent exp) 1)))
                       (deriv (base exp) var)))
        (else
         (error "unknown expression type -- DERIV" exp))))

(deriv '(** x 2) 'x)

;よさげ。
;gosh >(* 2 x)

; 2.57
; たとえば + x y 3
; みたいなのがあったとして
(define test '(+ x y 3))
(define (addend s) (cadr s))
(addend test)

; これが大変だった
(define (augend s) 
  (let ((rest (cdddr s)))
    (if (null? rest) (caddr s) (cons '+ (cddr s)))))

(define (multiplier p) (cadr p))

(define (multiplicand s) 
  (let ((rest (cdddr s)))
    (if (null? rest) (caddr s) (cons '* (cddr s)))))

(deriv '(* x y (+ x 3)) 'x)
;gosh> (+ (* x y) (* y (+ x 3)))

;; 2.58
;a
(define (make-sum a1 a2)
  (cond ((=number? a1 0) a2)
        ((=number? a2 0) a1)
        ((and (number? a1) (number? a2)) (+ a1 a2))
        (else (list a1 '+ a2))))

(define (make-product m1 m2)
  (cond ((or (=number? m1 0) (=number? m2 0)) 0)
        ((=number? m1 1) m2)
        ((=number? m2 1) m1)
        ((and (number? m1) (number? m2)) (* m1 m2))
        (else (list m1 '* m2))))

(define sumtest (make-sum 'x 1))
(define sumtest2 (make-sum 'x '(* 1 y)))
(define producttest (make-product 'x 2))
; gosh> (x + 1)
; gosh> (x * 2)
(define (addend s) (car s))

(define (augend s) 
  (caddr s) (caddr s))
(addend sumtest)
(augend sumtest)
(addend sumtest2)
(augend sumtest2)
; なんとなくよさげ


(define (multiplier p) (car p))
(define (multiplicand s)
  (caddr s))
; こっちもこんなかな
 

(define (sum? x)
  (and (pair? x) (eq? (cadr x) '+)))

(define (product? x)
  (and (pair? x) (eq? (cadr x) '*)))

; ここまで仕込んだらいけるのではないか
(deriv '((x * y) * (x + 3)) 'x)
;gosh> ((x * y) + (y * (x + 3)))

;; b むずすぎる
;(x + 3 * (x + y + 2))
;; a記法にできるか？
;(x + (3 * (x + (y + 2))))
(define muzui-expression '(x + 3 * (x + y + 2)))
; 何も考えずいきなり突っ込んでみる
(trace deriv)
(deriv muzui-expression 'x)

; 諦めた
; これがわかりやすかった
; https://wizardbook.wordpress.com/2010/12/07/exercise-2-58/
