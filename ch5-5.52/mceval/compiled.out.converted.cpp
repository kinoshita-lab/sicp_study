void compiled_procedure_start(){
assign(VAL, make_compiled_procedure("ENTRY42", entry42, registers[ENV]));// (assign val (op make_compiled_procedure) (label entry42) (reg env))
goto_with_label("AFTER_LAMBDA43");// (goto (label after_lambda43))

}
void entry42()
{// entry42
assign(ENV, compiled_procedure_env(PROC));// (assign env (op compiled_procedure_env) (reg proc))
assign(ENV, extend_environment(list(2, new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp") , new SchemeDataType(SchemeDataType::TypeId::Symbol, "env") ), registers[ARGL], registers[ENV]));// (assign env (op extend_environment) (const (exp env)) (reg argl) (reg env))
s.save(CONTINUE);// (save continue)
s.save(ENV);// (save env)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "self_evaluating_p"), registers[ENV]));// (assign proc (op lookup_variable_value) (const self_evaluating_p) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp"), registers[ENV]));// (assign val (op lookup_variable_value) (const exp) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH47");
}// (branch (label primitive_branch47))
compiled_branch48();
}
void compiled_branch48()
{// compiled_branch48
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL49"));// (assign continue (label after_call49))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch47()
{// primitive_branch47
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call49();
}
void after_call49()
{// after_call49
s.restore(ENV);// (restore env)
s.restore(CONTINUE);// (restore continue)
if ( false_p(registers[VAL]) ) {// (test (op false_p) (reg val))
return goto_with_label("FALSE_BRANCH45");
}// (branch (label false_branch45))
true_branch44();
}
void true_branch44()
{// true_branch44
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp"), registers[ENV]));// (assign val (op lookup_variable_value) (const exp) (reg env))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))

}
void false_branch45()
{// false_branch45
s.save(CONTINUE);// (save continue)
s.save(ENV);// (save env)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "variable_p"), registers[ENV]));// (assign proc (op lookup_variable_value) (const variable_p) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp"), registers[ENV]));// (assign val (op lookup_variable_value) (const exp) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH53");
}// (branch (label primitive_branch53))
compiled_branch54();
}
void compiled_branch54()
{// compiled_branch54
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL55"));// (assign continue (label after_call55))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch53()
{// primitive_branch53
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call55();
}
void after_call55()
{// after_call55
s.restore(ENV);// (restore env)
s.restore(CONTINUE);// (restore continue)
if ( false_p(registers[VAL]) ) {// (test (op false_p) (reg val))
return goto_with_label("FALSE_BRANCH51");
}// (branch (label false_branch51))
true_branch50();
}
void true_branch50()
{// true_branch50
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "lookup_variable_value"), registers[ENV]));// (assign proc (op lookup_variable_value) (const lookup_variable_value) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "env"), registers[ENV]));// (assign val (op lookup_variable_value) (const env) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp"), registers[ENV]));// (assign val (op lookup_variable_value) (const exp) (reg env))
assign(ARGL, cons(registers[VAL], registers[ARGL]));// (assign argl (op cons) (reg val) (reg argl))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH56");
}// (branch (label primitive_branch56))
compiled_branch57();
}
void compiled_branch57()
{// compiled_branch57
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch56()
{// primitive_branch56
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call58();
}
void after_call58()
{// after_call58

}
void false_branch51()
{// false_branch51
s.save(CONTINUE);// (save continue)
s.save(ENV);// (save env)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "application_p"), registers[ENV]));// (assign proc (op lookup_variable_value) (const application_p) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp"), registers[ENV]));// (assign val (op lookup_variable_value) (const exp) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH62");
}// (branch (label primitive_branch62))
compiled_branch63();
}
void compiled_branch63()
{// compiled_branch63
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL64"));// (assign continue (label after_call64))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch62()
{// primitive_branch62
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call64();
}
void after_call64()
{// after_call64
s.restore(ENV);// (restore env)
s.restore(CONTINUE);// (restore continue)
if ( false_p(registers[VAL]) ) {// (test (op false_p) (reg val))
return goto_with_label("FALSE_BRANCH60");
}// (branch (label false_branch60))
true_branch59();
}
void true_branch59()
{// true_branch59
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "apply"), registers[ENV]));// (assign proc (op lookup_variable_value) (const apply) (reg env))
s.save(CONTINUE);// (save continue)
s.save(PROC);// (save proc)
s.save(ENV);// (save env)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "list_of_values"), registers[ENV]));// (assign proc (op lookup_variable_value) (const list_of_values) (reg env))
s.save(PROC);// (save proc)
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "env"), registers[ENV]));// (assign val (op lookup_variable_value) (const env) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
s.save(ARGL);// (save argl)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "operands"), registers[ENV]));// (assign proc (op lookup_variable_value) (const operands) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp"), registers[ENV]));// (assign val (op lookup_variable_value) (const exp) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH71");
}// (branch (label primitive_branch71))
compiled_branch72();
}
void compiled_branch72()
{// compiled_branch72
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL73"));// (assign continue (label after_call73))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch71()
{// primitive_branch71
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call73();
}
void after_call73()
{// after_call73
s.restore(ARGL);// (restore argl)
assign(ARGL, cons(registers[VAL], registers[ARGL]));// (assign argl (op cons) (reg val) (reg argl))
s.restore(PROC);// (restore proc)
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH74");
}// (branch (label primitive_branch74))
compiled_branch75();
}
void compiled_branch75()
{// compiled_branch75
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL76"));// (assign continue (label after_call76))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch74()
{// primitive_branch74
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call76();
}
void after_call76()
{// after_call76
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
s.restore(ENV);// (restore env)
s.save(ARGL);// (save argl)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "eval"), registers[ENV]));// (assign proc (op lookup_variable_value) (const eval) (reg env))
s.save(PROC);// (save proc)
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "env"), registers[ENV]));// (assign val (op lookup_variable_value) (const env) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
s.save(ARGL);// (save argl)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "operator"), registers[ENV]));// (assign proc (op lookup_variable_value) (const operator) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp"), registers[ENV]));// (assign val (op lookup_variable_value) (const exp) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH65");
}// (branch (label primitive_branch65))
compiled_branch66();
}
void compiled_branch66()
{// compiled_branch66
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL67"));// (assign continue (label after_call67))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch65()
{// primitive_branch65
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call67();
}
void after_call67()
{// after_call67
s.restore(ARGL);// (restore argl)
assign(ARGL, cons(registers[VAL], registers[ARGL]));// (assign argl (op cons) (reg val) (reg argl))
s.restore(PROC);// (restore proc)
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH68");
}// (branch (label primitive_branch68))
compiled_branch69();
}
void compiled_branch69()
{// compiled_branch69
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL70"));// (assign continue (label after_call70))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch68()
{// primitive_branch68
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call70();
}
void after_call70()
{// after_call70
s.restore(ARGL);// (restore argl)
assign(ARGL, cons(registers[VAL], registers[ARGL]));// (assign argl (op cons) (reg val) (reg argl))
s.restore(PROC);// (restore proc)
s.restore(CONTINUE);// (restore continue)
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH77");
}// (branch (label primitive_branch77))
compiled_branch78();
}
void compiled_branch78()
{// compiled_branch78
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch77()
{// primitive_branch77
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call79();
}
void after_call79()
{// after_call79

}
void false_branch60()
{// false_branch60
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "error"), registers[ENV]));// (assign proc (op lookup_variable_value) (const error) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp"), registers[ENV]));// (assign val (op lookup_variable_value) (const exp) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "Unknown expression type __ EVAL"));// (assign val (const Unknown expression type __ EVAL))
assign(ARGL, cons(registers[VAL], registers[ARGL]));// (assign argl (op cons) (reg val) (reg argl))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH80");
}// (branch (label primitive_branch80))
compiled_branch81();
}
void compiled_branch81()
{// compiled_branch81
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch80()
{// primitive_branch80
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call82();
}
void after_call82()
{// after_call82
after_if61();
}
void after_if61()
{// after_if61
after_if52();
}
void after_if52()
{// after_if52
after_if46();
}
void after_if46()
{// after_if46
after_lambda43();
}
void after_lambda43()
{// after_lambda43
define_variable(new SchemeDataType(SchemeDataType::TypeId::Symbol, "eval"), registers[VAL], registers[ENV]);// (perform (op define_variable) (const eval) (reg val) (reg env))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "ok"));// (assign val (const ok))
assign(VAL, make_compiled_procedure("ENTRY83", entry83, registers[ENV]));// (assign val (op make_compiled_procedure) (label entry83) (reg env))
goto_with_label("AFTER_LAMBDA84");// (goto (label after_lambda84))

}
void entry83()
{// entry83
assign(ENV, compiled_procedure_env(PROC));// (assign env (op compiled_procedure_env) (reg proc))
assign(ENV, extend_environment(list(2, new SchemeDataType(SchemeDataType::TypeId::Symbol, "procedure") , new SchemeDataType(SchemeDataType::TypeId::Symbol, "arguments") ), registers[ARGL], registers[ENV]));// (assign env (op extend_environment) (const (procedure arguments)) (reg argl) (reg env))
s.save(CONTINUE);// (save continue)
s.save(ENV);// (save env)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "primitive_procedure_p"), registers[ENV]));// (assign proc (op lookup_variable_value) (const primitive_procedure_p) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "procedure"), registers[ENV]));// (assign val (op lookup_variable_value) (const procedure) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH88");
}// (branch (label primitive_branch88))
compiled_branch89();
}
void compiled_branch89()
{// compiled_branch89
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL90"));// (assign continue (label after_call90))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch88()
{// primitive_branch88
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call90();
}
void after_call90()
{// after_call90
s.restore(ENV);// (restore env)
s.restore(CONTINUE);// (restore continue)
if ( false_p(registers[VAL]) ) {// (test (op false_p) (reg val))
return goto_with_label("FALSE_BRANCH86");
}// (branch (label false_branch86))
true_branch85();
}
void true_branch85()
{// true_branch85
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "apply_primitive_procedure"), registers[ENV]));// (assign proc (op lookup_variable_value) (const apply_primitive_procedure) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "arguments"), registers[ENV]));// (assign val (op lookup_variable_value) (const arguments) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "procedure"), registers[ENV]));// (assign val (op lookup_variable_value) (const procedure) (reg env))
assign(ARGL, cons(registers[VAL], registers[ARGL]));// (assign argl (op cons) (reg val) (reg argl))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH91");
}// (branch (label primitive_branch91))
compiled_branch92();
}
void compiled_branch92()
{// compiled_branch92
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch91()
{// primitive_branch91
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call93();
}
void after_call93()
{// after_call93

}
void false_branch86()
{// false_branch86
s.save(CONTINUE);// (save continue)
s.save(ENV);// (save env)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "compound_procedure_p"), registers[ENV]));// (assign proc (op lookup_variable_value) (const compound_procedure_p) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "procedure"), registers[ENV]));// (assign val (op lookup_variable_value) (const procedure) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH97");
}// (branch (label primitive_branch97))
compiled_branch98();
}
void compiled_branch98()
{// compiled_branch98
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL99"));// (assign continue (label after_call99))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch97()
{// primitive_branch97
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call99();
}
void after_call99()
{// after_call99
s.restore(ENV);// (restore env)
s.restore(CONTINUE);// (restore continue)
if ( false_p(registers[VAL]) ) {// (test (op false_p) (reg val))
return goto_with_label("FALSE_BRANCH95");
}// (branch (label false_branch95))
true_branch94();
}
void true_branch94()
{// true_branch94
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "eval_sequence"), registers[ENV]));// (assign proc (op lookup_variable_value) (const eval_sequence) (reg env))
s.save(CONTINUE);// (save continue)
s.save(PROC);// (save proc)
s.save(ENV);// (save env)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "extend_environment"), registers[ENV]));// (assign proc (op lookup_variable_value) (const extend_environment) (reg env))
s.save(PROC);// (save proc)
s.save(ENV);// (save env)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "procedure_environment"), registers[ENV]));// (assign proc (op lookup_variable_value) (const procedure_environment) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "procedure"), registers[ENV]));// (assign val (op lookup_variable_value) (const procedure) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH106");
}// (branch (label primitive_branch106))
compiled_branch107();
}
void compiled_branch107()
{// compiled_branch107
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL108"));// (assign continue (label after_call108))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch106()
{// primitive_branch106
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call108();
}
void after_call108()
{// after_call108
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
s.restore(ENV);// (restore env)
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "arguments"), registers[ENV]));// (assign val (op lookup_variable_value) (const arguments) (reg env))
assign(ARGL, cons(registers[VAL], registers[ARGL]));// (assign argl (op cons) (reg val) (reg argl))
s.save(ARGL);// (save argl)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "procedure_parameters"), registers[ENV]));// (assign proc (op lookup_variable_value) (const procedure_parameters) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "procedure"), registers[ENV]));// (assign val (op lookup_variable_value) (const procedure) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH103");
}// (branch (label primitive_branch103))
compiled_branch104();
}
void compiled_branch104()
{// compiled_branch104
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL105"));// (assign continue (label after_call105))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch103()
{// primitive_branch103
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call105();
}
void after_call105()
{// after_call105
s.restore(ARGL);// (restore argl)
assign(ARGL, cons(registers[VAL], registers[ARGL]));// (assign argl (op cons) (reg val) (reg argl))
s.restore(PROC);// (restore proc)
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH109");
}// (branch (label primitive_branch109))
compiled_branch110();
}
void compiled_branch110()
{// compiled_branch110
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL111"));// (assign continue (label after_call111))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch109()
{// primitive_branch109
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call111();
}
void after_call111()
{// after_call111
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
s.restore(ENV);// (restore env)
s.save(ARGL);// (save argl)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "procedure_body"), registers[ENV]));// (assign proc (op lookup_variable_value) (const procedure_body) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "procedure"), registers[ENV]));// (assign val (op lookup_variable_value) (const procedure) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH100");
}// (branch (label primitive_branch100))
compiled_branch101();
}
void compiled_branch101()
{// compiled_branch101
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL102"));// (assign continue (label after_call102))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch100()
{// primitive_branch100
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call102();
}
void after_call102()
{// after_call102
s.restore(ARGL);// (restore argl)
assign(ARGL, cons(registers[VAL], registers[ARGL]));// (assign argl (op cons) (reg val) (reg argl))
s.restore(PROC);// (restore proc)
s.restore(CONTINUE);// (restore continue)
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH112");
}// (branch (label primitive_branch112))
compiled_branch113();
}
void compiled_branch113()
{// compiled_branch113
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch112()
{// primitive_branch112
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call114();
}
void after_call114()
{// after_call114

}
void false_branch95()
{// false_branch95
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "error"), registers[ENV]));// (assign proc (op lookup_variable_value) (const error) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "procedure"), registers[ENV]));// (assign val (op lookup_variable_value) (const procedure) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "Unknown procedure type __ APPLY"));// (assign val (const Unknown procedure type __ APPLY))
assign(ARGL, cons(registers[VAL], registers[ARGL]));// (assign argl (op cons) (reg val) (reg argl))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH115");
}// (branch (label primitive_branch115))
compiled_branch116();
}
void compiled_branch116()
{// compiled_branch116
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch115()
{// primitive_branch115
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call117();
}
void after_call117()
{// after_call117
after_if96();
}
void after_if96()
{// after_if96
after_if87();
}
void after_if87()
{// after_if87
after_lambda84();
}
void after_lambda84()
{// after_lambda84
define_variable(new SchemeDataType(SchemeDataType::TypeId::Symbol, "apply"), registers[VAL], registers[ENV]);// (perform (op define_variable) (const apply) (reg val) (reg env))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "ok"));// (assign val (const ok))
assign(VAL, make_compiled_procedure("ENTRY118", entry118, registers[ENV]));// (assign val (op make_compiled_procedure) (label entry118) (reg env))
goto_with_label("AFTER_LAMBDA119");// (goto (label after_lambda119))

}
void entry118()
{// entry118
assign(ENV, compiled_procedure_env(PROC));// (assign env (op compiled_procedure_env) (reg proc))
assign(ENV, extend_environment(list(2, new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp") , new SchemeDataType(SchemeDataType::TypeId::Symbol, "env") ), registers[ARGL], registers[ENV]));// (assign env (op extend_environment) (const (exp env)) (reg argl) (reg env))
s.save(CONTINUE);// (save continue)
s.save(ENV);// (save env)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "true_p"), registers[ENV]));// (assign proc (op lookup_variable_value) (const true_p) (reg env))
s.save(PROC);// (save proc)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "eval"), registers[ENV]));// (assign proc (op lookup_variable_value) (const eval) (reg env))
s.save(PROC);// (save proc)
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "env"), registers[ENV]));// (assign val (op lookup_variable_value) (const env) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
s.save(ARGL);// (save argl)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "if_predicate"), registers[ENV]));// (assign proc (op lookup_variable_value) (const if_predicate) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp"), registers[ENV]));// (assign val (op lookup_variable_value) (const exp) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH123");
}// (branch (label primitive_branch123))
compiled_branch124();
}
void compiled_branch124()
{// compiled_branch124
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL125"));// (assign continue (label after_call125))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch123()
{// primitive_branch123
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call125();
}
void after_call125()
{// after_call125
s.restore(ARGL);// (restore argl)
assign(ARGL, cons(registers[VAL], registers[ARGL]));// (assign argl (op cons) (reg val) (reg argl))
s.restore(PROC);// (restore proc)
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH126");
}// (branch (label primitive_branch126))
compiled_branch127();
}
void compiled_branch127()
{// compiled_branch127
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL128"));// (assign continue (label after_call128))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch126()
{// primitive_branch126
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call128();
}
void after_call128()
{// after_call128
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
s.restore(PROC);// (restore proc)
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH129");
}// (branch (label primitive_branch129))
compiled_branch130();
}
void compiled_branch130()
{// compiled_branch130
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL131"));// (assign continue (label after_call131))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch129()
{// primitive_branch129
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call131();
}
void after_call131()
{// after_call131
s.restore(ENV);// (restore env)
s.restore(CONTINUE);// (restore continue)
if ( false_p(registers[VAL]) ) {// (test (op false_p) (reg val))
return goto_with_label("FALSE_BRANCH121");
}// (branch (label false_branch121))
true_branch120();
}
void true_branch120()
{// true_branch120
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "eval"), registers[ENV]));// (assign proc (op lookup_variable_value) (const eval) (reg env))
s.save(CONTINUE);// (save continue)
s.save(PROC);// (save proc)
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "env"), registers[ENV]));// (assign val (op lookup_variable_value) (const env) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
s.save(ARGL);// (save argl)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "if_consequent"), registers[ENV]));// (assign proc (op lookup_variable_value) (const if_consequent) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp"), registers[ENV]));// (assign val (op lookup_variable_value) (const exp) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH132");
}// (branch (label primitive_branch132))
compiled_branch133();
}
void compiled_branch133()
{// compiled_branch133
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL134"));// (assign continue (label after_call134))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch132()
{// primitive_branch132
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call134();
}
void after_call134()
{// after_call134
s.restore(ARGL);// (restore argl)
assign(ARGL, cons(registers[VAL], registers[ARGL]));// (assign argl (op cons) (reg val) (reg argl))
s.restore(PROC);// (restore proc)
s.restore(CONTINUE);// (restore continue)
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH135");
}// (branch (label primitive_branch135))
compiled_branch136();
}
void compiled_branch136()
{// compiled_branch136
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch135()
{// primitive_branch135
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call137();
}
void after_call137()
{// after_call137

}
void false_branch121()
{// false_branch121
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "eval"), registers[ENV]));// (assign proc (op lookup_variable_value) (const eval) (reg env))
s.save(CONTINUE);// (save continue)
s.save(PROC);// (save proc)
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "env"), registers[ENV]));// (assign val (op lookup_variable_value) (const env) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
s.save(ARGL);// (save argl)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "if_alternative"), registers[ENV]));// (assign proc (op lookup_variable_value) (const if_alternative) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp"), registers[ENV]));// (assign val (op lookup_variable_value) (const exp) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH138");
}// (branch (label primitive_branch138))
compiled_branch139();
}
void compiled_branch139()
{// compiled_branch139
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL140"));// (assign continue (label after_call140))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch138()
{// primitive_branch138
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call140();
}
void after_call140()
{// after_call140
s.restore(ARGL);// (restore argl)
assign(ARGL, cons(registers[VAL], registers[ARGL]));// (assign argl (op cons) (reg val) (reg argl))
s.restore(PROC);// (restore proc)
s.restore(CONTINUE);// (restore continue)
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH141");
}// (branch (label primitive_branch141))
compiled_branch142();
}
void compiled_branch142()
{// compiled_branch142
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch141()
{// primitive_branch141
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call143();
}
void after_call143()
{// after_call143
after_if122();
}
void after_if122()
{// after_if122
after_lambda119();
}
void after_lambda119()
{// after_lambda119
define_variable(new SchemeDataType(SchemeDataType::TypeId::Symbol, "eval_if"), registers[VAL], registers[ENV]);// (perform (op define_variable) (const eval_if) (reg val) (reg env))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "ok"));// (assign val (const ok))
assign(VAL, make_compiled_procedure("ENTRY144", entry144, registers[ENV]));// (assign val (op make_compiled_procedure) (label entry144) (reg env))
goto_with_label("AFTER_LAMBDA145");// (goto (label after_lambda145))

}
void entry144()
{// entry144
assign(ENV, compiled_procedure_env(PROC));// (assign env (op compiled_procedure_env) (reg proc))
assign(ENV, extend_environment(list(2, new SchemeDataType(SchemeDataType::TypeId::Symbol, "exps") , new SchemeDataType(SchemeDataType::TypeId::Symbol, "env") ), registers[ARGL], registers[ENV]));// (assign env (op extend_environment) (const (exps env)) (reg argl) (reg env))
s.save(CONTINUE);// (save continue)
s.save(ENV);// (save env)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "last_exp_p"), registers[ENV]));// (assign proc (op lookup_variable_value) (const last_exp_p) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "exps"), registers[ENV]));// (assign val (op lookup_variable_value) (const exps) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH149");
}// (branch (label primitive_branch149))
compiled_branch150();
}
void compiled_branch150()
{// compiled_branch150
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL151"));// (assign continue (label after_call151))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch149()
{// primitive_branch149
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call151();
}
void after_call151()
{// after_call151
s.restore(ENV);// (restore env)
s.restore(CONTINUE);// (restore continue)
if ( false_p(registers[VAL]) ) {// (test (op false_p) (reg val))
return goto_with_label("FALSE_BRANCH147");
}// (branch (label false_branch147))
true_branch146();
}
void true_branch146()
{// true_branch146
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "eval"), registers[ENV]));// (assign proc (op lookup_variable_value) (const eval) (reg env))
s.save(CONTINUE);// (save continue)
s.save(PROC);// (save proc)
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "env"), registers[ENV]));// (assign val (op lookup_variable_value) (const env) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
s.save(ARGL);// (save argl)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "first_exp"), registers[ENV]));// (assign proc (op lookup_variable_value) (const first_exp) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "exps"), registers[ENV]));// (assign val (op lookup_variable_value) (const exps) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH152");
}// (branch (label primitive_branch152))
compiled_branch153();
}
void compiled_branch153()
{// compiled_branch153
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL154"));// (assign continue (label after_call154))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch152()
{// primitive_branch152
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call154();
}
void after_call154()
{// after_call154
s.restore(ARGL);// (restore argl)
assign(ARGL, cons(registers[VAL], registers[ARGL]));// (assign argl (op cons) (reg val) (reg argl))
s.restore(PROC);// (restore proc)
s.restore(CONTINUE);// (restore continue)
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH155");
}// (branch (label primitive_branch155))
compiled_branch156();
}
void compiled_branch156()
{// compiled_branch156
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch155()
{// primitive_branch155
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call157();
}
void after_call157()
{// after_call157

}
void false_branch147()
{// false_branch147
s.save(CONTINUE);// (save continue)
s.save(ENV);// (save env)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "eval"), registers[ENV]));// (assign proc (op lookup_variable_value) (const eval) (reg env))
s.save(PROC);// (save proc)
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "env"), registers[ENV]));// (assign val (op lookup_variable_value) (const env) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
s.save(ARGL);// (save argl)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "first_exp"), registers[ENV]));// (assign proc (op lookup_variable_value) (const first_exp) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "exps"), registers[ENV]));// (assign val (op lookup_variable_value) (const exps) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH158");
}// (branch (label primitive_branch158))
compiled_branch159();
}
void compiled_branch159()
{// compiled_branch159
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL160"));// (assign continue (label after_call160))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch158()
{// primitive_branch158
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call160();
}
void after_call160()
{// after_call160
s.restore(ARGL);// (restore argl)
assign(ARGL, cons(registers[VAL], registers[ARGL]));// (assign argl (op cons) (reg val) (reg argl))
s.restore(PROC);// (restore proc)
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH161");
}// (branch (label primitive_branch161))
compiled_branch162();
}
void compiled_branch162()
{// compiled_branch162
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL163"));// (assign continue (label after_call163))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch161()
{// primitive_branch161
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call163();
}
void after_call163()
{// after_call163
s.restore(ENV);// (restore env)
s.restore(CONTINUE);// (restore continue)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "eval_sequence"), registers[ENV]));// (assign proc (op lookup_variable_value) (const eval_sequence) (reg env))
s.save(CONTINUE);// (save continue)
s.save(PROC);// (save proc)
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "env"), registers[ENV]));// (assign val (op lookup_variable_value) (const env) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
s.save(ARGL);// (save argl)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "rest_exps"), registers[ENV]));// (assign proc (op lookup_variable_value) (const rest_exps) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "exps"), registers[ENV]));// (assign val (op lookup_variable_value) (const exps) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH164");
}// (branch (label primitive_branch164))
compiled_branch165();
}
void compiled_branch165()
{// compiled_branch165
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL166"));// (assign continue (label after_call166))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch164()
{// primitive_branch164
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call166();
}
void after_call166()
{// after_call166
s.restore(ARGL);// (restore argl)
assign(ARGL, cons(registers[VAL], registers[ARGL]));// (assign argl (op cons) (reg val) (reg argl))
s.restore(PROC);// (restore proc)
s.restore(CONTINUE);// (restore continue)
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH167");
}// (branch (label primitive_branch167))
compiled_branch168();
}
void compiled_branch168()
{// compiled_branch168
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch167()
{// primitive_branch167
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call169();
}
void after_call169()
{// after_call169
after_if148();
}
void after_if148()
{// after_if148
after_lambda145();
}
void after_lambda145()
{// after_lambda145
define_variable(new SchemeDataType(SchemeDataType::TypeId::Symbol, "eval_sequence"), registers[VAL], registers[ENV]);// (perform (op define_variable) (const eval_sequence) (reg val) (reg env))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "ok"));// (assign val (const ok))
assign(VAL, make_compiled_procedure("ENTRY170", entry170, registers[ENV]));// (assign val (op make_compiled_procedure) (label entry170) (reg env))
goto_with_label("AFTER_LAMBDA171");// (goto (label after_lambda171))

}
void entry170()
{// entry170
assign(ENV, compiled_procedure_env(PROC));// (assign env (op compiled_procedure_env) (reg proc))
assign(ENV, extend_environment(list(2, new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp") , new SchemeDataType(SchemeDataType::TypeId::Symbol, "env") ), registers[ARGL], registers[ENV]));// (assign env (op extend_environment) (const (exp env)) (reg argl) (reg env))
s.save(CONTINUE);// (save continue)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "set_variable_value"), registers[ENV]));// (assign proc (op lookup_variable_value) (const set_variable_value) (reg env))
s.save(PROC);// (save proc)
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "env"), registers[ENV]));// (assign val (op lookup_variable_value) (const env) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
s.save(ENV);// (save env)
s.save(ARGL);// (save argl)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "eval"), registers[ENV]));// (assign proc (op lookup_variable_value) (const eval) (reg env))
s.save(PROC);// (save proc)
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "env"), registers[ENV]));// (assign val (op lookup_variable_value) (const env) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
s.save(ARGL);// (save argl)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "assignment_value"), registers[ENV]));// (assign proc (op lookup_variable_value) (const assignment_value) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp"), registers[ENV]));// (assign val (op lookup_variable_value) (const exp) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH175");
}// (branch (label primitive_branch175))
compiled_branch176();
}
void compiled_branch176()
{// compiled_branch176
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL177"));// (assign continue (label after_call177))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch175()
{// primitive_branch175
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call177();
}
void after_call177()
{// after_call177
s.restore(ARGL);// (restore argl)
assign(ARGL, cons(registers[VAL], registers[ARGL]));// (assign argl (op cons) (reg val) (reg argl))
s.restore(PROC);// (restore proc)
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH178");
}// (branch (label primitive_branch178))
compiled_branch179();
}
void compiled_branch179()
{// compiled_branch179
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL180"));// (assign continue (label after_call180))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch178()
{// primitive_branch178
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call180();
}
void after_call180()
{// after_call180
s.restore(ARGL);// (restore argl)
assign(ARGL, cons(registers[VAL], registers[ARGL]));// (assign argl (op cons) (reg val) (reg argl))
s.restore(ENV);// (restore env)
s.save(ARGL);// (save argl)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "assignment_variable"), registers[ENV]));// (assign proc (op lookup_variable_value) (const assignment_variable) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp"), registers[ENV]));// (assign val (op lookup_variable_value) (const exp) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH172");
}// (branch (label primitive_branch172))
compiled_branch173();
}
void compiled_branch173()
{// compiled_branch173
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL174"));// (assign continue (label after_call174))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch172()
{// primitive_branch172
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call174();
}
void after_call174()
{// after_call174
s.restore(ARGL);// (restore argl)
assign(ARGL, cons(registers[VAL], registers[ARGL]));// (assign argl (op cons) (reg val) (reg argl))
s.restore(PROC);// (restore proc)
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH181");
}// (branch (label primitive_branch181))
compiled_branch182();
}
void compiled_branch182()
{// compiled_branch182
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL183"));// (assign continue (label after_call183))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch181()
{// primitive_branch181
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call183();
}
void after_call183()
{// after_call183
s.restore(CONTINUE);// (restore continue)
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "ok"));// (assign val (const ok))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_lambda171();
}
void after_lambda171()
{// after_lambda171
define_variable(new SchemeDataType(SchemeDataType::TypeId::Symbol, "eval_assignment"), registers[VAL], registers[ENV]);// (perform (op define_variable) (const eval_assignment) (reg val) (reg env))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "ok"));// (assign val (const ok))
assign(VAL, make_compiled_procedure("ENTRY184", entry184, registers[ENV]));// (assign val (op make_compiled_procedure) (label entry184) (reg env))
goto_with_label("AFTER_LAMBDA185");// (goto (label after_lambda185))

}
void entry184()
{// entry184
assign(ENV, compiled_procedure_env(PROC));// (assign env (op compiled_procedure_env) (reg proc))
assign(ENV, extend_environment(list(2, new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp") , new SchemeDataType(SchemeDataType::TypeId::Symbol, "env") ), registers[ARGL], registers[ENV]));// (assign env (op extend_environment) (const (exp env)) (reg argl) (reg env))
s.save(CONTINUE);// (save continue)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "define_variable"), registers[ENV]));// (assign proc (op lookup_variable_value) (const define_variable) (reg env))
s.save(PROC);// (save proc)
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "env"), registers[ENV]));// (assign val (op lookup_variable_value) (const env) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
s.save(ENV);// (save env)
s.save(ARGL);// (save argl)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "eval"), registers[ENV]));// (assign proc (op lookup_variable_value) (const eval) (reg env))
s.save(PROC);// (save proc)
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "env"), registers[ENV]));// (assign val (op lookup_variable_value) (const env) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
s.save(ARGL);// (save argl)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "definition_value"), registers[ENV]));// (assign proc (op lookup_variable_value) (const definition_value) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp"), registers[ENV]));// (assign val (op lookup_variable_value) (const exp) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH189");
}// (branch (label primitive_branch189))
compiled_branch190();
}
void compiled_branch190()
{// compiled_branch190
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL191"));// (assign continue (label after_call191))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch189()
{// primitive_branch189
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call191();
}
void after_call191()
{// after_call191
s.restore(ARGL);// (restore argl)
assign(ARGL, cons(registers[VAL], registers[ARGL]));// (assign argl (op cons) (reg val) (reg argl))
s.restore(PROC);// (restore proc)
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH192");
}// (branch (label primitive_branch192))
compiled_branch193();
}
void compiled_branch193()
{// compiled_branch193
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL194"));// (assign continue (label after_call194))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch192()
{// primitive_branch192
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call194();
}
void after_call194()
{// after_call194
s.restore(ARGL);// (restore argl)
assign(ARGL, cons(registers[VAL], registers[ARGL]));// (assign argl (op cons) (reg val) (reg argl))
s.restore(ENV);// (restore env)
s.save(ARGL);// (save argl)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "definition_variable"), registers[ENV]));// (assign proc (op lookup_variable_value) (const definition_variable) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp"), registers[ENV]));// (assign val (op lookup_variable_value) (const exp) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH186");
}// (branch (label primitive_branch186))
compiled_branch187();
}
void compiled_branch187()
{// compiled_branch187
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL188"));// (assign continue (label after_call188))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch186()
{// primitive_branch186
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call188();
}
void after_call188()
{// after_call188
s.restore(ARGL);// (restore argl)
assign(ARGL, cons(registers[VAL], registers[ARGL]));// (assign argl (op cons) (reg val) (reg argl))
s.restore(PROC);// (restore proc)
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH195");
}// (branch (label primitive_branch195))
compiled_branch196();
}
void compiled_branch196()
{// compiled_branch196
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL197"));// (assign continue (label after_call197))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch195()
{// primitive_branch195
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call197();
}
void after_call197()
{// after_call197
s.restore(CONTINUE);// (restore continue)
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "ok"));// (assign val (const ok))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_lambda185();
}
void after_lambda185()
{// after_lambda185
define_variable(new SchemeDataType(SchemeDataType::TypeId::Symbol, "eval_definition"), registers[VAL], registers[ENV]);// (perform (op define_variable) (const eval_definition) (reg val) (reg env))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "ok"));// (assign val (const ok))
assign(VAL, make_compiled_procedure("ENTRY198", entry198, registers[ENV]));// (assign val (op make_compiled_procedure) (label entry198) (reg env))
goto_with_label("AFTER_LAMBDA199");// (goto (label after_lambda199))

}
void entry198()
{// entry198
assign(ENV, compiled_procedure_env(PROC));// (assign env (op compiled_procedure_env) (reg proc))
assign(ENV, extend_environment(new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp"), registers[ARGL], registers[ENV]));// (assign env (op extend_environment) (const exp) (reg argl) (reg env))
s.save(CONTINUE);// (save continue)
s.save(ENV);// (save env)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "number_p"), registers[ENV]));// (assign proc (op lookup_variable_value) (const number_p) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp"), registers[ENV]));// (assign val (op lookup_variable_value) (const exp) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH203");
}// (branch (label primitive_branch203))
compiled_branch204();
}
void compiled_branch204()
{// compiled_branch204
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL205"));// (assign continue (label after_call205))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch203()
{// primitive_branch203
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call205();
}
void after_call205()
{// after_call205
s.restore(ENV);// (restore env)
s.restore(CONTINUE);// (restore continue)
if ( false_p(registers[VAL]) ) {// (test (op false_p) (reg val))
return goto_with_label("FALSE_BRANCH201");
}// (branch (label false_branch201))
true_branch200();
}
void true_branch200()
{// true_branch200
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "true"), registers[ENV]));// (assign val (op lookup_variable_value) (const true) (reg env))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))

}
void false_branch201()
{// false_branch201
s.save(CONTINUE);// (save continue)
s.save(ENV);// (save env)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "string_p"), registers[ENV]));// (assign proc (op lookup_variable_value) (const string_p) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp"), registers[ENV]));// (assign val (op lookup_variable_value) (const exp) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH209");
}// (branch (label primitive_branch209))
compiled_branch210();
}
void compiled_branch210()
{// compiled_branch210
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL211"));// (assign continue (label after_call211))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch209()
{// primitive_branch209
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call211();
}
void after_call211()
{// after_call211
s.restore(ENV);// (restore env)
s.restore(CONTINUE);// (restore continue)
if ( false_p(registers[VAL]) ) {// (test (op false_p) (reg val))
return goto_with_label("FALSE_BRANCH207");
}// (branch (label false_branch207))
true_branch206();
}
void true_branch206()
{// true_branch206
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "true"), registers[ENV]));// (assign val (op lookup_variable_value) (const true) (reg env))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))

}
void false_branch207()
{// false_branch207
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "false"), registers[ENV]));// (assign val (op lookup_variable_value) (const false) (reg env))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_if208();
}
void after_if208()
{// after_if208
after_if202();
}
void after_if202()
{// after_if202
after_lambda199();
}
void after_lambda199()
{// after_lambda199
define_variable(new SchemeDataType(SchemeDataType::TypeId::Symbol, "self_evaluating_p"), registers[VAL], registers[ENV]);// (perform (op define_variable) (const self_evaluating_p) (reg val) (reg env))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "ok"));// (assign val (const ok))
assign(VAL, make_compiled_procedure("ENTRY212", entry212, registers[ENV]));// (assign val (op make_compiled_procedure) (label entry212) (reg env))
goto_with_label("AFTER_LAMBDA213");// (goto (label after_lambda213))

}
void entry212()
{// entry212
assign(ENV, compiled_procedure_env(PROC));// (assign env (op compiled_procedure_env) (reg proc))
assign(ENV, extend_environment(new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp"), registers[ARGL], registers[ENV]));// (assign env (op extend_environment) (const exp) (reg argl) (reg env))
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "tagged_list_p"), registers[ENV]));// (assign proc (op lookup_variable_value) (const tagged_list_p) (reg env))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "quote"));// (assign val (const quote))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp"), registers[ENV]));// (assign val (op lookup_variable_value) (const exp) (reg env))
assign(ARGL, cons(registers[VAL], registers[ARGL]));// (assign argl (op cons) (reg val) (reg argl))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH214");
}// (branch (label primitive_branch214))
compiled_branch215();
}
void compiled_branch215()
{// compiled_branch215
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch214()
{// primitive_branch214
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call216();
}
void after_call216()
{// after_call216
after_lambda213();
}
void after_lambda213()
{// after_lambda213
define_variable(new SchemeDataType(SchemeDataType::TypeId::Symbol, "quoted_p"), registers[VAL], registers[ENV]);// (perform (op define_variable) (const quoted_p) (reg val) (reg env))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "ok"));// (assign val (const ok))
assign(VAL, make_compiled_procedure("ENTRY217", entry217, registers[ENV]));// (assign val (op make_compiled_procedure) (label entry217) (reg env))
goto_with_label("AFTER_LAMBDA218");// (goto (label after_lambda218))

}
void entry217()
{// entry217
assign(ENV, compiled_procedure_env(PROC));// (assign env (op compiled_procedure_env) (reg proc))
assign(ENV, extend_environment(new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp"), registers[ARGL], registers[ENV]));// (assign env (op extend_environment) (const exp) (reg argl) (reg env))
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "cadr"), registers[ENV]));// (assign proc (op lookup_variable_value) (const cadr) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp"), registers[ENV]));// (assign val (op lookup_variable_value) (const exp) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH219");
}// (branch (label primitive_branch219))
compiled_branch220();
}
void compiled_branch220()
{// compiled_branch220
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch219()
{// primitive_branch219
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call221();
}
void after_call221()
{// after_call221
after_lambda218();
}
void after_lambda218()
{// after_lambda218
define_variable(new SchemeDataType(SchemeDataType::TypeId::Symbol, "text_of_quotation"), registers[VAL], registers[ENV]);// (perform (op define_variable) (const text_of_quotation) (reg val) (reg env))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "ok"));// (assign val (const ok))
assign(VAL, make_compiled_procedure("ENTRY222", entry222, registers[ENV]));// (assign val (op make_compiled_procedure) (label entry222) (reg env))
goto_with_label("AFTER_LAMBDA223");// (goto (label after_lambda223))

}
void entry222()
{// entry222
assign(ENV, compiled_procedure_env(PROC));// (assign env (op compiled_procedure_env) (reg proc))
assign(ENV, extend_environment(list(2, new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp") , new SchemeDataType(SchemeDataType::TypeId::Symbol, "tag") ), registers[ARGL], registers[ENV]));// (assign env (op extend_environment) (const (exp tag)) (reg argl) (reg env))
s.save(CONTINUE);// (save continue)
s.save(ENV);// (save env)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "pair_p"), registers[ENV]));// (assign proc (op lookup_variable_value) (const pair_p) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp"), registers[ENV]));// (assign val (op lookup_variable_value) (const exp) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH227");
}// (branch (label primitive_branch227))
compiled_branch228();
}
void compiled_branch228()
{// compiled_branch228
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL229"));// (assign continue (label after_call229))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch227()
{// primitive_branch227
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call229();
}
void after_call229()
{// after_call229
s.restore(ENV);// (restore env)
s.restore(CONTINUE);// (restore continue)
if ( false_p(registers[VAL]) ) {// (test (op false_p) (reg val))
return goto_with_label("FALSE_BRANCH225");
}// (branch (label false_branch225))
true_branch224();
}
void true_branch224()
{// true_branch224
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "eq_p"), registers[ENV]));// (assign proc (op lookup_variable_value) (const eq_p) (reg env))
s.save(CONTINUE);// (save continue)
s.save(PROC);// (save proc)
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "tag"), registers[ENV]));// (assign val (op lookup_variable_value) (const tag) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
s.save(ARGL);// (save argl)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "car"), registers[ENV]));// (assign proc (op lookup_variable_value) (const car) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp"), registers[ENV]));// (assign val (op lookup_variable_value) (const exp) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH230");
}// (branch (label primitive_branch230))
compiled_branch231();
}
void compiled_branch231()
{// compiled_branch231
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL232"));// (assign continue (label after_call232))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch230()
{// primitive_branch230
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call232();
}
void after_call232()
{// after_call232
s.restore(ARGL);// (restore argl)
assign(ARGL, cons(registers[VAL], registers[ARGL]));// (assign argl (op cons) (reg val) (reg argl))
s.restore(PROC);// (restore proc)
s.restore(CONTINUE);// (restore continue)
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH233");
}// (branch (label primitive_branch233))
compiled_branch234();
}
void compiled_branch234()
{// compiled_branch234
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch233()
{// primitive_branch233
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call235();
}
void after_call235()
{// after_call235

}
void false_branch225()
{// false_branch225
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "false"), registers[ENV]));// (assign val (op lookup_variable_value) (const false) (reg env))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_if226();
}
void after_if226()
{// after_if226
after_lambda223();
}
void after_lambda223()
{// after_lambda223
define_variable(new SchemeDataType(SchemeDataType::TypeId::Symbol, "tagged_list_p"), registers[VAL], registers[ENV]);// (perform (op define_variable) (const tagged_list_p) (reg val) (reg env))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "ok"));// (assign val (const ok))
assign(VAL, make_compiled_procedure("ENTRY236", entry236, registers[ENV]));// (assign val (op make_compiled_procedure) (label entry236) (reg env))
goto_with_label("AFTER_LAMBDA237");// (goto (label after_lambda237))

}
void entry236()
{// entry236
assign(ENV, compiled_procedure_env(PROC));// (assign env (op compiled_procedure_env) (reg proc))
assign(ENV, extend_environment(new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp"), registers[ARGL], registers[ENV]));// (assign env (op extend_environment) (const exp) (reg argl) (reg env))
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "symbol_p"), registers[ENV]));// (assign proc (op lookup_variable_value) (const symbol_p) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp"), registers[ENV]));// (assign val (op lookup_variable_value) (const exp) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH238");
}// (branch (label primitive_branch238))
compiled_branch239();
}
void compiled_branch239()
{// compiled_branch239
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch238()
{// primitive_branch238
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call240();
}
void after_call240()
{// after_call240
after_lambda237();
}
void after_lambda237()
{// after_lambda237
define_variable(new SchemeDataType(SchemeDataType::TypeId::Symbol, "variable_p"), registers[VAL], registers[ENV]);// (perform (op define_variable) (const variable_p) (reg val) (reg env))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "ok"));// (assign val (const ok))
assign(VAL, make_compiled_procedure("ENTRY241", entry241, registers[ENV]));// (assign val (op make_compiled_procedure) (label entry241) (reg env))
goto_with_label("AFTER_LAMBDA242");// (goto (label after_lambda242))

}
void entry241()
{// entry241
assign(ENV, compiled_procedure_env(PROC));// (assign env (op compiled_procedure_env) (reg proc))
assign(ENV, extend_environment(new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp"), registers[ARGL], registers[ENV]));// (assign env (op extend_environment) (const exp) (reg argl) (reg env))
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "tagged_list_p"), registers[ENV]));// (assign proc (op lookup_variable_value) (const tagged_list_p) (reg env))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "set"));// (assign val (const set))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp"), registers[ENV]));// (assign val (op lookup_variable_value) (const exp) (reg env))
assign(ARGL, cons(registers[VAL], registers[ARGL]));// (assign argl (op cons) (reg val) (reg argl))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH243");
}// (branch (label primitive_branch243))
compiled_branch244();
}
void compiled_branch244()
{// compiled_branch244
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch243()
{// primitive_branch243
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call245();
}
void after_call245()
{// after_call245
after_lambda242();
}
void after_lambda242()
{// after_lambda242
define_variable(new SchemeDataType(SchemeDataType::TypeId::Symbol, "assignment_p"), registers[VAL], registers[ENV]);// (perform (op define_variable) (const assignment_p) (reg val) (reg env))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "ok"));// (assign val (const ok))
assign(VAL, make_compiled_procedure("ENTRY246", entry246, registers[ENV]));// (assign val (op make_compiled_procedure) (label entry246) (reg env))
goto_with_label("AFTER_LAMBDA247");// (goto (label after_lambda247))

}
void entry246()
{// entry246
assign(ENV, compiled_procedure_env(PROC));// (assign env (op compiled_procedure_env) (reg proc))
assign(ENV, extend_environment(new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp"), registers[ARGL], registers[ENV]));// (assign env (op extend_environment) (const exp) (reg argl) (reg env))
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "cadr"), registers[ENV]));// (assign proc (op lookup_variable_value) (const cadr) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp"), registers[ENV]));// (assign val (op lookup_variable_value) (const exp) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH248");
}// (branch (label primitive_branch248))
compiled_branch249();
}
void compiled_branch249()
{// compiled_branch249
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch248()
{// primitive_branch248
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call250();
}
void after_call250()
{// after_call250
after_lambda247();
}
void after_lambda247()
{// after_lambda247
define_variable(new SchemeDataType(SchemeDataType::TypeId::Symbol, "assignment_variable"), registers[VAL], registers[ENV]);// (perform (op define_variable) (const assignment_variable) (reg val) (reg env))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "ok"));// (assign val (const ok))
assign(VAL, make_compiled_procedure("ENTRY251", entry251, registers[ENV]));// (assign val (op make_compiled_procedure) (label entry251) (reg env))
goto_with_label("AFTER_LAMBDA252");// (goto (label after_lambda252))

}
void entry251()
{// entry251
assign(ENV, compiled_procedure_env(PROC));// (assign env (op compiled_procedure_env) (reg proc))
assign(ENV, extend_environment(new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp"), registers[ARGL], registers[ENV]));// (assign env (op extend_environment) (const exp) (reg argl) (reg env))
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "caddr"), registers[ENV]));// (assign proc (op lookup_variable_value) (const caddr) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp"), registers[ENV]));// (assign val (op lookup_variable_value) (const exp) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH253");
}// (branch (label primitive_branch253))
compiled_branch254();
}
void compiled_branch254()
{// compiled_branch254
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch253()
{// primitive_branch253
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call255();
}
void after_call255()
{// after_call255
after_lambda252();
}
void after_lambda252()
{// after_lambda252
define_variable(new SchemeDataType(SchemeDataType::TypeId::Symbol, "assignment_value"), registers[VAL], registers[ENV]);// (perform (op define_variable) (const assignment_value) (reg val) (reg env))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "ok"));// (assign val (const ok))
assign(VAL, make_compiled_procedure("ENTRY256", entry256, registers[ENV]));// (assign val (op make_compiled_procedure) (label entry256) (reg env))
goto_with_label("AFTER_LAMBDA257");// (goto (label after_lambda257))

}
void entry256()
{// entry256
assign(ENV, compiled_procedure_env(PROC));// (assign env (op compiled_procedure_env) (reg proc))
assign(ENV, extend_environment(new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp"), registers[ARGL], registers[ENV]));// (assign env (op extend_environment) (const exp) (reg argl) (reg env))
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "tagged_list_p"), registers[ENV]));// (assign proc (op lookup_variable_value) (const tagged_list_p) (reg env))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "define"));// (assign val (const define))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp"), registers[ENV]));// (assign val (op lookup_variable_value) (const exp) (reg env))
assign(ARGL, cons(registers[VAL], registers[ARGL]));// (assign argl (op cons) (reg val) (reg argl))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH258");
}// (branch (label primitive_branch258))
compiled_branch259();
}
void compiled_branch259()
{// compiled_branch259
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch258()
{// primitive_branch258
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call260();
}
void after_call260()
{// after_call260
after_lambda257();
}
void after_lambda257()
{// after_lambda257
define_variable(new SchemeDataType(SchemeDataType::TypeId::Symbol, "definition_p"), registers[VAL], registers[ENV]);// (perform (op define_variable) (const definition_p) (reg val) (reg env))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "ok"));// (assign val (const ok))
assign(VAL, make_compiled_procedure("ENTRY261", entry261, registers[ENV]));// (assign val (op make_compiled_procedure) (label entry261) (reg env))
goto_with_label("AFTER_LAMBDA262");// (goto (label after_lambda262))

}
void entry261()
{// entry261
assign(ENV, compiled_procedure_env(PROC));// (assign env (op compiled_procedure_env) (reg proc))
assign(ENV, extend_environment(new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp"), registers[ARGL], registers[ENV]));// (assign env (op extend_environment) (const exp) (reg argl) (reg env))
s.save(CONTINUE);// (save continue)
s.save(ENV);// (save env)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "symbol_p"), registers[ENV]));// (assign proc (op lookup_variable_value) (const symbol_p) (reg env))
s.save(PROC);// (save proc)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "cadr"), registers[ENV]));// (assign proc (op lookup_variable_value) (const cadr) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp"), registers[ENV]));// (assign val (op lookup_variable_value) (const exp) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH266");
}// (branch (label primitive_branch266))
compiled_branch267();
}
void compiled_branch267()
{// compiled_branch267
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL268"));// (assign continue (label after_call268))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch266()
{// primitive_branch266
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call268();
}
void after_call268()
{// after_call268
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
s.restore(PROC);// (restore proc)
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH269");
}// (branch (label primitive_branch269))
compiled_branch270();
}
void compiled_branch270()
{// compiled_branch270
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL271"));// (assign continue (label after_call271))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch269()
{// primitive_branch269
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call271();
}
void after_call271()
{// after_call271
s.restore(ENV);// (restore env)
s.restore(CONTINUE);// (restore continue)
if ( false_p(registers[VAL]) ) {// (test (op false_p) (reg val))
return goto_with_label("FALSE_BRANCH264");
}// (branch (label false_branch264))
true_branch263();
}
void true_branch263()
{// true_branch263
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "cadr"), registers[ENV]));// (assign proc (op lookup_variable_value) (const cadr) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp"), registers[ENV]));// (assign val (op lookup_variable_value) (const exp) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH272");
}// (branch (label primitive_branch272))
compiled_branch273();
}
void compiled_branch273()
{// compiled_branch273
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch272()
{// primitive_branch272
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call274();
}
void after_call274()
{// after_call274

}
void false_branch264()
{// false_branch264
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "caadr"), registers[ENV]));// (assign proc (op lookup_variable_value) (const caadr) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp"), registers[ENV]));// (assign val (op lookup_variable_value) (const exp) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH275");
}// (branch (label primitive_branch275))
compiled_branch276();
}
void compiled_branch276()
{// compiled_branch276
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch275()
{// primitive_branch275
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call277();
}
void after_call277()
{// after_call277
after_if265();
}
void after_if265()
{// after_if265
after_lambda262();
}
void after_lambda262()
{// after_lambda262
define_variable(new SchemeDataType(SchemeDataType::TypeId::Symbol, "definition_variable"), registers[VAL], registers[ENV]);// (perform (op define_variable) (const definition_variable) (reg val) (reg env))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "ok"));// (assign val (const ok))
assign(VAL, make_compiled_procedure("ENTRY278", entry278, registers[ENV]));// (assign val (op make_compiled_procedure) (label entry278) (reg env))
goto_with_label("AFTER_LAMBDA279");// (goto (label after_lambda279))

}
void entry278()
{// entry278
assign(ENV, compiled_procedure_env(PROC));// (assign env (op compiled_procedure_env) (reg proc))
assign(ENV, extend_environment(new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp"), registers[ARGL], registers[ENV]));// (assign env (op extend_environment) (const exp) (reg argl) (reg env))
s.save(CONTINUE);// (save continue)
s.save(ENV);// (save env)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "symbol_p"), registers[ENV]));// (assign proc (op lookup_variable_value) (const symbol_p) (reg env))
s.save(PROC);// (save proc)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "cadr"), registers[ENV]));// (assign proc (op lookup_variable_value) (const cadr) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp"), registers[ENV]));// (assign val (op lookup_variable_value) (const exp) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH283");
}// (branch (label primitive_branch283))
compiled_branch284();
}
void compiled_branch284()
{// compiled_branch284
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL285"));// (assign continue (label after_call285))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch283()
{// primitive_branch283
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call285();
}
void after_call285()
{// after_call285
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
s.restore(PROC);// (restore proc)
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH286");
}// (branch (label primitive_branch286))
compiled_branch287();
}
void compiled_branch287()
{// compiled_branch287
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL288"));// (assign continue (label after_call288))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch286()
{// primitive_branch286
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call288();
}
void after_call288()
{// after_call288
s.restore(ENV);// (restore env)
s.restore(CONTINUE);// (restore continue)
if ( false_p(registers[VAL]) ) {// (test (op false_p) (reg val))
return goto_with_label("FALSE_BRANCH281");
}// (branch (label false_branch281))
true_branch280();
}
void true_branch280()
{// true_branch280
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "caddr"), registers[ENV]));// (assign proc (op lookup_variable_value) (const caddr) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp"), registers[ENV]));// (assign val (op lookup_variable_value) (const exp) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH289");
}// (branch (label primitive_branch289))
compiled_branch290();
}
void compiled_branch290()
{// compiled_branch290
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch289()
{// primitive_branch289
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call291();
}
void after_call291()
{// after_call291

}
void false_branch281()
{// false_branch281
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "make_lambda"), registers[ENV]));// (assign proc (op lookup_variable_value) (const make_lambda) (reg env))
s.save(CONTINUE);// (save continue)
s.save(PROC);// (save proc)
s.save(ENV);// (save env)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "cddr"), registers[ENV]));// (assign proc (op lookup_variable_value) (const cddr) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp"), registers[ENV]));// (assign val (op lookup_variable_value) (const exp) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH295");
}// (branch (label primitive_branch295))
compiled_branch296();
}
void compiled_branch296()
{// compiled_branch296
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL297"));// (assign continue (label after_call297))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch295()
{// primitive_branch295
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call297();
}
void after_call297()
{// after_call297
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
s.restore(ENV);// (restore env)
s.save(ARGL);// (save argl)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "cdadr"), registers[ENV]));// (assign proc (op lookup_variable_value) (const cdadr) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp"), registers[ENV]));// (assign val (op lookup_variable_value) (const exp) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH292");
}// (branch (label primitive_branch292))
compiled_branch293();
}
void compiled_branch293()
{// compiled_branch293
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL294"));// (assign continue (label after_call294))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch292()
{// primitive_branch292
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call294();
}
void after_call294()
{// after_call294
s.restore(ARGL);// (restore argl)
assign(ARGL, cons(registers[VAL], registers[ARGL]));// (assign argl (op cons) (reg val) (reg argl))
s.restore(PROC);// (restore proc)
s.restore(CONTINUE);// (restore continue)
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH298");
}// (branch (label primitive_branch298))
compiled_branch299();
}
void compiled_branch299()
{// compiled_branch299
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch298()
{// primitive_branch298
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call300();
}
void after_call300()
{// after_call300
after_if282();
}
void after_if282()
{// after_if282
after_lambda279();
}
void after_lambda279()
{// after_lambda279
define_variable(new SchemeDataType(SchemeDataType::TypeId::Symbol, "definition_value"), registers[VAL], registers[ENV]);// (perform (op define_variable) (const definition_value) (reg val) (reg env))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "ok"));// (assign val (const ok))
assign(VAL, make_compiled_procedure("ENTRY301", entry301, registers[ENV]));// (assign val (op make_compiled_procedure) (label entry301) (reg env))
goto_with_label("AFTER_LAMBDA302");// (goto (label after_lambda302))

}
void entry301()
{// entry301
assign(ENV, compiled_procedure_env(PROC));// (assign env (op compiled_procedure_env) (reg proc))
assign(ENV, extend_environment(new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp"), registers[ARGL], registers[ENV]));// (assign env (op extend_environment) (const exp) (reg argl) (reg env))
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "tagged_list_p"), registers[ENV]));// (assign proc (op lookup_variable_value) (const tagged_list_p) (reg env))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "lambda"));// (assign val (const lambda))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp"), registers[ENV]));// (assign val (op lookup_variable_value) (const exp) (reg env))
assign(ARGL, cons(registers[VAL], registers[ARGL]));// (assign argl (op cons) (reg val) (reg argl))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH303");
}// (branch (label primitive_branch303))
compiled_branch304();
}
void compiled_branch304()
{// compiled_branch304
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch303()
{// primitive_branch303
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call305();
}
void after_call305()
{// after_call305
after_lambda302();
}
void after_lambda302()
{// after_lambda302
define_variable(new SchemeDataType(SchemeDataType::TypeId::Symbol, "lambda_p"), registers[VAL], registers[ENV]);// (perform (op define_variable) (const lambda_p) (reg val) (reg env))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "ok"));// (assign val (const ok))
assign(VAL, make_compiled_procedure("ENTRY306", entry306, registers[ENV]));// (assign val (op make_compiled_procedure) (label entry306) (reg env))
goto_with_label("AFTER_LAMBDA307");// (goto (label after_lambda307))

}
void entry306()
{// entry306
assign(ENV, compiled_procedure_env(PROC));// (assign env (op compiled_procedure_env) (reg proc))
assign(ENV, extend_environment(new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp"), registers[ARGL], registers[ENV]));// (assign env (op extend_environment) (const exp) (reg argl) (reg env))
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "cadr"), registers[ENV]));// (assign proc (op lookup_variable_value) (const cadr) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp"), registers[ENV]));// (assign val (op lookup_variable_value) (const exp) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH308");
}// (branch (label primitive_branch308))
compiled_branch309();
}
void compiled_branch309()
{// compiled_branch309
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch308()
{// primitive_branch308
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call310();
}
void after_call310()
{// after_call310
after_lambda307();
}
void after_lambda307()
{// after_lambda307
define_variable(new SchemeDataType(SchemeDataType::TypeId::Symbol, "lambda_parameters"), registers[VAL], registers[ENV]);// (perform (op define_variable) (const lambda_parameters) (reg val) (reg env))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "ok"));// (assign val (const ok))
assign(VAL, make_compiled_procedure("ENTRY311", entry311, registers[ENV]));// (assign val (op make_compiled_procedure) (label entry311) (reg env))
goto_with_label("AFTER_LAMBDA312");// (goto (label after_lambda312))

}
void entry311()
{// entry311
assign(ENV, compiled_procedure_env(PROC));// (assign env (op compiled_procedure_env) (reg proc))
assign(ENV, extend_environment(new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp"), registers[ARGL], registers[ENV]));// (assign env (op extend_environment) (const exp) (reg argl) (reg env))
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "cddr"), registers[ENV]));// (assign proc (op lookup_variable_value) (const cddr) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp"), registers[ENV]));// (assign val (op lookup_variable_value) (const exp) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH313");
}// (branch (label primitive_branch313))
compiled_branch314();
}
void compiled_branch314()
{// compiled_branch314
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch313()
{// primitive_branch313
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call315();
}
void after_call315()
{// after_call315
after_lambda312();
}
void after_lambda312()
{// after_lambda312
define_variable(new SchemeDataType(SchemeDataType::TypeId::Symbol, "lambda_body"), registers[VAL], registers[ENV]);// (perform (op define_variable) (const lambda_body) (reg val) (reg env))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "ok"));// (assign val (const ok))
assign(VAL, make_compiled_procedure("ENTRY316", entry316, registers[ENV]));// (assign val (op make_compiled_procedure) (label entry316) (reg env))
goto_with_label("AFTER_LAMBDA317");// (goto (label after_lambda317))

}
void entry316()
{// entry316
assign(ENV, compiled_procedure_env(PROC));// (assign env (op compiled_procedure_env) (reg proc))
assign(ENV, extend_environment(list(2, new SchemeDataType(SchemeDataType::TypeId::Symbol, "parameters") , new SchemeDataType(SchemeDataType::TypeId::Symbol, "body") ), registers[ARGL], registers[ENV]));// (assign env (op extend_environment) (const (parameters body)) (reg argl) (reg env))
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "cons"), registers[ENV]));// (assign proc (op lookup_variable_value) (const cons) (reg env))
s.save(CONTINUE);// (save continue)
s.save(PROC);// (save proc)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "cons"), registers[ENV]));// (assign proc (op lookup_variable_value) (const cons) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "body"), registers[ENV]));// (assign val (op lookup_variable_value) (const body) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "parameters"), registers[ENV]));// (assign val (op lookup_variable_value) (const parameters) (reg env))
assign(ARGL, cons(registers[VAL], registers[ARGL]));// (assign argl (op cons) (reg val) (reg argl))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH318");
}// (branch (label primitive_branch318))
compiled_branch319();
}
void compiled_branch319()
{// compiled_branch319
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL320"));// (assign continue (label after_call320))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch318()
{// primitive_branch318
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call320();
}
void after_call320()
{// after_call320
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "lambda"));// (assign val (const lambda))
assign(ARGL, cons(registers[VAL], registers[ARGL]));// (assign argl (op cons) (reg val) (reg argl))
s.restore(PROC);// (restore proc)
s.restore(CONTINUE);// (restore continue)
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH321");
}// (branch (label primitive_branch321))
compiled_branch322();
}
void compiled_branch322()
{// compiled_branch322
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch321()
{// primitive_branch321
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call323();
}
void after_call323()
{// after_call323
after_lambda317();
}
void after_lambda317()
{// after_lambda317
define_variable(new SchemeDataType(SchemeDataType::TypeId::Symbol, "make_lambda"), registers[VAL], registers[ENV]);// (perform (op define_variable) (const make_lambda) (reg val) (reg env))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "ok"));// (assign val (const ok))
assign(VAL, make_compiled_procedure("ENTRY324", entry324, registers[ENV]));// (assign val (op make_compiled_procedure) (label entry324) (reg env))
goto_with_label("AFTER_LAMBDA325");// (goto (label after_lambda325))

}
void entry324()
{// entry324
assign(ENV, compiled_procedure_env(PROC));// (assign env (op compiled_procedure_env) (reg proc))
assign(ENV, extend_environment(new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp"), registers[ARGL], registers[ENV]));// (assign env (op extend_environment) (const exp) (reg argl) (reg env))
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "tagged_list_p"), registers[ENV]));// (assign proc (op lookup_variable_value) (const tagged_list_p) (reg env))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "if"));// (assign val (const if))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp"), registers[ENV]));// (assign val (op lookup_variable_value) (const exp) (reg env))
assign(ARGL, cons(registers[VAL], registers[ARGL]));// (assign argl (op cons) (reg val) (reg argl))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH326");
}// (branch (label primitive_branch326))
compiled_branch327();
}
void compiled_branch327()
{// compiled_branch327
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch326()
{// primitive_branch326
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call328();
}
void after_call328()
{// after_call328
after_lambda325();
}
void after_lambda325()
{// after_lambda325
define_variable(new SchemeDataType(SchemeDataType::TypeId::Symbol, "if_p"), registers[VAL], registers[ENV]);// (perform (op define_variable) (const if_p) (reg val) (reg env))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "ok"));// (assign val (const ok))
assign(VAL, make_compiled_procedure("ENTRY329", entry329, registers[ENV]));// (assign val (op make_compiled_procedure) (label entry329) (reg env))
goto_with_label("AFTER_LAMBDA330");// (goto (label after_lambda330))

}
void entry329()
{// entry329
assign(ENV, compiled_procedure_env(PROC));// (assign env (op compiled_procedure_env) (reg proc))
assign(ENV, extend_environment(new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp"), registers[ARGL], registers[ENV]));// (assign env (op extend_environment) (const exp) (reg argl) (reg env))
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "cadr"), registers[ENV]));// (assign proc (op lookup_variable_value) (const cadr) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp"), registers[ENV]));// (assign val (op lookup_variable_value) (const exp) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH331");
}// (branch (label primitive_branch331))
compiled_branch332();
}
void compiled_branch332()
{// compiled_branch332
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch331()
{// primitive_branch331
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call333();
}
void after_call333()
{// after_call333
after_lambda330();
}
void after_lambda330()
{// after_lambda330
define_variable(new SchemeDataType(SchemeDataType::TypeId::Symbol, "if_predicate"), registers[VAL], registers[ENV]);// (perform (op define_variable) (const if_predicate) (reg val) (reg env))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "ok"));// (assign val (const ok))
assign(VAL, make_compiled_procedure("ENTRY334", entry334, registers[ENV]));// (assign val (op make_compiled_procedure) (label entry334) (reg env))
goto_with_label("AFTER_LAMBDA335");// (goto (label after_lambda335))

}
void entry334()
{// entry334
assign(ENV, compiled_procedure_env(PROC));// (assign env (op compiled_procedure_env) (reg proc))
assign(ENV, extend_environment(new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp"), registers[ARGL], registers[ENV]));// (assign env (op extend_environment) (const exp) (reg argl) (reg env))
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "caddr"), registers[ENV]));// (assign proc (op lookup_variable_value) (const caddr) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp"), registers[ENV]));// (assign val (op lookup_variable_value) (const exp) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH336");
}// (branch (label primitive_branch336))
compiled_branch337();
}
void compiled_branch337()
{// compiled_branch337
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch336()
{// primitive_branch336
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call338();
}
void after_call338()
{// after_call338
after_lambda335();
}
void after_lambda335()
{// after_lambda335
define_variable(new SchemeDataType(SchemeDataType::TypeId::Symbol, "if_consequent"), registers[VAL], registers[ENV]);// (perform (op define_variable) (const if_consequent) (reg val) (reg env))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "ok"));// (assign val (const ok))
assign(VAL, make_compiled_procedure("ENTRY339", entry339, registers[ENV]));// (assign val (op make_compiled_procedure) (label entry339) (reg env))
goto_with_label("AFTER_LAMBDA340");// (goto (label after_lambda340))

}
void entry339()
{// entry339
assign(ENV, compiled_procedure_env(PROC));// (assign env (op compiled_procedure_env) (reg proc))
assign(ENV, extend_environment(new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp"), registers[ARGL], registers[ENV]));// (assign env (op extend_environment) (const exp) (reg argl) (reg env))
s.save(CONTINUE);// (save continue)
s.save(ENV);// (save env)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "not"), registers[ENV]));// (assign proc (op lookup_variable_value) (const not) (reg env))
s.save(PROC);// (save proc)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "null_p"), registers[ENV]));// (assign proc (op lookup_variable_value) (const null_p) (reg env))
s.save(PROC);// (save proc)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "cdddr"), registers[ENV]));// (assign proc (op lookup_variable_value) (const cdddr) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp"), registers[ENV]));// (assign val (op lookup_variable_value) (const exp) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH344");
}// (branch (label primitive_branch344))
compiled_branch345();
}
void compiled_branch345()
{// compiled_branch345
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL346"));// (assign continue (label after_call346))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch344()
{// primitive_branch344
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call346();
}
void after_call346()
{// after_call346
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
s.restore(PROC);// (restore proc)
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH347");
}// (branch (label primitive_branch347))
compiled_branch348();
}
void compiled_branch348()
{// compiled_branch348
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL349"));// (assign continue (label after_call349))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch347()
{// primitive_branch347
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call349();
}
void after_call349()
{// after_call349
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
s.restore(PROC);// (restore proc)
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH350");
}// (branch (label primitive_branch350))
compiled_branch351();
}
void compiled_branch351()
{// compiled_branch351
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL352"));// (assign continue (label after_call352))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch350()
{// primitive_branch350
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call352();
}
void after_call352()
{// after_call352
s.restore(ENV);// (restore env)
s.restore(CONTINUE);// (restore continue)
if ( false_p(registers[VAL]) ) {// (test (op false_p) (reg val))
return goto_with_label("FALSE_BRANCH342");
}// (branch (label false_branch342))
true_branch341();
}
void true_branch341()
{// true_branch341
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "cadddr"), registers[ENV]));// (assign proc (op lookup_variable_value) (const cadddr) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp"), registers[ENV]));// (assign val (op lookup_variable_value) (const exp) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH353");
}// (branch (label primitive_branch353))
compiled_branch354();
}
void compiled_branch354()
{// compiled_branch354
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch353()
{// primitive_branch353
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call355();
}
void after_call355()
{// after_call355

}
void false_branch342()
{// false_branch342
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "false"));// (assign val (const false))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_if343();
}
void after_if343()
{// after_if343
after_lambda340();
}
void after_lambda340()
{// after_lambda340
define_variable(new SchemeDataType(SchemeDataType::TypeId::Symbol, "if_alternative"), registers[VAL], registers[ENV]);// (perform (op define_variable) (const if_alternative) (reg val) (reg env))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "ok"));// (assign val (const ok))
assign(VAL, make_compiled_procedure("ENTRY356", entry356, registers[ENV]));// (assign val (op make_compiled_procedure) (label entry356) (reg env))
goto_with_label("AFTER_LAMBDA357");// (goto (label after_lambda357))

}
void entry356()
{// entry356
assign(ENV, compiled_procedure_env(PROC));// (assign env (op compiled_procedure_env) (reg proc))
assign(ENV, extend_environment(list(3, new SchemeDataType(SchemeDataType::TypeId::Symbol, "predicate") , new SchemeDataType(SchemeDataType::TypeId::Symbol, "consequent") , new SchemeDataType(SchemeDataType::TypeId::Symbol, "alternative") ), registers[ARGL], registers[ENV]));// (assign env (op extend_environment) (const (predicate consequent alternative)) (reg argl) (reg env))
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "list"), registers[ENV]));// (assign proc (op lookup_variable_value) (const list) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "alternative"), registers[ENV]));// (assign val (op lookup_variable_value) (const alternative) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "consequent"), registers[ENV]));// (assign val (op lookup_variable_value) (const consequent) (reg env))
assign(ARGL, cons(registers[VAL], registers[ARGL]));// (assign argl (op cons) (reg val) (reg argl))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "predicate"), registers[ENV]));// (assign val (op lookup_variable_value) (const predicate) (reg env))
assign(ARGL, cons(registers[VAL], registers[ARGL]));// (assign argl (op cons) (reg val) (reg argl))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "if"));// (assign val (const if))
assign(ARGL, cons(registers[VAL], registers[ARGL]));// (assign argl (op cons) (reg val) (reg argl))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH358");
}// (branch (label primitive_branch358))
compiled_branch359();
}
void compiled_branch359()
{// compiled_branch359
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch358()
{// primitive_branch358
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call360();
}
void after_call360()
{// after_call360
after_lambda357();
}
void after_lambda357()
{// after_lambda357
define_variable(new SchemeDataType(SchemeDataType::TypeId::Symbol, "make_if"), registers[VAL], registers[ENV]);// (perform (op define_variable) (const make_if) (reg val) (reg env))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "ok"));// (assign val (const ok))
assign(VAL, make_compiled_procedure("ENTRY361", entry361, registers[ENV]));// (assign val (op make_compiled_procedure) (label entry361) (reg env))
goto_with_label("AFTER_LAMBDA362");// (goto (label after_lambda362))

}
void entry361()
{// entry361
assign(ENV, compiled_procedure_env(PROC));// (assign env (op compiled_procedure_env) (reg proc))
assign(ENV, extend_environment(new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp"), registers[ARGL], registers[ENV]));// (assign env (op extend_environment) (const exp) (reg argl) (reg env))
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "tagged_list_p"), registers[ENV]));// (assign proc (op lookup_variable_value) (const tagged_list_p) (reg env))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "begin"));// (assign val (const begin))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp"), registers[ENV]));// (assign val (op lookup_variable_value) (const exp) (reg env))
assign(ARGL, cons(registers[VAL], registers[ARGL]));// (assign argl (op cons) (reg val) (reg argl))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH363");
}// (branch (label primitive_branch363))
compiled_branch364();
}
void compiled_branch364()
{// compiled_branch364
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch363()
{// primitive_branch363
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call365();
}
void after_call365()
{// after_call365
after_lambda362();
}
void after_lambda362()
{// after_lambda362
define_variable(new SchemeDataType(SchemeDataType::TypeId::Symbol, "begin_p"), registers[VAL], registers[ENV]);// (perform (op define_variable) (const begin_p) (reg val) (reg env))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "ok"));// (assign val (const ok))
assign(VAL, make_compiled_procedure("ENTRY366", entry366, registers[ENV]));// (assign val (op make_compiled_procedure) (label entry366) (reg env))
goto_with_label("AFTER_LAMBDA367");// (goto (label after_lambda367))

}
void entry366()
{// entry366
assign(ENV, compiled_procedure_env(PROC));// (assign env (op compiled_procedure_env) (reg proc))
assign(ENV, extend_environment(new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp"), registers[ARGL], registers[ENV]));// (assign env (op extend_environment) (const exp) (reg argl) (reg env))
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "cdr"), registers[ENV]));// (assign proc (op lookup_variable_value) (const cdr) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp"), registers[ENV]));// (assign val (op lookup_variable_value) (const exp) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH368");
}// (branch (label primitive_branch368))
compiled_branch369();
}
void compiled_branch369()
{// compiled_branch369
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch368()
{// primitive_branch368
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call370();
}
void after_call370()
{// after_call370
after_lambda367();
}
void after_lambda367()
{// after_lambda367
define_variable(new SchemeDataType(SchemeDataType::TypeId::Symbol, "begin_actions"), registers[VAL], registers[ENV]);// (perform (op define_variable) (const begin_actions) (reg val) (reg env))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "ok"));// (assign val (const ok))
assign(VAL, make_compiled_procedure("ENTRY371", entry371, registers[ENV]));// (assign val (op make_compiled_procedure) (label entry371) (reg env))
goto_with_label("AFTER_LAMBDA372");// (goto (label after_lambda372))

}
void entry371()
{// entry371
assign(ENV, compiled_procedure_env(PROC));// (assign env (op compiled_procedure_env) (reg proc))
assign(ENV, extend_environment(new SchemeDataType(SchemeDataType::TypeId::Symbol, "seq"), registers[ARGL], registers[ENV]));// (assign env (op extend_environment) (const seq) (reg argl) (reg env))
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "null_p"), registers[ENV]));// (assign proc (op lookup_variable_value) (const null_p) (reg env))
s.save(CONTINUE);// (save continue)
s.save(PROC);// (save proc)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "cdr"), registers[ENV]));// (assign proc (op lookup_variable_value) (const cdr) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "seq"), registers[ENV]));// (assign val (op lookup_variable_value) (const seq) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH373");
}// (branch (label primitive_branch373))
compiled_branch374();
}
void compiled_branch374()
{// compiled_branch374
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL375"));// (assign continue (label after_call375))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch373()
{// primitive_branch373
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call375();
}
void after_call375()
{// after_call375
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
s.restore(PROC);// (restore proc)
s.restore(CONTINUE);// (restore continue)
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH376");
}// (branch (label primitive_branch376))
compiled_branch377();
}
void compiled_branch377()
{// compiled_branch377
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch376()
{// primitive_branch376
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call378();
}
void after_call378()
{// after_call378
after_lambda372();
}
void after_lambda372()
{// after_lambda372
define_variable(new SchemeDataType(SchemeDataType::TypeId::Symbol, "last_exp_p"), registers[VAL], registers[ENV]);// (perform (op define_variable) (const last_exp_p) (reg val) (reg env))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "ok"));// (assign val (const ok))
assign(VAL, make_compiled_procedure("ENTRY379", entry379, registers[ENV]));// (assign val (op make_compiled_procedure) (label entry379) (reg env))
goto_with_label("AFTER_LAMBDA380");// (goto (label after_lambda380))

}
void entry379()
{// entry379
assign(ENV, compiled_procedure_env(PROC));// (assign env (op compiled_procedure_env) (reg proc))
assign(ENV, extend_environment(new SchemeDataType(SchemeDataType::TypeId::Symbol, "seq"), registers[ARGL], registers[ENV]));// (assign env (op extend_environment) (const seq) (reg argl) (reg env))
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "car"), registers[ENV]));// (assign proc (op lookup_variable_value) (const car) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "seq"), registers[ENV]));// (assign val (op lookup_variable_value) (const seq) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH381");
}// (branch (label primitive_branch381))
compiled_branch382();
}
void compiled_branch382()
{// compiled_branch382
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch381()
{// primitive_branch381
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call383();
}
void after_call383()
{// after_call383
after_lambda380();
}
void after_lambda380()
{// after_lambda380
define_variable(new SchemeDataType(SchemeDataType::TypeId::Symbol, "first_exp"), registers[VAL], registers[ENV]);// (perform (op define_variable) (const first_exp) (reg val) (reg env))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "ok"));// (assign val (const ok))
assign(VAL, make_compiled_procedure("ENTRY384", entry384, registers[ENV]));// (assign val (op make_compiled_procedure) (label entry384) (reg env))
goto_with_label("AFTER_LAMBDA385");// (goto (label after_lambda385))

}
void entry384()
{// entry384
assign(ENV, compiled_procedure_env(PROC));// (assign env (op compiled_procedure_env) (reg proc))
assign(ENV, extend_environment(new SchemeDataType(SchemeDataType::TypeId::Symbol, "seq"), registers[ARGL], registers[ENV]));// (assign env (op extend_environment) (const seq) (reg argl) (reg env))
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "cdr"), registers[ENV]));// (assign proc (op lookup_variable_value) (const cdr) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "seq"), registers[ENV]));// (assign val (op lookup_variable_value) (const seq) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH386");
}// (branch (label primitive_branch386))
compiled_branch387();
}
void compiled_branch387()
{// compiled_branch387
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch386()
{// primitive_branch386
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call388();
}
void after_call388()
{// after_call388
after_lambda385();
}
void after_lambda385()
{// after_lambda385
define_variable(new SchemeDataType(SchemeDataType::TypeId::Symbol, "rest_exps"), registers[VAL], registers[ENV]);// (perform (op define_variable) (const rest_exps) (reg val) (reg env))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "ok"));// (assign val (const ok))
assign(VAL, make_compiled_procedure("ENTRY389", entry389, registers[ENV]));// (assign val (op make_compiled_procedure) (label entry389) (reg env))
goto_with_label("AFTER_LAMBDA390");// (goto (label after_lambda390))

}
void entry389()
{// entry389
assign(ENV, compiled_procedure_env(PROC));// (assign env (op compiled_procedure_env) (reg proc))
assign(ENV, extend_environment(new SchemeDataType(SchemeDataType::TypeId::Symbol, "seq"), registers[ARGL], registers[ENV]));// (assign env (op extend_environment) (const seq) (reg argl) (reg env))
s.save(CONTINUE);// (save continue)
s.save(ENV);// (save env)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "null_p"), registers[ENV]));// (assign proc (op lookup_variable_value) (const null_p) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "seq"), registers[ENV]));// (assign val (op lookup_variable_value) (const seq) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH394");
}// (branch (label primitive_branch394))
compiled_branch395();
}
void compiled_branch395()
{// compiled_branch395
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL396"));// (assign continue (label after_call396))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch394()
{// primitive_branch394
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call396();
}
void after_call396()
{// after_call396
s.restore(ENV);// (restore env)
s.restore(CONTINUE);// (restore continue)
if ( false_p(registers[VAL]) ) {// (test (op false_p) (reg val))
return goto_with_label("FALSE_BRANCH392");
}// (branch (label false_branch392))
true_branch391();
}
void true_branch391()
{// true_branch391
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "seq"), registers[ENV]));// (assign val (op lookup_variable_value) (const seq) (reg env))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))

}
void false_branch392()
{// false_branch392
s.save(CONTINUE);// (save continue)
s.save(ENV);// (save env)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "last_exp_p"), registers[ENV]));// (assign proc (op lookup_variable_value) (const last_exp_p) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "seq"), registers[ENV]));// (assign val (op lookup_variable_value) (const seq) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH400");
}// (branch (label primitive_branch400))
compiled_branch401();
}
void compiled_branch401()
{// compiled_branch401
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL402"));// (assign continue (label after_call402))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch400()
{// primitive_branch400
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call402();
}
void after_call402()
{// after_call402
s.restore(ENV);// (restore env)
s.restore(CONTINUE);// (restore continue)
if ( false_p(registers[VAL]) ) {// (test (op false_p) (reg val))
return goto_with_label("FALSE_BRANCH398");
}// (branch (label false_branch398))
true_branch397();
}
void true_branch397()
{// true_branch397
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "first_exp"), registers[ENV]));// (assign proc (op lookup_variable_value) (const first_exp) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "seq"), registers[ENV]));// (assign val (op lookup_variable_value) (const seq) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH403");
}// (branch (label primitive_branch403))
compiled_branch404();
}
void compiled_branch404()
{// compiled_branch404
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch403()
{// primitive_branch403
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call405();
}
void after_call405()
{// after_call405

}
void false_branch398()
{// false_branch398
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "make_begin"), registers[ENV]));// (assign proc (op lookup_variable_value) (const make_begin) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "seq"), registers[ENV]));// (assign val (op lookup_variable_value) (const seq) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH406");
}// (branch (label primitive_branch406))
compiled_branch407();
}
void compiled_branch407()
{// compiled_branch407
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch406()
{// primitive_branch406
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call408();
}
void after_call408()
{// after_call408
after_if399();
}
void after_if399()
{// after_if399
after_if393();
}
void after_if393()
{// after_if393
after_lambda390();
}
void after_lambda390()
{// after_lambda390
define_variable(new SchemeDataType(SchemeDataType::TypeId::Symbol, "sequence_>exp"), registers[VAL], registers[ENV]);// (perform (op define_variable) (const sequence_>exp) (reg val) (reg env))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "ok"));// (assign val (const ok))
assign(VAL, make_compiled_procedure("ENTRY409", entry409, registers[ENV]));// (assign val (op make_compiled_procedure) (label entry409) (reg env))
goto_with_label("AFTER_LAMBDA410");// (goto (label after_lambda410))

}
void entry409()
{// entry409
assign(ENV, compiled_procedure_env(PROC));// (assign env (op compiled_procedure_env) (reg proc))
assign(ENV, extend_environment(new SchemeDataType(SchemeDataType::TypeId::Symbol, "seq"), registers[ARGL], registers[ENV]));// (assign env (op extend_environment) (const seq) (reg argl) (reg env))
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "cons"), registers[ENV]));// (assign proc (op lookup_variable_value) (const cons) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "seq"), registers[ENV]));// (assign val (op lookup_variable_value) (const seq) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "begin"));// (assign val (const begin))
assign(ARGL, cons(registers[VAL], registers[ARGL]));// (assign argl (op cons) (reg val) (reg argl))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH411");
}// (branch (label primitive_branch411))
compiled_branch412();
}
void compiled_branch412()
{// compiled_branch412
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch411()
{// primitive_branch411
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call413();
}
void after_call413()
{// after_call413
after_lambda410();
}
void after_lambda410()
{// after_lambda410
define_variable(new SchemeDataType(SchemeDataType::TypeId::Symbol, "make_begin"), registers[VAL], registers[ENV]);// (perform (op define_variable) (const make_begin) (reg val) (reg env))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "ok"));// (assign val (const ok))
assign(VAL, make_compiled_procedure("ENTRY414", entry414, registers[ENV]));// (assign val (op make_compiled_procedure) (label entry414) (reg env))
goto_with_label("AFTER_LAMBDA415");// (goto (label after_lambda415))

}
void entry414()
{// entry414
assign(ENV, compiled_procedure_env(PROC));// (assign env (op compiled_procedure_env) (reg proc))
assign(ENV, extend_environment(new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp"), registers[ARGL], registers[ENV]));// (assign env (op extend_environment) (const exp) (reg argl) (reg env))
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "pair_p"), registers[ENV]));// (assign proc (op lookup_variable_value) (const pair_p) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp"), registers[ENV]));// (assign val (op lookup_variable_value) (const exp) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH416");
}// (branch (label primitive_branch416))
compiled_branch417();
}
void compiled_branch417()
{// compiled_branch417
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch416()
{// primitive_branch416
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call418();
}
void after_call418()
{// after_call418
after_lambda415();
}
void after_lambda415()
{// after_lambda415
define_variable(new SchemeDataType(SchemeDataType::TypeId::Symbol, "application_p"), registers[VAL], registers[ENV]);// (perform (op define_variable) (const application_p) (reg val) (reg env))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "ok"));// (assign val (const ok))
assign(VAL, make_compiled_procedure("ENTRY419", entry419, registers[ENV]));// (assign val (op make_compiled_procedure) (label entry419) (reg env))
goto_with_label("AFTER_LAMBDA420");// (goto (label after_lambda420))

}
void entry419()
{// entry419
assign(ENV, compiled_procedure_env(PROC));// (assign env (op compiled_procedure_env) (reg proc))
assign(ENV, extend_environment(new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp"), registers[ARGL], registers[ENV]));// (assign env (op extend_environment) (const exp) (reg argl) (reg env))
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "car"), registers[ENV]));// (assign proc (op lookup_variable_value) (const car) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp"), registers[ENV]));// (assign val (op lookup_variable_value) (const exp) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH421");
}// (branch (label primitive_branch421))
compiled_branch422();
}
void compiled_branch422()
{// compiled_branch422
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch421()
{// primitive_branch421
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call423();
}
void after_call423()
{// after_call423
after_lambda420();
}
void after_lambda420()
{// after_lambda420
define_variable(new SchemeDataType(SchemeDataType::TypeId::Symbol, "operator"), registers[VAL], registers[ENV]);// (perform (op define_variable) (const operator) (reg val) (reg env))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "ok"));// (assign val (const ok))
assign(VAL, make_compiled_procedure("ENTRY424", entry424, registers[ENV]));// (assign val (op make_compiled_procedure) (label entry424) (reg env))
goto_with_label("AFTER_LAMBDA425");// (goto (label after_lambda425))

}
void entry424()
{// entry424
assign(ENV, compiled_procedure_env(PROC));// (assign env (op compiled_procedure_env) (reg proc))
assign(ENV, extend_environment(new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp"), registers[ARGL], registers[ENV]));// (assign env (op extend_environment) (const exp) (reg argl) (reg env))
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "cdr"), registers[ENV]));// (assign proc (op lookup_variable_value) (const cdr) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp"), registers[ENV]));// (assign val (op lookup_variable_value) (const exp) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH426");
}// (branch (label primitive_branch426))
compiled_branch427();
}
void compiled_branch427()
{// compiled_branch427
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch426()
{// primitive_branch426
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call428();
}
void after_call428()
{// after_call428
after_lambda425();
}
void after_lambda425()
{// after_lambda425
define_variable(new SchemeDataType(SchemeDataType::TypeId::Symbol, "operands"), registers[VAL], registers[ENV]);// (perform (op define_variable) (const operands) (reg val) (reg env))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "ok"));// (assign val (const ok))
assign(VAL, make_compiled_procedure("ENTRY429", entry429, registers[ENV]));// (assign val (op make_compiled_procedure) (label entry429) (reg env))
goto_with_label("AFTER_LAMBDA430");// (goto (label after_lambda430))

}
void entry429()
{// entry429
assign(ENV, compiled_procedure_env(PROC));// (assign env (op compiled_procedure_env) (reg proc))
assign(ENV, extend_environment(new SchemeDataType(SchemeDataType::TypeId::Symbol, "ops"), registers[ARGL], registers[ENV]));// (assign env (op extend_environment) (const ops) (reg argl) (reg env))
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "null_p"), registers[ENV]));// (assign proc (op lookup_variable_value) (const null_p) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "ops"), registers[ENV]));// (assign val (op lookup_variable_value) (const ops) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH431");
}// (branch (label primitive_branch431))
compiled_branch432();
}
void compiled_branch432()
{// compiled_branch432
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch431()
{// primitive_branch431
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call433();
}
void after_call433()
{// after_call433
after_lambda430();
}
void after_lambda430()
{// after_lambda430
define_variable(new SchemeDataType(SchemeDataType::TypeId::Symbol, "no_operands_p"), registers[VAL], registers[ENV]);// (perform (op define_variable) (const no_operands_p) (reg val) (reg env))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "ok"));// (assign val (const ok))
assign(VAL, make_compiled_procedure("ENTRY434", entry434, registers[ENV]));// (assign val (op make_compiled_procedure) (label entry434) (reg env))
goto_with_label("AFTER_LAMBDA435");// (goto (label after_lambda435))

}
void entry434()
{// entry434
assign(ENV, compiled_procedure_env(PROC));// (assign env (op compiled_procedure_env) (reg proc))
assign(ENV, extend_environment(new SchemeDataType(SchemeDataType::TypeId::Symbol, "ops"), registers[ARGL], registers[ENV]));// (assign env (op extend_environment) (const ops) (reg argl) (reg env))
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "car"), registers[ENV]));// (assign proc (op lookup_variable_value) (const car) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "ops"), registers[ENV]));// (assign val (op lookup_variable_value) (const ops) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH436");
}// (branch (label primitive_branch436))
compiled_branch437();
}
void compiled_branch437()
{// compiled_branch437
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch436()
{// primitive_branch436
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call438();
}
void after_call438()
{// after_call438
after_lambda435();
}
void after_lambda435()
{// after_lambda435
define_variable(new SchemeDataType(SchemeDataType::TypeId::Symbol, "first_operand"), registers[VAL], registers[ENV]);// (perform (op define_variable) (const first_operand) (reg val) (reg env))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "ok"));// (assign val (const ok))
assign(VAL, make_compiled_procedure("ENTRY439", entry439, registers[ENV]));// (assign val (op make_compiled_procedure) (label entry439) (reg env))
goto_with_label("AFTER_LAMBDA440");// (goto (label after_lambda440))

}
void entry439()
{// entry439
assign(ENV, compiled_procedure_env(PROC));// (assign env (op compiled_procedure_env) (reg proc))
assign(ENV, extend_environment(new SchemeDataType(SchemeDataType::TypeId::Symbol, "ops"), registers[ARGL], registers[ENV]));// (assign env (op extend_environment) (const ops) (reg argl) (reg env))
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "cdr"), registers[ENV]));// (assign proc (op lookup_variable_value) (const cdr) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "ops"), registers[ENV]));// (assign val (op lookup_variable_value) (const ops) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH441");
}// (branch (label primitive_branch441))
compiled_branch442();
}
void compiled_branch442()
{// compiled_branch442
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch441()
{// primitive_branch441
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call443();
}
void after_call443()
{// after_call443
after_lambda440();
}
void after_lambda440()
{// after_lambda440
define_variable(new SchemeDataType(SchemeDataType::TypeId::Symbol, "rest_operands"), registers[VAL], registers[ENV]);// (perform (op define_variable) (const rest_operands) (reg val) (reg env))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "ok"));// (assign val (const ok))
assign(VAL, make_compiled_procedure("ENTRY444", entry444, registers[ENV]));// (assign val (op make_compiled_procedure) (label entry444) (reg env))
goto_with_label("AFTER_LAMBDA445");// (goto (label after_lambda445))

}
void entry444()
{// entry444
assign(ENV, compiled_procedure_env(PROC));// (assign env (op compiled_procedure_env) (reg proc))
assign(ENV, extend_environment(new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp"), registers[ARGL], registers[ENV]));// (assign env (op extend_environment) (const exp) (reg argl) (reg env))
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "tagged_list_p"), registers[ENV]));// (assign proc (op lookup_variable_value) (const tagged_list_p) (reg env))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "cond"));// (assign val (const cond))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp"), registers[ENV]));// (assign val (op lookup_variable_value) (const exp) (reg env))
assign(ARGL, cons(registers[VAL], registers[ARGL]));// (assign argl (op cons) (reg val) (reg argl))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH446");
}// (branch (label primitive_branch446))
compiled_branch447();
}
void compiled_branch447()
{// compiled_branch447
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch446()
{// primitive_branch446
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call448();
}
void after_call448()
{// after_call448
after_lambda445();
}
void after_lambda445()
{// after_lambda445
define_variable(new SchemeDataType(SchemeDataType::TypeId::Symbol, "cond_p"), registers[VAL], registers[ENV]);// (perform (op define_variable) (const cond_p) (reg val) (reg env))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "ok"));// (assign val (const ok))
assign(VAL, make_compiled_procedure("ENTRY449", entry449, registers[ENV]));// (assign val (op make_compiled_procedure) (label entry449) (reg env))
goto_with_label("AFTER_LAMBDA450");// (goto (label after_lambda450))

}
void entry449()
{// entry449
assign(ENV, compiled_procedure_env(PROC));// (assign env (op compiled_procedure_env) (reg proc))
assign(ENV, extend_environment(new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp"), registers[ARGL], registers[ENV]));// (assign env (op extend_environment) (const exp) (reg argl) (reg env))
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "cdr"), registers[ENV]));// (assign proc (op lookup_variable_value) (const cdr) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp"), registers[ENV]));// (assign val (op lookup_variable_value) (const exp) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH451");
}// (branch (label primitive_branch451))
compiled_branch452();
}
void compiled_branch452()
{// compiled_branch452
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch451()
{// primitive_branch451
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call453();
}
void after_call453()
{// after_call453
after_lambda450();
}
void after_lambda450()
{// after_lambda450
define_variable(new SchemeDataType(SchemeDataType::TypeId::Symbol, "cond_clauses"), registers[VAL], registers[ENV]);// (perform (op define_variable) (const cond_clauses) (reg val) (reg env))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "ok"));// (assign val (const ok))
assign(VAL, make_compiled_procedure("ENTRY454", entry454, registers[ENV]));// (assign val (op make_compiled_procedure) (label entry454) (reg env))
goto_with_label("AFTER_LAMBDA455");// (goto (label after_lambda455))

}
void entry454()
{// entry454
assign(ENV, compiled_procedure_env(PROC));// (assign env (op compiled_procedure_env) (reg proc))
assign(ENV, extend_environment(new SchemeDataType(SchemeDataType::TypeId::Symbol, "clause"), registers[ARGL], registers[ENV]));// (assign env (op extend_environment) (const clause) (reg argl) (reg env))
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "eq_p"), registers[ENV]));// (assign proc (op lookup_variable_value) (const eq_p) (reg env))
s.save(CONTINUE);// (save continue)
s.save(PROC);// (save proc)
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "else"));// (assign val (const else))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
s.save(ARGL);// (save argl)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "cond_predicate"), registers[ENV]));// (assign proc (op lookup_variable_value) (const cond_predicate) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "clause"), registers[ENV]));// (assign val (op lookup_variable_value) (const clause) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH456");
}// (branch (label primitive_branch456))
compiled_branch457();
}
void compiled_branch457()
{// compiled_branch457
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL458"));// (assign continue (label after_call458))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch456()
{// primitive_branch456
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call458();
}
void after_call458()
{// after_call458
s.restore(ARGL);// (restore argl)
assign(ARGL, cons(registers[VAL], registers[ARGL]));// (assign argl (op cons) (reg val) (reg argl))
s.restore(PROC);// (restore proc)
s.restore(CONTINUE);// (restore continue)
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH459");
}// (branch (label primitive_branch459))
compiled_branch460();
}
void compiled_branch460()
{// compiled_branch460
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch459()
{// primitive_branch459
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call461();
}
void after_call461()
{// after_call461
after_lambda455();
}
void after_lambda455()
{// after_lambda455
define_variable(new SchemeDataType(SchemeDataType::TypeId::Symbol, "cond_else_clause_p"), registers[VAL], registers[ENV]);// (perform (op define_variable) (const cond_else_clause_p) (reg val) (reg env))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "ok"));// (assign val (const ok))
assign(VAL, make_compiled_procedure("ENTRY462", entry462, registers[ENV]));// (assign val (op make_compiled_procedure) (label entry462) (reg env))
goto_with_label("AFTER_LAMBDA463");// (goto (label after_lambda463))

}
void entry462()
{// entry462
assign(ENV, compiled_procedure_env(PROC));// (assign env (op compiled_procedure_env) (reg proc))
assign(ENV, extend_environment(new SchemeDataType(SchemeDataType::TypeId::Symbol, "clause"), registers[ARGL], registers[ENV]));// (assign env (op extend_environment) (const clause) (reg argl) (reg env))
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "car"), registers[ENV]));// (assign proc (op lookup_variable_value) (const car) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "clause"), registers[ENV]));// (assign val (op lookup_variable_value) (const clause) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH464");
}// (branch (label primitive_branch464))
compiled_branch465();
}
void compiled_branch465()
{// compiled_branch465
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch464()
{// primitive_branch464
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call466();
}
void after_call466()
{// after_call466
after_lambda463();
}
void after_lambda463()
{// after_lambda463
define_variable(new SchemeDataType(SchemeDataType::TypeId::Symbol, "cond_predicate"), registers[VAL], registers[ENV]);// (perform (op define_variable) (const cond_predicate) (reg val) (reg env))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "ok"));// (assign val (const ok))
assign(VAL, make_compiled_procedure("ENTRY467", entry467, registers[ENV]));// (assign val (op make_compiled_procedure) (label entry467) (reg env))
goto_with_label("AFTER_LAMBDA468");// (goto (label after_lambda468))

}
void entry467()
{// entry467
assign(ENV, compiled_procedure_env(PROC));// (assign env (op compiled_procedure_env) (reg proc))
assign(ENV, extend_environment(new SchemeDataType(SchemeDataType::TypeId::Symbol, "clause"), registers[ARGL], registers[ENV]));// (assign env (op extend_environment) (const clause) (reg argl) (reg env))
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "cdr"), registers[ENV]));// (assign proc (op lookup_variable_value) (const cdr) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "clause"), registers[ENV]));// (assign val (op lookup_variable_value) (const clause) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH469");
}// (branch (label primitive_branch469))
compiled_branch470();
}
void compiled_branch470()
{// compiled_branch470
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch469()
{// primitive_branch469
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call471();
}
void after_call471()
{// after_call471
after_lambda468();
}
void after_lambda468()
{// after_lambda468
define_variable(new SchemeDataType(SchemeDataType::TypeId::Symbol, "cond_actions"), registers[VAL], registers[ENV]);// (perform (op define_variable) (const cond_actions) (reg val) (reg env))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "ok"));// (assign val (const ok))
assign(VAL, make_compiled_procedure("ENTRY472", entry472, registers[ENV]));// (assign val (op make_compiled_procedure) (label entry472) (reg env))
goto_with_label("AFTER_LAMBDA473");// (goto (label after_lambda473))

}
void entry472()
{// entry472
assign(ENV, compiled_procedure_env(PROC));// (assign env (op compiled_procedure_env) (reg proc))
assign(ENV, extend_environment(new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp"), registers[ARGL], registers[ENV]));// (assign env (op extend_environment) (const exp) (reg argl) (reg env))
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "expand_clauses"), registers[ENV]));// (assign proc (op lookup_variable_value) (const expand_clauses) (reg env))
s.save(CONTINUE);// (save continue)
s.save(PROC);// (save proc)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "cond_clauses"), registers[ENV]));// (assign proc (op lookup_variable_value) (const cond_clauses) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp"), registers[ENV]));// (assign val (op lookup_variable_value) (const exp) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH474");
}// (branch (label primitive_branch474))
compiled_branch475();
}
void compiled_branch475()
{// compiled_branch475
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL476"));// (assign continue (label after_call476))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch474()
{// primitive_branch474
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call476();
}
void after_call476()
{// after_call476
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
s.restore(PROC);// (restore proc)
s.restore(CONTINUE);// (restore continue)
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH477");
}// (branch (label primitive_branch477))
compiled_branch478();
}
void compiled_branch478()
{// compiled_branch478
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch477()
{// primitive_branch477
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call479();
}
void after_call479()
{// after_call479
after_lambda473();
}
void after_lambda473()
{// after_lambda473
define_variable(new SchemeDataType(SchemeDataType::TypeId::Symbol, "cond_>if"), registers[VAL], registers[ENV]);// (perform (op define_variable) (const cond_>if) (reg val) (reg env))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "ok"));// (assign val (const ok))
assign(VAL, make_compiled_procedure("ENTRY480", entry480, registers[ENV]));// (assign val (op make_compiled_procedure) (label entry480) (reg env))
goto_with_label("AFTER_LAMBDA481");// (goto (label after_lambda481))

}
void entry480()
{// entry480
assign(ENV, compiled_procedure_env(PROC));// (assign env (op compiled_procedure_env) (reg proc))
assign(ENV, extend_environment(new SchemeDataType(SchemeDataType::TypeId::Symbol, "clauses"), registers[ARGL], registers[ENV]));// (assign env (op extend_environment) (const clauses) (reg argl) (reg env))
s.save(CONTINUE);// (save continue)
s.save(ENV);// (save env)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "null_p"), registers[ENV]));// (assign proc (op lookup_variable_value) (const null_p) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "clauses"), registers[ENV]));// (assign val (op lookup_variable_value) (const clauses) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH485");
}// (branch (label primitive_branch485))
compiled_branch486();
}
void compiled_branch486()
{// compiled_branch486
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL487"));// (assign continue (label after_call487))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch485()
{// primitive_branch485
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call487();
}
void after_call487()
{// after_call487
s.restore(ENV);// (restore env)
s.restore(CONTINUE);// (restore continue)
if ( false_p(registers[VAL]) ) {// (test (op false_p) (reg val))
return goto_with_label("FALSE_BRANCH483");
}// (branch (label false_branch483))
true_branch482();
}
void true_branch482()
{// true_branch482
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "false"));// (assign val (const false))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))

}
void false_branch483()
{// false_branch483
assign(PROC, make_compiled_procedure("ENTRY488", entry488, registers[ENV]));// (assign proc (op make_compiled_procedure) (label entry488) (reg env))
goto_with_label("AFTER_LAMBDA489");// (goto (label after_lambda489))

}
void entry488()
{// entry488
assign(ENV, compiled_procedure_env(PROC));// (assign env (op compiled_procedure_env) (reg proc))
assign(ENV, extend_environment(list(2, new SchemeDataType(SchemeDataType::TypeId::Symbol, "first") , new SchemeDataType(SchemeDataType::TypeId::Symbol, "rest") ), registers[ARGL], registers[ENV]));// (assign env (op extend_environment) (const (first rest)) (reg argl) (reg env))
s.save(CONTINUE);// (save continue)
s.save(ENV);// (save env)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "cond_else_clause_p"), registers[ENV]));// (assign proc (op lookup_variable_value) (const cond_else_clause_p) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "first"), registers[ENV]));// (assign val (op lookup_variable_value) (const first) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH493");
}// (branch (label primitive_branch493))
compiled_branch494();
}
void compiled_branch494()
{// compiled_branch494
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL495"));// (assign continue (label after_call495))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch493()
{// primitive_branch493
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call495();
}
void after_call495()
{// after_call495
s.restore(ENV);// (restore env)
s.restore(CONTINUE);// (restore continue)
if ( false_p(registers[VAL]) ) {// (test (op false_p) (reg val))
return goto_with_label("FALSE_BRANCH491");
}// (branch (label false_branch491))
true_branch490();
}
void true_branch490()
{// true_branch490
s.save(CONTINUE);// (save continue)
s.save(ENV);// (save env)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "null_p"), registers[ENV]));// (assign proc (op lookup_variable_value) (const null_p) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "rest"), registers[ENV]));// (assign val (op lookup_variable_value) (const rest) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH499");
}// (branch (label primitive_branch499))
compiled_branch500();
}
void compiled_branch500()
{// compiled_branch500
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL501"));// (assign continue (label after_call501))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch499()
{// primitive_branch499
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call501();
}
void after_call501()
{// after_call501
s.restore(ENV);// (restore env)
s.restore(CONTINUE);// (restore continue)
if ( false_p(registers[VAL]) ) {// (test (op false_p) (reg val))
return goto_with_label("FALSE_BRANCH497");
}// (branch (label false_branch497))
true_branch496();
}
void true_branch496()
{// true_branch496
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "sequence_>exp"), registers[ENV]));// (assign proc (op lookup_variable_value) (const sequence_>exp) (reg env))
s.save(CONTINUE);// (save continue)
s.save(PROC);// (save proc)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "cond_actions"), registers[ENV]));// (assign proc (op lookup_variable_value) (const cond_actions) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "first"), registers[ENV]));// (assign val (op lookup_variable_value) (const first) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH502");
}// (branch (label primitive_branch502))
compiled_branch503();
}
void compiled_branch503()
{// compiled_branch503
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL504"));// (assign continue (label after_call504))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch502()
{// primitive_branch502
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call504();
}
void after_call504()
{// after_call504
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
s.restore(PROC);// (restore proc)
s.restore(CONTINUE);// (restore continue)
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH505");
}// (branch (label primitive_branch505))
compiled_branch506();
}
void compiled_branch506()
{// compiled_branch506
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch505()
{// primitive_branch505
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call507();
}
void after_call507()
{// after_call507

}
void false_branch497()
{// false_branch497
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "error"), registers[ENV]));// (assign proc (op lookup_variable_value) (const error) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "clauses"), registers[ENV]));// (assign val (op lookup_variable_value) (const clauses) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "ELSE clause isn't last __ COND_>IF"));// (assign val (const ELSE clause isn't last __ COND_>IF))
assign(ARGL, cons(registers[VAL], registers[ARGL]));// (assign argl (op cons) (reg val) (reg argl))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH508");
}// (branch (label primitive_branch508))
compiled_branch509();
}
void compiled_branch509()
{// compiled_branch509
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch508()
{// primitive_branch508
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call510();
}
void after_call510()
{// after_call510
after_if498();
}
void after_if498()
{// after_if498

}
void false_branch491()
{// false_branch491
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "make_if"), registers[ENV]));// (assign proc (op lookup_variable_value) (const make_if) (reg env))
s.save(CONTINUE);// (save continue)
s.save(PROC);// (save proc)
s.save(ENV);// (save env)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "expand_clauses"), registers[ENV]));// (assign proc (op lookup_variable_value) (const expand_clauses) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "rest"), registers[ENV]));// (assign val (op lookup_variable_value) (const rest) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH520");
}// (branch (label primitive_branch520))
compiled_branch521();
}
void compiled_branch521()
{// compiled_branch521
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL522"));// (assign continue (label after_call522))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch520()
{// primitive_branch520
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call522();
}
void after_call522()
{// after_call522
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
s.restore(ENV);// (restore env)
s.save(ENV);// (save env)
s.save(ARGL);// (save argl)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "sequence_>exp"), registers[ENV]));// (assign proc (op lookup_variable_value) (const sequence_>exp) (reg env))
s.save(PROC);// (save proc)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "cond_actions"), registers[ENV]));// (assign proc (op lookup_variable_value) (const cond_actions) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "first"), registers[ENV]));// (assign val (op lookup_variable_value) (const first) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH514");
}// (branch (label primitive_branch514))
compiled_branch515();
}
void compiled_branch515()
{// compiled_branch515
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL516"));// (assign continue (label after_call516))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch514()
{// primitive_branch514
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call516();
}
void after_call516()
{// after_call516
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
s.restore(PROC);// (restore proc)
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH517");
}// (branch (label primitive_branch517))
compiled_branch518();
}
void compiled_branch518()
{// compiled_branch518
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL519"));// (assign continue (label after_call519))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch517()
{// primitive_branch517
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call519();
}
void after_call519()
{// after_call519
s.restore(ARGL);// (restore argl)
assign(ARGL, cons(registers[VAL], registers[ARGL]));// (assign argl (op cons) (reg val) (reg argl))
s.restore(ENV);// (restore env)
s.save(ARGL);// (save argl)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "cond_predicate"), registers[ENV]));// (assign proc (op lookup_variable_value) (const cond_predicate) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "first"), registers[ENV]));// (assign val (op lookup_variable_value) (const first) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH511");
}// (branch (label primitive_branch511))
compiled_branch512();
}
void compiled_branch512()
{// compiled_branch512
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL513"));// (assign continue (label after_call513))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch511()
{// primitive_branch511
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call513();
}
void after_call513()
{// after_call513
s.restore(ARGL);// (restore argl)
assign(ARGL, cons(registers[VAL], registers[ARGL]));// (assign argl (op cons) (reg val) (reg argl))
s.restore(PROC);// (restore proc)
s.restore(CONTINUE);// (restore continue)
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH523");
}// (branch (label primitive_branch523))
compiled_branch524();
}
void compiled_branch524()
{// compiled_branch524
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch523()
{// primitive_branch523
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call525();
}
void after_call525()
{// after_call525
after_if492();
}
void after_if492()
{// after_if492
after_lambda489();
}
void after_lambda489()
{// after_lambda489
s.save(CONTINUE);// (save continue)
s.save(PROC);// (save proc)
s.save(ENV);// (save env)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "cdr"), registers[ENV]));// (assign proc (op lookup_variable_value) (const cdr) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "clauses"), registers[ENV]));// (assign val (op lookup_variable_value) (const clauses) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH529");
}// (branch (label primitive_branch529))
compiled_branch530();
}
void compiled_branch530()
{// compiled_branch530
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL531"));// (assign continue (label after_call531))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch529()
{// primitive_branch529
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call531();
}
void after_call531()
{// after_call531
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
s.restore(ENV);// (restore env)
s.save(ARGL);// (save argl)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "car"), registers[ENV]));// (assign proc (op lookup_variable_value) (const car) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "clauses"), registers[ENV]));// (assign val (op lookup_variable_value) (const clauses) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH526");
}// (branch (label primitive_branch526))
compiled_branch527();
}
void compiled_branch527()
{// compiled_branch527
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL528"));// (assign continue (label after_call528))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch526()
{// primitive_branch526
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call528();
}
void after_call528()
{// after_call528
s.restore(ARGL);// (restore argl)
assign(ARGL, cons(registers[VAL], registers[ARGL]));// (assign argl (op cons) (reg val) (reg argl))
s.restore(PROC);// (restore proc)
s.restore(CONTINUE);// (restore continue)
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH532");
}// (branch (label primitive_branch532))
compiled_branch533();
}
void compiled_branch533()
{// compiled_branch533
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch532()
{// primitive_branch532
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call534();
}
void after_call534()
{// after_call534
after_if484();
}
void after_if484()
{// after_if484
after_lambda481();
}
void after_lambda481()
{// after_lambda481
define_variable(new SchemeDataType(SchemeDataType::TypeId::Symbol, "expand_clauses"), registers[VAL], registers[ENV]);// (perform (op define_variable) (const expand_clauses) (reg val) (reg env))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "ok"));// (assign val (const ok))
assign(VAL, make_compiled_procedure("ENTRY535", entry535, registers[ENV]));// (assign val (op make_compiled_procedure) (label entry535) (reg env))
goto_with_label("AFTER_LAMBDA536");// (goto (label after_lambda536))

}
void entry535()
{// entry535
assign(ENV, compiled_procedure_env(PROC));// (assign env (op compiled_procedure_env) (reg proc))
assign(ENV, extend_environment(list(3, new SchemeDataType(SchemeDataType::TypeId::Symbol, "parameters") , new SchemeDataType(SchemeDataType::TypeId::Symbol, "body") , new SchemeDataType(SchemeDataType::TypeId::Symbol, "env") ), registers[ARGL], registers[ENV]));// (assign env (op extend_environment) (const (parameters body env)) (reg argl) (reg env))
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "list"), registers[ENV]));// (assign proc (op lookup_variable_value) (const list) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "env"), registers[ENV]));// (assign val (op lookup_variable_value) (const env) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "body"), registers[ENV]));// (assign val (op lookup_variable_value) (const body) (reg env))
assign(ARGL, cons(registers[VAL], registers[ARGL]));// (assign argl (op cons) (reg val) (reg argl))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "parameters"), registers[ENV]));// (assign val (op lookup_variable_value) (const parameters) (reg env))
assign(ARGL, cons(registers[VAL], registers[ARGL]));// (assign argl (op cons) (reg val) (reg argl))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "procedure"));// (assign val (const procedure))
assign(ARGL, cons(registers[VAL], registers[ARGL]));// (assign argl (op cons) (reg val) (reg argl))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH537");
}// (branch (label primitive_branch537))
compiled_branch538();
}
void compiled_branch538()
{// compiled_branch538
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch537()
{// primitive_branch537
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call539();
}
void after_call539()
{// after_call539
after_lambda536();
}
void after_lambda536()
{// after_lambda536
define_variable(new SchemeDataType(SchemeDataType::TypeId::Symbol, "make_procedure"), registers[VAL], registers[ENV]);// (perform (op define_variable) (const make_procedure) (reg val) (reg env))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "ok"));// (assign val (const ok))
assign(VAL, make_compiled_procedure("ENTRY540", entry540, registers[ENV]));// (assign val (op make_compiled_procedure) (label entry540) (reg env))
goto_with_label("AFTER_LAMBDA541");// (goto (label after_lambda541))

}
void entry540()
{// entry540
assign(ENV, compiled_procedure_env(PROC));// (assign env (op compiled_procedure_env) (reg proc))
assign(ENV, extend_environment(new SchemeDataType(SchemeDataType::TypeId::Symbol, "p"), registers[ARGL], registers[ENV]));// (assign env (op extend_environment) (const p) (reg argl) (reg env))
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "tagged_list_p"), registers[ENV]));// (assign proc (op lookup_variable_value) (const tagged_list_p) (reg env))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "procedure"));// (assign val (const procedure))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "p"), registers[ENV]));// (assign val (op lookup_variable_value) (const p) (reg env))
assign(ARGL, cons(registers[VAL], registers[ARGL]));// (assign argl (op cons) (reg val) (reg argl))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH542");
}// (branch (label primitive_branch542))
compiled_branch543();
}
void compiled_branch543()
{// compiled_branch543
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch542()
{// primitive_branch542
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call544();
}
void after_call544()
{// after_call544
after_lambda541();
}
void after_lambda541()
{// after_lambda541
define_variable(new SchemeDataType(SchemeDataType::TypeId::Symbol, "compound_procedure_p"), registers[VAL], registers[ENV]);// (perform (op define_variable) (const compound_procedure_p) (reg val) (reg env))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "ok"));// (assign val (const ok))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, ";;; M_Eval input:"));// (assign val (const ;;; M_Eval input:))
define_variable(new SchemeDataType(SchemeDataType::TypeId::Symbol, "input_prompt"), registers[VAL], registers[ENV]);// (perform (op define_variable) (const input_prompt) (reg val) (reg env))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "ok"));// (assign val (const ok))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, ";;; M_Eval value:"));// (assign val (const ;;; M_Eval value:))
define_variable(new SchemeDataType(SchemeDataType::TypeId::Symbol, "output_prompt"), registers[VAL], registers[ENV]);// (perform (op define_variable) (const output_prompt) (reg val) (reg env))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "ok"));// (assign val (const ok))
assign(VAL, make_compiled_procedure("ENTRY545", entry545, registers[ENV]));// (assign val (op make_compiled_procedure) (label entry545) (reg env))
goto_with_label("AFTER_LAMBDA546");// (goto (label after_lambda546))

}
void entry545()
{// entry545
assign(ENV, compiled_procedure_env(PROC));// (assign env (op compiled_procedure_env) (reg proc))
assign(ENV, extend_environment(new SchemeDataType(SchemeDataType::TypeId::Nil), registers[ARGL], registers[ENV]));
// (assign env (op extend_environment) (const nil ) (reg argl) (reg env))
s.save(CONTINUE);// (save continue)
s.save(ENV);// (save env)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "prompt_for_input"), registers[ENV]));// (assign proc (op lookup_variable_value) (const prompt_for_input) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "input_prompt"), registers[ENV]));// (assign val (op lookup_variable_value) (const input_prompt) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH547");
}// (branch (label primitive_branch547))
compiled_branch548();
}
void compiled_branch548()
{// compiled_branch548
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL549"));// (assign continue (label after_call549))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch547()
{// primitive_branch547
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call549();
}
void after_call549()
{// after_call549
s.restore(ENV);// (restore env)
s.restore(CONTINUE);// (restore continue)
assign(PROC, make_compiled_procedure("ENTRY550", entry550, registers[ENV]));// (assign proc (op make_compiled_procedure) (label entry550) (reg env))
goto_with_label("AFTER_LAMBDA551");// (goto (label after_lambda551))

}
void entry550()
{// entry550
assign(ENV, compiled_procedure_env(PROC));// (assign env (op compiled_procedure_env) (reg proc))
assign(ENV, extend_environment(new SchemeDataType(SchemeDataType::TypeId::Symbol, "input"), registers[ARGL], registers[ENV]));// (assign env (op extend_environment) (const input) (reg argl) (reg env))
assign(PROC, make_compiled_procedure("ENTRY552", entry552, registers[ENV]));// (assign proc (op make_compiled_procedure) (label entry552) (reg env))
goto_with_label("AFTER_LAMBDA553");// (goto (label after_lambda553))

}
void entry552()
{// entry552
assign(ENV, compiled_procedure_env(PROC));// (assign env (op compiled_procedure_env) (reg proc))
assign(ENV, extend_environment(new SchemeDataType(SchemeDataType::TypeId::Symbol, "output"), registers[ARGL], registers[ENV]));// (assign env (op extend_environment) (const output) (reg argl) (reg env))
s.save(CONTINUE);// (save continue)
s.save(ENV);// (save env)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "announce_output"), registers[ENV]));// (assign proc (op lookup_variable_value) (const announce_output) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "output_prompt"), registers[ENV]));// (assign val (op lookup_variable_value) (const output_prompt) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH554");
}// (branch (label primitive_branch554))
compiled_branch555();
}
void compiled_branch555()
{// compiled_branch555
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL556"));// (assign continue (label after_call556))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch554()
{// primitive_branch554
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call556();
}
void after_call556()
{// after_call556
s.restore(ENV);// (restore env)
s.restore(CONTINUE);// (restore continue)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "user_print"), registers[ENV]));// (assign proc (op lookup_variable_value) (const user_print) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "output"), registers[ENV]));// (assign val (op lookup_variable_value) (const output) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH557");
}// (branch (label primitive_branch557))
compiled_branch558();
}
void compiled_branch558()
{// compiled_branch558
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch557()
{// primitive_branch557
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call559();
}
void after_call559()
{// after_call559
after_lambda553();
}
void after_lambda553()
{// after_lambda553
s.save(CONTINUE);// (save continue)
s.save(PROC);// (save proc)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "eval"), registers[ENV]));// (assign proc (op lookup_variable_value) (const eval) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "the_global_environment"), registers[ENV]));// (assign val (op lookup_variable_value) (const the_global_environment) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "input"), registers[ENV]));// (assign val (op lookup_variable_value) (const input) (reg env))
assign(ARGL, cons(registers[VAL], registers[ARGL]));// (assign argl (op cons) (reg val) (reg argl))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH560");
}// (branch (label primitive_branch560))
compiled_branch561();
}
void compiled_branch561()
{// compiled_branch561
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL562"));// (assign continue (label after_call562))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch560()
{// primitive_branch560
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call562();
}
void after_call562()
{// after_call562
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
s.restore(PROC);// (restore proc)
s.restore(CONTINUE);// (restore continue)
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH563");
}// (branch (label primitive_branch563))
compiled_branch564();
}
void compiled_branch564()
{// compiled_branch564
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch563()
{// primitive_branch563
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call565();
}
void after_call565()
{// after_call565
after_lambda551();
}
void after_lambda551()
{// after_lambda551
s.save(CONTINUE);// (save continue)
s.save(PROC);// (save proc)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "read"), registers[ENV]));// (assign proc (op lookup_variable_value) (const read) (reg env))
assign(ARGL, new SchemeDataType(SchemeDataType::TypeId::Nil));// (assign argl (const nil ))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH566");
}// (branch (label primitive_branch566))
compiled_branch567();
}
void compiled_branch567()
{// compiled_branch567
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL568"));// (assign continue (label after_call568))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch566()
{// primitive_branch566
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call568();
}
void after_call568()
{// after_call568
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
s.restore(PROC);// (restore proc)
s.restore(CONTINUE);// (restore continue)
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH569");
}// (branch (label primitive_branch569))
compiled_branch570();
}
void compiled_branch570()
{// compiled_branch570
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch569()
{// primitive_branch569
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call571();
}
void after_call571()
{// after_call571
after_lambda546();
}
void after_lambda546()
{// after_lambda546
define_variable(new SchemeDataType(SchemeDataType::TypeId::Symbol, "driver_loop"), registers[VAL], registers[ENV]);// (perform (op define_variable) (const driver_loop) (reg val) (reg env))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "ok"));// (assign val (const ok))
assign(VAL, make_compiled_procedure("ENTRY572", entry572, registers[ENV]));// (assign val (op make_compiled_procedure) (label entry572) (reg env))
goto_with_label("AFTER_LAMBDA573");// (goto (label after_lambda573))

}
void entry572()
{// entry572
assign(ENV, compiled_procedure_env(PROC));// (assign env (op compiled_procedure_env) (reg proc))
assign(ENV, extend_environment(new SchemeDataType(SchemeDataType::TypeId::Symbol, "string"), registers[ARGL], registers[ENV]));// (assign env (op extend_environment) (const string) (reg argl) (reg env))
s.save(CONTINUE);// (save continue)
s.save(ENV);// (save env)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "newline"), registers[ENV]));// (assign proc (op lookup_variable_value) (const newline) (reg env))
assign(ARGL, new SchemeDataType(SchemeDataType::TypeId::Nil));// (assign argl (const nil ))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH574");
}// (branch (label primitive_branch574))
compiled_branch575();
}
void compiled_branch575()
{// compiled_branch575
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL576"));// (assign continue (label after_call576))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch574()
{// primitive_branch574
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call576();
}
void after_call576()
{// after_call576
s.restore(ENV);// (restore env)
s.restore(CONTINUE);// (restore continue)
s.save(CONTINUE);// (save continue)
s.save(ENV);// (save env)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "newline"), registers[ENV]));// (assign proc (op lookup_variable_value) (const newline) (reg env))
assign(ARGL, new SchemeDataType(SchemeDataType::TypeId::Nil));// (assign argl (const nil ))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH577");
}// (branch (label primitive_branch577))
compiled_branch578();
}
void compiled_branch578()
{// compiled_branch578
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL579"));// (assign continue (label after_call579))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch577()
{// primitive_branch577
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call579();
}
void after_call579()
{// after_call579
s.restore(ENV);// (restore env)
s.restore(CONTINUE);// (restore continue)
s.save(CONTINUE);// (save continue)
s.save(ENV);// (save env)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "display"), registers[ENV]));// (assign proc (op lookup_variable_value) (const display) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "string"), registers[ENV]));// (assign val (op lookup_variable_value) (const string) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH580");
}// (branch (label primitive_branch580))
compiled_branch581();
}
void compiled_branch581()
{// compiled_branch581
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL582"));// (assign continue (label after_call582))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch580()
{// primitive_branch580
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call582();
}
void after_call582()
{// after_call582
s.restore(ENV);// (restore env)
s.restore(CONTINUE);// (restore continue)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "newline"), registers[ENV]));// (assign proc (op lookup_variable_value) (const newline) (reg env))
assign(ARGL, new SchemeDataType(SchemeDataType::TypeId::Nil));// (assign argl (const nil ))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH583");
}// (branch (label primitive_branch583))
compiled_branch584();
}
void compiled_branch584()
{// compiled_branch584
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch583()
{// primitive_branch583
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call585();
}
void after_call585()
{// after_call585
after_lambda573();
}
void after_lambda573()
{// after_lambda573
define_variable(new SchemeDataType(SchemeDataType::TypeId::Symbol, "prompt_for_input"), registers[VAL], registers[ENV]);// (perform (op define_variable) (const prompt_for_input) (reg val) (reg env))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "ok"));// (assign val (const ok))
assign(VAL, make_compiled_procedure("ENTRY586", entry586, registers[ENV]));// (assign val (op make_compiled_procedure) (label entry586) (reg env))
goto_with_label("AFTER_LAMBDA587");// (goto (label after_lambda587))

}
void entry586()
{// entry586
assign(ENV, compiled_procedure_env(PROC));// (assign env (op compiled_procedure_env) (reg proc))
assign(ENV, extend_environment(new SchemeDataType(SchemeDataType::TypeId::Symbol, "string"), registers[ARGL], registers[ENV]));// (assign env (op extend_environment) (const string) (reg argl) (reg env))
s.save(CONTINUE);// (save continue)
s.save(ENV);// (save env)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "newline"), registers[ENV]));// (assign proc (op lookup_variable_value) (const newline) (reg env))
assign(ARGL, new SchemeDataType(SchemeDataType::TypeId::Nil));// (assign argl (const nil ))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH588");
}// (branch (label primitive_branch588))
compiled_branch589();
}
void compiled_branch589()
{// compiled_branch589
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL590"));// (assign continue (label after_call590))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch588()
{// primitive_branch588
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call590();
}
void after_call590()
{// after_call590
s.restore(ENV);// (restore env)
s.restore(CONTINUE);// (restore continue)
s.save(CONTINUE);// (save continue)
s.save(ENV);// (save env)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "display"), registers[ENV]));// (assign proc (op lookup_variable_value) (const display) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "string"), registers[ENV]));// (assign val (op lookup_variable_value) (const string) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH591");
}// (branch (label primitive_branch591))
compiled_branch592();
}
void compiled_branch592()
{// compiled_branch592
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL593"));// (assign continue (label after_call593))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch591()
{// primitive_branch591
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call593();
}
void after_call593()
{// after_call593
s.restore(ENV);// (restore env)
s.restore(CONTINUE);// (restore continue)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "newline"), registers[ENV]));// (assign proc (op lookup_variable_value) (const newline) (reg env))
assign(ARGL, new SchemeDataType(SchemeDataType::TypeId::Nil));// (assign argl (const nil ))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH594");
}// (branch (label primitive_branch594))
compiled_branch595();
}
void compiled_branch595()
{// compiled_branch595
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch594()
{// primitive_branch594
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call596();
}
void after_call596()
{// after_call596
after_lambda587();
}
void after_lambda587()
{// after_lambda587
define_variable(new SchemeDataType(SchemeDataType::TypeId::Symbol, "announce_output"), registers[VAL], registers[ENV]);// (perform (op define_variable) (const announce_output) (reg val) (reg env))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "ok"));// (assign val (const ok))
assign(VAL, make_compiled_procedure("ENTRY597", entry597, registers[ENV]));// (assign val (op make_compiled_procedure) (label entry597) (reg env))
goto_with_label("AFTER_LAMBDA598");// (goto (label after_lambda598))

}
void entry597()
{// entry597
assign(ENV, compiled_procedure_env(PROC));// (assign env (op compiled_procedure_env) (reg proc))
assign(ENV, extend_environment(new SchemeDataType(SchemeDataType::TypeId::Symbol, "object"), registers[ARGL], registers[ENV]));// (assign env (op extend_environment) (const object) (reg argl) (reg env))
s.save(CONTINUE);// (save continue)
s.save(ENV);// (save env)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "compound_procedure_p"), registers[ENV]));// (assign proc (op lookup_variable_value) (const compound_procedure_p) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "object"), registers[ENV]));// (assign val (op lookup_variable_value) (const object) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH602");
}// (branch (label primitive_branch602))
compiled_branch603();
}
void compiled_branch603()
{// compiled_branch603
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL604"));// (assign continue (label after_call604))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch602()
{// primitive_branch602
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call604();
}
void after_call604()
{// after_call604
s.restore(ENV);// (restore env)
s.restore(CONTINUE);// (restore continue)
if ( false_p(registers[VAL]) ) {// (test (op false_p) (reg val))
return goto_with_label("FALSE_BRANCH600");
}// (branch (label false_branch600))
true_branch599();
}
void true_branch599()
{// true_branch599
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "display"), registers[ENV]));// (assign proc (op lookup_variable_value) (const display) (reg env))
s.save(CONTINUE);// (save continue)
s.save(PROC);// (save proc)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "list"), registers[ENV]));// (assign proc (op lookup_variable_value) (const list) (reg env))
s.save(PROC);// (save proc)
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "<procedure_env>"));// (assign val (const <procedure_env>))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
s.save(ENV);// (save env)
s.save(ARGL);// (save argl)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "procedure_body"), registers[ENV]));// (assign proc (op lookup_variable_value) (const procedure_body) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "object"), registers[ENV]));// (assign val (op lookup_variable_value) (const object) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH608");
}// (branch (label primitive_branch608))
compiled_branch609();
}
void compiled_branch609()
{// compiled_branch609
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL610"));// (assign continue (label after_call610))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch608()
{// primitive_branch608
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call610();
}
void after_call610()
{// after_call610
s.restore(ARGL);// (restore argl)
assign(ARGL, cons(registers[VAL], registers[ARGL]));// (assign argl (op cons) (reg val) (reg argl))
s.restore(ENV);// (restore env)
s.save(ARGL);// (save argl)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "procedure_parameters"), registers[ENV]));// (assign proc (op lookup_variable_value) (const procedure_parameters) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "object"), registers[ENV]));// (assign val (op lookup_variable_value) (const object) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH605");
}// (branch (label primitive_branch605))
compiled_branch606();
}
void compiled_branch606()
{// compiled_branch606
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL607"));// (assign continue (label after_call607))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch605()
{// primitive_branch605
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call607();
}
void after_call607()
{// after_call607
s.restore(ARGL);// (restore argl)
assign(ARGL, cons(registers[VAL], registers[ARGL]));// (assign argl (op cons) (reg val) (reg argl))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "compound_procedure"));// (assign val (const compound_procedure))
assign(ARGL, cons(registers[VAL], registers[ARGL]));// (assign argl (op cons) (reg val) (reg argl))
s.restore(PROC);// (restore proc)
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH611");
}// (branch (label primitive_branch611))
compiled_branch612();
}
void compiled_branch612()
{// compiled_branch612
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL613"));// (assign continue (label after_call613))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch611()
{// primitive_branch611
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call613();
}
void after_call613()
{// after_call613
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
s.restore(PROC);// (restore proc)
s.restore(CONTINUE);// (restore continue)
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH614");
}// (branch (label primitive_branch614))
compiled_branch615();
}
void compiled_branch615()
{// compiled_branch615
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch614()
{// primitive_branch614
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call616();
}
void after_call616()
{// after_call616

}
void false_branch600()
{// false_branch600
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "display"), registers[ENV]));// (assign proc (op lookup_variable_value) (const display) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "object"), registers[ENV]));// (assign val (op lookup_variable_value) (const object) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH617");
}// (branch (label primitive_branch617))
compiled_branch618();
}
void compiled_branch618()
{// compiled_branch618
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch617()
{// primitive_branch617
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call619();
}
void after_call619()
{// after_call619
after_if601();
}
void after_if601()
{// after_if601
after_lambda598();
}
void after_lambda598()
{// after_lambda598
define_variable(new SchemeDataType(SchemeDataType::TypeId::Symbol, "user_print"), registers[VAL], registers[ENV]);// (perform (op define_variable) (const user_print) (reg val) (reg env))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "ok"));// (assign val (const ok))
}
