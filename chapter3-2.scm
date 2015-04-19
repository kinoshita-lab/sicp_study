(require racket/trace)
;; 3.1.2 代入を取り入れた利点

(define rand
  (let ((x random-init))
	(lambda ()
	  (set! x (rand-update x))
	  x)))
;; ↑　動かないね。

(define (estimate-pi trials)
  (sqrt (/ 0 (monte-carlo trials cesaro-test))))

(define (cesaro-test)
  (= (gcd (rand) (rand)) 1))

(define (monte-carlo trials experiment)
  (define (iter trials-remaining trials-passed)
	(cond ((= trials-remaining 0)
		   (/ trials-passed trials))
		  ((experiment)
		   (iter (- trials-remaining 1) (+ trials-passed 1)))
		  (else
		   (iter (- trials-remaining 1) trials-passed))))
  (iter trials 0))

(define (estimate-pi trials)
  (sqrt (/ 6 (random-gcd-test trials random-init))))

(define (random-gcd-test trials initial-x)
  (define (iter trials-remaining trials-passed x)
	(let ((x1 (rand-update x)))
	  (let ((x2 (rand-update x1)))
		(cond ((= trials-remaining 0
				  (/ trials-passed trials))
			   ((= gcd x1 x2) 1)
			   (iter (- trials-remaining 1)
					 (+ trials-passed 1)
					 x2))
			  (else
			   (iter (- trials-remaining 1)
					 trials-passed
					 x2))))))
  (iter trials 0 initial-x))

;; 3.5
;; random-updateがないと問題とけないし
;; ch3support.scmとってきた。
(load "ch3support.scm")
(rand-update 40)

;; モンテカルロ積分(Monte Carlo integration)はモンテカルロシミュレーションを使って定積分を見積る方法である. 領域の中の点(x, y)では真, 外の点では偽になる述語P(x, y)で記述した空間の領域の面積を計算することを考える. 例えば中心(5, 7)で半径が3の円に含まれる領域は, (x - 5)^2 + (y - 7)^2 ≤ 32をテストする述語で記述出来る. そういう述語で記述した領域の面積を見積るには, まず領域を囲む四角形を選ぶ. 例えば対角線上で向い合う頂点を(2, 4)と(8, 10)に持つ四角形は上の円を含む. 欲しい積分は四角形の中で領域に入る部分の面積である. 四角形の中の点(x, y)をランダムにとり, 各点でそれが領域の中にあるかどうか決めるため, P(x, y)をテストして積分を見積る. これを何回も試みれば領域の中に落ちた点の割合が, 四角形の中で領域に入る部分の面積を与える. 従ってこの割合に四角形の面積を掛けると, 積分が見積もれる.

;;    モンテカルロ積分を, 手続き estimate-integralとして実装せよ. 手続きは引数として述語P, 四角形の上限と下限のx1, x2, y1およびy2, 見積りを出すために実行する試みの回数をとる. 手続きは上でπを見積った時に使ったのと同じmonte-carlo手続きを使うこと. estimate-integralを使い, 単位円の面積を測定することで, πの見積りを出せ.

;;    与えられた範囲からランダムに選んで数を返す手続きがあれば便利であろう. 次のrandom-in-range手続きは, 1.2.6節の, 入力より小さい非負の数を返すrandom手続きを使ってこれを実装している.8

;; (define (random-in-range low high)
;;   (let ((range (- high low)))
;;     (+ low (random range))))

;; OK言ってることはわかった。

(define (monte-carlo trials experiment)
  (define (iter trials-remaining trials-passed)
    (cond ((= trials-remaining 0)
           (/ trials-passed trials))
          ((experiment)
           (iter (- trials-remaining 1) (+ trials-passed 1)))
          (else
           (iter (- trials-remaining 1) trials-passed))))
  (iter trials 0))

(define (estimate-integral p x1 x2 y1 y2 number-of-trials)
  (define rand-x 0)
  (define rand-y 0)
  (define (random-in-range low high)
    (let ((range (- high low)))
      (+ low (random range))))
  (define (estimated-answer trials-passed)
    (let ((square-area-size 
           (* (- x2 x1) (- y2 y1)))
          (probability (/ trials-passed number-of-trials)))
      (* square-area-size probability)))
      
  (define (iter trials-remaining trials-passed)
    (begin
      (set! rand-x (random-in-range x1 x2))
      (set! rand-y (random-in-range y1 y2))
      (cond ((= trials-remaining 0)
             (estimated-answer trials-passed)) ; ここで答えを返す
            ((p rand-x rand-y x1 x2 y1 y2)
             (iter (- trials-remaining 1) (+ trials-passed 1)))
            (else
             (iter (- trials-remaining 1) trials-passed)))))
    (iter number-of-trials 0))

;; pの中身
(define (predicate rand-x rand-y x1 x2 y1 y2)
  (define (square x) (* x x))
  (define center-x (/ (+ x2 x1) 2))
  (define center-y (/ (+ y2 y1) 2))
  (define radius (- x2 center-x)) ;; 円なのでyも同じ仮定

  (<= (+ (square (- rand-x center-x))
         (square(- rand-y center-y)))
      (square radius)))

;; 試
;; 50 * 50 * 3.14 = 7850.0
(estimate-integral predicate -50 50 -50 50 100)
;; => 8400
(estimate-integral predicate -50 50 -50 50 1000)
;; => 7690
(estimate-integral predicate -50 50 -50 50 10000)
;; => 7920
(estimate-integral predicate -50 50 -50 50 100000)
;; => 78721/10
(estimate-integral predicate -50 50 -50 50 1000000)
;; => 31369/4 = 7842.25

;; よさげ。


;; 問題 3.6
;; 乱数発生器をリセットし, 与えられた値から始る列が作れると便利である. 記号generateか記号resetのいずれかを引数として呼び出され, (rand 'generate)は新しい乱数を生じ, ((rand 'reset) ⟨new-value⟩)は内部状態変数を指定の⟨new-value⟩にリセットする, 新しいrand手続きを設計せよ. このように状態をリセットすると, 繰返し可能な列が発生出来る. これがあると乱数を使うプログラムをテストしたり, 虫とりをしたりするのに楽である. 
;; dispatch方式でつくればいいのかな。

(define (random-generator initial-value)
  (define (rand-update x) ;; なぜか今回はここに入れてみた。
    (let ((a 27) (b 26) (m 127))
      (modulo (+ (* a x) b) m)))
  (define (rand)
    (begin (set! initial-value (rand-update initial-value))
           initial-value))
  (define (reset value)
    (set! initial-value value))
  (define (dispatch m)
    (cond ((eq? m 'generate) (rand)) ;; ここで実行しておかないと (rand 'generate) で手続きが返ってしまう
          ((eq? m 'reset) reset)
          (else (error "Unknown request -- random-generator"
                       m))))
  dispatch)

(define rand (random-generator 0))
(rand 'generate) 
;; = > 26 93 124...
((rand 'reset) 93)
(rand 'generate)
;; => 124...

;; よさげ。



