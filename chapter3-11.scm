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

;; 3.63
;; Alyssa版はguessesを返すのではなく、sqrt-streamを呼びまくって突き進んでいく。メモ化ができない。
;; delayがメモ化してなかったら結局同じように計算が進んでいくから同じような気がする。

;; 3.64
(define (stream-limit s tolerance)
  (let ((s0 (stream-car s)) ;; 相続く
        (s1 (stream-car (stream-cdr s)))) ;;2つの要素
    (if (< (abs (- s0 s1)) tolerance) s1 ;; 絶対値で許容誤差より小さくなるのを見つけ、その2つの要素の2番めを返す
        (stream-limit (stream-cdr s) tolerance))))
;;試
(define (sqrt x tolerance)
  (stream-limit (sqrt-stream x) tolerance))
(sqrt 2 1)
;; gosh> 1.5
(sqrt 2 0.01)
;; gosh> 1.4142156862745097
(sqrt 2 0.0000000000000000000001)
;; gosh> 1.414213562373095

;; 3.65
;; pi-summandsのかんじでいけるよね
(define (ln2-summands n)
  (cons-stream (/ 1.0 n)
               (stream-map - (ln2-summands (+ n 1)))))
(show-stream (ln2-summands 1) 10)
;; gosh>  1.0 -0.5 0.3333333333333333 -0.25 0.2 -0.16666666666666666 0.14285714285714285 -0.125 0.1111111111111111 -0.1
;; いいげ。

;; その1 普通編
(define ln2-stream
  (partial-sums (ln2-summands 1)))
(show-stream ln2-stream 10)
;; gosh>  1.0 0.5 0.8333333333333333 0.5833333333333333 0.7833333333333332 0.6166666666666666 0.7595238095238095 0.6345238095238095 0.7456349206349207 0.6456349206349207

;; ln2ってなんだろう 0.3010みたいなやつ・・・？
;; 自然対数の方だった 0.693147...

;; その2 euler編
(define (square x) ;; squareがなかった
  (* x x))
(show-stream (euler-transform ln2-stream) 10)
;; gosh>  0.7 0.6904761904761905 0.6944444444444444 0.6924242424242424 0.6935897435897436 0.6928571428571428 0.6933473389355742 0.6930033416875522 0.6932539682539683 0.6930657506744464


;; その3 タブロー編
(show-stream (accelerated-sequence euler-transform ln2-stream) 10)
;; 1.0 0.7 0.6932773109243697 0.6931488693329254 0.6931471960735491 0.6931471806635636 0.6931471805604039 0.6931471805599445 0.6931471805599427 0.6931471805599454

;; どれくらい速く？ その1 < その2 < その3 ってかんじ

;;; 対の無限のストリーム
(define (interleave s1 s2)
        (if (stream-null? s1)
            s2
            (cons-stream (stream-car s1)
                         (interleave s2 (stream-cdr s1)))))
(define (pairs s t)
  (cons-stream
   (list (stream-car s) (stream-car t))
   (interleave
    (stream-map (lambda (x) (list (stream-car s) x))
                (stream-cdr t))
    (pairs (stream-cdr s) (stream-cdr t)))))

;; 3.66

(define ones (cons-stream 1 ones))
(define integers (cons-stream 1 (add-streams ones integers)))
;; 例えば
(show-stream (pairs integers integers) 100)
;; (1 1) (1 2) (2 2) (1 3) (2 3) (1 4) (3 3) (1 5) (2 4) (1 6)
;; ↑を本文に出てた並べ替えてみるとこんな感じ
;; (1 1) (1 2) (1 3) (1 4) (1 5) (1 6) 
;;       (2 2) (2 3) (2 4) 
;;             (3 3)
(show-stream (pairs integers integers) 200)
;; ってやったら198番目だった
;; (99, 100)は出るのすごい時間かかりそう 10000くらい？
;; 全然でなかった
;; (n, n)みたいなやつは何回ででるのか?
;; 1,1 1
;; 2,2 3
;; 3,3 7
;; 4,4 15
;; なんとなく 2^n -1　番目っぽい
;; 5,5 は31番め　よさげ
;; (100, 100)は
;; 1267650600228229401496703205375番め。
;; 同じ感じでやると
;; 1,2 2+0
;; 2,3 5 4+1
;; 3,4 11 8+3
;; 4,5 23 16+7
;; 5,6 47 32 +15
;; 2^n + 2^(n-1) -1 っぽい
;; そうすると (99, 100)は
;; 950737950171172051122527404031番め

;; 3.67 問題の意味すらわからない
;; (2 1)みたいなのを出せってことみたい
(define (pairs2 s t)
  (cons-stream
   (list (stream-car s) (stream-car t))
    (interleave
     (interleave
      (stream-map (lambda (x) (list (stream-car s) x))
                  (stream-cdr t))
      (stream-map (lambda (x) (list x (stream-car s))) ;; 逆のやつを作って合体
                  (stream-cdr t)))
       (pairs (stream-cdr s) (stream-cdr t)))))
(show-stream (pairs2 integers integers) 10)
;; gosh>  (1 1) (1 2) (2 2) (2 1) (2 3) (1 3) (3 3) (3 1) (2 4) (1 4)
;; よさげ。

;; 3.68 なぜいつもlouisはまちがっているのだろう
(define (pairs-l s t)
  (interleave
   (stream-map (lambda (x) (list (stream-car s) x))
               t)
   (pairs-l (stream-cdr s) (stream-cdr t))))

;; (show-stream (pairs-l integers integers) 10)
;; ってやると無限ループになって何も表示されなかった。
;; 違うところは最初のstream-mapの2番めの引数が(cdr-stream t)じゃなくてtなところ
;; (define (interleave s1 s2)
;;        (if (stream-null? s1)
;;            s2
;;            (cons-stream (stream-car s1)
;;                         (interleave s2 (stream-cdr s1)))))
;; interleaveはこんな感じになっていてs2がtのままになってしまうから？

;; 3.69
;; とりあえず3つの組をつくってみる
;; うまくいっていたpairを改造すれば出来そう..と思ったけどわからなかった
;; こうらしい
(define (triples s t u)
  (cons-stream
    (list (stream-car s) (stream-car t) (stream-car u))
    (interleave
      (stream-map
        (lambda (x) (list (stream-car s) x))
        (pairs t u))
      (triples (stream-cdr s) (stream-cdr t) (stream-cdr u)))))



;; フィルタる
(define integer-triples (triples integers integers integers))
(show-stream integer-triples 10)
;; これでいいような気がするけどどうにも動かない。謎。無限ループになってしまう。
;; (define pytagoras-triples
;;   (stream-filter
;;    (lambda (s)
;;      (= (square (car s)) (+ (square (cadr s)) (square (caddr s)))))
;;    integer-triples))
;; (show-stream pytagoras-triples 10)


;; 3.70
(define (merge-weighted s1 s2 weight)
  (cond ((stream-null? s1) s2) ;; 長さが違って、どっちか終わっちゃった時とか
		((stream-null? s2) s1) ;; は残ったほうのストリームをそのまま返す
		(else
		 (let ((s1car (stream-car s1)) ;; 先頭を
				(s2car (stream-car s2))) ;; 持ってきて・・
		   (cond ((< (weight s1car) (weight s2car)) ;; 適用した結果を使って比較
				  (cons-stream s1car (merge-weighted (stream-cdr s1) s2 weight)))      ;; 小さい順
				 (else                                                                 ;; に
				  (cons-stream s2car (merge-weighted (stream-cdr s2) s1 weight)))))))) ;; 並べる
				 

(define (weighted-pairs s t w)
  (cons-stream
   (list (stream-car s) (stream-car t))
   (merge-weighted
    (stream-map (lambda (x) (list (stream-car s) x))
                (stream-cdr t))
    (weighted-pairs (stream-cdr s) (stream-cdr t) w) w)))

;; a
(define q70-a
  (weighted-pairs integers integers
				  (lambda (si)  
					(+ (car si) (cadr si)))))

(show-stream q70-a 10)
;; gosh>  (1 1) (1 2) (2 2) (1 3) (2 3) (1 4) (3 3) (1 5) (2 4) (1 6)
;; よさげ。

;; b
;; 2, 3, 5どれでも割り切れない正の整数 をまず作る
(define q70b-integer-stream
  (stream-filter (lambda (x)
                   (not (and (= (remainder x 2) 0)
                             (= (remainder x 3) 0)
                             (= (remainder x 5) 0))))
                 integers))
(show-stream q70b-integer-stream 100)
;; gosh>  1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 51 52 53 54 55 56 57 58 59 61 62 63 64 65 66 67 68 69 70 71 72 73 74 75 76 77 78 79 80 81 82 83 84 85 86 87 88 89 91 92 93 94 95 96 97 98 99 100 101 102 103
;; いいのかな。確かに30とかそうっぽい
(define q70-b
  (weighted-pairs q70b-integer-stream q70b-integer-stream
                  (lambda (si)
                    (let ((i (car si))
                          (j (cadr si)))
                      (+ (* 2 i) (* 3 j) (* 5 i j))))))
(show-stream q70-b 10)

;; こんなのでてきた
;; (1 1)(1 2)
;;  (1 2)(1 3)
;;  (1 3)(1 4)
;;  (2 2)(2 3)
;; (2 3)
;;  (1 4)(1 5)
;;  (1 5)(1 6)
;;  (2 3)(2 4)
;; (2 4)
;;  (1 6)(1 7)
;;  (2 4)(2 5)
;; (3 3)
;;  (1 7)(1 8)
