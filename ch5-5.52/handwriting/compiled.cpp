#include "cons_man.h"
#include "types.h"
#include "global.h"

/**
(define (make-compiled-procedure entry env)
  (list 'compiled-procedure entry env))
  */
SchemeDataType* make_compiled_procedure(const char* label, CompiledProcedureFunction entry, SchemeDataType* reg)
{
    return list(3, new SchemeDataType(SchemeDataType::Symbol, "compiled-procedure"), new SchemeDataType(entry), reg);
}

/**
(define (compiled-procedure-env c-proc) (caddr c-proc))
*/
SchemeDataType* compiled_procedure_env(const RegisterId id)
{
    if (registers[id]) {
        return caddr(registers[id]);        
    }
    return registers[ENV]; // こうでいいのか謎
}
/**
    (define (compiled-procedure-entry c-proc) (cadr c-proc))
    @todo compiled_procedure_envとインタフェースが違って変
*/
SchemeDataType* compiled_procedure_entry(SchemeDataType* const reg)
{
    return cadr(reg);
}
