#pragma once

struct SchemeDataType;
struct ConsCell
{
	SchemeDataType* car;
	SchemeDataType* cdr;

	ConsCell() : car(nullptr), cdr(nullptr) {}

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
		Unknown
	};
	int type;

	// vals
	int intValue;
	char* stringValue;
	char* symbolValue;
	ConsCell cellValue;
	void* othersValue;

	SchemeDataType();
	SchemeDataType(const int v);
	SchemeDataType(const int typeId, const char* s); 	// string or symbol
	SchemeDataType(const SchemeDataType& r);
	SchemeDataType& operator=(const SchemeDataType& r);
	~SchemeDataType();
};

void dumpData(const SchemeDataType& data);
void dumpConsCell(const SchemeDataType& data);

typedef SchemeDataType RegisterType; // 前が最新
