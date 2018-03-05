#include <cstdio>
#include <cstdlib>
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

	return data1 == data2;
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

bool atom_p(SchemeDataType* const data)
{
	return (data->type != SchemeDataType::Cons) 
		&& null_p(data);
}

bool null_p(SchemeDataType* const data)
{
	return data->type == SchemeDataType::Nil;
}

bool list_p(SchemeDataType* const data)
{
	return data->type == SchemeDataType::Cons;
}

bool eq_p(SchemeDataType* data1, SchemeDataType* data2)
{
	if (null_p(data1) && null_p(data2)) {
		return true;
	}

	if (atom_p(data1) && atom_p(data2)) {
		return atom_eq_p(data1, data2);
	}

	if (list_p(data1) && list_p(data2)) {
		return (eq_p(car(data1), car(data2))) 
			&& (eq_p(cdr(data1), cdr(data2)));
	}

	return false;
}
