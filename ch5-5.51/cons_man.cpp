#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "cons_man.h"

namespace
{
bool atom_eq_p(SchemeDataType* const data1, SchemeDataType* data2)
{
	if (!atom_p(data1) || !atom_p(data2)) {
		puts("Error Non atom-comparation: @atom_eq_p");
	}

	if (data1->type != data2->type) {
		return false;
	}

	switch (data1->type) {
		case SchemeDataType::Integer:
		return data1->intValue == data2->intValue;
		case SchemeDataType::String:
		return strcmp(data1->stringValue, data2->stringValue) == 0;
		case SchemeDataType::Symbol:
		return strcmp(data1->symbolValue, data2->symbolValue) == 0;
		default:
		puts("non atomic operation@ atom_eq_p");
		return false;
	}
}
}

SchemeDataType* cons(SchemeDataType* const car, SchemeDataType* const cdr)
{
	ConsCell cell(car, cdr);
	return new SchemeDataType(cell);
}

SchemeDataType* car(SchemeDataType* const data)
{
	if (data->type != SchemeDataType::Cons) {
		puts("Error Invalid data type @car");
		exit(0);
	}

	return data->cellValue.car;
}

SchemeDataType* cdr(SchemeDataType* const data)
{
	if (data->type != SchemeDataType::Cons) {
		puts("Error Invalid data type @cdr");
		exit(0);
	}

	return data->cellValue.cdr;
}

// under construction
SchemeDataType* list(...)
{
	return new SchemeDataType();
}

bool atom_p(SchemeDataType* const data)
{
	return (data->type != SchemeDataType::Cons) 
		&& !(null_p(data));
}

bool null_p(SchemeDataType* const data)
{
	return data->type == SchemeDataType::Nil;
}

bool pair_p(SchemeDataType* const data)
{
	return data->type == SchemeDataType::Cons;
}

bool symbol_p(SchemeDataType* const data)
{
	return data->type == SchemeDataType::Symbol;
}

bool eq_p(SchemeDataType* data1, SchemeDataType* data2)
{
	if (null_p(data1) && null_p(data2)) {
		return true;
	}

	if (atom_p(data1) && atom_p(data2)) {
		return atom_eq_p(data1, data2);
	}

	if (pair_p(data1) && pair_p(data2)) {
		return (eq_p(car(data1), car(data2))) 
			&& (eq_p(cdr(data1), cdr(data2)));
	}

	return false;
}
