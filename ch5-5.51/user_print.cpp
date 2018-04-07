#include <iostream>
#include "types.h"

using namespace std;

void user_print(SchemeDataType* const reg)
{	
	const auto strings = reg->to_s();
	for (auto&& s : strings) {
		cout << s << " ";
	}
	cout << endl;
}


