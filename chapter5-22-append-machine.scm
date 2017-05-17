(load "./code_from_text/ch5-regsim.scm")
(define append-machine
  (make-machine
   '(x y continue ans tmp)
   (list (list 'null? null?) (list 'cons cons) (list 'car car) (list 'cdr cdr))
   '(
     (assign continue (label append-done))
     append-loop
     (test (op null?) (reg x))
     (branch (label null))
     ;; (append (cdr x) y) をやる準備
     (save x)
     (assign x (op cdr) (reg x))  ;; x <- (cdr x)
     (save continue)
     (assign continue (label afterappend-cdr))
     (goto (label append-loop))
     afterappend-cdr ;; ansに (append (cdr x) y) の結果が入ってる
     (restore continue)
     (restore x)
     (assign tmp (op car) (reg x))
     (assign ans (op cons) (reg tmp) (reg ans))
     (goto (reg continue))
     ;;
     null
     (assign ans (reg y))
     (goto (reg continue))
     append-done
     )))


;; 副作用編はめちゃくちゃ簡単なのでは。
(define (last-pair x)
  (if (null? (cdr x))
      x
      (last-pair (cdr x))))

(define append!-machine
  (make-machine
   '(x y carx tmp tmp2)
   (list (list 'car car) (list 'cons cons) (list 'last-pair last-pair) (list 'set-cdr! set-cdr!))
   '(
     (assign tmp (op last-pair) (reg x)) ;; tmp <- (last-pair x)
     (assign carx (op car) (reg x)) ;; carx <- (car x)
     (assign tmp2 (op set-cdr!) (reg tmp) (reg y)) ;; tmp2は意味ない値
     append!-done
     )))
;; gosh> (1 2 3 4)
