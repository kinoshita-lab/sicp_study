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

;; 4.41 うごかないうごかない言ってたから本当にうごかさないといけないの出てきた・・
(define members '(baker cooper fletcher miller smith))
(define all-possibilities (list  (cons 1 members) (cons 2 members) (cons 3 members) (cons 4 members) (cons 5 members)))
all-possibilities
((1 baker cooper fletcher miller smith) (2 baker cooper fletcher miller smith) (3 baker cooper fletcher miller smith) (4 baker cooper fletcher miller smith) (5 baker cooper fletcher miller smith))

;; 単純なやつ
(define (filtered-member-by-floor floor member member-list)
  (define (filter-member member members)
	(filter (lambda (m) (not (equal? member m))) members))
  (let ((floor-number (car member-list))
		(members (cdr member-list)))
	(if (not (= floor floor-number)) member-list
		(cons floor-number (filter-member member members)))))
(filtered-member-by-floor 1 'baker (cons 1 members))
;; gosh> (1 cooper fletcher miller smith)
(define (filter-all-floor-member-by-floor floor member member-list)
  (if (eq? member-list '()) '()
	  (cons (filtered-member-by-floor floor member (car member-list))
			(filter-all-floor-member-by-floor floor member (cdr member-list)))))
(filter-all-floor-member-by-floor 1 'baker all-possibilities)
;; gosh> ((1 cooper fletcher miller smith) (2 baker cooper fletcher miller smith) (3 baker cooper fletcher miller smith) (4 baker cooper fletcher miller smith) (5 baker cooper fletcher miller smith))
;; これで上の方のやつはできそう
(define (normal-scheme-distinct member-list)
  (begin
	(set! member-list (filter-all-floor-member-by-floor 5 'baker member-list))
	(set! member-list (filter-all-floor-member-by-floor 1 'cooper member-list))
	(set! member-list (filter-all-floor-member-by-floor 5 'fletcher member-list))
	(set! member-list (filter-all-floor-member-by-floor 1 'fletcher member-list))
	))
(normal-scheme-distinct all-possibilities)
;; gosh> ((1 baker miller smith) (2 baker cooper fletcher miller smith) (3 baker cooper fletcher miller smith) (4 baker cooper fletcher miller smith) (5 cooper miller smith))

;; のこりもこんな感じで頑張ればいけるかもだけどくじけた。
;; これつかうと楽にできるっぽい https://practical-scheme.net/gauche/man/gauche-refj/Zu-miHe-wase.html



;; 4.42
;; どうせ動かないけど4.38風にやればいいのだろう
(define (distinct? items)
  (cond ((null? items) true)
		((null? (cdr items)) true)
		((member (car items) (cdr items)) false)
		(else (distinct? (cdr items)))))
;; requireのところは両方真のことはないのでxorだ
;; https://ja.wikipedia.org/wiki/XOR%E3%82%B2%E3%83%BC%E3%83%88
;; これのっけたことにした
(define (xor a b)
  (define (nand a b)
	(not (and a b)))
  (let* ((first-gate-out (nand a b))
		 (second-above-out (nand a first-gate-out))
		 (second-below-out (nand b first-gate-out)))
	(nand second-above-out second-below-out)))

(define (multiple-dwelling)
  (let ((betty (amb 1 2 3 4 5)) (ethel (amb 1 2 3 4 5))
		(joan (amb 1 2 3 4 5)) (kitty (amb 1 2 3 4 5))
		(mary (amb 1 2 3 4 5)))
	(require 
	 (distinct? (list betty ethel joan kitty mary)))
	(require (xor (= kitty 2) (= betty 3)))
	(require (xor (= ethel 1) (= joan 2)))
	(require (xor (= joan 3) (= ethel 5)))
	(require (xor (= kitty 2) (= mary 4)))
	(require (xor (= mary 4) (= betty 1)))
	(list (list 'betty betty) (list 'ethel ethel)
		  (list 'joan joan) (list 'kitty kitty)
		  (list 'mary mary))))

;; 4.43 同じ感じでやるとこんな
(define (multiple-dwelling)
  (let ((moore (amb 'gabrielle 'lorna 'rosalind 'melissa 'mary)) 
		(dawning (amb 'gabrielle 'lorna 'rosalind 'melissa 'mary)) 
		(hall (amb 'gabrielle 'lorna 'rosalind 'melissa 'mary)) 
		(barnacle  (amb 'gabrielle 'lorna 'rosalind 'melissa 'mary)) 
		(parker (amb 'gabrielle 'lorna 'rosalind 'melissa 'mary)) 
	(require 
	 (distinct? (list 'betty 'ethel 'joan 'kitty 'mary)))
	(require (= moore 'mary))
	(require (not (= barnacle 'gabrielle)))
	(require (not (= moore 'lorna)))
	(require (not (= downing 'melissa)))
	(require (= barnacle 'melissa))
	(require (= parer 'mery))
	(list (list 'moore moore) (list 'dawning dawning)
		  (list 'hall hall) (list 'barnacle barnacle)
		  (list 'parker parker)))))

;; 4.44
;; 8クイーン解けない・・
