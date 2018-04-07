#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include "types.h"
#include "cons_man.h"
#include "user_print.h"


void ConsCell::listPush(SchemeDataType* item) {
	if (!car) {
		car = item;
		return;
	}
	
	if (!cdr) {
		auto newCons = new SchemeDataType(SchemeDataType::Cons);
		newCons->cellValue.car = item;
		cdr = newCons;
		return;
	}

	cdr->cellValue.listPush(item);
}

SchemeDataType::SchemeDataType()
	: type(Nil), othersValue(nullptr)
{
}


SchemeDataType::SchemeDataType(const int typeId)
	: type(typeId)
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
	if (typeId == SchemeDataType::SchemeConstant) {
		this->type = typeId;
		constValue = value;
		return;
	}

	if (typeId == SchemeDataType::Integer) {
		this->type = typeId;
		intValue = value;
		return;
	}
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
	case SchemeDataType::Cons: {
		r.push_back("(");
		
		std::vector<std::string> carStrings;
		if (cellValue.car) {
			carStrings = cellValue.car->to_s();
		}
		std::vector<std::string> cdrStrings;
		if (cellValue.cdr) {
			cdrStrings = cellValue.cdr->to_s();
		}
		for (auto&& ca : carStrings) {
			r.push_back(ca);
		}

		r.push_back(".");

		for (auto&& cd : cdrStrings) {
			r.push_back(cd);
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

