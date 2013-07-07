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

(define (scale-list items factor)
  (if (null? items)
      '()
      (cons (* (car items) factor)
            (scale-list (cdr items) factor))))

(scale-list (list 1 2 3 4 5) 10)

(define (map proc items)
  (if (null? items)
      '()
      (cons (proc (car items))
            (map proc (cdr items)))))
(map abs (list -10 2.5 -11.6 17))

(define (scale-list items factor)
  (map (lambda (x) (* x factor))
       items))


(scale-list (list 1 2 3 4 5) 10)

;;2.21
(define (square-list items)
  (if (null? items)
      '()
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

(define (for-each proc items)
  (define (iter proc remain)
    (if (null? remain)
        #t ;; 「任意のものであっていい」ってことでこうした。
        (proc (car remain)))
    (if (not (null? remain)) ;; くるしい。いい方法がありそう
             (iter proc (cdr remain))))
  (iter proc items))

(for-each (lambda (x) (newline) (display x))
          (list 57 321 88))
;;;
(cons (list 1 2) (list 3 4))

(define x (cons (list 1 2) (list 3 4)))
(length x)

(define (count-leaves x)
  (cond ((null? x) 0)
        ((not (pair? x)) 1)
        (else (+ (count-leaves (car x))
                 (count-leaves (cdr x))))))
(count-leaves x)

;; 2.24
(list 1 (list 2 (list 3 4)))

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
(newline)
(display (cons x y))
(newline)
(display (list x y))

;; 2.27
;; 2.18を修正しようとしてあきらめた！
;; 再帰で書いたほうが修正らくっぽいね。
;; すぐ思いつかなかったので解凍みてみた。再帰でやってるやつ発見した。
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

;; SICP 2.29
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
(define (scale-tree factor)
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
(define scalee-list (list 1 (list 2 (list 3 4) 5) (list 6 7)))
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
                
