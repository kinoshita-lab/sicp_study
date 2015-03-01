(use slib)
(require 'trace)
; quackで;;;ってやると背景が変わって分かりやすいので使う
;;;
;;; 2.5.1 汎用算術演算
;;;
;;  attach-tag,put, get, apply-genericいるっぽい
(define (attach-tag type-tag contents)
  (cons type-tag contents))

(define put-lists '())

(define (clear-putlist)
  (set! put-lists '()))

(define (put op type item)
  (if (get op type) put-lists
  (set! put-lists (cons (list op type item) put-lists)))) ; set!っての使えばやりたいことできそう

(define (get op type) 
  (define (get-operator listItem)
    (car listItem))

  (define (get-type listItem)
    (cadr listItem))

  (define (get-item listItem)
    (caddr listItem))

  (define (get-iter list op type)
    (if (null? list) #f
        (let ((top (car list)))
          (if (and (equal? op (get-operator top))
                   (equal? type (get-type top))) (get-item top)
                   (get-iter (cdr list) op type)))))
  (get-iter put-lists op type))

(define (contents datum)
  (if (pair? datum)
      (cdr datum)
      (error "Bad tagged datum -- CONTENTS" datum)))

(define (apply-generic op . args)
  (let ((type-tags (map type-tag args)))
    (print type-tags)
    (let ((proc (get op type-tags)))
      (print proc)
      (if proc
          (apply proc (map contents args))
          (error
           "No method for these types -- APPLY-GENERIC"
           (list op type-tags))))))

(define (type-tag datum)
  (if (pair? datum)
      (car datum)
      (error "Bad tagged datum -- TYPE-TAG" datum))); なぜ急にエラーチェック？
(define (install-scheme-number-package)
  (define (tag x)
    (attach-tag 'scheme-number x))
  (put 'add '(scheme-number scheme-number)
       (lambda (x y) (tag (+ x y))))
  (put 'sub '(scheme-number scheme-number)
       (lambda (x y) (tag (- x y))))
  (put 'mul '(scheme-number scheme-number)
       (lambda (x y) (tag (* x y))))
  (put 'div '(scheme-number scheme-number)
       (lambda (x y) (tag (/ x y))))
  (put 'make 'scheme-number
       (lambda (x) (tag x)))
  'done)

(define (make-scheme-number n)
  ((get 'make 'scheme-number) n))

; 使ってみる
(install-scheme-number-package)
(define a (make-scheme-number 10))
(define b (make-scheme-number 5))
a
; gosh> (scheme-number . 10)
b
; gosh> (scheme-number . 5)
(get 'add '(scheme-number scheme-number))
; あれ #fが返ってきた
;(eq? '(scheme-number scheme-number) '(scheme-number scheme-number))
;これ#fだ
;こういうときは equal? を使えばいいみたい
; https://www.shido.info/lisp/scheme5.html
(get 'add '(scheme-number scheme-number))
; #<closure (install-scheme-number-package #:G235)>
; なんか返ってきたので演算に適用
;((get 'add '(scheme-number scheme-number)) a b)
; *** ERROR: operation + is not defined between (scheme-number . 5) and (scheme-number . 10)
; ???
; apply-generic経由で使ってみる
(define (add x y) (apply-generic 'add x y))
(define (sub x y) (apply-generic 'sub x y))
(define (mul x y) (apply-generic 'mul x y))
(define (div x y) (apply-generic 'div x y))

(install-scheme-number-package)
(add a b)
; (scheme-number . 15)
; お　できた(ここに至るまでに上のを色々と書き換えた)

; 有理数
(define (install-rational-package)
  ;; 内部手続き
  (define (numer x) (car x))
  (define (denom x) (cdr x))
  (define (make-rat n d)
    (let ((g (gcd n d)))
      (cons (/ n g) (/ d g))))
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

  ;; システムの他の部分へのインターフェース
  (define (tag x) (attach-tag 'rational x))
  (put 'add '(rational rational)
       (lambda (x y) (tag (add-rat x y))))
  (put 'sub '(rational rational)
       (lambda (x y) (tag (sub-rat x y)))) ; この辺省略できそう
  (put 'mul '(rational rational)
       (lambda (x y) (tag (mul-rat x y))))
  (put 'div '(rational rational)
       (lambda (x y) (tag (div-rat x y))))

  (put 'make 'rational
       (lambda (n d) (tag (make-rat n d))))
  'done)
(define (make-rational n d)
  ((get 'make 'rational) n d))

(clear-putlist)
(install-scheme-number-package)
(install-rational-package)

(define c (make-rational 1 2))
(define d (make-rational 1 3))

(add c d)
; gosh> (rational 5 . 6)
(sub c d)
; gosh> (rational 1 . 6)
(mul c d)
; gosh> (rational 1 . 6)
(div c d)
; gosh> (rational 3 . 2)

; よさげ。

; 次複素数
(define (install-complex-package)
  ;; 直交座標と極座標パッケージから取り入れた手続き
  (define (make-from-real-imag x y)
    ((get 'make-from-real-imag 'rectangular) x y))
  (define (make-from-mag-ang r a)
    ((get 'make-from-mag-ang 'polar) r a))

  ;; 内部手続き
  (define (add-complex z1 z2)
    (make-from-real-imag (+ (real-part z1) (real-part z2))
                         (+ (imag-part z1) (imag-part z2))))
  (define (sub-complex z1 z2)
    (make-from-real-imag (- (real-part z1) (real-part z2))
                         (- (imag-part z1) (imag-part z2))))
  (define (mul-complex z1 z2)
    (make-from-mag-ang (* (magnitude z1) (magnitude z2))
                       (+ (angle z1) (angle z2))))
  (define (div-complex z1 z2)
    (make-from-mag-ang (/ (magnitude z1) (magnitude z2))
                       (- (angle z1) (angle z2))))
  
  ;; システムの他の部分へのインターフェース
  (define (tag z) (attach-tag 'complex z))
  (put 'add '(complex complex)
       (lambda (z1 z2) (tag (add-complex z1 z2))))
  (put 'sub '(complex complex)
       (lambda (z1 z2) (tag (sub-complex z1 z2))))
  (put 'mul '(complex complex)
       (lambda (z1 z2) (tag (mul-complex z1 z2))))
  (put 'div '(complex complex)
       (lambda (z1 z2) (tag (div-complex z1 z2))))
  (put 'make-from-real-imag 'complex
       (lambda (x y) (tag (make-from-real-imag x y))))
  (put 'make-from-mag-ang 'complex
       (lambda (r a) (tag (make-from-mag-ang r a))))
  'done)

(define (make-complex-from-real-imag x y)
  ((get 'make-from-real-imag 'complex) x y))
(define (make-complex-from-mag-ang r a)
  ((get 'make-from-mag-ang 'complex) r a))

(install-complex-package)
(make-complex-from-real-imag 1 2)
; 動かないし
(make-complex-from-mag-ang 3 4)
((get 'make-from-real-imag 'complex) 1 2)
; error仕込んでみた
; gosh> *** ERROR: op not found make-from-real-imag rectangular
; ふむこれないよね
; 足す。

;; Benの
(define (install-rectangular-package)
   ;; 内部手続き
  (define (real-part z) (car z))
  (define (imag-part z) (cdr z))
  (define (make-from-real-imag x y) (cons x y))
  (define (magnitude z)
    (sqrt (+ (square (real-part z))
             (square (imag-part z)))))
  (define (angle z)
    (atan (imag-part z) (real-part z)))
  (define (make-from-mag-ang r a) 
    (cons (* r (cos a)) (* r (sin a))))

   ;; システムの他の部分とのインターフェース
  (define (tag x) (attach-tag 'rectangular x)) 
  (put 'real-part 'rectangular real-part) ; この辺、テキストだと '(rectangular)ってなってるけど本当？
  (put 'imag-part 'rectangular imag-part)
  (put 'magnitude 'rectangular magnitude)
  (put 'angle 'rectangular angle)
  (put 'make-from-real-imag 'rectangular 
       (lambda (x y) (tag (make-from-real-imag x y)))) ; なぜ急にlambda?
  (put 'make-from-mag-ang 'rectangular 
       (lambda (r a) (tag (make-from-mag-ang r a)))) ; なぜ急に
  'done)

;; Alyssaの
(define (install-polar-package)
   ;; 内部手続き
  (define (magnitude z) (car z))
  (define (angle z) (cdr z))
  (define (make-from-mag-ang r a) (cons r a))
  (define (real-part z)
    (* (magnitude z) (cos (angle z))))
  (define (imag-part z)
    (* (magnitude z) (sin (angle z))))
  (define (make-from-real-imag x y) 
    (cons (sqrt (+ (square x) (square y)))
          (atan y x)))

   ;; システムの他の部分とのインターフェース
  (define (tag x) (attach-tag '(polar) x))
  (put 'real-part '(polar) real-part)
  (put 'imag-part '(polar) imag-part)
  (put 'magnitude '(polar) magnitude)
  (put 'angle '(polar) angle)
  (put 'make-from-real-imag '(polar)
       (lambda (x y) (tag (make-from-real-imag x y))))
  (put 'make-from-mag-ang '(polar) 
       (lambda (r a) (tag (make-from-mag-ang r a))))
  'done)
(clear-putlist)
(install-complex-package)
(install-rectangular-package)
(install-polar-package)
put-lists

; ここまでやると出来た
(make-complex-from-mag-ang 3 4)
;gosh> (complex polar 3 . 4)
((get 'make-from-real-imag 'complex) 1 2)
;gosh> (complex rectangular 1 . 2)
(define z1 (make-complex-from-mag-ang 3 4))
(mul z1 z1)
;;; 2.77
;; 
(define (install-complex-package)
  ;; 直交座標と極座標パッケージから取り入れた手続き
  (define (make-from-real-imag x y)
    ((get 'make-from-real-imag 'rectangular) x y))
  (define (make-from-mag-ang r a)
    ((get 'make-from-mag-ang 'polar) r a))

  ;; 内部手続き
  (define (add-complex z1 z2)
    (make-from-real-imag (+ (real-part z1) (real-part z2))
                         (+ (imag-part z1) (imag-part z2))))
  (define (sub-complex z1 z2)
    (make-from-real-imag (- (real-part z1) (real-part z2))
                         (- (imag-part z1) (imag-part z2))))
  (define (mul-complex z1 z2)
    (make-from-mag-ang (* (magnitude z1) (magnitude z2))
                       (+ (angle z1) (angle z2))))
  (define (div-complex z1 z2)
    (make-from-mag-ang (/ (magnitude z1) (magnitude z2))
                       (- (angle z1) (angle z2))))
  
  ;; システムの他の部分へのインターフェース
  (define (tag z) (attach-tag 'complex z))
  (put 'add '(complex complex)
       (lambda (z1 z2) (tag (add-complex z1 z2))))
  (put 'sub '(complex complex)
       (lambda (z1 z2) (tag (sub-complex z1 z2))))
  (put 'mul '(complex complex)
       (lambda (z1 z2) (tag (mul-complex z1 z2))))
  (put 'div '(complex complex)
       (lambda (z1 z2) (tag (div-complex z1 z2))))
  (put 'make-from-real-imag 'complex
       (lambda (x y) (tag (make-from-real-imag x y))))
  (put 'make-from-mag-ang 'complex
       (lambda (r a) (tag (make-from-mag-ang r a))))
  ;; ここを追加
  (put 'real-part '(complex) real-part)
  (put 'imag-part '(complex) imag-part)
  (put 'magnitude '(complex) magnitude)
  (put 'angle '(complex) angle)
  'done)

(install-complex-package)

(define c1 (make-complex-from-mag-ang 3 4))
(define (magnitude x) (apply-generic 'magnitude x))

(magnitude c1)
(clear-putlist)
(install-complex-package)
(install-rectangular-package)
(install-polar-package)
;; うーむどうやら2回めのapply-genericで止まっているみたい
; Alyssaのやつ、magnitudeとかのところをタイプタグを '(polar) にしたら動いた
;; gosh> CALL magnitude (complex polar 3 . 4)
;;   CALL apply-generic magnitude (complex polar 3 . 4)
;;     CALL apply-generic magnitude (polar 3 . 4)
;; #<closure (install-polar-package magnitude)>
;;     RETN apply-generic 3
;;   RETN apply-generic 3
;; RETN magnitude 3
;; 3
;;つまり 1回目のapply-genericで　(complex polar 3. 4)を引数にして呼ぶと、そのなかでもう1度apply-genericが今度は(polar 3. 4)って呼ばれるからうまいこと行っている。


;;; 2.79, 2.80
;; めんどいけど全部持ってきて、まとめてやる
; 整数
(define (install-scheme-number-package)
  (define (tag x)
    (attach-tag 'scheme-number x))
  (put 'add '(scheme-number scheme-number)
       (lambda (x y) (tag (+ x y))))
  (put 'sub '(scheme-number scheme-number)
       (lambda (x y) (tag (- x y))))
  (put 'mul '(scheme-number scheme-number)
       (lambda (x y) (tag (* x y))))
  (put 'div '(scheme-number scheme-number)
       (lambda (x y) (tag (/ x y))))
  (put 'make 'scheme-number
       (lambda (x) (tag x)))

  ; for 2.79
  (put 'equ? '(scheme-number scheme-number)
       (lambda (x y) (equal? x y)))
  ; for 2.80
  (put '=zero? '(scheme-number)
       (lambda (x) (= 0 x)))
  'done)

; 有理数
(define (install-rational-package)
  ;; 内部手続き
  (define (numer x) (car x))
  (define (denom x) (cdr x))
  (define (make-rat n d)
    (let ((g (gcd n d)))
      (cons (/ n g) (/ d g))))
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

  ;; システムの他の部分へのインターフェース
  (define (tag x) (attach-tag 'rational x))
  (put 'add '(rational rational)
       (lambda (x y) (tag (add-rat x y))))
  (put 'sub '(rational rational)
       (lambda (x y) (tag (sub-rat x y)))) ; この辺省略できそう
  (put 'mul '(rational rational)
       (lambda (x y) (tag (mul-rat x y))))
  (put 'div '(rational rational)
       (lambda (x y) (tag (div-rat x y))))

  (put 'make 'rational
       (lambda (n d) (tag (make-rat n d))))

  ; for 2.79
  (put 'equ? '(rational rational)
       (lambda (x y) 
         (and (= (numer x) (numer y))
              (= (denom x) (denom y)))))
  ; for 2.80
  (put '=zero? '(rational)
       (lambda (x) (= 0 (numer x))))
  'done)

;; Benの
(define (install-rectangular-package)
   ;; 内部手続き
  (define (real-part z) (car z))
  (define (imag-part z) (cdr z))
  (define (make-from-real-imag x y) (cons x y))
  (define (magnitude z)
    (sqrt (+ (square (real-part z))
             (square (imag-part z)))))
  (define (angle z)
    (atan (imag-part z) (real-part z)))
  (define (make-from-mag-ang r a) 
    (cons (* r (cos a)) (* r (sin a))))

   ;; システムの他の部分とのインターフェース
  (define (tag x) (attach-tag 'rectangular x)) 
  (put 'real-part 'rectangular real-part) ; この辺、テキストだと '(rectangular)ってなってるけど本当？
  (put 'imag-part 'rectangular imag-part)
  (put 'magnitude 'rectangular magnitude)
  (put 'angle 'rectangular angle)
  (put 'make-from-real-imag 'rectangular 
       (lambda (x y) (tag (make-from-real-imag x y)))) ; なぜ急にlambda?
  (put 'make-from-mag-ang 'rectangular 
       (lambda (r a) (tag (make-from-mag-ang r a)))) ; なぜ急に

  (put 'equ? '(rectangular rectangular)
       (lambda (x y)
         (and (= (real-part x) (real-part y)
                 (imag-part x) (imag-part y)))))

  (put '=zero? 'rectangular
       (lambda (x)
         (and (= 0 (real-part x))
              (= 0 (imag-part y)))))
  'done)

;; Alyssaの
(define (install-polar-package)
   ;; 内部手続き
  (define (magnitude z) (car z))
  (define (angle z) (cdr z))
  (define (make-from-mag-ang r a) (cons r a))
  (define (real-part z)
    (* (magnitude z) (cos (angle z))))
  (define (imag-part z)
    (* (magnitude z) (sin (angle z))))
  (define (make-from-real-imag x y) 
    (cons (sqrt (+ (square x) (square y)))
          (atan y x)))

   ;; システムの他の部分とのインターフェース
  (define (tag x) (attach-tag 'polar x))
  (put 'real-part '(polar) real-part)
  (put 'imag-part '(polar) imag-part)
  (put 'magnitude '(polar) magnitude)
  (put 'angle '(polar) angle)
  (put 'make-from-real-imag '(polar)
       (lambda (x y) (tag (make-from-real-imag x y))))
  (put 'make-from-mag-ang '(polar) 
       (lambda (r a) (tag (make-from-mag-ang r a))))
  (put 'equ? '(polar polar)
       (lambda (x y)
         (and (= (angle x) (angle y)
                 (magnitude x) (magnitude y)))))
  (put 'zero '(polar)
       (lambda (x)
         (= 0 (magnitude x))))
  'done)

(define (install-complex-package)
  ;; 直交座標と極座標パッケージから取り入れた手続き
  (define (make-from-real-imag x y)
    ((get 'make-from-real-imag 'rectangular) x y))
  (define (make-from-mag-ang r a)
    ((get 'make-from-mag-ang 'polar) r a))

  ;; 内部手続き
  (define (add-complex z1 z2)
    (make-from-real-imag (+ (real-part z1) (real-part z2))
                         (+ (imag-part z1) (imag-part z2))))
  (define (sub-complex z1 z2)
    (make-from-real-imag (- (real-part z1) (real-part z2))
                         (- (imag-part z1) (imag-part z2))))
  (define (mul-complex z1 z2)
    (make-from-mag-ang (* (magnitude z1) (magnitude z2))
                       (+ (angle z1) (angle z2))))
  (define (div-complex z1 z2)
    (make-from-mag-ang (/ (magnitude z1) (magnitude z2))
                       (- (angle z1) (angle z2))))
  
  ;; システムの他の部分へのインターフェース
  (define (tag z) (attach-tag 'complex z))
  (put 'add '(complex complex)
       (lambda (z1 z2) (tag (add-complex z1 z2))))
  (put 'sub '(complex complex)
       (lambda (z1 z2) (tag (sub-complex z1 z2))))
  (put 'mul '(complex complex)
       (lambda (z1 z2) (tag (mul-complex z1 z2))))
  (put 'div '(complex complex)
       (lambda (z1 z2) (tag (div-complex z1 z2))))
  (put 'make-from-real-imag 'complex
       (lambda (x y) (tag (make-from-real-imag x y))))
  (put 'make-from-mag-ang 'complex
       (lambda (r a) (tag (make-from-mag-ang r a))))
  ;; ここを追加
  (put 'real-part '(complex) real-part)
  (put 'imag-part '(complex) imag-part)
  (put 'magnitude '(complex) magnitude)
  (put 'angle '(complex) angle)
  ; 2.79
  (put 'equ? '(complex complex) equ?)

  ; 2.80
  (put '=zero? '(complex) =zero?)
  'done)
(define (make-scheme-number n)
  ((get 'make 'scheme-number) n))
(define (make-rational n d)
  ((get 'make 'rational) n d))
(define (make-complex-from-real-imag x y)
  ((get 'make-from-real-imag 'complex) x y))
(define (make-complex-from-mag-ang r a)
  ((get 'make-from-mag-ang 'complex) r a))

(define (add x y) (apply-generic 'add x y))
(define (sub x y) (apply-generic 'sub x y))
(define (mul x y) (apply-generic 'mul x y))
(define (div x y) (apply-generic 'div x y))
(define (equ? x y) (apply-generic 'equ? x y))
(define (=zero? x) (apply-generic '=zero? x))

(clear-putlist)
(install-scheme-number-package)
(define a (make-scheme-number 10))
(define b (make-scheme-number 20))
(define c (make-scheme-number 10))
(define d (make-scheme-number 0))
(equ? a b)
; #f
(equ? a c)
; #t
(=zero? a)
; #f
(=zero? d)
; #t
; よさげ
(install-rational-package)
(define e (make-rational 1 3))
(define f (make-rational 1 3))
(define g (make-rational 1 4))
(define h (make-rational 0 3))
(equ? e f)
; #t
(equ? e g)
; #f
(=zero? e)
; #f
(=zero? h)
(clear-putlist)
(install-complex-package)
(install-rectangular-package)
(install-polar-package)
(define j (make-complex-from-real-imag 1 2))
(define k (make-complex-from-real-imag 1 2))
(equ? j k)
; たぶんこれでよさげなのだけどうまくいかない。
