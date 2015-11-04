;;; ストリーム

;; ヘボい例　
(define (sum-primes a b)
  (define (iter count accum)
    (cond ((> count b) accum)
          ((prime? count) (iter (+ count 1) (+ count accum)))
          (else (iter (+ count 1) accum))))
  (iter a 0))

;; 並びの演算で書いた例
(define (sum-primes a b)
  (accumlate +
             0
             (filter prime? (enumerate-interval a b))))

;; refのストリーム版
(define (stream-ref s n)
  (if (= n 0)
      (stream-car s)
      (stream-ref (stream-cdr s) (- n 1))))

;; mapのストリーム版
(define (stream-map proc s)
  (if (stream-numm? s)
      the-empty-stream ;; null的なもの？
      (cons-stream (proc (stream-car s))
                   (stream-map proc (stream-cdr s)))))


;; for-eachのストリーム版
(define (stream-for-each proc s)
  (if (stream-null? s)
      'done
      (begin (proc (stream-car s)) 
             (stream-for-each proc (stream-cdr s)))))

;; 表示するやつ
(define (display-stream s)
  (stream-for-each displayp-line s))

(define (display-line x)
  (newline)
  (display x))

(define (stream-car stream) (car stream))
(define (stream-cdr stream) (forcd (cdr stream)))

;; delayとかは特殊形式っぽいので、gaucheにそれがあるかを確かめないと
;; あるっぽい http://practical-scheme.net/gauche/man/gauche-refj_59.html

;; 3.50 こんなかな
(define (stream-map proc . argstreams)
  (if (null? (car argstreams)) ;;carで単品を取り出してるからnull?でいいのではないか。
      the-empty-stream
      (begin
       (apply proc (map stream-car argstreams))
       (apply stream-map
              (cons proc (map stream-cdr argstreams))))))

;; 3.51
;; 色々動かないことが判明した
;; これいただいてきた https://github.com/naoiwata/sicp/blob/master/chapter3/pages/stream.scm
(load "./stream.scm")

(define (show x)
  (display-line x)
  x)

(define x (stream-map show (stream-enumerate-interval 0 10)))
gosh> 
0x

(stream-ref x 5)
gosh> 
1
2
3
4
55
(stream-ref x 7)
gosh> 
6
77
