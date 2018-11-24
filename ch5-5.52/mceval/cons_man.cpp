#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "cons_man.h"
#include "parse.h"
#include "global.h"
#include "env.h"
#include "compiled.h"
#include "goto_with_label.h"

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
	if (data == nullptr)
	{
		return new SchemeDataType(SchemeDataType::TypeId::Nil);
	}
	// make cons if atom
	if (data->type != SchemeDataType::TypeId::Cons)
	{
		auto* r = list();
		r->cellValue->car = data;
		return r;
	}
	auto* r = list();
	r->cellValue->car = data;
	return r;
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
	if (data->type == SchemeDataType::TypeId::Cons) {
		if (data->cellValue->cdr == nullptr) {
			return data->cellValue->car->type == SchemeDataType::TypeId::Nil;
		}

		return data->cellValue->car->type == data->cellValue->cdr->type && data->cellValue->car->type == SchemeDataType::TypeId::Nil;
	}

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
	if (!data1) {
		return false;
	}
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
	auto* arg = arg1;
	auto sum = 0;
	while (true) {
		auto* n = car(arg);
		if (null_p(n)) {
			break;
		}

		sum += n->intValue;
		arg = cdr(arg);
	}

	return new SchemeDataType(SchemeDataType::TypeId::Integer, sum);
}

SchemeDataType* primitive_num_mul(SchemeDataType* const arg1, SchemeDataType* const arg2)
{
	auto* arg = arg1;
	auto product = 1;
	while (true) {
		auto* n = car(arg);
		if (null_p(n)) {
			break;
		}

		product *= n->intValue;
		arg = cdr(arg);
	}

	return new SchemeDataType(SchemeDataType::TypeId::Integer, product);
}
SchemeDataType* primitive_num_minus(SchemeDataType* const arg1, SchemeDataType* const arg2)
{
	auto* arg = arg1;
	auto sub = car(arg1)->intValue;
	arg = cdr(arg);
	while (true) {
		auto* n = car(arg);
		if (null_p(n)) {
			break;
		}

		sub -= n->intValue;
		arg = cdr(arg);
	}

	return new SchemeDataType(SchemeDataType::TypeId::Integer, sub);
}

SchemeDataType* primitive_num_equal(SchemeDataType* const arg1, SchemeDataType* const arg2)
{
	const auto n1 = car(arg1)->intValue;
	const auto n2 = cadr(arg1)->intValue;

	return new SchemeDataType(SchemeDataType::TypeId::SchemeBoolean, n1 == n2);
}

SchemeDataType* primitive_num_div(SchemeDataType* const arg1, SchemeDataType* const arg2)
{
	auto* arg = arg1;
	auto div = car(arg1)->intValue;
	arg = cdr(arg);
	while (true) {
		auto* n = car(arg);
		if (null_p(n)) {
			break;
		}

		div /= n->intValue;
		arg = cdr(arg);
	}

	return new SchemeDataType(SchemeDataType::TypeId::Integer, div);
}

SchemeDataType* primitive_num_gt(SchemeDataType* const arg1, SchemeDataType* const arg2)
{
	const auto n1 = car(arg1)->intValue;
	const auto n2 = cadr(arg1)->intValue;

	return new SchemeDataType(SchemeDataType::TypeId::SchemeBoolean, n1 > n2);	
}

SchemeDataType* primitive_num_lt(SchemeDataType* const arg1, SchemeDataType* const arg2)
{
	const auto n1 = car(arg1)->intValue;
	const auto n2 = cadr(arg1)->intValue;

	return new SchemeDataType(SchemeDataType::TypeId::SchemeBoolean, n1 < n2);	
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
	auto strs = arg1->to_s();

	for (auto&& str : strs) {
		std::cout << str;
	}
	std::cout << std::endl;
	return new SchemeDataType(SchemeDataType::TypeId::Nil);
}

SchemeDataType* primitive_pair_p(SchemeDataType* const arg1, SchemeDataType* const arg2)
{
	return new SchemeDataType(SchemeDataType::TypeId::SchemeBoolean, arg1->type == SchemeDataType::TypeId::Cons);
}

SchemeDataType* primitive_eq_p(SchemeDataType* const arg1, SchemeDataType* const arg2)
{
	return new SchemeDataType(SchemeDataType::TypeId::SchemeBoolean, eq_p(arg1, arg2));
}

SchemeDataType* primitive_read(SchemeDataType* const arg1, SchemeDataType* const arg2)
{
	std::string input;
	std::string tmp;
	
	std::getline(std::cin, tmp);
	input += tmp;
	
	if (input == "!exit") {
		exit(0);
	}

	const auto parsed = parse(input);
	return parsed;
}

SchemeDataType* primitive_num_p(SchemeDataType* const arg1, SchemeDataType* const arg2)
{
	bool isInteger = arg1->type == SchemeDataType::TypeId::Integer;
	return new SchemeDataType(SchemeDataType::TypeId::SchemeBoolean, isInteger);
}

SchemeDataType* primitive_string_p(SchemeDataType* const arg1, SchemeDataType* const arg2)
{
	bool isString = arg1->type == SchemeDataType::TypeId::String;
	return new SchemeDataType(SchemeDataType::TypeId::SchemeBoolean, isString);
}

SchemeDataType* primitive_symbol_p(SchemeDataType* const arg1, SchemeDataType* const arg2)
{
	bool isSymbol = arg1->type == SchemeDataType::TypeId::Symbol;
	return new SchemeDataType(SchemeDataType::TypeId::SchemeBoolean, isSymbol);
}

SchemeDataType* primitive_procedure_p(SchemeDataType* const arg1, SchemeDataType* const arg2)
{
	const std::string argSymbol = car(arg1)->symbolValue;
	bool isPrimitive =  argSymbol == "primitive";
	return new SchemeDataType(SchemeDataType::TypeId::SchemeBoolean, isPrimitive);
}


SchemeDataType* list_of_values_eval(SchemeDataType* const argl, SchemeDataType* const env)
{
	assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "eval"), registers[ENV]));
    assign(VAL, compiled_procedure_entry(registers[PROC]));
	registers[CONTINUE] = new SchemeDataType(SchemeDataType::TypeId::String, "return");
	assign(ARGL, argl);

	try {
            goto_with_label(registers[VAL]);
    }
    catch (const char*) {
        ;
	}

	return registers[VAL];
}
SchemeDataType* primitive_list_of_values(SchemeDataType* const arg1, SchemeDataType* const arg2)
{
	if (null_p(arg1)) {
		return new SchemeDataType();
	}
	auto* env = car(arg2);
	auto* argl = arg1;

	return cons(list_of_values_eval(argl, env), primitive_list_of_values(cdr(arg1), env));
}

SchemeDataType* primitive_apply(SchemeDataType* const arg1, SchemeDataType* const arg2)
{
	auto* f = cadr(arg1);
    auto* function_arg1 = car(arg2);
    auto* function_arg2 = cdr(arg2);

	return (*(f->primitive))(function_arg1, function_arg2);
}