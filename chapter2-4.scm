;; 2.3.3 例: 集合の表現
(use slib)
(require 'trace)
; true/falseない
(define false #f)
(define true #t)

(define (element-of-set? x set)
  (cond ((null? set) false)
        ((equal? x (car set)) true)
        (else (element-of-set? x (cdr set)))))

(define (adjoin-set x set)
  (if (element-of-set? x set) 
      set
      (cons x set)))

(define (intersection-set set1 set2)
  (cond ((or (null? set1) (null? set2)) '())
        ((element-of-set? (car set1) set2)
         (cons (car set1)
               (intersection-set (cdr set1) set2)))
        (else (intersection-set (cdr set1) set2))))

; 2.59
(define (union-set set1 set2)
  (cond ((null? set1) set2)
        ((element-of-set? (car set1) set2)
         (union-set (cdr set1) set2))
        (else (union-set
               (cdr set1)
               (cons (car set1) set2)))))
      
(define list1 '(a b c d))
(define list2 '(c d e f))
(union-set list1 list2)
(intersection-set list1 list2)
; gosh> (b a c d e f)

; 2.60
; element-of-set? これは変えなくていいと思う
(define (element-of-set? x set)
  ((cond ((null? set) false)
         ((equal? x (car set)) true)
         (else (element-of-set? x (cdr set))))))

; adjoin-set 何も考えずにつっこめばいい
(define (adjoin-set x set)
  (cons x set))

; intersection-set 変えなくて良さそう
(define (intersection-set set1 set2)
  (cond ((or (null? set1) (null? set2)) '())
        ((element-of-set? (car set1) set2)
         (cons (car set1)
               (intersection-set (cdr set1) set2)))
        (else (intersection-set (cdr set1) set2))))

; union-set 合体すればいいんじゃないのか         
(define (union-set set1 set2)
  (append set1 set2))

(define list1 '(2 3 2 1 3 2 2))
(define list2 '(3 2 1 2 5 5 5))

(intersection-set list1 list2)
; gosh> (2 3 2 1 3 2 2)
(union-set list1 list2)
; gosh> (2 3 2 1 3 2 2 3 2 1 2 5 5 5)
; 重複なし表現の対応する手続きと比べて効率はどうなるか. 重複なし表現よりこの表現の方が使いたくなる応用はあるだろうか. 

; 効率は要素数によるので一概にいえないのでは？
; 何が何個あるか？みたいなことを調べたい場合は重複を許す集合のほうがいい、というかそうしないとできないね。


; 順序づけられたリストとしての集合
(define (element-of-set? x set)
  (cond ((null? set) false)
        ((= x (car set)) true)
        ((< x (car set)) false)
        (else (element-of-set? x (cdr set)))))

(define (intersection-set set1 set2)
  (if (or (null? set1) (null? set2))
      '()
      (let ((x1 (car set1)) (x2 (car set2)))
        (cond ((= x1 x2)
               (cons x1
                     (intersection-set (cdr set1)
                                       (cdr set2)))) ;採用された
              ((< x1 x2)
               (intersection-set (cdr set1) set2)) ; set1にはこれ以上小さい数はないので次の数で比較を開始
              ((< x2 x1)
               (intersection-set set1 (cdr set2))))))) ; set2にはこれ以上小さい数はないので次の数で比較を開始


; 2.61
; element-of-set?は順序付きのこれ使う
(define (element-of-set? x set)
  (cond ((null? set) false)
        ((= x (car set)) true)
        ((< x (car set)) false)
        (else (element-of-set? x (cdr set)))))

(define (adjoin-set x set)
  (if (element-of-set? x set) 
      set
      (if (< x (car set)) (cons x set)
          (cons (car set) (adjoin-set x (cdr set))))))

(define list1 '(2 4 6 8))
(adjoin-set '3 list1)
; gosh> (2 3 4 6 8)


; 2.62
(define (union-set set1 set2)
  (cond ((null? set1) set2)
        ((element-of-set? (car set1) set2)
         (union-set (cdr set1) set2))
        (else (union-set
               (cdr set1)
               (cons (car set1) set2)))))

(define (union-set set1 set2)
 (cond ((null? set1) set2)
       ((null? set2) set1)
       (else (let ((x1 (car set1)) 
             (x2 (car set2)))
         (cond ((= x1 x2)
                (union-set (cdr set1) set2))
               ((< x1 x2)
                (cons x1 (union-set (cdr set1)
                                    set2)))
               ((> x1 x2)
                (cons x2 (union-set set1 (cdr set2)))))))))
(define list1 '(2 4 6 8))
(define list2 '(1 3 5 7))
(union-set list1 list2) 
;gosh>(1 2 3 4 5 6 7 8)



(define (entry tree) (car tree))
(define (left-branch tree) (cadr tree))
(define (right-branch tree) (caddr tree))
(define (make-tree entry left right)
  (list entry left right))

(define (element-of-set? x set)
  (cond ((null? set) false)
        ((= x (entry set)) true)
        ((< x (entry set))
         (element-of-set? x (left-branch set)))
        ((> x (entry set))
         (element-of-set? x (right-branch set)))))

(define (adjoin-set x set)
  (cond ((null? set) (make-tree x '() '()))
        ((= x (entry set)) set)
        ((< x (entry set))
         (make-tree (entry set)
                    (adjoin-set x (left-branch set))
                    (right-branch set)))
        ((> x (entry set))
         (make-tree (entry set)
                    (left-branch set)
                    (adjoin-set x (right-branch set))))))


; 2.63
(define (tree->list-1 tree)
  (if (null? tree)
      '()
      (append (tree->list-1 (left-branch tree))
              (cons (entry tree)
                    (tree->list-1 (right-branch tree))))))

(define (tree->list-2 tree)
  (define (copy-to-list tree result-list)
    (if (null? tree)
        result-list
        (copy-to-list (left-branch tree)
                      (cons (entry tree)
                            (copy-to-list (right-branch tree)
                                          result-list)))))
  (copy-to-list tree '()))

(define tree216-1
  (make-tree '7 (make-tree '3 '1 '5) (make-tree '9 '() '11)))

(define tree216-2
  (make-tree '3 '1 (make-tree '7 '5 (make-tree '9 '() '11))))

(define tree216-3
  (make-tree '5 (make-tree '3 '1 '()) (make-tree '9 '7 '11)))

(trace tree->list-1)
(trace tree->list-2)

(tree->list-1 tree216-1)
(tree->list-2 tree216-1)

(tree->list-1 tree216-2)
(tree->list-2 tree216-2)

(tree->list-1 tree216-3)
(tree->list-2 tree216-3)

; 問題がまともに動かないし　なんじゃこれ
; 2番目のほうが１章でやった iter方式だからこっちのがよさげ。


; 2.64

; a
(define (list->tree elements)
  (car (partial-tree elements (length elements))))

(define (partial-tree elts n)
  (if (= n 0)
      (cons '() elts)
      (let ((left-size (quotient (- n 1) 2)))
        (let ((left-result (partial-tree elts left-size)))
          (let ((left-tree (car left-result))
                (non-left-elts (cdr left-result))
                (right-size (- n (+ left-size 1))))
            (let ((this-entry (car non-left-elts))
                  (right-result (partial-tree (cdr non-left-elts)
                                              right-size)))
              (let ((right-tree (car right-result))
                    (remaining-elts (cdr right-result)))
                (cons (make-tree this-entry left-tree right-tree)
                      remaining-elts))))))))

(trace list->tree)
(trace partial-tree)
(trace make-tree)
(list->tree '(1 3 5 7 9 11))

; こんなのでてきた
; (5 (1 () (3 () ())) (9 (7 () ()) (11 () ())))
; 絵を描くのがめんどい
  ;;     5
  ;;  /     \
  ;; 1       9
  ;;   \    / \ 
  ;;    3  7  11
; quatientってなんだっけ 商
; traceはってみる
;; gosh> CALL list->tree (1 3 5 7 9 11)
;;   CALL partial-tree (1 3 5 7 9 11) 6
;;     CALL partial-tree (1 3 5 7 9 11) 2
;;       CALL partial-tree (1 3 5 7 9 11) 0
;;       RETN partial-tree (() 1 3 5 7 9 11)
;;       CALL partial-tree (3 5 7 9 11) 1
;;         CALL partial-tree (3 5 7 9 11) 0
;;         RETN partial-tree (() 3 5 7 9 11)
;;         CALL partial-tree (5 7 9 11) 0
;;         RETN partial-tree (() 5 7 9 11)
;;         CALL make-tree 3 () ()
;;         RETN make-tree (3 () ())
;;       RETN partial-tree ((3 ...) 5 7 9 11)
;;       CALL make-tree 1 () (3 () ())
;;       RETN make-tree (1 () (3 () ()))
;;     RETN partial-tree ((1 ...) 5 7 9 11)
;;     CALL partial-tree (7 9 11) 3
;;       CALL partial-tree (7 9 11) 1
;;         CALL partial-tree (7 9 11) 0
;;         RETN partial-tree (() 7 9 11)
;;         CALL partial-tree (9 11) 0
;;         RETN partial-tree (() 9 11)
;;         CALL make-tree 7 () ()
;;         RETN make-tree (7 () ())
;;       RETN partial-tree ((7 () ()) 9 11)
;;       CALL partial-tree (11) 1
;;         CALL partial-tree (11) 0
;;         RETN partial-tree (() 11)
;;         CALL partial-tree () 0
;;         RETN partial-tree (())
;;         CALL make-tree 11 () ()
;;         RETN make-tree (11 () ())
;;       RETN partial-tree ((11 () ()))
;;       CALL make-tree 9 (7 () ()) (11 () ())
;;       RETN make-tree (9 (7 () ()) (11 () ()))
;;     RETN partial-tree ((9 (7 () ()) (11 () ())))
;;     CALL make-tree 5 (1 () (3 () ())) (9 (7 () ()) (11 () ()))
;;     RETN make-tree (5 (1 () (3 () ())) (9 (7 () ()) (11 () ())))
;;   RETN partial-tree ((5 (1 () (3 () ())) (9 (7 () ...) (11 () ()))))
;; RETN list->tree (5 (1 () (3 () ())) (9 (7 () ()) (11 () ())))
;; (5 (1 () (3 () ())) (9 (7 () ()) (11 () ())))
;;
;; 3つ拾ってきて木にするしてそれを合体する動きをしている

; b
; 要素が増えると　ばらして左右って気を作るステップが最大で3増えて、場合によっては新しい木にするために上の構造までその影響が及ぶので logNくらいじゃないかな。


; 2.65
;問題2.63と2.64の結果を使い, (釣合った)二進木として実装されている集合のunion-setとintersection-setを&Theta(n)で実装せよ.
; こういうことなの？？ちがくない？
; a
(define (union-set-tree set1 set2)
  (let ((tree1 (list->tree set1))
        (tree2 (list->tree set2)))
    (tree->list-2 (union-set tree1 tree2))))

(define (intersection-se-tree set1 set2)
  (let ((tree1 (list->tree set1))
        (tree2 (list->tree set2)))
    (tree->list-2 (intersection-set tree1 tree2))))

; b
; 増加の程度は木ってるからΘ(n)で行けると思う


;; (define (lookup given-key set-of-records)
;;   (cond ((null? set-of-records) false)
;;         ((equal? given-key (key (car set-of-records)))
;;          (car set-of-records))
;;         (else (lookup given-key (cdr set-of-records)))))
;; ↑のkeyってのがそもそも定義されてないし
;; (key (car-set-of-elements))で取り出せるものと仮定するしかない
;; (car set-of-records)はkeyとそこにバインドされている情報が返ってくる。
;; このへん説明がなくてうざいなあ。


; 2.66
; element-of-set? 木っぽい編はこうだった        
;; (define (element-of-set? x set)
;;   (cond ((null? set) false)
;;         ((= x (entry set)) true)
;;         ((< x (entry set))
;;          (element-of-set? x (left-branch set)))
;;         ((> x (entry set))
;;          (element-of-set? x (right-branch set)))))
;;
(define (lookup given-key set-of-records)
  (let ((top-record (car set-of-records)))   
    (cond ((null? set-of-records) false)
          ((= x (key top-record)
              (car set-of-records)))
          ((< x (key top-record))
              (lookup x (left-branch set-of-records)))
          ((> x (key top-record))
              (lookup x (right-branch set-of-records))))))
;; 多分こんな感じ
  
        
