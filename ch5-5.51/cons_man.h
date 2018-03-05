/**
 * @file cons manipulation
 * 
 */
#pragma once
#include "types.h"

SchemeDataType* cons(SchemeDataType* const car, SchemeDataType* const cdr);

SchemeDataType* car(SchemeDataType* const data);
SchemeDataType* cdr(SchemeDataType* const data);

// *_p functions
bool atom_p(SchemeDataType* const data);
bool null_p(SchemeDataType* const data);
bool list_p(SchemeDataType* const data);

bool eq_p(SchemeDataType* const data1, SchemeDataType* const data2);
