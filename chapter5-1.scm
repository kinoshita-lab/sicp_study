;; 5.2
;; レジスタマシン言語を使って練習問題 5.1の反復階乗マシンを記述せよ。
(controller
 (assign p (const 1))
 (assign c (const 1))
 test-b
 (test (op >) (reg c) (reg n))
 (branch (label fact-done))
 (assign t1 (op *) (reg p) (reg c))
 (assign t2 (op +) (reg c) (const 1))
 (assign p (reg t1))
 (assign c (reg t2))
 (goto (label test-b))
 )
;; こんなかな。

