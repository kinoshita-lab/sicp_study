#include <iostream>
#include "syntax.h"
#include "types.h"
#include "cons_man.h"

using namespace std;

/*
(define (self-evaluating? exp)
  (cond ((number? exp) true)
        ((string? exp) true)
        (else false)))
*/
bool self_evaluating_p(SchemeDataType* const exp)
{	
	return exp->type == SchemeDataType::Integer || exp->type == SchemeDataType::String;
}

/*
(define (quoted? exp)
  (tagged-list? exp 'quote))
*/
bool quoted_p(SchemeDataType* const exp)
{
    return (tagged_list_p(exp, "quote"));
}

/*
 (define (text-of-quotation exp) (cadr exp))
*/
SchemeDataType* text_of_quotation(SchemeDataType* const exp)
{
    return cadr(exp);
}

/*
(define (tagged-list? exp tag)
  (if (pair? exp)
      (eq? (car exp) tag)
      false))
*/
bool tagged_list_p(SchemeDataType* const exp, const char* tag)
{
    if (pair_p(exp)) {
        return eq_p(car(exp), new SchemeDataType(SchemeDataType::Symbol, tag));
    }

    return false;
}

/*
 (define (variable? exp) (symbol? exp))
*/
bool variable_p(SchemeDataType* const exp)
{
    return symbol_p(exp);
}

/*
 (define (assignment? exp)
   (tagged-list? exp 'set!))
 */
bool assignment_p(SchemeDataType* const exp)
{
    return tagged_list_p(exp, "set!");
}

/*
 (define (assignment-variable exp) (cadr exp))
 */
SchemeDataType* assignment_variable(SchemeDataType* const exp)
{
    return cadr(exp);
}

/*
 (define (assignment-value exp) (caddr exp))
 */
SchemeDataType* assignment_value(SchemeDataType* const exp)
{
    return caddr(exp);
}

/*
(define (definition? exp)
  (tagged-list? exp 'define))
 */
bool definition_p(SchemeDataType* const exp)
{
    return tagged_list_p(exp, "define");
}

/*
(define (definition-variable exp)
  (if (symbol? (cadr exp))
      (cadr exp)
      (caadr exp)))
*/
SchemeDataType* definition_variable(SchemeDataType* const exp)
{
    if (symbol_p(cadr(exp))) {
        return cadr(exp);
    }

    return caadr(exp);
}

/*
(define (definition-value exp)
  (if (symbol? (cadr exp))
      (caddr exp)
      (make-lambda (cdadr exp)
                   (cddr exp))))
*/
SchemeDataType* definition_value(SchemeDataType* const exp)
{
    if (symbol_p(cadr(exp))) {
        return caddr(exp);
    }

    return make_lambda(cdadr(exp), cddr(exp));
}

/*
 (define (lambda? exp) (tagged-list? exp 'lambda))
 */
bool lambda_p(SchemeDataType* const exp)
{
    return tagged_list_p(exp, "lambda");
}

/*
 (define (lambda-parameters exp) (cadr exp))
 */
SchemeDataType* lambda_parameters(SchemeDataType* const exp)
{
    return cadr(exp);
}

/*
 (define (lambda-body exp) (cddr exp))
 */
SchemeDataType* lambda_boty(SchemeDataType* const exp)
{
    return cddr(exp);
}

/*
(define (make-lambda parameters body)
  (cons 'lambda (cons parameters body)))
 */
SchemeDataType* make_lambda(SchemeDataType* const parameters, SchemeDataType* const body)
{
    return cons(new SchemeDataType(SchemeDataType::String, "lambda"),
                (cons(parameters, body)));
}

/*
(define (if? exp) (tagged-list? exp 'if))
*/
bool if_p(SchemeDataType* const exp)
{
    return tagged_list_p(exp, "if");
}

/*
(define (if-predicate exp) (cadr exp))
*/
SchemeDataType* if_predicate(SchemeDataType* const exp)
{
    return cadr(exp);
}

/*
(define (if-consequent exp) (caddr exp))
*/
SchemeDataType* if_consequent(SchemeDataType* const exp)
{
    return caddr(exp);
}

/*
(define (if-alternative exp)
  (if (not (null? (cdddr exp)))
      (cadddr exp)
      'false))
*/
SchemeDataType* if_alternative(SchemeDataType* const exp)
{
    if (!null_p(cdddr(exp))) {
        return caddr(exp);
    }

    return new SchemeDataType(SchemeDataType::SchemeConstant, SchemeDataType::False);
}

/*
 (define (begin? exp) (tagged-list? exp 'begin))
 */
bool begin_p(SchemeDataType* const exp)
{
    return tagged_list_p(exp, "begin");
}

/*
 (define (begin-actions exp) (cdr exp))
 */
SchemeDataType* begin_actions(SchemeDataType* const exp)
{
    return cdr(exp);
}

/*
 (define (last-exp? seq) (null? (cdr seq)))
 */
bool last_exp_p(SchemeDataType* const seq)
{
    return null_p(cdr(seq));
}

/*
 (define (first-exp seq) (car seq))
 */
SchemeDataType* first_exp(SchemeDataType* const seq)
{
    return car(seq);
}
/*
 (define (rest-exps seq) (cdr seq))
 */
SchemeDataType* rest_exps(SchemeDataType* const seq)
{
    return cdr(seq);
}

/*
 (define (application? exp) (pair? exp))
 */
bool application_p(SchemeDataType* const exp)
{
    return pair_p(exp);
}

/*
 (define (operator exp) (car exp))
 */
SchemeDataType* operator_(SchemeDataType* const exp)
{
    return car(exp);
}

/*
 (define (operands exp) (cdr exp))
*/
SchemeDataType* operands(SchemeDataType* const exp)
{
    return cdr(exp);
}

/*
 (define (no-operands? ops) (null? ops))
 */
bool no_operands_p(SchemeDataType* const ops)
{
    return null_p(ops);
}

/*
 (define (first-operand ops) (car ops))
 */
SchemeDataType* first_operand(SchemeDataType* const ops)
{
    return car(ops);
}

/*
 (define (rest-operands ops) (cdr ops))
 */
SchemeDataType* rest_operands(SchemeDataType* const ops)
{
    return cdr(ops);
}

/*
(define (make-if predicate consequent alternative)
  (list 'if predicate consequent alternative))
  */
SchemeDataType* make_if(SchemeDataType* const predicate, SchemeDataType* const consequent, SchemeDataType* const alternative)
{
    return list(new SchemeDataType(SchemeDataType::String, "list"),
        consequent, alternative);
}

/*
(define (sequence->exp seq)
  (cond ((null? seq) seq)
        ((last-exp? seq) (first-exp seq))
        (else (make-begin seq))))
*/
SchemeDataType* sequence_to_exp(SchemeDataType* seq)
{
    if (null_p(seq)) {
        return seq;
    }

    if (last_exp_p(seq)) {
        return first_exp(seq);
    }

    return make_begin(seq);
}

/*
(define (make-begin seq) (cons 'begin seq))
*/
SchemeDataType* make_begin(SchemeDataType* const seq)
{
    return cons(new SchemeDataType(SchemeDataType::String, "begin"), seq);
}

/*
(define (cond? exp) (tagged-list? exp 'cond))
*/
bool cond_p(SchemeDataType* const exp)
{
    return tagged_list_p(exp, "cond");
}

/*
(define (cond-clauses exp) (cdr exp))
*/
SchemeDataType* cond_clauses(SchemeDataType* const exp)
{
    return cdr(exp);
}

/*
(define (cond-else-clause? clause)
  (eq? (cond-predicate clause) 'else))
*/
bool cond_else_clause_p(SchemeDataType* const clause)
{
    return eq_p(cond_predicate(clause), new SchemeDataType(SchemeDataType::String, "else"));
}

/*
(define (cond-predicate clause) (car clause))
*/
SchemeDataType* cond_predicate(SchemeDataType* const clause)
{
    return car(clause);
}

/*
(define (cond-actions clause) (cdr clause))
*/
SchemeDataType* cond_actions(SchemeDataType* const clause)
{
    return cdr(clause);
}

/*
(define (cond->if exp)
  (expand-clauses (cond-clauses exp)))
  */
SchemeDataType* cond_to_if(SchemeDataType* const exp)
{
    return expand_clauses(cond_clauses(exp));
}

/*
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
*/
SchemeDataType* const expand_clauses(SchemeDataType* const clauses)
{
    if (null_p(clauses)) {
        return new SchemeDataType(SchemeDataType::SchemeConstant, SchemeDataType::False);
    }

    auto* const first = car(clauses);
    auto* const rest = cdr(clauses);

    if (cond_else_clause_p(first)) {
        if (null_p(rest)) {
            return sequence_to_exp(cond_actions(first));
        } else {
            cout << "error ELSE clause isn't last -- COND->IF "  << clauses->to_s() << endl;
            return new SchemeDataType();
        }
    } else {
        return make_if(cond_predicate(first), sequence_to_exp(cond_actions(first)), expand_clauses(rest));
    }
}