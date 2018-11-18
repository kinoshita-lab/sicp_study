#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "cons_man.h"
#include "parse.h"

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
		case SchemeDataType::TypeId::Integer:
		return data1->intValue == data2->intValue;
		case SchemeDataType::TypeId::String:
		return strcmp(data1->stringValue, data2->stringValue) == 0;
		case SchemeDataType::TypeId::Symbol:
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
    SchemeDataType* r = new SchemeDataType(SchemeDataType::TypeId::Cons);
    r->cellValue = l1->cellValue;
    r->cellValue->listPush(l2);
    
    return r;    
}


SchemeDataType* car(SchemeDataType* const data, SchemeDataType* const)
{
	if (data->type != SchemeDataType::TypeId::Cons) {
		return new SchemeDataType(SchemeDataType::TypeId::Nil);
	}

	return data->cellValue->car;
}

SchemeDataType* cdr(SchemeDataType* const data, SchemeDataType* const)
{
	if (data->type != SchemeDataType::TypeId::Cons) {
		return new SchemeDataType(SchemeDataType::TypeId::Nil);
	}

	return data->cellValue->cdr;
}

SchemeDataType* list()
{
    auto* r = new SchemeDataType(SchemeDataType::TypeId::Cons);
    r->cellValue->car = new SchemeDataType(SchemeDataType::TypeId::Nil);
    r->cellValue->cdr = new SchemeDataType(SchemeDataType::TypeId::Nil);

    return r;    
}

SchemeDataType* list(const int number_of_items, ...)
{
    auto* r = new SchemeDataType(SchemeDataType::TypeId::Cons);
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
	// make cons if atom
	if (data->type != SchemeDataType::TypeId::Cons)
	{
		auto* r = list();
		r->cellValue->car = data;
		return r;
	}
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
	return (data->type != SchemeDataType::TypeId::Cons) 
		&& !(null_p(data));
}

bool null_p(SchemeDataType* const data)
{
	return data->type == SchemeDataType::TypeId::Nil;
}

SchemeDataType* null_p_primitive(SchemeDataType* const data, SchemeDataType* const)
{
	if (data->type == SchemeDataType::TypeId::Cons) {
		return new SchemeDataType(SchemeDataType::TypeId::SchemeBoolean,
			(data->cellValue->car->type == SchemeDataType::TypeId::Nil && data->cellValue->cdr->type == SchemeDataType::TypeId::Nil) ? SchemeDataType::True :SchemeDataType::False);
	}

	return new SchemeDataType(SchemeDataType::TypeId::SchemeBoolean, 
	data->type == SchemeDataType::TypeId::Nil ? SchemeDataType::True : SchemeDataType::False);
}

bool pair_p(SchemeDataType* const data)
{
	return data->type == SchemeDataType::TypeId::Cons;
}

bool symbol_p(SchemeDataType* const data)
{
	return data->type == SchemeDataType::TypeId::Symbol;
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


SchemeDataType* primitive_num_add(SchemeDataType* const arg1, SchemeDataType* const arg2)
{
	return new SchemeDataType(SchemeDataType::TypeId::Integer, 
				arg1->cellValue->car->intValue 
				+ arg2->cellValue->car->intValue);
}

SchemeDataType* primitive_num_mul(SchemeDataType* const arg1, SchemeDataType* const arg2)
{
	return new SchemeDataType(SchemeDataType::TypeId::Integer, 
				arg1->cellValue->car->intValue 
				* arg2->cellValue->car->intValue);
}
SchemeDataType* primitive_num_minus(SchemeDataType* const arg1, SchemeDataType* const arg2)
{
	return new SchemeDataType(SchemeDataType::TypeId::Integer, 
				arg1->cellValue->car->intValue 
				- arg2->cellValue->car->intValue);
}

SchemeDataType* primitive_num_equal(SchemeDataType* const arg1, SchemeDataType* const arg2)
{
	return new SchemeDataType(SchemeDataType::TypeId::SchemeBoolean, 
				arg1->cellValue->car->intValue == arg2->cellValue->car->intValue ? SchemeDataType::True : SchemeDataType::False);	
}

SchemeDataType* primitive_num_div(SchemeDataType* const arg1, SchemeDataType* const arg2)
{
return new SchemeDataType(SchemeDataType::TypeId::Integer, 
				arg1->cellValue->car->intValue 
				/ arg2->cellValue->car->intValue);
}

SchemeDataType* primitive_num_gt(SchemeDataType* const arg1, SchemeDataType* const arg2)
{
	return new SchemeDataType(SchemeDataType::TypeId::SchemeBoolean, 
				arg1->cellValue->car->intValue > arg2->cellValue->car->intValue ? SchemeDataType::True : SchemeDataType::False);	
}

SchemeDataType* primitive_num_lt(SchemeDataType* const arg1, SchemeDataType* const arg2)
{
	return new SchemeDataType(SchemeDataType::TypeId::SchemeBoolean, 
				arg1->cellValue->car->intValue < arg2->cellValue->car->intValue ? SchemeDataType::True : SchemeDataType::False);	
}

SchemeDataType* primitive_list(SchemeDataType* const arg1, SchemeDataType* const arg2)
{
	return append(arg1, arg2);
}

SchemeDataType* primitive_cons(SchemeDataType* const arg1, SchemeDataType* const arg2)
{
	return cons(arg1, arg2);
}

SchemeDataType* primitive_newline(SchemeDataType* const, SchemeDataType* const)
{
	std::cout << std::endl;
	return new SchemeDataType(SchemeDataType::TypeId::Nil);
}

SchemeDataType* primitive_display(SchemeDataType* const arg1, SchemeDataType* const arg2)
{
	auto strs = car(arg1)->to_s();

	for (auto&& str : strs) {
		std::cout << str;
	}
	std::cout << std::endl;
	return new SchemeDataType(SchemeDataType::TypeId::Nil);
}

SchemeDataType* primitive_pair_p(SchemeDataType* const arg1, SchemeDataType* const arg2)
{
	return new SchemeDataType(SchemeDataType::TypeId::Nil);
}

SchemeDataType* primitive_eq_p(SchemeDataType* const arg1, SchemeDataType* const arg2)
{
	return new SchemeDataType(SchemeDataType::TypeId::SchemeBoolean, eq_p(arg1, arg2));
}

SchemeDataType* primitive_read(SchemeDataType* const arg1, SchemeDataType* const arg2)
{
	
#if 0	
	std::string input;
	std::string tmp;
	
	std::getline(std::cin, tmp);
		input += tmp;
#endif
	auto input = std::string("(+ 1 1)");
	if (input == "!exit") {
		exit(0);
	}

	auto* parsed = parse(input);

	return parsed;
}

SchemeDataType* primitive_num_p(SchemeDataType* const arg1, SchemeDataType* const arg2)
{
	bool isInteger = car(arg1)->type == SchemeDataType::TypeId::Integer;
	return new SchemeDataType(SchemeDataType::TypeId::SchemeBoolean, isInteger);
}

SchemeDataType* primitive_string_p(SchemeDataType* const arg1, SchemeDataType* const arg2)
{
	bool isString = car(arg1)->type == SchemeDataType::TypeId::String;
	return new SchemeDataType(SchemeDataType::TypeId::SchemeBoolean, isString);
}

SchemeDataType* primitive_symbol_p(SchemeDataType* const arg1, SchemeDataType* const arg2)
{
	bool isSymbol = car(arg1)->type == SchemeDataType::TypeId::Symbol;
	return new SchemeDataType(SchemeDataType::TypeId::SchemeBoolean, isSymbol);
}