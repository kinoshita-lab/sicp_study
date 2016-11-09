;; https://mitpress.mit.edu/sicp/code/index.html
;; ここでAMB評価器を発見した・・・
(add-load-path "code_from_text" :relative)
(load "ch4-ambeval.scm")
(define true #t)
(define false #f)
(define the-global-environment (setup-environment))
(driver-loop)
;;;;Then you can initialize and start the evaluator by evaluating
;;;; the two lines at the end of the file ch4-mceval.scm
;;;; (setting up the global environment and starting the driver loop).
;;;;In the driver loop, do
(define (require p)
  (if (not p) (amb)))
;; 自然言語の構文解析

;; こいつらはAMB評価器で実行する必要がありだるい
(define nouns '(noun student professor cat class))
(define verbs '(verb studies lectures eats sleeps))
(define articles '(article the a))

(define (parse-sentence)
  (list 'sentence
		(parse-noun-phrase)
		(parse-word verbs)))
(define (parse-noun-phrase)
  (list 'noun-phrase
		(parse-word articles)
		(parse-word nouns)))
(define (parse-word word-list)
  (require (not (null? *unparsed*)))
  (require (memq (car *unparsed*) (cdr word-list)))
  (let ((found-word (car *unparsed*)))
	(set! *unparsed* (cdr *unparsed*))
	(list (car word-list) found-word)))
(define *unparsed* '())
(define (parse input)
  (set! *unparsed* input)
  (let ((sent (parse-sentence)))
	(require (null? *unparsed*)) sent))

(define prepositions '(prep for to in by with))
(define (parse-prepositional-phrase)
  (list 'prep-phrase
		(parse-word prepositions)
		(parse-noun-phrase)))

(define (parse-sentence)
  (list 'sentence (parse-noun-phrase) (parse-verb-phrase)))
(define (parse-verb-phrase)
  (define (maybe-extend verb-phrase)
	(amb verb-phrase
		 (maybe-extend
		  (list 'verb-phrase
				verb-phrase
				(parse-prepositional-phrase )))))
  (maybe-extend (parse-word verbs)))
(define (parse-simple-noun-phrase)
  (list 'simple-noun-phrase
		(parse-word articles)
		(parse-word nouns)))
(define (parse-noun-phrase)
  (define (maybe-extend noun-phrase)
	(amb noun-phrase
		 (maybe-extend
		  (list 'noun-phrase
				noun-phrase
				(parse-prepositional-phrase )))))
  (maybe-extend (parse-simple-noun-phrase)))
(parse '(the student with the cat sleeps in the class))

(parse '(the professor lectures to the student with the cat))

;; 4.45
(parse '(the professor lectures to the student in the class with the cat))
try-again
try-again
try-again
try-again
try-again
;; ;;; Starting a new problem 
;; ;;; Amb-Eval value:s
;; (sentence (simple-noun-phrase (article the) (noun professor)) (verb-phrase (verb-phrase (verb-phrase (verb lectures) (prep-phrase (prep to) (simple-noun-phrase (article the) (noun student)))) (prep-phrase (prep in) (simple-noun-phrase (article the) (noun class)))) (prep-phrase (prep with) (simple-noun-phrase (article the) (noun cat)))))

;; ;;; Amb-Eval input:

;; ;;; Amb-Eval value:
;; (sentence (simple-noun-phrase (article the) (noun professor)) (verb-phrase (verb-phrase (verb lectures) (prep-phrase (prep to) (simple-noun-phrase (article the) (noun student)))) (prep-phrase (prep in) (noun-phrase (simple-noun-phrase (article the) (noun class)) (prep-phrase (prep with) (simple-noun-phrase (article the) (noun cat)))))))

;; ;;; Amb-Eval input:

;; ;;; Amb-Eval value:
;; (sentence (simple-noun-phrase (article the) (noun professor)) (verb-phrase (verb-phrase (verb lectures) (prep-phrase (prep to) (noun-phrase (simple-noun-phrase (article the) (noun student)) (prep-phrase (prep in) (simple-noun-phrase (article the) (noun class)))))) (prep-phrase (prep with) (simple-noun-phrase (article the) (noun cat)))))

;; ;;; Amb-Eval input:

;; ;;; Amb-Eval value:
;; (sentence (simple-noun-phrase (article the) (noun professor)) (verb-phrase (verb lectures) (prep-phrase (prep to) (noun-phrase (noun-phrase (simple-noun-phrase (article the) (noun student)) (prep-phrase (prep in) (simple-noun-phrase (article the) (noun class)))) (prep-phrase (prep with) (simple-noun-phrase (article the) (noun cat)))))))

;; ;;; Amb-Eval input:

;; ;;; Amb-Eval value:
;; (sentence (simple-noun-phrase (article the) (noun professor)) (verb-phrase (verb lectures) (prep-phrase (prep to) (noun-phrase (simple-noun-phrase (article the) (noun student)) (prep-phrase (prep in) (noun-phrase (simple-noun-phrase (article the) (noun class)) (prep-phrase (prep with) (simple-noun-phrase (article the) (noun cat)))))))))

;; ;;; Amb-Eval input:

;; ;;; There are no more values of
;; (parse '(the professor lectures to the student in the class with the cat))


;; 4.46
;; 構文評価は頭からやらないとできないやん。

;; 4.47
; maybe-extend をつかわない方式ってことね。
; parse-simple-nown-phraseとにたようなかんじになるってことか。
; 「あるかもしれないしないかもしれない」を削ると動詞と前置詞句がかならず無いと構文解析できないものになりそう。

;; 4.48
; あんまよくわかってないから形容詞でも入れてみよう
; noun phrase が article adjective noun になるやつをつくってみる

(define adjectives '(adjective red good ugly sleepy))

(define (parse-simple-noun-phrase)
  (list 'simple-noun-phrase
		(parse-word articles)
		(parse-word nouns)))
;; これでいいような気がするので試
(parse '(the good student with the red cat sleeps in the ugly class))
;;; Amb-Eval value:
;; (sentence (noun-phrase (simple-noun-phrase (article the) (adjective good) (noun student)) (prep-phrase (prep with) (simple-noun-phrase (article the) (adjective red) (noun cat)))) (verb-phrase (verb sleeps) (prep-phrase (prep in) (simple-noun-phrase (article the) (adjective ugly) (noun class)))))
;; ただこうするとかならず形容詞が必要になっちゃう
;; まいっか。
