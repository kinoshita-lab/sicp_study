;;; 2.78専用会場
;;; やりわすれてた。ここだけracket
(require racket/trace)
(require trace)
(define nil '())
(number? 10)
;; => #t
(symbol? 'unko)
;; => #t
;; ってなるので number時はattach-tagで何もつけない
(define (attach-tag type-tag contents)
  (if (equal? nil type-tag)
      contents
      (cons type-tag contents)))

(attach-tag nil 10)
;; => 10

;; tagが欲しい時だけむりくり返す
(define (type-tag datum)
  (if (number? datum)
      'scheme-number
      (if (pair? datum)
          (car datum)
          (error "Bad tagged datum -- TYPE-TAG" datum)))); なぜ急にエラーチェック？  
(type-tag 10)
;; => scheme-number

;; タグを付けないscheme-number
(define (install-scheme-number-package)
  (define (tag x)
    (attach-tag '() x))
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

;;;;;;
;;;;; 変えなくて良さそうなもの
;;;;;;
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
      (if proc
          (apply proc (map contents args))
          (error
           "No method for these types -- APPLY-GENERIC"
           (list op type-tags))))))

(define (make-scheme-number n)
  ((get 'make 'scheme-number) n))

; 使ってみる
(install-scheme-number-package)
;; => done

(define a (make-scheme-number 10))
(define b (make-scheme-number 5))
a
;; => 10
((get 'add '(scheme-number scheme-number)) a b)
;; => 15
;; できたっぽい
