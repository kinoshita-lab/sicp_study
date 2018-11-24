void compiled_procedure_start(){
assign(VAL, make_compiled_procedure("ENTRY42", entry42, registers[ENV]));// (assign val (op make_compiled_procedure) (label entry42) (reg env))
goto_with_label("AFTER_LAMBDA43");// (goto (label after_lambda43))

}
void entry42()
{// entry42
assign(ENV, compiled_procedure_env(PROC));// (assign env (op compiled_procedure_env) (reg proc))
assign(ENV, extend_environment(new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp"), registers[ARGL], registers[ENV]));
assign(ENV, extend_environment(new SchemeDataType(SchemeDataType::TypeId::Symbol, "env"), registers[ARGL], registers[ENV]));
// (assign env (op extend_environment) (const (exp env)) (reg argl) (reg env))
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
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "quoted_p"), registers[ENV]));// (assign proc (op lookup_variable_value) (const quoted_p) (reg env))
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
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "text_of_quotation"), registers[ENV]));// (assign proc (op lookup_variable_value) (const text_of_quotation) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp"), registers[ENV]));// (assign val (op lookup_variable_value) (const exp) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH65");
}// (branch (label primitive_branch65))
compiled_branch66();
}
void compiled_branch66()
{// compiled_branch66
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch65()
{// primitive_branch65
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call67();
}
void after_call67()
{// after_call67

}
void false_branch60()
{// false_branch60
s.save(CONTINUE);// (save continue)
s.save(ENV);// (save env)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "assignment_p"), registers[ENV]));// (assign proc (op lookup_variable_value) (const assignment_p) (reg env))
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
s.restore(ENV);// (restore env)
s.restore(CONTINUE);// (restore continue)
if ( false_p(registers[VAL]) ) {// (test (op false_p) (reg val))
return goto_with_label("FALSE_BRANCH69");
}// (branch (label false_branch69))
true_branch68();
}
void true_branch68()
{// true_branch68
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "eval_assignment"), registers[ENV]));// (assign proc (op lookup_variable_value) (const eval_assignment) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "env"), registers[ENV]));// (assign val (op lookup_variable_value) (const env) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp"), registers[ENV]));// (assign val (op lookup_variable_value) (const exp) (reg env))
assign(ARGL, cons(registers[VAL], registers[ARGL]));// (assign argl (op cons) (reg val) (reg argl))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH74");
}// (branch (label primitive_branch74))
compiled_branch75();
}
void compiled_branch75()
{// compiled_branch75
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch74()
{// primitive_branch74
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call76();
}
void after_call76()
{// after_call76

}
void false_branch69()
{// false_branch69
s.save(CONTINUE);// (save continue)
s.save(ENV);// (save env)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "definition_p"), registers[ENV]));// (assign proc (op lookup_variable_value) (const definition_p) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp"), registers[ENV]));// (assign val (op lookup_variable_value) (const exp) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH80");
}// (branch (label primitive_branch80))
compiled_branch81();
}
void compiled_branch81()
{// compiled_branch81
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL82"));// (assign continue (label after_call82))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch80()
{// primitive_branch80
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call82();
}
void after_call82()
{// after_call82
s.restore(ENV);// (restore env)
s.restore(CONTINUE);// (restore continue)
if ( false_p(registers[VAL]) ) {// (test (op false_p) (reg val))
return goto_with_label("FALSE_BRANCH78");
}// (branch (label false_branch78))
true_branch77();
}
void true_branch77()
{// true_branch77
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "eval_definition"), registers[ENV]));// (assign proc (op lookup_variable_value) (const eval_definition) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "env"), registers[ENV]));// (assign val (op lookup_variable_value) (const env) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp"), registers[ENV]));// (assign val (op lookup_variable_value) (const exp) (reg env))
assign(ARGL, cons(registers[VAL], registers[ARGL]));// (assign argl (op cons) (reg val) (reg argl))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH83");
}// (branch (label primitive_branch83))
compiled_branch84();
}
void compiled_branch84()
{// compiled_branch84
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch83()
{// primitive_branch83
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call85();
}
void after_call85()
{// after_call85

}
void false_branch78()
{// false_branch78
s.save(CONTINUE);// (save continue)
s.save(ENV);// (save env)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "if_p"), registers[ENV]));// (assign proc (op lookup_variable_value) (const if_p) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp"), registers[ENV]));// (assign val (op lookup_variable_value) (const exp) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH89");
}// (branch (label primitive_branch89))
compiled_branch90();
}
void compiled_branch90()
{// compiled_branch90
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL91"));// (assign continue (label after_call91))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch89()
{// primitive_branch89
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call91();
}
void after_call91()
{// after_call91
s.restore(ENV);// (restore env)
s.restore(CONTINUE);// (restore continue)
if ( false_p(registers[VAL]) ) {// (test (op false_p) (reg val))
return goto_with_label("FALSE_BRANCH87");
}// (branch (label false_branch87))
true_branch86();
}
void true_branch86()
{// true_branch86
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "eval_if"), registers[ENV]));// (assign proc (op lookup_variable_value) (const eval_if) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "env"), registers[ENV]));// (assign val (op lookup_variable_value) (const env) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp"), registers[ENV]));// (assign val (op lookup_variable_value) (const exp) (reg env))
assign(ARGL, cons(registers[VAL], registers[ARGL]));// (assign argl (op cons) (reg val) (reg argl))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH92");
}// (branch (label primitive_branch92))
compiled_branch93();
}
void compiled_branch93()
{// compiled_branch93
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch92()
{// primitive_branch92
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call94();
}
void after_call94()
{// after_call94

}
void false_branch87()
{// false_branch87
s.save(CONTINUE);// (save continue)
s.save(ENV);// (save env)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "lambda_p"), registers[ENV]));// (assign proc (op lookup_variable_value) (const lambda_p) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp"), registers[ENV]));// (assign val (op lookup_variable_value) (const exp) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH98");
}// (branch (label primitive_branch98))
compiled_branch99();
}
void compiled_branch99()
{// compiled_branch99
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL100"));// (assign continue (label after_call100))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch98()
{// primitive_branch98
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call100();
}
void after_call100()
{// after_call100
s.restore(ENV);// (restore env)
s.restore(CONTINUE);// (restore continue)
if ( false_p(registers[VAL]) ) {// (test (op false_p) (reg val))
return goto_with_label("FALSE_BRANCH96");
}// (branch (label false_branch96))
true_branch95();
}
void true_branch95()
{// true_branch95
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "make_procedure"), registers[ENV]));// (assign proc (op lookup_variable_value) (const make_procedure) (reg env))
s.save(CONTINUE);// (save continue)
s.save(PROC);// (save proc)
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "env"), registers[ENV]));// (assign val (op lookup_variable_value) (const env) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
s.save(ENV);// (save env)
s.save(ARGL);// (save argl)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "lambda_body"), registers[ENV]));// (assign proc (op lookup_variable_value) (const lambda_body) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp"), registers[ENV]));// (assign val (op lookup_variable_value) (const exp) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH104");
}// (branch (label primitive_branch104))
compiled_branch105();
}
void compiled_branch105()
{// compiled_branch105
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL106"));// (assign continue (label after_call106))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch104()
{// primitive_branch104
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call106();
}
void after_call106()
{// after_call106
s.restore(ARGL);// (restore argl)
assign(ARGL, cons(registers[VAL], registers[ARGL]));// (assign argl (op cons) (reg val) (reg argl))
s.restore(ENV);// (restore env)
s.save(ARGL);// (save argl)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "lambda_parameters"), registers[ENV]));// (assign proc (op lookup_variable_value) (const lambda_parameters) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp"), registers[ENV]));// (assign val (op lookup_variable_value) (const exp) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH101");
}// (branch (label primitive_branch101))
compiled_branch102();
}
void compiled_branch102()
{// compiled_branch102
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL103"));// (assign continue (label after_call103))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch101()
{// primitive_branch101
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call103();
}
void after_call103()
{// after_call103
s.restore(ARGL);// (restore argl)
assign(ARGL, cons(registers[VAL], registers[ARGL]));// (assign argl (op cons) (reg val) (reg argl))
s.restore(PROC);// (restore proc)
s.restore(CONTINUE);// (restore continue)
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH107");
}// (branch (label primitive_branch107))
compiled_branch108();
}
void compiled_branch108()
{// compiled_branch108
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch107()
{// primitive_branch107
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call109();
}
void after_call109()
{// after_call109

}
void false_branch96()
{// false_branch96
s.save(CONTINUE);// (save continue)
s.save(ENV);// (save env)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "begin_p"), registers[ENV]));// (assign proc (op lookup_variable_value) (const begin_p) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp"), registers[ENV]));// (assign val (op lookup_variable_value) (const exp) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH113");
}// (branch (label primitive_branch113))
compiled_branch114();
}
void compiled_branch114()
{// compiled_branch114
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL115"));// (assign continue (label after_call115))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch113()
{// primitive_branch113
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call115();
}
void after_call115()
{// after_call115
s.restore(ENV);// (restore env)
s.restore(CONTINUE);// (restore continue)
if ( false_p(registers[VAL]) ) {// (test (op false_p) (reg val))
return goto_with_label("FALSE_BRANCH111");
}// (branch (label false_branch111))
true_branch110();
}
void true_branch110()
{// true_branch110
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "eval_sequence"), registers[ENV]));// (assign proc (op lookup_variable_value) (const eval_sequence) (reg env))
s.save(CONTINUE);// (save continue)
s.save(PROC);// (save proc)
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "env"), registers[ENV]));// (assign val (op lookup_variable_value) (const env) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
s.save(ARGL);// (save argl)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "begin_actions"), registers[ENV]));// (assign proc (op lookup_variable_value) (const begin_actions) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp"), registers[ENV]));// (assign val (op lookup_variable_value) (const exp) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH116");
}// (branch (label primitive_branch116))
compiled_branch117();
}
void compiled_branch117()
{// compiled_branch117
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL118"));// (assign continue (label after_call118))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch116()
{// primitive_branch116
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call118();
}
void after_call118()
{// after_call118
s.restore(ARGL);// (restore argl)
assign(ARGL, cons(registers[VAL], registers[ARGL]));// (assign argl (op cons) (reg val) (reg argl))
s.restore(PROC);// (restore proc)
s.restore(CONTINUE);// (restore continue)
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH119");
}// (branch (label primitive_branch119))
compiled_branch120();
}
void compiled_branch120()
{// compiled_branch120
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch119()
{// primitive_branch119
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call121();
}
void after_call121()
{// after_call121

}
void false_branch111()
{// false_branch111
s.save(CONTINUE);// (save continue)
s.save(ENV);// (save env)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "cond_p"), registers[ENV]));// (assign proc (op lookup_variable_value) (const cond_p) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp"), registers[ENV]));// (assign val (op lookup_variable_value) (const exp) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH125");
}// (branch (label primitive_branch125))
compiled_branch126();
}
void compiled_branch126()
{// compiled_branch126
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL127"));// (assign continue (label after_call127))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch125()
{// primitive_branch125
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call127();
}
void after_call127()
{// after_call127
s.restore(ENV);// (restore env)
s.restore(CONTINUE);// (restore continue)
if ( false_p(registers[VAL]) ) {// (test (op false_p) (reg val))
return goto_with_label("FALSE_BRANCH123");
}// (branch (label false_branch123))
true_branch122();
}
void true_branch122()
{// true_branch122
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "eval"), registers[ENV]));// (assign proc (op lookup_variable_value) (const eval) (reg env))
s.save(CONTINUE);// (save continue)
s.save(PROC);// (save proc)
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "env"), registers[ENV]));// (assign val (op lookup_variable_value) (const env) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
s.save(ARGL);// (save argl)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "cond_>if"), registers[ENV]));// (assign proc (op lookup_variable_value) (const cond_>if) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp"), registers[ENV]));// (assign val (op lookup_variable_value) (const exp) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH128");
}// (branch (label primitive_branch128))
compiled_branch129();
}
void compiled_branch129()
{// compiled_branch129
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL130"));// (assign continue (label after_call130))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch128()
{// primitive_branch128
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call130();
}
void after_call130()
{// after_call130
s.restore(ARGL);// (restore argl)
assign(ARGL, cons(registers[VAL], registers[ARGL]));// (assign argl (op cons) (reg val) (reg argl))
s.restore(PROC);// (restore proc)
s.restore(CONTINUE);// (restore continue)
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH131");
}// (branch (label primitive_branch131))
compiled_branch132();
}
void compiled_branch132()
{// compiled_branch132
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch131()
{// primitive_branch131
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call133();
}
void after_call133()
{// after_call133

}
void false_branch123()
{// false_branch123
s.save(CONTINUE);// (save continue)
s.save(ENV);// (save env)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "application_p"), registers[ENV]));// (assign proc (op lookup_variable_value) (const application_p) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp"), registers[ENV]));// (assign val (op lookup_variable_value) (const exp) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH137");
}// (branch (label primitive_branch137))
compiled_branch138();
}
void compiled_branch138()
{// compiled_branch138
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL139"));// (assign continue (label after_call139))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch137()
{// primitive_branch137
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call139();
}
void after_call139()
{// after_call139
s.restore(ENV);// (restore env)
s.restore(CONTINUE);// (restore continue)
if ( false_p(registers[VAL]) ) {// (test (op false_p) (reg val))
return goto_with_label("FALSE_BRANCH135");
}// (branch (label false_branch135))
true_branch134();
}
void true_branch134()
{// true_branch134
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
return goto_with_label("PRIMITIVE_BRANCH146");
}// (branch (label primitive_branch146))
compiled_branch147();
}
void compiled_branch147()
{// compiled_branch147
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL148"));// (assign continue (label after_call148))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch146()
{// primitive_branch146
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call148();
}
void after_call148()
{// after_call148
s.restore(ARGL);// (restore argl)
assign(ARGL, cons(registers[VAL], registers[ARGL]));// (assign argl (op cons) (reg val) (reg argl))
s.restore(PROC);// (restore proc)
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
return goto_with_label("PRIMITIVE_BRANCH140");
}// (branch (label primitive_branch140))
compiled_branch141();
}
void compiled_branch141()
{// compiled_branch141
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL142"));// (assign continue (label after_call142))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch140()
{// primitive_branch140
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call142();
}
void after_call142()
{// after_call142
s.restore(ARGL);// (restore argl)
assign(ARGL, cons(registers[VAL], registers[ARGL]));// (assign argl (op cons) (reg val) (reg argl))
s.restore(PROC);// (restore proc)
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH143");
}// (branch (label primitive_branch143))
compiled_branch144();
}
void compiled_branch144()
{// compiled_branch144
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL145"));// (assign continue (label after_call145))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch143()
{// primitive_branch143
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call145();
}
void after_call145()
{// after_call145
s.restore(ARGL);// (restore argl)
assign(ARGL, cons(registers[VAL], registers[ARGL]));// (assign argl (op cons) (reg val) (reg argl))
s.restore(PROC);// (restore proc)
s.restore(CONTINUE);// (restore continue)
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH152");
}// (branch (label primitive_branch152))
compiled_branch153();
}
void compiled_branch153()
{// compiled_branch153
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch152()
{// primitive_branch152
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call154();
}
void after_call154()
{// after_call154

}
void false_branch135()
{// false_branch135
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "error"), registers[ENV]));// (assign proc (op lookup_variable_value) (const error) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp"), registers[ENV]));// (assign val (op lookup_variable_value) (const exp) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "Unknown expression type __ EVAL"));// (assign val (const Unknown expression type __ EVAL))
assign(ARGL, cons(registers[VAL], registers[ARGL]));// (assign argl (op cons) (reg val) (reg argl))
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
after_if136();
}
void after_if136()
{// after_if136
after_if124();
}
void after_if124()
{// after_if124
after_if112();
}
void after_if112()
{// after_if112
after_if97();
}
void after_if97()
{// after_if97
after_if88();
}
void after_if88()
{// after_if88
after_if79();
}
void after_if79()
{// after_if79
after_if70();
}
void after_if70()
{// after_if70
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
assign(VAL, make_compiled_procedure("ENTRY158", entry158, registers[ENV]));// (assign val (op make_compiled_procedure) (label entry158) (reg env))
goto_with_label("AFTER_LAMBDA159");// (goto (label after_lambda159))

}
void entry158()
{// entry158
assign(ENV, compiled_procedure_env(PROC));// (assign env (op compiled_procedure_env) (reg proc))
assign(ENV, extend_environment(new SchemeDataType(SchemeDataType::TypeId::Symbol, "procedure"), registers[ARGL], registers[ENV]));
assign(ENV, extend_environment(new SchemeDataType(SchemeDataType::TypeId::Symbol, "arguments"), registers[ARGL], registers[ENV]));
// (assign env (op extend_environment) (const (procedure arguments)) (reg argl) (reg env))
s.save(CONTINUE);// (save continue)
s.save(ENV);// (save env)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "primitive_procedure_p"), registers[ENV]));// (assign proc (op lookup_variable_value) (const primitive_procedure_p) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "procedure"), registers[ENV]));// (assign val (op lookup_variable_value) (const procedure) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH163");
}// (branch (label primitive_branch163))
compiled_branch164();
}
void compiled_branch164()
{// compiled_branch164
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL165"));// (assign continue (label after_call165))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch163()
{// primitive_branch163
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call165();
}
void after_call165()
{// after_call165
s.restore(ENV);// (restore env)
s.restore(CONTINUE);// (restore continue)
if ( false_p(registers[VAL]) ) {// (test (op false_p) (reg val))
return goto_with_label("FALSE_BRANCH161");
}// (branch (label false_branch161))
true_branch160();
}
void true_branch160()
{// true_branch160
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "apply_primitive_procedure"), registers[ENV]));// (assign proc (op lookup_variable_value) (const apply_primitive_procedure) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "arguments"), registers[ENV]));// (assign val (op lookup_variable_value) (const arguments) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "procedure"), registers[ENV]));// (assign val (op lookup_variable_value) (const procedure) (reg env))
assign(ARGL, cons(registers[VAL], registers[ARGL]));// (assign argl (op cons) (reg val) (reg argl))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH166");
}// (branch (label primitive_branch166))
compiled_branch167();
}
void compiled_branch167()
{// compiled_branch167
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch166()
{// primitive_branch166
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call168();
}
void after_call168()
{// after_call168

}
void false_branch161()
{// false_branch161
s.save(CONTINUE);// (save continue)
s.save(ENV);// (save env)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "compound_procedure_p"), registers[ENV]));// (assign proc (op lookup_variable_value) (const compound_procedure_p) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "procedure"), registers[ENV]));// (assign val (op lookup_variable_value) (const procedure) (reg env))
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
s.restore(ENV);// (restore env)
s.restore(CONTINUE);// (restore continue)
if ( false_p(registers[VAL]) ) {// (test (op false_p) (reg val))
return goto_with_label("FALSE_BRANCH170");
}// (branch (label false_branch170))
true_branch169();
}
void true_branch169()
{// true_branch169
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
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
s.restore(ENV);// (restore env)
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "arguments"), registers[ENV]));// (assign val (op lookup_variable_value) (const arguments) (reg env))
assign(ARGL, cons(registers[VAL], registers[ARGL]));// (assign argl (op cons) (reg val) (reg argl))
s.save(ARGL);// (save argl)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "procedure_parameters"), registers[ENV]));// (assign proc (op lookup_variable_value) (const procedure_parameters) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "procedure"), registers[ENV]));// (assign val (op lookup_variable_value) (const procedure) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
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
s.restore(PROC);// (restore proc)
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH184");
}// (branch (label primitive_branch184))
compiled_branch185();
}
void compiled_branch185()
{// compiled_branch185
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL186"));// (assign continue (label after_call186))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch184()
{// primitive_branch184
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call186();
}
void after_call186()
{// after_call186
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
s.restore(ENV);// (restore env)
s.save(ARGL);// (save argl)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "procedure_body"), registers[ENV]));// (assign proc (op lookup_variable_value) (const procedure_body) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "procedure"), registers[ENV]));// (assign val (op lookup_variable_value) (const procedure) (reg env))
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
s.restore(CONTINUE);// (restore continue)
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH187");
}// (branch (label primitive_branch187))
compiled_branch188();
}
void compiled_branch188()
{// compiled_branch188
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch187()
{// primitive_branch187
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call189();
}
void after_call189()
{// after_call189

}
void false_branch170()
{// false_branch170
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "error"), registers[ENV]));// (assign proc (op lookup_variable_value) (const error) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "procedure"), registers[ENV]));// (assign val (op lookup_variable_value) (const procedure) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "Unknown procedure type __ APPLY"));// (assign val (const Unknown procedure type __ APPLY))
assign(ARGL, cons(registers[VAL], registers[ARGL]));// (assign argl (op cons) (reg val) (reg argl))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH190");
}// (branch (label primitive_branch190))
compiled_branch191();
}
void compiled_branch191()
{// compiled_branch191
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch190()
{// primitive_branch190
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call192();
}
void after_call192()
{// after_call192
after_if171();
}
void after_if171()
{// after_if171
after_if162();
}
void after_if162()
{// after_if162
after_lambda159();
}
void after_lambda159()
{// after_lambda159
define_variable(new SchemeDataType(SchemeDataType::TypeId::Symbol, "apply"), registers[VAL], registers[ENV]);// (perform (op define_variable) (const apply) (reg val) (reg env))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "ok"));// (assign val (const ok))
assign(VAL, make_compiled_procedure("ENTRY193", entry193, registers[ENV]));// (assign val (op make_compiled_procedure) (label entry193) (reg env))
goto_with_label("AFTER_LAMBDA194");// (goto (label after_lambda194))

}
void entry193()
{// entry193
assign(ENV, compiled_procedure_env(PROC));// (assign env (op compiled_procedure_env) (reg proc))
assign(ENV, extend_environment(new SchemeDataType(SchemeDataType::TypeId::Symbol, "exps"), registers[ARGL], registers[ENV]));
assign(ENV, extend_environment(new SchemeDataType(SchemeDataType::TypeId::Symbol, "env"), registers[ARGL], registers[ENV]));
// (assign env (op extend_environment) (const (exps env)) (reg argl) (reg env))
s.save(CONTINUE);// (save continue)
s.save(ENV);// (save env)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "no_operands_p"), registers[ENV]));// (assign proc (op lookup_variable_value) (const no_operands_p) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "exps"), registers[ENV]));// (assign val (op lookup_variable_value) (const exps) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH198");
}// (branch (label primitive_branch198))
compiled_branch199();
}
void compiled_branch199()
{// compiled_branch199
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL200"));// (assign continue (label after_call200))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch198()
{// primitive_branch198
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call200();
}
void after_call200()
{// after_call200
s.restore(ENV);// (restore env)
s.restore(CONTINUE);// (restore continue)
if ( false_p(registers[VAL]) ) {// (test (op false_p) (reg val))
return goto_with_label("FALSE_BRANCH196");
}// (branch (label false_branch196))
true_branch195();
}
void true_branch195()
{// true_branch195
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::Nil));// (assign val (const nil ))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))

}
void false_branch196()
{// false_branch196
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "cons"), registers[ENV]));// (assign proc (op lookup_variable_value) (const cons) (reg env))
s.save(CONTINUE);// (save continue)
s.save(PROC);// (save proc)
s.save(ENV);// (save env)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "list_of_values"), registers[ENV]));// (assign proc (op lookup_variable_value) (const list_of_values) (reg env))
s.save(PROC);// (save proc)
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "env"), registers[ENV]));// (assign val (op lookup_variable_value) (const env) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
s.save(ARGL);// (save argl)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "rest_operands"), registers[ENV]));// (assign proc (op lookup_variable_value) (const rest_operands) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "exps"), registers[ENV]));// (assign val (op lookup_variable_value) (const exps) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH207");
}// (branch (label primitive_branch207))
compiled_branch208();
}
void compiled_branch208()
{// compiled_branch208
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL209"));// (assign continue (label after_call209))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch207()
{// primitive_branch207
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call209();
}
void after_call209()
{// after_call209
s.restore(ARGL);// (restore argl)
assign(ARGL, cons(registers[VAL], registers[ARGL]));// (assign argl (op cons) (reg val) (reg argl))
s.restore(PROC);// (restore proc)
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH210");
}// (branch (label primitive_branch210))
compiled_branch211();
}
void compiled_branch211()
{// compiled_branch211
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL212"));// (assign continue (label after_call212))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch210()
{// primitive_branch210
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call212();
}
void after_call212()
{// after_call212
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
s.restore(ENV);// (restore env)
s.save(ARGL);// (save argl)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "eval"), registers[ENV]));// (assign proc (op lookup_variable_value) (const eval) (reg env))
s.save(PROC);// (save proc)
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "env"), registers[ENV]));// (assign val (op lookup_variable_value) (const env) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
s.save(ARGL);// (save argl)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "first_operand"), registers[ENV]));// (assign proc (op lookup_variable_value) (const first_operand) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "exps"), registers[ENV]));// (assign val (op lookup_variable_value) (const exps) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH201");
}// (branch (label primitive_branch201))
compiled_branch202();
}
void compiled_branch202()
{// compiled_branch202
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL203"));// (assign continue (label after_call203))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch201()
{// primitive_branch201
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call203();
}
void after_call203()
{// after_call203
s.restore(ARGL);// (restore argl)
assign(ARGL, cons(registers[VAL], registers[ARGL]));// (assign argl (op cons) (reg val) (reg argl))
s.restore(PROC);// (restore proc)
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH204");
}// (branch (label primitive_branch204))
compiled_branch205();
}
void compiled_branch205()
{// compiled_branch205
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL206"));// (assign continue (label after_call206))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch204()
{// primitive_branch204
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call206();
}
void after_call206()
{// after_call206
s.restore(ARGL);// (restore argl)
assign(ARGL, cons(registers[VAL], registers[ARGL]));// (assign argl (op cons) (reg val) (reg argl))
s.restore(PROC);// (restore proc)
s.restore(CONTINUE);// (restore continue)
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH213");
}// (branch (label primitive_branch213))
compiled_branch214();
}
void compiled_branch214()
{// compiled_branch214
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch213()
{// primitive_branch213
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call215();
}
void after_call215()
{// after_call215
after_if197();
}
void after_if197()
{// after_if197
after_lambda194();
}
void after_lambda194()
{// after_lambda194
define_variable(new SchemeDataType(SchemeDataType::TypeId::Symbol, "list_of_values"), registers[VAL], registers[ENV]);// (perform (op define_variable) (const list_of_values) (reg val) (reg env))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "ok"));// (assign val (const ok))
assign(VAL, make_compiled_procedure("ENTRY216", entry216, registers[ENV]));// (assign val (op make_compiled_procedure) (label entry216) (reg env))
goto_with_label("AFTER_LAMBDA217");// (goto (label after_lambda217))

}
void entry216()
{// entry216
assign(ENV, compiled_procedure_env(PROC));// (assign env (op compiled_procedure_env) (reg proc))
assign(ENV, extend_environment(new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp"), registers[ARGL], registers[ENV]));
assign(ENV, extend_environment(new SchemeDataType(SchemeDataType::TypeId::Symbol, "env"), registers[ARGL], registers[ENV]));
// (assign env (op extend_environment) (const (exp env)) (reg argl) (reg env))
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
return goto_with_label("PRIMITIVE_BRANCH221");
}// (branch (label primitive_branch221))
compiled_branch222();
}
void compiled_branch222()
{// compiled_branch222
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL223"));// (assign continue (label after_call223))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch221()
{// primitive_branch221
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call223();
}
void after_call223()
{// after_call223
s.restore(ARGL);// (restore argl)
assign(ARGL, cons(registers[VAL], registers[ARGL]));// (assign argl (op cons) (reg val) (reg argl))
s.restore(PROC);// (restore proc)
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH224");
}// (branch (label primitive_branch224))
compiled_branch225();
}
void compiled_branch225()
{// compiled_branch225
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL226"));// (assign continue (label after_call226))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch224()
{// primitive_branch224
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call226();
}
void after_call226()
{// after_call226
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
s.restore(PROC);// (restore proc)
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
return goto_with_label("FALSE_BRANCH219");
}// (branch (label false_branch219))
true_branch218();
}
void true_branch218()
{// true_branch218
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
void false_branch219()
{// false_branch219
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
return goto_with_label("PRIMITIVE_BRANCH236");
}// (branch (label primitive_branch236))
compiled_branch237();
}
void compiled_branch237()
{// compiled_branch237
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL238"));// (assign continue (label after_call238))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch236()
{// primitive_branch236
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call238();
}
void after_call238()
{// after_call238
s.restore(ARGL);// (restore argl)
assign(ARGL, cons(registers[VAL], registers[ARGL]));// (assign argl (op cons) (reg val) (reg argl))
s.restore(PROC);// (restore proc)
s.restore(CONTINUE);// (restore continue)
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH239");
}// (branch (label primitive_branch239))
compiled_branch240();
}
void compiled_branch240()
{// compiled_branch240
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch239()
{// primitive_branch239
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call241();
}
void after_call241()
{// after_call241
after_if220();
}
void after_if220()
{// after_if220
after_lambda217();
}
void after_lambda217()
{// after_lambda217
define_variable(new SchemeDataType(SchemeDataType::TypeId::Symbol, "eval_if"), registers[VAL], registers[ENV]);// (perform (op define_variable) (const eval_if) (reg val) (reg env))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "ok"));// (assign val (const ok))
assign(VAL, make_compiled_procedure("ENTRY242", entry242, registers[ENV]));// (assign val (op make_compiled_procedure) (label entry242) (reg env))
goto_with_label("AFTER_LAMBDA243");// (goto (label after_lambda243))

}
void entry242()
{// entry242
assign(ENV, compiled_procedure_env(PROC));// (assign env (op compiled_procedure_env) (reg proc))
assign(ENV, extend_environment(new SchemeDataType(SchemeDataType::TypeId::Symbol, "exps"), registers[ARGL], registers[ENV]));
assign(ENV, extend_environment(new SchemeDataType(SchemeDataType::TypeId::Symbol, "env"), registers[ARGL], registers[ENV]));
// (assign env (op extend_environment) (const (exps env)) (reg argl) (reg env))
s.save(CONTINUE);// (save continue)
s.save(ENV);// (save env)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "last_exp_p"), registers[ENV]));// (assign proc (op lookup_variable_value) (const last_exp_p) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "exps"), registers[ENV]));// (assign val (op lookup_variable_value) (const exps) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH247");
}// (branch (label primitive_branch247))
compiled_branch248();
}
void compiled_branch248()
{// compiled_branch248
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL249"));// (assign continue (label after_call249))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch247()
{// primitive_branch247
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call249();
}
void after_call249()
{// after_call249
s.restore(ENV);// (restore env)
s.restore(CONTINUE);// (restore continue)
if ( false_p(registers[VAL]) ) {// (test (op false_p) (reg val))
return goto_with_label("FALSE_BRANCH245");
}// (branch (label false_branch245))
true_branch244();
}
void true_branch244()
{// true_branch244
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
return goto_with_label("PRIMITIVE_BRANCH250");
}// (branch (label primitive_branch250))
compiled_branch251();
}
void compiled_branch251()
{// compiled_branch251
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL252"));// (assign continue (label after_call252))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch250()
{// primitive_branch250
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call252();
}
void after_call252()
{// after_call252
s.restore(ARGL);// (restore argl)
assign(ARGL, cons(registers[VAL], registers[ARGL]));// (assign argl (op cons) (reg val) (reg argl))
s.restore(PROC);// (restore proc)
s.restore(CONTINUE);// (restore continue)
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

}
void false_branch245()
{// false_branch245
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
return goto_with_label("PRIMITIVE_BRANCH256");
}// (branch (label primitive_branch256))
compiled_branch257();
}
void compiled_branch257()
{// compiled_branch257
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL258"));// (assign continue (label after_call258))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch256()
{// primitive_branch256
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call258();
}
void after_call258()
{// after_call258
s.restore(ARGL);// (restore argl)
assign(ARGL, cons(registers[VAL], registers[ARGL]));// (assign argl (op cons) (reg val) (reg argl))
s.restore(PROC);// (restore proc)
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH259");
}// (branch (label primitive_branch259))
compiled_branch260();
}
void compiled_branch260()
{// compiled_branch260
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL261"));// (assign continue (label after_call261))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch259()
{// primitive_branch259
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call261();
}
void after_call261()
{// after_call261
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
return goto_with_label("PRIMITIVE_BRANCH262");
}// (branch (label primitive_branch262))
compiled_branch263();
}
void compiled_branch263()
{// compiled_branch263
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL264"));// (assign continue (label after_call264))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch262()
{// primitive_branch262
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call264();
}
void after_call264()
{// after_call264
s.restore(ARGL);// (restore argl)
assign(ARGL, cons(registers[VAL], registers[ARGL]));// (assign argl (op cons) (reg val) (reg argl))
s.restore(PROC);// (restore proc)
s.restore(CONTINUE);// (restore continue)
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH265");
}// (branch (label primitive_branch265))
compiled_branch266();
}
void compiled_branch266()
{// compiled_branch266
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch265()
{// primitive_branch265
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call267();
}
void after_call267()
{// after_call267
after_if246();
}
void after_if246()
{// after_if246
after_lambda243();
}
void after_lambda243()
{// after_lambda243
define_variable(new SchemeDataType(SchemeDataType::TypeId::Symbol, "eval_sequence"), registers[VAL], registers[ENV]);// (perform (op define_variable) (const eval_sequence) (reg val) (reg env))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "ok"));// (assign val (const ok))
assign(VAL, make_compiled_procedure("ENTRY268", entry268, registers[ENV]));// (assign val (op make_compiled_procedure) (label entry268) (reg env))
goto_with_label("AFTER_LAMBDA269");// (goto (label after_lambda269))

}
void entry268()
{// entry268
assign(ENV, compiled_procedure_env(PROC));// (assign env (op compiled_procedure_env) (reg proc))
assign(ENV, extend_environment(new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp"), registers[ARGL], registers[ENV]));
assign(ENV, extend_environment(new SchemeDataType(SchemeDataType::TypeId::Symbol, "env"), registers[ARGL], registers[ENV]));
// (assign env (op extend_environment) (const (exp env)) (reg argl) (reg env))
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
return goto_with_label("PRIMITIVE_BRANCH273");
}// (branch (label primitive_branch273))
compiled_branch274();
}
void compiled_branch274()
{// compiled_branch274
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL275"));// (assign continue (label after_call275))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch273()
{// primitive_branch273
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call275();
}
void after_call275()
{// after_call275
s.restore(ARGL);// (restore argl)
assign(ARGL, cons(registers[VAL], registers[ARGL]));// (assign argl (op cons) (reg val) (reg argl))
s.restore(PROC);// (restore proc)
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH276");
}// (branch (label primitive_branch276))
compiled_branch277();
}
void compiled_branch277()
{// compiled_branch277
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL278"));// (assign continue (label after_call278))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch276()
{// primitive_branch276
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call278();
}
void after_call278()
{// after_call278
s.restore(ARGL);// (restore argl)
assign(ARGL, cons(registers[VAL], registers[ARGL]));// (assign argl (op cons) (reg val) (reg argl))
s.restore(ENV);// (restore env)
s.save(ARGL);// (save argl)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "assignment_variable"), registers[ENV]));// (assign proc (op lookup_variable_value) (const assignment_variable) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp"), registers[ENV]));// (assign val (op lookup_variable_value) (const exp) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH270");
}// (branch (label primitive_branch270))
compiled_branch271();
}
void compiled_branch271()
{// compiled_branch271
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL272"));// (assign continue (label after_call272))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch270()
{// primitive_branch270
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call272();
}
void after_call272()
{// after_call272
s.restore(ARGL);// (restore argl)
assign(ARGL, cons(registers[VAL], registers[ARGL]));// (assign argl (op cons) (reg val) (reg argl))
s.restore(PROC);// (restore proc)
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH279");
}// (branch (label primitive_branch279))
compiled_branch280();
}
void compiled_branch280()
{// compiled_branch280
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL281"));// (assign continue (label after_call281))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch279()
{// primitive_branch279
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call281();
}
void after_call281()
{// after_call281
s.restore(CONTINUE);// (restore continue)
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "ok"));// (assign val (const ok))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_lambda269();
}
void after_lambda269()
{// after_lambda269
define_variable(new SchemeDataType(SchemeDataType::TypeId::Symbol, "eval_assignment"), registers[VAL], registers[ENV]);// (perform (op define_variable) (const eval_assignment) (reg val) (reg env))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "ok"));// (assign val (const ok))
assign(VAL, make_compiled_procedure("ENTRY282", entry282, registers[ENV]));// (assign val (op make_compiled_procedure) (label entry282) (reg env))
goto_with_label("AFTER_LAMBDA283");// (goto (label after_lambda283))

}
void entry282()
{// entry282
assign(ENV, compiled_procedure_env(PROC));// (assign env (op compiled_procedure_env) (reg proc))
assign(ENV, extend_environment(new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp"), registers[ARGL], registers[ENV]));
assign(ENV, extend_environment(new SchemeDataType(SchemeDataType::TypeId::Symbol, "env"), registers[ARGL], registers[ENV]));
// (assign env (op extend_environment) (const (exp env)) (reg argl) (reg env))
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
return goto_with_label("PRIMITIVE_BRANCH287");
}// (branch (label primitive_branch287))
compiled_branch288();
}
void compiled_branch288()
{// compiled_branch288
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL289"));// (assign continue (label after_call289))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch287()
{// primitive_branch287
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call289();
}
void after_call289()
{// after_call289
s.restore(ARGL);// (restore argl)
assign(ARGL, cons(registers[VAL], registers[ARGL]));// (assign argl (op cons) (reg val) (reg argl))
s.restore(PROC);// (restore proc)
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH290");
}// (branch (label primitive_branch290))
compiled_branch291();
}
void compiled_branch291()
{// compiled_branch291
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL292"));// (assign continue (label after_call292))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch290()
{// primitive_branch290
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call292();
}
void after_call292()
{// after_call292
s.restore(ARGL);// (restore argl)
assign(ARGL, cons(registers[VAL], registers[ARGL]));// (assign argl (op cons) (reg val) (reg argl))
s.restore(ENV);// (restore env)
s.save(ARGL);// (save argl)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "definition_variable"), registers[ENV]));// (assign proc (op lookup_variable_value) (const definition_variable) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp"), registers[ENV]));// (assign val (op lookup_variable_value) (const exp) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH284");
}// (branch (label primitive_branch284))
compiled_branch285();
}
void compiled_branch285()
{// compiled_branch285
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL286"));// (assign continue (label after_call286))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch284()
{// primitive_branch284
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call286();
}
void after_call286()
{// after_call286
s.restore(ARGL);// (restore argl)
assign(ARGL, cons(registers[VAL], registers[ARGL]));// (assign argl (op cons) (reg val) (reg argl))
s.restore(PROC);// (restore proc)
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH293");
}// (branch (label primitive_branch293))
compiled_branch294();
}
void compiled_branch294()
{// compiled_branch294
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL295"));// (assign continue (label after_call295))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch293()
{// primitive_branch293
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call295();
}
void after_call295()
{// after_call295
s.restore(CONTINUE);// (restore continue)
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "ok"));// (assign val (const ok))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_lambda283();
}
void after_lambda283()
{// after_lambda283
define_variable(new SchemeDataType(SchemeDataType::TypeId::Symbol, "eval_definition"), registers[VAL], registers[ENV]);// (perform (op define_variable) (const eval_definition) (reg val) (reg env))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "ok"));// (assign val (const ok))
assign(VAL, make_compiled_procedure("ENTRY296", entry296, registers[ENV]));// (assign val (op make_compiled_procedure) (label entry296) (reg env))
goto_with_label("AFTER_LAMBDA297");// (goto (label after_lambda297))

}
void entry296()
{// entry296
assign(ENV, compiled_procedure_env(PROC));// (assign env (op compiled_procedure_env) (reg proc))
assign(ENV, extend_environment(new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp"), registers[ARGL], registers[ENV]));
// (assign env (op extend_environment) (const exp) (reg argl) (reg env))
s.save(CONTINUE);// (save continue)
s.save(ENV);// (save env)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "number_p"), registers[ENV]));// (assign proc (op lookup_variable_value) (const number_p) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp"), registers[ENV]));// (assign val (op lookup_variable_value) (const exp) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH301");
}// (branch (label primitive_branch301))
compiled_branch302();
}
void compiled_branch302()
{// compiled_branch302
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL303"));// (assign continue (label after_call303))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch301()
{// primitive_branch301
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call303();
}
void after_call303()
{// after_call303
s.restore(ENV);// (restore env)
s.restore(CONTINUE);// (restore continue)
if ( false_p(registers[VAL]) ) {// (test (op false_p) (reg val))
return goto_with_label("FALSE_BRANCH299");
}// (branch (label false_branch299))
true_branch298();
}
void true_branch298()
{// true_branch298
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "true"), registers[ENV]));// (assign val (op lookup_variable_value) (const true) (reg env))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))

}
void false_branch299()
{// false_branch299
s.save(CONTINUE);// (save continue)
s.save(ENV);// (save env)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "string_p"), registers[ENV]));// (assign proc (op lookup_variable_value) (const string_p) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp"), registers[ENV]));// (assign val (op lookup_variable_value) (const exp) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH307");
}// (branch (label primitive_branch307))
compiled_branch308();
}
void compiled_branch308()
{// compiled_branch308
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL309"));// (assign continue (label after_call309))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch307()
{// primitive_branch307
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call309();
}
void after_call309()
{// after_call309
s.restore(ENV);// (restore env)
s.restore(CONTINUE);// (restore continue)
if ( false_p(registers[VAL]) ) {// (test (op false_p) (reg val))
return goto_with_label("FALSE_BRANCH305");
}// (branch (label false_branch305))
true_branch304();
}
void true_branch304()
{// true_branch304
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "true"), registers[ENV]));// (assign val (op lookup_variable_value) (const true) (reg env))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))

}
void false_branch305()
{// false_branch305
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "false"), registers[ENV]));// (assign val (op lookup_variable_value) (const false) (reg env))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_if306();
}
void after_if306()
{// after_if306
after_if300();
}
void after_if300()
{// after_if300
after_lambda297();
}
void after_lambda297()
{// after_lambda297
define_variable(new SchemeDataType(SchemeDataType::TypeId::Symbol, "self_evaluating_p"), registers[VAL], registers[ENV]);// (perform (op define_variable) (const self_evaluating_p) (reg val) (reg env))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "ok"));// (assign val (const ok))
assign(VAL, make_compiled_procedure("ENTRY310", entry310, registers[ENV]));// (assign val (op make_compiled_procedure) (label entry310) (reg env))
goto_with_label("AFTER_LAMBDA311");// (goto (label after_lambda311))

}
void entry310()
{// entry310
assign(ENV, compiled_procedure_env(PROC));// (assign env (op compiled_procedure_env) (reg proc))
assign(ENV, extend_environment(new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp"), registers[ARGL], registers[ENV]));
// (assign env (op extend_environment) (const exp) (reg argl) (reg env))
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "tagged_list_p"), registers[ENV]));// (assign proc (op lookup_variable_value) (const tagged_list_p) (reg env))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "quote"));// (assign val (const quote))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp"), registers[ENV]));// (assign val (op lookup_variable_value) (const exp) (reg env))
assign(ARGL, cons(registers[VAL], registers[ARGL]));// (assign argl (op cons) (reg val) (reg argl))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH312");
}// (branch (label primitive_branch312))
compiled_branch313();
}
void compiled_branch313()
{// compiled_branch313
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch312()
{// primitive_branch312
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call314();
}
void after_call314()
{// after_call314
after_lambda311();
}
void after_lambda311()
{// after_lambda311
define_variable(new SchemeDataType(SchemeDataType::TypeId::Symbol, "quoted_p"), registers[VAL], registers[ENV]);// (perform (op define_variable) (const quoted_p) (reg val) (reg env))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "ok"));// (assign val (const ok))
assign(VAL, make_compiled_procedure("ENTRY315", entry315, registers[ENV]));// (assign val (op make_compiled_procedure) (label entry315) (reg env))
goto_with_label("AFTER_LAMBDA316");// (goto (label after_lambda316))

}
void entry315()
{// entry315
assign(ENV, compiled_procedure_env(PROC));// (assign env (op compiled_procedure_env) (reg proc))
assign(ENV, extend_environment(new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp"), registers[ARGL], registers[ENV]));
// (assign env (op extend_environment) (const exp) (reg argl) (reg env))
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "cadr"), registers[ENV]));// (assign proc (op lookup_variable_value) (const cadr) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp"), registers[ENV]));// (assign val (op lookup_variable_value) (const exp) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH317");
}// (branch (label primitive_branch317))
compiled_branch318();
}
void compiled_branch318()
{// compiled_branch318
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch317()
{// primitive_branch317
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call319();
}
void after_call319()
{// after_call319
after_lambda316();
}
void after_lambda316()
{// after_lambda316
define_variable(new SchemeDataType(SchemeDataType::TypeId::Symbol, "text_of_quotation"), registers[VAL], registers[ENV]);// (perform (op define_variable) (const text_of_quotation) (reg val) (reg env))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "ok"));// (assign val (const ok))
assign(VAL, make_compiled_procedure("ENTRY320", entry320, registers[ENV]));// (assign val (op make_compiled_procedure) (label entry320) (reg env))
goto_with_label("AFTER_LAMBDA321");// (goto (label after_lambda321))

}
void entry320()
{// entry320
assign(ENV, compiled_procedure_env(PROC));// (assign env (op compiled_procedure_env) (reg proc))
assign(ENV, extend_environment(new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp"), registers[ARGL], registers[ENV]));
assign(ENV, extend_environment(new SchemeDataType(SchemeDataType::TypeId::Symbol, "tag"), registers[ARGL], registers[ENV]));
// (assign env (op extend_environment) (const (exp tag)) (reg argl) (reg env))
s.save(CONTINUE);// (save continue)
s.save(ENV);// (save env)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "pair_p"), registers[ENV]));// (assign proc (op lookup_variable_value) (const pair_p) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp"), registers[ENV]));// (assign val (op lookup_variable_value) (const exp) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH325");
}// (branch (label primitive_branch325))
compiled_branch326();
}
void compiled_branch326()
{// compiled_branch326
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL327"));// (assign continue (label after_call327))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch325()
{// primitive_branch325
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call327();
}
void after_call327()
{// after_call327
s.restore(ENV);// (restore env)
s.restore(CONTINUE);// (restore continue)
if ( false_p(registers[VAL]) ) {// (test (op false_p) (reg val))
return goto_with_label("FALSE_BRANCH323");
}// (branch (label false_branch323))
true_branch322();
}
void true_branch322()
{// true_branch322
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
return goto_with_label("PRIMITIVE_BRANCH328");
}// (branch (label primitive_branch328))
compiled_branch329();
}
void compiled_branch329()
{// compiled_branch329
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL330"));// (assign continue (label after_call330))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch328()
{// primitive_branch328
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call330();
}
void after_call330()
{// after_call330
s.restore(ARGL);// (restore argl)
assign(ARGL, cons(registers[VAL], registers[ARGL]));// (assign argl (op cons) (reg val) (reg argl))
s.restore(PROC);// (restore proc)
s.restore(CONTINUE);// (restore continue)
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

}
void false_branch323()
{// false_branch323
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "false"), registers[ENV]));// (assign val (op lookup_variable_value) (const false) (reg env))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_if324();
}
void after_if324()
{// after_if324
after_lambda321();
}
void after_lambda321()
{// after_lambda321
define_variable(new SchemeDataType(SchemeDataType::TypeId::Symbol, "tagged_list_p"), registers[VAL], registers[ENV]);// (perform (op define_variable) (const tagged_list_p) (reg val) (reg env))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "ok"));// (assign val (const ok))
assign(VAL, make_compiled_procedure("ENTRY334", entry334, registers[ENV]));// (assign val (op make_compiled_procedure) (label entry334) (reg env))
goto_with_label("AFTER_LAMBDA335");// (goto (label after_lambda335))

}
void entry334()
{// entry334
assign(ENV, compiled_procedure_env(PROC));// (assign env (op compiled_procedure_env) (reg proc))
assign(ENV, extend_environment(new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp"), registers[ARGL], registers[ENV]));
// (assign env (op extend_environment) (const exp) (reg argl) (reg env))
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "symbol_p"), registers[ENV]));// (assign proc (op lookup_variable_value) (const symbol_p) (reg env))
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
define_variable(new SchemeDataType(SchemeDataType::TypeId::Symbol, "variable_p"), registers[VAL], registers[ENV]);// (perform (op define_variable) (const variable_p) (reg val) (reg env))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "ok"));// (assign val (const ok))
assign(VAL, make_compiled_procedure("ENTRY339", entry339, registers[ENV]));// (assign val (op make_compiled_procedure) (label entry339) (reg env))
goto_with_label("AFTER_LAMBDA340");// (goto (label after_lambda340))

}
void entry339()
{// entry339
assign(ENV, compiled_procedure_env(PROC));// (assign env (op compiled_procedure_env) (reg proc))
assign(ENV, extend_environment(new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp"), registers[ARGL], registers[ENV]));
// (assign env (op extend_environment) (const exp) (reg argl) (reg env))
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "tagged_list_p"), registers[ENV]));// (assign proc (op lookup_variable_value) (const tagged_list_p) (reg env))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "set"));// (assign val (const set))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp"), registers[ENV]));// (assign val (op lookup_variable_value) (const exp) (reg env))
assign(ARGL, cons(registers[VAL], registers[ARGL]));// (assign argl (op cons) (reg val) (reg argl))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH341");
}// (branch (label primitive_branch341))
compiled_branch342();
}
void compiled_branch342()
{// compiled_branch342
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch341()
{// primitive_branch341
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call343();
}
void after_call343()
{// after_call343
after_lambda340();
}
void after_lambda340()
{// after_lambda340
define_variable(new SchemeDataType(SchemeDataType::TypeId::Symbol, "assignment_p"), registers[VAL], registers[ENV]);// (perform (op define_variable) (const assignment_p) (reg val) (reg env))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "ok"));// (assign val (const ok))
assign(VAL, make_compiled_procedure("ENTRY344", entry344, registers[ENV]));// (assign val (op make_compiled_procedure) (label entry344) (reg env))
goto_with_label("AFTER_LAMBDA345");// (goto (label after_lambda345))

}
void entry344()
{// entry344
assign(ENV, compiled_procedure_env(PROC));// (assign env (op compiled_procedure_env) (reg proc))
assign(ENV, extend_environment(new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp"), registers[ARGL], registers[ENV]));
// (assign env (op extend_environment) (const exp) (reg argl) (reg env))
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "cadr"), registers[ENV]));// (assign proc (op lookup_variable_value) (const cadr) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp"), registers[ENV]));// (assign val (op lookup_variable_value) (const exp) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH346");
}// (branch (label primitive_branch346))
compiled_branch347();
}
void compiled_branch347()
{// compiled_branch347
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch346()
{// primitive_branch346
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call348();
}
void after_call348()
{// after_call348
after_lambda345();
}
void after_lambda345()
{// after_lambda345
define_variable(new SchemeDataType(SchemeDataType::TypeId::Symbol, "assignment_variable"), registers[VAL], registers[ENV]);// (perform (op define_variable) (const assignment_variable) (reg val) (reg env))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "ok"));// (assign val (const ok))
assign(VAL, make_compiled_procedure("ENTRY349", entry349, registers[ENV]));// (assign val (op make_compiled_procedure) (label entry349) (reg env))
goto_with_label("AFTER_LAMBDA350");// (goto (label after_lambda350))

}
void entry349()
{// entry349
assign(ENV, compiled_procedure_env(PROC));// (assign env (op compiled_procedure_env) (reg proc))
assign(ENV, extend_environment(new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp"), registers[ARGL], registers[ENV]));
// (assign env (op extend_environment) (const exp) (reg argl) (reg env))
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "caddr"), registers[ENV]));// (assign proc (op lookup_variable_value) (const caddr) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp"), registers[ENV]));// (assign val (op lookup_variable_value) (const exp) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH351");
}// (branch (label primitive_branch351))
compiled_branch352();
}
void compiled_branch352()
{// compiled_branch352
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch351()
{// primitive_branch351
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call353();
}
void after_call353()
{// after_call353
after_lambda350();
}
void after_lambda350()
{// after_lambda350
define_variable(new SchemeDataType(SchemeDataType::TypeId::Symbol, "assignment_value"), registers[VAL], registers[ENV]);// (perform (op define_variable) (const assignment_value) (reg val) (reg env))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "ok"));// (assign val (const ok))
assign(VAL, make_compiled_procedure("ENTRY354", entry354, registers[ENV]));// (assign val (op make_compiled_procedure) (label entry354) (reg env))
goto_with_label("AFTER_LAMBDA355");// (goto (label after_lambda355))

}
void entry354()
{// entry354
assign(ENV, compiled_procedure_env(PROC));// (assign env (op compiled_procedure_env) (reg proc))
assign(ENV, extend_environment(new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp"), registers[ARGL], registers[ENV]));
// (assign env (op extend_environment) (const exp) (reg argl) (reg env))
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "tagged_list_p"), registers[ENV]));// (assign proc (op lookup_variable_value) (const tagged_list_p) (reg env))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "define"));// (assign val (const define))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp"), registers[ENV]));// (assign val (op lookup_variable_value) (const exp) (reg env))
assign(ARGL, cons(registers[VAL], registers[ARGL]));// (assign argl (op cons) (reg val) (reg argl))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH356");
}// (branch (label primitive_branch356))
compiled_branch357();
}
void compiled_branch357()
{// compiled_branch357
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch356()
{// primitive_branch356
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call358();
}
void after_call358()
{// after_call358
after_lambda355();
}
void after_lambda355()
{// after_lambda355
define_variable(new SchemeDataType(SchemeDataType::TypeId::Symbol, "definition_p"), registers[VAL], registers[ENV]);// (perform (op define_variable) (const definition_p) (reg val) (reg env))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "ok"));// (assign val (const ok))
assign(VAL, make_compiled_procedure("ENTRY359", entry359, registers[ENV]));// (assign val (op make_compiled_procedure) (label entry359) (reg env))
goto_with_label("AFTER_LAMBDA360");// (goto (label after_lambda360))

}
void entry359()
{// entry359
assign(ENV, compiled_procedure_env(PROC));// (assign env (op compiled_procedure_env) (reg proc))
assign(ENV, extend_environment(new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp"), registers[ARGL], registers[ENV]));
// (assign env (op extend_environment) (const exp) (reg argl) (reg env))
s.save(CONTINUE);// (save continue)
s.save(ENV);// (save env)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "symbol_p"), registers[ENV]));// (assign proc (op lookup_variable_value) (const symbol_p) (reg env))
s.save(PROC);// (save proc)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "cadr"), registers[ENV]));// (assign proc (op lookup_variable_value) (const cadr) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp"), registers[ENV]));// (assign val (op lookup_variable_value) (const exp) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH364");
}// (branch (label primitive_branch364))
compiled_branch365();
}
void compiled_branch365()
{// compiled_branch365
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL366"));// (assign continue (label after_call366))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch364()
{// primitive_branch364
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call366();
}
void after_call366()
{// after_call366
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
s.restore(PROC);// (restore proc)
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH367");
}// (branch (label primitive_branch367))
compiled_branch368();
}
void compiled_branch368()
{// compiled_branch368
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL369"));// (assign continue (label after_call369))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch367()
{// primitive_branch367
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call369();
}
void after_call369()
{// after_call369
s.restore(ENV);// (restore env)
s.restore(CONTINUE);// (restore continue)
if ( false_p(registers[VAL]) ) {// (test (op false_p) (reg val))
return goto_with_label("FALSE_BRANCH362");
}// (branch (label false_branch362))
true_branch361();
}
void true_branch361()
{// true_branch361
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "cadr"), registers[ENV]));// (assign proc (op lookup_variable_value) (const cadr) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp"), registers[ENV]));// (assign val (op lookup_variable_value) (const exp) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH370");
}// (branch (label primitive_branch370))
compiled_branch371();
}
void compiled_branch371()
{// compiled_branch371
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch370()
{// primitive_branch370
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call372();
}
void after_call372()
{// after_call372

}
void false_branch362()
{// false_branch362
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "caadr"), registers[ENV]));// (assign proc (op lookup_variable_value) (const caadr) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp"), registers[ENV]));// (assign val (op lookup_variable_value) (const exp) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH373");
}// (branch (label primitive_branch373))
compiled_branch374();
}
void compiled_branch374()
{// compiled_branch374
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch373()
{// primitive_branch373
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call375();
}
void after_call375()
{// after_call375
after_if363();
}
void after_if363()
{// after_if363
after_lambda360();
}
void after_lambda360()
{// after_lambda360
define_variable(new SchemeDataType(SchemeDataType::TypeId::Symbol, "definition_variable"), registers[VAL], registers[ENV]);// (perform (op define_variable) (const definition_variable) (reg val) (reg env))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "ok"));// (assign val (const ok))
assign(VAL, make_compiled_procedure("ENTRY376", entry376, registers[ENV]));// (assign val (op make_compiled_procedure) (label entry376) (reg env))
goto_with_label("AFTER_LAMBDA377");// (goto (label after_lambda377))

}
void entry376()
{// entry376
assign(ENV, compiled_procedure_env(PROC));// (assign env (op compiled_procedure_env) (reg proc))
assign(ENV, extend_environment(new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp"), registers[ARGL], registers[ENV]));
// (assign env (op extend_environment) (const exp) (reg argl) (reg env))
s.save(CONTINUE);// (save continue)
s.save(ENV);// (save env)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "symbol_p"), registers[ENV]));// (assign proc (op lookup_variable_value) (const symbol_p) (reg env))
s.save(PROC);// (save proc)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "cadr"), registers[ENV]));// (assign proc (op lookup_variable_value) (const cadr) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp"), registers[ENV]));// (assign val (op lookup_variable_value) (const exp) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH381");
}// (branch (label primitive_branch381))
compiled_branch382();
}
void compiled_branch382()
{// compiled_branch382
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL383"));// (assign continue (label after_call383))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch381()
{// primitive_branch381
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call383();
}
void after_call383()
{// after_call383
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
s.restore(PROC);// (restore proc)
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH384");
}// (branch (label primitive_branch384))
compiled_branch385();
}
void compiled_branch385()
{// compiled_branch385
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL386"));// (assign continue (label after_call386))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch384()
{// primitive_branch384
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call386();
}
void after_call386()
{// after_call386
s.restore(ENV);// (restore env)
s.restore(CONTINUE);// (restore continue)
if ( false_p(registers[VAL]) ) {// (test (op false_p) (reg val))
return goto_with_label("FALSE_BRANCH379");
}// (branch (label false_branch379))
true_branch378();
}
void true_branch378()
{// true_branch378
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "caddr"), registers[ENV]));// (assign proc (op lookup_variable_value) (const caddr) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp"), registers[ENV]));// (assign val (op lookup_variable_value) (const exp) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH387");
}// (branch (label primitive_branch387))
compiled_branch388();
}
void compiled_branch388()
{// compiled_branch388
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch387()
{// primitive_branch387
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call389();
}
void after_call389()
{// after_call389

}
void false_branch379()
{// false_branch379
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "make_lambda"), registers[ENV]));// (assign proc (op lookup_variable_value) (const make_lambda) (reg env))
s.save(CONTINUE);// (save continue)
s.save(PROC);// (save proc)
s.save(ENV);// (save env)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "cddr"), registers[ENV]));// (assign proc (op lookup_variable_value) (const cddr) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp"), registers[ENV]));// (assign val (op lookup_variable_value) (const exp) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH393");
}// (branch (label primitive_branch393))
compiled_branch394();
}
void compiled_branch394()
{// compiled_branch394
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL395"));// (assign continue (label after_call395))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch393()
{// primitive_branch393
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call395();
}
void after_call395()
{// after_call395
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
s.restore(ENV);// (restore env)
s.save(ARGL);// (save argl)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "cdadr"), registers[ENV]));// (assign proc (op lookup_variable_value) (const cdadr) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp"), registers[ENV]));// (assign val (op lookup_variable_value) (const exp) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH390");
}// (branch (label primitive_branch390))
compiled_branch391();
}
void compiled_branch391()
{// compiled_branch391
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL392"));// (assign continue (label after_call392))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch390()
{// primitive_branch390
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call392();
}
void after_call392()
{// after_call392
s.restore(ARGL);// (restore argl)
assign(ARGL, cons(registers[VAL], registers[ARGL]));// (assign argl (op cons) (reg val) (reg argl))
s.restore(PROC);// (restore proc)
s.restore(CONTINUE);// (restore continue)
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH396");
}// (branch (label primitive_branch396))
compiled_branch397();
}
void compiled_branch397()
{// compiled_branch397
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch396()
{// primitive_branch396
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call398();
}
void after_call398()
{// after_call398
after_if380();
}
void after_if380()
{// after_if380
after_lambda377();
}
void after_lambda377()
{// after_lambda377
define_variable(new SchemeDataType(SchemeDataType::TypeId::Symbol, "definition_value"), registers[VAL], registers[ENV]);// (perform (op define_variable) (const definition_value) (reg val) (reg env))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "ok"));// (assign val (const ok))
assign(VAL, make_compiled_procedure("ENTRY399", entry399, registers[ENV]));// (assign val (op make_compiled_procedure) (label entry399) (reg env))
goto_with_label("AFTER_LAMBDA400");// (goto (label after_lambda400))

}
void entry399()
{// entry399
assign(ENV, compiled_procedure_env(PROC));// (assign env (op compiled_procedure_env) (reg proc))
assign(ENV, extend_environment(new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp"), registers[ARGL], registers[ENV]));
// (assign env (op extend_environment) (const exp) (reg argl) (reg env))
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "tagged_list_p"), registers[ENV]));// (assign proc (op lookup_variable_value) (const tagged_list_p) (reg env))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "lambda"));// (assign val (const lambda))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp"), registers[ENV]));// (assign val (op lookup_variable_value) (const exp) (reg env))
assign(ARGL, cons(registers[VAL], registers[ARGL]));// (assign argl (op cons) (reg val) (reg argl))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH401");
}// (branch (label primitive_branch401))
compiled_branch402();
}
void compiled_branch402()
{// compiled_branch402
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch401()
{// primitive_branch401
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call403();
}
void after_call403()
{// after_call403
after_lambda400();
}
void after_lambda400()
{// after_lambda400
define_variable(new SchemeDataType(SchemeDataType::TypeId::Symbol, "lambda_p"), registers[VAL], registers[ENV]);// (perform (op define_variable) (const lambda_p) (reg val) (reg env))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "ok"));// (assign val (const ok))
assign(VAL, make_compiled_procedure("ENTRY404", entry404, registers[ENV]));// (assign val (op make_compiled_procedure) (label entry404) (reg env))
goto_with_label("AFTER_LAMBDA405");// (goto (label after_lambda405))

}
void entry404()
{// entry404
assign(ENV, compiled_procedure_env(PROC));// (assign env (op compiled_procedure_env) (reg proc))
assign(ENV, extend_environment(new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp"), registers[ARGL], registers[ENV]));
// (assign env (op extend_environment) (const exp) (reg argl) (reg env))
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "cadr"), registers[ENV]));// (assign proc (op lookup_variable_value) (const cadr) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp"), registers[ENV]));// (assign val (op lookup_variable_value) (const exp) (reg env))
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
after_lambda405();
}
void after_lambda405()
{// after_lambda405
define_variable(new SchemeDataType(SchemeDataType::TypeId::Symbol, "lambda_parameters"), registers[VAL], registers[ENV]);// (perform (op define_variable) (const lambda_parameters) (reg val) (reg env))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "ok"));// (assign val (const ok))
assign(VAL, make_compiled_procedure("ENTRY409", entry409, registers[ENV]));// (assign val (op make_compiled_procedure) (label entry409) (reg env))
goto_with_label("AFTER_LAMBDA410");// (goto (label after_lambda410))

}
void entry409()
{// entry409
assign(ENV, compiled_procedure_env(PROC));// (assign env (op compiled_procedure_env) (reg proc))
assign(ENV, extend_environment(new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp"), registers[ARGL], registers[ENV]));
// (assign env (op extend_environment) (const exp) (reg argl) (reg env))
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "cddr"), registers[ENV]));// (assign proc (op lookup_variable_value) (const cddr) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp"), registers[ENV]));// (assign val (op lookup_variable_value) (const exp) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
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
define_variable(new SchemeDataType(SchemeDataType::TypeId::Symbol, "lambda_body"), registers[VAL], registers[ENV]);// (perform (op define_variable) (const lambda_body) (reg val) (reg env))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "ok"));// (assign val (const ok))
assign(VAL, make_compiled_procedure("ENTRY414", entry414, registers[ENV]));// (assign val (op make_compiled_procedure) (label entry414) (reg env))
goto_with_label("AFTER_LAMBDA415");// (goto (label after_lambda415))

}
void entry414()
{// entry414
assign(ENV, compiled_procedure_env(PROC));// (assign env (op compiled_procedure_env) (reg proc))
assign(ENV, extend_environment(new SchemeDataType(SchemeDataType::TypeId::Symbol, "parameters"), registers[ARGL], registers[ENV]));
assign(ENV, extend_environment(new SchemeDataType(SchemeDataType::TypeId::Symbol, "body"), registers[ARGL], registers[ENV]));
// (assign env (op extend_environment) (const (parameters body)) (reg argl) (reg env))
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "cons"), registers[ENV]));// (assign proc (op lookup_variable_value) (const cons) (reg env))
s.save(CONTINUE);// (save continue)
s.save(PROC);// (save proc)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "cons"), registers[ENV]));// (assign proc (op lookup_variable_value) (const cons) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "body"), registers[ENV]));// (assign val (op lookup_variable_value) (const body) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "parameters"), registers[ENV]));// (assign val (op lookup_variable_value) (const parameters) (reg env))
assign(ARGL, cons(registers[VAL], registers[ARGL]));// (assign argl (op cons) (reg val) (reg argl))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH416");
}// (branch (label primitive_branch416))
compiled_branch417();
}
void compiled_branch417()
{// compiled_branch417
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL418"));// (assign continue (label after_call418))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch416()
{// primitive_branch416
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call418();
}
void after_call418()
{// after_call418
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "lambda"));// (assign val (const lambda))
assign(ARGL, cons(registers[VAL], registers[ARGL]));// (assign argl (op cons) (reg val) (reg argl))
s.restore(PROC);// (restore proc)
s.restore(CONTINUE);// (restore continue)
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH419");
}// (branch (label primitive_branch419))
compiled_branch420();
}
void compiled_branch420()
{// compiled_branch420
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch419()
{// primitive_branch419
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call421();
}
void after_call421()
{// after_call421
after_lambda415();
}
void after_lambda415()
{// after_lambda415
define_variable(new SchemeDataType(SchemeDataType::TypeId::Symbol, "make_lambda"), registers[VAL], registers[ENV]);// (perform (op define_variable) (const make_lambda) (reg val) (reg env))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "ok"));// (assign val (const ok))
assign(VAL, make_compiled_procedure("ENTRY422", entry422, registers[ENV]));// (assign val (op make_compiled_procedure) (label entry422) (reg env))
goto_with_label("AFTER_LAMBDA423");// (goto (label after_lambda423))

}
void entry422()
{// entry422
assign(ENV, compiled_procedure_env(PROC));// (assign env (op compiled_procedure_env) (reg proc))
assign(ENV, extend_environment(new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp"), registers[ARGL], registers[ENV]));
// (assign env (op extend_environment) (const exp) (reg argl) (reg env))
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "tagged_list_p"), registers[ENV]));// (assign proc (op lookup_variable_value) (const tagged_list_p) (reg env))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "if"));// (assign val (const if))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp"), registers[ENV]));// (assign val (op lookup_variable_value) (const exp) (reg env))
assign(ARGL, cons(registers[VAL], registers[ARGL]));// (assign argl (op cons) (reg val) (reg argl))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH424");
}// (branch (label primitive_branch424))
compiled_branch425();
}
void compiled_branch425()
{// compiled_branch425
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch424()
{// primitive_branch424
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call426();
}
void after_call426()
{// after_call426
after_lambda423();
}
void after_lambda423()
{// after_lambda423
define_variable(new SchemeDataType(SchemeDataType::TypeId::Symbol, "if_p"), registers[VAL], registers[ENV]);// (perform (op define_variable) (const if_p) (reg val) (reg env))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "ok"));// (assign val (const ok))
assign(VAL, make_compiled_procedure("ENTRY427", entry427, registers[ENV]));// (assign val (op make_compiled_procedure) (label entry427) (reg env))
goto_with_label("AFTER_LAMBDA428");// (goto (label after_lambda428))

}
void entry427()
{// entry427
assign(ENV, compiled_procedure_env(PROC));// (assign env (op compiled_procedure_env) (reg proc))
assign(ENV, extend_environment(new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp"), registers[ARGL], registers[ENV]));
// (assign env (op extend_environment) (const exp) (reg argl) (reg env))
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "cadr"), registers[ENV]));// (assign proc (op lookup_variable_value) (const cadr) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp"), registers[ENV]));// (assign val (op lookup_variable_value) (const exp) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH429");
}// (branch (label primitive_branch429))
compiled_branch430();
}
void compiled_branch430()
{// compiled_branch430
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch429()
{// primitive_branch429
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call431();
}
void after_call431()
{// after_call431
after_lambda428();
}
void after_lambda428()
{// after_lambda428
define_variable(new SchemeDataType(SchemeDataType::TypeId::Symbol, "if_predicate"), registers[VAL], registers[ENV]);// (perform (op define_variable) (const if_predicate) (reg val) (reg env))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "ok"));// (assign val (const ok))
assign(VAL, make_compiled_procedure("ENTRY432", entry432, registers[ENV]));// (assign val (op make_compiled_procedure) (label entry432) (reg env))
goto_with_label("AFTER_LAMBDA433");// (goto (label after_lambda433))

}
void entry432()
{// entry432
assign(ENV, compiled_procedure_env(PROC));// (assign env (op compiled_procedure_env) (reg proc))
assign(ENV, extend_environment(new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp"), registers[ARGL], registers[ENV]));
// (assign env (op extend_environment) (const exp) (reg argl) (reg env))
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "caddr"), registers[ENV]));// (assign proc (op lookup_variable_value) (const caddr) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp"), registers[ENV]));// (assign val (op lookup_variable_value) (const exp) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH434");
}// (branch (label primitive_branch434))
compiled_branch435();
}
void compiled_branch435()
{// compiled_branch435
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch434()
{// primitive_branch434
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call436();
}
void after_call436()
{// after_call436
after_lambda433();
}
void after_lambda433()
{// after_lambda433
define_variable(new SchemeDataType(SchemeDataType::TypeId::Symbol, "if_consequent"), registers[VAL], registers[ENV]);// (perform (op define_variable) (const if_consequent) (reg val) (reg env))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "ok"));// (assign val (const ok))
assign(VAL, make_compiled_procedure("ENTRY437", entry437, registers[ENV]));// (assign val (op make_compiled_procedure) (label entry437) (reg env))
goto_with_label("AFTER_LAMBDA438");// (goto (label after_lambda438))

}
void entry437()
{// entry437
assign(ENV, compiled_procedure_env(PROC));// (assign env (op compiled_procedure_env) (reg proc))
assign(ENV, extend_environment(new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp"), registers[ARGL], registers[ENV]));
// (assign env (op extend_environment) (const exp) (reg argl) (reg env))
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
return goto_with_label("PRIMITIVE_BRANCH442");
}// (branch (label primitive_branch442))
compiled_branch443();
}
void compiled_branch443()
{// compiled_branch443
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL444"));// (assign continue (label after_call444))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch442()
{// primitive_branch442
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call444();
}
void after_call444()
{// after_call444
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
s.restore(PROC);// (restore proc)
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH445");
}// (branch (label primitive_branch445))
compiled_branch446();
}
void compiled_branch446()
{// compiled_branch446
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL447"));// (assign continue (label after_call447))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch445()
{// primitive_branch445
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call447();
}
void after_call447()
{// after_call447
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
s.restore(PROC);// (restore proc)
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH448");
}// (branch (label primitive_branch448))
compiled_branch449();
}
void compiled_branch449()
{// compiled_branch449
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL450"));// (assign continue (label after_call450))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch448()
{// primitive_branch448
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call450();
}
void after_call450()
{// after_call450
s.restore(ENV);// (restore env)
s.restore(CONTINUE);// (restore continue)
if ( false_p(registers[VAL]) ) {// (test (op false_p) (reg val))
return goto_with_label("FALSE_BRANCH440");
}// (branch (label false_branch440))
true_branch439();
}
void true_branch439()
{// true_branch439
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "cadddr"), registers[ENV]));// (assign proc (op lookup_variable_value) (const cadddr) (reg env))
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

}
void false_branch440()
{// false_branch440
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "false"));// (assign val (const false))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_if441();
}
void after_if441()
{// after_if441
after_lambda438();
}
void after_lambda438()
{// after_lambda438
define_variable(new SchemeDataType(SchemeDataType::TypeId::Symbol, "if_alternative"), registers[VAL], registers[ENV]);// (perform (op define_variable) (const if_alternative) (reg val) (reg env))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "ok"));// (assign val (const ok))
assign(VAL, make_compiled_procedure("ENTRY454", entry454, registers[ENV]));// (assign val (op make_compiled_procedure) (label entry454) (reg env))
goto_with_label("AFTER_LAMBDA455");// (goto (label after_lambda455))

}
void entry454()
{// entry454
assign(ENV, compiled_procedure_env(PROC));// (assign env (op compiled_procedure_env) (reg proc))
assign(ENV, extend_environment(new SchemeDataType(SchemeDataType::TypeId::Symbol, "predicate"), registers[ARGL], registers[ENV]));
assign(ENV, extend_environment(new SchemeDataType(SchemeDataType::TypeId::Symbol, "consequent"), registers[ARGL], registers[ENV]));
assign(ENV, extend_environment(new SchemeDataType(SchemeDataType::TypeId::Symbol, "alternative"), registers[ARGL], registers[ENV]));
// (assign env (op extend_environment) (const (predicate consequent alternative)) (reg argl) (reg env))
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
return goto_with_label("PRIMITIVE_BRANCH456");
}// (branch (label primitive_branch456))
compiled_branch457();
}
void compiled_branch457()
{// compiled_branch457
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch456()
{// primitive_branch456
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call458();
}
void after_call458()
{// after_call458
after_lambda455();
}
void after_lambda455()
{// after_lambda455
define_variable(new SchemeDataType(SchemeDataType::TypeId::Symbol, "make_if"), registers[VAL], registers[ENV]);// (perform (op define_variable) (const make_if) (reg val) (reg env))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "ok"));// (assign val (const ok))
assign(VAL, make_compiled_procedure("ENTRY459", entry459, registers[ENV]));// (assign val (op make_compiled_procedure) (label entry459) (reg env))
goto_with_label("AFTER_LAMBDA460");// (goto (label after_lambda460))

}
void entry459()
{// entry459
assign(ENV, compiled_procedure_env(PROC));// (assign env (op compiled_procedure_env) (reg proc))
assign(ENV, extend_environment(new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp"), registers[ARGL], registers[ENV]));
// (assign env (op extend_environment) (const exp) (reg argl) (reg env))
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "tagged_list_p"), registers[ENV]));// (assign proc (op lookup_variable_value) (const tagged_list_p) (reg env))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "begin"));// (assign val (const begin))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp"), registers[ENV]));// (assign val (op lookup_variable_value) (const exp) (reg env))
assign(ARGL, cons(registers[VAL], registers[ARGL]));// (assign argl (op cons) (reg val) (reg argl))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH461");
}// (branch (label primitive_branch461))
compiled_branch462();
}
void compiled_branch462()
{// compiled_branch462
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch461()
{// primitive_branch461
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call463();
}
void after_call463()
{// after_call463
after_lambda460();
}
void after_lambda460()
{// after_lambda460
define_variable(new SchemeDataType(SchemeDataType::TypeId::Symbol, "begin_p"), registers[VAL], registers[ENV]);// (perform (op define_variable) (const begin_p) (reg val) (reg env))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "ok"));// (assign val (const ok))
assign(VAL, make_compiled_procedure("ENTRY464", entry464, registers[ENV]));// (assign val (op make_compiled_procedure) (label entry464) (reg env))
goto_with_label("AFTER_LAMBDA465");// (goto (label after_lambda465))

}
void entry464()
{// entry464
assign(ENV, compiled_procedure_env(PROC));// (assign env (op compiled_procedure_env) (reg proc))
assign(ENV, extend_environment(new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp"), registers[ARGL], registers[ENV]));
// (assign env (op extend_environment) (const exp) (reg argl) (reg env))
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "cdr"), registers[ENV]));// (assign proc (op lookup_variable_value) (const cdr) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp"), registers[ENV]));// (assign val (op lookup_variable_value) (const exp) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH466");
}// (branch (label primitive_branch466))
compiled_branch467();
}
void compiled_branch467()
{// compiled_branch467
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch466()
{// primitive_branch466
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call468();
}
void after_call468()
{// after_call468
after_lambda465();
}
void after_lambda465()
{// after_lambda465
define_variable(new SchemeDataType(SchemeDataType::TypeId::Symbol, "begin_actions"), registers[VAL], registers[ENV]);// (perform (op define_variable) (const begin_actions) (reg val) (reg env))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "ok"));// (assign val (const ok))
assign(VAL, make_compiled_procedure("ENTRY469", entry469, registers[ENV]));// (assign val (op make_compiled_procedure) (label entry469) (reg env))
goto_with_label("AFTER_LAMBDA470");// (goto (label after_lambda470))

}
void entry469()
{// entry469
assign(ENV, compiled_procedure_env(PROC));// (assign env (op compiled_procedure_env) (reg proc))
assign(ENV, extend_environment(new SchemeDataType(SchemeDataType::TypeId::Symbol, "seq"), registers[ARGL], registers[ENV]));
// (assign env (op extend_environment) (const seq) (reg argl) (reg env))
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "null_p"), registers[ENV]));// (assign proc (op lookup_variable_value) (const null_p) (reg env))
s.save(CONTINUE);// (save continue)
s.save(PROC);// (save proc)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "cdr"), registers[ENV]));// (assign proc (op lookup_variable_value) (const cdr) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "seq"), registers[ENV]));// (assign val (op lookup_variable_value) (const seq) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH471");
}// (branch (label primitive_branch471))
compiled_branch472();
}
void compiled_branch472()
{// compiled_branch472
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL473"));// (assign continue (label after_call473))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch471()
{// primitive_branch471
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call473();
}
void after_call473()
{// after_call473
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
s.restore(PROC);// (restore proc)
s.restore(CONTINUE);// (restore continue)
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH474");
}// (branch (label primitive_branch474))
compiled_branch475();
}
void compiled_branch475()
{// compiled_branch475
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch474()
{// primitive_branch474
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call476();
}
void after_call476()
{// after_call476
after_lambda470();
}
void after_lambda470()
{// after_lambda470
define_variable(new SchemeDataType(SchemeDataType::TypeId::Symbol, "last_exp_p"), registers[VAL], registers[ENV]);// (perform (op define_variable) (const last_exp_p) (reg val) (reg env))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "ok"));// (assign val (const ok))
assign(VAL, make_compiled_procedure("ENTRY477", entry477, registers[ENV]));// (assign val (op make_compiled_procedure) (label entry477) (reg env))
goto_with_label("AFTER_LAMBDA478");// (goto (label after_lambda478))

}
void entry477()
{// entry477
assign(ENV, compiled_procedure_env(PROC));// (assign env (op compiled_procedure_env) (reg proc))
assign(ENV, extend_environment(new SchemeDataType(SchemeDataType::TypeId::Symbol, "seq"), registers[ARGL], registers[ENV]));
// (assign env (op extend_environment) (const seq) (reg argl) (reg env))
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "car"), registers[ENV]));// (assign proc (op lookup_variable_value) (const car) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "seq"), registers[ENV]));// (assign val (op lookup_variable_value) (const seq) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH479");
}// (branch (label primitive_branch479))
compiled_branch480();
}
void compiled_branch480()
{// compiled_branch480
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch479()
{// primitive_branch479
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call481();
}
void after_call481()
{// after_call481
after_lambda478();
}
void after_lambda478()
{// after_lambda478
define_variable(new SchemeDataType(SchemeDataType::TypeId::Symbol, "first_exp"), registers[VAL], registers[ENV]);// (perform (op define_variable) (const first_exp) (reg val) (reg env))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "ok"));// (assign val (const ok))
assign(VAL, make_compiled_procedure("ENTRY482", entry482, registers[ENV]));// (assign val (op make_compiled_procedure) (label entry482) (reg env))
goto_with_label("AFTER_LAMBDA483");// (goto (label after_lambda483))

}
void entry482()
{// entry482
assign(ENV, compiled_procedure_env(PROC));// (assign env (op compiled_procedure_env) (reg proc))
assign(ENV, extend_environment(new SchemeDataType(SchemeDataType::TypeId::Symbol, "seq"), registers[ARGL], registers[ENV]));
// (assign env (op extend_environment) (const seq) (reg argl) (reg env))
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "cdr"), registers[ENV]));// (assign proc (op lookup_variable_value) (const cdr) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "seq"), registers[ENV]));// (assign val (op lookup_variable_value) (const seq) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH484");
}// (branch (label primitive_branch484))
compiled_branch485();
}
void compiled_branch485()
{// compiled_branch485
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch484()
{// primitive_branch484
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call486();
}
void after_call486()
{// after_call486
after_lambda483();
}
void after_lambda483()
{// after_lambda483
define_variable(new SchemeDataType(SchemeDataType::TypeId::Symbol, "rest_exps"), registers[VAL], registers[ENV]);// (perform (op define_variable) (const rest_exps) (reg val) (reg env))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "ok"));// (assign val (const ok))
assign(VAL, make_compiled_procedure("ENTRY487", entry487, registers[ENV]));// (assign val (op make_compiled_procedure) (label entry487) (reg env))
goto_with_label("AFTER_LAMBDA488");// (goto (label after_lambda488))

}
void entry487()
{// entry487
assign(ENV, compiled_procedure_env(PROC));// (assign env (op compiled_procedure_env) (reg proc))
assign(ENV, extend_environment(new SchemeDataType(SchemeDataType::TypeId::Symbol, "seq"), registers[ARGL], registers[ENV]));
// (assign env (op extend_environment) (const seq) (reg argl) (reg env))
s.save(CONTINUE);// (save continue)
s.save(ENV);// (save env)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "null_p"), registers[ENV]));// (assign proc (op lookup_variable_value) (const null_p) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "seq"), registers[ENV]));// (assign val (op lookup_variable_value) (const seq) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH492");
}// (branch (label primitive_branch492))
compiled_branch493();
}
void compiled_branch493()
{// compiled_branch493
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL494"));// (assign continue (label after_call494))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch492()
{// primitive_branch492
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call494();
}
void after_call494()
{// after_call494
s.restore(ENV);// (restore env)
s.restore(CONTINUE);// (restore continue)
if ( false_p(registers[VAL]) ) {// (test (op false_p) (reg val))
return goto_with_label("FALSE_BRANCH490");
}// (branch (label false_branch490))
true_branch489();
}
void true_branch489()
{// true_branch489
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "seq"), registers[ENV]));// (assign val (op lookup_variable_value) (const seq) (reg env))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))

}
void false_branch490()
{// false_branch490
s.save(CONTINUE);// (save continue)
s.save(ENV);// (save env)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "last_exp_p"), registers[ENV]));// (assign proc (op lookup_variable_value) (const last_exp_p) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "seq"), registers[ENV]));// (assign val (op lookup_variable_value) (const seq) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH498");
}// (branch (label primitive_branch498))
compiled_branch499();
}
void compiled_branch499()
{// compiled_branch499
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL500"));// (assign continue (label after_call500))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch498()
{// primitive_branch498
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call500();
}
void after_call500()
{// after_call500
s.restore(ENV);// (restore env)
s.restore(CONTINUE);// (restore continue)
if ( false_p(registers[VAL]) ) {// (test (op false_p) (reg val))
return goto_with_label("FALSE_BRANCH496");
}// (branch (label false_branch496))
true_branch495();
}
void true_branch495()
{// true_branch495
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "first_exp"), registers[ENV]));// (assign proc (op lookup_variable_value) (const first_exp) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "seq"), registers[ENV]));// (assign val (op lookup_variable_value) (const seq) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH501");
}// (branch (label primitive_branch501))
compiled_branch502();
}
void compiled_branch502()
{// compiled_branch502
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch501()
{// primitive_branch501
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call503();
}
void after_call503()
{// after_call503

}
void false_branch496()
{// false_branch496
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "make_begin"), registers[ENV]));// (assign proc (op lookup_variable_value) (const make_begin) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "seq"), registers[ENV]));// (assign val (op lookup_variable_value) (const seq) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH504");
}// (branch (label primitive_branch504))
compiled_branch505();
}
void compiled_branch505()
{// compiled_branch505
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch504()
{// primitive_branch504
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call506();
}
void after_call506()
{// after_call506
after_if497();
}
void after_if497()
{// after_if497
after_if491();
}
void after_if491()
{// after_if491
after_lambda488();
}
void after_lambda488()
{// after_lambda488
define_variable(new SchemeDataType(SchemeDataType::TypeId::Symbol, "sequence_>exp"), registers[VAL], registers[ENV]);// (perform (op define_variable) (const sequence_>exp) (reg val) (reg env))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "ok"));// (assign val (const ok))
assign(VAL, make_compiled_procedure("ENTRY507", entry507, registers[ENV]));// (assign val (op make_compiled_procedure) (label entry507) (reg env))
goto_with_label("AFTER_LAMBDA508");// (goto (label after_lambda508))

}
void entry507()
{// entry507
assign(ENV, compiled_procedure_env(PROC));// (assign env (op compiled_procedure_env) (reg proc))
assign(ENV, extend_environment(new SchemeDataType(SchemeDataType::TypeId::Symbol, "seq"), registers[ARGL], registers[ENV]));
// (assign env (op extend_environment) (const seq) (reg argl) (reg env))
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "cons"), registers[ENV]));// (assign proc (op lookup_variable_value) (const cons) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "seq"), registers[ENV]));// (assign val (op lookup_variable_value) (const seq) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "begin"));// (assign val (const begin))
assign(ARGL, cons(registers[VAL], registers[ARGL]));// (assign argl (op cons) (reg val) (reg argl))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH509");
}// (branch (label primitive_branch509))
compiled_branch510();
}
void compiled_branch510()
{// compiled_branch510
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch509()
{// primitive_branch509
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call511();
}
void after_call511()
{// after_call511
after_lambda508();
}
void after_lambda508()
{// after_lambda508
define_variable(new SchemeDataType(SchemeDataType::TypeId::Symbol, "make_begin"), registers[VAL], registers[ENV]);// (perform (op define_variable) (const make_begin) (reg val) (reg env))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "ok"));// (assign val (const ok))
assign(VAL, make_compiled_procedure("ENTRY512", entry512, registers[ENV]));// (assign val (op make_compiled_procedure) (label entry512) (reg env))
goto_with_label("AFTER_LAMBDA513");// (goto (label after_lambda513))

}
void entry512()
{// entry512
assign(ENV, compiled_procedure_env(PROC));// (assign env (op compiled_procedure_env) (reg proc))
assign(ENV, extend_environment(new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp"), registers[ARGL], registers[ENV]));
// (assign env (op extend_environment) (const exp) (reg argl) (reg env))
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "pair_p"), registers[ENV]));// (assign proc (op lookup_variable_value) (const pair_p) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp"), registers[ENV]));// (assign val (op lookup_variable_value) (const exp) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH514");
}// (branch (label primitive_branch514))
compiled_branch515();
}
void compiled_branch515()
{// compiled_branch515
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch514()
{// primitive_branch514
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call516();
}
void after_call516()
{// after_call516
after_lambda513();
}
void after_lambda513()
{// after_lambda513
define_variable(new SchemeDataType(SchemeDataType::TypeId::Symbol, "application_p"), registers[VAL], registers[ENV]);// (perform (op define_variable) (const application_p) (reg val) (reg env))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "ok"));// (assign val (const ok))
assign(VAL, make_compiled_procedure("ENTRY517", entry517, registers[ENV]));// (assign val (op make_compiled_procedure) (label entry517) (reg env))
goto_with_label("AFTER_LAMBDA518");// (goto (label after_lambda518))

}
void entry517()
{// entry517
assign(ENV, compiled_procedure_env(PROC));// (assign env (op compiled_procedure_env) (reg proc))
assign(ENV, extend_environment(new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp"), registers[ARGL], registers[ENV]));
// (assign env (op extend_environment) (const exp) (reg argl) (reg env))
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "car"), registers[ENV]));// (assign proc (op lookup_variable_value) (const car) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp"), registers[ENV]));// (assign val (op lookup_variable_value) (const exp) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH519");
}// (branch (label primitive_branch519))
compiled_branch520();
}
void compiled_branch520()
{// compiled_branch520
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch519()
{// primitive_branch519
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call521();
}
void after_call521()
{// after_call521
after_lambda518();
}
void after_lambda518()
{// after_lambda518
define_variable(new SchemeDataType(SchemeDataType::TypeId::Symbol, "operator"), registers[VAL], registers[ENV]);// (perform (op define_variable) (const operator) (reg val) (reg env))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "ok"));// (assign val (const ok))
assign(VAL, make_compiled_procedure("ENTRY522", entry522, registers[ENV]));// (assign val (op make_compiled_procedure) (label entry522) (reg env))
goto_with_label("AFTER_LAMBDA523");// (goto (label after_lambda523))

}
void entry522()
{// entry522
assign(ENV, compiled_procedure_env(PROC));// (assign env (op compiled_procedure_env) (reg proc))
assign(ENV, extend_environment(new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp"), registers[ARGL], registers[ENV]));
// (assign env (op extend_environment) (const exp) (reg argl) (reg env))
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "cdr"), registers[ENV]));// (assign proc (op lookup_variable_value) (const cdr) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp"), registers[ENV]));// (assign val (op lookup_variable_value) (const exp) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH524");
}// (branch (label primitive_branch524))
compiled_branch525();
}
void compiled_branch525()
{// compiled_branch525
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch524()
{// primitive_branch524
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call526();
}
void after_call526()
{// after_call526
after_lambda523();
}
void after_lambda523()
{// after_lambda523
define_variable(new SchemeDataType(SchemeDataType::TypeId::Symbol, "operands"), registers[VAL], registers[ENV]);// (perform (op define_variable) (const operands) (reg val) (reg env))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "ok"));// (assign val (const ok))
assign(VAL, make_compiled_procedure("ENTRY527", entry527, registers[ENV]));// (assign val (op make_compiled_procedure) (label entry527) (reg env))
goto_with_label("AFTER_LAMBDA528");// (goto (label after_lambda528))

}
void entry527()
{// entry527
assign(ENV, compiled_procedure_env(PROC));// (assign env (op compiled_procedure_env) (reg proc))
assign(ENV, extend_environment(new SchemeDataType(SchemeDataType::TypeId::Symbol, "ops"), registers[ARGL], registers[ENV]));
// (assign env (op extend_environment) (const ops) (reg argl) (reg env))
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "null_p"), registers[ENV]));// (assign proc (op lookup_variable_value) (const null_p) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "ops"), registers[ENV]));// (assign val (op lookup_variable_value) (const ops) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH529");
}// (branch (label primitive_branch529))
compiled_branch530();
}
void compiled_branch530()
{// compiled_branch530
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch529()
{// primitive_branch529
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call531();
}
void after_call531()
{// after_call531
after_lambda528();
}
void after_lambda528()
{// after_lambda528
define_variable(new SchemeDataType(SchemeDataType::TypeId::Symbol, "no_operands_p"), registers[VAL], registers[ENV]);// (perform (op define_variable) (const no_operands_p) (reg val) (reg env))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "ok"));// (assign val (const ok))
assign(VAL, make_compiled_procedure("ENTRY532", entry532, registers[ENV]));// (assign val (op make_compiled_procedure) (label entry532) (reg env))
goto_with_label("AFTER_LAMBDA533");// (goto (label after_lambda533))

}
void entry532()
{// entry532
assign(ENV, compiled_procedure_env(PROC));// (assign env (op compiled_procedure_env) (reg proc))
assign(ENV, extend_environment(new SchemeDataType(SchemeDataType::TypeId::Symbol, "ops"), registers[ARGL], registers[ENV]));
// (assign env (op extend_environment) (const ops) (reg argl) (reg env))
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "car"), registers[ENV]));// (assign proc (op lookup_variable_value) (const car) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "ops"), registers[ENV]));// (assign val (op lookup_variable_value) (const ops) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH534");
}// (branch (label primitive_branch534))
compiled_branch535();
}
void compiled_branch535()
{// compiled_branch535
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch534()
{// primitive_branch534
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call536();
}
void after_call536()
{// after_call536
after_lambda533();
}
void after_lambda533()
{// after_lambda533
define_variable(new SchemeDataType(SchemeDataType::TypeId::Symbol, "first_operand"), registers[VAL], registers[ENV]);// (perform (op define_variable) (const first_operand) (reg val) (reg env))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "ok"));// (assign val (const ok))
assign(VAL, make_compiled_procedure("ENTRY537", entry537, registers[ENV]));// (assign val (op make_compiled_procedure) (label entry537) (reg env))
goto_with_label("AFTER_LAMBDA538");// (goto (label after_lambda538))

}
void entry537()
{// entry537
assign(ENV, compiled_procedure_env(PROC));// (assign env (op compiled_procedure_env) (reg proc))
assign(ENV, extend_environment(new SchemeDataType(SchemeDataType::TypeId::Symbol, "ops"), registers[ARGL], registers[ENV]));
// (assign env (op extend_environment) (const ops) (reg argl) (reg env))
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "cdr"), registers[ENV]));// (assign proc (op lookup_variable_value) (const cdr) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "ops"), registers[ENV]));// (assign val (op lookup_variable_value) (const ops) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH539");
}// (branch (label primitive_branch539))
compiled_branch540();
}
void compiled_branch540()
{// compiled_branch540
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch539()
{// primitive_branch539
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call541();
}
void after_call541()
{// after_call541
after_lambda538();
}
void after_lambda538()
{// after_lambda538
define_variable(new SchemeDataType(SchemeDataType::TypeId::Symbol, "rest_operands"), registers[VAL], registers[ENV]);// (perform (op define_variable) (const rest_operands) (reg val) (reg env))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "ok"));// (assign val (const ok))
assign(VAL, make_compiled_procedure("ENTRY542", entry542, registers[ENV]));// (assign val (op make_compiled_procedure) (label entry542) (reg env))
goto_with_label("AFTER_LAMBDA543");// (goto (label after_lambda543))

}
void entry542()
{// entry542
assign(ENV, compiled_procedure_env(PROC));// (assign env (op compiled_procedure_env) (reg proc))
assign(ENV, extend_environment(new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp"), registers[ARGL], registers[ENV]));
// (assign env (op extend_environment) (const exp) (reg argl) (reg env))
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "tagged_list_p"), registers[ENV]));// (assign proc (op lookup_variable_value) (const tagged_list_p) (reg env))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "cond"));// (assign val (const cond))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp"), registers[ENV]));// (assign val (op lookup_variable_value) (const exp) (reg env))
assign(ARGL, cons(registers[VAL], registers[ARGL]));// (assign argl (op cons) (reg val) (reg argl))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH544");
}// (branch (label primitive_branch544))
compiled_branch545();
}
void compiled_branch545()
{// compiled_branch545
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch544()
{// primitive_branch544
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call546();
}
void after_call546()
{// after_call546
after_lambda543();
}
void after_lambda543()
{// after_lambda543
define_variable(new SchemeDataType(SchemeDataType::TypeId::Symbol, "cond_p"), registers[VAL], registers[ENV]);// (perform (op define_variable) (const cond_p) (reg val) (reg env))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "ok"));// (assign val (const ok))
assign(VAL, make_compiled_procedure("ENTRY547", entry547, registers[ENV]));// (assign val (op make_compiled_procedure) (label entry547) (reg env))
goto_with_label("AFTER_LAMBDA548");// (goto (label after_lambda548))

}
void entry547()
{// entry547
assign(ENV, compiled_procedure_env(PROC));// (assign env (op compiled_procedure_env) (reg proc))
assign(ENV, extend_environment(new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp"), registers[ARGL], registers[ENV]));
// (assign env (op extend_environment) (const exp) (reg argl) (reg env))
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "cdr"), registers[ENV]));// (assign proc (op lookup_variable_value) (const cdr) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp"), registers[ENV]));// (assign val (op lookup_variable_value) (const exp) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH549");
}// (branch (label primitive_branch549))
compiled_branch550();
}
void compiled_branch550()
{// compiled_branch550
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch549()
{// primitive_branch549
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call551();
}
void after_call551()
{// after_call551
after_lambda548();
}
void after_lambda548()
{// after_lambda548
define_variable(new SchemeDataType(SchemeDataType::TypeId::Symbol, "cond_clauses"), registers[VAL], registers[ENV]);// (perform (op define_variable) (const cond_clauses) (reg val) (reg env))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "ok"));// (assign val (const ok))
assign(VAL, make_compiled_procedure("ENTRY552", entry552, registers[ENV]));// (assign val (op make_compiled_procedure) (label entry552) (reg env))
goto_with_label("AFTER_LAMBDA553");// (goto (label after_lambda553))

}
void entry552()
{// entry552
assign(ENV, compiled_procedure_env(PROC));// (assign env (op compiled_procedure_env) (reg proc))
assign(ENV, extend_environment(new SchemeDataType(SchemeDataType::TypeId::Symbol, "clause"), registers[ARGL], registers[ENV]));
// (assign env (op extend_environment) (const clause) (reg argl) (reg env))
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
s.restore(ARGL);// (restore argl)
assign(ARGL, cons(registers[VAL], registers[ARGL]));// (assign argl (op cons) (reg val) (reg argl))
s.restore(PROC);// (restore proc)
s.restore(CONTINUE);// (restore continue)
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
define_variable(new SchemeDataType(SchemeDataType::TypeId::Symbol, "cond_else_clause_p"), registers[VAL], registers[ENV]);// (perform (op define_variable) (const cond_else_clause_p) (reg val) (reg env))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "ok"));// (assign val (const ok))
assign(VAL, make_compiled_procedure("ENTRY560", entry560, registers[ENV]));// (assign val (op make_compiled_procedure) (label entry560) (reg env))
goto_with_label("AFTER_LAMBDA561");// (goto (label after_lambda561))

}
void entry560()
{// entry560
assign(ENV, compiled_procedure_env(PROC));// (assign env (op compiled_procedure_env) (reg proc))
assign(ENV, extend_environment(new SchemeDataType(SchemeDataType::TypeId::Symbol, "clause"), registers[ARGL], registers[ENV]));
// (assign env (op extend_environment) (const clause) (reg argl) (reg env))
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "car"), registers[ENV]));// (assign proc (op lookup_variable_value) (const car) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "clause"), registers[ENV]));// (assign val (op lookup_variable_value) (const clause) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH562");
}// (branch (label primitive_branch562))
compiled_branch563();
}
void compiled_branch563()
{// compiled_branch563
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch562()
{// primitive_branch562
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call564();
}
void after_call564()
{// after_call564
after_lambda561();
}
void after_lambda561()
{// after_lambda561
define_variable(new SchemeDataType(SchemeDataType::TypeId::Symbol, "cond_predicate"), registers[VAL], registers[ENV]);// (perform (op define_variable) (const cond_predicate) (reg val) (reg env))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "ok"));// (assign val (const ok))
assign(VAL, make_compiled_procedure("ENTRY565", entry565, registers[ENV]));// (assign val (op make_compiled_procedure) (label entry565) (reg env))
goto_with_label("AFTER_LAMBDA566");// (goto (label after_lambda566))

}
void entry565()
{// entry565
assign(ENV, compiled_procedure_env(PROC));// (assign env (op compiled_procedure_env) (reg proc))
assign(ENV, extend_environment(new SchemeDataType(SchemeDataType::TypeId::Symbol, "clause"), registers[ARGL], registers[ENV]));
// (assign env (op extend_environment) (const clause) (reg argl) (reg env))
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "cdr"), registers[ENV]));// (assign proc (op lookup_variable_value) (const cdr) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "clause"), registers[ENV]));// (assign val (op lookup_variable_value) (const clause) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH567");
}// (branch (label primitive_branch567))
compiled_branch568();
}
void compiled_branch568()
{// compiled_branch568
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch567()
{// primitive_branch567
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call569();
}
void after_call569()
{// after_call569
after_lambda566();
}
void after_lambda566()
{// after_lambda566
define_variable(new SchemeDataType(SchemeDataType::TypeId::Symbol, "cond_actions"), registers[VAL], registers[ENV]);// (perform (op define_variable) (const cond_actions) (reg val) (reg env))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "ok"));// (assign val (const ok))
assign(VAL, make_compiled_procedure("ENTRY570", entry570, registers[ENV]));// (assign val (op make_compiled_procedure) (label entry570) (reg env))
goto_with_label("AFTER_LAMBDA571");// (goto (label after_lambda571))

}
void entry570()
{// entry570
assign(ENV, compiled_procedure_env(PROC));// (assign env (op compiled_procedure_env) (reg proc))
assign(ENV, extend_environment(new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp"), registers[ARGL], registers[ENV]));
// (assign env (op extend_environment) (const exp) (reg argl) (reg env))
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "expand_clauses"), registers[ENV]));// (assign proc (op lookup_variable_value) (const expand_clauses) (reg env))
s.save(CONTINUE);// (save continue)
s.save(PROC);// (save proc)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "cond_clauses"), registers[ENV]));// (assign proc (op lookup_variable_value) (const cond_clauses) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp"), registers[ENV]));// (assign val (op lookup_variable_value) (const exp) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH572");
}// (branch (label primitive_branch572))
compiled_branch573();
}
void compiled_branch573()
{// compiled_branch573
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL574"));// (assign continue (label after_call574))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch572()
{// primitive_branch572
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call574();
}
void after_call574()
{// after_call574
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
s.restore(PROC);// (restore proc)
s.restore(CONTINUE);// (restore continue)
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH575");
}// (branch (label primitive_branch575))
compiled_branch576();
}
void compiled_branch576()
{// compiled_branch576
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch575()
{// primitive_branch575
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call577();
}
void after_call577()
{// after_call577
after_lambda571();
}
void after_lambda571()
{// after_lambda571
define_variable(new SchemeDataType(SchemeDataType::TypeId::Symbol, "cond_>if"), registers[VAL], registers[ENV]);// (perform (op define_variable) (const cond_>if) (reg val) (reg env))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "ok"));// (assign val (const ok))
assign(VAL, make_compiled_procedure("ENTRY578", entry578, registers[ENV]));// (assign val (op make_compiled_procedure) (label entry578) (reg env))
goto_with_label("AFTER_LAMBDA579");// (goto (label after_lambda579))

}
void entry578()
{// entry578
assign(ENV, compiled_procedure_env(PROC));// (assign env (op compiled_procedure_env) (reg proc))
assign(ENV, extend_environment(new SchemeDataType(SchemeDataType::TypeId::Symbol, "clauses"), registers[ARGL], registers[ENV]));
// (assign env (op extend_environment) (const clauses) (reg argl) (reg env))
s.save(CONTINUE);// (save continue)
s.save(ENV);// (save env)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "null_p"), registers[ENV]));// (assign proc (op lookup_variable_value) (const null_p) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "clauses"), registers[ENV]));// (assign val (op lookup_variable_value) (const clauses) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH583");
}// (branch (label primitive_branch583))
compiled_branch584();
}
void compiled_branch584()
{// compiled_branch584
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL585"));// (assign continue (label after_call585))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch583()
{// primitive_branch583
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call585();
}
void after_call585()
{// after_call585
s.restore(ENV);// (restore env)
s.restore(CONTINUE);// (restore continue)
if ( false_p(registers[VAL]) ) {// (test (op false_p) (reg val))
return goto_with_label("FALSE_BRANCH581");
}// (branch (label false_branch581))
true_branch580();
}
void true_branch580()
{// true_branch580
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "false"));// (assign val (const false))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))

}
void false_branch581()
{// false_branch581
assign(PROC, make_compiled_procedure("ENTRY586", entry586, registers[ENV]));// (assign proc (op make_compiled_procedure) (label entry586) (reg env))
goto_with_label("AFTER_LAMBDA587");// (goto (label after_lambda587))

}
void entry586()
{// entry586
assign(ENV, compiled_procedure_env(PROC));// (assign env (op compiled_procedure_env) (reg proc))
assign(ENV, extend_environment(new SchemeDataType(SchemeDataType::TypeId::Symbol, "first"), registers[ARGL], registers[ENV]));
assign(ENV, extend_environment(new SchemeDataType(SchemeDataType::TypeId::Symbol, "rest"), registers[ARGL], registers[ENV]));
// (assign env (op extend_environment) (const (first rest)) (reg argl) (reg env))
s.save(CONTINUE);// (save continue)
s.save(ENV);// (save env)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "cond_else_clause_p"), registers[ENV]));// (assign proc (op lookup_variable_value) (const cond_else_clause_p) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "first"), registers[ENV]));// (assign val (op lookup_variable_value) (const first) (reg env))
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
if ( false_p(registers[VAL]) ) {// (test (op false_p) (reg val))
return goto_with_label("FALSE_BRANCH589");
}// (branch (label false_branch589))
true_branch588();
}
void true_branch588()
{// true_branch588
s.save(CONTINUE);// (save continue)
s.save(ENV);// (save env)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "null_p"), registers[ENV]));// (assign proc (op lookup_variable_value) (const null_p) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "rest"), registers[ENV]));// (assign val (op lookup_variable_value) (const rest) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH597");
}// (branch (label primitive_branch597))
compiled_branch598();
}
void compiled_branch598()
{// compiled_branch598
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL599"));// (assign continue (label after_call599))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch597()
{// primitive_branch597
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call599();
}
void after_call599()
{// after_call599
s.restore(ENV);// (restore env)
s.restore(CONTINUE);// (restore continue)
if ( false_p(registers[VAL]) ) {// (test (op false_p) (reg val))
return goto_with_label("FALSE_BRANCH595");
}// (branch (label false_branch595))
true_branch594();
}
void true_branch594()
{// true_branch594
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "sequence_>exp"), registers[ENV]));// (assign proc (op lookup_variable_value) (const sequence_>exp) (reg env))
s.save(CONTINUE);// (save continue)
s.save(PROC);// (save proc)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "cond_actions"), registers[ENV]));// (assign proc (op lookup_variable_value) (const cond_actions) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "first"), registers[ENV]));// (assign val (op lookup_variable_value) (const first) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH600");
}// (branch (label primitive_branch600))
compiled_branch601();
}
void compiled_branch601()
{// compiled_branch601
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL602"));// (assign continue (label after_call602))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch600()
{// primitive_branch600
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call602();
}
void after_call602()
{// after_call602
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
s.restore(PROC);// (restore proc)
s.restore(CONTINUE);// (restore continue)
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH603");
}// (branch (label primitive_branch603))
compiled_branch604();
}
void compiled_branch604()
{// compiled_branch604
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch603()
{// primitive_branch603
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call605();
}
void after_call605()
{// after_call605

}
void false_branch595()
{// false_branch595
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "error"), registers[ENV]));// (assign proc (op lookup_variable_value) (const error) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "clauses"), registers[ENV]));// (assign val (op lookup_variable_value) (const clauses) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "ELSE clause isn't last __ COND_>IF"));// (assign val (const ELSE clause isn't last __ COND_>IF))
assign(ARGL, cons(registers[VAL], registers[ARGL]));// (assign argl (op cons) (reg val) (reg argl))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH606");
}// (branch (label primitive_branch606))
compiled_branch607();
}
void compiled_branch607()
{// compiled_branch607
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch606()
{// primitive_branch606
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call608();
}
void after_call608()
{// after_call608
after_if596();
}
void after_if596()
{// after_if596

}
void false_branch589()
{// false_branch589
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "make_if"), registers[ENV]));// (assign proc (op lookup_variable_value) (const make_if) (reg env))
s.save(CONTINUE);// (save continue)
s.save(PROC);// (save proc)
s.save(ENV);// (save env)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "expand_clauses"), registers[ENV]));// (assign proc (op lookup_variable_value) (const expand_clauses) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "rest"), registers[ENV]));// (assign val (op lookup_variable_value) (const rest) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH618");
}// (branch (label primitive_branch618))
compiled_branch619();
}
void compiled_branch619()
{// compiled_branch619
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL620"));// (assign continue (label after_call620))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch618()
{// primitive_branch618
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call620();
}
void after_call620()
{// after_call620
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
return goto_with_label("PRIMITIVE_BRANCH612");
}// (branch (label primitive_branch612))
compiled_branch613();
}
void compiled_branch613()
{// compiled_branch613
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL614"));// (assign continue (label after_call614))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch612()
{// primitive_branch612
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call614();
}
void after_call614()
{// after_call614
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
s.restore(PROC);// (restore proc)
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH615");
}// (branch (label primitive_branch615))
compiled_branch616();
}
void compiled_branch616()
{// compiled_branch616
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL617"));// (assign continue (label after_call617))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch615()
{// primitive_branch615
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call617();
}
void after_call617()
{// after_call617
s.restore(ARGL);// (restore argl)
assign(ARGL, cons(registers[VAL], registers[ARGL]));// (assign argl (op cons) (reg val) (reg argl))
s.restore(ENV);// (restore env)
s.save(ARGL);// (save argl)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "cond_predicate"), registers[ENV]));// (assign proc (op lookup_variable_value) (const cond_predicate) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "first"), registers[ENV]));// (assign val (op lookup_variable_value) (const first) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH609");
}// (branch (label primitive_branch609))
compiled_branch610();
}
void compiled_branch610()
{// compiled_branch610
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL611"));// (assign continue (label after_call611))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch609()
{// primitive_branch609
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call611();
}
void after_call611()
{// after_call611
s.restore(ARGL);// (restore argl)
assign(ARGL, cons(registers[VAL], registers[ARGL]));// (assign argl (op cons) (reg val) (reg argl))
s.restore(PROC);// (restore proc)
s.restore(CONTINUE);// (restore continue)
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH621");
}// (branch (label primitive_branch621))
compiled_branch622();
}
void compiled_branch622()
{// compiled_branch622
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch621()
{// primitive_branch621
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call623();
}
void after_call623()
{// after_call623
after_if590();
}
void after_if590()
{// after_if590
after_lambda587();
}
void after_lambda587()
{// after_lambda587
s.save(CONTINUE);// (save continue)
s.save(PROC);// (save proc)
s.save(ENV);// (save env)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "cdr"), registers[ENV]));// (assign proc (op lookup_variable_value) (const cdr) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "clauses"), registers[ENV]));// (assign val (op lookup_variable_value) (const clauses) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH627");
}// (branch (label primitive_branch627))
compiled_branch628();
}
void compiled_branch628()
{// compiled_branch628
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL629"));// (assign continue (label after_call629))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch627()
{// primitive_branch627
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call629();
}
void after_call629()
{// after_call629
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
s.restore(ENV);// (restore env)
s.save(ARGL);// (save argl)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "car"), registers[ENV]));// (assign proc (op lookup_variable_value) (const car) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "clauses"), registers[ENV]));// (assign val (op lookup_variable_value) (const clauses) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH624");
}// (branch (label primitive_branch624))
compiled_branch625();
}
void compiled_branch625()
{// compiled_branch625
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL626"));// (assign continue (label after_call626))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch624()
{// primitive_branch624
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call626();
}
void after_call626()
{// after_call626
s.restore(ARGL);// (restore argl)
assign(ARGL, cons(registers[VAL], registers[ARGL]));// (assign argl (op cons) (reg val) (reg argl))
s.restore(PROC);// (restore proc)
s.restore(CONTINUE);// (restore continue)
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH630");
}// (branch (label primitive_branch630))
compiled_branch631();
}
void compiled_branch631()
{// compiled_branch631
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch630()
{// primitive_branch630
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call632();
}
void after_call632()
{// after_call632
after_if582();
}
void after_if582()
{// after_if582
after_lambda579();
}
void after_lambda579()
{// after_lambda579
define_variable(new SchemeDataType(SchemeDataType::TypeId::Symbol, "expand_clauses"), registers[VAL], registers[ENV]);// (perform (op define_variable) (const expand_clauses) (reg val) (reg env))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "ok"));// (assign val (const ok))
assign(VAL, make_compiled_procedure("ENTRY633", entry633, registers[ENV]));// (assign val (op make_compiled_procedure) (label entry633) (reg env))
goto_with_label("AFTER_LAMBDA634");// (goto (label after_lambda634))

}
void entry633()
{// entry633
assign(ENV, compiled_procedure_env(PROC));// (assign env (op compiled_procedure_env) (reg proc))
assign(ENV, extend_environment(new SchemeDataType(SchemeDataType::TypeId::Symbol, "parameters"), registers[ARGL], registers[ENV]));
assign(ENV, extend_environment(new SchemeDataType(SchemeDataType::TypeId::Symbol, "body"), registers[ARGL], registers[ENV]));
assign(ENV, extend_environment(new SchemeDataType(SchemeDataType::TypeId::Symbol, "env"), registers[ARGL], registers[ENV]));
// (assign env (op extend_environment) (const (parameters body env)) (reg argl) (reg env))
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
return goto_with_label("PRIMITIVE_BRANCH635");
}// (branch (label primitive_branch635))
compiled_branch636();
}
void compiled_branch636()
{// compiled_branch636
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch635()
{// primitive_branch635
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call637();
}
void after_call637()
{// after_call637
after_lambda634();
}
void after_lambda634()
{// after_lambda634
define_variable(new SchemeDataType(SchemeDataType::TypeId::Symbol, "make_procedure"), registers[VAL], registers[ENV]);// (perform (op define_variable) (const make_procedure) (reg val) (reg env))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "ok"));// (assign val (const ok))
assign(VAL, make_compiled_procedure("ENTRY638", entry638, registers[ENV]));// (assign val (op make_compiled_procedure) (label entry638) (reg env))
goto_with_label("AFTER_LAMBDA639");// (goto (label after_lambda639))

}
void entry638()
{// entry638
assign(ENV, compiled_procedure_env(PROC));// (assign env (op compiled_procedure_env) (reg proc))
assign(ENV, extend_environment(new SchemeDataType(SchemeDataType::TypeId::Symbol, "p"), registers[ARGL], registers[ENV]));
// (assign env (op extend_environment) (const p) (reg argl) (reg env))
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "tagged_list_p"), registers[ENV]));// (assign proc (op lookup_variable_value) (const tagged_list_p) (reg env))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "procedure"));// (assign val (const procedure))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "p"), registers[ENV]));// (assign val (op lookup_variable_value) (const p) (reg env))
assign(ARGL, cons(registers[VAL], registers[ARGL]));// (assign argl (op cons) (reg val) (reg argl))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH640");
}// (branch (label primitive_branch640))
compiled_branch641();
}
void compiled_branch641()
{// compiled_branch641
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch640()
{// primitive_branch640
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call642();
}
void after_call642()
{// after_call642
after_lambda639();
}
void after_lambda639()
{// after_lambda639
define_variable(new SchemeDataType(SchemeDataType::TypeId::Symbol, "compound_procedure_p"), registers[VAL], registers[ENV]);// (perform (op define_variable) (const compound_procedure_p) (reg val) (reg env))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "ok"));// (assign val (const ok))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, ";;; M_Eval input:"));// (assign val (const ;;; M_Eval input:))
define_variable(new SchemeDataType(SchemeDataType::TypeId::Symbol, "input_prompt"), registers[VAL], registers[ENV]);// (perform (op define_variable) (const input_prompt) (reg val) (reg env))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "ok"));// (assign val (const ok))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, ";;; M_Eval value:"));// (assign val (const ;;; M_Eval value:))
define_variable(new SchemeDataType(SchemeDataType::TypeId::Symbol, "output_prompt"), registers[VAL], registers[ENV]);// (perform (op define_variable) (const output_prompt) (reg val) (reg env))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "ok"));// (assign val (const ok))
assign(VAL, make_compiled_procedure("ENTRY643", entry643, registers[ENV]));// (assign val (op make_compiled_procedure) (label entry643) (reg env))
goto_with_label("AFTER_LAMBDA644");// (goto (label after_lambda644))

}
void entry643()
{// entry643
assign(ENV, compiled_procedure_env(PROC));// (assign env (op compiled_procedure_env) (reg proc))
assign(ENV, extend_environment(new SchemeDataType(SchemeDataType::TypeId::Nil), registers[ARGL], registers[ENV]));
// (assign env (op extend_environment) (const nil ) (reg argl) (reg env))
s.save(CONTINUE);// (save continue)
s.save(ENV);// (save env)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "prompt_for_input"), registers[ENV]));// (assign proc (op lookup_variable_value) (const prompt_for_input) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "input_prompt"), registers[ENV]));// (assign val (op lookup_variable_value) (const input_prompt) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH645");
}// (branch (label primitive_branch645))
compiled_branch646();
}
void compiled_branch646()
{// compiled_branch646
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL647"));// (assign continue (label after_call647))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch645()
{// primitive_branch645
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call647();
}
void after_call647()
{// after_call647
s.restore(ENV);// (restore env)
s.restore(CONTINUE);// (restore continue)
assign(PROC, make_compiled_procedure("ENTRY648", entry648, registers[ENV]));// (assign proc (op make_compiled_procedure) (label entry648) (reg env))
goto_with_label("AFTER_LAMBDA649");// (goto (label after_lambda649))

}
void entry648()
{// entry648
assign(ENV, compiled_procedure_env(PROC));// (assign env (op compiled_procedure_env) (reg proc))
assign(ENV, extend_environment(new SchemeDataType(SchemeDataType::TypeId::Symbol, "input"), registers[ARGL], registers[ENV]));
// (assign env (op extend_environment) (const input) (reg argl) (reg env))
assign(PROC, make_compiled_procedure("ENTRY650", entry650, registers[ENV]));// (assign proc (op make_compiled_procedure) (label entry650) (reg env))
goto_with_label("AFTER_LAMBDA651");// (goto (label after_lambda651))

}
void entry650()
{// entry650
assign(ENV, compiled_procedure_env(PROC));// (assign env (op compiled_procedure_env) (reg proc))
assign(ENV, extend_environment(new SchemeDataType(SchemeDataType::TypeId::Symbol, "output"), registers[ARGL], registers[ENV]));
// (assign env (op extend_environment) (const output) (reg argl) (reg env))
s.save(CONTINUE);// (save continue)
s.save(ENV);// (save env)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "announce_output"), registers[ENV]));// (assign proc (op lookup_variable_value) (const announce_output) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "output_prompt"), registers[ENV]));// (assign val (op lookup_variable_value) (const output_prompt) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH652");
}// (branch (label primitive_branch652))
compiled_branch653();
}
void compiled_branch653()
{// compiled_branch653
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL654"));// (assign continue (label after_call654))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch652()
{// primitive_branch652
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call654();
}
void after_call654()
{// after_call654
s.restore(ENV);// (restore env)
s.restore(CONTINUE);// (restore continue)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "user_print"), registers[ENV]));// (assign proc (op lookup_variable_value) (const user_print) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "output"), registers[ENV]));// (assign val (op lookup_variable_value) (const output) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH655");
}// (branch (label primitive_branch655))
compiled_branch656();
}
void compiled_branch656()
{// compiled_branch656
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch655()
{// primitive_branch655
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call657();
}
void after_call657()
{// after_call657
after_lambda651();
}
void after_lambda651()
{// after_lambda651
s.save(CONTINUE);// (save continue)
s.save(PROC);// (save proc)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "eval"), registers[ENV]));// (assign proc (op lookup_variable_value) (const eval) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "the_global_environment"), registers[ENV]));// (assign val (op lookup_variable_value) (const the_global_environment) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "input"), registers[ENV]));// (assign val (op lookup_variable_value) (const input) (reg env))
assign(ARGL, cons(registers[VAL], registers[ARGL]));// (assign argl (op cons) (reg val) (reg argl))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH658");
}// (branch (label primitive_branch658))
compiled_branch659();
}
void compiled_branch659()
{// compiled_branch659
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL660"));// (assign continue (label after_call660))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch658()
{// primitive_branch658
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call660();
}
void after_call660()
{// after_call660
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
s.restore(PROC);// (restore proc)
s.restore(CONTINUE);// (restore continue)
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH661");
}// (branch (label primitive_branch661))
compiled_branch662();
}
void compiled_branch662()
{// compiled_branch662
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch661()
{// primitive_branch661
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call663();
}
void after_call663()
{// after_call663
after_lambda649();
}
void after_lambda649()
{// after_lambda649
s.save(CONTINUE);// (save continue)
s.save(PROC);// (save proc)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "read"), registers[ENV]));// (assign proc (op lookup_variable_value) (const read) (reg env))
assign(ARGL, new SchemeDataType(SchemeDataType::TypeId::Nil));// (assign argl (const nil ))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH664");
}// (branch (label primitive_branch664))
compiled_branch665();
}
void compiled_branch665()
{// compiled_branch665
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL666"));// (assign continue (label after_call666))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch664()
{// primitive_branch664
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call666();
}
void after_call666()
{// after_call666
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
s.restore(PROC);// (restore proc)
s.restore(CONTINUE);// (restore continue)
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH667");
}// (branch (label primitive_branch667))
compiled_branch668();
}
void compiled_branch668()
{// compiled_branch668
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch667()
{// primitive_branch667
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call669();
}
void after_call669()
{// after_call669
after_lambda644();
}
void after_lambda644()
{// after_lambda644
define_variable(new SchemeDataType(SchemeDataType::TypeId::Symbol, "driver_loop"), registers[VAL], registers[ENV]);// (perform (op define_variable) (const driver_loop) (reg val) (reg env))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "ok"));// (assign val (const ok))
assign(VAL, make_compiled_procedure("ENTRY670", entry670, registers[ENV]));// (assign val (op make_compiled_procedure) (label entry670) (reg env))
goto_with_label("AFTER_LAMBDA671");// (goto (label after_lambda671))

}
void entry670()
{// entry670
assign(ENV, compiled_procedure_env(PROC));// (assign env (op compiled_procedure_env) (reg proc))
assign(ENV, extend_environment(new SchemeDataType(SchemeDataType::TypeId::Symbol, "string"), registers[ARGL], registers[ENV]));
// (assign env (op extend_environment) (const string) (reg argl) (reg env))
s.save(CONTINUE);// (save continue)
s.save(ENV);// (save env)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "newline"), registers[ENV]));// (assign proc (op lookup_variable_value) (const newline) (reg env))
assign(ARGL, new SchemeDataType(SchemeDataType::TypeId::Nil));// (assign argl (const nil ))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH672");
}// (branch (label primitive_branch672))
compiled_branch673();
}
void compiled_branch673()
{// compiled_branch673
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL674"));// (assign continue (label after_call674))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch672()
{// primitive_branch672
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call674();
}
void after_call674()
{// after_call674
s.restore(ENV);// (restore env)
s.restore(CONTINUE);// (restore continue)
s.save(CONTINUE);// (save continue)
s.save(ENV);// (save env)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "newline"), registers[ENV]));// (assign proc (op lookup_variable_value) (const newline) (reg env))
assign(ARGL, new SchemeDataType(SchemeDataType::TypeId::Nil));// (assign argl (const nil ))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH675");
}// (branch (label primitive_branch675))
compiled_branch676();
}
void compiled_branch676()
{// compiled_branch676
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL677"));// (assign continue (label after_call677))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch675()
{// primitive_branch675
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call677();
}
void after_call677()
{// after_call677
s.restore(ENV);// (restore env)
s.restore(CONTINUE);// (restore continue)
s.save(CONTINUE);// (save continue)
s.save(ENV);// (save env)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "display"), registers[ENV]));// (assign proc (op lookup_variable_value) (const display) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "string"), registers[ENV]));// (assign val (op lookup_variable_value) (const string) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH678");
}// (branch (label primitive_branch678))
compiled_branch679();
}
void compiled_branch679()
{// compiled_branch679
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL680"));// (assign continue (label after_call680))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch678()
{// primitive_branch678
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call680();
}
void after_call680()
{// after_call680
s.restore(ENV);// (restore env)
s.restore(CONTINUE);// (restore continue)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "newline"), registers[ENV]));// (assign proc (op lookup_variable_value) (const newline) (reg env))
assign(ARGL, new SchemeDataType(SchemeDataType::TypeId::Nil));// (assign argl (const nil ))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH681");
}// (branch (label primitive_branch681))
compiled_branch682();
}
void compiled_branch682()
{// compiled_branch682
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch681()
{// primitive_branch681
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call683();
}
void after_call683()
{// after_call683
after_lambda671();
}
void after_lambda671()
{// after_lambda671
define_variable(new SchemeDataType(SchemeDataType::TypeId::Symbol, "prompt_for_input"), registers[VAL], registers[ENV]);// (perform (op define_variable) (const prompt_for_input) (reg val) (reg env))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "ok"));// (assign val (const ok))
assign(VAL, make_compiled_procedure("ENTRY684", entry684, registers[ENV]));// (assign val (op make_compiled_procedure) (label entry684) (reg env))
goto_with_label("AFTER_LAMBDA685");// (goto (label after_lambda685))

}
void entry684()
{// entry684
assign(ENV, compiled_procedure_env(PROC));// (assign env (op compiled_procedure_env) (reg proc))
assign(ENV, extend_environment(new SchemeDataType(SchemeDataType::TypeId::Symbol, "string"), registers[ARGL], registers[ENV]));
// (assign env (op extend_environment) (const string) (reg argl) (reg env))
s.save(CONTINUE);// (save continue)
s.save(ENV);// (save env)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "newline"), registers[ENV]));// (assign proc (op lookup_variable_value) (const newline) (reg env))
assign(ARGL, new SchemeDataType(SchemeDataType::TypeId::Nil));// (assign argl (const nil ))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH686");
}// (branch (label primitive_branch686))
compiled_branch687();
}
void compiled_branch687()
{// compiled_branch687
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL688"));// (assign continue (label after_call688))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch686()
{// primitive_branch686
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call688();
}
void after_call688()
{// after_call688
s.restore(ENV);// (restore env)
s.restore(CONTINUE);// (restore continue)
s.save(CONTINUE);// (save continue)
s.save(ENV);// (save env)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "display"), registers[ENV]));// (assign proc (op lookup_variable_value) (const display) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "string"), registers[ENV]));// (assign val (op lookup_variable_value) (const string) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH689");
}// (branch (label primitive_branch689))
compiled_branch690();
}
void compiled_branch690()
{// compiled_branch690
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL691"));// (assign continue (label after_call691))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch689()
{// primitive_branch689
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call691();
}
void after_call691()
{// after_call691
s.restore(ENV);// (restore env)
s.restore(CONTINUE);// (restore continue)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "newline"), registers[ENV]));// (assign proc (op lookup_variable_value) (const newline) (reg env))
assign(ARGL, new SchemeDataType(SchemeDataType::TypeId::Nil));// (assign argl (const nil ))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH692");
}// (branch (label primitive_branch692))
compiled_branch693();
}
void compiled_branch693()
{// compiled_branch693
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch692()
{// primitive_branch692
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call694();
}
void after_call694()
{// after_call694
after_lambda685();
}
void after_lambda685()
{// after_lambda685
define_variable(new SchemeDataType(SchemeDataType::TypeId::Symbol, "announce_output"), registers[VAL], registers[ENV]);// (perform (op define_variable) (const announce_output) (reg val) (reg env))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "ok"));// (assign val (const ok))
assign(VAL, make_compiled_procedure("ENTRY695", entry695, registers[ENV]));// (assign val (op make_compiled_procedure) (label entry695) (reg env))
goto_with_label("AFTER_LAMBDA696");// (goto (label after_lambda696))

}
void entry695()
{// entry695
assign(ENV, compiled_procedure_env(PROC));// (assign env (op compiled_procedure_env) (reg proc))
assign(ENV, extend_environment(new SchemeDataType(SchemeDataType::TypeId::Symbol, "object"), registers[ARGL], registers[ENV]));
// (assign env (op extend_environment) (const object) (reg argl) (reg env))
s.save(CONTINUE);// (save continue)
s.save(ENV);// (save env)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "compound_procedure_p"), registers[ENV]));// (assign proc (op lookup_variable_value) (const compound_procedure_p) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "object"), registers[ENV]));// (assign val (op lookup_variable_value) (const object) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH700");
}// (branch (label primitive_branch700))
compiled_branch701();
}
void compiled_branch701()
{// compiled_branch701
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL702"));// (assign continue (label after_call702))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch700()
{// primitive_branch700
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call702();
}
void after_call702()
{// after_call702
s.restore(ENV);// (restore env)
s.restore(CONTINUE);// (restore continue)
if ( false_p(registers[VAL]) ) {// (test (op false_p) (reg val))
return goto_with_label("FALSE_BRANCH698");
}// (branch (label false_branch698))
true_branch697();
}
void true_branch697()
{// true_branch697
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
return goto_with_label("PRIMITIVE_BRANCH706");
}// (branch (label primitive_branch706))
compiled_branch707();
}
void compiled_branch707()
{// compiled_branch707
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL708"));// (assign continue (label after_call708))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch706()
{// primitive_branch706
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call708();
}
void after_call708()
{// after_call708
s.restore(ARGL);// (restore argl)
assign(ARGL, cons(registers[VAL], registers[ARGL]));// (assign argl (op cons) (reg val) (reg argl))
s.restore(ENV);// (restore env)
s.save(ARGL);// (save argl)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "procedure_parameters"), registers[ENV]));// (assign proc (op lookup_variable_value) (const procedure_parameters) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "object"), registers[ENV]));// (assign val (op lookup_variable_value) (const object) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH703");
}// (branch (label primitive_branch703))
compiled_branch704();
}
void compiled_branch704()
{// compiled_branch704
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL705"));// (assign continue (label after_call705))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch703()
{// primitive_branch703
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call705();
}
void after_call705()
{// after_call705
s.restore(ARGL);// (restore argl)
assign(ARGL, cons(registers[VAL], registers[ARGL]));// (assign argl (op cons) (reg val) (reg argl))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "compound_procedure"));// (assign val (const compound_procedure))
assign(ARGL, cons(registers[VAL], registers[ARGL]));// (assign argl (op cons) (reg val) (reg argl))
s.restore(PROC);// (restore proc)
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH709");
}// (branch (label primitive_branch709))
compiled_branch710();
}
void compiled_branch710()
{// compiled_branch710
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL711"));// (assign continue (label after_call711))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch709()
{// primitive_branch709
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call711();
}
void after_call711()
{// after_call711
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
s.restore(PROC);// (restore proc)
s.restore(CONTINUE);// (restore continue)
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH712");
}// (branch (label primitive_branch712))
compiled_branch713();
}
void compiled_branch713()
{// compiled_branch713
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch712()
{// primitive_branch712
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call714();
}
void after_call714()
{// after_call714

}
void false_branch698()
{// false_branch698
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "display"), registers[ENV]));// (assign proc (op lookup_variable_value) (const display) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "object"), registers[ENV]));// (assign val (op lookup_variable_value) (const object) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH715");
}// (branch (label primitive_branch715))
compiled_branch716();
}
void compiled_branch716()
{// compiled_branch716
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch715()
{// primitive_branch715
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call717();
}
void after_call717()
{// after_call717
after_if699();
}
void after_if699()
{// after_if699
after_lambda696();
}
void after_lambda696()
{// after_lambda696
define_variable(new SchemeDataType(SchemeDataType::TypeId::Symbol, "user_print"), registers[VAL], registers[ENV]);// (perform (op define_variable) (const user_print) (reg val) (reg env))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "ok"));// (assign val (const ok))
}
