;;; 3.3.5 制約の拡散
;; もうちょっと定義する順番どうにかならないのかな。
(define (celcius-fahrenheit-converter c f)
  (let ((u (make-connector))
        (v (make-connector))
        (w (make-connector))
        (x (make-connector))
        (y (make-connector)))
    (multiplier c w u)
    (multiplier v x u)
    (adder v y f)
    (constant 9 w)
    (constant 5 x)
    (constant 32 y)
    'ok))

(define C (make-connector))
(define F (make-connector))
(celcius-fahrenheit-converter C F)

(define (adder a1 a2 sum)
  (define (process-new-value)
    (cond ((and (has-value? a1) (has-value? a2))
           (set-value! sum
                       (+ (get-value a1) (get-value a2))
                       me))
          ((and (has-value? a1) (has-value? sum))
           (set-value! a2
                       (- (get-value sum) (get-value a1))
                       me))
          ((and (has-value? a2) (has-value? sum))
           (set-value! a1
                       (- (get-value sum) (get-value a2))
                       me))))
  (define (process-forget-value)
    (forget-value! sum me)
    (forget-value! a1 me)
    (forget-value! a2 me)
    (process-new-value))
  (define (me request)
    (cond ((eq? request 'I-have-a-value)
           (process-new-value))
          ((eq? request 'I-lost-my-value)
           (process-forget-value))
          (else
           (error "Unknown request -- ADDER" request))))
  (connect a1 me)
  (connect a2 me)
  (connect sum me)
  me)

(define (inform-about-value constraint)
  (constraint 'I-have-a-value))

(define (inform-about-no-value constraint)
  (constraint 'I-lost-my-value))


          
(define (multiplier m1 m2 product)
  (define (process-new-value)
    (cond ((or (and (has-value? m1) (= (get-value m1) 0))
               (and (has-value? m2) (= (get-value m2) 0)))
           (set-value! product 0 me))
          ((and (has-value? m1) (has-value? m2))
           (set-value! product
                       (* (get-value m1) (get-value m2))
                       me))
          ((and (has-value? product) (has-value? m1))
           (set-value! m2
                       (/ (get-value product) (get-value m1))
                       me))
          ((and (has-value? product) (has-value? m2))
           (set-value! m1
                       (/ (get-value product) (get-value m2))
                       me))))
  (define (process-forget-value)
    (forget-value! product me)
    (forget-value! m1 me)
    (forget-value! m2 me)
    (process-new-value))
  (define (me request)
    (cond ((eq? request 'I-have-a-value)
           (process-new-value))
          ((eq? request 'I-lost-my-value)
           (process-forget-value))
          (else
           (error "Unknown request -- MULTIPLIER" request))))
  (connect m1 me)
  (connect m2 me)
  (connect product me)
  me)

(define (constant value connector)
  (define (me request)
    (error "Unknown request -- CONSTANT" request))
  (connect connector me) ;; meどこから値入れるの？
  (set-value! connector value me)
  me)
           
          
(define (probe name connector)
  (define (print-probe value)
    (newline)
    (display "Probe: ")
    (display name)
    (display " = ")
    (display value))
  (define (process-new-value)
    (print-probe (get-value connector)))
  (define (process-forget-value)
    (print-probe "?"))
  (define (me request)
    (cond ((eq? request 'I-have-a-value)
           (process-new-value))
          ((eq? request 'I-lost-my-value)
           (process-forget-value))
          (else
           (error "Unknown request -- PROBE" request))))
  (connect connector me)
  me)

(define (make-connector)
  (let ((value false) (informant false) (constraints '()))
    (define (set-my-value newval setter)
      (cond ((not (has-value? me))
             (set! value newval)
             (set! informant setter)
             (for-each-except setter
                              inform-about-value
                              constraints))
            ((not (= value newval))
             (error "Contradiction" (list value newval)))
            (else 'ignored)))
    (define (forget-my-value retractor)
      (if (eq? retractor informant)
          (begin (set! informant false)
                 (for-each-except retractor
                                  inform-about-no-value
                                  constraints))
          'ignored))
    (define (connect new-constraint)
      (if (not (memq new-constraint constraints))
          (set! constraints
                (cons new-constraint constraints)))
      (if (has-value? me)
          (inform-about-value new-constraint))
      'done)
    (define (me request)
      (cond ((eq? request 'has-value?)
             (if informant true false))
            ((eq? request 'value) value)
            ((eq? request 'set-value!) set-my-value)
            ((eq? request 'forget) forget-my-value)
            ((eq? request 'connect) connect)
            (else (error "Unknown operation -- CONNECTOR"
                         request))))
    me))

(define (for-each-except exception procedure list)
  (define (loop items)
    (cond ((null? items) 'done)
          ((eq? (car items) exception) (loop (cdr items)))
          (else (procedure (car items))
                (loop (cdr items)))))
  (loop list))

(define (has-value? connector)
  (connector 'has-value?))

(define (get-value connector)
  (connector 'value))

(define (set-value! connector new-value informant)
  ((connector 'set-value!) new-value informant))

(define (forget-value! connector retractor)
  ((connector 'forget) retractor))

(define (connect connector new-constraint)
  ((connector 'connect) new-constraint))

;; ↓ここまで全部定義すると上のやつが動くような気がするのでやってみるコーナー
(define C (make-connector))
(define F (make-connector))
(celcius-fahrenheit-converter C F)
;; => ok
celcius-fahrenheit-converter
;; #<closure celcius-fahrenheit-converter>
(probe "Celsius temp" C)
;; #<closure (probe me)>
(probe "Fahrenheit temp" F)
;; #<closure (probe me)>
(set-value! C 25 'user)
;; Probe: Celsius temp = 25
;; Probe: Fahrenheit temp = 77
;; done
(set-value! F 212 'user)
;; *** ERROR: Contradiction (77 212)
(forget-value! C 'user)
;; Probe: Celsius temp = ?
;; Probe: Fahrenheit temp = ?done
;; うごいているっぽい

;; 3.33
;; こうかな
(define (averager a b c)
  (let ((u (make-connector))
        (v (make-connector)))
    (adder a b u)
    (multiplier u v c)
    (constant 0.5 v)
    'ok))
;; 試
(define A (make-connector))
(define B (make-connector))
(define C (make-connector))
(averager A B C)
;; => ok
(probe "Average output" C)
(set-value! A 10 'user)
(set-value! B 20 'user)
;; Probe: Average output = 15.0
(forget-value! A 'user)
;; Probe: Average output = ?
;; よさげ。


;; 3.34
;; multiplierは出口の値を決めると、手前の値を決められるけど
;; 平方根が入り口に来るような動作をしなくなってしまう。

;; 3.35 こんなかな。
(define (squarer a b)
  (define (process-new-value)
    (if (has-value? b)
        (if (< (get-value b) 0)
            (error "square less than 0 -- SQUARER" (get-value b))
            (set-value! a (sqrt (get-value b)) me)))
    (if (has-value? a)
        (set-value! b (* (get-value a) (get-value a)) me)))
  
  (define (process-forget-value)
    (forget-value! a me)
    (forget-value! b me)
    (process-new-value))

  (define (me request)
    (cond ((eq? request 'I-have-a-value)
           (process-new-value))
          ((eq? request 'I-lost-my-value)
           (process-forget-value))
          (else
           (error "Unknown Request -- SQUARER" request))))
  (connect a me)
  (connect b me)
  me)

;; 試
(define A (make-connector))
(define B (make-connector))
(define squarer-tester (squarer A B))
(probe "SQ output " B)
(probe "SQ input" A)
(set-value! A 10 'user)
;; Probe: SQ input = 10
;; Probe: SQ output  = 100done
(forget-value! A 'user)
;; Probe: SQ input = ?
;; Probe: SQ output  = ?done
(set-value! B 100 'user)
;; Probe: SQ output  = 100
;; Probe: SQ input = 10done

;; 3.37
;; celsius-fahrenheit-converter手続きは,

;; (define (celsius-fahrenheit-converter x)
;;   (c+ (c* (c/ (cv 9) (cv 5))
;;           x)
;;       (cv 32)))

;; (define C (make-connector))
;; (define F (celsius-fahrenheit-converter C))
;; のような, より式主導の定義の形と比べると, 煩わしい. ここでc+, c*などは算術演算の「制約」版である. 例えばc+は引数として二つのコネクタをとり, これらと加算制約で関係づけられたコネクタを返す:
;; (define (c+ x y)
;;   (let ((z (make-connector)))
;;     (adder x y z)
;;     z))

;;
(define (c+ x y)
  (let ((z (make-connector)))
    (adder x y z)
    z))
(define (c* x y)
  (let ((z (make-connector)))
    (multiplier x y z)
    z))
(define (c/ x y)
  (let ((z (make-connector)))
    (divider x y z)
    z))
(define (cv x)
  (let ((z (make-connector)))
    (constant x z)))
;; ここで逆数入れて逃げた割り算器を作らなければいけなくなった
(define (divider m1 m2 product)
  (define (process-new-value)
    (cond ((or (and (has-value? m1) (= (get-value m1) 0))
               (and (has-value? m2) (= (get-value m2) 0)))
           (set-value! product 0 me))
          ((and (has-value? m1) (has-value? m2))
           (set-value! product
                       (/ (get-value m1) (get-value m2))
                       me))
          ((and (has-value? product) (has-value? m1))
           (set-value! m2
                       (* (get-value product) (get-value m1))
                       me))
          ((and (has-value? product) (has-value? m2))
           (set-value! m1
                       (* (get-value product) (get-value m2))
                       me))))
  (define (process-forget-value)
    (forget-value! product me)
    (forget-value! m1 me)
    (forget-value! m2 me)
    (process-new-value))
  (define (me request)
    (cond ((eq? request 'I-have-a-value)
           (process-new-value))
          ((eq? request 'I-lost-my-value)
           (process-forget-value))
          (else
           (error "Unknown request -- DIVIDER" request))))
  (connect m1 me)
  (connect m2 me)
  (connect product me)
  me)

;; 試
(define (celsius-fahrenheit-converter x)
  (c+ (c* (c/ (cv 9) (cv 5))
          x)
      (cv 32)))

(define C (make-connector))
(define F (celsius-fahrenheit-converter C))
;; いいような気がするけど動かない謎
;; *** ERROR: Unknown request -- CONSTANT connect
