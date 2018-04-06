#include <iostream>
#include "eval.h"
#include "types.h"
#include "global.h"
#include "env.h"
#include "syntax.h"

using namespace std;

void ev_self_eval(SchemeDataType* const reg)
{
	registers[VAL] = reg;
}

void ev_variable(SchemeDataType* const reg)
{
	registers[VAL] = lookup_variable_value(reg, the_global_environment);
}


void ev_quote(SchemeDataType* const reg)
{
	registers[VAL] = text_of_quotation(reg);
}