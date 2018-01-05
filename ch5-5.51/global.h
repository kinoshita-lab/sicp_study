#pragma once

#include "types.h"

extern RegisterType registers[NumberOfRegisters];
extern RegisterType the_global_environment;

RegisterType& get_global_environment();

