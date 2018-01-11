#include <iostream>
#include "eval.h"
#include "types.h"
#include "global.h"
#include "env.h"

using namespace std;

void ev_self_eval(RegisterType& reg)
{
	registers[VAL] = reg;
}

void ev_variable(RegisterType& reg)
{
	registers[VAL] = lookup_variable_value(reg);
}
