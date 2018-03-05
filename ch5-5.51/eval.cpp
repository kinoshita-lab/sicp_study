#include <iostream>
#include "eval.h"
#include "types.h"
#include "global.h"
#include "env.h"

using namespace std;

void ev_self_eval(SchemeDataType* const reg)
{
	registers[VAL] = reg;
}

void ev_variable(SchemeDataType* const reg)
{
	registers[VAL] = lookup_variable_value(reg, get_global_environment());
}
