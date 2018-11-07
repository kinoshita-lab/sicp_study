#pragma once
#include "types.h"

void setup_environment();
SchemeDataType* extend_environment(SchemeDataType* const vars, SchemeDataType* const vals, SchemeDataType* const base_env);
SchemeDataType* make_frame(SchemeDataType* const variables, SchemeDataType* const values);
SchemeDataType* enclosing_environment(SchemeDataType* const env);
SchemeDataType* lookup_variable_value(SchemeDataType* const var, SchemeDataType* const env);