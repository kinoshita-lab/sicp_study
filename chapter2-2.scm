#lang planet neil/sicp
; Dr Racketでやることにする
; waveではないけど
(define wave einstein)
;(define wave2 (beside einstein (flip-vert einstein)))
;(paint wave2)

;(define wave4 (below wave2 wave2))
;(paint wave4)


(define (flipped-pairs painter)
  (let ((painter2 (beside painter (flip-vert painter))))
    (below painter2 painter2)))
(define wave4 (flipped-pairs wave))

(paint wave4)

(define (right-split painter n)
  (if (= n 0)
      painter
      (let ((smaller (right-split painter (- n 1))))
        (beside painter (below smaller smaller)))))

(paint (right-split wave 4))

;(define (up-split painter n)
;  (if (= n 0)
;      painter
;      (let ((smaller (up-split painter (- n 1))))
;        (below painter (beside smaller smaller)))))

(define (corner-split painter n)
  (if (= n 0)
      painter
      (let ((up (up-split painter (- n 1)))
            (right (right-split painter (- n 1))))
        (let ((top-left (beside up up))
              (bottom-right (below right right))
              (corner (corner-split painter (- n 1))))
          (beside (below painter top-left)
                  (below bottom-right corner))))))

;; 2.44
(define (up-split painter n)
  (if (= n 0)
      painter
      (let ((smaller (up-split painter (- n 1))))
        (below painter (beside smaller smaller)))))
(paint (corner-split wave 4))

;; 本文
(define (square-of-four tl tr bl br)
  (lambda (painter)
    (let ((top (beside (tl painter) (tr painter)))
          (bottom (beside (bl painter) (br painter))))
      (below bottom top))))

;(define (flipped-pairs painter)
;  (let ((combine4 (square-of-four identity flip-vert
;                                  identity flip-vert)))
;    (combine4 painter)))

;(define (square-limit painter n)
;  (let ((combine4 (square-of-four flip-horiz identity
;                                  rotate180 flip-vert)))
;    (combine4 painter)))

; 2.45
(define (right-split painter n)
  (if (= n 0)
      painter
      (let ((smaller (right-split painter (- n 1))))
        (beside painter (below smaller smaller)))))

(paint (right-split wave 4))

;(define (up-split painter n)
;  (if (= n 0)
;      painter
;      (let ((smaller (up-split painter (- n 1))))
;        (below painter (beside smaller smaller)))))

(define (corner-split painter n)
  (if (= n 0)
      painter
      (let ((up (up-split painter (- n 1)))
            (right (right-split painter (- n 1))))
        (let ((top-left (beside up up))
              (bottom-right (below right right))
              (corner (corner-split painter (- n 1))))
          (beside (below painter top-left)
                  (below bottom-right corner))))))

;; 2.45
;; それぞれこうでした
;; (define (right-split painter n)
;;   (if (= n 0)
;;       painter
;;       (let ((smaller (right-split painter (- n 1))))
;;         (beside painter (below smaller smaller)))))
;(define (up-split painter n)
;  (if (= n 0)
;      painter
;      (let ((smaller (up-split painter (- n 1))))
;        (below painter (beside smaller smaller)))))
; 引数の感じがぜんぜんちがうけどいいのかな
(define (split first-func second-func)
  (define (internal-spliter painter n)
    (if (= n 0)
        painter
        (let ((smaller (right-split painter (- n 1))))
          (first-func painter (second-func smaller smaller)))))
  (internal-spliter einstein 4))

(define right-split (split beside below))
(define up-split (split below beside))

(paint right-split)
(paint up-split)

;; ここからgosh
;; 2.46
(define (make-vect x y)
  (cons x y))
(make-vect 1 2)

(define (xcor-vect vect)
  (car vect))
(define (ycor-vect vect)
  (cdr vect))

(define (add-vect vect1 vect2)
  (make-vect (+ (xcor-vect vect1) (xcor-vect vect2))
             (+ (ycor-vect vect1) (ycor-vect vect2))))
(define (sub-vect vect1 vect2)
  (make-vect (- (xcor-vect vect1) (xcor-vect vect2))
             (- (ycor-vect vect1) (ycor-vect vect2))))
(define (scale-vect vect scale)
  (make-vect (* (xcor-vect vect) scale)
             (* (ycor-vect vect) scale)))

(define vect-1 (make-vect 1 2))
(define vect-2 (make-vect 3 4))

(add-vect vect-1 vect-2)
;gosh> (4 . 6)
(sub-vect vect-1 vect-2)
;gosh> (-2 . -2)
(scale-vect vect-1 3.0)
;gosh> (3.0 . 6.0)
