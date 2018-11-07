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
	if (car->type == SchemeDataType::Nil) {
		car = item;
		return;
	}
	
	if (cdr->type == SchemeDataType::Nil) {
		auto newCons = new SchemeDataType(SchemeDataType::Cons);
		newCons->cellValue->car = item;
		cdr = newCons;
		return;
	}

	cdr->cellValue->listPush(item);
}

SchemeDataType::SchemeDataType()
	: type(Nil), cellValue(nullptr)
{
}


SchemeDataType::SchemeDataType(const int typeId)
	: type(typeId)
{
	if (type == SchemeDataType::Cons) {
		cellValue = new ConsCell();
	}
}

SchemeDataType::SchemeDataType(const int typeId, const char* s)
	: type(typeId)
{
	const auto length = strlen(s);
		
	if (typeId == String) {
		stringValue = (char*)malloc(length);
		strcpy(stringValue, s);
	}

	if (typeId == Symbol) {
		symbolValue = (char*)malloc(length);
		strcpy(symbolValue, s);
	}
}


SchemeDataType::SchemeDataType(ConsCell* cell) 
{ 
	type = Cons;
	cellValue = cell;
}

SchemeDataType::SchemeDataType(const SchemeDataType& r)
 {
	type = r.type;

	if (type == Integer) {
		intValue = r.intValue;
	}
		
	if (type == String) {
		const auto length = strlen(r.stringValue);
		stringValue = (char*)malloc(length);
		strcpy(stringValue, r.stringValue);
	}

	if (type == Symbol) {
		const auto length = strlen(r.symbolValue);
		symbolValue = (char*)malloc(length);
		strcpy(symbolValue, r.symbolValue);
	}

    if (type == SchemeBoolean) {
        booleanValue = r.booleanValue;        
    }
    
}

SchemeDataType& SchemeDataType::operator=(const SchemeDataType& r) 
{
	type = r.type;
		
	if (type == Integer) {
		intValue = r.intValue;
	}
		
	if (type == String) {
		const auto length = strlen(r.stringValue);
		stringValue = (char*)malloc(length);
		strcpy(stringValue, r.stringValue);
	}

	if (type == Symbol) {
		const auto length = strlen(r.symbolValue);
		symbolValue = (char*)malloc(length);
		strcpy(symbolValue, r.symbolValue);
	}

    if (type == SchemeBoolean) {
        booleanValue = r.booleanValue;        
    }

	return *this;
}

SchemeDataType::SchemeDataType(const int typeId, const int value)
{
	if (typeId == SchemeDataType::SchemeBoolean) {
		this->type = typeId;
		booleanValue = (SchemeBooleanValue)value;
		return;
	}

	if (typeId == SchemeDataType::Integer) {
		this->type = typeId;
		intValue = value;
		return;
	}
}

SchemeDataType::SchemeDataType(PrimitiveFunction p)
{
	type = SchemeDataType::PrimitiveProc;
	primitive = p;
}

SchemeDataType::~SchemeDataType()
{
	if (type == String) {
		free(stringValue);
		return;
	}

	if (type == Symbol) {
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
	using namespace std;
	std::vector<std::string> r;

	switch (type) {
	case SchemeDataType::Integer:
		r.push_back(to_string(intValue));
		break;
	case SchemeDataType::String:
		r.push_back(std::string(stringValue));
		break;
	case SchemeDataType::Symbol:
		r.push_back(symbolValue);
		break;
	case SchemeDataType::Nil:
		r.push_back(string("nil"));
		break;
	case SchemeDataType::Unknown:
		r.push_back(string("Unknown"));
		break;
	case SchemeDataType::PrimitiveProc:
		r.push_back(string("C++ primitive function"));
		break;
	case SchemeDataType::Cons: {
		auto* cell = cellValue;
		r.push_back("(");

		while (cell) {
			auto* cellCar = cell->car;
			auto ss = cellCar->to_s();

			for (auto&& s : ss) {
				r.push_back(s);
			}

			if (cell->cdr->type != SchemeDataType::Cons && cell->cdr->type != SchemeDataType::Nil) {
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

		if (current->type != SchemeDataType::Cons) {
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
		case SchemeDataType::Integer:
			r->type = SchemeDataType::Integer;
			r->intValue = data->intValue;
			break;
		case SchemeDataType::Symbol: {
			r->type = SchemeDataType::Symbol;
			const auto length = strlen(data->symbolValue);
			r->symbolValue = (char*)malloc(length);
			strcpy(r->symbolValue, data->symbolValue);
			break;
		}
		case SchemeDataType::String: {
			r->type = SchemeDataType::String;
			const auto length = strlen(data->stringValue);
			r->stringValue = (char*)malloc(length);
			strcpy(r->stringValue, data->stringValue);
			break;
		}
		case SchemeDataType::Nil:
			r->type = SchemeDataType::Nil;
			break;
		case SchemeDataType::PrimitiveProc:
			r->type = SchemeDataType::PrimitiveProc;
			r->primitive = data->primitive;
			break;
		case SchemeDataType::SchemeBoolean:
			r->type = SchemeDataType::SchemeBoolean;
			r->booleanValue = data->booleanValue;
			break;
		case SchemeDataType::Cons:
			r->type = SchemeDataType::Cons;
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
	case SchemeDataType::Integer:
		cout << "Integer: " << data.intValue << endl;
		break;
	case SchemeDataType::String:
		cout << "String: " << data.stringValue << endl;
		break;
	case SchemeDataType::Symbol:
		cout << "Symbol: " << data.symbolValue << endl;
		break;
	case SchemeDataType::Cons:
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

