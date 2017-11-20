(load "./code_from_text/ch5-compiler.scm")

(use slib)
(require 'pretty-print)
(define pp pretty-print)
;; 5.33
(pp (compile
 '(define (factorial-alt n)
    (if (= n 1)
        (* n (factorial (- n 1))))) ;; ここのかけざんの順番が違う
 'val
 'next))

;; original
(pp (compile
     '(define (factorial n)
        (if (= n 1)
            1
            (* (factorial (- n 1)) n)))
     'val
     'next ))

;; compileのたびにラベルの番号が増えてdiffがとりづらいんじゃ!
;; ってことでちょい改造
;; diffとってみた
@@ -53,6 +53,9 @@
   (test (op false?) (reg val))
   (branch (label false-branch2))
   true-branch1
+  (assign val (const 1))
+  (goto (reg continue))
+  false-branch2
   (assign
     proc
     (op lookup-variable-value)
@@ -60,7 +63,13 @@
     (reg env))
   (save continue)
   (save proc)
-  (save env)
+  (assign
+    val
+    (op lookup-variable-value)
+    (const n)
+    (reg env))
+  (assign argl (op list) (reg val))
+  (save argl)
   (assign
     proc
     (op lookup-variable-value)
@@ -114,44 +123,31 @@
     (reg proc)
     (reg argl))
   after-call6
-  (assign argl (op list) (reg val))
-  (restore env)
-  (assign
-    val
-    (op lookup-variable-value)
-    (const n)
-    (reg env))
+  (restore argl)
   (assign argl (op cons) (reg val) (reg argl))
   (restore proc)
   (restore continue)
   (test (op primitive-procedure?) (reg proc))
-  (branch (label primitive-branch7))
-  compiled-branch8
+  (branch (label primitive-branch1))
+  compiled-branch2
   (assign
     val
     (op compiled-procedure-entry)
     (reg proc))
   (goto (reg val))
-  primitive-branch7
+  primitive-branch1
   (assign
     val
     (op apply-primitive-procedure)
     (reg proc)
     (reg argl))
   (goto (reg continue))
-  after-call9
-  false-branch2
-  (assign
-    val
-    (op lookup-variable-value)
-    (const false)
-    (reg env))
-  (goto (reg continue))
+  after-call3
   after-if3
   after-lambda2
   (perform
     (op define-variable!)
-    (const factorial-alt)
+    (const factorial)
     (reg val)
     (reg env))
   (assign val (const ok))))

;; すぐわかるのは nを入れるタイミングが違うってのだけど、他にもありそう。
;; false-branch2に相当するものが増えた
;; このへん
;; -  false-branch2
;; -  (assign
;; -    val
;; -    (op lookup-variable-value)
;; -    (const false)
;; -    (reg env))
;; -  (goto (reg continue))
;; ので、実行効率だと factorialの方がよさそう

;; 5.34
;; カウンターのリセットのしかたがマズかった。複合手続きのコンパイルがgdgdになってしまった。
;; 別の手続きにした。
(reset-counter!)
(pp (compile 
     '(define (factorial n)
       (define (iter product counter)
         (if (> counter n)
             product
             (iter (* counter product)
                   (+ counter 1))))
       (iter 1 1))
     'val
     'next))
                                               ;; ↓こうなった
((env)
  (val)                                                                          
  ((assign                                                      ;; ↓
     val                                                        ;;   
     (op make-compiled-procedure)                               ;;  entry1から先のlambda式をコンパイルしてvalに入れて
     (label entry1)                                             ;;  after-lambda2へ飛ぶ(すごい下)
     (reg env))                                                 ;;      
   (goto (label after-lambda2))                                 ;; ↑
   entry1                                                       ;; ← ここから本体がはじまる
   (assign                                                      ;; ↓
     env                                                        ;;
     (op compiled-procedure-env)                                ;;  lambda式の中身をenvに入れる(違うかも)
     (reg proc))                                                ;; ↑  
   (assign                                                      ;; ↓
     env                                                        ;;
     (op extend-environment)                                    ;;
     (const (n))                                                ;;  引数を環境に追加
     (reg argl)                                                 ;;
     (reg env))                                                 ;; ↑
   (assign                                                      ;; ↓
     val                                                        ;; 
     (op make-compiled-procedure)                               ;;
     (label entry3)                                           ;;  entry3から先のlambda式(iterの中身)をコンパイルしてvalに入れて
     (reg env))                                               ;;  after-lambda4へ飛ぶ
   (goto (label after-lambda4))                               ;; ↑
   entry3                                                     ;; ↓
   (assign                                                    ;; 
     env                                                      ;; lambda式の中身をenvに入れる(違うかも)
     (op compiled-procedure-env)                              ;; 
     (reg proc))                                              ;; ↑
   (assign                                                    ;; ↓ 
     env                                                      ;; 
     (op extend-environment)                                  ;; 
     (const (product counter))                                ;; 引数をenvに追加
     (reg argl)                                               ;; 
     (reg env))                                               ;; ↑
   (save continue)                                             ;; ← iterの本体開始 
   (save env)                                                  ;;  
   (assign                                                     ;; ↓
     proc                                                      ;; 
     (op lookup-variable-value)                                ;; > を探してきてprocに入れる
     (const >)                                                 ;; 
     (reg env))                                                ;; ↑
   (assign                                                     ;; ↓
     val                                                       ;; nの値をさがしてきてvalに入れる 
     (op lookup-variable-value)                                ;; 
     (const n)                                                 ;; 
     (reg env))                                                ;; ↑
   (assign argl (op list) (reg val))                           ;; ← arglに valの中身(nの値) を入れる
   (assign                                                     ;; ↓
     val                                                       ;; 
     (op lookup-variable-value)                                ;; counterの値をさがしてきてvalに入れる
     (const counter)                                           ;; 
     (reg env))                                                ;; ↑
   (assign argl (op cons) (reg val) (reg argl))                ;; ← arglにcounterの値もついか (counter n) みたいになる
   (test (op primitive-procedure?) (reg proc))                 ;; ↓
   (branch (label primitive-branch8))                          ;; ↑ > はprimitive? ならprimitive-branch8へ
   compiled-branch9                                            ;; ↓
   (assign continue (label after-call10))                      ;; 
   (assign                                                     ;; 
     val                                                       ;; 呼ばれない地帯
     (op compiled-procedure-entry)                             ;; 
     (reg proc))                                               ;; 
   (goto (reg val))                                            ;; ↑
   primitive-branch8                                           ;; ↓
   (assign                                                     ;; 
     val                                                       ;; 
     (op apply-primitive-procedure)                            ;;  (> counter n) を実行
     (reg proc)                                                ;; 
     (reg argl))                                               ;; 
   after-call10                                                ;; ↓
   (restore env)                                               ;;
   (restore continue)                                          ;; ifの判定後のジャンプ先
   (test (op false?) (reg val))                                ;; 
   (branch (label false-branch6))                              ;; 
   true-branch5                                                ;; ↑
   (assign                                                     ;; ↓
     val                                                       ;;
     (op lookup-variable-value)                                ;; 計算結果をvalに入れて終了
     (const product)                                           ;;
     (reg env))                                                ;;
   (goto (reg continue))                                       ;; ↑
   false-branch6                                               ;; ↓
   (assign                                                     ;; 
     proc                                                      ;;
     (op lookup-variable-value)                                ;; iterを探してきてprocに入れる
     (const iter)                                              ;;
     (reg env))                                                ;; ↑
   (save continue)                                             ;; ↓
   (save proc)                                                 ;;  iterの入ってるprocをstackに積む
   (save env)                                                  ;; ↑
   (assign                                                     ;; ↓
     proc                                                      ;;
     (op lookup-variable-value)                                ;;  + を 探してきてprocに入れる
     (const +)                                                 ;;
     (reg env))                                                ;; ↑
   (assign val (const 1))                                      ;; ← 1 をvalに入れる
   (assign argl (op list) (reg val))                           ;; ← arglにvalを入れる(1が入った) 
   (assign                                                     ;; ↓
     val                                                       ;;
     (op lookup-variable-value)                                ;;  counterの値を探してきてvalに入れる
     (const counter)                                           ;;
     (reg env))                                                ;; ↑
   (assign argl (op cons) (reg val) (reg argl))                ;; arglにcounterの値をconsる (counter 1) みたいになる
   (test (op primitive-procedure?) (reg proc))                 ;; primitive? + がはいってる
   (branch (label primitive-branch14))                         ;; + なのでここでbranch
   compiled-branch15                                           ;; ↓
   (assign continue (label after-call16))                      ;;
   (assign                                                     ;;
     val                                                       ;;  compiledではないゆえにこのへんは使われてない
     (op compiled-procedure-entry)                             ;;
     (reg proc))                                               ;;
   (goto (reg val))                                            ;; ↑
   primitive-branch14                                          ;; ↓
   (assign                                                     ;; 
     val                                                       ;;  (+ counter 1) を計算して valに入れる
     (op apply-primitive-procedure)                            ;; 
     (reg proc)                                                ;; 
     (reg argl))                                               ;; ↑
   after-call16                                                ;; ↓
   (assign argl (op list) (reg val))                           ;;
   (restore env)                                               ;;  結果をarglに入れてstackにpush 関数からもどってきたのでenvを関数の外に戻す
   (save argl)                                                 ;; ↑
   (assign                                                     ;; ↓ 
     proc                                                      ;; 
     (op lookup-variable-value)                                ;;  * を探してきて procに入れる
     (const *)                                                 ;; 
     (reg env))                                                ;; ↑
   (assign                                                     ;; ↓ 
     val                                                       ;; 
     (op lookup-variable-value)                                ;; productの値を探してきて valに入れる
     (const product)                                           ;; 
     (reg env))                                                ;; ↑
   (assign argl (op list) (reg val))                           ;; valの値をarglにコピー
   (assign                                                     ;; ↓ 
     val                                                       ;; 
     (op lookup-variable-value)                                ;; counterの値を探してきてvalにいれる
     (const counter)                                           ;; 
     (reg env))                                                ;; ↑
   (assign argl (op cons) (reg val) (reg argl))                ;; valに入ってるcounterの値をarglにcons (counter product) が入ってる
   (test (op primitive-procedure?) (reg proc))                 ;; *はprimitive? を判定 
   (branch (label primitive-branch11))                         ;; primitiveなのでここでbranch
   compiled-branch12                                           ;; ↓
   (assign continue (label after-call13))                      ;; 
   (assign                                                     ;; 
     val                                                       ;; 呼ばれない地帯
     (op compiled-procedure-entry)                             ;; 
     (reg proc))                                               ;; 
   (goto (reg val))                                            ;; ↑
   primitive-branch11                                          ;; ↓ 
   (assign                                                     ;; 
     val                                                       ;; (* counter product) をvalに入れる
     (op apply-primitive-procedure)                            ;; 
     (reg proc)                                                ;; 
     (reg argl))                                               ;; ↑
   after-call13                                                ;; 
   (restore argl)                                              ;; arglをpop
   (assign argl (op cons) (reg val) (reg argl))                ;; 今回の結果をcons (* counter product) と、 (+ counter 1) がはいっている
   (restore proc)                                              ;; procを戻す(iterになる)
   (restore continue)                                          ;; continueをpop
   (test (op primitive-procedure?) (reg proc))                 ;; こんかいはiterなのでprimitiveではない
   (branch (label primitive-branch17))                         ;; ので branchしない
   compiled-branch18                                           ;; ↓ 
   (assign                                                     ;; 
     val                                                       ;; iterを呼ぶ
     (op compiled-procedure-entry)                             ;; 
     (reg proc))                                               ;; ↑
   (goto (reg val))                                            ;; valに入ってる値 = iter へジャンプ
   primitive-branch17                                          ;; ↓ 
   (assign                                                     ;; 
     val                                                       ;; 
     (op apply-primitive-procedure)                            ;; 呼ばれない地帯(primitive procedureではないため
     (reg proc)                                                ;; 
     (reg argl))                                               ;; 
   (goto (reg continue))                                       ;; ↑
   after-call19                                                ;;
   after-if7                                                   ;;  
   after-lambda4                                               ;; ↓ 
   (perform                                                    ;; 
     (op define-variable!)                                     ;; 
     (const iter)                                              ;;  valに入ってる手続を envで iter として登録
     (reg val)                                                 ;; 
     (reg env))                                                ;; 
   (assign val (const ok))                                     ;; ↑
   (assign                                                     ;; ↓
     proc                                                      ;; 
     (op lookup-variable-value)                                ;; 
     (const iter)                                              ;; (iter 1 1) をつくるところ
     (reg env))                                                ;; 
   (assign val (const 1))                                      ;; 
   (assign argl (op list) (reg val))                           ;; 
   (assign val (const 1))                                      ;; 
   (assign argl (op cons) (reg val) (reg argl))                ;; ↑ 
   (test (op primitive-procedure?) (reg proc))                 ;; primitiveではないので
   (branch (label primitive-branch20))                         ;; branchしない
   compiled-branch21                                           ;; ↓
   (assign                                                     ;;
     val                                                       ;; iterをvalに入れて
     (op compiled-procedure-entry)                             ;; そこへgotoする
     (reg proc))                                               ;;
   (goto (reg val))                                            ;; ↑
   primitive-branch20                                          ;; ↓  
   (assign                                                     ;; 
     val                                                       ;; 
     (op apply-primitive-procedure)                            ;; 呼ばれない地帯
     (reg proc)                                                ;; 
     (reg argl))                                               ;; 
   (goto (reg continue))                                       ;; ↑ 
   after-call22                                       
   after-lambda2                                               ;; ↓
   (perform                                                    ;; 
     (op define-variable!)                                     ;; 
     (const factorial)                                         ;; valに入っている内容をfactorialとしてenvに追加
     (reg val)                                                 ;; 
     (reg env))                                                ;; 
   (assign val (const ok))))                                   ;; ↑

;; 全部注釈つけた(つかれた)
;; 図 5.17: ↓ factorial 手続き定義のコンパイル結果 ってのがあるけどこれはどっちのだ？ 再帰版っぽい
;; ↑のiter版ではstackのpush/popが (> counter n) と (* counter product) (+ counter 1)のところでしかおこってないので単純なloopになってる
;; 本質的な違いってくらいだから再帰版で save continueがどんどん増えるところを発見すればよさそう
;; ここだ↓
;; * のもうひとつの引数である (factorial (- n 1)) を計算
;; (assign proc
;; (op lookup-variable-value )
;; (const factorial) ;; ここ
;; (reg env))
;; (save proc) ; factorial 手続きを保存
;; 再帰のときにはprocに自分自身をsaveして自分を呼ぶコードがでてきた。
;; iterも自分を呼んでるけどどうしてsaveしないコードがでてくるのかな。
;; ていうのが 「コンパイル済み手続きの適用」の所に書いてあるのか。
;; この return リンクの実装で、コンパイラは末尾再帰のコードを生成します。手
;; 続きの本体の最後のステップとして手続き呼び出しを行うと、スタックに何の
;; 情報も保存せず、直接移動を行うことになります。
