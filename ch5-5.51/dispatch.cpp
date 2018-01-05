#include <iostream>
#include "dispatch.h"
#include "types.h"
using namespace std;

bool self_evaluating_p(RegisterType& reg)
{
	const auto& re = reg.front();
	
	if (re.size() != 1) {
		return false;
	}

	const auto& rc = re.front();
	return rc.type == RegisterElementCore::Integer || rc.type == RegisterElementCore::String;
}

bool variable_p(RegisterType& reg)
{
	const auto& re = reg.front();
	
	if (re.size() != 1) {
		return false;
	}

	const auto& rc = re.front();
	
	return rc.type == RegisterElementCore::Symbol;
}


