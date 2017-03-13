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


;; 4.60
;;lives-nearを追加
(assert! (rule (lives-near ?person-1 ?person-2 )
			   (and (address ?person-1 (?town . ?rest-1 ))
					(address ?person-2 (?town . ?rest-2 ))
					(not (same ?person-1 ?person-2 )))))
;; sameも追加
(assert! (rule (same ?x ?x)))

;; 試
(lives-near ?x (Bitdiddle Ben))
;; ;;; Query results:
;; (lives-near (Aull DeWitt) (Bitdiddle Ben))
;; (lives-near (Reasoner Louis) (Bitdiddle Ben))

;; 問題の
(lives-near ?person-1 ?person-2)
;;; Query results:
;; (lives-near (Aull DeWitt) (Reasoner Louis))
;; (lives-near (Aull DeWitt) (Bitdiddle Ben))
;; (lives-near (Reasoner Louis) (Aull DeWitt))
;; (lives-near (Reasoner Louis) (Bitdiddle Ben))
;; (lives-near (Hacker Alyssa P) (Fect Cy D))
;; (lives-near (Fect Cy D) (Hacker Alyssa P))
;; (lives-near (Bitdiddle Ben) (Aull DeWitt))
;; (lives-near (Bitdiddle Ben) (Reasoner Louis))
;; こうなる。
;; なぜ起こるのか？ person-1に誰かが入ってる時とperson-2に誰かが入ってる時両方でクエリが
;; 呼ばれてしまうから。
;; 
;; 1回しかあらわれないようにするには？
;; 表示したやつをputのlistとかに入れといて、交換したやつがすでにlistに入ってれば出さない、 とかやればいいような気がする
;; あんまり普遍的ではないけど。
;; 説明した からいいのかなこれで。

;; プログラムとしての論理
;; interpreter再起動
(load "./chapter4-queryeval.scm")
(assert! (rule (append-to-form () ?y ?y)))
(assert! (rule (append-to-form (?u . ?v) ?y (?u . ?z))
			   (append-to-form ?v ?y ?z)))

(append-to-form (a b) (c d) ?z)
;;; Query results:
;; (append-to-form (a b) (c d) (a b c d))
;;
;;
(append-to-form (a b) ?y (a b c d))
;;; Query results:
;;(append-to-form (a b) (c d) (a b c d))
(append-to-form ?x ?y (a b c d))
;; ;;; Query results:
;; (append-to-form (a b c d) () (a b c d))
;; (append-to-form () (a b c d) (a b c d))
;; (append-to-form (a) (b c d) (a b c d))
;; (append-to-form (a b) (c d) (a b c d))
;; (append-to-form (a b c) (d) (a b c d))

;; 4.61
;; ルールを追加
(assert! (rule (?x next-to ?y in (?x ?y . ?u))))
(assert! (rule (?x next-to ?y in (?v . ?z))
			   (?x next-to ?y in ?z)))

(?x next-to ?y in (1 (2 3) 4))
;;; Query results:
;; ((2 3) next-to 4 in (1 (2 3) 4))
;; (1 next-to (2 3) in (1 (2 3) 4))

(?x next-to 1 in (2 1 3 1))
;;; Query results:
;; (3 next-to 1 in (2 1 3 1))
;; (2 next-to 1 in (2 1 3 1))
;; すげー 
;; ちょっと試
(?x next-to 1 in (2 1 3 1 2 1 3 1))
;;; Query results:
;; (3 next-to 1 in (2 1 3 1 2 1 3 1))
;; (2 next-to 1 in (2 1 3 1 2 1 3 1))
;; (3 next-to 1 in (2 1 3 1 2 1 3 1))
;; (2 next-to 1 in (2 1 3 1 2 1 3 1))

;; appendのとこをよく把握しとく必要あるな
(load "./chapter4-queryeval.scm")
(rule (append-to-form () ?y ?y)) ;; 任意のリスト y について、空リストと y を append すると y になる。 のrule
(rule (append-to-form (?u . ?v) ?y (?u . ?z)) ;; (cons u v) と y を append すると (cons u z) になる。
	  (append-to-form ?v ?y ?z)) ;; ;; v と y を append すると z になるならば

;; last-pair は 最後のやつを表示するやつだった
;; (last-pair (1 2 3 4)) => (4) みたいな
;; これをappend風にあらわす。 2番目のruleはなぜ逆なのだろう。逆にするとどうなるんだ？
;; interpreter再起動
(load "./chapter4-queryeval.scm")
(assert! (rule (append-to-form () ?y ?y))) ;; 任意のリスト y について、空リストと y を append すると y になる。 のrule
(assert! (rule (append-to-form ?v ?y ?z) ;; ;; v と y を append すると z になるならば
			   (append-to-form (?u . ?v) ?y (?u . ?z)))) ;; (cons u v) と y を append すると (cons u z) になる。
;; 答かえってこなくなった

;; 4.62
;; append風にあらわせればいいってことだ
(load "./chapter4-queryeval.scm")
(assert! (rule (last-pair (?y . ()) (?y)))) ; 任意のリストyについて、 (cons y '()) の last-pairはyになる のrule
(assert! (rule (last-pair (?u . ?v) ?z) ;; (cons u v) の last-pair がzになるならば  
			   (last-pair ?v ?z)))    ;;  vのlast-pairはzになる

(last-pair (3) ?x)
;;; Query results:
;; (last-pair (3) (3))


(last-pair (1 2 3) ?x)
;;; Query results:
;; (last-pair (1 2 3) (3))

(last-pair (2 ?x) (3))
;;; Query results:
;; (last-pair (2 3) (3))

;; ↓ 実行注意!
;; (last-pair ?x (3))
;; 返事がかえってこなくなった
;; 「last-pairが 3 になるリスト全て」 というのは無限にあるから答えがかえってこなくなった。


;; 4.63
;; interpreter再起動
(load "./chapter4-queryeval.scm")
;; データベースつくる
(assert! (son Adam Cain))
(assert! (son Cain Enoch ))
(assert! (son Enoch Irad))
(assert! (son Irad Mehujael))
(assert! (son Mehujael Methushael))
(assert! (son Methushael Lamech))
(assert! (wife Lamech Ada))
(assert! (son Ada Jabal))
(assert! (son Ada Jubal))

(son ?x ?y)
;; ;;; Query results:
;; (son Ada Jubal)
;; (son Ada Jabal)
;; (son Methushael Lamech)
;; (son Mehujael Methushael)
;; (son Irad Mehujael)
;; (son Enoch Irad)
;; (son Cain Enoch)
;; “もし S が f の息子であり、かつ、f が G の息子ならば、S は Gの孫である”
(assert! (rule (grandson ?g ?s)
			   (and (son ?g ?u)
					(son ?u ?s))))
(grandson Adam ?x)
;; (grandson Adam Enoch)
;; “もし W が M の妻であり、かつ、S が W の息子ならば、S は M の息子である”
(assert! (rule (son-m ?w ?s)
			   (and (wife ?w ?h)
					(son ?h ?s))))

(son-m Lamech ?x)
;;; Query results:
;; (son-m Lamech Jubal)
;; (son-m Lamech Jabal)


;; 4.64
;; interpreter再起動
(load "./chapter4-queryeval.scm")

;; Louisのoutranked-by
;; (rule (outranked-by ?staff-person ?boss)
;; 	  (or (supervisor ?staff-person ?boss)
;; 		  (and (outranked-by ?middle-manager ?boss)
;; 			   (supervisor ?staff-person
;; 						   ?middle-manager))))
;; もともとの
;; (rule (outranked-by ?staff-person ?boss)
;; 	  (or (supervisor ?staff-person ?boss)
;; 		  (and (supervisor ?staff-person
;; 						   ?middle-manager)
;; 			   (outranked-by ?middle-manager ?boss))));

;; ちがうのはandの条件の順番
;;  (outranked-by ?middle-manager ?boss)
;; がパターン変数が何にも束縛されないで呼ばれちゃうから無限になってしまう。
;; もともとのやつだと1番目の条件できまったストリームを、削るためにつかってた。

;; 4.65
;; wheelはこんなかんじ
;; (rule (wheel ?person)
;; 	  (and (supervisor ?middle-manager ?person)
;; 		   (supervisor ?x ?middle-manager)))
;; 条件に合えば有効な結果として表示されるようになっているので、
;; Warbucks Oliverが色々な人のsupervisorだと、このようになる。
