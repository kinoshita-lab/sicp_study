#include <iostream>
#include "dispatch.h"
#include "types.h"
using namespace std;

bool self_evaluating_p(SchemeDataType* const reg)
{	
	return reg->type == SchemeDataType::Integer || reg->type == SchemeDataType::String;
}

bool variable_p(SchemeDataType* const reg)
{	
	return reg->type == SchemeDataType::Symbol;
}


