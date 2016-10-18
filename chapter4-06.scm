;; 4.3 Scheme の変異版— 非決定性計算
;; 4.35
;; 2 つの与えられた限界の間の整数を返す手続きaninteger-
;; between を書け。
;; ambで適当にかけばいいのかな。動かないけど。
(define (an-integer-between min max)
  (define (an-integer-starting-from n)
	(amb n (an-integer-starting-from (+ n 1))))
  (let ((start-from (an-integer-starting-from min)))
	(require ((<= start-from max))) 1
	(amb start-from)))

;; 4.36
;; 3.69はこんなでした
;; (define (triples s t u)
;;   (cons-stream
;;     (list (stream-car s) (stream-car t) (stream-car u))
;;     (interleave
;;       (stream-map
;;         (lambda (x) (list (stream-car s) x))
;;         (pairs t u))
;;       (triples (stream-cdr s) (stream-cdr t) (stream-cdr u)))))
;; 
;; (define pytagoras-triples
;;   (stream-filter
;;    (lambda (s)
;;      (= (square (car s)) (+ (square (cadr s)) (square (caddr s)))))
;;    integer-triples))
;; (show-stream pytagoras-triples 10)
;; 
;; 多分これだとambがダメだった場合に1, 2, 3,... という風にすすんでいってしまって他の2つ次第ではピタゴラス数になる場合がひろえないのではないだろうか。
;; そこらへんがストリームと違うっぽい。
;; まあうごかないからわからないけど。
;; 書くとしたらそこらへん気にしたのをかけばいいのではと言う感じ

;; 4.37

