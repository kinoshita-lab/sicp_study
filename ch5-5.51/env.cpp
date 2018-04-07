#include <iostream>
#include "env.h"
#include "global.h"
#include "cons_man.h"
#include "frames.h"
#include "user_print.h"

using namespace std;

void setup_environment()
{ 
	the_empty_environment = new SchemeDataType;
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

SchemeDataType* env_loop(SchemeDataType* const env, SchemeDataType* const var);
SchemeDataType* scan(SchemeDataType* const env, SchemeDataType* const var, SchemeDataType* const vars, SchemeDataType* const vals);

SchemeDataType* scan(SchemeDataType* const env, SchemeDataType* const var, SchemeDataType* const vars, SchemeDataType* const vals)
{
  if (null_p(vars)) {
      return env_loop(enclosing_environment(env), var);
  }

  if (eq_p(var, car(vars))){
    return car(vals);
  }

  return scan(env, var, cdr(vars), cdr(vals));
}

SchemeDataType* env_loop(SchemeDataType* const env, SchemeDataType* const var)
{
  if (eq_p(env, the_empty_environment)) {

    cout << "error Unbound variable:";
    user_print(var);
    return new SchemeDataType(); // nil
  }

  auto* frame = first_frame(env);
  return scan(env, var, frame_variables(frame), frame_values(frame));
}

SchemeDataType* lookup_variable_value(SchemeDataType* const var, SchemeDataType* const env)
{
	return env_loop(the_global_environment, var);
}