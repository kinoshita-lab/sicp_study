#include "global.h"

SchemeDataType* registers[NumberOfRegisters];
SchemeDataType* the_global_environment;

SchemeDataType* get_global_environment()
{
	return the_global_environment;
}
