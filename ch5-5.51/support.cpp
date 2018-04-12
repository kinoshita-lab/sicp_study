#include <iostream>
#include "support.h"
#include "cons_man.h"
#include "syntax.h"
#include "global.h"
#include "eceval.h"
#include "frames.h"
#include "env.h"

/**
;;following compound-procedure operations not used by compiled code
(define (make-procedure parameters body env)
  (list 'procedure parameters body env))
  */
SchemeDataType* make_procedure(SchemeDataType* const parameters, SchemeDataType* const body, SchemeDataType* const env)
{
    return list(4, new SchemeDataType(SchemeDataType::Symbol, "procedure"), parameters, body, env);
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

/**
 * (define (primitive-implementation proc) (cadr proc))
 */
SchemeDataType* primitive_implementation(SchemeDataType* const proc)
{
    return cadr(proc);
}


SchemeDataType* apply_primitive_implementation(SchemeDataType* const proc, SchemeDataType* const args)
{
    // todo impl
    return new SchemeDataType();
}

/**
 (define (apply-primitive-procedure proc args)
  (apply-in-underlying-scheme
   (primitive-implementation proc) args))
   */
SchemeDataType* apply_primitive_procedure(SchemeDataType* const proc, SchemeDataType* const args)
{
    return apply_primitive_implementation(proc, args); // apply_primitive_implementationでC++の関数を呼ぶ
}


/**
 (define (set-variable-value! var val env)
  (define (env-loop env)
    (define (scan vars vals)
      (cond ((null? vars)
             (env-loop (enclosing-environment env)))
            ((eq? var (car vars))
             (set-car! vals val))
            (else (scan (cdr vars) (cdr vals)))))
    (if (eq? env the-empty-environment)
        (error "Unbound variable -- SET!" var)
        (let ((frame (first-frame env)))
          (scan (frame-variables frame)
                (frame-values frame)))))
  (env-loop env))
  */
void set_variable_value_env_loop(SchemeDataType* const env, SchemeDataType* const var, SchemeDataType* const val);
void set_variable_value_scan(SchemeDataType* vars, SchemeDataType* const vals, SchemeDataType* const env, SchemeDataType* const var, SchemeDataType* const val);
void set_variable_value(SchemeDataType* const var, SchemeDataType* const val, SchemeDataType* const env)
{
    set_variable_value_env_loop(env, var, val);
}

void set_variable_value_scan(SchemeDataType* vars, SchemeDataType* const vals, SchemeDataType* const env, SchemeDataType* const var, SchemeDataType* const val)
{
    if (null_p(vars)) {
        set_variable_value_env_loop(enclosing_environment(env), var, val);
        return;
    }

    if (eq_p(var, car(vars))) {
        set_car(vals, val);
        return;
    }

    set_variable_value_scan(cdr(vars), cdr(vals), env, var, val);
}

void set_variable_value_env_loop(SchemeDataType* const env, SchemeDataType* const var, SchemeDataType* const val)
{
    using namespace std;

    if (eq_p(env, the_empty_environment)) {
        cout << "error: Unbound variable -- set-variable-value" << endl;
        read_eval_print_loop();
    }

    auto* frame = first_frame(env);
    set_variable_value_scan(frame_variables(frame), frame_values(frame), env, var, val);
}

/**
(define (define-variable! var val env)
  (let ((frame (first-frame env)))
    (define (scan vars vals)
      (cond ((null? vars)
             (add-binding-to-frame! var val frame))
            ((eq? var (car vars))
             (set-car! vals val))
            (else (scan (cdr vars) (cdr vals)))))
    (scan (frame-variables frame)
          (frame-values frame))))
 */
void define_variable(SchemeDataType* const var, SchemeDataType* const val, SchemeDataType* const env)
{
    // under construction
}










