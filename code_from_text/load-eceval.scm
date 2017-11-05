;;;; LOADS THE EXPLICIT-CONTROL EVALUATOR FROM SECTION 5.4 OF
;;;; STRUCTURE AND INTERPRETATION OF COMPUTER PROGRAMS, WITH
;;;; ALL THE SUPPORTING CODE IT NEEDS IN ORDER TO RUN.

;;;; **NB** The actual "load" calls are implementation dependent.

(load "./code_from_text/ch5-regsim.scm")			;reg machine simulator

;; **NB** next file contains another "load"
(load "./code_from_text/ch5-eceval-support.scm")		;simulation of machine operations

(load "./code_from_text/ch5-eceval.scm")			;eceval itself


(define the-global-environment (setup-environment))
