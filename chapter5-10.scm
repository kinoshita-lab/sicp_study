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

;;; 5.40
;; 足して、lambdaのときに膨らませばいいのかな。

;; 5.41
;; 地味シリーズだ 5.39とやることがほとんどかわんないぞ。
;; 
;; 何個先のcompile-time-environmentに入ってるか？
(define (find-frame-contains-variable variable env-list)
  (define (iter index variable env-list) 
    (if (null? env-list)
        '()
        (if (memq variable (car env-list))
            index
            (iter (+ index 1) variable (cdr env-list)))))
  (iter 0 variable env-list))

(find-frame-contains-variable 'c '((y z) (a b c d e) (x y))) ;; => 1
(find-frame-contains-variable 'x '((y z) (a b c d e) (x y))) ;; => 2
(find-frame-contains-variable 'w '((y z) (a b c d e) (x y))) ;; => ()
;; よさげ。

;; listの何番目に入ってるか？
(define (find-displacement-index variable frame)
  (define (iter index variable frame)
    (if (null? frame)
        '()
        (if (equal? variable (car frame))
            index
            (iter (+ index 1) variable (cdr frame)))))
  (iter 0 variable frame))

;; ここまで同じだとまとめたくなるけどとりあえずいいや。
(find-displacement-index 'c '(a b c d e)) ;; => 2
(find-displacement-index 'x '(x z)) ;; => 0
(find-displacement-index 'w'(a b c d e)) ;; => ()

;; これをまとめた感じのを作る
(define (find-variable variable compile-time-environment)
  ;; 何個先のcompile-time-environmentに入ってるか？
  (define (find-frame-contains-variable variable env-list)
    (define (iter index variable env-list) 
      (if (null? env-list)
          '()
          (if (memq variable (car env-list))
              index
              (iter (+ index 1) variable (cdr env-list)))))
    (iter 0 variable env-list))

  ;; listの何番目に入ってるか？
  (define (find-displacement-index variable frame)
    (define (iter index variable frame)
      (if (null? frame)
          '()
          (if (equal? variable (car frame))
              index
              (iter (+ index 1) variable (cdr frame)))))
    (iter 0 variable frame))

  ;; nth的なものが要る
  (define (nth index l)
    (if (= 0 index)
        (car l)
        (nth (- index 1) (cdr l))))
  
  ;; ↑の色々を使ってfind-variableを作る
  (let ((frame-index (find-frame-contains-variable variable compile-time-environment)))
    (if (null? frame-index)
        'not-found
        (let ((frame (nth frame-index compile-time-environment)))
          (list frame-index (find-displacement-index variable frame))))))

(find-variable 'c '((y z) (a b c d e) (x y))) ;; (1 2)
(find-variable 'x '((y z) (a b c d e) (x y))) ;; (2 0)
(find-variable 'w '((y z) (a b c d e) (x y))) ;; not-found

;; 5.42
;; 急激にめんどいやつだ
;; 5.40でcompile-time-environment足したやつをforkしてそこからやってみる
(define (compile-variable exp target linkage compile-time-environment)
  (end-with-linkage linkage
   (make-instruction-sequence '(env) (list target)
    `((assign ,target
              (op lookup-variable-value)
              (const ,exp)
              (reg env))))))
;; これをこんな感じに書きかえればいいのかな。
(define (compile-variable exp target linkage compile-time-environment)
  ;; compile時環境からindexひろえる場合はlookup-variable-valueをとばして直でassignする
  (let ((compile-time-variable-address (find-variable exp compile-time-environment)))
    (if (not (equal? 'not-found compile-time-variable-address))
        (let ((lookup-ed-value (lexical-address-lookup
                              compile-time-variable-address
                              compile-time-environment)))
          (end-with-linkage linkage
                            (make-instruction-sequence '(env) (list target)
                                                       `((assign ,target
                                                                 ,lookup-ed-valu)))))
        ;; 見つからなかったばあいは元々のlookup-variable-value版を使う
        (end-with-linkage linkage
                          (make-instruction-sequence '(env) (list target)
                                                     `((assign ,target
                                                               (op lookup-variable-value)
                                                               (const ,exp)
                                                               (reg env))))))))

;; compile-assignmentの方
(define (compile-assignment exp target linkage compile-time-environment)
  (let ((var (assignment-variable exp))
        (get-value-code
         (compile (assignment-value exp) 'val 'next)))
    (end-with-linkage linkage
     (preserving '(env)
      get-value-code
      (make-instruction-sequence '(env val) (list target)
       `((perform (op set-variable-value!)
                  (const ,var)
                  (reg val)
                  (reg env))
         (assign ,target (const ok))))))))
;; これを
(define (compile-assignment exp target linkage compile-time-environment)
  (let* ((var (assignment-variable exp)) ;; let*った
        (get-value-code
         (compile (assignment-value exp) 'val 'next))
        (compile-time-variable-address (find-variable var compile-time-environment)))
    (if (not (equal? 'not-found compile-time-variable-address))
        (end-with-linkage linkage
                          (preserving '(env)
                                      get-value-code
                                      (make-instruction-sequence '(env) (list target)
                                                                 `((perform (op lexical-address-set!) 
                                                                            (const ,var)
                                                                            (reg val)
                                                                            (reg env))
                                                                   (assign ,target (const ok)))))
        ;; この下は元のコード
        (end-with-linkage linkage
                          (preserving '(env)
                                      get-value-code
                                      (make-instruction-sequence '(env val) (list target)
                                                                 `((perform (op set-variable-value!)
                                                                            (const ,var)
                                                                            (reg val)
                                                                            (reg env))
                                                                   (assign ,target (const ok))))))))))

;; こうすればいいのかな。

;; 試
(load "./code_from_text/ch5-compiler-find-variable.scm")
(use slib)
(require 'pretty-print)
(define pp pretty-print)
(define global-compile-time-environment '())
(pp (compile
     '((lambda x y)
       (+ x y)
       1
       2)
     'val
     'next
     global-compile-time-environment))
;; 全然だめだ。compile-time-envの形式が根本的にまちがっている気がする。
;; 形式はもともとのenvと同じにしてみよう。
;; extend-environmentっぽくしないとだめだとおもう
(define (extend-compile-time-environment new-formals compile-time-env)
  (define (make-unassigned-vals-list formals)
    (define (iter result formals)
      (if (null? formals)
          result
          (iter (cons '*unassigned* result) (cdr formals))))
    (iter '() formals))

  (let ((new-env-frame (list new-formals (make-unassigned-vals-list new-formals))))
    (cons new-env-frame compile-time-env)))

(extend-compile-time-environment '(x y z) (extend-compile-time-environment '(a b c) global-compile-time-environment))
;; (((x y z) (*unassigned* *unassigned* *unassigned*)) ((a b c) (*unassigned* *unassigned* *unassigned*)))
;; こんなのを作ってみたのだが、 うまくいかないのは変わらず。
