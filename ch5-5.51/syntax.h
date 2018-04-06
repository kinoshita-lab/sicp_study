#pragma once
#include "types.h"

/*
;;;;SCHEME SYNTAX FROM SECTION 4.1.2 OF STRUCTURE AND INTERPRETATION OF
;;;  COMPUTER PROGRAMS, TO SUPPORT CHAPTER 5
;;;;Loaded by compiler.scm (for use by compiler), and by eceval-support.scm
;;;; (for simulation of eceval machine operations)

(define (self-evaluating? exp)
  (cond ((number? exp) true)
        ((string? exp) true)
        (else false)))


(define (quoted? exp)
  (tagged-list? exp 'quote))

(define (text-of-quotation exp) (cadr exp))

(define (tagged-list? exp tag)
  (if (pair? exp)
      (eq? (car exp) tag)
      false))


(define (variable? exp) (symbol? exp))

(define (assignment? exp)
  (tagged-list? exp 'set!))

(define (assignment-variable exp) (cadr exp))

(define (assignment-value exp) (caddr exp))


(define (definition? exp)
  (tagged-list? exp 'define))

(define (definition-variable exp)
  (if (symbol? (cadr exp))
      (cadr exp)
      (caadr exp)))

(define (definition-value exp)
  (if (symbol? (cadr exp))
      (caddr exp)
      (make-lambda (cdadr exp)
                   (cddr exp))))

(define (lambda? exp) (tagged-list? exp 'lambda))

(define (lambda-parameters exp) (cadr exp))
(define (lambda-body exp) (cddr exp))

(define (make-lambda parameters body)
  (cons 'lambda (cons parameters body)))

(define (if? exp) (tagged-list? exp 'if))

(define (if-predicate exp) (cadr exp))

(define (if-consequent exp) (caddr exp))

(define (if-alternative exp)
  (if (not (null? (cdddr exp)))
      (cadddr exp)
      'false))


(define (begin? exp) (tagged-list? exp 'begin))
(define (begin-actions exp) (cdr exp))

(define (last-exp? seq) (null? (cdr seq)))
(define (first-exp seq) (car seq))
(define (rest-exps seq) (cdr seq))

(define (application? exp) (pair? exp))
(define (operator exp) (car exp))
(define (operands exp) (cdr exp))

(define (no-operands? ops) (null? ops))
(define (first-operand ops) (car ops))
(define (rest-operands ops) (cdr ops))

;;;**following needed only to implement COND as derived expression,
;;; not needed by eceval machine in text.  But used by compiler

;; from 4.1.2
(define (make-if predicate consequent alternative)
  (list 'if predicate consequent alternative))


(define (sequence->exp seq)
  (cond ((null? seq) seq)
        ((last-exp? seq) (first-exp seq))
        (else (make-begin seq))))

(define (make-begin seq) (cons 'begin seq))

(define (cond? exp) (tagged-list? exp 'cond))
(define (cond-clauses exp) (cdr exp))
(define (cond-else-clause? clause)
  (eq? (cond-predicate clause) 'else))
(define (cond-predicate clause) (car clause))
(define (cond-actions clause) (cdr clause))

(define (cond->if exp)
  (expand-clauses (cond-clauses exp)))

(define (expand-clauses clauses)
  (if (null? clauses)
      'false                          ; no else clause
      (let ((first (car clauses))
            (rest (cdr clauses)))
        (if (cond-else-clause? first)
            (if (null? rest)
                (sequence->exp (cond-actions first))
                (error "ELSE clause isn't last -- COND->IF"
                       clauses))
            (make-if (cond-predicate first)
                     (sequence->exp (cond-actions first))
                     (expand-clauses rest))))))
;; end of Cond support
*/
bool self_evaluating_p(SchemeDataType* const exp);
bool quoted_p(SchemeDataType* const exp);
SchemeDataType* text_of_quotation(SchemeDataType* const exp);

bool tagged_list_p(SchemeDataType* const exp, const char* tag);
bool variable_p(SchemeDataType* const exp);
bool assignment_p(SchemeDataType* const exp);

SchemeDataType* assignment_variable(SchemeDataType* const exp);
SchemeDataType* assignment_value(SchemeDataType* const exp);

bool definition_p(SchemeDataType* const exp);
SchemeDataType* definition_variable(SchemeDataType* const exp);
SchemeDataType* definition_value(SchemeDataType* const exp);

bool lambda_p(SchemeDataType* const exp);
SchemeDataType* lambda_parameters(SchemeDataType* const exp);
SchemeDataType* lambda_boty(SchemeDataType* const exp);
SchemeDataType* make_lambda(SchemeDataType* const parameters, SchemeDataType* const body);

bool if_p(SchemeDataType* const exp);
SchemeDataType* if_predicate(SchemeDataType* const exp);
SchemeDataType* if_consequent(SchemeDataType* const exp);
SchemeDataType* if_alternative(SchemeDataType* const exp);

bool begin_p(SchemeDataType* const exp);
SchemeDataType* begin_actions(SchemeDataType* const exp);
bool last_exp_p(SchemeDataType* const seq);
SchemeDataType* first_exp(SchemeDataType* const seq);
SchemeDataType* rest_exps(SchemeDataType* const seq);

bool application_p(SchemeDataType* const exp);
bool no_operands(SchemeDataType* const ops);
SchemeDataType* operator_(SchemeDataType* const exp);
SchemeDataType* operands(SchemeDataType* const exp);

bool no_operands_p(SchemeDataType* const ops);
SchemeDataType* first_operand(SchemeDataType* const ops);
SchemeDataType* rest_operands(SchemeDataType* const ops);

SchemeDataType* make_if(SchemeDataType* const predicate, SchemeDataType* const consequent, SchemeDataType* const alternative);
SchemeDataType* sequence_to_exp(SchemeDataType* seq);
SchemeDataType* make_begin(SchemeDataType* const seq);

bool cond_p(SchemeDataType* const exp);
SchemeDataType* cond_clauses(SchemeDataType* const exp);
bool cond_else_clause_p(SchemeDataType* const clause);
SchemeDataType* cond_predicate(SchemeDataType* const clause);
SchemeDataType* cond_actions(SchemeDataType* const clause);

SchemeDataType* cond_to_if(SchemeDataType* const exp);
SchemeDataType* const expand_clauses(SchemeDataType* const clause);