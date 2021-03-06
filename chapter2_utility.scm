;;  attach-tag,etc.
(define put-lists '())
(define (clear-putlist)
  (set! put-lists '()))

(define (put op type item)
  (if (get op type) put-lists
  (set! put-lists (cons (list op type item) put-lists)))) ; setっての使えばやりたいことできそう

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
          (if (and (eq? op (get-operator top))
                   (eq? type (get-type top))) (get-item top)
                   (get-iter (cdr list) op type)))))
  (get-iter put-lists op type))

(define (attach-tag type-tag contents)
  (cons type-tag contents))

(define (contents datum)
  (print datum)
  (if (pair? datum)
      (cdr datum)
      (error "Bad tagged datum -- CONTENTS" datum)))

(define (type-tag datum)
  (if (pair? datum)
      (car datum)
      (error "Bad tagged datum -- TYPE-TAG" datum))); なぜ急にエラーチェック？


;; ここでput/get coercionとかいうのが必要になっている気がする
(define coercion-list '())

(define (clear-coercion-list)
  (set! coercion-list '()))

(define (put-coercion type1 type2 item)
  (if (get-coercion type1 type2) coercion-list 
      (set! coercion-list
            (cons (list type1 type2 item)
                  coercion-list))))
;; get/put coercion
(define (put-coercion type1 type2 item)
  (if (get-coercion type1 type2) coercion-list 
      (set! coercion-list
            (cons (list type1 type2 item)
                  coercion-list))))

(define (get-coercion type1 type2) 
  (define (get-type1 listItem)
    (car listItem))
  (define (get-type2 listItem)
    (cadr listItem))
  (define (get-item listItem)
    (caddr listItem))
  (define (get-coercion-iter list type1 type2)
    (if (null? list) #f
        (let ((top (car list)))
          (if (and (equal? type1 (get-type1 top))
                   (equal? type2 (get-type2 top))) (get-item top)
                   (get-coercion-iter (cdr list) type1 type2)))))
  (get-coercion-iter coercion-list type1 type2))
