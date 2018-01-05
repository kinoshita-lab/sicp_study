#include "eval.h"
#include "types.h"

void ev_self_eval(RegisterType& reg)
{
	registers[VAL] = reg;
}
