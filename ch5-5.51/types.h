#pragma once
#include <cstring>
#include <cstdlib>
#include <list>
#include <iostream>
#include <memory>
enum RegisterId
{
	EXP,
	ENV,
	VAL,
	PROC,
	ARGL,
	CONTINUE,
	UNEV,
	NumberOfRegisters
};

struct RegisterElementCore
{
	enum TypeId
	{
		Integer,
		String,
		Symbol,
		Unknown
	};

	union Value
	{
		int intValue;
		char* stringValue;
		char* symbolValue;
		void* others;
		
		Value() : others(nullptr) {}
	};
	
	int type;
	Value value;

	void dump() {
		switch (type) {
		case Integer:
			std::cout << "type: Integer: value: " << value.intValue << std::endl;
			break;
		case String:
			std::cout << "type: String: value: " << value.stringValue << std::endl;
			break;
		case Symbol:
			std::cout << "type: Symbol: value: " << value.symbolValue << std::endl;
			break;
		default:
			std::cout << "type: Unknown: value: " << value.others << std::endl;
			break;
		}
	}

	RegisterElementCore() : type(Unknown) {}

	RegisterElementCore(const int v) : type(Integer) {
		value.intValue = v;
	}

	// string or symbol
	RegisterElementCore(const int typeId, const char* s) : type(typeId) {
		const auto length = strlen(s);
		
		if (typeId == String) {
			value.stringValue = (char*)malloc(length);
			strcpy(value.stringValue, s);
		}

		if (typeId == Symbol) {
			value.symbolValue = (char*)malloc(length);
			strcpy(value.symbolValue, s);
		}
	}

	RegisterElementCore(const RegisterElementCore& r) {
		type = r.type;

		if (type == Integer) {
			value.intValue = r.value.intValue;
		}
		
		if (type == String) {
			const auto length = strlen(r.value.stringValue);
			value.stringValue = (char*)malloc(length);
			strcpy(value.stringValue, r.value.stringValue);
		}

		if (type == Symbol) {
			const auto length = strlen(r.value.symbolValue);
			value.symbolValue = (char*)malloc(length);
			strcpy(value.symbolValue, r.value.symbolValue);
		}
	}

	RegisterElementCore& operator=(const RegisterElementCore& r) {
		type = r.type;
		
		if (type == Integer) {
			value.intValue = r.value.intValue;
		}
		
		if (type == String) {
			const auto length = strlen(r.value.stringValue);
			value.stringValue = (char*)malloc(length);
			strcpy(value.stringValue, r.value.stringValue);
		}

		if (type == Symbol) {
			const auto length = strlen(r.value.symbolValue);
			value.symbolValue = (char*)malloc(length);
			strcpy(value.symbolValue, r.value.symbolValue);
		}

		return *this;
	}
	
	~RegisterElementCore() {
		if (type == String) {
			free(value.stringValue);
			return;
		}

		if (type == Symbol) {
			free(value.symbolValue);
			return;
		}
	}
};

typedef std::list<RegisterElementCore> RegisterElement;
typedef std::list<RegisterElement> RegisterType; // 前が最新
extern RegisterType registers[NumberOfRegisters];
extern RegisterType the_global_environment;
