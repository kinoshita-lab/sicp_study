;; 4.55

; 1
(suprervisor ?x (Bitdiddle Ben))
; 2
(job ?x (accounting . ?type))
; 3
(address ?x (Slummerville . ?address))

;; 4.56 なんでabcになった
;a
(and (supervisor ?x (Bitdiddle Ben))
	 (address ?x ?where))
;b これでben含まれるけどいいのかな
(or (salary ?person ?amount) (lisp-value <= ?amount 60000)

;c
(and (not (job ?x (computer . ?type)))
	 (supervisor ?x ?y)
	 (job ?x ?z))

;; 4.57
; a.
(can-do-job ?name (job (Fect Cy D)))

; b.
; 謎。答えみても謎。a.も違うっぽい

;; 4.58
;; これも違うとおもう。感覚がよくわかってない
(rule (big-shot ?person)
	  (and (not (supervisor ?person ?boss))
		   (not (same ?person ?person))))
;; ということでquery evaluatorの動くものを実装した。

(load "./chapter4-queryeval.scm")


;; 4.59 会議を追加
(assert! (meeting accounting (Monday 9am)))
(assert! (meeting administration (Monday 10 am)))
(assert! (meeting computer (Wednesday 3pm)))
(assert! (meeting administration (Friday 1pm )))
(assert! (meeting whole-company (Wednesday 4pm )))

;; a. 金曜の朝、Ben はその日にあるすべての会議についてデータ
;; ベースに問い合わせようと思った。彼はどのようなクエリを
;; 使うべきだろうか。
(meeting ?job (Friday ?time))
;; ;;; Query results:
;; (meeting administration (Friday 1pm))

;; b. Alyssa P. Hacker は、このやり方はあまりよくないと思った。
;; 彼女は、自分の名前を指定して自分の会議について聞くこと
;; ができたほうがずっと便利だろうと考えた。そこで、彼女は
;; 規則を設計することにした。その規則は、ある人の会議は全
;; 社 (whole-company) 会議とその人の部門会議をすべて含むと
;; いうものだ。Alyssa の規則に本体を補え。

;; 全社
(meeting whole-company ?day-and-time)

;; 個別 ;;これでいけそうだけど動かないぞ ー> andをputしてなかったし実装が違った
(and (job ?person (?section . ?hoge))
	 (meeting ?section (?day . ?fuga)))

(assert! (rule (meeting-time ?person ?day-and-time)
			   (or (meeting whole-company ?day-and-time))
			   (and (job ?person (?section . ?hoge))
					(meeting ?section (?day . ?fuga)))))

;; c. Alyssa は水曜の朝に職場に着き、その日にどんな会議がある
;; か考えた。上記の規則を定義してあるとして、この検索を行
;; うには、彼女はどのようなクエリを作るべきだろうか。
(meeting-time (Hacker Alyssa P) (Wednesday ?hoge))

