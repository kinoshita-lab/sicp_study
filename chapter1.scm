;1.1 
(+ 5 3 4)
(- 9 1)
(/ 6 2)
(+ (* 2 4) (- 4 6))
(define a 3)
(define b (+ a 1))
(= a b)
(if (and (> b a) (< b (* a b)))
      b
      a)
(cond ((= a 4) 6)
        ((= b 4) (+ 6 7 a))
        (else 25))
(+ 2 (if (>b a) b a))

(+ 2 (if (> b a) b a))
(* (cond ((> a b) a)
           ((< a b) b)
           (else -1))
     (+ a 1))

; 1.2
 (/ (+ 5 4 (- 2 (- 3 (+ 6 4/5))))
     (* 3 (- 6 2) (- 2 7)))

> (define (<= x y)
    (not (> x y)))
> (define (bigger-two-numbers-square-sum x y z)
    (if (and (<= x y) (<= x z))
           (+ (* y y) (* z z))
           (if (and (<= y x) (<= y z)) (+ (* x x) (* z z))
               (+ (* x x) (* y y)))))


; 1.3
(bigger-two-numbers-square-sum 1 2 3)
(bigger-two-numbers-square-sum 1 3 2)
(bigger-two-numbers-square-sum 2 1 3)
(bigger-two-numbers-square-sum 2 3 1)
(bigger-two-numbers-square-sum 3 1 2)
(bigger-two-numbers-square-sum 3 2 1)
(bigger-two-numbers-square-sum 1 1 2)
(bigger-two-numbers-square-sum 1 2 1)
(bigger-two-numbers-square-sum 2 1 1)
(bigger-two-numbers-square-sum 1 2 2)
(bigger-two-numbers-square-sum 2 1 2)
(bigger-two-numbers-square-sum 2 2 1)
(bigger-two-numbers-square-sum 2 2 2)

; 1.4
;われわれの評価モデルって何よ？置き換えモデルのこと？

(define (a-plus-abs-b a b))
    ((if (> b 0) + -) a b))
;に対して、

(a-plus-abss-b 1 2)
;を入力したとき、まず(a-plus-abs-b a b)の本体を取り出す。

((if (> b 0) + -) a b))
;次に仮パラメタa, bを引数の1,2で取り替える。

((if (> 2 0) + -) 1 2))
;if内を評価して、

(+ 1 2)
;そして最後に
3

(a-plus-abs-b 1 -2)
;の時には、

((if (> -2 0) + -) 1 -2))
;↓
(- 1 -2)
;↓
3

; 1.5

;作用的順序・・・引数の演算があれば行ってから、演算する
;正規順序・・・分解できるところまで分解して、それから演算する
;ということだよな。

;作用的順序の場合

(test 0 (p))
;(p)を評価して作用させる
(test 0 (p))
;(p)を評価して作用させる
(test 0 (p))
・
・
・
;正規順序の場合

(test 0 (p))
(if (= 0 0)
    0
    (p))
;if　は　帰結式(真の方)を選ぶので、
;結果は
0
;ためしに、自分の処理系(DrScheme)でやってみた。

(define (p) (p))
(define (test x y)
    (if (= x 0)
        0
        y))
(test 0 (p))
. user break
 
;返事が返ってこない。この解釈系が実際に使っているのは、確かに作用的順序の方だ。

;1.6

;new-if　を使うと、これが特殊形式ではないため、作用的順序の解釈系では、

(new-if (good-enough? guess x)
    guess
    (sqrt-iter (improve guess x)
                   x)))
;の部分が

(new-if (#t または #f)
    guess
    (new-if (good-enough? guess x)
     guess
     (sqrt-iter (improve guess x)
                      x))))
;・
;・
;・
;というふうに、 new-ifの代替部が無限に展開されてしまうから。

;1.7

;good-enoughが、 0.001　よりも差が小さくなればよい　としているので、
;小さい数の場合、0.00001　などの平方根を求めようとすると、数値のほうが誤差より小さいため問題になる。
;大きい数の場合、桁が大きすぎて0.001　の部分が表現できていないときに、誤差が0.001以上あっても #t　となってしまう。
;これを回避するためには、変化の割合を good-enoughの評価に使えばいい。 ってことなのかな？

(define (good-enough? guess x)
    (< (abs (- 1 (/ (square guess) x))) 0.001))
;ってやってみた。

(sqrt 98172409382170947810293847109238471098234710)
;9.90820381236501e+021
(sqrt 0.00001)
;0.0031622926477232706


; 1.8
(define (square x)
    (* x x))

(define (cube x)
    (* x x x))

(define (cbrt-iter guess x)
    (if (good-enough? guess x)
        guess
        (cbrt-iter (improve guess x)
                   x)))

(define (improve guess x)
    (/ (+ (/ x (square guess)) (* 2 guess)) 3))

 (define (good-enough? guess x)
    (< (abs (- (cube guess) x)) 0.001))

(define (cbrt x)
    (cbrt-iter 1.0 x))

;1.9
;上のやつ
;; (+ 4 5)
;; (inc (+ 3 5))
;; (inc (inc (+ 2 5)))
;; (inc (inc (inc (+ 1 5))))
;; (inc (inc (inc (inc (+ 0 5)))))
;; (inc (inc (inc (inc  5))))
;; (inc (inc (inc 6)))
;; (inc (inc  7))
;; (inc 8)
;; 9
;下の
;; (+ 4 5)
;; (+ 3 6)
;; (+ 2 7)
;; (+ 1 8)
;; (+ 0 9)
;; 9

;1.10

(define (A x y)
  (cond ((= y 0) 0)
		((= x 0) (* 2 y))
		((= y 1) 2)
		(else (A (- x 1)
				 (A x (- y 1))))))
(A 1 10)
(A 2 4)
(A 3 3)

;(f n) = 2n
;(g n) = 2
;(h n)・・・わからん。 回答みてもわからん。。。困るな。

;1.11
;再帰的
(define (func n)
  (cond ((<= n 3) n)
		(else (+ (func (- n 1))
				 (* 2 (func (- n 2)))
				 (* 3 (func (- n 3)))))))
;反復的
(define (func n)
  (func-iter 2 1 0 n))

(define (func-iter nm1 nm2 nm3 count)
  (if (<= count 3) (+ nm1 (* 2 nm2) (* 3 nm3))
	  (func-iter (+ nm1 (* 2 nm2) (* 3 nm3))
				 nm1 nm2 (- count 1))))

;1.12
;要素を計算　って意味がよくわからなかった。
;(x+y)^n のm項目を求める　というプログラムを作った。
(define (Pascal n m)
  (if (or (= n 0) (= m 1) (= m (+ n 1)))
	  1
	  (+ (Pascal (- n 1) (- m 1))
		 (Pascal (- n 1) m))))
(Pascal 3 2)
(Pascal 4 3) 3 6

;1.13
;; ;tex記法　で書いてみたけど、なんか読みにくいなあ。
;; n=1のとき
;; \frac{\phi^n - \psi^n}{\sqrt{5}} = (\frac{1 + \sqrt{5}}{2} - \frac{1 - \sqrt{5}}{2})/\sqrt{5} = 1 = \text{Fib}(1)

;; n=kのとき
;; \text{Fib}(k) = \frac{\phi^k - \psi^k}{\sqrt{5}} が成立していると仮定
;; 定義より、
;; \text{Fib}(k+1) = \text{Fib}(k) + \text{Fib}(k-1)
;; 仮定より、上式の右辺は、
;; \text{Fib}(k) + \text{Fib}(k-1) = \frac{\phi^k - \psi^k}{\sqrt{5}} + \frac{\phi^{k-1} - \psi^{k-1}}{\sqrt{5}}
;; = \frac{\phi^{k-1}(\phi + 1) - \psi^{k-1}(\psi +1)}{\sqrt{5}}
;; = \frac{\phi^{k-1}(\frac{3+\sqrt{5}}{2}) - \psi^{k-1}(\frac{3-\sqrt{5}}{2}) }{\sqrt{5}}
;; \frac{\phi^{k+1} - \psi^{k+1}}{\sqrt{5}] [tex:\therefore \text{Fib}(k+1) = \frac{\phi^(k+1) - \psi^(k+1)}{\sqrt{5}}
;; 帰納法により \text{Fib}(n) = \frac{\phi^n - \psi^n}{\sqrt{5}} を示した。

;; ところで、 \forall n \in N \psi^n < 0.5]は明らか。
;; ゆえに、\text{Fib}(n)は、\frac{\phi^n}{\sqrt{5}}に最も近い整数である。
;; Quod Erat Demonstrandum

; 1.14
;木構造の再帰的な計算なので、O(n^2)ステップと、O(n)のスペースを必要とする。


; 1.15
;; a.
;; 12.5 / 3.0 = 4.166...
;; なので、5回。

;; b.
;; スペースとステップ数は、どちらも　ceil(a)回。
;; ・・・かな。


;;;; ここから先ロスト！ あらためてやる


;;; memo
とりあえず．込み入ったlambdaを置き換えモデルで考えるのが難しかった（ということは1章を確実に把握できてないのかも)

substitution model で考えようとしてみる．

(define one (add-1 zero))
↓
(add-1 (lambda (f) (lambda (x) x)))
↓
(lambda (f) (lambda (x) (f (((lambda (f) (lambda (x) x))) f) x)))
;・・・すいません無理！！！ lambdaヨクワカリマセン・・・ってなって，色々調べてみた．
;結局わからなかったのは
;これ↓の意味．
(define zero
  (lambda (f) (lambda (x) x)))
;あってるのか知らないけどとりあえず自分の理解した範囲ではこんなことになってた．

(lambda (x) x) 
;の部分は，前に出てきたidentityと同じ意味だよな．
;これ↓．

(define identity
  (lambda (x) x))
;じゃあzeroは，

(define zero
  (lambda (f) x))
;って書いてもいいんじゃないの？

;zeroという関数は「関数ｆがなんだか知らないけど，とにかくxを返す関数」だと思っておけばいいのかな．
;これをadd-1に入れると出てくるのは，きっと１なんだろう．

(add-1 zero)
;↓
(lambda (f) (lambda (x) (f ((zero f) x))))
;↓ ((zero f) x)はとにかくxを返す関数なので，
(lambda (f) (lambda (x) (f x)))
;なんだかわからない関数fをxに1回適用した値を返すってことか．
;もう一回add-1するとどうなるか？

(add-1 one)
;↓
(lambda (f) (lambda (x) (f
               ((one f) x)
               )))
;↓　((one f) x)は 関数fをxに1回適用した値を返すので，
(lambda (f) (lambda (x) (f (f x))))
;結局，fをn回適用するってのが数の定義ってことになった．
;＋を定義するのはこわかったのでこうした．
(define (plus a b)
  (lambda (f) (lambda (x)
           ((a f) (b f) x))))
;これは，すでにfをa回適用して，b回fを適用する関数を返す関数
