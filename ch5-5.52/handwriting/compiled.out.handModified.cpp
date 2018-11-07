void compiled_procedure_start() { // これつける
assign(VAL, make_compiled_procedure("entry1", entry1, registers[ENV])); // (assign val (op make-compiled-procedure) (label entry1) (reg env))
goto_with_label("AFTER_LAMBDA2"); // (goto (label after-lambda2))
}
void entry1() {// entry1
assign(ENV, compiled_procedure_env(PROC));// (assign env (op compiled-procedure-env) (reg proc))
assign(ENV, extend_environment(new SchemeDataType(SchemeDataType::Symbol, "n"),  registers[ARGL], registers[ENV]));// (assign env (op extend-environment) (const (n)) (reg argl) (reg env))
s.save(registers[CONTINUE]);// (save continue)
s.save(registers[ENV]);// (save env)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::Symbol, "="), registers[ENV])); // (assign proc (op lookup-variable-value) (const =) (reg env))
assign(VAL, new SchemeDataType(1)); // (assign val (const 1))
assign(ARGL, list(registers[VAL])); // (assign argl (op list) (reg val))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::Symbol, "n"), registers[ENV]));// (assign val (op lookup-variable-value) (const n) (reg env))
assign(ARGL, cons(registers[VAL], registers[ARGL])); // (assign argl (op cons) (reg val) (reg argl))
if (primitive_procedure_p(registers[PROC])) {// (test (op primitive-procedure?) (reg proc))
return primitive_branch6();// (branch (label primitive-branch6))
}
compiled_branch7();
}
void compiled_branch7() {// compiled-branch7
assign(CONTINUE, new SchemeDataType(SchemeDataType::String, "AFTER_CALL8"));// (assign continue (label after-call8))
assign(VAL, compiled_procedure_entry(registers[PROC])); // (assign val (op compiled-procedure-entry) (reg proc))
goto_with_label(registers[VAL]); // (goto (reg val))
}
void primitive_branch6() {// primitive-branch6
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply-primitive-procedure) (reg proc) (reg argl))
after_call8();
}
void after_call8() {// after-call8
s.restore(ENV);// (restore env)
s.restore(CONTINUE);// (restore continue)
if (false_p(registers[VAL])) {// (test (op false?) (reg val))
return goto_with_label("FALSE_BRANCH4");// (branch (label false-branch4))
}
true_branch3();
}
void true_branch3() {// true-branch3
assign(VAL, new SchemeDataType(1));// (assign val (const 1))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
}
void false_branch4() {// false-branch4
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::Symbol, "*"), registers[ENV]));// (assign proc (op lookup-variable-value) (const *) (reg env))
s.save(CONTINUE); // (save continue)
s.save(PROC); // (save proc)
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::Symbol, "n"), registers[ENV]));// (assign val (op lookup-variable-value) (const n) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
s.save(ARGL);// (save argl)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::Symbol, "factorial") , registers[ENV]));// (assign proc (op lookup-variable-value) (const factorial) (reg env))
s.save(PROC);// (save proc)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::Symbol, "-"), registers[ENV]));// (assign proc (op lookup-variable-value) (const -) (reg env))
assign(VAL, new SchemeDataType(1));// (assign val (const 1))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::Symbol, "n"), registers[ENV]));// (assign val (op lookup-variable-value) (const n) (reg env))
assign(ARGL, cons(registers[VAL], registers[ARGL]));// (assign argl (op cons) (reg val) (reg argl))
if (primitive_procedure_p(registers[PROC])) {// (test (op primitive-procedure?) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH9");// (branch (label primitive-branch9))
}
compiled_branch10();
}
void compiled_branch10() {// compiled-branch10
assign(CONTINUE, new SchemeDataType(SchemeDataType::String, "AFTER_CALL11"));// (assign continue (label after-call11))
assign(VAL, compiled_procedure_entry(registers[PROC])); // (assign val (op compiled-procedure-entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))
primitive_branch9();
}
void primitive_branch9() {// primitive-branch9
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL])); // (assign val (op apply-primitive-procedure) (reg proc) (reg argl))
after_call11();
}
void after_call11() {// after-call11
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
s.restore(PROC);// (restore proc)
if (primitive_procedure_p(registers[PROC])) {// (test (op primitive-procedure?) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH12");// (branch (label primitive-branch12))
}
compiled_branch13();
}
void compiled_branch13() {// compiled-branch13
assign(CONTINUE, new SchemeDataType(SchemeDataType::String, "AFTER_CALL14"));// (assign continue (label after-call14))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled-procedure-entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))
}
void primitive_branch12() {// primitive-branch12
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply-primitive-procedure) (reg proc) (reg argl))
after_call14();
}
void after_call14() {// after-call14
s.restore(ARGL);// (restore argl)
assign(ARGL, cons(registers[VAL], registers[ARGL])); // (assign argl (op cons) (reg val) (reg argl))
s.restore(PROC);// (restore proc)
s.restore(CONTINUE);// (restore continue)
if (primitive_procedure_p(registers[PROC])) {// (test (op primitive-procedure?) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH_15");// (branch (label primitive-branch15))
}
compiled_branch_16();
}
void compiled_branch_16() {// compiled-branch16
assign(VAL, compiled_procedure_entry(registers[PROC])); // (assign val (op compiled-procedure-entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))
primitive_branch15();
}
void primitive_branch15() {// primitive-branch15
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply-primitive-procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call17();
}
void after_call17() {// after-call17
after_if5();
}
void after_if5() {// after-if5
after_lambda2();
}
void after_lambda2() {// after-lambda2
define_variable(new SchemeDataType(SchemeDataType::Symbol, "factorial"), registers[VAL], registers[ENV]);// (perform (op define-variable!) (const factorial) (reg val) (reg env))
assign(VAL, new SchemeDataType(SchemeDataType::String, "OK"));// (assign val (const ok))
}
