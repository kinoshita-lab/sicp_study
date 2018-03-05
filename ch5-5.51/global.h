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

SchemeDataType* get_global_environment();

