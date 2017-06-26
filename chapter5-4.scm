;; 5.23
;; cond->ifやったなあ。なつかしい
(define (cond? exp)
  #?=(exp)
  (tagged-list? exp 'cond))
(define (cond-clauses exp) (cdr exp))
(define (cond-else-clause? clause)
  (eq? (cond-predicate clause) 'else))
(define (cond-predicate clause) (car clause))
(define (cond-actions clause) (cdr clause))
(define (cond->if exp) (expand-clauses (cond-clauses exp)))
(define (expand-clauses clauses)
  (if (null? clauses)
      'false
      (let ((first (car clauses))
            (rest (cdr clauses)))
        (if (cond-else-clause? first)
            (if (null? rest)
                (sequence->exp (cond-actions first))
                (error "ELSE clause isn't last: COND->IF" clauses))
            (make-if (cond-predicate first)
                     (sequence->exp (cond-actions first))
                     (expand-clauses rest))))))

(load "./code_from_text/load-eceval.scm")
;; eceval-operationsを改造しておいた
(start eceval)

;;; EC-Eval input:
(cond ((= 1 2) #t) (else #f))
;; unknown-expression-type-error
;; わからん。

;; expの中はこんなんなってた。
;; (cond ((= 1 2) #t) (else #f))(= 1 2)=12#

