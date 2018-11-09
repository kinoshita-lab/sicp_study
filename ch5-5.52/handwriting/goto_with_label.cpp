#include "types.h"
#include "goto_with_label.h"
#include "compiled.out.function_prototypes.h"

#define call_function_if_label_eq(_labelname, _func) if (std::string(label) == _labelname) { return _func(); }
void goto_with_label(const char* label)
{
    call_function_if_label_eq("AFTER_LAMBDA2", after_lambda2);
    call_function_if_label_eq("AFTER_CALL8", after_call8);
    call_function_if_label_eq("FALSE_BRANCH4", false_branch4);
    call_function_if_label_eq("PRIMITIVE_BRANCH9", primitive_branch9);
    call_function_if_label_eq("AFTER_CALL11", after_call11);
    call_function_if_label_eq("PRIMITIVE_BRANCH12", primitive_branch12);
    call_function_if_label_eq("AFTER_CALL14", after_call14);
    call_function_if_label_eq("PRIMITIVE_BRANCH_15", primitive_branch15);
}

void goto_with_label(const SchemeDataType* reg)
{
    if (reg->type != SchemeDataType::String) {
        return;
    }

    goto_with_label(reg->stringValue);
}