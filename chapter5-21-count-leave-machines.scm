(define (not-pair? l)
  (not (pair? l)))

(define count-leave-machine
  (make-machine
   '(tree continue val tmp)
   (list (list 'null? null?) (list 'not-pair? not-pair?) (list 'car car) (list 'cdr cdr) (list '+ +))
   '(
	  (assign continue (label  count-leaves-done))
	  count-leaves-loop
	  (test (op null?) (reg tree))
	  (branch (label immediate-answer-0))
      (test (op not-pair?) (reg tree))
      (branch (label immediate-answer-1))
	  ;; (count-leaves (car tree)) を求める準備
	  (save continue)
	  (assign continue (label aftercount-leaves-car))
	  (save tree) 										; treeの古い値を保存
	  (assign tree (op car) (reg tree)) ; tree を car tree で上書き
	  (goto (label count-leaves-loop)) ; 再帰呼び出しの実行
	  aftercount-leaves-car 										; リターン時に Count-Leaves(car tree) は val に入っている
	  (restore tree)
	  ;; Count-Leaves(cdr tree) を求める準備
	  (assign tree (op cdr) (reg tree))
	  (assign continue (label aftercount-leaves-cdr))
	  (save val) 									; Count-Leaves(car tree) を保存
	  (goto (label count-leaves-loop))
	  aftercount-leaves-cdr				; リターン時に Count-Leaves(cdr tree) は val に入っている
	  (assign tmp (reg val)) 		; tmp には Count-Leaves(cdr tree) が入る
	  (restore val) 			; val には Count-Leaves(car tree) が入る
	  (restore continue)
	  (assign val ; Count-Leaves(car tree) + Count-Leaves(cdr tree)
			  (op +) (reg val) (reg tmp))
	  (goto (reg continue)) 										; 呼び出し元に戻る、答えはval の中
	  immediate-answer-0
	  (assign val (const 0)) 										; 基底の場合: Count-Leaves(0) = 0
	  (goto (reg continue))
      immediate-answer-1
      (assign val (const 1))
      (goto (reg continue))
	   count-leaves-done)))
