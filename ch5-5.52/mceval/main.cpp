#include "global.h"
#include "types.h"
#include "compiled.out.function_prototypes.h"
#include "env.h"
#include "stack.h"
#include "cons_man.h"
#include "support.h"
#include "goto_with_label.h"
#include "compiled.h"

auto main() -> int
{
    s.initialize();
    setup_environment();
    define_variable(new SchemeDataType(SchemeDataType::TypeId::Symbol, "the_empty_environment"), the_empty_environment, registers[ENV]);
    define_variable(new SchemeDataType(SchemeDataType::TypeId::Symbol, "the_global_environment"), registers[ENV], registers[ENV]);



    compiled_procedure_start();
    registers[ENV]->print();


    define_variable(new SchemeDataType(SchemeDataType::TypeId::Symbol, "true"), 
        new SchemeDataType(SchemeDataType::TypeId::SchemeBoolean, true), registers[ENV]);
    define_variable(new SchemeDataType(SchemeDataType::TypeId::Symbol, "false"), 
        new SchemeDataType(SchemeDataType::TypeId::SchemeBoolean, false), registers[ENV]);        

    while (true) {
        // set driver-loop to val
        assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "driver_loop"), registers[ENV]));
        assign(VAL, compiled_procedure_entry(registers[PROC]));
        registers[CONTINUE] = new SchemeDataType(SchemeDataType::TypeId::String, "return");
        
        try {
            goto_with_label(registers[VAL]);
        }
        catch (const char*) {
            ;
        }
    }
    return 0;    
}
