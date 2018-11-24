#include <iostream>
#include <algorithm>
#include "support.h"
#include "types.h"
#include "cons_man.h"
#include "syntax.h"
#include "global.h"
#include "frames.h"
#include "env.h"
#include "frames.h"

/**
;;following compound-procedure operations not used by compiled code
(define (make-procedure parameters body env)
  (list 'procedure parameters body env))
  */
SchemeDataType* make_procedure(SchemeDataType* const parameters, SchemeDataType* const body, SchemeDataType* const env)
{
    return list(4, new SchemeDataType(SchemeDataType::TypeId::Symbol, "procedure"), parameters, body, env);
}

/**
(define (empty-arglist) '())
*/
SchemeDataType* empty_arglist()
{
    SchemeDataType* r = new SchemeDataType(SchemeDataType::TypeId::Cons);
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
    if (x->type != SchemeDataType::TypeId::SchemeBoolean) {
        return true;        
    }

    return x->booleanValue == SchemeDataType::SchemeBooleanValue::True;    
}

bool false_p(SchemeDataType* const x)
{
    return !(true_p(x));
}

/**
 (define (last-operand? ops)
  (null? (cdr ops)))
 */
bool last_operand_p(SchemeDataType* const ops)
{
    return cdr(ops)->type == SchemeDataType::TypeId::Nil;    // 違うかも
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
    auto* f = cadr(proc);
    auto* arg1 = car(args);
    auto* arg2 = cdr(args);

    return (*(f->primitive))(arg1, arg2);
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


void set_variable_value(SchemeDataType* const var, SchemeDataType* const val, SchemeDataType* const env)
{
    auto& frames = env->environmentFrames;

    for (auto&& frame : frames) {
        auto val_candidate = std::find_if(frame.begin(), frame.end(), [&](auto item) {
            return *(item->variable) == var;
        });
        if (val_candidate != frame.end()) {
            (*val_candidate)->value = val;
        }
    }
}

void define_variable(SchemeDataType* const var, SchemeDataType* const val, SchemeDataType* const env)
{
    auto& frames = env->environmentFrames;

    for (auto&& frame : frames) {
        auto val_candidate = std::find_if(frame.begin(), frame.end(), [&](auto item) {
            return *(item->variable) == var;
        });
        if (val_candidate != frame.end()) {
            (*val_candidate)->value = val;
        }
    }

    if (!env->environmentFrames.size()) {
        EnvironmentFrame ef;
        env->environmentFrames.push_front(EnvironmentFrame());
    }
    env->environmentFrames.front().push_front(new EnvironmentItem(var, val));
    
#if 0
    これに相当するものをのせる
    if (null_p(vars)) {
        add_bindings_to_frame(var, val, frame);
        return;
    }

    if (eq_p(var , car(vars))) {
        set_car(vals, val);
        return;
    }
#endif
}









