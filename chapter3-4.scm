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


;問題 3.17
;問題3.16のcount-pairsで, 任意の構造の異る対の個数を返す正しい解を考えよ. (ヒント: どの対が既に数えられたかを覚えておくのに使う補助のデータ構造を補正しながら構造を渡り歩け.) 
;; 何をすればいいのかはザックリわかった。
;; が、ここでmemqを使うという発想はなかった・・
(define (corrected-count-pairs x)
  (define counting-list '()) ; letでもいいと思うけど
  (define (counter x)
    (cond ((not (pair? x)) 0)
          ((memq x counting-list) 0) ;; 数えてたら数えない
          (else   (set! counting-list (cons counting-list x))
                  (+ (counter (car x))
                     (counter (cdr x))
                     1))))
  (trace counter)
  (counter x))
(define x (list 'a 'b))
(define z1 (cons x x))
z1
 
(corrected-count-pairs z1)
;; 1

(define z2 (cons (list 'a 'b) (list 'a 'b)))
(corrected-count-pairs z2)
;; 3
;; これであってるの？

;; 3.18
(define (circular? x)
  (define counting-list '())
  (define (circular-finder item)
    (cond ((null? item) #f)
          ((memq (car item) counting-list) #t)
          (else (set! counting-list (cons (car item)
                                          counting-list))
                (circular-finder (cdr item)))))
  (circular-finder x))
;; #t
(define normal-list '(a b c))
(circular? normal-list)
;; CALL circular-finder (a b c)
;;   CALL circular-finder (b c)
;;     CALL circular-finder (c)
;;       CALL circular-finder ()
;;       RETN circular-finder #f
;;     RETN circular-finder #f
;;   RETN circular-finder #f
;; RETN circular-finder #f
;; #f
(define (last-pair x)
  (if (null? (cdr x))
      x
      (last-pair (cdr x))))
(define (make-cycle x)
  (set-cdr! (last-pair x) x)
  x)
(define z (make-cycle (list 'a 'b 'c)))
z
(circular? z)
;;  CALL circular-finder (a b c a b c a b c a b c a b c a b c a b c a b ...)
;;   CALL circular-finder (b c a b c a b c a b c a b c a b c a b c a b c ...)
;;     CALL circular-finder (c a b c a b c a b c a b c a b c a b c a b c a ...)
;;       CALL circular-finder (a b c a b c a b c a b c a b c a b c a b c a b ...)
;;       RETN circular-finder #t
;;     RETN circular-finder #t
;;   RETN circular-finder #t
;; RETN circular-finder #t
;; #t
;; よさげ
