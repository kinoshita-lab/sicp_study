;; 5.31
;; ecevalの時どんなかんじだったかを拾ってくるとこんな。
;; ev-application
;;   (save continue)
;;   (save env)l ;;演算子の評価の前 envの保存
;;   (assign unev (op operands) (reg exp))
;;   (save unev)
;;   (assign exp (op operator) (reg exp))
;;   (assign continue (label ev-appl-did-operator))
;;   (goto (label eval-dispatch))
;; ev-appl-did-operator
;;   (restore unev)
;;   (restore env) ;;演算子の評価の後 envの復元
;;   (assign argl (op empty-arglist))
;;   (assign proc (reg val))
;;   (test (op no-operands?) (reg unev))
;;   (branch (label apply-dispatch))
;;   (save proc) ;; 被演算子列の評価前 procの保存
;; ev-appl-operand-loop
;;   (save argl) ;;被演算子の評価の前 arglの保存
;;   (assign exp (op first-operand) (reg unev))
;;   (test (op last-operand?) (reg unev))
;;   (branch (label ev-appl-last-arg))
;;   (save env)
;;   (save unev)
;;   (assign continue (label ev-appl-accumulate-arg))
;;   (goto (label eval-dispatch))
;; ev-appl-last-arg
;;   (assign continue (label ev-appl-accum-last-arg))
;;   (goto (label eval-dispatch))
;; ev-appl-accum-last-arg
;;   (restore argl) ;;被演算子の評価の後 arglの復元
;;   (assign argl (op adjoin-arg) (reg val) (reg argl))
;;   (restore proc);; 被演算子列の評価後 procの復元
;;   (goto (label apply-dispatch))

;(f 'x 'y) ;; 引数の評価に環境の保存は不要なのでenvの保存、復元はいらない。 arglもかわらないので不要。fを探してきて apply-dispatchに飛ぶだけなので procも不要。

;((f) 'x 'y) ;; procに fとその返り値が入るので procだけ必要な気がする。

;(f (g ' x) y) ;; yは探してくる必要あるけど保存はいらなそう？と思ったけどyが何かはわからない(関数かも) proc/arglが保存、復元必要。arglに (g 'x) とその評価した値が入るので argl/procは保存と復元が必要。 procは不要

;(f (g 'x) 'y) 'y 不要 (g 'x) argl/proc必要 f不要

