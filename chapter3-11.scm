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

;; 3.71
(define (ramanujan-weight i j)
  (+ (* i i i) (* j j j)))
(define ramanujan-weighted-stream
  (weighted-pairs integers integers
                  (lambda (si)
                    (let ((i (car si))
                          (j (cadr si)))
                      (ramanujan-weight i j)))))
(show-stream ramanujan-weighted-stream 10)
;;  (1 1) (1 2) (2 2) (1 3) (2 3) (3 3) (1 4) (2 4) (3 4) (1 5)
;; なんか並んだ。ここから同じ重みのやつを拾ってくればいいのかな。
(define (ramanujan-numbers s)
  (let* ((s1car (stream-car s))
		 (s2car (stream-car (stream-cdr s)))
		 (ws1 (ramanujan-weight (car s1car) (cadr s1car)))
		 (ws2 (ramanujan-weight (car s2car) (cadr s2car))))
	(if (= ws1 ws2)
		(cons-stream ws1 (ramanujan-numbers (stream-cdr s)))
		(ramanujan-numbers (stream-cdr s)))))
	
  
(define ramanujan-stream
  (ramanujan-numbers ramanujan-weighted-stream))
(show-stream ramanujan-stream 10)
;; gosh>  1729 4104 13832 20683 32832 39312 40033 46683 64232 65728
;; よさげだけど無駄が多いようなきがする

;; 3.72
;;  3.71の無駄方式でやる
(define (q372-weight i j)
  (+ (* i i) (* j j))) ;; 2つの平方数の和
(define q372-weighted-stream
  (weighted-pairs integers integers
                  (lambda (si)
                    (let ((i (car si))
                          (j (cadr si)))
                      (q372-weight i j)))))
(show-stream q372-weighted-stream 10)
;; gosh>  (1 1) (1 2) (2 2) (1 3) (2 3) (1 4) (3 3) (2 4) (3 4) (1 5)
(define (q372-numbers s)
  (let* ((s1car (stream-car s))
		 (s2car (stream-car (stream-cdr s)))
         (s3car (stream-car (stream-cdr (stream-cdr s))))
		 (ws1 (q372-weight (car s1car) (cadr s1car)))
		 (ws2 (q372-weight (car s2car) (cadr s2car)))
         (ws3 (q372-weight (car s3car) (cadr s3car))))
	(if (= ws1 ws2 ws3)
		(cons-stream ws1 (q372-numbers (stream-cdr s)))
		(q372-numbers (stream-cdr s)))))
	
  
(define q372-stream
  (q372-numbers q372-weighted-stream))

(show-stream q372-stream 10)
;; gosh>  325 425 650 725 845 850 925 1025 1105 1105
;; よさげ・・ではある

;; 信号としてのストリーム
(define (integral integrand initial-value dt)
  (define int
    (cons-stream initial-value
                 (add-streams (scale-stream integrand dt)
                              int))))

;; 3.73
;; 問題の意味がよくわからないんだけどv0とiはどこから入れるんだろう
;; RCの系を作っといてどこからかv0を入れるわけにもいかなそう　めんどいから外で定義
(define v0 0) ;; 0v
(define i (scale-stream ones 1));; 1A
(show-stream i 10)
;; 1 1 1 1 1 1 1 1 1 1
(define (RC R C dt)
  (add-streams (scale-stream i R) ;; R側
               (integral (scale-stream i (/ 1 C)) v0 dt))) ;; C側

(define RC1 (RC 5 1 0.5))
(show-stream RC1 10)
;;  5 5.5 6.0 6.5 7.0 7.5 8.0 8.5 9.0 9.5
;; いいのかな。

;; 3.74
;; 問題がざっくりしているなあ
(define zero-crossings
  (stream-map sign-change-detector sense-data (cons-stream 0 sense-data)))
;; こうらしい

;; 3.75
;; 毎度間違っているlouisが出てきた
;; (define (make-zero-crossings input-stream last-value)
;;   (let ((avpt (/ (+ (stream-car input-stream) last-value) 2)))
;;     (cons-stream (sign-change-detector avpt last-value)
;;                  (make-zero-crossings (stream-cdr input-stream)
;;                                       avpt))))
;; んー 2回めのlast-valueはavptになっちゃってるから？　んでlast-valueと別で追加すればいいのかな
(define (make-zero-crossings input-stream last-value last-avpt)
  (let ((avpt (/ (+ (stream-car input-stream) last-value) 2)))
    (cons-stream (sign-change-detector avpt last-value)
                 (make-zero-crossings (stream-cdr input-stream)
                                      (stream-car input-stream) ;; 真のlast-value
                                      avpt))))
;; 3.76
;; smoothはこんなかな。
(define (smooth stream)
  (cons-stream (/ (+ (stream-car stream) (stream-car (stream-cdr stream))) 2)
               (stream-cdr stream)))

;; 試したいけどいい方法はないのかな
;; gaucheだとrandom-realってのがあるっぽい　0~1までの乱数
(define sense-data
  (stream-map (lambda (s) (- 0.5 (random-real)))
              ones))
(show-stream sense-data 10)
;; 1323592462254095 0.4024595950005905 0.2215017811329516 -0.046881519204983846 -0.4575068354342976 -0.46488853519927653 0.3423869183224517 -0.4705927817606157 -0.45716694824294557
;; 使えそう。
;; smoothのテスト
(show-stream (smooth sense-data) 10)
;; 0.028916596241992276 0.35811366137278466 0.07823871737372501 -0.4157355251890671 -0.2922073295595544 -0.459492426392903 -0.15574069915658684 0.46428832142581045 -0.3491293058687771 -0.43399324775755055
;; 部品化スタイルってなんだろう
;; input-streamがsmoothったやつ　ってことであれば louisが最初考えた版を使って
(define zero-crossings
  (make-zero-crossings (smooth sense-data) 0))
;; こうかな。

;;;3.5.4 ストリームと遅延評価
(define (integral delayed-integrand initial-value dt)
  (define int
    (cons-stream initial-value
                 (let ((integrand (force delayed-integrand)))
                   (add-streams (scale-stream integrand dt)
                                int))))
  int)


;; 3.77
(define (integral delayed-integrand initial-value dt)
  (cons-stream initial-value
               (if (stream-null? (force delayed-integrand))
                   the-empty-stream
                   (integral (delay (stream-cdr (force delayed-integrand)))
                             (+ (* dt (stream-car (force delayed-integrand)))
                                initial-value)
                             dt))))

;; この問題はgaucheでは動かないらしい


;; 3.78
;; solveみたいにして delayを使って順番にかいてけばいいんだろうね
(define (scale-stream stream factor)
  (stream-map (lambda (x) (* x factor))
              stream))

(define (solve-2nd a b y0 dt)
  (define y (integral (delay dy) y0 dt))
  (define dy (integral (delay ddy) dy0 dt))
  (define ddy (add-streams (scale-stream dy a)
                           (scale-stream y b)))
  y)
;; こんなかな。

;; 3.79
;; fがどこにきいてくるかよくわからないなあ。
;; addとscaleの地点だけでよいのであれば
(define (solve-2nd-generic f y0 dt)
  (define y (integral (delay dy) y0 dt))
  (define dy (integral (delay ddy) dy0 dt))
  (define ddy (stream-map f dy y))
  y)
;; こんなかな。

;; 3.80
(define iL0 0)
(define vC0 10)

(define (RLC R L C dt)
  (define vc (integral (delay dvc) vC0 dt))
  (define il (integral (delay dil) iL0 dt))
  (define dvc (scale-stream il (/ (- 1) C)))
  (define dil (add-streams (scale-stream vc (/ 1 L))
                           (scale-stream il (/ (- R) L))))

  (stream-map (lambda (a b) (cons a b))
              vc il))
  
(show-stream (RLC 1 1 0.2 0.1) 10)
;; (10 . 0) (10.0 . 1.0) (9.5 . 1.9) (8.55 . 2.66) (7.220000000000001 . 3.249) (5.5955 . 3.6461) (3.77245 . 3.84104) (1.8519299999999999 . 3.834181) (-0.0651605000000004 . 3.6359559) (-1.8831384500000004 . 3.2658442599999997)
;; あってるのかな。

;;; 3.5.5 関数的プログラムの部品化度とオブジェクトの部品化度
(load "./ch3support.scm");; これと
(define random-init 0) ;; これがないと動かない。
(define random-numbers
  (cons-stream random-init
               (stream-map rand-update random-numbers)))

(define (map-successive-pairs f s)
  (cons-stream
   (f (stream-car s) (stream-car (stream-cdr s)))
   (map-successive-pairs f (stream-cdr (stream-cdr s)))))

(define cesaro-stream
  (map-successive-pairs (lambda (r1 r2) (= (gcd r1 r2) 1))
                        random-numbers))

(define (monte-carlo experiment-stream passed failed)
  (define (next passed failed)
    (cons-stream
     (/ passed (+ passed failed))
     (monte-carlo
      (stream-cdr experiment-stream) passed failed)))
  (if (stream-car experiment-stream)
      (next (+ passed 1) failed)
      (next passed (+ failed 1))))

(define pi
  (stream-map (lambda (p) (sqrt (/ 6 p)))
              (monte-carlo cesaro-stream 0 0)))
;; gosh> *** ERROR: attempt to calculate a division by zero
;; 動かないし


;; 3.81

;; 3.6はこんなだった。この時は自前でrand-updateを作っていてえらいな。
;; (define (random-generator initial-value)
;;   (define (rand-update x) 
;;     (let ((a 27) (b 26) (m 127))
;;       (modulo (+ (* a x) b) m)))
;;   (define (rand)
;;     (begin (set! initial-value (rand-update initial-value))
;;            initial-value))
;;   (define (reset value)
;;     (set! initial-value value))
;;   (define (dispatch m)
;;     (cond ((eq? m 'generate) (rand))
;;           ((eq? m 'reset) reset)
;;           (else (error "Unknown request -- random-generator"
;;                        m))))
;;   dispatch)

(define (random-generator initial-value)
  (define (rand-update x) 
    (let ((a 27) (b 26) (m 127))
      (modulo (+ (* a x) b) m)))
  (define rand ;; ここが数値ではなくてストリームを返す
    (cons-stream initial-value
                 (stream-map rand-update rand)))
  (define (reset value)
    (random-generator value)) ;; こうかな
  (define (dispatch m)
    (cond ((eq? m 'generate) rand)
          ((eq? m 'reset) reset)
          (else (error "Unknown request -- random-generator"
                       m))))
  dispatch)

;; 試
(define hoge (random-generator 0))

(show-stream (hoge 'generate) 10)
;;  0 26 93 124 72 65 3 107 121 118 乱数かも
(show-stream (((hoge 'reset) 10) 'generate) 10)
;; 10 42 17 104 40 90 43 44 71 38
;; 違うのでたからいいのかな。

;; 3.82
;; random-in-rangeのstreamを作らないとだ
(use srfi-27)
(random-real) ;; 0.0 ~ 1.0
(define (random high)
  (* (random-real) high))
(random 10)

(define random-init 1) 
(define (random-numbers high)
  (cons-stream (random high)
               (random-numbers high)))
(define (random-in-range-stream low high)
  (cons-stream (+ low (stream-car (random-numbers (- high low))))
  (random-in-range-stream low high)))
(show-stream (random-in-range-stream 10 20) 10)
;; gosh>  14.89764395788231 14.455862007108994 16.463130101112647 17.093648308580725 17.54686681982361 12.760250769985785 16.797026768536746 16.550980039738405 11.626117351946306 11.189976815583766
;; できた

;; monte-carloのstream版をいまいちよくわかってなかったかも
(define (monte-carlo experiment-stream passed failed)
  (define (next passed failed)
    (cons-stream
     (/ passed (+ passed failed))
     (monte-carlo
      (stream-cdr experiment-stream) passed failed)))
  (if (stream-car experiment-stream)
      (next (+ passed 1) failed)
      (next passed (+ failed 1))))


;; 面積を求めるやつ
(define (area-size x1 x2 y1 y2)
  (* (- x2 x1) (- y2 y1)))

(define (square x)
  (* x x))

;; predicateはrandomな値を2つとってきてそれが条件を満たしているのを返す手続き
;; 調べて #tとか #fとか返すやつ。例えば問題3.5みたいに円だったら
(define (predicate x y x1 x2 y1 y2)
  (let* ((cx (/ (+ x1 x2) 2.0)) 
		(cy (/ (+ y1 y2) 2.0))
		(r (- x2 cx)))
;;	(print (+ (square (- x cx)) (square (- y cy))) "," (square r))
	(<= (+ (square (- x cx)) (square (- y cy))) (square r))))
(predicate 0.0 0.0 -1 1 -1 1)
(predicate 1.5 0 -1 1 -1 1)

;; monte-caroに突っ込むexperiment-streamはすでに#t/#fのカタマリになっている必要があるっぽいので
;; x1~y2までの面積を
;; predicateに入っている確率で割った答えが延々と入っているストリームを作る・・前に単品でやってみると
(define (estimate-integral-p1 p x1 x2 y1 y2)
  (let* ((area (area-size x1 x2 y1 y2))
		 (rand-x (random-in-range-stream x1 x2))
		 (rand-y (random-in-range-stream y1 y2))
		 (carx (stream-car rand-x))
		 (cary (stream-car rand-y)))
	(p carx cary x1 x2 y1 y2)))
(estimate-integral-p1 predicate -1 1 -1 1)
;; gosh> #t

;; 1個monte-carloれるのが出てきたのでこれをストリームでやる版をつくると
(define (estimate-integral-p2 p x1 x2 y1 y2)
  (let* ((area (area-size x1 x2 y1 y2))
		 (rand-x (random-in-range-stream x1 x2))
		 (rand-y (random-in-range-stream y1 y2))
		 (carx (stream-car rand-x))
		 (cary (stream-car rand-y)))
		 (cons-stream (p carx cary x1 x2 y1 y2)
					  (estimate-integral-p2 p x1 x2 y1 y2))))

(show-stream (estimate-integral-p2 predicate -1 1 -1 1) 100)
;; gosh>  #t #f #f #f #t #f #t #t #t #t
;; なんかそれっぽいの出てきた
;; のでこれをmonte-carloにつっこんでみる
(define (estimate-integral-p3 p x1 x2 y1 y2)
  (let* ((area (area-size x1 x2 y1 y2))
		 (rand-x (random-in-range-stream x1 x2))
		 (rand-y (random-in-range-stream y1 y2))
		 (carx (stream-car rand-x))
		 (cary (stream-car rand-y)))
		 (monte-carlo (cons-stream (p carx cary x1 x2 y1 y2)
                                   (estimate-integral-p3 p x1 x2 y1 y2)) 0.0 0.0)))

(show-stream (estimate-integral-p3 predicate -1 1 -1 1) 100)

(define (estimate-integral-p3 p x1 x2 y1 y2)
  (define rand-x (random-in-range-stream x1 x2))
  (define rand-y (random-in-range-stream y1 y2))
  (define experiment-stream 
    (stream-map (lambda (n m) (p n m x1 x2 y1 y2)) rand-x rand-y)) ;; mapで適用済みじゃないとうまくいかなかった
  (define monte-carlo-stream
    (monte-carlo experiment-stream 0.0 0.0))
  monte-carlo-stream)
(show-stream (estimate-integral-p3 predicate -1 1 -1 1) 10)
;; gosh>  1.0 0.5 0.6666666666666666 0.75 0.6 0.6666666666666666 0.7142857142857143 0.75 0.7777777777777778 0.8
;; それっぽいの出てきた その2！!

;; これに後は面積をかけ算すると出来上がりかも
(define (estimate-integral p x1 x2 y1 y2)
  (define rand-x (random-in-range-stream x1 x2))
  (define rand-y (random-in-range-stream y1 y2))
  (define experiment-stream
    (stream-map (lambda (n m) (p n m x1 x2 y1 y2)) rand-x rand-y))
  (define monte-carlo-stream
    (monte-carlo experiment-stream 0.0 0.0))
  (let ((area (area-size x1 x2 y1 y2)))
    (scale-stream monte-carlo-stream area)))

(show-stream (estimate-integral predicate -1 1 -1 1) 100)
;; gosh>  4.0 4.0 4.0 4.0 4.0 4.0 4.0 4.0 4.0 4.0 4.0 4.0 4.0 4.0 4.0 4.0 4.0 4.0 4.0 4.0 4.0 4.0 4.0 4.0 4.0 4.0 4.0 4.0 4.0 4.0 4.0 4.0 4.0 3.8823529411764706 3.8857142857142857 3.888888888888889 3.891891891891892 3.789473684210526 3.7948717948717947 3.8 3.8048780487804876 3.8095238095238093 3.813953488372093 3.8181818181818183 3.8222222222222224 3.8260869565217392 3.74468085106383 3.75 3.7551020408163267 3.76 3.764705882352941 3.769230769230769 3.7735849056603774 3.7777777777777777 3.7818181818181817 3.7857142857142856 3.789473684210526 3.793103448275862 3.7966101694915255 3.7333333333333334 3.737704918032787 3.7419354838709675 3.746031746031746 3.6875 3.6923076923076925 3.696969696969697 3.701492537313433 3.7058823529411766 3.710144927536232 3.7142857142857144 3.6619718309859155 3.6666666666666665 3.671232876712329 3.6216216216216215 3.6266666666666665 3.6315789473684212 3.6363636363636362 3.58974358974359 3.5443037974683542 3.5 3.506172839506173 3.5121951219512195 3.5180722891566263 3.5238095238095237 3.5294117647058822 3.5348837209302326 3.5402298850574714 3.5454545454545454 3.50561797752809 3.511111111111111 3.5164835164835164 3.4782608695652173 3.4838709677419355 3.4893617021276597 3.4947368421052634 3.5 3.5051546391752577 3.510204081632653 3.515151515151515 3.52
;; pi っぽくなればいいのであっているかも
(stream-ref (estimate-integral predicate -1 1 -1 1) 100000)
;; gosh> 3.138248617513825
;; gosh> 3.150608493915061
;; gosh> 3.137088629113709
;; 収束が微妙・・

