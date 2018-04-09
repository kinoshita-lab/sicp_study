#pragma once

#include "types.h"
#include "stack.h"

void eceval();
void eval_dispatch();
void assign(int registerId, SchemeDataType* const r);
void goto_with_label(const char* const label);
void goto_with_label(SchemeDataType* const reg);
void unknown_expression_type();
void unknown_procedure_type();
void signal_error();

extern Stack s;

