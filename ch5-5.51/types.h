#pragma once

#include <string>
#include <gc_cpp.h>

struct SchemeDataType;
struct ConsCell : public gc
{
	SchemeDataType* car;
	SchemeDataType* cdr;

	ConsCell() : car(nullptr), cdr(nullptr) {}
	ConsCell(SchemeDataType* car, SchemeDataType* cdr) : car(car), cdr(cdr) {}

	int length();
	void listPush(SchemeDataType* item); 
};

struct SchemeDataType : public gc
{
	enum TypeId
	{
		Integer,
		String,
		Symbol,
		Cons,
		Nil,
		SchemeConstant,
		Unknown
	};
	int type;

	// vals
	int intValue;
	char* stringValue;
	char* symbolValue;
	ConsCell cellValue;
	void* othersValue;
	int constValue;
	char* errorMessage;

	enum Constants{
		True, // #t
		False // #f
	};

	SchemeDataType();
	SchemeDataType(const int typeId);
	SchemeDataType(const int typeId, const char* s); 	// string or symbol
	SchemeDataType(const ConsCell &cell);
	SchemeDataType(const SchemeDataType &r);
	SchemeDataType(const int typeId, const int value); // for constants
	

	SchemeDataType& operator=(const SchemeDataType& r);

	std::string to_s();



	~SchemeDataType();

	bool operator==(SchemeDataType* const rhs);
};

// debugging utils
void dumpData(const SchemeDataType& data);
void dumpConsCell(const SchemeDataType& data);
