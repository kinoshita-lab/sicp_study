#include "compiled.h"
#include "global.h"
#include "types.h"

auto main() -> int
{
    compiled_code_entry();
    dumpData(*registers[VAL]);
    return 0;    
}
