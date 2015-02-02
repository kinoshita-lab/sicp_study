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

;; 2.47
(define (make-frame origin edge1 edge2)
  (list origin edge1 edge2))
;編
(define o1 (make-vect 1 4))
(define e1 (make-vect 2 5))
(define e2 (make-vect 3 6))
(define f1 (make-frame o1 e1 e2))
gosh> ((1 . 1) (2 . 5) (3 . 6))

(define (origin frame)
  (car frame))
(define (edge1 frame)
  (car (cdr frame)))
(define (edge2 frame)
  (car (cdr (cdr frame))))

(origin f1)
(edge1 f1)
(edge2 f1)

(define (make-frame origin edge1 edge2)
  (cons origin (cons edge1 edge2)))
;編
(define o1 (make-vect 1 4))
(define e1 (make-vect 2 5))
(define e2 (make-vect 3 6))
(define f1 (make-frame o1 e1 e2))
f1
gosh> ((1 . 4) (2 . 5) 3 . 6)
(define (origin frame)
  (car frame))
(define (edge1 frame)
  (car (cdr frame)))
(define (edge2 frame)
  (cdr (cdr frame)))
(origin f1)
(edge1 f1)
(edge2 f1)


;2.48
; 簡単な時とムズい時の差がすごいな
(define (make-segment start-segment end-segment)
  (list start-segment end-segment))
(define start (make-vect 1 2))
(define end (make-vect 3 4))

(make-segment start end)
;gosh> ((1 . 2) (3 . 4))

;; これもcons編が作れる　どっちがいいのやら
(define (make-segment start-segment end-segment)
  (cons start-segment end-segment))
(make-segment start end)
;gosh> ((1 . 2) 3 . 4)
; list版で進める
(define (make-segment start-segment end-segment)
  (list start-segment end-segment))
(define start (make-vect 1 2))
(define end (make-vect 3 4))
(define segment (make-segment start end))
(define (start-segment segments)
  (car segments))

(define (end-segment segment)
  (car (cdr segment)))
(end-segment segment)
;; 2.49
; segments->painterを使い, 次の基本的ペインタを定義せよ: 
; a. 指定されたフレームの外形を描くペインタ. 
; b. フレームの向い側の頂点を結んで「X」を描くペインタ. 
; c. フレームの辺の中点を結んで菱形を描くペインタ. 
; d. waveペインタ. 
(define (segments->painter segment-list)
  (lambda (frame)
    (for-each
     (lambda (segment)
       (draw-line
        ((frame-coord-map frame) (start-segment segment))
        ((frame-coord-map frame) (end-segment segment))))
     segment-list)))
;↑いろいろとたりてないけど動く前提で
(define (segments->painter segment-list)
;  (define (draw-line start-segment end-segment)
;    )                  
    (lambda (frame)
    (for-each
     (lambda (segment)
       (draw-line
        ((frame-coord-map frame) start-segment segment)
        ((frame-coord-map frame) end-segment segment)))))
     segment-list)
; ↑動くにたようなものを作った 
; frameの定義はこっちのリスト版を使う
(define (make-frame origin edge1 edge2)
  (list origin edge1 edge2))
;編
(define o1 (make-vect 1 4))
(define e1 (make-vect 2 5))
(define e2 (make-vect 3 6))
(define f1 (make-frame o1 e1 e2))
gosh> ((1 . 1) (2 . 5) (3 . 6))
f1
(define (origin frame)
  (car frame))
(define (edge1 frame)
  (car (cdr frame)))
(define (edge2 frame)
  (car (cdr (cdr frame))))

(define o1 (make-vect 1 4))
(define e1 (make-vect 2 5))
(define e2 (make-vect 3 6))
(define f1 (make-frame o1 e1 e2))
; a
(define (draw-frame-painter frame)
  (let ((sum-vect (add-vect (edge1 frame) 
                            (edge2 frame))))
    (segments->painter 
     (list (list (origin frame) (edge1 frame))
           (list (origin frame) (edge2 frame))
           (list (edge1 frame) sum-vect)
           (list (edge2 frame) sum-vect)))))
(draw-frame-painter f1)
; gosh > (((1 . 4) (2 . 5)) ((1 . 4) (3 . 6)) ((2 . 5) (5 . 11)) ((3 . 6) (5 . 11)))

;b. フレームの向い側の頂点を結んで「X」を描くペインタ. 
(define (draw-diagonal-line frame)
  (let ((sum-vect (add-vect (edge1 frame)
                            (edge2 frame))))
    (segments->painter
     (list (list (origin frame) sum-vect)
           (list (edge1 frame) (edge2 frame))))))
(draw-diagonal-line f1)
;gosh> (((1 . 4) (5 . 11)) ((2 . 5) (3 . 6)))

;c. フレームの辺の中点を結んで菱形を描くペインタ. 
(define (center a b)
  (/ (+ a b) 2))
(define (center-vector vect1 vect2)
  (make-vect (center (xcor-vect vect1) (xcor-vect vect2))
             (center (ycor-vect vect1) (ycor-vect vect2))))
(center-vector o1 e1)


(center 1 2)
(define (draw-dia-line frame)
  (define (center a b) 
    (/ (+ a b) 2))
  (define (center-vector vect1 vect2)
    (make-vect (center (xcor-vect vect1) (xcor-vect vect2))
               (center (ycor-vect vect1) (ycor-vect vect2))))
  (define (sum-vect frame)  ; ちょっとやり方変えてみた
    (add-vect (edge1 frame)
              (edge2 frame)))
  (let ((p1 (center-vector (origin frame) (edge1 frame)))
        (p2 (center-vector (edge1 frame) (sum-vect frame)))
        (p3 (center-vector (edge2 frame) (sum-vect frame)))
        (p4 (center-vector (origin frame) (edge2 frame))))
    (segments->painter
     (list (list p1 p2)
           (list p2 p3)
           (list p3 p4)
           (list p4 p1)))))
(draw-dia-line f1)
;; gosh> (((3/2 . 9/2) (7/2 . 8)) ((7/2 . 8) (4 . 17/2)) ((4 . 17/2) (2 . 5)) ((2 . 5) (3/2 . 9/2)))            

;d. waveペインタ. 
(define (wave-painter frame)
  (define vect1 (edge1 frame))
  (define vect2 (edge2 frame))
  (define z (origin frame))
  (define (make-draw-point-vector vect1 vect2 magnitude-vect1 magnitude-vect2)
    (add-vect (scale-vect vect1 magnitude-vect1)
              (scale-vect vect2 magnitude-vect2)))
  (let ((p1 (make-draw-point-vector z     vect2 0    0.33)) ; 右足の先
        (p2 (make-draw-point-vector vect1 vect2 0.5  0.35)) ; 右足の付け根
        (p3 (make-draw-point-vector vect1 vect2 0.6  0.3)) ; 右脇
        (p4 (make-draw-point-vector vect1 vect2 0.45 0.25)) ; 右肘
        (p5 (make-draw-point-vector vect1     z 0.75 0)) ; 右手の先-1
        (p6 (make-draw-point-vector vect1     z 0.8  0)) ; 右手の先-2
        (p7 (make-draw-point-vector vect1 vect2 0.6  0.25)) ; 右ひじ内側
        (p8 (make-draw-point-vector vect1 vect2 0.7  0.3)) ; 右肩
        (p9 (make-draw-point-vector vect1 vect2 0.7  0.4)) ; 右首
        (p10 (make-draw-point-vector vect1 vect2 0.8  0.35)) ; 右耳
        (p11 (make-draw-point-vector vect1 vect2 1.0  0.45)) ; 右頭てっぺん
        (p12 (make-draw-point-vector vect1 vect2 1.0  0.55)) ; 左頭てっぺん
        (p13 (make-draw-point-vector vect1 vect2 0.8  0.65)) ; 左耳
        (p14 (make-draw-point-vector vect1 vect2 0.7  0.6)) ; 左首
        (p15 (make-draw-point-vector vect1 vect2 0.7  0.7)) ; 左肩
        (p16 (make-draw-point-vector vect1     z 0.4  0)) ;; 左手の先-1
        (p17 (make-draw-point-vector vect1     z 0.2  0)) ;; 左手の先-2
        (p18 (make-draw-point-vector vect1 vect2 0.5  0.6)); 左わき
        (p19 (make-draw-point-vector z     vect2   0  0.65)) ; 左足の先
        (p20 (make-draw-point-vector z     vect2   0  0.6))  ; 股-1
        (p21 (make-draw-point-vector vect1 vect2 0.2  0.5))  ; 股-2
        (p22 (make-draw-point-vector z     vect2   0  0.3)))  ; 股-3
    (segments->painter
     (list (list p1 p2) ; 線その1
           (list p2 p3)
           (list p3 p4)
           (list p4 p5)
           (list p6 p7) ; 線その2
           (list p7 p8) 
           (list p8 p9)
           (list p9 p10)
           (list p10 p11)
           (list p12 p13) ; 線その3
           (list p13 p14)
           (list p14 p15)
           (list p15 p16)
           (list p16 p17)
           (list p17 p18)
           (list p18 p19)
           (list p20 p21) ;線その4
           (list p21 p22)))))
(wave-painter f1)


(define (transform-painter painter origin corner1 corner2)
  (lambda (frame)
    (let ((m (frame-coord-map frame)))
      (let ((new-origin (m origin)))
        (painter
         (make-frame new-origin
                     (sub-vect (m corner1) new-origin)
                     (sub-vect (m corner2) new-origin)))))))

(define (flip-vert painter)
  (transform-painter painter
                     (make-vect 0.0 1.0)
                     (make-vect 1.0 1.0)
                     (make-vect 0.0 0.0)))

(define (shrink-to-upper-right painter)
  (transform-painter painter
                     (make-vect 0.5 0.5)
                     (make-vect 1.0 0.5)
                     (make-vect 0.5 1.0)))

(define (rotate90 painter)
  (transform-painter painter
                     (make-vect 1.0 0.0)
                     (make-vect 1.0 1.0)
                     (make-vect 0.0 0.0)))

(define (squash-inwards painter)
  (transform-painter painter
                     (make-vect 0.0 0.0)
                     (make-vect 0.65 0.35)
                     (make-vect 0.35 0.65)))


(define (beside painter1 painter2)
  (let ((split-point (make-vect 0.5 0.0)))
    (let ((paint-left
           (transform-painter painter1
                              (make-vect 0.0 0.0)
                              split-point
                              (make-vect 0.0 1.0)))
          (paint-right
           (transform-painter painter2
                              split-point
                              (make-vect 1.0 0.0)
                              (make-vect 0.5 1.0))))
      (lambda (frame)
        (paint-left frame)
        (paint-right frame)))))


; 2.50...の前に変換がわかっているのかな
; 何もしない変換は多分こう
(define (identity painter)
  (transform-painter painter
                     (make-vect 0.0 0.0)
                     (make-vect 1.0 0.0)
                     (make-vect 0.0 1.0)))

; 2.50
(define (flip-horiz painter)
  (transform-painter painter
                     (make-vect 0.0 1.0)
                     (make-vect 0.0 0.0)
                     (make-vect 0.0 1.0)))


(define (rotate180 painter)
  (transform-painter painter
                     (make-vect 1.0 1.0)
                     (make-vect 0.0 1.0)
                     (make-vect 1.0 0.0)))

(define (rotate270 painter)
  (transform-painter painter
                     (make-vect 0.0 1.0)
                     (make-vect 0.0 0.0)
                     (make-vect 1.0 1.0)))

; 2.51その1
(define (below painter1 painter2)
  (let ((split-point (make-vect 0.0 0.5)))
    (let ((paint-bottom
           (transform-painter painter1
                              (make-vect 0.0 0.0)
                              (make-vect 1.0 0.0)
                              split-point))
          (paint-up
           (transform-painter painter2
                              split-point
                              (make-vect 1.0 0.5)
                              (make-vect 0.0 1.0)))))
    (lambda (frame)
      (paint-bottom frame)
      (paint-up frame))))

; 2.51その2 besideで2つ縦に並べたやつを最後に90度回せばいいのかな
(define (below-2 painter1 painter2)
  (rotate90 (beside (rotete270 painter1) (rotete270 painter2))))

;2.52
;a. 問題2.49の基本的waveペインタに(例えば笑っているような)線分を加えよ. 
;d. waveペインタ. 
(define (wave-painter frame)
  (define vect1 (edge1 frame))
  (define vect2 (edge2 frame))
  (define z (origin frame))
  (define (make-draw-point-vector vect1 vect2 magnitude-vect1 magnitude-vect2)
    (add-vect (scale-vect vect1 magnitude-vect1)
              (scale-vect vect2 magnitude-vect2)))
  (let ((p1 (make-draw-point-vector z     vect2 0    0.33)) ; 右足の先
        (p2 (make-draw-point-vector vect1 vect2 0.5  0.35)) ; 右足の付け根
        (p3 (make-draw-point-vector vect1 vect2 0.6  0.3)) ; 右脇
        (p4 (make-draw-point-vector vect1 vect2 0.45 0.25)) ; 右肘
        (p5 (make-draw-point-vector vect1     z 0.75 0)) ; 右手の先-1
        (p6 (make-draw-point-vector vect1     z 0.8  0)) ; 右手の先-2
        (p7 (make-draw-point-vector vect1 vect2 0.6  0.25)) ; 右ひじ内側
        (p8 (make-draw-point-vector vect1 vect2 0.7  0.3)) ; 右肩
        (p9 (make-draw-point-vector vect1 vect2 0.7  0.4)) ; 右首
        (p10 (make-draw-point-vector vect1 vect2 0.8  0.35)) ; 右耳
        (p11 (make-draw-point-vector vect1 vect2 1.0  0.45)) ; 右頭てっぺん
        (p12 (make-draw-point-vector vect1 vect2 1.0  0.55)) ; 左頭てっぺん
        (p13 (make-draw-point-vector vect1 vect2 0.8  0.65)) ; 左耳
        (p14 (make-draw-point-vector vect1 vect2 0.7  0.6)) ; 左首
        (p15 (make-draw-point-vector vect1 vect2 0.7  0.7)) ; 左肩
        (p16 (make-draw-point-vector vect1     z 0.4  0)) ;; 左手の先-1
        (p17 (make-draw-point-vector vect1     z 0.2  0)) ;; 左手の先-2
        (p18 (make-draw-point-vector vect1 vect2 0.5  0.6)); 左わき
        (p19 (make-draw-point-vector z     vect2   0  0.65)) ; 左足の先
        (p20 (make-draw-point-vector z     vect2   0  0.6))  ; 股-1
        (p21 (make-draw-point-vector vect1 vect2 0.2  0.5))  ; 股-2
        (p22 (make-draw-point-vector z     vect2   0  0.3))  ; 股-3
    
    (segments->painter
     (list (list p1 p2) ; 線その1
           (list p2 p3)
           (list p3 p4)
           (list p4 p5)
           (list p6 p7) ; 線その2
           (list p7 p8) 
           (list p8 p9)
           (list p9 p10)
           (list p10 p11)
           (list p12 p13) ; 線その3
           (list p13 p14)
           (list p14 p15)
           (list p15 p16)
           (list p16 p17)
           (list p17 p18)
           (list p18 p19)
           (list p20 p21) ;線その4
           (list p21 p22)))))
(wave-painter f1)

;b. corner-splitで構成されるパターンを(例えば二つでなく, up-splitとright-splitのコピーを使うことで)変更せよ. 
;c. square-limitでsquare-of-fourを使う版を, 隅を異るパターン(例えばRogers氏を, 四角の隅では外側を向せるように)修正せよ. 
(define (square-limit painter n)
  (let ((quarter (corner-split painter n)))
    (let ((half (beside (flip-horiz quarter) quarter)))
      (below (flip-vert half) half))))
