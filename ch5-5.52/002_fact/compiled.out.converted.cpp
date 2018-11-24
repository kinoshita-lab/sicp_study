void compiled_procedure_start(){
assign(VAL, make_compiled_procedure("ENTRY1", entry1, registers[ENV]));// (assign val (op make_compiled_procedure) (label entry1) (reg env))
goto_with_label("AFTER_LAMBDA2");// (goto (label after_lambda2))

}
void entry1()
{// entry1
assign(ENV, compiled_procedure_env(PROC));// (assign env (op compiled_procedure_env) (reg proc))
assign(ENV, extend_environment(list(1, new SchemeDataType(SchemeDataType::TypeId::Symbol, "n")), registers[ARGL], registers[ENV]));// (assign env (op extend_environment) (const n) (reg argl) (reg env))
s.save(CONTINUE);// (save continue)
s.save(ENV);// (save env)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "="), registers[ENV]));// (assign proc (op lookup_variable_value) (const =) (reg env))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::Integer, 1));// (assign val (const 1))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "n"), registers[ENV]));// (assign val (op lookup_variable_value) (const n) (reg env))
assign(ARGL, cons(registers[VAL], registers[ARGL]));// (assign argl (op cons) (reg val) (reg argl))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH6");
}// (branch (label primitive_branch6))
compiled_branch7();
}
void compiled_branch7()
{// compiled_branch7
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL8"));// (assign continue (label after_call8))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))
primitive_branch6();
}
void primitive_branch6()
{// primitive_branch6
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call8();
}
void after_call8()
{// after_call8
s.restore(ENV);// (restore env)
s.restore(CONTINUE);// (restore continue)
if ( false_p(registers[VAL]) ) {// (test (op false_p) (reg val))
return goto_with_label("FALSE_BRANCH4");
}// (branch (label false_branch4))
true_branch3();
}
void true_branch3()
{// true_branch3
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::Integer, 1));// (assign val (const 1))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
false_branch4();
}
void false_branch4()
{// false_branch4
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "*"), registers[ENV]));// (assign proc (op lookup_variable_value) (const *) (reg env))
s.save(CONTINUE);// (save continue)
s.save(PROC);// (save proc)
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "n"), registers[ENV]));// (assign val (op lookup_variable_value) (const n) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
s.save(ARGL);// (save argl)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "factorial"), registers[ENV]));// (assign proc (op lookup_variable_value) (const factorial) (reg env))
s.save(PROC);// (save proc)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "-"), registers[ENV]));// (assign proc (op lookup_variable_value) (const -) (reg env))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::Integer, 1));// (assign val (const 1))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "n"), registers[ENV]));// (assign val (op lookup_variable_value) (const n) (reg env))
assign(ARGL, cons(registers[VAL], registers[ARGL]));// (assign argl (op cons) (reg val) (reg argl))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH9");
}// (branch (label primitive_branch9))
compiled_branch10();
}
void compiled_branch10()
{// compiled_branch10
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL11"));// (assign continue (label after_call11))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))
primitive_branch9();
}
void primitive_branch9()
{// primitive_branch9
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call11();
}
void after_call11()
{// after_call11
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
s.restore(PROC);// (restore proc)
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH12");
}// (branch (label primitive_branch12))
compiled_branch13();
}
void compiled_branch13()
{// compiled_branch13
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL14"));// (assign continue (label after_call14))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))
primitive_branch12();
}
void primitive_branch12()
{// primitive_branch12
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call14();
}
void after_call14()
{// after_call14
s.restore(ARGL);// (restore argl)
assign(ARGL, cons(registers[VAL], registers[ARGL]));// (assign argl (op cons) (reg val) (reg argl))
s.restore(PROC);// (restore proc)
s.restore(CONTINUE);// (restore continue)
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH15");
}// (branch (label primitive_branch15))
compiled_branch16();
}
void compiled_branch16()
{// compiled_branch16
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))
primitive_branch15();
}
void primitive_branch15()
{// primitive_branch15
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call17();
}
void after_call17()
{// after_call17
after_if5();
}
void after_if5()
{// after_if5
after_lambda2();
}
void after_lambda2()
{// after_lambda2
define_variable(new SchemeDataType(SchemeDataType::TypeId::Symbol, "factorial"), registers[VAL], registers[ENV]);// (perform (op define_variable) (const factorial) (reg val) (reg env))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "ok"));// (assign val (const ok))
}
