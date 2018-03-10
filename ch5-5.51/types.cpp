#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include "types.h"
#include "cons_man.h"
#include "user_print.h"

SchemeDataType::SchemeDataType()
	: type(Nil), othersValue(nullptr)
{
}

SchemeDataType::SchemeDataType(const int v)
	: type(Integer), intValue(v)
{
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

	if (typeId == Unknown) {
		errorMessage = (char*)malloc(length);
		strcpy(errorMessage, s);
	}
}

SchemeDataType::SchemeDataType(const ConsCell &cell) 
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

	return *this;
}

SchemeDataType::SchemeDataType(const int typeId, const int value)
{
	if (typeId != SchemeDataType::SchemeConstant) {
		this->type = Nil;
		return;
	}

	type = SchemeConstant;
	constValue = value;
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


std::string SchemeDataType::to_s()
{
	using namespace std;

	switch (type) {
	case SchemeDataType::Integer:
		return to_string(intValue);
	case SchemeDataType::String:
		return stringValue;
	case SchemeDataType::Symbol:
		return symbolValue;
	case SchemeDataType::Nil:
		return string("nil");
	case SchemeDataType::Unknown:
		return string("Unknown");
	default:
		return string("to_s: complex data element");
	}
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

		current = cdr->cellValue.car;
	}

	return l;
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
		dumpConsCell(data);
		break;
	default:
		cout << "Unknow Data Element!" << endl;
	}
}

void dumpConsCell(const SchemeDataType& data)
{
	
}
