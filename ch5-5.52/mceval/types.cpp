#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include "types.h"
#include "cons_man.h"
#include "user_print.h"
#include "global.h"


ConsCell::ConsCell() : car(new SchemeDataType()), cdr(new SchemeDataType()) {}

void ConsCell::listPush(SchemeDataType* item) 
{
	if (car->type == SchemeDataType::TypeId::Nil) {
		car = item;
		return;
	}
	
	if (cdr->type == SchemeDataType::TypeId::Nil) {
		auto newCons = new SchemeDataType(SchemeDataType::TypeId::Cons);
		newCons->cellValue->car = item;
		cdr = newCons;
		return;
	}

	cdr->cellValue->listPush(item);
}

int SchemeDataType::to_s_counter = 0; 

SchemeDataType::SchemeDataType()
	: type(TypeId::Nil), cellValue(nullptr)
{
}


SchemeDataType::SchemeDataType(const TypeId typeId)
	: type(typeId)
{
	if (type == SchemeDataType::TypeId::Cons) {
		cellValue = new ConsCell();
	}
}

SchemeDataType::SchemeDataType(const TypeId typeId, const char* s)
	: type(typeId)
{
	const auto length = strlen(s);
		
	if (typeId == TypeId::String) {
		stringValue = (char*)malloc(length);
		strcpy(stringValue, s);
	}

	if (typeId == TypeId::Symbol) {
		symbolValue = (char*)malloc(length);
		strcpy(symbolValue, s);
	}
}


SchemeDataType::SchemeDataType(ConsCell* cell) 
{ 
	type = TypeId::Cons;
	cellValue = cell;
}

SchemeDataType::SchemeDataType(const SchemeDataType& r)
{
	type = r.type;

	if (type == TypeId::Integer) {
		intValue = r.intValue;
	}
		
	if (type == TypeId::String) {
		const auto length = strlen(r.stringValue);
		stringValue = (char*)malloc(length);
		strcpy(stringValue, r.stringValue);
	}

	if (type == TypeId::Symbol) {
		const auto length = strlen(r.symbolValue);
		symbolValue = (char*)malloc(length);
		strcpy(symbolValue, r.symbolValue);
	}

    if (type == TypeId::SchemeBoolean) {
        booleanValue = r.booleanValue;        
    }
    
}

SchemeDataType& SchemeDataType::operator=(const SchemeDataType& r) 
{
	type = r.type;
		
	if (type == TypeId::Integer) {
		intValue = r.intValue;
	}
		
	if (type == TypeId::String) {
		const auto length = strlen(r.stringValue);
		stringValue = (char*)malloc(length);
		strcpy(stringValue, r.stringValue);
	}

	if (type == TypeId::Symbol) {
		const auto length = strlen(r.symbolValue);
		symbolValue = (char*)malloc(length);
		strcpy(symbolValue, r.symbolValue);
	}

    if (type == TypeId::SchemeBoolean) {
        booleanValue = r.booleanValue;        
    }

	return *this;
}

SchemeDataType::SchemeDataType(const TypeId typeId, const int value)
{
	if (typeId == SchemeDataType::TypeId::SchemeBoolean) {
		this->type = typeId;
		booleanValue = (SchemeBooleanValue)value;
		return;
	}

	if (typeId == SchemeDataType::TypeId::Integer) {
		this->type = typeId;
		intValue = value;
		return;
	}
}

SchemeDataType::SchemeDataType(PrimitiveFunction p)
{
	type = SchemeDataType::TypeId::PrimitiveProc;
	primitive = p;
}

SchemeDataType::SchemeDataType(CompiledProcedureFunction p)
{
	type = SchemeDataType::TypeId::CompiledProcedure;
	compiledProcedure = p;
}

SchemeDataType::~SchemeDataType()
{
	if (type == TypeId::String) {
		free(stringValue);
		return;
	}

	if (type == TypeId::Symbol) {
		free(symbolValue);
		return;
	}
}

bool SchemeDataType::operator==(SchemeDataType* const rhs)
{
	return eq_p(this, rhs);
}

std::vector<std::string> SchemeDataType::to_s()
{
	to_s_counter = 0; 
	auto r = to_s_inner();
	return r;
}

std::vector<std::string> SchemeDataType::to_s_inner()
{
	using namespace std;
	std::vector<std::string> r;
	to_s_counter++;

	if (to_s_counter >= 80) {
		r.push_back("too many elems");
		return r;
	}


	switch (type) {
	case SchemeDataType::TypeId::Integer:
		r.push_back(to_string(intValue));
		break;
	case SchemeDataType::TypeId::String:
		r.push_back(std::string(stringValue));
		break;
	case SchemeDataType::TypeId::Symbol:
		r.push_back(symbolValue);
		break;
	case SchemeDataType::TypeId::Nil:
		r.push_back(string("nil"));
		break;
	case SchemeDataType::TypeId::Unknown:
		r.push_back(string("Unknown"));
		break;
	case SchemeDataType::TypeId::PrimitiveProc:
		r.push_back(string("C++ primitive function"));
		break;
	case SchemeDataType::TypeId::Cons: {
		auto* cell = cellValue;
		r.push_back("(");

		while (cell) {
			auto* cellCar = cell->car;
			auto ss = cellCar->to_s_inner();

			for (auto&& s : ss) {
				r.push_back(s);
			}

			if (cell->cdr->type != SchemeDataType::TypeId::Cons && cell->cdr->type != SchemeDataType::TypeId::Nil) {
				r.push_back(string("."));
			}

			cell = cell->cdr->cellValue;
		}

		r.push_back(")");
	}
	break;
	default:
		r.push_back(string("to_s: complex data element"));
	}

	return r;
}

void SchemeDataType::print()
{
	auto ss = to_s();

	for (auto&& s : ss) {
		std::cout << s << " ";
	}

	std::cout << std::endl;
}

int ConsCell::length()
{
	auto* current = car;
	auto l = 0;
	
	while (current) {
		
		l++;
		current = cdr;

		if (current == nullptr) {
			break;
		}

		if (current->type != SchemeDataType::TypeId::Cons) {
			l++;
			break;
		}

		current = cdr->cellValue->car;
	}

	return l;
}


SchemeDataType* deepCopyOf(SchemeDataType* data)
{
	SchemeDataType* r = new SchemeDataType();

	switch (data->type) {
		case SchemeDataType::TypeId::Integer:
			r->type = SchemeDataType::TypeId::Integer;
			r->intValue = data->intValue;
			break;
		case SchemeDataType::TypeId::Symbol: {
			r->type = SchemeDataType::TypeId::Symbol;
			const auto length = strlen(data->symbolValue);
			r->symbolValue = (char*)malloc(length);
			strcpy(r->symbolValue, data->symbolValue);
			break;
		}
		case SchemeDataType::TypeId::String: {
			r->type = SchemeDataType::TypeId::String;
			const auto length = strlen(data->stringValue);
			r->stringValue = (char*)malloc(length);
			strcpy(r->stringValue, data->stringValue);
			break;
		}
		case SchemeDataType::TypeId::Nil:
			r->type = SchemeDataType::TypeId::Nil;
			break;
		case SchemeDataType::TypeId::PrimitiveProc:
			r->type = SchemeDataType::TypeId::PrimitiveProc;
			r->primitive = data->primitive;
			break;
		case SchemeDataType::TypeId::SchemeBoolean:
			r->type = SchemeDataType::TypeId::SchemeBoolean;
			r->booleanValue = data->booleanValue;
			break;
		case SchemeDataType::TypeId::Cons:
			r->type = SchemeDataType::TypeId::Cons;
			r->cellValue = new ConsCell();
			r->cellValue->car = deepCopyOf(data->cellValue->car);
			r->cellValue->cdr = deepCopyOf(data->cellValue->cdr);
			break;
		default:
			break;
	}

	return r;
}

void dumpData(const SchemeDataType& data)
{
	using namespace std;

	switch (data.type) {
	case SchemeDataType::TypeId::Integer:
		cout << "Integer: " << data.intValue << endl;
		break;
	case SchemeDataType::TypeId::String:
		cout << "String: " << data.stringValue << endl;
		break;
	case SchemeDataType::TypeId::Symbol:
		cout << "Symbol: " << data.symbolValue << endl;
		break;
	case SchemeDataType::TypeId::Cons:
		cout << "Cons Cell" << endl;
		break;
	default:
		cout << "Unknown Data Element!" << endl;
	}
}


void assign(int registerId, SchemeDataType* const r)
{
	registers[registerId] = r;
}

