#include "env.h"
#include "global.h"
#include "cons_man.h"

void setup_environment()
{ 
	SchemeDataType* the_empty_environment = new SchemeDataType;
	SchemeDataType* primitive_procedure_names = new SchemeDataType;
	SchemeDataType* primitive_procedure_objects = new SchemeDataType;
	the_global_environment = extend_environment(primitive_procedure_names, primitive_procedure_objects, the_empty_environment);
}

/**
 * @todo length error checking
 */
SchemeDataType* extend_environment(SchemeDataType* const vars, SchemeDataType* const vals, SchemeDataType* const base_env)
{
	return cons(make_frame(vars, vals), base_env);
}

SchemeDataType* make_frame(SchemeDataType* const variables, SchemeDataType* const values)
{
	return cons(variables, values);
}

SchemeDataType* enclosing_environment(SchemeDataType* const env)
{
	return cdr(env);
}

/**
(define (lookup-variable-value var env)
  (define (env-loop env)
    (define (scan vars vals)
      (cond ((null? vars)
             (env-loop (enclosing-environment env)))
            ((eq? var (car vars))
             (car vals))
            (else (scan (cdr vars) (cdr vals)))))
    (if (eq? env the-empty-environment)
        (error "Unbound variable" var)
        (let ((frame (first-frame env)))
          (scan (frame-variables frame)
                (frame-values frame)))))
  (env-loop env))
  */
SchemeDataType* lookup_variable_value(SchemeDataType* const var, SchemeDataType* const env)
{
	auto env_loop = [&] (SchemeDataType* const env) -> SchemeDataType* {
		auto scan = [&] (SchemeDataType* const vars, SchemeDataType* const vals) -> SchemeDataType* {
			if (null_p(vars)) {
        ;
			}
      return nullptr; // under construction
		};

	};

	return env_loop(get_global_environment());
}