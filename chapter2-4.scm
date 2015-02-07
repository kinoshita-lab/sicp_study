;; 2.3.3 例: 集合の表現
(use slib)
(require 'trace)
; true/falseない
(define false #f)
(define true #t)

(define (element-of-set? x set)
  (cond ((null? set) false)
        ((equal? x (car set)) true)
        (else (element-of-set? x (cdr set)))))

(define (adjoin-set x set)
  (if (element-of-set? x set) 
      set
      (cons x set)))

(define (intersection-set set1 set2)
  (cond ((or (null? set1) (null? set2)) '())
        ((element-of-set? (car set1) set2)
         (cons (car set1)
               (intersection-set (cdr set1) set2)))
        (else (intersection-set (cdr set1) set2))))

; 2.59
(define (union-set set1 set2)
  (cond ((null? set1) set2)
        ((element-of-set? (car set1) set2)
         (union-set (cdr set1) set2))
        (else (union-set
               (cdr set1)
               (cons (car set1) set2)))))
      
(define list1 '(a b c d))
(define list2 '(c d e f))
(union-set list1 list2)
(intersection-set list1 list2)
; gosh> (b a c d e f)

; 2.60
; element-of-set? これは変えなくていいと思う
(define (element-of-set? x set)
  ((cond ((null? set) false)
         ((equal? x (car set)) true)
         (else (element-of-set? x (cdr set))))))

; adjoin-set 何も考えずにつっこめばいい
(define (adjoin-set x set)
  (cons x set))

; intersection-set 変えなくて良さそう
(define (intersection-set set1 set2)
  (cond ((or (null? set1) (null? set2)) '())
        ((element-of-set? (car set1) set2)
         (cons (car set1)
               (intersection-set (cdr set1) set2)))
        (else (intersection-set (cdr set1) set2))))

; union-set 合体すればいいんじゃないのか         
(define (union-set set1 set2)
  (append set1 set2))

(define list1 '(2 3 2 1 3 2 2))
(define list2 '(3 2 1 2 5 5 5))

(intersection-set list1 list2)
; gosh> (2 3 2 1 3 2 2)
(union-set list1 list2)
; gosh> (2 3 2 1 3 2 2 3 2 1 2 5 5 5)
; 重複なし表現の対応する手続きと比べて効率はどうなるか. 重複なし表現よりこの表現の方が使いたくなる応用はあるだろうか. 

; 効率は要素数によるので一概にいえないのでは？
; 何が何個あるか？みたいなことを調べたい場合は重複を許す集合のほうがいい、というかそうしないとできないね。


; 順序づけられたリストとしての集合
(define (element-of-set? x set)
  (cond ((null? set) false)
        ((= x (car set)) true)
        ((< x (car set)) false)
        (else (element-of-set? x (cdr set)))))

(define (intersection-set set1 set2)
  (if (or (null? set1) (null? set2))
      '()
      (let ((x1 (car set1)) (x2 (car set2)))
        (cond ((= x1 x2)
               (cons x1
                     (intersection-set (cdr set1)
                                       (cdr set2)))) ;採用された
              ((< x1 x2)
               (intersection-set (cdr set1) set2)) ; set1にはこれ以上小さい数はないので次の数で比較を開始
              ((< x2 x1)
               (intersection-set set1 (cdr set2))))))) ; set2にはこれ以上小さい数はないので次の数で比較を開始


; 2.61
; element-of-set?は順序付きのこれ使う
(define (element-of-set? x set)
  (cond ((null? set) false)
        ((= x (car set)) true)
        ((< x (car set)) false)
        (else (element-of-set? x (cdr set)))))

(define (adjoin-set x set)
  (if (element-of-set? x set) 
      set
      (if (< x (car set)) (cons x set)
          (cons (car set) (adjoin-set x (cdr set))))))

(define list1 '(2 4 6 8))
(adjoin-set '3 list1)
; gosh> (2 3 4 6 8)


; 2.62
(define (union-set set1 set2)
  (cond ((null? set1) set2)
        ((element-of-set? (car set1) set2)
         (union-set (cdr set1) set2))
        (else (union-set
               (cdr set1)
               (cons (car set1) set2)))))

(define (union-set set1 set2)
 (cond ((null? set1) set2)
       ((null? set2) set1)
       (else
         (if (null? set1) 
             set2
             (let ((x1 (car set1)) 
                   (x2 (car set2)))
               (cond ((= x1 x2)
                      (union-set (cdr set1) set2))
                     ((< x1 x2)
                      (cons x1 (union-set (cdr set1)
                                          set2)))
                     ((> x1 x2)
                      (cons x2 (union-set set1 (cdr set2))))))))))
(define list1 '(2 4 6 8))
(define list2 '(1 3 5 7))
(union-set list1 list2) 
(trace union-set)




