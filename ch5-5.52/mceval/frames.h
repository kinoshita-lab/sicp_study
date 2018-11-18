#pragma once
#include "types.h"

SchemeDataType* first_frame(SchemeDataType* env);
SchemeDataType* frame_variables(SchemeDataType* frame);
SchemeDataType* frame_values(SchemeDataType* frame);
void add_bindings_to_frame(SchemeDataType* const var, SchemeDataType* const val, SchemeDataType* const frame);