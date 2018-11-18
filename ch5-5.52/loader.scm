#!/usr/bin/env gosh

(load "./ch5-compiler.scm")

(define (write-with-newline code file)
  (define (iter code)
    (if (null? code)
        (close-output-port file)
        (begin
          (write (car code) file)
          (write-char #\newline file)
          (iter (cdr code)))))
  (iter code))

;; ファイルに書くやつ作った
(define (output-compiled-result c)
  (let ((file (open-output-file "compiled.out")))
    (write-with-newline c file)))

;; 最初に出る (env) とかがいらないのでけずる
(define (strip-output c)
  (caddr c))

;; まず簡単なやつ
(define compiled-constant
  (compile
   '1
   'val
   'return))
  

;; できたらfactorialでいけるようにしたい。
(define compiled-fact
  (compile
   '(define (factorial n)
      (if (= n 1)
          1
          (* (factorial (- n 1)) n)))
   'val
   'next))

;; 他にもやることあった。複数の関数の実験
(define compiled-multi-function
  (compile
   '(begin
      (define (f1 a)
        (+ a 1))
      (define (f2 a)
        (* a 2)))
   'val
   'next))

(define compiled-tagged-list
  (compile
    '(define (tagged-list? exp tag)
      (if (pair? exp)
        (eq? (car exp) tag)
        false))
        'val
        'next))
  
;; 最終目標
(load "./ch4-mceval.scm")
(define compiled-mceval (compile mceval 'val 'next))
(output-compiled-result (strip-output compiled-fact))

;; (define (main args)
;;   (output-compiled-result (strip-output compiled-fact))
;;   0)

;; (define (main args)
;;   (output-compiled-result (strip-output compiled-multi-function))
;;   0)

(define (main args)
  (output-compiled-result (strip-output compiled-mceval))
  0)

;; (define (main args)
;;    (output-compiled-result (strip-output compiled-tagged-list))
;;    0)





  
