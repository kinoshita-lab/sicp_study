;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;; 2.1.1
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
(define (make-rat n d)
 (cons n d))

(define (numer x)
  (car x))

(define (denom x)
  (cdr x))

(define (print-rat x)
  (newline)
  (display (numer x))
  (display "/")
  (display (denom x)))

(define (add-rat x y)
  (make-rat (+ (* (numer x) (denom y))
               (* (numer y) (denom x)))
            (* (denom x) (denom y))))

(define (sub-rat x y)
  (make-rat (- (* (numer x) (denom y))
               (* (numer y) (denom x)))
            (* (denom x) (denom y))))

(define (mul-rat x y)
  (make-rat (* (numer x) (numer y))
            (* (denom x) (denom y))))

(define (div-rat x y)
  (make-rat (* (numer x) (denom y))
            (* (denom x) (numer y))))

(define (equal-rat? x y)
  (= (* (numer x) (denom y))
     (* (numer y) (denom x))))


(define one-half (make-rat 1 2))
(print-rat one-half)

(define one-third (make-rat 1 3))
(print-rat (add-rat one-half one-third)
		   
(define (gcd a b)
  (if (= b 0)
      a
      (gcd b (remainder a b))))

(define (make-rat n d)
  (let ((g (gcd n d)))
    (cons (/ n g) (/ d g))))

(print-rat (add-rat one-third one-third)

;; exercise 2.1
(define (make-rat n d)
  (cond
   ((and (> n 0) (> d 0)) (cons n d))
   ((and (< n 0) (< d 0)) (cons (- n) (- d)))
   ((and (< n 0) (> d 0)) (cons n d))
   (else (cons (- n) (- d)))))

(make-rat -1  2)
(make-rat -1  -2)
(make-rat 1 -2)
(make-rat 1 2)
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;; 2.1.2
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
(define (make-rat n d)
  (cons n d))

(define (numer x)
  (let ((g (gcd (car x) (cdr x))))
    (/ (car x) g)))

(define (denom x)
  (let ((g (gcd (car x) (cdr x))))
    (/ (cdr x) g)))

(define hoge (make-rat 2 6))
(numer hoge)
(denom hoge)

;; exercise 2.2 start
(define (make-segment start end)
  (cons start end))

(define (start-segment segment)
  (car segment))

(define (end-segment segment)
  (cdr segment))

(define (make-point x y)
  (cons x y))

(define (x-point point)
  (car point))

(define (y-point point)
  (cdr point))

(define (print-point p)
  (newline)
  (display "(")
  (display (x-point p))
  (display ",")
  (display (y-point p))
  (display ")")
  (newline))
  
(define (midpoint-segment segment)
  (print-point (make-point (/ (+ (x-point (start-segment segment))
                                 (x-point (end-segment segment)))
                              2.0)
                           (/ (+ (y-point (start-segment segment))
                                 (y-point (end-segment segment)))
                              2.0))))

(define point1 (make-point 10 20))
(define point2 (make-point 30 40))
(define segment1 (make-segment point1 point2))
(midpoint-segment segment1)
;; exercise 2.2 end

;; exercise 2.3 start

;; point ver
(define (make-rectangle bottom-left top-right)
  (cons bottom-left top-right))

(define (bottom-left rectangle)
  (car rectangle))

(define (top-right rectangle)
  (cdr rectangle))

(define (x-distance rectangle)
  (abs (- (x-point (top-right rectangle)) (x-point (bottom-left rectangle)))))

(define (y-distance rectangle)
  (abs (- (y-point (top-right rectangle)) (y-point (bottom-left rectangle)))))

(define (perimeter rectangle)
  (* 2.0
     (+ (x-distance rectangle)
        (y-distance rectangle))))

(define (area rectangle)
  (* (x-distance rectangle)
     (y-distance rectangle)))
    
(define rectangle1 (make-rectangle
                    (make-point 10 20)
                    (make-point 30 40)))

(perimeter rectangle1)
(area rectangle1)

;; segment ver
(define (make-rectangle first-point second-point)
  (make-segment first-point second-point))

(define (x-distance rectangle)
  (abs (- (x-point (end-segment rectangle))
          (x-point (start-segment rectangle)))))

(define (y-distance rectangle)
  (abs (- (y-point (end-segment rectangle))
          (y-point (start-segment rectangle)))))

(define rectangle1 (make-rectangle
                    (make-point 10 20)
                    (make-point 30 40)))


(perimeter rectangle1)
(area rectangle1)

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;; 2.1.3
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
(define (cons x y)
  (define (dispatch m)
	(cond ((= m 0) x)
		  ((= m 1) y)
		  (else (error "Argument not 0 or 1 -- CONS" m))))
  dispatch)

(define (car z) (z 0))
(define (cdr z) (z 1))

(define hoge (cons 1 2))
(car hoge)
(cdr hoge)

;;; exercise 2.4
(define (cons x y)
  (lambda (m) (m x y)))

(define (car z)
  (z (lambda (p q) p)))

(define (cdr z)
  (z (lambda (p q) q)))

(define hoge (cons 1 2))
(car hoge)
(cdr hoge)

(car (cons x y))

; car
(z (lambda (p q) p))
((cons x y) (lambda (p q) p))
((lambda (m) (m x y)) (lambda (p q) p))
((lambda (p q) p) x y))
x

;;;;;;; 2.5
(define (cons a b)
  (* (expt 2 a)
     (expt 3 b)))

(define (factorize-with number factor)
  (define (iter n i)
    (if (or (= n 1)
            (not (= (remainder n factor) 0)))
        i
        (iter (/ n factor) (+ i 1))))
  (iter number 0))

(define (car x)
  (factorize-with x 2))

(define (cdr x)
  (factorize-with x 3))

(define test-data (cons 2 3))
(car test-data)
(cdr test-data)


;;; 2.6
(define zero (lambda (f) (lambda (x) x)))

(define (add-1 n)
  (lambda (f) (lambda (x) (f ((n f) x)))))

(add-1 zero)

(lambda (f) (lambda (x) (f ((zero f) x))))
(lambda (f) (lambda (x) (f (((lambda (f) (lambda (x) x)) f) x))))
(lambda (f) (lambda (f) (lambda (x) x)))

(add-1 (add-1 zero))
(lambda (f) (lambda (f) (lambda (f) (lambda (x) x))))

;;;;;;;;;;
;;; 2.1.4
;;;;;;;;;
;omit..


;;;;;;;;;;
;;; 2.2
;;;;;;;;;
(define nil '())
(cons 1
      (cons 2
            (cons 3
                  (cons 4 nil))))

(define one-through-four (list 1 2 3 4))
one-through-four
(car one-through-four)
(cdr one-through-four)
(car (cdr one-through-four))
(cons 10 one-through-four)
(cons 5 one-through-four)


(define (list-ref items n)
  (if (= n 0)
      (car items)
      (list-ref (cdr items) (- n 1))))

(define squares (list 1 4 9 16 25))
(list-ref squares 3)

(define (length items)
  (if (null? items)
      0
      (+ 1 (length (cdr items)))))

(define odds (list 1 3 5 7))
(length odds)


(define (length items)
  (define (length-iter a count)
    (if (null? a)
        count
        (length-iter (cdr a) (+ 1 count))))
  (length-iter items 0))
(length odds)

(append squares odds)
(append odds squares)

(define squares (list 1 4 9 16 25))


;; 2.17
(define (last-pair items)
  (define (length items)
    (if (null? items)
        0
        (+ 1 (length (cdr items)))))
  (if (= 1 (length items))
      items
      (last-pair (cdr items))))

(last-pair squares)


;; 2.18
(define (reverse items)
  (define (reverse-iter reversed items)
    (if (null? items)
        reversed
        (reverse-iter (append (list (car items)) reversed) (cdr items))))
  (reverse-iter '() items))
(reverse squares)


;; 2.19
(define (first-denomination denomination)
  (car denomination))

(define (except-first-denomination denomination)
  (cdr denomination))

(define (no-more? coin-values)
  (null? coin-values))

(define (cc amount coin-values)
  (cond ((= amount 0) 1)
        ((or (< amount 0) (no-more? coin-values)) 0)
        (else
         (+ (cc amount
                (except-first-denomination coin-values))
            (cc (- amount
                   (first-denomination coin-values))
                coin-values)))))

(define us-coins (list 50 25 10 5 1))
(define uk-coins (list 100 50 20 10 5 2 1 0.5))
(display (cc 100 us-coins))
(display (cc 100 uk-coins))

(define us-coins (list 50 25 10 5 1))
(display (cc 100 us-coins))
(define us-coins (list 1 5 10 25 50))
(display (cc 100 us-coins))

;; coinsの全種類の組み合わせを操作しているから順番は関係ないのではないか。

;; 2.20
(define (same-parity . items)
  (let ((parity (mod (car items) 2)))
    (define (same-parity-iter result remain)      
      (if (null? remain)
          result
          (if (= parity (mod (car remain) 2))
              (same-parity-iter (append result (list (car remain))) (cdr remain))
              (same-parity-iter result (cdr remain)))))
    (same-parity-iter '() items)))

(display (same-parity 1 2 3 4 5 6))
(newline)
(display (same-parity 2 3 4 5 6))

;;; リストの写像
(define nil '())
(define (scale-list items factor)
  (if (null? items)
      nil
      (cons (* (car items) factor)
            (scale-list (cdr items) factor))))

(scale-list (list 1 2 3 4 5) 10)

(define (map proc items)
  (if (null? items)
      nil
      (cons (proc (car items))
            (map proc (cdr items)))))
(map abs (list -10 2.5 -11.6 17))

(map (lambda (x) (* x x))
	 (list 1 2 3 4))

(define (scale-list items factor)
  (map (lambda (x) (* x factor))
       items))

(scale-list (list 1 2 3 4 5) 10)

;;2.21
(define nil '())
(define (square-list items)
  (if (null? items)
      nil
      (cons (* (car items) (car items))
            (square-list (cdr items)))))

(define (square-list items)
  (map (lambda (x) (* x x)) items))

(square-list (list 1 2 3 4))


;; 2.22
(define (square x)
  (* x x))

(define (square-list items)
  (define (iter things answer)
    (if (null? things)
        answer
        (iter (cdr things)
              (cons (square (car things))
                    answer))))
  (iter items '()))
(square-list (list 1 2 3 4))
;; -> (16 9 4 1)

;; 確かに逆になった。
;; consの順番が逆なんじゃない？
;; iterの部分を置き換えでやってみると、
;; (iter (list 1 2 3 4) '())
;; (iter (2 3 4) 1)
;; (iter (3 4) 4 1)
;; (iter (4) (9 4 1)
;; (iter '() (16 9 4 1)
;; (16 9 4 1)
;; ってなるね。

;;; Lous Reasonerの2番目のやつ
(define (square-list items)
  (define (iter things answer)
    (if (null? things)
        answer
        (iter (cdr things)
              (cons answer
                    (square (car things))))))
  (iter items '()))
(square-list (list 1 2 3 4))
;; ((((() . 1) . 4) . 9) . 16)
;; ぎゃー！これも置き換えで。
;; (cons '() 1) ってやるとどうなるの？
;; ('() . 1) ってなった。
;; (iter (list 1 2 3 4) '())
;; (iter (2 3 4) (cons '() 1))
;;   (iter (2 3 4) ('() . 1))
;; (iter (3 4) (cons ('() . 1) 4))
;;   (iter (3 4) (('() . 1) . 4))
;; (iter (4) (cons (('() . 1) . 4) 9))
;;   (iter (4) ((('() . 1) . 4) . 9))
;; (iter '() (cons ((('() . 1 ). 4) . 9) . 16)
;;   (iter (((('() . 1) . 4) . 9) . 16)
;; (((('() . 1) . 4 . 9) . 16)
;; (cons (cons '() 1) 4) は ((() . 1) . 4)
;; 答えはリストでほしいのでこの形のconsのかけかた（？）だとうまくいかない。
;; (cons 1 (cons 4 '())) というふうにしたかった。
;; consでできるのかわからないけど、2.20でやったみたいにappendでくっつけていけばできる。

(define (square-list items)
    (define (iter result remain)      
      (if (null? remain)
          result
          (iter (append result (list (square (car remain)))) (cdr remain))))
    (iter '() items))
(square-list (list 1 2 3 4))

;; 2.23
(for-each (lambda (x) (newline) (display x))
          (list 57 321 88))
;; gaucheだとfor-eachは最初から実装されてるみたいで↑動いた。

(define (my-for-each proc items)
  (define (iter proc remain)
    (if (null? remain)
        #t ;; 「任意のものであっていい」ってことでこうした。
        (proc (car remain)))
    (if (not (null? remain)) ;; くるしい。いい方法がありそう
             (iter proc (cdr remain))))
  (iter proc items))

(for-each (lambda (x) (newline) (display x))
          (list 57 321 88))
;;; 2.2.2
(cons (list 1 2) (list 3 4))

(define x (cons (list 1 2) (list 3 4)))
(length x)

(define (count-leaves x)
  (cond ((null? x) 0)
        ((not (pair? x)) 1)
        (else (+ (count-leaves (car x))
                 (count-leaves (cdr x))))))
(count-leaves x)

(list x x)
(length (list x x))
(count-leaves (list x x))

;; 2.24
(list 1 (list 2 (list 3 4)))
; got: gosh> (1 (2 (3 4)))

;; 2.25
(define list1 (list 1 3 (list 5 7) 9))
(define list2 (list (list 7)))
(define list3 (list 1 (list 2 (list 3 (list 4 (list 5 (list 6 7)))))))

(display (car (cdr (car (cdr (cdr list1))))))
(newline)
(display (car (car list2)))
(newline)
(display (car (cdr (car (cdr (car (cdr (car (cdr (car (cdr (car (cdr list3)))))))))))))

;; 2.26
(define x (list 1 2 3))
(define y (list 4 5 6))

(display (append x y))
; got: gosh> (1 2 3 4 5 6)#<undef>

(display (cons x y))
; got: gosh> ((1 2 3) 4 5 6)#<undef>

(display (list x y))
; got: gosh> ((1 2 3) (4 5 6))#<undef>

;; 2.27
;; 2.18を修正しようとしてあきらめた！
;; 再帰で書いたほうが修正らくっぽいね。
;; すぐ思いつかなかったので回答みてみた。再帰でやってるやつ発見した。
;; http://www.billthelizard.com/2010/12/sicp-218-reversing-list.html
(define (reverse items)
  (if (null? items)
      items
      (append (reverse (cdr items)) (list (car items)))))
(reverse (list 1 2 3 4))


(define (deep-reverse items)
  (if (pair? items)
      items
      (append (deep-reverse (cdr items)) (list (car items)))))

(define x (list (list 1 2) (list 3 4)))
(deep-reverse x)

;; 2.28
(define (fringe x)
  (cond ((null? x) '())
        ((not (pair? x)) (append (list x)))
        (else (append (fringe (car x))
                      (fringe (cdr x))))))
(define x (list (list 1 2) (list 3 4)))

(display (fringe x))
(newline)
(display (fringe (list x x)))

;; 2.29
(define (make-mobile left right)
  (list left right))

(define (make-branch length structure)
  (list length structure))

(define (left-branch mobile)
  (car mobile))

(define (right-branch mobile)
  (car (cdr mobile)))

(define (branch-length branch)
  (car branch))

(define (branch-weight branch)
  (if (number? (branch-structure branch))
      (branch-structure branch)
      (total-weight (branch-structure branch))))

(define (total-weight mobil)
  (+ (branch-weight (left-branch mobil))
     (branch-weight (right-branch mobil))))


(define (balanced-branch? branch)
  (if (number? (branch-structure branch))
      #t
      (balanced? (branch-structure branch))))

(define (balanced? mobil)
  (if (= (* (branch-length (left-branch mobil))
            (branch-weight (left-branch mobil)))
         (* (branch-length (right-branch mobil))
            (branch-weight (right-branch mobil))))
      (and (balanced-branch? (left-branch mobil))
           (balanced-branch? (right-branch mobil))) 
      #f))

;; 木の写像
(define (scale-tree tree factor)
  (cond ((null? tree) '())
        ((not (pair? tree)) (* tree factor))
        (else (cons (scale-tree (car tree) factor)
                    (scale-tree (cdr tree) factor)))))

(scale-tree (list 1 (list 2 (list 3 4) 5) (list 6 7))
            10)

(define (scale-tree tree factor)
  (map (lambda (sub-tree)
         (if (pair? sub-tree)
             (scale-tree sub-tree factor)
             (* sub-tree factor)))
       tree))
(define scalee-list (list 1 (list 2 (list 3 4) 5) (list 6 7)))
(scale-tree scalee-list 10)


;; (define (scale-list items factor)
;;   (if (null? items)
;;       '()
;;       (cons (* (car items) factor)
;;             (scale-list (cdr items) factor))))
;; (scale-list (list 1 2 3 4 5) 10)
;; (define (map proc items)
;;   (if (null? items)
;;       '()
;;       (cons (proc (car items))
;;             (map proc (cdr items)))))
;; (map abs (list -10 2.5 -11.6 17))
;; (define (scale-list items factor)
;;   (map (lambda (x) (* x factor))
;;        items))
;; (scale-list (list 1 2 3 4 5) 10)
;; ;;2.21
;; (define (square-list items)
;;   (if (null? items)
;;       '()
;;       (cons (* (car items) (car items))
;;             (square-list (cdr items)))))
;; (define (square-list items)
;;   (map (lambda (x) (* x x)) items))
;; (square-list (list 1 2 3 4))
;;

;; 再帰的
(define (square-tree tree)
  (cond ((null? tree) '())
        ((not (pair? tree)) (* tree tree))
        (else (cons (square-tree (car tree))
                    (square-tree (cdr tree))))))

(display (square-tree scalee-list))

;; lambdaで
(define (square-tree tree)
  (map (lambda (sub-tree)
         (if (pair? sub-tree)
             (square-tree sub-tree)
             (* sub-tree sub-tree)))
       tree))

(display (square-tree scalee-list))

;;;;;;;;;;;;;
;; 2.31
(define scale-list (list 1 (list 2 (list 3 4) 5) (list 6 7)))
(define (tree-map function tree)
  (map (lambda (sub-tree)
         (if (pair? sub-tree)
             (tree-map function sub-tree)
             (function sub-tree)))
       tree))

(define (square x)
  (* x x))

(define (square-tree tree) (tree-map square tree))

(display (square-tree scalee-list))

(display-tree scalee-list)
;;; 2.32
(define nil '())
(define (subsets s)
  (if (null? s)
      (list nil)
      (let ((rest (subsets (cdr s))))
        (append rest (map (lambda (x) (cons (car s) x))  rest)))))
(display (subsets '(1 2 3)))

;; 2.2.3
(define (sum-odd-squares tree)
  (cond ((null? tree) 0)
        ((not (pair? tree))
         (if (odd? tree) (square tree) 0))
        (else (+ (sum-odd-squares (car tree))
                 (sum-odd-squares (cdr tree))))))

(define nil '())
(define (even-fibs n)
  (define (next k)
    (if (> k n)
        nil
        (let ((f (fib k)))
          (if (even? f)
              (cons f (next (+ k 1)))
              (next (+ k 1))))))
  (next 0))

; 並びの演算
(define (square x)
  (* x x))

(map square (list 1 2 3 4 5))

(define (filter predicate sequence)
  (cond ((null? sequence) nil)
        ((predicate (car sequence))
         (cons (car sequence)
               (filter predicate (cdr sequence))))
        (else (filter predicate (cdr sequence)))))

(filter odd? (list 1 2 3 4 5))

(define (accumlate op initial sequence)
  (if (null? sequence)
      initial
      (op (car sequence)
          (accumlate op initial (cdr sequence)))))

(accumlate + 0 (list 1 2 3 4 5))

(accumlate * 1 (list 1 2 3 4 5))

(accumlate cons nil (list 1 2 3 4 5))

(define (enumerate-interval low high)
  (if (> low high)
      nil
      (cons low (enumerate-interval (+ low 1) high))))
(enumerate-interval 2 7)

(define (enumerate-tree tree)
  (cond ((null? tree) tree)
		((not (pair? tree)) (list tree))
		(else (append (enumerate-tree (car tree))
					  (enumerate-tree (cdr tree))))))
(enumerate-tree (list 1 (list 2 (list 3 4)) 5))


(define (sum-odd-squares tree)
  (accumlate +
			  0
			  (map square
				   (filter odd?
						    (enumerate-tree tree)))))

(define tmpTree (list 1 (list 2 (list 3 4)) 5))
(sum-odd-squares tmpTree)

(define nil '())
(define (fib n)
  (cond ((= n 0) 0)
        ((= n 1) 1)
        (else (+ (fib (- n 1))
                 (fib (- n 2))))))
(define (even-fibs n)
  (accumlate cons
			  nil
			  (filter even?
					  (map fib
					   (enumerate-interval 0 n)))))
(even-fibs 10)

(define (list-fib-squares n)
  (accumlate cons
			  nil
			  (map square
				   (map fib
						(enumerate-interval 0 n)))))
(list-fib-squares 10)

(define (product-of-squares-of-odd-elements sequence)
  (accumlate *
			  1
			  (map square
				   (filter odd? sequence))))
(product-of-squares-of-odd-elements (list 1 2 3 4 5))

(define (salary-of-highest-paid-programmer records)
  (accumlate max
			  0
			  (map salary
				   (filter programmer? records))))
; ↑は実行出来ない。

; excersize 2.33
;; (define (map proc items)
;;   (if (null? items)
;;       nil
;;       (cons (proc (car items))
;;             (map proc (cdr items)))))
(define (accumlate op initial sequence)
  (if (null? sequence)
      initial
      (op (car sequence)
          (accumlate op initial (cdr sequence)))))

(define nil '())
(define (map p sequence)
  (accumlate (lambda (x y)
			   (cons (p x) y))
			 nil
			 sequence))

(map odd? (list 1 2 3 4 5))

(define (append seq1 seq2)
  (accumlate cons seq2
			 seq1))
(append (list 1 2 3) (list 4 5 6))

(define (length sequence)
  (accumlate (lambda (x y)
			   (+ 1 y))
			 0
			 sequence))
(length (list 1 2 3))


;2.34
(define (horner-eval x coefficient-sequence)
  (accumlate (lambda (this-coeff higher-terms)
                (+ (* x higher-terms)
                   this-coeff))
             0
             coefficient-sequence))
(horner-eval 2 (list 1 3 0 5 0 1))

;2.35
;; 2.2.2のcount-leaves
;; (define (count-leaves x)
;;   (cond ((null? x) 0)
;;         ((not (pair? x)) 1)
;;         (else (+ (count-leaves (car x))
;;                  (count-leaves (cdr x))))))
(define (map p sequence)
  (accumlate (lambda (x y)
			   (cons (p x) y))
			 nil
			 sequence))
(define (accumlate op initial sequence)
  (if (null? sequence)
      initial
      (op (car sequence)
          (accumlate op initial (cdr sequence)))))
(define (count-leaves t)
  (define (map_func l)
    (cond ((null? l) 0)
          ((not (pair? l)) 1)
          (else (count-leaves l))))
  (accumlate + 0  (map map_func t)))
(define y (cons (list 1 2) (list 3 4)))
(count-leaves y)

;; 2.36
(define (accumlate-n op init seqs)
  (if (null? (car seqs))
      nil
      (cons (accumlate op init (map car seqs))
            (accumlate-n op init (map cdr seqs)))))
(define s (list (list 1 2 3) (list 4 5 6) (list 7 8 9) (list 10 11 12)))
(accumlate-n + 0 s)

;; 2.37
;; http://www.billthelizard.com/2011/04/sicp-236-237-matrix-algebra.html
(define v (list (list 1 2 3 4) (list 4 5 6 6) (list 6 7 8 9)))
(define (dot-product v w)
  (accumlate + 0 (map * v w)))
(define (matrix-*vector m v)
  (map (lambda (row) (dot-product row v)) m))
(define (transpose mat)
  (accumlate-n cons nil mat))
(transpose v)
(define (matrix-*-matrix m n)
  (let ((cols (transpose n)))
    (map (lambda (row) (matrix-*vector cols row)) m)))

 
;; 2.38
(define (fold-right op initial sequence)
(define (fold-right op initial sequence)
  (if (null? sequence)
      initial
      (op (car sequence)
          (accumlate op initial (cdr sequence)))))
(define (fold-left op initial sequence)
  (define (iter result rest)
    (if (null? rest)
        result
        (iter (op result (car rest))
              (cdr rest))))
  (iter initial sequence))

(fold-right / 1 (list 1 2 3))
; gosh> 3/2 (/ 3 (/ 2 1))
(fold-left / 1 (list 1 2 3))
; gosh> 1/6 (/ 1 (/ 2 3))

(fold-right list nil (list 1 2 3))
; gosh> (1 (2 (3 ())))
(fold-left list nil (list 1 2 3))
; gosh> (((() 1) 2) 3)

;; 交換法則が成り立つ？

;; 2.39(define (reverse items)
;; 2.18
;; (define (reverse-iter reversed items)
;;   (if (null? items)
;;       reversed
;;       (reverse-iter (append (list (car items)) reversed) (cdr items))))
;; (reverse-iter '() items))

(define (reverse sequence)
  (fold-right (lambda (x y)
                (append y (list x)))
              nil sequence))
(define hoge (list 1 2 3 4))
(reverse hoge)

(define (reverse sequence)
  (fold-left (lambda (x y)
               (cons y x))
             nil sequence))
(reverse hoge)

(define (enumerate-interval low high)
  (if (> low high)
      nil
      (cons low (enumerate-interval (+ low 1) high))))
(define (flatmap proc seq)
  (accumlate append nil (map proc seq)))
(define (prime-sum? pair)
  (prime? (+ (car pair) (cadr pair))))
(define (make-pair-sum pair)
  (list (car pair) (cadr pair) (+ (car pair) (cadr pair))))
(define nil '())
(define (accumlate op initial sequence)
  (if (null? sequence)
      initial
      (op (car sequence)
          (accumlate op initial (cdr sequence)))))
(define (prime-sum-pairs n)
  (map (make-pair-sum
        (filter prime-sum?
                (flatmap
                 (lambda (i)
                   (map (lambda (j) (list i j))
                        (enumerate-interval 1 (- i 1))))
                 (enumerate-interval 1 n))))))
(prime-sum-pairs 10)

(define (remove item sequence)
  (filter (lambda (x) (not (= x item)))
          sequence))
  
(define (permutations s)
  (if (null? s)
      (list nil)
      (flatmap (lambda (x)
                 (map (lambda (p) (cons x p))
                      (permutations (remove x s))))
               s)))


;; 2.40
(define (unique-pairs n)
  (define (nil '()))
  (define (flatmap proc seq)
    (accumlate append nil (map proc seq)))
  (define (enumerate-interval low high)
    (if (> low high)
        nil
        (cons low (enumerate-interval (+ low 1) high))))
  (flatmap (lambda (i)
             (map (lambda (j) (list j i))
                  (enumerate-interval 1 (- i 1))))
           (enumerate-interval 1 n)))
(unique-pairs 10)
;((1 2) (1 3) (2 3) (1 4) (2 4) (3 4) (1 5) (2 5) (3 5) (4 5) (1 6) (2 6) (3 6) (4 6) (5 6) (1 7) (2 7) (3 7) (4 7) (5 7) (6 7) (1 8) (2 8) (3 8) (4 8) (5 8) (6 8) (7 8) (1 9) (2 9) (3 9) (4 9) (5 9) (6 9) (7 9) (8 9) (1 10) (2 10) (3 10) (4 10) (5 10) (6 10) (7 10) (8 10) (9 10))
;; 良さげだけどこれでいいのかな？
(define (prime-sum-pairs n)
  (map (make-pair-sum
        (filter prime-sum?  
                (unique-pairs n)))))
;; 簡単にはなった。
;; 2.41
;; 2.40ベースで unique-triplesを作る必要ありそう
;; わからん動かんので
;; http://www.billthelizard.com/2011/05/sicp-240-241-nested-mappings.html
(define (ordered-triples n)
  (define (nil '()))
  (define (accumlate op initial sequence)
    (if (null? sequence)
        initial
        (op (car sequence)
            (accumlate op initial (cdr sequence)))))
  (define (flatmap proc seq)
    (accumlate append nil (map proc seq)))
  (define (enumerate-interval low high)
    (if (> low high)
        nil
        (cons low (enumerate-interval (+ low 1) high))))
  (flatmap (lambda (i)
             (flatmap (lambda (j)
                        (map (lambda (k)
                               (list i j k))
                             (enumerate-interval 1 (- j 1))))
                      (enumerate-interval 1 (- i 1))))
           (enumerate-interval 1 n)))
(define (ordered-triple-sum n s)
   (define (triple-sum? triple)
     (= s (accumulate + 0 triple)))
   (map make-triple-sum
        (filter triple-sum?
                (ordered-triples n))))
(ordered-triples 6)

;; 2.42
;; もはや写経
;; http://d.hatena.ne.jp/awacio/20100519/1274273076
(define (queens board-size)
  (define (enumerate-interval low high)
    (if (> low high)
        nil
        (cons low (enumerate-interval (+ low 1) high))))
  (define (queen-cols k)
    (if (= k 0)
        (list empty-board)
        (filter
         (lambda (positions) (safe? k positions))
         (flatmap
          (lambda (rest-of-queens)
            (map (lambda (new-row)
                   (adjoin-position new-row
                                    k
                                    rest-of-queens))
                 (enumerate-interval 1 board-size)))
          (queen-cols (- k 1))))))
  (queen-cols board-size))
 (define (enumerate-interval low high)
    (if (> low high)
        nil
        (cons low (enumerate-interval (+ low 1) high))))
(define empty-board '())
(define nil '())
(define (safe? k lis)
  (if (null? lis)
      #t
      (let loop ((head (car lis))
		 (body (cdr lis))
		 (count 1))
	(cond ((null? body) #t)
	      ((or (= head (car body))
		   (= head (+ (car body) count))
		   (= head (- (car body) count)))
	       #f)
	      (else
	       (loop head (cdr body) (+ 1 count)))))))

(define (adjoin-position new-row k rest-of-queens)
  (cons new-row rest-of-queens))
 (define (accumlate op initial sequence)
    (if (null? sequence)
        initial
        (op (car sequence)
            (accumlate op initial (cdr sequence)))))
  (define (flatmap proc seq)
    (accumlate append nil (map proc seq)))
(queens 10)


;; 2.43
;; はあ http://www.serendip.ws/archives/798
;; Louisのやつは board-size * board-sizeかかる
;; 普通のやつはboard-size回かかる？  
