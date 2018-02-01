#include "cons_man.h"

SchemeDataType* cons(SchemeDataType* const car, SchemeDataType* const cdr)
{
	ConsCell cell(car, cdr);
	return new SchemeDataType(cell);
}