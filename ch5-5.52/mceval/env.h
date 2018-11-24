#pragma once
#include "types.h"

void setup_environment();
SchemeDataType* extend_environment(SchemeDataType* const vars, SchemeDataType* const vals, SchemeDataType* const base_env);
SchemeDataType* lookup_variable_value(SchemeDataType* const var, SchemeDataType* const env);