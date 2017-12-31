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
