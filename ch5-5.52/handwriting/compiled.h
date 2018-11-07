#pragma once 
#include "types.h"
#include "global.h"

typedef void (*compiledProcedure)();

SchemeDataType* make_compiled_procedure(const char* label, compiledProcedure, SchemeDataType* reg);

SchemeDataType* compiled_procedure_env(const RegisterId id);

SchemeDataType* compiled_procedure_entry(SchemeDataType* const reg);

SchemeDataType* apply_primitive_procedure(SchemeDataType* const proc, SchemeDataType* const argl);

bool primitive_procedure_p(SchemeDataType* const reg);

SchemeDataType* compiled_procedure_entry(SchemeDataType* const reg);

void define_variable(SchemeDataType* const reg, SchemeDataType* const val, SchemeDataType* const env);

bool false_p(SchemeDataType* const reg);
