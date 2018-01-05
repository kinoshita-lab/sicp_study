#include "global.h"

RegisterType registers[NumberOfRegisters];
RegisterType the_global_environment;

RegisterType& get_global_environment()
{
	return the_global_environment;
}
