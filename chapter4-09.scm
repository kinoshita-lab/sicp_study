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
		   (not (same ?person ?person)))
