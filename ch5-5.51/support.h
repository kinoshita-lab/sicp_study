/**
 * @file support routines based on ch5-eceval-support.scm
 */
#pragma once
#include "types.h"

SchemeDataType* make_procedure(SchemeDataType* const parameters, SchemeDataType* const body, SchemeDataType* const env);

SchemeDataType* empty_arglist();

SchemeDataType* adjoin_arg(SchemeDataType* const arg, SchemeDataType* const arglist);

SchemeDataType* procedure_parameters(SchemeDataType* const p);
SchemeDataType* procedure_body(SchemeDataType* const p);
SchemeDataType* procedure_environment(SchemeDataType* const p);


SchemeDataType* apply_primitive_procedure(SchemeDataType* const proc, SchemeDataType* const args);
void set_variable_value(SchemeDataType* const var, SchemeDataType* const val, SchemeDataType* const env);
void define_variable(SchemeDataType* const var, SchemeDataType* const val, SchemeDataType* const env);





bool true_p(SchemeDataType* const x);
bool last_operand_p(SchemeDataType* const ops);
bool primitive_procedure_p(SchemeDataType* const proc);
bool compound_procedure_p(SchemeDataType* const p);

