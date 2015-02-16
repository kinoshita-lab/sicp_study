;; 2.3.4 例: Huffman符号木
(use slib)
(require 'trace)
; true/falseない
(define false #f)
(define true #t)

(define (make-leaf symbol weight)
  (list 'leaf symbol weight))

(define (leaf? object)
  (eq? (car object) 'leaf))

(define (symbol-leaf x) (cadr x))

(define (weight-leaf x) (caddr x))

(define (left-branch tree) (car tree))

(define (right-branch tree) (cadr tree))

(define (symbols tree)
  (if (leaf? tree)
      (list (symbol-leaf tree))
      (caddr tree)))

(define (weight tree)
  (if (leaf? tree)
      (weight-leaf tree)
      (cadddr tree)))

(define (make-code-tree left right)
  (list left
        right
        (append (symbols left) (symbols right))
        (+ (weight left) (weight right))))

; 復号化手続き
(define (decode bits tree)
  (define (decode-1 bits current-branch)
    (if (null? bits)
        '()
        (let ((next-branch
               (choose-branch (car bits) current-branch)))
          (if (leaf? next-branch)
              (cons (symbol-leaf next-branch)
                    (decode-1 (cdr bits) tree))
              (decode-1 (cdr bits) next-branch)))))
  (decode-1 bits tree))

(define (choose-branch bit branch)
  (cond ((= bit 0) (left-branch branch))
        ((= bit 1) (right-branch branch))
        (else (error "bad bit -- CHOOSE-BRANCH" bit))))

(define (adjoin-set x set)
  (cond ((null? set) (list x))
        ((< (weight x) (weight (car set))) (cons x set))
        (else (cons (car set)
                    (adjoin-set x (cdr set))))))

(define (make-leaf-set pairs)
  (if (null? pairs)
      '()
      (let ((pair (car pairs)))
        (adjoin-set (make-leaf (car pair)    ; 記号
                               (cadr pair))  ; 頻度
                    (make-leaf-set (cdr pairs))))))

;; 2.67
(define sample-tree
  (make-code-tree (make-leaf 'A 4)
                  (make-code-tree
                   (make-leaf 'B 2)
                   (make-code-tree (make-leaf 'D 1)
                                   (make-leaf 'C 1)))))
(define sample-message '(0 1 1 0 0 1 0 1 0 1 1 1 0))


(decode sample-message sample-tree)
; gosh> (A D A B B C A)

;; 2.68
(define (encode message tree)
  (if (null? message)
      '()
      (append (encode-symbol (car message) tree)
              (encode (cdr message) tree))))

;; ↑で動くようにencode-symbolを考える問題


; こんなんかいてみた
(define (has-symbol a-symbol symbols)
  (cond ((null? symbols) false)
        ((eq? (car symbols) a-symbol) true)
        (else (has-symbol a-symbol (cdr symbols)))))

(has-symbol 'A (symbols sample-tree))
(has-symbol 'Z (symbols sample-tree))
;gosh> #t
;gosh> #f
;よさげ

(define (encode-one bits letter subtree)
  (if (leaf? subtree)
      bits
      (cond ((has-symbol letter (symbols (left-branch subtree)))
             (encode-one (append bits '(0)) letter (left-branch subtree)))
            ((has-symbol letter (symbols (right-branch subtree)))
             (encode-one (append bits '(1)) letter (right-branch subtree)))
            (else (error "bad bit -- ENCODE-ONE" bit)))))

(encode-one '() 'A sample-tree)
(encode-one '() 'B sample-tree)
(encode-one '() 'C sample-tree)            
(encode-one '() 'D sample-tree)
; よさげ  
;; gosh> (0)
;; gosh> (1 0)
;; gosh> (1 1 1)
;; gosh> (1 1 0)

;; 合体
(define (encode-message message tree)
  (define (has-symbol a-symbol symbols)
    (cond ((null? symbols) false)
          ((eq? (car symbols) a-symbol) true)
          (else (has-symbol a-symbol (cdr symbols)))))

  (define (encode-one bits letter subtree)
    (if (leaf? subtree)
        bits
        (cond ((has-symbol letter (symbols (left-branch subtree)))  ; 左側にあったら
               (encode-one (append bits '(0)) letter (left-branch subtree))) ; 0をつけて1段階掘り進む
              ((has-symbol letter (symbols (right-branch subtree))) ; 右側にあったら
               (encode-one (append bits '(1)) letter (right-branch subtree))) ;1をつけて1段階掘り進む
              (else (error "bad bit -- ENCODE-ONE" bit)))))

  (define (encode-iter bits message tree)
    (if (null? message) bits
        (append bits (encode-iter (encode-one '() (car message) tree) ; bits
                     (cdr message) ; letter
                     tree))))
  (encode-iter '() message tree))

(encode-message '(A D A B B C A) sample-tree)
; gosh> (0 1 1 0 0 1 0 1 0 1 1 1 0)  
;
; そもそも題意を間違えている
; ここだけでOK
(define (encode-symbol letter subtree)
  (define (iter bits letter subtree)
    (if (leaf? subtree)
        bits
        (cond ((has-symbol letter (symbols (left-branch subtree)))
               (iter (append bits '(0)) letter (left-branch subtree)))
              ((has-symbol letter (symbols (right-branch subtree)))
               (iter (append bits '(1)) letter (right-branch subtree)))
              (else (error "bad bit -- ENCODE-SYMBOL" bit)))))

  (iter '() letter subtree))

; 2.69
(define (generate-huffman-tree pairs)
  (successive-merge (make-leaf-set pairs)))

(define (make-leaf-set pairs)
  (if (null? pairs)
      '()
      (let ((pair (car pairs)))
        (adjoin-set (make-leaf (car pair)    ; 記号
                               (cadr pair))  ; 頻度
                    (make-leaf-set (cdr pairs))))))


(define (make-code-tree left right)
  (list left
        right
        (append (symbols left) (symbols right))
        (+ (weight left) (weight right))))

; 無理でした
(define (successive-merge set)
  (if (null? (cdr set))
      (car set)
      (successive-merge
       (adjoin-set (make-code-tree
                    (car set)
                    (cadr set))
                   (cddr set)))))

;; 2.70
(define lyric-magnitude-list (list '(A 2) '(NA 16) 
                                   '(BOOM 1) '(SHA 3) 
                                   '(GET 2)  '(YIP 9)
                                   '(JOB 2)  '(WAH 1)))
; ((A 2) (NA 16) (BOOM 1) (SHA 3) (GET 2) (YIP 9) (JOB 2) (WAH 1))

(define lyric-tree (generate-huffman-tree lyric-magnitude-list))
; ((leaf NA 16) ((leaf YIP 9) (((leaf A 2) ((leaf WAH 1) (leaf BOOM 1) (WAH BOOM) 2) (A WAH BOOM) 4) ((leaf SHA 3) ((leaf JOB 2) (leaf GET 2) (JOB GET) 4) (SHA JOB GET) 7) (A WAH BOOM SHA JOB GET) 11) (YIP A WAH BOOM SHA JOB GET) 20) (NA YIP A WAH BOOM SHA JOB GET) 36)

(define the-lyric '(GET A JOB SHA NA NA NA NA NA NA NA NA GET A JOB SHA NA NA NA NA NA NA NA NA WAH YIP YIP YIP YIP YIP YIP YIP YIP YIP SHA BOOM))
the-lyric

(define encoded-lyric (encode-message the-lyric lyric-tree))
encoded-lyric
; (1 1 1 1 1 1 1 0 0 1 1 1 1 0 1 1 1 0 0 0 0 0 0 0 0 0 1 1 1 1 1 1 1 0 0 1 1 1 1 0 1 1 1 0 0 0 0 0 0 0 0 0 1 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 1 1 0 1 1 0 1 1)
; (length encoded-lyric)
; gosh> 84
; なのでhuffmanだと84ビット必要。
; 通常の8文字エンコードだと1文字3ビット必要なので
(* 3 (length the-lyric))
; gosh> 108
; 108ビット必要。


;; 2.71
(define five-letters-magnitude-list (list '(A 1) '(B 2) '(C 4) '(D 8) '(E 16)))
(define five-letters-huffman-tree (generate-huffman-tree five-letters-magnitude-list))
five-letters-huffman-tree
;gosh> (((((leaf A 1) (leaf B 2) (A B) 3) (leaf C 4) (A B C) 7) (leaf D 8) (A B C D) 15) (leaf E 16) (A B C D E) 31)
(encode-message '(B) five-letters-huffman-tree)

(define ten-letters-magnitude-list (list '(A 1) '(B 2) '(C 4) '(D 8) '(E 16)
                                         '(F 32) '(G 64) '(H 128) '(I 256) '(J 512)))
(define ten-letters-huffman-tree (generate-huffman-tree ten-letters-magnitude-list))
ten-letters-huffman-tree
;gosh> ((((((((((leaf A 1) (leaf B 2) (A B) 3) (leaf C 4) (A B C) 7) (leaf D 8) (A B C D) 15) (leaf E 16) (A B C D E) 31) (leaf F 32) (A B C D E F) 63) (leaf G 64) (A B C D E F G) 127) (leaf H 128) (A B C D E F G H) 255) (leaf I 256) (A B C D E F G H I) 511) (leaf J 512) (A B C D E F G H I J) 1023)

; 絵をかいた。

; (一般のnの)こういう木で, 最高頻度の記号を符号化するのに必要なビット数はいくらか. 最低頻度の記号ではどうか. 
; 最高頻度 1ビット
; 最低頻度 n - 1ビット　っぽい

; 2.72
; encode-symbolはビット数分増える その中で使っているhas-symbolもビット数分増える
; ので最低頻度の場合は (N - 1) * (N - 1) = N^2 - 2N + 1なので増加の程度で言うとN^2
; 最低頻度の場合は1ビットになるので 1(定数)
