;; 5.39 - 5.43のlexicalたち
;; 5.39 言ってることの意味があんまわかんないけどこうかな。
;; (lexical-address-lookup '(0 0) (((a b c) (1 2 3))
;;                                ((d e f) (4 5 6))
;;                                ((x y z) ('a 'b 'c))))
;; -> aの値 = 1
;; (lexical-address-lookup '(1 2) ((((a b c) (1 2 3))
;;                                ((d e f) (4 5 6))
;;                                ((x y z) ('a 'b 'c))))
;; -> fの値 = 6
;; みたいなやつ。

(define test-frame '(((a b c) (1 2 3))
                      ((d e f) (4 5 6))
                      ((x y z) ('a 'b 'c))))

(define (find-frame address frame)
  (if (null? frame)
      '() ;; 無いときは nil返す
      (if (= 0 address)
          (car frame)
          (get-frame (- address 1) (cdr frame)))))
(find-frame 0 test-frame)
;; ((a b c) (1 2 3))
(find-frame 2 test-frame)
;; ((x y z) ('a 'b 'c))
;; よさげ。

(define (find-displacement-value displacement frame)
  (if (null? (car frame)) ;; dasai
      '() ;; 無いときは nil返す
      (let ((vars (car frame))
            (vals (cadr frame)))
        (if (= 0 displacement)
            (car vals)
            (find-displacement-value (- displacement 1) (cons (cdr vars) (list (cdr vals)))))))) ;; dasai

(find-displacement-value 1 '((a b c) (1 2 3)))
;; 1
(find-displacement-value 2 '((a b c) (1 2 3)))
;; 2
(find-displacement-value 3 '((a b c) (1 2 3)))
;; ()
;; よさげ。
;; 合成
(define (lexical-address-lookup address compile-time-env)
  
  (define (find-frame index frame)
    (if (null? frame)
        '() ;; 無いときは nil返す
        (if (= 0 index)
            (car frame)
            (find-frame (- index 1) (cdr frame)))))
  
  (define (find-displacement-value displacement frame)
    (if (null? (car frame)) ;; dasai
        '() ;; 無いときは nil返す
      (let ((vars (car frame))
            (vals (cadr frame)))
        (if (= 0 displacement)
            (car vals)
            (find-displacement-value (- displacement 1) (cons (cdr vars) (list (cdr vals)))))))) ;; dasai
  
  (let* ((frame-index (car address)) ;; めんどいので let*
         (displacement-index (cadr address))
         (search-frame (find-frame frame-index compile-time-env)))
    
    (if (null? search-frame)
        (error "Unbound Value") ;; frameなかったらerror
        (let ((val (find-displacement-value displacement-index search-frame)))
          (cond ((null? val) (error "Unbound Value"))
                ((eq? val "*unassigned*") (error "Unassigned Value")) ;; 問題文に出てるエラー
                (else val))))))

  
(define test-frame '(((a b c) (1 2 3))
                      ((d e f) (4 5 6))
                      ((x y z) ('a 'b 'c))))

(lexical-address-lookup '(0 0) test-frame)
;; 1
(lexical-address-lookup '(1 2) test-frame)
;; 6
(lexical-address-lookup '(6 2) test-frame)
;; *** ERROR: Unbound variable
;; よさげ。
