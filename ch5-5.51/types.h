#pragma once

#include <string>
#include <vector>

#include <gc_cpp.h>

struct SchemeDataType;
struct ConsCell : public gc
{
	SchemeDataType* car;
	SchemeDataType* cdr;

	ConsCell();
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
        SchemeBoolean,
		Unknown
	};
    
    enum SchemeBooleanValue
    {
        False,
        True,
    };
    
        
	int type;

	// vals
	int intValue;
	char* stringValue;
	char* symbolValue;
	ConsCell* cellValue;
    SchemeBooleanValue booleanValue;    

	SchemeDataType();
	SchemeDataType(const int typeId);
	SchemeDataType(const int typeId, const char* s); 	// string or symbol
	SchemeDataType(ConsCell* cell);
	SchemeDataType(const SchemeDataType &r);
	SchemeDataType(const int typeId, const int value); // for constants, booleans
	

	SchemeDataType& operator=(const SchemeDataType& r);

	std::vector<std::string> to_s();



	~SchemeDataType();

	bool operator==(SchemeDataType* const rhs);
};

// debugging utils
void dumpData(const SchemeDataType& data);
void dumpConsCell(const SchemeDataType& data);
