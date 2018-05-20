void init();
void entry1();
void compiled_branch7();
void primitive_branch6();
void after_call8();
void true_branch3();
void false_branch4();
void compiled_branch10();
void primitive_branch9();
void after_call11();
void compiled_branch13();
void primitive_branch12();
void after_call14();
void compiled_branch16();
void primitive_branch15();
void after_call17();
void after_if5();
void after_lambda2();
void init()
{
// (assign val (op make_compiled_procedure) (label entry1) (reg env))
// (goto (label after_lambda2))
	entry1();
}
void entry1()
{
// (assign env (op compiled_procedure_env) (reg proc))
// (assign env (op extend_environment) (const n) (reg argl) (reg env))
// (save continue)
// (save env)
// (assign proc (op lookup_variable_value) (const =) (reg env))
// (assign val (const 1))
// (assign argl (op list) (reg val))
// (assign val (op lookup_variable_value) (const n) (reg env))
// (assign argl (op cons) (reg val) (reg argl))
// (test (op primitive_procedure_) (reg proc))
// (branch (label primitive_branch6))
	compiled_branch7();
}
void compiled_branch7()
{
// (assign continue (label after_call8))
// (assign val (op compiled_procedure_entry) (reg proc))
// (goto (reg val))
	primitive_branch6();
}
void primitive_branch6()
{
// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
	after_call8();
}
void after_call8()
{
// (restore env)
// (restore continue)
// (test (op false_) (reg val))
// (branch (label false_branch4))
	true_branch3();
}
void true_branch3()
{
// (assign val (const 1))
// (goto (reg continue))
	false_branch4();
}
void false_branch4()
{
// (assign proc (op lookup_variable_value) (const *) (reg env))
// (save continue)
// (save proc)
// (assign val (op lookup_variable_value) (const n) (reg env))
// (assign argl (op list) (reg val))
// (save argl)
// (assign proc (op lookup_variable_value) (const factorial) (reg env))
// (save proc)
// (assign proc (op lookup_variable_value) (const _) (reg env))
// (assign val (const 1))
// (assign argl (op list) (reg val))
// (assign val (op lookup_variable_value) (const n) (reg env))
// (assign argl (op cons) (reg val) (reg argl))
// (test (op primitive_procedure_) (reg proc))
// (branch (label primitive_branch9))
	compiled_branch10();
}
void compiled_branch10()
{
// (assign continue (label after_call11))
// (assign val (op compiled_procedure_entry) (reg proc))
// (goto (reg val))
	primitive_branch9();
}
void primitive_branch9()
{
// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
	after_call11();
}
void after_call11()
{
// (assign argl (op list) (reg val))
// (restore proc)
// (test (op primitive_procedure_) (reg proc))
// (branch (label primitive_branch12))
	compiled_branch13();
}
void compiled_branch13()
{
// (assign continue (label after_call14))
// (assign val (op compiled_procedure_entry) (reg proc))
// (goto (reg val))
	primitive_branch12();
}
void primitive_branch12()
{
// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
	after_call14();
}
void after_call14()
{
// (restore argl)
// (assign argl (op cons) (reg val) (reg argl))
// (restore proc)
// (restore continue)
// (test (op primitive_procedure_) (reg proc))
// (branch (label primitive_branch15))
	compiled_branch16();
}
void compiled_branch16()
{
// (assign val (op compiled_procedure_entry) (reg proc))
// (goto (reg val))
	primitive_branch15();
}
void primitive_branch15()
{
// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
// (goto (reg continue))
	after_call17();
}
void after_call17()
{
	after_if5();
}
void after_if5()
{
	after_lambda2();
}
void after_lambda2()
{
// (perform (op define_variable__) (const factorial) (reg val) (reg env))
// (assign val (const ok))
	return; 
}
