;; 5.24: cond を if に簡約せずに新しい基本特殊形式とし
;; て実装せよ。真である述語を見つけるまで連続した cond 節の述語
;; をテストしていくループを構築し、それから ev-sequence を使っ
;; てその節のアクションを評価する必要があるだろう。
;; ifのときどんなだった？を細かくみてみる
ev-if
  (save exp) ;; 環境 
  (save env) ;; を
  (save continue) ;; save
  (assign continue (label ev-if-decide)) ;; ifの条件節を評価したら ev-if-decideにとびたい
  (assign exp (op if-predicate) (reg exp)) ;; 条件節をexpに入れて
  (goto (label eval-dispatch)) ;; それを評価
ev-if-decide
  (restore continue) ;; 環境
  (restore env) ;; を
  (restore exp) ;; もどす
  (test (op true?) (reg val)) ;; 評価結果がtrueだったら 
  (branch (label ev-if-consequent)) ;; if-consequentに行く
ev-if-alternative
  (assign exp (op if-alternative) (reg exp)) ;; expにif-alternativeに入れて
  (goto (label eval-dispatch)) ;; そいつを評価
ev-if-consequent
  (assign exp (op if-consequent) (reg exp)) ;; expにif-consequentに入れて
  (goto (label eval-dispatch)) ;; そいつを評価
;; ↑と同じかんじにすればよさそう

ev-cond
  (save exp) ;; 環境 
  (save env) ;; を
  (save continue) ;; save
  (assign continue (label ev-cond-decide)) ;; condの条件節を評価したら ev-cond-decideにとびたい
  (assign exp (op cond-predicate) (reg exp)) ;; 条件節をexpに入れて
  (goto (label eval-dispatch)) ;; それを評価
ev-cond-decide
  (restore continue) ;; 環境
  (restore env) ;; を
  (restore exp) ;; もどす
  (test (op true?) (reg val)) ;; 評価結果がtrueだったら 
  (branch (label ev-cond-consequent)) ;; cond-consequentに行く
ev-cond-next ;; 次のcond
  (assign exp (op cond-next) (reg exp)) ;; 次の条件節をexpに入れて
  (test (op else?) (reg exp)) ;; それがelse だったら
  (branch (label ev-cond-consequent)) ;; cond-consequentに行って評価
  ;; それ以外の場合は条件を調べる
  (save exp) ;; 環境 
  (save env) ;; を
  (save continue) ;; save
  (assign exp (op cond-predicate) (reg exp)) ;; 条件節をexpに入れて
  (goto (label eval-dispatch)) ;; そいつを評価
ev-cond-consequent ;; condの結果
  (assign exp (op cond-consequent) (reg exp)) ;; expにcond-consequentに入れて
  (goto (label eval-dispatch)) ;; そいつを評価

;; こんなかな。
;; これ用のhelperっぽいのを作る
(define (else? exp)
  (eq? 'else (car exp)))
(define (cond-predicate exp)
  (car exp))
(define (cond-next exp)
  (car exp))
(define (cond-consequent exp)
  (cadr exp))
;; ev-sequence使わなかった。

;; 5.26
;; むずいのでパス

