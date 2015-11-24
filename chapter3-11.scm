(load "./stream.scm")



(define (pi-summands n)
  (cons-stream (/ 1.0 n)
               (stream-map - (pi-summands (+ n 2)))))
;; これ動かしてみたいけど途中まで表示するには
;; show-streamを呼べばいいのかな。
(show-stream (pi-summands 1) 10)
;; gosh>  1.0 -0.3333333333333333 0.2 -0.14285714285714285 0.1111111111111111 -0.09090909090909091 0.07692307692307693 -0.06666666666666667 0.058823529411764705 -0.05263157894736842
;; いいげ。

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
