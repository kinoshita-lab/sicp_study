;; 5.5.7 コンパイル済みコードと評価器の接続
(load "./code_from_text/ch5-eceval-compiler.scm")
(compile-and-go
 '(define (factorial n)
    (if (= n 1)
        1
        (* (factorial (- n 1)) n))))
;; 5.45
;; --------------------------
;; 5.27ではこんな感じだった。
;; (define (factorial n)
;;   (if (= n 1) 1 (* (factorial (- n 1)) n)))
;; ;; (total-pushes = 3 maximum-depth = 3)
;; (factorial 1)
;; ;; (total-pushes = 16 maximum-depth = 8)
;; (factorial 2)
;; ;; (total-pushes = 48 maximum-depth = 13)
;; (factorial 3)
;; ;; (total-pushes = 80 maximum-depth = 18)
;; (factorial 4)
;; ;; (total-pushes = 112 maximum-depth = 23)
;; ;; push(n) = 16 + 32 * (n - 1)
;; ;; max(n) = 8 + 5 * (n - 1)
;; --------------------------
;; ラッキーなことに(？) code_from_textの eceval-compilerはstackのpushとmaxを表示してくれる。
;; 同じように実行して試してみる。
;; eceval-compilerでの実行結果
;; (factorial 1)
;; (total-pushes = 7 maximum-depth = 3)

;; (factorial 2)
;; (total-pushes = 13 maximum-depth = 5)

;; (factorial 3)
;; (total-pushes = 19 maximum-depth = 8)

;; (factorial 4)
;; (total-pushes = 25 maximum-depth = 11)

;; (factorial 5)
;; (total-pushes = 31 maximum-depth = 14)
push(n) = 7 + 6 * (n - 1)
max(n) = 3                  (n=1のとき)
max(n) = 5 + 3 * (n-2)      (n >= 2)



pushのほう

 lim        7 +  6(n - 1)
          ----------------   = 3/16       
n->inf     16 + 32(n - 1)

maxのほう

 lim        5 +  3(n - 2)
          ----------------   = 3/5
n->inf      8 +  5(n - 1)

というかんじになった。
コンパイラすげー。

;; b
;; 言ってることがよくわかんないし、そうする必要はまったくないのだけど、
;; 最適化してるとこをなくせばいいんだよね。
;; これまでやってきたことを全部なくせばいいのではないか。
;; 全部のレジスタを退避
;; 毎回stackを使いまくる
;; というのをlinkageにかかわらずやる
;; open codeとかもなし
;; ってやったらものすごく重いコンパイル結果が出るとおもう。

;; 5.46
;; fibもやるのね。
;; 5.29のときはこんなでした
;; (fib 2)
;; (total-pushes = 72 maximum-depth = 13)
;; (fib 3)
;; (total-pushes = 128 maximum-depth = 18)
;; (fib 4)
;; (total-pushes = 240 maximum-depth = 23)
;; (fib 5)
;; (total-pushes = 408 maximum-depth = 28)
;; a. max(n) = 13 + 5 * (n - 1)
;; b.
;; total(n) = total(n - 1) + total(n - 2) + k
;; n = 5 の場合だと、
;; total(5) = total(4) + total(3) + k
;; 408 = 240 + 128 + k
;; k = 40
;; n = 6で試してみる
;; (fib 6)
;; (total-pushes = 688 maximum-depth = 33)
;; 408 + 240 + 40 = 688
;; 肝心なとこ拾ってくると
;; a. max(n) = 13 + 5 * (n - 1)
;; b. total(n) = total(n - 1) + total(n - 2) + 40
(load "./code_from_text/ch5-eceval-compiler.scm")
(compile-and-go
 '(define (fib n)
  (if (< n 2)
      n
      (+ (fib (- n 1)) (fib (- n 2))))))

;; (fib 0) -> (total-pushes =   7 maximum-depth =  3)
;; (fib 1) -> (total-pushes =   7 maximum-depth =  3)
;; (fib 2) -> (total-pushes =  17 maximum-depth =  5)
;; (fib 3) -> (total-pushes =  27 maximum-depth =  8)
;; (fib 4) -> (total-pushes =  47 maximum-depth = 11)
;; (fib 5) -> (total-pushes =  77 maximum-depth = 14)
;; (fib 6) -> (total-pushes = 127 maximum-depth = 17)
;; (fib 7) -> (total-pushes = 207 maximum-depth = 20)
;; push n >= 2のとき push - 7は
;; 10 20 30 50 80... ;; fibだ
push(n) = push(n-1) + push(n-2) + 7 ;; これは線形にならない
max(n) = 5 + 3 * (n - 2)

