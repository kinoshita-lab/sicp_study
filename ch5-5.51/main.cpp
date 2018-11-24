#include <cstdio>
#include "eceval.h"
#include "env.h"

int main()
{
	setup_environment();
	
	while (true) {
		eceval();
	}

	return 0;
}
