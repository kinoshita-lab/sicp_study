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
		Unknown
	};

	union Value
	{
		int intValue;
		char* stringValue;
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
		default:
			std::cout << "type: Unknown: value: " << value.others << std::endl;
			break;
		}
	}

	RegisterElementCore() : type(Unknown) {}

	RegisterElementCore(const char* const s) : type(String) {
		const auto length = strlen(s);
		value.stringValue = (char*)malloc(length);
		strcpy(value.stringValue, s);
	}

	RegisterElementCore(const int v) : type(Integer) {
		value.intValue = v;
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

		return *this;
	}
	
	~RegisterElementCore() {
		if (type == String) {
			free(value.stringValue);
			return;
		}
	}
};

typedef std::list<RegisterElementCore> RegisterElement;
typedef std::list<RegisterElement> RegisterType; // 前が最新
extern RegisterType registers[NumberOfRegisters];
