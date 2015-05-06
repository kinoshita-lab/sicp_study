;;; 3.3.3 表の表現

(define (lookup key table)
  (let ((record (assoc key (cdr table))))
    (if record
        (cdr record)
        #f)))

(define (assoc key records)
  (cond ((null? records) #f)
        ((equal? key (caar records)) (car records))
        (else (assoc key (cdr records)))))

(define (insert! key value table)
  (let ((record (assoc key (cdr table))))
    (if record
        (set-cdr! record value);; 見つかったら値を更新
        (set-cdr! table
                  (cons (cons key value) (cdr table))))) ;;ど頭に入れる
  'ok)

(define (make-table)
  (list '*table*))

;; 試
(define hogeTable (make-table))
hogeTable
;; (*table*)
(insert! 'a 1 hogeTable)
;; ok
hogeTable
;;  (*table* (a . 1))
(insert! 'b 2 hogeTable)
;; ok
hogeTable
;; (*table* (b . 2) (a . 1))
(insert! 'c 3 hogeTable)
;; ok
hogeTable
;; (*table* (c . 3) (b . 2) (a . 1))

;; 二次元の表
(define (lookup key-1 key-2 table)
  (let ((subtable (assoc key-1 (cdr table))))
    (if subtable
        (let ((record (assoc key-2 (cdr subtable))))
          (if record
              (cdr record)
              #f))
        #f)))

(define (insert! key-1 key-2 value table)
  (let ((subtable (assoc key-1 (cdr table))))
    (if subtable
        (let ((record (assoc key-2 (cdr subtable))))
          (if record
              (set-cdr! record value) ;; サブテーブルに値があった場合は更新
              (set-cdr! subtable ;; なかったら新しいのを作って追加
                        (cons (cons key-2 value)
                              (cdr subtable)))))
        (set-cdr! table　　　　　　　　;; サブテーブルがなかった場合は
                  (cons (list key-1  ;; サブテーブルをくっつけつつ
                              (cons key-2 value)) ;; key valueも追加。
                        (cdr table)))))
  'ok)

(define (make-table)
  (let ((local-table (list '*table*)))
    (define (lookup key-1 key-2)
      (let ((subtable (assoc key-1 (cdr local-table))))
        (if subtable
            (let ((record (assoc key-2 (cdr subtable))))
              (if record
                  (cdr record)
                  #f))
            #f)))
    (define (insert! key-1 key-2 value)
      (let ((subtable (assoc key-1 (cdr local-table))))
        (if subtable
            (let ((record (assoc key-2 (cdr subtable))))
              (if record
                  (set-cdr! record value)
                  (set-cdr! subtable
                            (cons (cons key-2 value)
                                  (cdr subtable)))))
            (set-cdr! local-table
                      (cons (list key-1
                                  (cons key-2 value))
                            (cdr local-table)))))
      'ok)
    
    (define (dispatch m)
      (cond ((eq? m 'lookup-proc) lookup)
            ((eq? m 'insert-proc) insert!)
            (else (error "Unknown operation -- table" m))))
    dispatch))

;; 3.24
;; めんどいので1次元で。
(define (make-table keyfunction)
  (let ((table (list '*table*)))
    ;; 内部手続
    (define (lookup key)
      (let ((record (assoc key (cdr table))))
        (if record
            (cdr record)
            #f)))
  
    (define (assoc key records)
      (cond ((null? records) #f)
            ((keyfunction key (caar records)) (car records))
            (else (assoc key (cdr records)))))
    
    (define (insert! key value)
      (let ((record (assoc key (cdr table))))
        (if record
            (set-cdr! record value);; 見つかったら値を更新
            (set-cdr! table
                      (cons (cons key value) (cdr table))))) ;;ど頭に入れる
      'ok)
    
    (define (dispatch m)
      (cond ((eq? 'lookup m) lookup)
            ((eq? 'insert m) insert!)
            ((eq? 'show m) table) ;; つくってみた
            (else
             (error "unknown message.."))))
    
    dispatch))

;; +-10%ならOKという関数を作ってみた
(define (ten-percent-good v1 v2)
  (let ((div (/ v1 v2)))
    (and (> div 0.9) (< div 1.1))))

(ten-percent-good 1.0 1.01)
;; #t

(ten-percent-good 1.0 2.0)
;; #f

;; 試
(define range-table (make-table ten-percent-good))
((range-table 'insert) 1.1 'a)
(range-table 'show)
;; (*table* (1.1 . a))
((range-table 'insert) 2.2 'b)
(range-table 'show)
;; (*table* (2.2 . b) (1.1 . a))
((range-table 'lookup) 1.05)
;; a
((range-table 'lookup) 2.1)
;; b
((range-table 'lookup) 3.0)
;; #f
;; よさげ

;; 3.25
;; だめだったので
;; https://github.com/ten0s/sicp/blob/master/ch03/3.25.scm
;; を参考にした
(define (make-table)
  (let ((table (cons '*table* '())))

    (define (assoc key records)
      (cond ((null? records) #f)
            ((equal? key (caar records)) (car records))
            (else (assoc key (cdr records)))))
    
    (define (lookup keys)
      (cond ((null? keys) #f)
            ((null? table) #f)
            ((not (list? table)) #f)
            (else
             (let ((subtable (assoc (car keys) (cdr table))))
               (if subtable
                   (if (= (length keys) 1)
                       (cdr subtable)
                       (lookup (cdr keys) (subtable)))
                   #f)))))
    
    (define (insert! keys value table)
      (let ((key (car keys)))
        (let ((subtable (assoc key (cdr table))))
          (if subtable
              (if (= (length keys) 1)
                  (set-cdr! subtable value)
                  (insert! (cdr keys) value subtable))
              (let ((new-subtable (cons (cons key '())
                                        (cdr table))))
                (set-cdr! table new-subtable)
                (insert keys value table)))))
      'ok)
    
    (define (dispatch m)
      (cond ((eq? m 'lookup-proc) lookup)
            ((eq? m 'insert-proc) insert!)
            (else (error "Unknown operation -- table" m))))
    dispatch))
