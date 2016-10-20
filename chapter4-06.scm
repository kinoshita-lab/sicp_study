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
;; 多分これだと1つのambがダメだった場合に1, 2, 3,... という風にすすんでいってしまって他の2つ次第ではピタゴラス数になる場合がひろえないのではないだろうか。
;; そこらへんがストリームと違うっぽい。
;; まあうごかないからわからないけど。
;; 書くとしたらそこらへん気にしたのをかけばいいのではと言う感じ

;; 4.37
;; (ヒント：探索すべき可能性の数を考えよ) ってことなのでそれだけ考えてみると・・
;; require がOKになる可能性がbenのヤツのほうが高くなるぶん速そう

;; 4.38
;; どうせうごかないから写経だけでも
(define (distinct? items)
  (cond ((null? items) true)
		((null? (cdr items)) true)
		((member (car items) (cdr items)) false)
		(else (distinct? (cdr items)))))
(define (multiple-dwelling)
  (let ((baker (amb 1 2 3 4 5)) (cooper (amb 1 2 3 4 5))
		(fletcher (amb 1 2 3 4 5)) (miller (amb 1 2 3 4 5))
		(smith (amb 1 2 3 4 5)))
	(require 
	 (distinct? (list baker cooper fletcher miller smith)))
	(require (not (= baker 5)))
	(require (not (= cooper 1)))
	(require (not (= fletcher 5)))
	(require (not (= fletcher 1)))
	(require (> miller cooper))
	(require (not (= (abs (- smith fletcher)) 1))) ;; 4.38ではここが消える
	(require (not (= (abs (- fletcher cooper)) 1))) ;; 4.38ではここが消える
	(list (list 'baker baker) (list 'cooper cooper)
		  (list 'fletcher fletcher) (list 'miller miller)
		  (list 'smith smith))))

;; しらみつぶしにやってみることにした
;; 1  2  3  4  5
;; b  c  f  m  s
;; b  c  m  f  s
;; b  f  c  m  s
;; b  f  c  s  m
;; s  b  c  f  m
;; s  c  b  f  m
;; s  f  b  c  m
;; s  f  c  b  m
;;
;; 8とおり

;; 4.39
;; 最初におもいっきりへらせたほうが後の方のたんさくが速そう
;; 全可能性は 5! = 60とおり
;; not系は4! だから各24とおりOK
;; (> miller cooper) は 9とおりx6とおりで54とおりがOK
;; となりあってないやつは　5! - 9*2 = 60 - 18 = 42とおりがOK
;; とすると
(define (multiple-dwelling)
  (let ((baker (amb 1 2 3 4 5)) (cooper (amb 1 2 3 4 5))
		(fletcher (amb 1 2 3 4 5)) (miller (amb 1 2 3 4 5))
		(smith (amb 1 2 3 4 5)))
	(require 
	 (distinct? (list baker cooper fletcher miller smith)))
	(require (not (= baker 5)))
	(require (not (= cooper 1)))
	(require (not (= fletcher 5)))
	(require (not (= fletcher 1)))
	(require (not (= (abs (- smith fletcher)) 1))) 
	(require (not (= (abs (- fletcher cooper)) 1))) 
	(require (> miller cooper))
	(list (list 'baker baker) (list 'cooper cooper)
		  (list 'fletcher fletcher) (list 'miller miller)
		  (list 'smith smith))))
;; こうするとはやくなるのではないか。

;; 4.40 問題の意味がかなり謎
;; ひとりずつ決めた後に条件つけてけばいいきがするけどうごかないのでよくわからないね。

