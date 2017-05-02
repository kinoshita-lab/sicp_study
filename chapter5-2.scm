;; 5.2 レジスタマシンシミュレータ
;; これは実物があるっぽいので入れといた。

(load "./code_from_text/ch5-regsim.scm")

(define gcd-machine
  (make-machine
   '(a b t)
   (list (list 'rem remainder ) (list '= =))
   '(test-b (test (op =) (reg b) ( const 0))
			(branch (label gcd-done))
			(assign t (op rem) (reg a) (reg b))
			(assign a (reg b))
			(assign b (reg t))
			(goto (label test-b ))
			gcd-done)))
(set-register-contents! gcd-machine 'a 206)
(set-register-contents! gcd-machine 'b 40)
(start gcd-machine)
(get-register-contents gcd-machine 'a)
;; gosh> 2
;; おお動いた!


;; 5.7
(define recurcive-expt
  (make-machine
   '(b n continue val)
   (list (list '* *) (list '= =) (list '- -))
   '((assign continue (label expt-done)) 
	 expt-loop
	 (test (op =) (reg n) (const 0))
	 (branch (label base-case))
	 (save continue)
	 (save n)
	 (assign n (op -) (reg n) (const 1))
	 (assign continue (label after-expt))
	 (goto (label expt-loop))
	 after-expt
	 (restore n)
	 (restore continue)
	 (assign val (op *) (reg b) (reg val)) 
	 (goto (reg continue))
	 base-case
	 (assign val (const 1))
	 (goto (reg continue))
	 expt-done)))
(set-register-contents! recurcive-expt 'b 2)
(set-register-contents! recurcive-expt 'n 10)
(start recurcive-expt)
(get-register-contents recurcive-expt 'val)
;; gosh> 1024

(define expt-iter-machine
  (make-machine
   '(b counter product)
   (list (list '* *) (list '= =) (list '- -))
   '(
	 (assign product (const 1))
	 expt-iter-loop
	 (test (op =) (reg counter) (const 0))
	 (branch (label expt-done))
	 (assign product (op *) (reg b) (reg product))
	 (assign counter (op -) (reg counter) (const 1))
	(goto (label expt-iter-loop))
	expt-done
	)))
(set-register-contents! expt-iter-machine 'b 2)
(set-register-contents! expt-iter-machine 'counter 10)
(start expt-iter-machine)
(get-register-contents expt-iter-machine 'product)
;; gosh> 1024

;; 5.8
;; 適当なmachineを作って、まわしてから考えるとわかりやすいかも。

(define ex58-machine
  (make-machine
   '(a)
   '()
   '(
	 start
	 (goto (label here))
	 here
	 (assign a (const 3))
	 (goto (label there))
	 where
	 (assign a (const 4))
	 (goto (label there))
	 there
	)))

(start ex58-machine)
(get-register-contents ex58-machine 'a) ;; 3だった
;; どこかの時点でラベルが複数あることを検出すればいい気がするがcpsで大変わかりづらい。
;; labelsに入ってるっぽい
;; ((here ((assign a (const 3))) ((goto (label there))) ((assign a (const 4))) ((goto (label there)))) (here ((assign a (const 4))) ((goto (label there)))) (there))
;; のでこんなかんじにした。
(define (extract-labels text receive)
  (if (null? text)
      (receive '() '())
      (extract-labels (cdr text)
       (lambda (insts labels)
         (let ((next-inst (car text)))
           (if (symbol? next-inst) ;; ここがlabelの時来るところ
			   (begin
				 (if (assoc next-inst labels) ;; labelは頭についてるのでそこひっかけて
					 (error "duplicate label name" next-inst) ;; かぶってたらerror
					 (receive insts
						 (cons (make-label-entry next-inst
												 insts)
							   labels))))
               (receive (cons (make-instruction next-inst)
                              insts)
				   labels)))))))


;; 5.9 本当にそうなの？ ってことで 5.8のmachineでためしてみる。
(define ex59-machine
  (make-machine
   '(a)
   (list (list '= =)) ;; これ足してみた
   '(
	 start
	 (goto (label here))
	 here
	 (assign a (const 3))
	 (test (op =) (label here) (label here)) ;; これ足してみた
	 (goto (label there))
	 where
	 (assign a (const 4))
	 (goto (label there))
	 there
	)))
;; > ex59-machine
;; できた。↑を作るときにミスったのでcall stack見えた
;;  1  (make-operation-exp condition machine labels operations)
;;        at "./code_from_text/ch5-regsim.scm":279。
(define (make-operation-exp exp machine labels operations)
  (let ((op (lookup-prim (operation-exp-op exp) operations))
        (aprocs
         (map (lambda (e)
				(if (label-exp? e)
					(error "cannot perform label operation!") ;; 5.9で足した
					(make-primitive-exp e machine labels)))
              (operation-exp-operands exp))))
    (lambda ()
      (apply op (map (lambda (p) (p)) aprocs)))))
;; こうやってから実行すると
;; gosh> *** ERROR: cannot perform label operation!

;; 5.10
;; 構文って何よ？
;; make-execution-procedureで定義してるやつだとおもう
;; レジスタの0クリアでもつくってみるか ってことで実装の方をいじった。
(define ex510-machine
  (make-machine
   '(a)
   (list (list '= =)) ;; これ足してみた
   '(
	 start
	 (assign a (const 3))
	 (clear a)
	 there
	)))
(start ex510-machine)
(get-register-contents ex510-machine 'a)
;; 0だった

;; 5.11
;; fib machineつくる
(load "./code_from_text/ch5-regsim.scm")
(define ex511-fib-machine
  (make-machine
   '(n continue val)
   (list (list '< <) (list '- -) (list '+ +))
   '(
	  (assign continue (label fib-done))
	  fib-loop
	  (test (op <) (reg n) (const 2))
	  (branch (label immediate-answer))
	  ;; Fib(n − 1) を求める準備
	  (save continue)
	  (assign continue (label afterfib-n-1))
	  (save n) 										; n の古い値を保存
	  (assign n (op -) (reg n) (const 1)) ; n を n-1 で上書き
	  (goto (label fib-loop )) ; 再帰呼び出しの実行
	  afterfib-n-1 										; リターン時に Fib(n − 1) は val に入っている
	  (restore n)
	  (restore continue )
	  ;; Fib(n − 2) を求める準備
	  (assign n (op -) (reg n) (const 2))
	  (save continue )
	  (assign continue (label afterfib-n-2 ))
	  (save val) 									; Fib(n − 1) を保存
	  (goto (label fib-loop))
	  afterfib-n-2				; リターン時に Fib(n − 2) は val に入っている
	  (assign n (reg val)) 		; n には Fib(n − 2) が入る
	  (restore val) 			; val には Fib(n − 1) が入る
	  (restore continue)
	  (assign val ; Fib(n − 1) + Fib(n − 2)
			  (op +) (reg val) (reg n))
	  (goto (reg continue)) 										; 呼び出し元に戻る、答えはval の中
	  immediate-answer
	  (assign val (reg n)) 										; 基底の場合: Fib(n) = n
	  (goto (reg continue))
	  fib-done)))
(set-register-contents! ex511-fib-machine 'n 10)
(start ex511-fib-machine)
(get-register-contents ex511-fib-machine 'n)
; 21
;; afterfib-n-2				; リターン時に Fib(n − 2) は val に入っている
;; (assign n (reg val)) 		; n には Fib(n − 2) が入る
;; (restore val) 			; val には Fib(n − 1) が入る
;; ↓
;; afterfib-n-2 ; リターン時に Fib(n − 2) は val に入っている
;; (restore n) ;; nにはFib (n-1) が入る
;; ので下の計算が正しくできる。
;;	  (assign val ; Fib(n − 1) + Fib(n − 2) 
;;			  (op +) (reg val) (reg n))


;; b
;; stackそのものは変えなくてよさそうで、 make-save, make-restoreでpairを入れればよさげ。
(load "./code_from_text/ch5-regsim.scm")
;; loadしたあとで make-saveとmake-restoreを上書き 
(define (make-save inst machine stack pc)
  (let ((reg (get-register machine
                           (stack-inst-reg-name inst)))
        (regname (stack-inst-reg-name inst))) ;; これ増えた
    (lambda ()
      (push stack (cons (get-contents reg) regname)) ;; consったpair的なものを入れる
      (advance-pc pc))))

(define (make-restore inst machine stack pc)
  (let ((reg (get-register machine
                           (stack-inst-reg-name inst)))
        (regname (stack-inst-reg-name inst)))
    (lambda ()
      (let* ((popped-pair (pop stack))
             (popped-regname (cdr popped-pair))) ;; 名前ひろってきて
        (if (equal? regname popped-regname) ;; 同じかチェック
            (begin                          ;; 同じならrestore
              (set-contents! reg (car popped-pair))
              (advance-pc pc))
            (error "different reg pop")))))) ;; 違ったらerror

;; 試
(define ex511b-machine
  (make-machine
   '(a b)
   '()
   '(
	 start
	 (save a)
     (save b)
     (restore a) ;; エラー
	)))
(start ex511b-machine)
;;  (display "make-restore!")

;; c
;; 問題の意味がイマイチよくわからないけど、reg毎にstackを別にしろってことなのかな。
;; おおごとになったので別
(load "./ch5_511c.scm")

(define ex511c-machine
  (make-machine
   '(a b)
   '()
   '(
	 start
	 (save a)
     (save b)
     (restore a) ;; エラーにならずにaのstackからpop
	)))
(start ex511c-machine)

;; 5.12
;; 全命令のリスト。重複を削除し、命令の型 (assign, goto 等)によってソートしたもの。
;; これも別ファイルにしたほうが確実だよなあ。ってことでそうした。
;; やったこと
;; the-instruction-sequenceってのに必要そうなのが入ってて
;; (((save a) . #<closure ((make-save make-save))>) ((save b) . #<closure ((make-save make-save))>) ((restore a) . #<closure ((make-restore make-restore))>))
;; (define tmp1 (map (lambda (op) (car op)) (ex512-machine 'instructions)))
;((save a) (save b) (restore a))
;; (define tmp2 (map (lambda (op-and-args) (car op-and-args)) tmp1))
; (save save restore)
;; gaucheの力でuniq
;; (use gauche.sequence)
;; (define (unique-sequence s)
;;   (map car (group-sequence s)))
;; (define tmp3 (unique-sequence tmp2))
; (save restore)
;; gaucheの力でsort
;; (sort tmp3)
; (restore save)

(load "./ch5-5.12.scm")
(define ex512-1-machine
  (make-machine
   '(a b)
   '()
   '(
	 start
	 (save a)
     (save b)
     (restore a) ;; エラーにならずにaのstackからpop
	)))
(ex512-1-machine 'instructions)
; (restore save)

;; エントリポイントを入れるために使われるレジスタの (重複なし) リスト (これらは goto 命令によって参照されるレジスタである)。
;; これもやることはほとんど同じ
;; entry pointがないと試せないのでfibひろってきた
(load "./ch5-5.12.scm")
(define ex512-2-fib-machine
  (make-machine
   '(n continue val)
   (list (list '< <) (list '- -) (list '+ +))
   '(
	  (assign continue (label fib-done))
	  fib-loop
	  (test (op <) (reg n) (const 2))
	  (branch (label immediate-answer))
	  ;; Fib(n − 1) を求める準備
	  (save continue)
	  (assign continue (label afterfib-n-1))
	  (save n) 										; n の古い値を保存
	  (assign n (op -) (reg n) (const 1)) ; n を n-1 で上書き
	  (goto (label fib-loop )) ; 再帰呼び出しの実行
	  afterfib-n-1 										; リターン時に Fib(n − 1) は val に入っている
	  (restore n)
	  (restore continue )
	  ;; Fib(n − 2) を求める準備
	  (assign n (op -) (reg n) (const 2))
	  (save continue )
	  (assign continue (label afterfib-n-2 ))
	  (save val) 									; Fib(n − 1) を保存
	  (goto (label fib-loop))
	  afterfib-n-2				; リターン時に Fib(n − 2) は val に入っている
	  (assign n (reg val)) 		; n には Fib(n − 2) が入る
	  (restore val) 			; val には Fib(n − 1) が入る
	  (restore continue)
	  (assign val ; Fib(n − 1) + Fib(n − 2)
			  (op +) (reg val) (reg n))
	  (goto (reg continue)) 										; 呼び出し元に戻る、答えはval の中
	  immediate-answer
	  (assign val (reg n)) 										; 基底の場合: Fib(n) = n
	  (goto (reg continue))
	  fib-done)))
(ex512-2-fib-machine 'entry-points)
;; (continue) ;; できた

;; それぞれのレジスタに対する代入元の (重複なし) リスト (例えば、図 5.11の階乗マシンでは、レジスタ val の代入元は(const 1) と ((op *) (reg n) (reg val)) である)。
;; ただのlistいじりになってきた ここはassignをひろってくればできるとおもう
(ex512-2-fib-machine 'assigns)
;; ((continue (label afterfib-n-1)) (continue (label afterfib-n-2)) (continue (label fib-done)) (n (op -) (reg n) (const 1)) (n (op -) (reg n) (const 2)) (n (reg val)) (val (op +) (reg val) (reg n)) (val (reg n)))

;; これやってなかった
;; save または restore されるレジスタの (重複なし) リスト。
(ex512-2-fib-machine 'save-restore)
;;  (continue n val)


;; 5.13
;; ↓のerrorの部分でテーブルを更新すればよさげ
;; (define (lookup-register name)
;;        (let ((val (assoc name register-table)))
;;          (if val
;;              (cadr val)
;;              (error "Unknown register:" name))))
(load "./ch5-5.13.scm")
;; fibで。
(define fib-machine
  (make-machine
   (list (list '< <) (list '- -) (list '+ +))
   '(
	  (assign continue (label fib-done))
	  fib-loop
	  (test (op <) (reg n) (const 2))
	  (branch (label immediate-answer))
	  ;; Fib(n − 1) を求める準備
	  (save continue)
	  (assign continue (label afterfib-n-1))
	  (save n) 										; n の古い値を保存
	  (assign n (op -) (reg n) (const 1)) ; n を n-1 で上書き
	  (goto (label fib-loop )) ; 再帰呼び出しの実行
	  afterfib-n-1 										; リターン時に Fib(n − 1) は val に入っている
	  (restore n)
	  (restore continue )
	  ;; Fib(n − 2) を求める準備
	  (assign n (op -) (reg n) (const 2))
	  (save continue )
	  (assign continue (label afterfib-n-2 ))
	  (save val) 									; Fib(n − 1) を保存
	  (goto (label fib-loop))
	  afterfib-n-2				; リターン時に Fib(n − 2) は val に入っている
	  (assign n (reg val)) 		; n には Fib(n − 2) が入る
	  (restore val) 			; val には Fib(n − 1) が入る
	  (restore continue)
	  (assign val ; Fib(n − 1) + Fib(n − 2)
			  (op +) (reg val) (reg n))
	  (goto (reg continue)) 										; 呼び出し元に戻る、答えはval の中
	  immediate-answer
	  (assign val (reg n)) 										; 基底の場合: Fib(n) = n
	  (goto (reg continue))
	  fib-done)))
(set-register-contents! fib-machine 'n 10)
(get-register-contents fib-machine 'n)
(start fib-machine)
(get-register-contents fib-machine 'n)
;; gosh> 21

;; 5.14
;; 小さな n の値について n! の計算に必要となる push の回数とスタ
;; ックの最大の深さを計測せよ。そのデータから、任意の n > 1 に
;; ついて、n! を計算するのに使われる push 演算の総数とスタック
;; の最大の深さを表す n の方程式を決定せよ。
;; 
;; regsimにはstackの拡張が組み込まれてるのでそれ使う。
(load "./code_from_text/ch5-regsim.scm")
;; fact machineつくる
(define fact-machine
  (make-machine
   '(continue n val)
   (list (list '= =) (list '- -) (list '* *))
   '(
     (assign continue (label fact-done))                        ;set up final return address    
     fact-loop
     (test (op =) (reg n) (const 1))
     (branch (label base-case))
     (save continue)
     (save n)
     (assign n (op -) (reg n) (const 1))
     (assign continue (label after-fact))
     (goto (label fact-loop))
     after-fact
     (restore n)
     (restore continue)
     (assign val (op *) (reg n) (reg val)) ;val now contains n(n - 1)!
     (goto (reg continue))
     base-case
     (assign val (const 1))
     (goto (reg continue))
     fact-done)))
;; n = 1
(set-register-contents! fact-machine 'n 1)
(start fact-machine)
(get-register-contents fact-machine 'val)
((fact-machine 'stack) 'print-statistics)
;; (total-pushes = 0 maximum-depth = 0)

;; n = 2
(set-register-contents! fact-machine 'n 2)
(start fact-machine)
(get-register-contents fact-machine 'val)
((fact-machine 'stack) 'print-statistics)
;; (total-pushes = 2 maximum-depth = 2)

;; n = 3
(set-register-contents! fact-machine 'n 3)
(start fact-machine)
(get-register-contents fact-machine 'val)
((fact-machine 'stack) 'print-statistics)
;; (total-pushes = 4 maximum-depth = 4)

;; n = 4
(set-register-contents! fact-machine 'n 4)
(start fact-machine)
(get-register-contents fact-machine 'val)
((fact-machine 'stack) 'print-statistics)
;; (total-pushes = 6 maximum-depth = 6)

;; n = 5
(set-register-contents! fact-machine 'n 5)
(start fact-machine)
(get-register-contents fact-machine 'val)
((fact-machine 'stack) 'print-statistics)
;; (total-pushes = 8 maximum-depth = 8)


;; push演算の総数  2 * (n - 1)
;; 最大の深さ 2 * (n - 1)

;; 5.15
;; regsimに追加してみる
;; factで試
(load "./code_from_text/ch5-regsim.scm")
;; fact machineつくる
(define fact-machine
  (make-machine
   '(continue n val)
   (list (list '= =) (list '- -) (list '* *))
   '(
     (assign continue (label fact-done))                        ;set up final return address    
     fact-loop
     (test (op =) (reg n) (const 1))
     (branch (label base-case))
     (save continue)
     (save n)
     (assign n (op -) (reg n) (const 1))
     (assign continue (label after-fact))
     (goto (label fact-loop))
     after-fact
     (restore n)
     (restore continue)
     (assign val (op *) (reg n) (reg val)) ;val now contains n(n - 1)!
     (goto (reg continue))
     base-case
     (assign val (const 1))
     (goto (reg continue))
     fact-done)))

;; 
(set-register-contents! fact-machine 'n 4)
(start fact-machine)
(fact-machine 'get-instruction-counter)
;; 38 ;; instruction-counter動いた
(fact-machine 'reset-instruction-counter)
(fact-machine 'get-instruction-counter)
;; 0 ; reset 動いた

;; でかめ
(set-register-contents! fact-machine 'n 100)
(start fact-machine)
(fact-machine 'get-instruction-counter)
;; 1094

;; 5.16
;; 5.15と会場一緒

;; factで試
(load "./code_from_text/ch5-regsim.scm")
;; fact machineつくる
(define fact-machine
  (make-machine
   '(continue n val)
   (list (list '= =) (list '- -) (list '* *))
   '(
     (assign continue (label fact-done))                        ;set up final return address    
     fact-loop
     (test (op =) (reg n) (const 1))
     (branch (label base-case))
     (save continue)
     (save n)
     (assign n (op -) (reg n) (const 1))
     (assign continue (label after-fact))
     (goto (label fact-loop))
     after-fact
     (restore n)
     (restore continue)
     (assign val (op *) (reg n) (reg val)) ;val now contains n(n - 1)!
     (goto (reg continue))
     base-case
     (assign val (const 1))
     (goto (reg continue))
     fact-done)))
(fact-machine 'trace-on)
(set-register-contents! fact-machine 'n 4)
(start fact-machine)

;; ついでに番号もつけてみた。
;; (trace: 1 (assign continue (label fact-done)))
;; (trace: 2 (test (op =) (reg n) (const 1)))
;; (trace: 3 (branch (label base-case)))
;; (trace: 4 (save continue))
;; (trace: 5 (save n))
;; (trace: 6 (assign n (op -) (reg n) (const 1)))
;; (trace: 7 (assign continue (label after-fact)))
;; (trace: 8 (goto (label fact-loop)))
;; (trace: 9 (test (op =) (reg n) (const 1)))
;; (trace: 10 (branch (label base-case)))
;; (trace: 11 (save continue))
;; (trace: 12 (save n))
;; (trace: 13 (assign n (op -) (reg n) (const 1)))
;; (trace: 14 (assign continue (label after-fact)))
;; (trace: 15 (goto (label fact-loop)))
;; (trace: 16 (test (op =) (reg n) (const 1)))
;; (trace: 17 (branch (label base-case)))
;; (trace: 18 (save continue))
;; (trace: 19 (save n))
;; (trace: 20 (assign n (op -) (reg n) (const 1)))
;; (trace: 21 (assign continue (label after-fact)))
;; (trace: 22 (goto (label fact-loop)))
;; (trace: 23 (test (op =) (reg n) (const 1)))
;; (trace: 24 (branch (label base-case)))
;; (trace: 25 (assign val (const 1)))
;; (trace: 26 (goto (reg continue)))
;; (trace: 27 (restore n))
;; (trace: 28 (restore continue))
;; (trace: 29 (assign val (op *) (reg n) (reg val)))
;; (trace: 30 (goto (reg continue)))
;; (trace: 31 (restore n))
;; (trace: 32 (restore continue))
;; (trace: 33 (assign val (op *) (reg n) (reg val)))
;; (trace: 34 (goto (reg continue)))
;; (trace: 35 (restore n))
;; (trace: 36 (restore continue))
;; (trace: 37 (assign val (op *) (reg n) (reg val)))
;; (trace: 38 (goto (reg continue)))
;; done


;; 5.17
;; labelのあつかいがどうなってるかよくわかってないとこまるね。
;; asembleするとlabbelごとのかたまりの対になっているのか。
;; これのどこの何番目にいるのかが分かればよさそう。
;; おおごとになりそうなので別にした上、とけなかった。
;; cf. http://wat-aro.hatenablog.com/entry/2016/01/29/214707
(load "./ch5-5.17.scm")
;; fact machineつくる
(define fact-machine
  (make-machine
   '(continue n val)
   (list (list '= =) (list '- -) (list '* *))
   '(
     (assign continue (label fact-done))                        ;set up final return address    
     fact-loop
     (test (op =) (reg n) (const 1))
     (branch (label base-case))
     (save continue)
     (save n)
     (assign n (op -) (reg n) (const 1))
     (assign continue (label after-fact))
     (goto (label fact-loop))
     after-fact
     (restore n)
     (restore continue)
     (assign val (op *) (reg n) (reg val)) ;val now contains n(n - 1)!
     (goto (reg continue))
     base-case
     (assign val (const 1))
     (goto (reg continue))
     fact-done)))
(fact-machine 'trace-on)
(set-register-contents! fact-machine 'n 4)
(start fact-machine)

;; global : (assign continue (label fact-done))
;; (fact-loop) : (test (op =) (reg n) (const 1))
;; (fact-loop) : (branch (label base-case))
;; (fact-loop) : (save continue)
;; (fact-loop) : (save n)
;; (fact-loop) : (assign n (op -) (reg n) (const 1))
;; (fact-loop) : (assign continue (label after-fact))
;; (fact-loop) : (goto (label fact-loop))
;; (fact-loop) : (test (op =) (reg n) (const 1))
;; (fact-loop) : (branch (label base-case))
;; (fact-loop) : (save continue)
;; (fact-loop) : (save n)
;; (fact-loop) : (assign n (op -) (reg n) (const 1))
;; (fact-loop) : (assign continue (label after-fact))
;; (fact-loop) : (goto (label fact-loop))
;; (fact-loop) : (test (op =) (reg n) (const 1))
;; (fact-loop) : (branch (label base-case))
;; (fact-loop) : (save continue)
;; (fact-loop) : (save n)
;; (fact-loop) : (assign n (op -) (reg n) (const 1))
;; (fact-loop) : (assign continue (label after-fact))
;; (fact-loop) : (goto (label fact-loop))
;; (fact-loop) : (test (op =) (reg n) (const 1))
;; (fact-loop) : (branch (label base-case))
;; (base-case) : (assign val (const 1))
;; (base-case) : (goto (reg continue))
;; (after-fact) : (restore n)
;; (after-fact) : (restore continue)
;; (after-fact) : (assign val (op *) (reg n) (reg val))
;; (after-fact) : (goto (reg continue))
;; (after-fact) : (restore n)
;; (after-fact) : (restore continue)
;; (after-fact) : (assign val (op *) (reg n) (reg val))
;; (after-fact) : (goto (reg continue))
;; (after-fact) : (restore n)
;; (after-fact) : (restore continue)
;; (after-fact) : (assign val (op *) (reg n) (reg val))
;; (after-fact) : (goto (reg continue))
;; done

;; 5.18
(load "./code_from_text/ch5-regsim.scm")
(define fact-machine
  (make-machine
   '(continue n val)
   (list (list '= =) (list '- -) (list '* *))
   '(
     (assign continue (label fact-done))                        ;set up final return address    
     fact-loop
     (test (op =) (reg n) (const 1))
     (branch (label base-case))
     (save continue)
     (save n)
     (assign n (op -) (reg n) (const 1))
     (assign continue (label after-fact))
     (goto (label fact-loop))
     after-fact
     (restore n)
     (restore continue)
     (assign val (op *) (reg n) (reg val)) ;val now contains n(n - 1)!
     (goto (reg continue))
     base-case
     (assign val (const 1))
     (goto (reg continue))
     fact-done)))
(set-register-contents! fact-machine 'n 4)
(((fact-machine 'get-register) 'n) 'trace-on)
(start fact-machine)
;; (reg  n : 4  ->  3)
;; (reg  n : 3  ->  2)
;; (reg  n : 2  ->  1)
;; (reg  n : 1  ->  2)
;; (reg  n : 2  ->  3)
;; (reg  n : 3  ->  4)
;; done
