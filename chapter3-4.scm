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


;; 共有と同一
(define (set-to-wow! x)
  (set-car! (car x) 'wow)
  x)
(define x (list 'a 'b))
(define z1 (cons x x))
z1
;; gosh> ((a b) a b)
;; こうだから図3.16はなんか微妙に変な気がする
(define z2 (cons (list 'a 'b) (list 'a 'b)))
z2

(set-to-wow! z1)
;; gosh> ((wow b) wow b)

(set-to-wow! z2)
;; gosh> ((wow b) a b)

;; 3.16
;; benのやつ
(define (count-pairs x)
  (if (not (pair? x))
      0
      (+ (count-pairs (car x))
         (count-pairs (cdr x))
         1)))
(define l1 (list 'a 'b 'c))
(count-pairs l1)
;; gosh> 3
;; よさげにみえるけど
;; ↑で作った無限ループのやつとかどうなるのだろう
z
;; 無限ループ注意　(count-pairs z)
;; 無限ループって答えが帰ってこなくなった

(define x (list 'a 'b))
(define z1 (cons x x))
(count-pairs z1)
;; これ5が返ってくる

(define z2 (cons (list 'a 'b) (list 'a 'b)))
(count-pairs z1)
;; これも5が返ってくる
;; とりあえず正しくないことは示した？

;; z1の方は3つだけど5が返ってくる。
;; こういう感じのを作ればいいのだろう
;; ってことで図をかいた。
