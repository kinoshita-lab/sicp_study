#include <string>
#include "types.h"
#include "goto_with_label.h"
#include "compiled.out.function_prototypes.h"

void goto_with_label(const char* label)
{
    const auto strLabel = std::string(label);
	if(strLabel == "COMPILED_PROCEDURE_START") return compiled_procedure_start();
	if(strLabel == "ENTRY1") return entry1();
	if(strLabel == "COMPILED_BRANCH7") return compiled_branch7();
	if(strLabel == "PRIMITIVE_BRANCH6") return primitive_branch6();
	if(strLabel == "AFTER_CALL8") return after_call8();
	if(strLabel == "TRUE_BRANCH3") return true_branch3();
	if(strLabel == "FALSE_BRANCH4") return false_branch4();
	if(strLabel == "COMPILED_BRANCH10") return compiled_branch10();
	if(strLabel == "PRIMITIVE_BRANCH9") return primitive_branch9();
	if(strLabel == "AFTER_CALL11") return after_call11();
	if(strLabel == "COMPILED_BRANCH13") return compiled_branch13();
	if(strLabel == "PRIMITIVE_BRANCH12") return primitive_branch12();
	if(strLabel == "AFTER_CALL14") return after_call14();
	if(strLabel == "COMPILED_BRANCH16") return compiled_branch16();
	if(strLabel == "PRIMITIVE_BRANCH15") return primitive_branch15();
	if(strLabel == "AFTER_CALL17") return after_call17();
	if(strLabel == "AFTER_IF5") return after_if5();
	if(strLabel == "AFTER_LAMBDA2") return after_lambda2();
    if (strLabel == "return") {
        throw "finished";
    }
}

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
