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


;; 次 lexical-address-set!
;; frameをたどってってそこだけ変えたframeを返せばいいかな。

;; 必要なframeをひろってくるやつ ↑と一緒
;; framesのほうがよさげな名前だと思った。
(define (find-frame index frames)
  (if (null? frames)
      '() ;; 無いときは nil返す
      (if (= 0 index)
          (car frames)
          (find-frame (- index 1) (cdr frames)))))

(define test-frames '(((a b c) (1 2 3))
                      ((d e f) (4 5 6))
                      ((x y z) ('a 'b 'c))))
(find-frame 1 test-frames)

;; displacementの所まで行ってそこの値だけ書きかえるやつ
(define (set-at-displacement! displacement value frame)
  (define (iter i result rest-frame)
    (if (null? rest-frame)
        result ;; restなくなったらおわり
        (if (not (= 0 i)) ;; indexが0の時以外は
            (iter (- i 1) (append result (list (car rest-frame))) (cdr rest-frame)) ;; ただくっつける
            (iter (- i 1) (append result (list value)) (cdr rest-frame))))) ;; そうじゃない時は更新
 (set-cdr! frame (list (iter displacement '() (cadr frame))))
 frame)


(define test-set-at-displacement-frame '((d e f) (4 5 6)))
(set-at-displacement! 1 1 test-set-at-displacement-frame)
;; ((d e f) (4 1 6))
;; できた。 

(define (lexical-address-set! address value frames)

  (define (find-frame index frames)
    (if (null? frames)
        '() ;; 無いときは nil返す
        (if (= 0 index)
            (car frames)
            (find-frame (- index 1) (cdr frames)))))

  (define (set-at-displacement! displacement value frame)
    (define (iter i result rest-frame)
      (if (null? rest-frame)
          result ;; restなくなったらおわり
          (if (not (= 0 i)) ;; indexが0の時以外は
              (iter (- i 1) (append result (list (car rest-frame))) (cdr rest-frame)) ;; ただくっつける
              (iter (- i 1) (append result (list value)) (cdr rest-frame))))) ;; そうじゃない時は更新
    (set-cdr! frame (list (iter displacement '() (cadr frame))))
    frame)
  
  (let ((frame (find-frame (car address) frames)))
    (if (null? frame)
        (error "Frame Not Found")
        (let ((displacement (cadr address)))
          (list-set! frames (car address) (set-at-displacement! displacement value frame))
          frames)))) ;; 便利関数list-set!をつかった。 set-at-displacement!もそうできる


;; 試
(define test-frames '(((a b c) (1 2 3))
                      ((d e f) (4 5 6))
                      ((x y z) ('a 'b 'c))))

(lexical-address-set! '(1 1) 1 test-frames)
;; (((a b c) (1 2 3)) ((d e f) (4 1 6)) ((x y z) ('a 'b 'c)))


