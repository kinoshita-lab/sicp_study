#include <iostream>
#include "types.h"

using namespace std;

void user_print(RegisterType& reg)
{	
	if (!reg.size()) {
		cout << "Register is Empty!" << endl;
	}

	const auto& top = reg.front();
	const auto& first = top.front();
	
	switch (first.type) {
	case RegisterElementCore::Integer:
		cout << first.value.intValue << endl;
		break;
	case RegisterElementCore::String:
		cout << first.value.stringValue << endl;
		break;
	default:
		cout << "user_print: complex data element" << endl;
	}
	
}


