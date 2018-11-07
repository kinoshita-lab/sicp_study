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
	return new SchemeDataType(new ConsCell(car, cdr));
}

SchemeDataType* append(SchemeDataType* const l1, SchemeDataType* const l2)
{
    SchemeDataType* r = new SchemeDataType(SchemeDataType::Cons);
    r->cellValue = l1->cellValue;
    r->cellValue->listPush(l2);
    
    return r;    
}


SchemeDataType* car(SchemeDataType* const data, SchemeDataType* const)
{
	if (data->type != SchemeDataType::Cons) {
		puts("Error Invalid data type @car");
		exit(0);
	}

	return data->cellValue->car;
}

SchemeDataType* cdr(SchemeDataType* const data, SchemeDataType* const)
{
	if (data->type != SchemeDataType::Cons) {
		puts("Error Invalid data type @cdr");
		exit(0);
	}

	return data->cellValue->cdr;
}

SchemeDataType* list()
{
    auto* r = new SchemeDataType(SchemeDataType::Cons);
    r->cellValue->car = new SchemeDataType(SchemeDataType::Nil);
    r->cellValue->cdr = new SchemeDataType(SchemeDataType::Nil);

    return r;    
}

SchemeDataType* list(const int number_of_items, ...)
{
    auto* r = new SchemeDataType(SchemeDataType::Cons);
    va_list args;
    va_start(args, number_of_items);

    for (auto i = 0; i < number_of_items; ++i) {
        r->cellValue->listPush(va_arg(args, SchemeDataType*));        
    }
    
    va_end(args);

    return r;    
}

SchemeDataType* list(SchemeDataType* data)
{
	// todo make cons if atom
	return data;
}
void set_car(SchemeDataType* data, SchemeDataType* carData)
{
	data->cellValue->car = carData;
}

void set_cdr(SchemeDataType* data, SchemeDataType* cdrData)
{
	data->cellValue->cdr = cdrData;
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

SchemeDataType* null_p_primitive(SchemeDataType* const data, SchemeDataType* const)
{
	return new SchemeDataType(SchemeDataType::SchemeBoolean, 
	data->type == SchemeDataType::Nil ? SchemeDataType::True : SchemeDataType::False);
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


SchemeDataType* cons_num_add(SchemeDataType* const arg1, SchemeDataType* const arg2)
{
	return new SchemeDataType(SchemeDataType::Integer, 
				arg1->cellValue->car->intValue 
				+ arg2->cellValue->car->intValue);
}

SchemeDataType* cons_num_mul(SchemeDataType* const arg1, SchemeDataType* const arg2)
{
	return new SchemeDataType(SchemeDataType::Integer, 
				arg1->cellValue->car->intValue 
				* arg2->cellValue->car->intValue);
}
SchemeDataType* cons_num_minus(SchemeDataType* const arg1, SchemeDataType* const arg2)
{
	return new SchemeDataType(SchemeDataType::Integer, 
				arg1->cellValue->car->intValue 
				- arg2->cellValue->car->intValue);
}

SchemeDataType* cons_num_equal(SchemeDataType* const arg1, SchemeDataType* const arg2)
{
	return new SchemeDataType(SchemeDataType::SchemeBoolean, 
				arg1->cellValue->car->intValue == arg2->cellValue->car->intValue ? SchemeDataType::True : SchemeDataType::False);	
}

SchemeDataType* cons_num_div(SchemeDataType* const arg1, SchemeDataType* const arg2)
{
return new SchemeDataType(SchemeDataType::Integer, 
				arg1->cellValue->car->intValue 
				/ arg2->cellValue->car->intValue);
}

SchemeDataType* cons_num_gt(SchemeDataType* const arg1, SchemeDataType* const arg2)
{
	return new SchemeDataType(SchemeDataType::SchemeBoolean, 
				arg1->cellValue->car->intValue > arg2->cellValue->car->intValue ? SchemeDataType::True : SchemeDataType::False);	
}

SchemeDataType* cons_num_lt(SchemeDataType* const arg1, SchemeDataType* const arg2)
{
	return new SchemeDataType(SchemeDataType::SchemeBoolean, 
				arg1->cellValue->car->intValue < arg2->cellValue->car->intValue ? SchemeDataType::True : SchemeDataType::False);	
}