#pragma once

#include <string>
#include <vector>
#include <gc_cpp.h>

struct SchemeDataType;

typedef SchemeDataType* (*PrimitiveFunction)(SchemeDataType* const arg1, SchemeDataType* const arg2);
typedef void (*CompiledProcedureFunction)();

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
		PrimitiveProc,
		CompiledProcedure,
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
	PrimitiveFunction primitive;  
	CompiledProcedureFunction compiledProcedure;

	SchemeDataType();
	SchemeDataType(const int typeId);
	SchemeDataType(const int typeId, const char* s); 	// string or symbol
	SchemeDataType(ConsCell* cell);
	SchemeDataType(const SchemeDataType &r);
	SchemeDataType(const int typeId, const int value); // for constants, booleans
	SchemeDataType(PrimitiveFunction p);
	SchemeDataType(CompiledProcedureFunction p);
	SchemeDataType* deepCopy();

	SchemeDataType& operator=(const SchemeDataType& r);

	std::vector<std::string> to_s();



	~SchemeDataType();

	bool operator==(SchemeDataType* const rhs);
};

SchemeDataType* deepCopyOf(SchemeDataType* data);
// debugging utils
void dumpData(const SchemeDataType& data);
void dumpConsCell(const SchemeDataType& data);

void assign(int registerId, SchemeDataType* const r);
