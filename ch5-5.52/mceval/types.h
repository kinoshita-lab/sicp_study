#pragma once

#include <string>
#include <vector>
#include <list>
#include <gc_cpp.h>

struct SchemeDataType;

typedef SchemeDataType* (*PrimitiveFunction)(SchemeDataType* const arg1, SchemeDataType* const arg2);
typedef void (*CompiledProcedureFunction)();

struct ConsCell 
{
	SchemeDataType* car;
	SchemeDataType* cdr;

	ConsCell();
	ConsCell(SchemeDataType* car, SchemeDataType* cdr) : car(car), cdr(cdr) {}

	int length();
	void listPush(SchemeDataType* item); 
};

struct EnvironmentItem
{
	SchemeDataType* variable;
	SchemeDataType* value;	

	EnvironmentItem(SchemeDataType* const variable, SchemeDataType* const value);
	EnvironmentItem() : variable(nullptr), value(nullptr) {}
};

using EnvironmentFrame = std::list<EnvironmentItem*>;
using EnvironmentFrames = std::list<EnvironmentFrame>;

struct SchemeDataType 
{
	enum class TypeId
	{
		Integer,
		String,
		Symbol,
		Cons,
		Nil,
        SchemeBoolean,
		PrimitiveProc,
		CompiledProcedure,
		Environment,
		Unknown
	};
    
    enum SchemeBooleanValue
    {
        False,
        True,
    };
    
        
	TypeId type;

	// vals
	int intValue;
	char* stringValue;
	char* symbolValue;
	ConsCell* cellValue;
    SchemeBooleanValue booleanValue;
	PrimitiveFunction primitive;  
	CompiledProcedureFunction compiledProcedure;
	EnvironmentFrames environmentFrames;

	SchemeDataType();
	SchemeDataType(const TypeId typeId);
	SchemeDataType(const TypeId typeId, const char* s); 	// string or symbol
	SchemeDataType(ConsCell* cell);
	SchemeDataType(const SchemeDataType &r);
	SchemeDataType(const TypeId typeId, const int value); // for constants, booleans
	SchemeDataType(PrimitiveFunction p);
	SchemeDataType(CompiledProcedureFunction p);
	SchemeDataType(const TypeId typeId, SchemeDataType* const var, SchemeDataType* const val); // for environment frame
	SchemeDataType* deepCopy();

	SchemeDataType& operator=(const SchemeDataType& r);

	std::vector<std::string> to_s();
	std::vector<std::string> to_s_inner();
	void print();
	static int to_s_counter;


	~SchemeDataType();

	bool operator==(SchemeDataType* const rhs);
};

SchemeDataType* deepCopyOf(SchemeDataType* data);
// debugging utils
void dumpData(const SchemeDataType& data);
void dumpConsCell(const SchemeDataType& data);

void assign(int registerId, SchemeDataType* const r);
