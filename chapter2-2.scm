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
