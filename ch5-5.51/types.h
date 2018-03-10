#pragma once

#include <string>

struct SchemeDataType;
struct ConsCell
{
	SchemeDataType* car;
	SchemeDataType* cdr;

	ConsCell() : car(nullptr), cdr(nullptr) {}
	ConsCell(SchemeDataType* car, SchemeDataType* cdr) : car(car), cdr(cdr) {}

	int length();	
};

struct SchemeDataType
{
	enum TypeId
	{
		Integer,
		String,
		Symbol,
		Cons,
		Nil,
		Unknown
	};
	int type;

	// vals
	int intValue;
	char* stringValue;
	char* symbolValue;
	ConsCell cellValue;
	void* othersValue;
	char* errorMessage;

	SchemeDataType();
	SchemeDataType(const int v);
	SchemeDataType(const int typeId, const char* s); 	// string or symbol
	SchemeDataType(const ConsCell &cell);
	SchemeDataType(const SchemeDataType &r);
	SchemeDataType& operator=(const SchemeDataType& r);

	std::string to_s();



	~SchemeDataType();

	bool operator==(SchemeDataType* const rhs);
};

// debugging utils
void dumpData(const SchemeDataType& data);
void dumpConsCell(const SchemeDataType& data);
