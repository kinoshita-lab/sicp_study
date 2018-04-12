/**
 * @file cons manipulation
 * 
 */
#pragma once
#include <cstdarg>
#include "types.h"

SchemeDataType* cons(SchemeDataType* const car, SchemeDataType* const cdr);
SchemeDataType* append(SchemeDataType* const l1, SchemeDataType* const l2);

SchemeDataType* car(SchemeDataType* const data);
SchemeDataType* cdr(SchemeDataType* const data);

SchemeDataType* list();
SchemeDataType* list(const int number_of_items, ...);

void set_car(SchemeDataType* data, SchemeDataType* carData);


// *_p functions
bool atom_p(SchemeDataType* const data);
bool null_p(SchemeDataType* const data);
bool pair_p(SchemeDataType* const data);
bool symbol_p(SchemeDataType* const data);
bool eq_p(SchemeDataType* const data1, SchemeDataType* const data2);

// macros for cddr, cadr etc.
#define cadr(exp) (car(cdr(exp)))
#define caddr(exp) (car(cdr(cdr(exp))))
#define caadr(exp) (car(car(cdr(exp))))
#define cdadr(exp) (cdr(car(cdr(exp))))
#define cddr(exp) (cdr(cdr(exp)))
#define cdddr(exp) (cdr(cdr(cdr(exp))))
#define cadddr(exp) (car(cdr(cdr(cdr(exp)))))
