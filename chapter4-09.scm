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
