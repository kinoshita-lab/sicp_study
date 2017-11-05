;; 評価器のパフォーマンス監視
;; ecevalを元にもどした。
;; スタックの深さ表示は実装済みだった。
(load "./code_from_text/load-eceval.scm")
(start eceval)
(define (factorial n)
  (if (= n 1) 1 (* (factorial (- n 1)) n)))
;; (total-pushes = 3 maximum-depth = 3)

(factorial 5)
;; (total-pushes = 144 maximum-depth = 28)

;; 5.26
(define (factorial n)
  (define (iter product counter )
    (if (> counter n)
        product
        (iter (* counter product ) (+ counter 1))))
  (iter 1 1))
(factorial 1)
;; (total-pushes = 64 maximum-depth = 10)
(factorial 2)
;; (total-pushes = 99 maximum-depth = 10)
(factorial 3)
;; (total-pushes = 134 maximum-depth = 10)
(factorial 4)
;; (total-pushes = 169 maximum-depth = 10)

;; a. maximum-depthは10
;; b. 4のときと3のときの差 35
;; 3のときと2のときの差 35
;; n = 1のときのpush 64
;; push(n) = 64 + 35 * (n - 1)
;; かな。

;; 5.27 普通の再帰版
(define (factorial n)
  (if (= n 1) 1 (* (factorial (- n 1)) n)))
;; (total-pushes = 3 maximum-depth = 3)

(factorial 1)
;; (total-pushes = 16 maximum-depth = 8)
(factorial 2)
;; (total-pushes = 48 maximum-depth = 13)
(factorial 3)
;; (total-pushes = 80 maximum-depth = 18)
(factorial 4)
;; (total-pushes = 112 maximum-depth = 23)

;; push(n) = 16 + 32 * (n - 1)
;; max(n) = 8 + 5 * (n - 1)

;; 5.28 ev-sequenceを末尾再帰しない形にする
(load "./code_from_text/load-eceval.scm")
(start eceval)

;; 末尾再帰しない版(だったはずのもの)
(define (factorial n)
  (define (iter product counter )
    (if (> counter n)
        product
        (iter (* counter product ) (+ counter 1))))
  (iter 1 1))
;; (total-pushes = 3 maximum-depth = 3)
(factorial 1)
;; (total-pushes = 70 maximum-depth = 17)
(factorial 2)
;; (total-pushes = 107 maximum-depth = 20)
(factorial 3)
;;(total-pushes = 144 maximum-depth = 23)
(factorial 4)
;; (total-pushes = 181 maximum-depth = 26)
;; push(n) = 70 + (n - 1) * 37
;; max(n) = 17 + (n - 1) * 3
;; maxが増えた
;; 再帰版
(define (factorial n)
  (if (= n 1) 1 (* (factorial (- n 1)) n)))

(factorial 1)
;; (total-pushes = 18 maximum-depth = 11)
(factorial 2)
;; (total-pushes = 52 maximum-depth = 19)
(factorial 3)
;; (total-pushes = 86 maximum-depth = 27)
(factorial 4)
;; (total-pushes = 120 maximum-depth = 35)
;; push(n) = 18 + 34 * (n - 1)
;; max(n) = 11 + 8 * (n - 1)

