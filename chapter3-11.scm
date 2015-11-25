(load "./stream.scm")



(define (pi-summands n)
  (cons-stream (/ 1.0 n)
               (stream-map - (pi-summands (+ n 2)))))
;; これ動かしてみたいけど途中まで表示するには
;; show-streamを呼べばいいのかな。
(show-stream (pi-summands 1) 10)
;; gosh>  1.0 -0.3333333333333333 0.2 -0.14285714285714285 0.1111111111111111 -0.09090909090909091 0.07692307692307693 -0.06666666666666667 0.058823529411764705 -0.05263157894736842
;; いいげ。

;; pi-stream
(define (add-streams s1 s2)
  (stream-map + s1 s2))
(define (partial-sums stream)
  (define sum
    (cons-stream
     (stream-car stream)
     (add-streams sum (stream-cdr stream))))
  sum)
(define (scale-stream stream factor)
  (stream-map (lambda (x) (* x factor))
              stream))
(define pi-stream
  (scale-stream (partial-sums (pi-summands 1)) 4))
(show-stream pi-stream 10)
;; 4.0 2.666666666666667 3.466666666666667 2.8952380952380956 3.3396825396825403 2.9760461760461765 3.2837384837384844 3.017071817071818 3.2523659347188767 3.0418396189294032

;; 動いたのでついでに上のsqrt-streamもやってみる
(define (average x y)
  (/ (+ x y) 2))

(define (sqrt-improve guess x)
  (average guess (/ x guess)))
(define (sqrt-stream x)
  (define guesses
    (cons-stream 1.0
                 (stream-map (lambda (guess)
                               (sqrt-improve guess x))
                             guesses)))
  guesses)
(show-stream (sqrt-stream 2) 10)
;; gosh>  1.0 1.5 1.4166666666666665 1.4142156862745097 1.4142135623746899 1.414213562373095 1.414213562373095 1.414213562373095 1.414213562373095 1.414213562373095

;; euler-transform
(define (euler-transform s)
  (let ((s0 (stream-ref s 0))
        (s1 (stream-ref s 1))
        (s2 (stream-ref s 2)))
    (cons-stream (- s2 (/ (square (- s2 s1))
                          (+ s0 (* -2 s1) s2)))
                 (euler-transform (stream-cdr s)))))
(show-stream (euler-transform pi-stream) 10)
;; gosh>  3.166666666666667 3.1333333333333337 3.1452380952380956 3.13968253968254 3.1427128427128435 3.1408813408813416 3.142071817071818 3.1412548236077655 3.1418396189294033 3.141406718496503

;; タブロー
(define (make-tableau transform s)
  (cons-stream s
               (make-tableau transform
                             (transform s))))
(define (accelerated-sequence transform s)
  (stream-map stream-car
              (make-tableau transform s)))

(show-stream (accelerated-sequence euler-transform
                                   pi-stream) 10)
;; gosh>  4.0 3.166666666666667 3.142105263157895 3.141599357319005 3.1415927140337785 3.1415926539752927 3.1415926535911765 3.141592653589778 3.1415926535897953 3.141592653589795
