;; 3.13試してみる
;; set-cdr! とかがracketでは動かないので、ここからgaucheになった。
(define (last-pair x)
  (if (null? (cdr x))
      x
      (last-pair (cdr x))))

(define (make-cycle x)
  (set-cdr! (last-pair x) x)
  x)

(define z (make-cycle (list 'a 'b 'c)))
z

;; gosh> last-pair
;; gosh> make-cycle
;; gosh> z
;; gosh> #0=(a b c . #0#)
;; こんなかんじになった。#0が循環してるっぽいかんじかな。

;; 3.14
;; loopの中を紙で動かしてみた。
;; 一般にmysteryが何をするか説明せよ
;; 'a 'b 'c 'd => 'd 'c 'b 'aってなる。
;; 動かしてみる
(define (mystery x)
  (define (loop x y)
    (if (null? x)
        y
        (let ((temp (cdr x)))
          (set-cdr! x y)
          (loop temp x))))
  (loop x '()))
(define v (list 'a 'b 'c 'd))
v
(define w (mystery v))
w
v
;; gosh> mystery
;; gosh> v
;; gosh> (a b c d)
;; gosh> w
;; gosh> (d c b a)
;; gosh> (a)
