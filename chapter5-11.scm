;; 5.5.7 コンパイル済みコードと評価器の接続
(load "./code_from_text/ch5-eceval-compiler.scm")
(compile-and-go
 '(define (factorial n)
    (if (= n 1)
        1
        (* (factorial (- n 1)) n))))
