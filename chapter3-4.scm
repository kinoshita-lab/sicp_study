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

