#pragma once

#include "types.h"

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

extern SchemeDataType* registers[NumberOfRegisters];
extern SchemeDataType* the_global_environment;
extern SchemeDataType* the_empty_environment;

