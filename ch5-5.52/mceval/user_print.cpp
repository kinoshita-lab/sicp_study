#include <iostream>
#include "types.h"

using namespace std;

void user_print(SchemeDataType* const reg)
{	
	const auto strings = reg->to_s();

	for (auto it = strings.begin(); it != strings.end(); ++it) {
		cout << *it;

		if (*it == "(") {
			continue;
		}

		auto next = it + 1;
		if (next == strings.end()) {
			continue;
		} 
		
		if (*next == ")") {
			continue;
		}

		cout << " ";
	}
	cout << endl;
}


