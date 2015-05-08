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

;; 3.26
;; 2.66の答えはこんな感じだった(これ合ってるのかしらない)
(define (lookup given-key set-of-records)
  (let ((top-record (car set-of-records)))   
    (cond ((null? set-of-records) false)
          ((= x (key top-record)
              (car set-of-records)))
          ((< x (key top-record))
              (lookup x (left-branch set-of-records)))
          ((> x (key top-record))
              (lookup x (right-branch set-of-records))))))

;; この辺も必要かも
(define (entry tree) (car tree))
(define (left-branch tree) (cadr tree))
(define (right-branch tree) (caddr tree))
(define (make-tree entry left right)
  (list entry left right))

;; めんどいので１次元だしバラバラ方式でやる
;; 微妙に変えないとダメだ ((key . value) left right) こんな感じにする
(define (make-tree-entry key value left right)
  (list (cons key value) left right))
(make-tree-entry 'a 1 '() '())
(define (set-left! tree left-entry)
  (set-car! (cdr tree) left-entry)
  tree)
(define (set-right! tree right-entry)
  (set-cdr! (cdr tree) right-entry)
  tree)

(define a1 (make-tree-entry 'a 1 '() '()))
(define b2 (make-tree-entry 'b 2 '() '()))
(define c3 (make-tree-entry 'c 3 '() '()))
(define abtree (set-left! a1 b2))
abtree
;; ((a . 1) ((b . 2) () ()) ())
(define abctree (set-right! abtree c3))
abctree
;; ((a . 1) ((b . 2) () ()) (c . 3) () ())
;; ここまでよさげ。
;; lookup書き換える
;; まえにkey取り出しが必要ぽい
(define (get-key tree-entry)
  (caar tree-entry))
(get-key a1)
;; a よさげ
;; さらにそのなかの値を拾うやつも必要
(define (get-value tree-entry)
  (cdar tree-entry))
(get-value a1)
;; 1 よさげ


;; left-branch, right-branchも必要
(define (left-branch tree)
  (print (car tree))
  (if (null? (cdr tree)) '()
      (cadr tree)))
(left-branch abctree)
;; ((b . 2) () ())
(define (right-branch tree)
  (print tree)
  (if (null? (cdr tree)) '()
      (caddr tree)))
(right-branch abctree)
;; ((c . 3) () ())


(define (lookup key tree)
  (let ((top-record (car tree)))
    (cond ((null? tree) #f)
          ((= key (get-key top-record)
              (get-value top-record))) ;; 見つかったtree-entryの値を返す
          ((< key (get-key top-record))
              (lookup key (left-branch tree)))
          ((> key (get-key top-record))
              (lookup key (right-branch tree))))))

(define (assoc key tree)
  (if (not (pair? tree)) #f
      (let ((actual-tree (cdr tree)))
        (if (null? actual-tree) #f
            (let ((top-record (car actual-tree)))
              (cond ((= key (get-key top-record))
                     top-record)
                    ((< key (get-key top-record))
                     (assoc key (left-branch actual-tree)))
                    ((> key (get-key top-record))
                     (assoc key (right-branch actual-tree)))))))))


(define (set-value! entry value)
  (set-cdr! (car entry) value)
  entry)

;; これも拾ってきた
(define (keyValueItem entry)
  (car entry))

(define (adjoin-set entry tree) 
  (print tree)
  (cond ((null? tree) entry) 
        ;;=のときは先にやっている
        ((= (get-key entry) (get-key (car tree))) tree) 
        ((< (get-key entry) (get-key (car tree)))
         (make-tree-entry
          (get-key entry) (get-value entry)
          (adjoin-set entry (left-branch (car tree))) 
          (right-branch (car tree)))) 
        ((> (get-key entry) (get-key (car tree)))
         (make-tree-entry
          (get-key entry) (get-value entry)
          (left-branch (car tree))
          (adjoin-set entry (right-branch (car tree)))))))

(define (insert! key value table)
  (let ((record (assoc key table)))
    (if record
        (set-value! record value)
        (set-cdr! table (cons (adjoin-set (make-tree-entry key value '() '()) (cdr table)) '()))))
  'ok)

(define (make-table)
  (list '*table*))

;; 試　数字をキーにする
(define hogeTable (make-table))
(insert! 1 'aaa hogeTable)
hogeTable
(insert! 2 'bbb hogeTable)

;; ・・うまくいかないな。
;; http://www.serendip.ws/archives/1337
;; こんな感じみたい　大枠まちがってなさそうなんだけどなあ

;; 3.27
;; 最初のtableでやる
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

(define (memorize f)
  (let ((table (make-table)))
    (lambda (x)
      (let ((previously-computed-result (lookup x table)))
        (or previously-computed-result
            (let ((result (f x)))
              (insert! x result table)
              result))))))
      
(define memo-fib
  (memorize (lambda (n)
              (cond ((= n 0) 0)
                    ((= n 1) 1)
                    (else (+ (memo-fib (- n 1))
                             (memo-fib (- n 2))))))))

(memo-fib 3)
;; 1回目
;; CALL memo-fib 3
;;   CALL memo-fib 2
;;     CALL memo-fib 1
;;     RETN memo-fib 1
;;     CALL memo-fib 0
;;     RETN memo-fib 0
;;   RETN memo-fib 1
;;   CALL memo-fib 1
;;   RETN memo-fib 1
;; RETN memo-fib 2
;; 2
(memo-fib 3)
;; CALL memo-fib 3
;; RETN memo-fib 2
;; 2
;; ２回めは結果が入っているのでそれが帰ってきた
;; (memo-fib 3)の計算を解析する環境の図を描け.
;; かいた。

;; memo-fibがn番目のFibonacci数をnに比例したステップ数で計算出来る理由を説明せよ.
;; どの計算でも前の値は計算済みなので、その先で毎回再帰が起こらないから。

;; この方式はmemo-fibを単に(memoize fib)と定義してもやはり働くだろうか. 
;; うごかなそう。 再帰のたびにfibの頭で毎回memorizeを呼びたい


