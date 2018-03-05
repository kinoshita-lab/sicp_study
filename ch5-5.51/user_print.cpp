#include <iostream>
#include "types.h"

using namespace std;

void user_print(SchemeDataType* const reg)
{	
	switch (reg->type) {
	case SchemeDataType::Integer:
		cout << reg->intValue << endl;
		break;
	case SchemeDataType::String:
		cout << reg->stringValue << endl;
		break;
	case SchemeDataType::Symbol:
		cout << reg->symbolValue << endl;
		break;
	default:
		cout << "user_print: complex data element" << endl;
	}
	
}


