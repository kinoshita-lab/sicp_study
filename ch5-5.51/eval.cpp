#include <iostream>
#include "eval.h"
#include "types.h"

using namespace std;

void ev_self_eval(RegisterType& reg)
{
	registers[VAL] = reg;
}

void ev_variable(RegisterType& reg)
{
	cout << "todo: ev_variable(): impl lookup-variable-value" << endl;
}
