;;; CODE FROM OTHER CHAPTERS OF STRUCTURE AND INTERPRETATION OF
;;;  COMPUTER PROGRAMS NEEDED BY CHAPTER 2

;;;from chapter 1
(define (square x) (* x x))

;;;from section 1.2.5, for Section 2.1.1
(define (gcd a b)
  (if (= b 0)
      a
      (gcd b (remainder a b))))

;;;from section 1.2.2, for Section 2.2.3
(define (fib n)
  (cond ((= n 0) 0)
        ((= n 1) 1)
        (else (+ (fib (- n 1))
                 (fib (- n 2))))))

;;; ***not in book, but needed for code before quote is introduced*** 
(define nil '())
;;;; 動かないのでコメントアウト
;;;-----------
;;;from section 3.3.3 for section 2.4.3
;;; to support operation/type table for data-directed dispatch

;; (define (assoc key records)
;;   (cond ((null? records) false)
;;         ((equal? key (caar records)) (car records))
;;         (else (assoc key (cdr records)))))

;; (define (make-table)
;;   (let ((local-table (list '*table*)))
;;     (define (lookup key-1 key-2)
;;       (let ((subtable (assoc key-1 (cdr local-table))))
;;         (if subtable
;;             (let ((record (assoc key-2 (cdr subtable))))
;;               (if record
;;                   (cdr record)
;;                   false))
;;             false)))
;;     (define (insert! key-1 key-2 value)
;;       (let ((subtable (assoc key-1 (cdr local-table))))
;;         (if subtable
;;             (let ((record (assoc key-2 (cdr subtable))))
;;               (if record
;;                   (set-cdr! record value)
;;                   (set-cdr! subtable
;;                             (cons (cons key-2 value)
;;                                   (cdr subtable)))))
;;             (set-cdr! local-table
;;                       (cons (list key-1
;;                                   (cons key-2 value))
;;                             (cdr local-table)))))
;;       'ok)    
;;     (define (dispatch m)
;;       (cond ((eq? m 'lookup-proc) lookup)
;;             ((eq? m 'insert-proc!) insert!)
;;             (else (error "Unknown operation -- TABLE" m))))
;;     dispatch))

;; (define operation-table (make-table))
;; (define get (operation-table 'lookup-proc))
;; (define put (operation-table 'insert-proc!))

;;;-----------
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
