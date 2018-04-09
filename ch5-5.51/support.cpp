#include "support.h"
#include "cons_man.h"
#include "syntax.h"

/**
;;following compound-procedure operations not used by compiled code
(define (make-procedure parameters body env)
  (list 'procedure parameters body env))
  */
SchemeDataType* make_procedure(SchemeDataType* const parameters, SchemeDataType* const body, SchemeDataType* const env)
{
    SchemeDataType* r = new SchemeDataType(SchemeDataType::Cons);
    r->cellValue->car = new SchemeDataType(SchemeDataType::Symbol, "procedure");
    
    SchemeDataType* b = new SchemeDataType(SchemeDataType::Cons);
    b->cellValue->car = body;
    r->cellValue->listPush(b);   
    
    SchemeDataType* e = new SchemeDataType(SchemeDataType::Cons);
    r->cellValue->listPush(e);
    
    return r;    
}

/**
(define (empty-arglist) '())
*/
SchemeDataType* empty_arglist()
{
    SchemeDataType* r = new SchemeDataType(SchemeDataType::Cons);
    r->cellValue->car = new SchemeDataType(SchemeDataType::Nil);
    return r;
}

/**
(define (adjoin-arg arg arglist)
  (append arglist (list arg)))
  */
SchemeDataType* adjoin_arg(SchemeDataType* const arg, SchemeDataType* const arglist)
{
    return append(arglist, arg);    
}

/**
(define (procedure-parameters p) (cadr p))
*/
SchemeDataType* procedure_parameters(SchemeDataType* const p)
{
    return cadr(p);    
}


/**
(define (procedure-body p) (caddr p))
*/
SchemeDataType* procedure_body(SchemeDataType* const p)
{
    return caddr(p);    
}


/**
(define (procedure-environment p) (cadddr p))
*/
SchemeDataType* procedure_environment(SchemeDataType* const p)
{
    return cadddr(p);    
}


/**
(define (true? x)
  (not (eq? x false)))
 */
bool true_p(SchemeDataType* const x)
{
    if (x->type != SchemeDataType::SchemeBoolean) {
        return true;        
    }

    return x->booleanValue == SchemeDataType::SchemeBooleanValue::True;    
}

/**
 (define (last-operand? ops)
  (null? (cdr ops)))
 */
bool last_operand_p(SchemeDataType* const ops)
{
    return cdr(ops)->type == SchemeDataType::Nil;    // 違うかも
}

/**
 (define (primitive-procedure? proc)
  (tagged-list? proc 'primitive))
 */
bool primitive_procedure_p(SchemeDataType* const proc)
{
    return tagged_list_p(proc, "primitive");
}

/**
(define (compound-procedure? p)
  (tagged-list? p 'procedure))
 */
bool compound_procedure_p(SchemeDataType* const p)
{
    return tagged_list_p(p, "procedure");    
}









