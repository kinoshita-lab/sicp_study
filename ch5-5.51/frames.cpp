#include "frames.h"
#include "cons_man.h"

SchemeDataType* first_frame(SchemeDataType* env)
{
    return car(env);
}

SchemeDataType* frame_variables(SchemeDataType* frame)
{
    return car(frame);
}

SchemeDataType* frame_values(SchemeDataType* frame)
{
    return cdr(frame);
}

/**
 (define (add-binding-to-frame! var val frame)
  (set-car! frame (cons var (car frame)))
  (set-cdr! frame (cons val (cdr frame))))
*/
void add_bindings_to_frame(SchemeDataType* const var, SchemeDataType* const val, SchemeDataType* const frame)
{
    set_car(frame, cons(var, car(frame)));
    set_cdr(frame, cons(val, cdr(frame)));
}