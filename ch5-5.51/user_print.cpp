#include <iostream>
#include "types.h"

using namespace std;

void user_print(SchemeDataType* const reg)
{	
	cout << reg->to_s() << endl;
}


