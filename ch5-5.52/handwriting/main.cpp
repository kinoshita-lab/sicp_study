#include "global.h"
#include "types.h"
#include "compiled.out.function_prototypes.h"
#include "env.h"
#include "stack.h"
#include "cons_man.h"

auto main() -> int
{
    s.initialize();
    setup_environment();
    compiled_procedure_start();
    registers[ARGL] = list(1, new SchemeDataType(SchemeDataType::Integer, 2));
    registers[CONTINUE] = new SchemeDataType(entry1);
    entry1();
    printf("Result is: %d\n", registers[VAL]->intValue);
    return 0;    
}
