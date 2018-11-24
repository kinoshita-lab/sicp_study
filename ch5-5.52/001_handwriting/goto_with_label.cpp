#include "types.h"
#include "goto_with_label.h"
#include "compiled.out.function_prototypes.h"

#define call_function_if_label_eq(_labelname, _func) if (strLabel == _labelname) { return _func(); }

void goto_with_label(const char* label)
{
    const auto strLabel = std::string(label);
    if (strLabel == "AFTER_LAMBDA2") { 
        return after_lambda2();
    }
    
    if(strLabel == "AFTER_CALL8") return after_call8();
    if(strLabel == "FALSE_BRANCH4") return false_branch4();
    if(strLabel == "PRIMITIVE_BRANCH9") return primitive_branch9();
    if(strLabel == "AFTER_CALL11") return after_call11();
    if(strLabel == "PRIMITIVE_BRANCH12") return primitive_branch12();
    if(strLabel == "AFTER_CALL14") return after_call14();
    if(strLabel == "PRIMITIVE_BRANCH_15") return primitive_branch15();
    
    if (strLabel == "return") {
        throw "finished";
    }
}

// ここに entry1で来ることある
void goto_with_label(const SchemeDataType* reg)
{
    if (reg->type == SchemeDataType::TypeId::String) {
        return goto_with_label(reg->stringValue);
    }

    if (reg->type == SchemeDataType::TypeId::CompiledProcedure)
    {
        return (*reg->compiledProcedure)();
    }

    return;
}