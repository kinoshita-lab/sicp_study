#!/usr/bin/env gosh

(load "./ch5-compiler.scm")

(define output-file-name "compiled.out")
;; ファイルに書くやつ作った
(define (output-compiled-result c)
  (let ((file (open-output-file "compiled.out")))
    (begin
      (write c file)
      (close-output-port file))))

;; まず簡単なやつ
(define compiled-constant
  (compile
   '1
   'val
   'next))

;; (define (main args)
;;   (output-compiled-result compiled-constant)
;;   0)
  

;; できたらfactorialでいけるようにしたい。
(define compiled-fact
  (compile
   '(define (factorial n)
      (if (= n 1)
          1
          (* (factorial (- n 1)) n)))
   'val
   'next))
  
;; 最終目標
(load "./ch4-mceval.scm")
(define compiled-mceval (compile mceval 'val 'next))
(output-compiled-result compiled-mceval)

(define (main args)
  (output-compiled-result compiled-mceval)
  0)



  
