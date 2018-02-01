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

extern RegisterType registers[NumberOfRegisters];
extern RegisterType* the_global_environment;

RegisterType* get_global_environment();

