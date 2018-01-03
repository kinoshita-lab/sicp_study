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

;; 5.47
;;;; (3) support for compiled code to call interpreted code (exercise 5.47) --
;;;;     (new register and 1 new instruction at start)
;; もうやってあるやつかこれ ー> ecevalのとこだけやってあった
;; compile-procedure-callとかはcompilerの方だった
;; この段階でどうなるか？ をためした。
(load "./code_from_text/ch5-eceval-compiler.scm")
;; コードをテストするには、まず手続き g を呼ぶ手続き f を定義する。
;; はい。
(compile-and-go
 '(define (f x)
  (g x)))
;; (total-pushes = 0 maximum-depth = 0)
;;; EC-Eval value:
;; ok

;;; EC-Eval input:
(define (g x) x)

;; (total-pushes = 3 maximum-depth = 3)
;; ;;; EC-Eval value:
;; ok
;;; EC-Eval input:
;; (f 1)
;; *** ERROR: pair required, but got x
;; 0  (cdr inst)
;;       at "./code_from_text/ch5-regsim-orig.scm":212
;; 1  (instruction-execution-proc (car insts))
;;       at "./code_from_text/ch5-regsim-orig.scm":139
;; 2  ((instruction-execution-proc (car insts)))
;;       at "./code_from_text/ch5-regsim-orig.scm":139
;; 3  (eval expr env)
;;       at "/usr/share/gauche-0.9/0.9.6_pre2/lib/gauche/interactive.scm":284
;; だめだったということやな。
;; エラーがregsimの方で出てるのはなぜだろう。コンパイル結果が欲しいやつじゃなかったということだな。
;; compile-procedure-callはいつ呼ばれてるかというとcompile-and-goのとき。
(load "./code_from_text/ch5-eceval-compiler.scm") ;; ロードしといて
;; うわがき。
(define (compile-procedure-call target linkage)
  (let ((primitive-branch (make-label 'primitive-branch))
        (compiled-branch (make-label 'compiled-branch))
        (compound-branch (make-label 'compound-branch)) ;; これ足した
        (after-call (make-label 'after-call)))
    (let ((compiled-linkage
           (if (eq? linkage 'next) after-call linkage)))
      (append-instruction-sequences
       (make-instruction-sequence '(proc) '()
                                  `((test (op primitive-procedure?) (reg proc))
                                    (branch (label ,primitive-branch))
                                    (test (op compound-procedure?) (reg proc)) ;; これ足した
                                    (branch (label ,compound-branch))))         ;; これ足した
       (parallel-instruction-sequences
        (parallel-instruction-sequences             ;; これ必要だった
         (append-instruction-sequences
          compound-branch                                          ;; これ足した
          (compile-compound-proc-appl target compiled-linkage))    ;; これ足した
         (append-instruction-sequences
          compiled-branch
          (compile-proc-appl target compiled-linkage)))
        (append-instruction-sequences
         primitive-branch
         (end-with-linkage linkage
                           (make-instruction-sequence '(proc argl)
                                                      (list target)
                                                      `((assign ,target
                                                                (op apply-primitive-procedure)
                                                                (reg proc)
                                                                (reg argl))))))) 
                                  after-call))))
  
;; compile-compound-proc-applをこさえる 謎だったのでこちらまるごと参考にした
;; http://wat-aro.hatenablog.com/entry/2016/02/10/173919
(define (compile-compound-proc-appl target linkage)
  (cond ((and (eq? target 'val) (not (eq? linkage 'return)))
         (make-instruction-sequence
          '() all-regs
          `((assign continue (label ,linkage))
            (save continue)
            (goto (reg compapp)))))
        ((and (not (eq? target 'val))
              (not (eq? linkage 'return)))
         (let ((proc-return (make-label 'proc-return)))
           (make-instruction-sequence
            '(proc) all-regs
            `((assign continue (label ,proc-return))
              (save continue)
              (goto (reg compapp))
              ,proc-return
              (assign ,target (reg val))
              (goto (label ,linkage))))))
        ((and (eq? target 'val) (eq? linkage 'return))
         (make-instruction-sequence
          '(proc continue) all-regs
          `((save continue)
            (goto (reg compapp)))))
        ((and (not (eq? target 'val)) (eq? linkage 'return))
         (error "return linkage, target not val -- COMPILE" target))))

;; 試
(compile-and-go
 '(define (f x)
  (g x)))
;; (total-pushes = 0 maximum-depth = 0)
;;; EC-Eval value:
;; ok

;;; EC-Eval input:
(define (g x) x)

;; (total-pushes = 3 maximum-depth = 3)
;; ;;; EC-Eval value:
;; ok
;;; EC-Eval input:
;; (f 1)
;;; EC-Eval value:
1
