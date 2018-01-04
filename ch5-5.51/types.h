#pragma once
#include <list>
#include <string>
#include <array>

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

typedef std::list<std::string> RegisterType; // 前が最新
extern std::array<RegisterType, NumberOfRegisters> registers;
