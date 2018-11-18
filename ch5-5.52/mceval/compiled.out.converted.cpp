void compiled_procedure_start(){
assign(VAL, make_compiled_procedure("ENTRY42", entry42, registers[ENV]));// (assign val (op make_compiled_procedure) (label entry42) (reg env))
goto_with_label("AFTER_LAMBDA43");// (goto (label after_lambda43))

}
void entry42()
{// entry42
assign(ENV, compiled_procedure_env(PROC));// (assign env (op compiled_procedure_env) (reg proc))
assign(ENV, extend_environment(list(2, new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp"), new SchemeDataType(SchemeDataType::TypeId::Symbol, "env")), registers[ARGL], registers[ENV]));// (assign env (op extend_environment) (const (exp env)) (reg argl) (reg env))
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
assign(ENV, extend_environment(list(2, new SchemeDataType(SchemeDataType::TypeId::Symbol, "procedure"), new SchemeDataType(SchemeDataType::TypeId::Symbol, "arguments")), registers[ARGL], registers[ENV]));// (assign env (op extend_environment) (const (procedure arguments)) (reg argl) (reg env))
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
assign(ENV, extend_environment(list(2, new SchemeDataType(SchemeDataType::TypeId::Symbol, "exps"), new SchemeDataType(SchemeDataType::TypeId::Symbol, "env")), registers[ARGL], registers[ENV]));// (assign env (op extend_environment) (const (exps env)) (reg argl) (reg env))
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
assign(ENV, extend_environment(list(2, new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp"), new SchemeDataType(SchemeDataType::TypeId::Symbol, "env")), registers[ARGL], registers[ENV]));// (assign env (op extend_environment) (const (exp env)) (reg argl) (reg env))
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
assign(ENV, extend_environment(list(2, new SchemeDataType(SchemeDataType::TypeId::Symbol, "exps"), new SchemeDataType(SchemeDataType::TypeId::Symbol, "env")), registers[ARGL], registers[ENV]));// (assign env (op extend_environment) (const (exps env)) (reg argl) (reg env))
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
assign(ENV, extend_environment(list(2, new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp"), new SchemeDataType(SchemeDataType::TypeId::Symbol, "env")), registers[ARGL], registers[ENV]));// (assign env (op extend_environment) (const (exp env)) (reg argl) (reg env))
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
assign(ENV, extend_environment(list(2, new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp"), new SchemeDataType(SchemeDataType::TypeId::Symbol, "env")), registers[ARGL], registers[ENV]));// (assign env (op extend_environment) (const (exp env)) (reg argl) (reg env))
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
assign(ENV, extend_environment(list(1, new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp")), registers[ARGL], registers[ENV]));// (assign env (op extend_environment) (const exp) (reg argl) (reg env))
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
assign(ENV, extend_environment(list(1, new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp")), registers[ARGL], registers[ENV]));// (assign env (op extend_environment) (const exp) (reg argl) (reg env))
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
assign(ENV, extend_environment(list(1, new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp")), registers[ARGL], registers[ENV]));// (assign env (op extend_environment) (const exp) (reg argl) (reg env))
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
assign(ENV, extend_environment(list(2, new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp"), new SchemeDataType(SchemeDataType::TypeId::Symbol, "tag")), registers[ARGL], registers[ENV]));// (assign env (op extend_environment) (const (exp tag)) (reg argl) (reg env))
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
assign(ENV, extend_environment(list(1, new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp")), registers[ARGL], registers[ENV]));// (assign env (op extend_environment) (const exp) (reg argl) (reg env))
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
assign(ENV, extend_environment(list(1, new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp")), registers[ARGL], registers[ENV]));// (assign env (op extend_environment) (const exp) (reg argl) (reg env))
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
assign(ENV, extend_environment(list(1, new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp")), registers[ARGL], registers[ENV]));// (assign env (op extend_environment) (const exp) (reg argl) (reg env))
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
assign(ENV, extend_environment(list(1, new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp")), registers[ARGL], registers[ENV]));// (assign env (op extend_environment) (const exp) (reg argl) (reg env))
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
assign(ENV, extend_environment(list(1, new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp")), registers[ARGL], registers[ENV]));// (assign env (op extend_environment) (const exp) (reg argl) (reg env))
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
assign(ENV, extend_environment(list(1, new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp")), registers[ARGL], registers[ENV]));// (assign env (op extend_environment) (const exp) (reg argl) (reg env))
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
assign(ENV, extend_environment(list(1, new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp")), registers[ARGL], registers[ENV]));// (assign env (op extend_environment) (const exp) (reg argl) (reg env))
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
assign(ENV, extend_environment(list(1, new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp")), registers[ARGL], registers[ENV]));// (assign env (op extend_environment) (const exp) (reg argl) (reg env))
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
assign(ENV, extend_environment(list(1, new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp")), registers[ARGL], registers[ENV]));// (assign env (op extend_environment) (const exp) (reg argl) (reg env))
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
assign(ENV, extend_environment(list(1, new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp")), registers[ARGL], registers[ENV]));// (assign env (op extend_environment) (const exp) (reg argl) (reg env))
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
assign(ENV, extend_environment(list(2, new SchemeDataType(SchemeDataType::TypeId::Symbol, "parameters"), new SchemeDataType(SchemeDataType::TypeId::Symbol, "body")), registers[ARGL], registers[ENV]));// (assign env (op extend_environment) (const (parameters body)) (reg argl) (reg env))
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
assign(ENV, extend_environment(list(1, new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp")), registers[ARGL], registers[ENV]));// (assign env (op extend_environment) (const exp) (reg argl) (reg env))
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
assign(ENV, extend_environment(list(1, new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp")), registers[ARGL], registers[ENV]));// (assign env (op extend_environment) (const exp) (reg argl) (reg env))
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
assign(ENV, extend_environment(list(1, new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp")), registers[ARGL], registers[ENV]));// (assign env (op extend_environment) (const exp) (reg argl) (reg env))
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
assign(ENV, extend_environment(list(1, new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp")), registers[ARGL], registers[ENV]));// (assign env (op extend_environment) (const exp) (reg argl) (reg env))
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
assign(ENV, extend_environment(list(3, new SchemeDataType(SchemeDataType::TypeId::Symbol, "predicate"), new SchemeDataType(SchemeDataType::TypeId::Symbol, "consequent"), new SchemeDataType(SchemeDataType::TypeId::Symbol, "alternative")), registers[ARGL], registers[ENV]));// (assign env (op extend_environment) (const (predicate consequent alternative)) (reg argl) (reg env))
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
assign(ENV, extend_environment(list(1, new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp")), registers[ARGL], registers[ENV]));// (assign env (op extend_environment) (const exp) (reg argl) (reg env))
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
assign(ENV, extend_environment(list(1, new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp")), registers[ARGL], registers[ENV]));// (assign env (op extend_environment) (const exp) (reg argl) (reg env))
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
assign(ENV, extend_environment(list(1, new SchemeDataType(SchemeDataType::TypeId::Symbol, "seq")), registers[ARGL], registers[ENV]));// (assign env (op extend_environment) (const seq) (reg argl) (reg env))
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
assign(ENV, extend_environment(list(1, new SchemeDataType(SchemeDataType::TypeId::Symbol, "seq")), registers[ARGL], registers[ENV]));// (assign env (op extend_environment) (const seq) (reg argl) (reg env))
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
assign(ENV, extend_environment(list(1, new SchemeDataType(SchemeDataType::TypeId::Symbol, "seq")), registers[ARGL], registers[ENV]));// (assign env (op extend_environment) (const seq) (reg argl) (reg env))
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
assign(ENV, extend_environment(list(1, new SchemeDataType(SchemeDataType::TypeId::Symbol, "seq")), registers[ARGL], registers[ENV]));// (assign env (op extend_environment) (const seq) (reg argl) (reg env))
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
assign(ENV, extend_environment(list(1, new SchemeDataType(SchemeDataType::TypeId::Symbol, "seq")), registers[ARGL], registers[ENV]));// (assign env (op extend_environment) (const seq) (reg argl) (reg env))
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
assign(ENV, extend_environment(list(1, new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp")), registers[ARGL], registers[ENV]));// (assign env (op extend_environment) (const exp) (reg argl) (reg env))
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
assign(ENV, extend_environment(list(1, new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp")), registers[ARGL], registers[ENV]));// (assign env (op extend_environment) (const exp) (reg argl) (reg env))
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
assign(ENV, extend_environment(list(1, new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp")), registers[ARGL], registers[ENV]));// (assign env (op extend_environment) (const exp) (reg argl) (reg env))
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
assign(ENV, extend_environment(list(1, new SchemeDataType(SchemeDataType::TypeId::Symbol, "ops")), registers[ARGL], registers[ENV]));// (assign env (op extend_environment) (const ops) (reg argl) (reg env))
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
assign(ENV, extend_environment(list(1, new SchemeDataType(SchemeDataType::TypeId::Symbol, "ops")), registers[ARGL], registers[ENV]));// (assign env (op extend_environment) (const ops) (reg argl) (reg env))
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
assign(ENV, extend_environment(list(1, new SchemeDataType(SchemeDataType::TypeId::Symbol, "ops")), registers[ARGL], registers[ENV]));// (assign env (op extend_environment) (const ops) (reg argl) (reg env))
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
assign(ENV, extend_environment(list(1, new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp")), registers[ARGL], registers[ENV]));// (assign env (op extend_environment) (const exp) (reg argl) (reg env))
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
assign(ENV, extend_environment(list(1, new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp")), registers[ARGL], registers[ENV]));// (assign env (op extend_environment) (const exp) (reg argl) (reg env))
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
assign(ENV, extend_environment(list(1, new SchemeDataType(SchemeDataType::TypeId::Symbol, "clause")), registers[ARGL], registers[ENV]));// (assign env (op extend_environment) (const clause) (reg argl) (reg env))
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
assign(ENV, extend_environment(list(1, new SchemeDataType(SchemeDataType::TypeId::Symbol, "clause")), registers[ARGL], registers[ENV]));// (assign env (op extend_environment) (const clause) (reg argl) (reg env))
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
assign(ENV, extend_environment(list(1, new SchemeDataType(SchemeDataType::TypeId::Symbol, "clause")), registers[ARGL], registers[ENV]));// (assign env (op extend_environment) (const clause) (reg argl) (reg env))
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
assign(ENV, extend_environment(list(1, new SchemeDataType(SchemeDataType::TypeId::Symbol, "exp")), registers[ARGL], registers[ENV]));// (assign env (op extend_environment) (const exp) (reg argl) (reg env))
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
assign(ENV, extend_environment(list(1, new SchemeDataType(SchemeDataType::TypeId::Symbol, "clauses")), registers[ARGL], registers[ENV]));// (assign env (op extend_environment) (const clauses) (reg argl) (reg env))
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
assign(ENV, extend_environment(list(2, new SchemeDataType(SchemeDataType::TypeId::Symbol, "first"), new SchemeDataType(SchemeDataType::TypeId::Symbol, "rest")), registers[ARGL], registers[ENV]));// (assign env (op extend_environment) (const (first rest)) (reg argl) (reg env))
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
assign(ENV, extend_environment(list(1, new SchemeDataType(SchemeDataType::TypeId::Symbol, "x")), registers[ARGL], registers[ENV]));// (assign env (op extend_environment) (const x) (reg argl) (reg env))
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "not"), registers[ENV]));// (assign proc (op lookup_variable_value) (const not) (reg env))
s.save(CONTINUE);// (save continue)
s.save(PROC);// (save proc)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "eq_p"), registers[ENV]));// (assign proc (op lookup_variable_value) (const eq_p) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "false"), registers[ENV]));// (assign val (op lookup_variable_value) (const false) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "x"), registers[ENV]));// (assign val (op lookup_variable_value) (const x) (reg env))
assign(ARGL, cons(registers[VAL], registers[ARGL]));// (assign argl (op cons) (reg val) (reg argl))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH635");
}// (branch (label primitive_branch635))
compiled_branch636();
}
void compiled_branch636()
{// compiled_branch636
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL637"));// (assign continue (label after_call637))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch635()
{// primitive_branch635
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call637();
}
void after_call637()
{// after_call637
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
s.restore(PROC);// (restore proc)
s.restore(CONTINUE);// (restore continue)
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH638");
}// (branch (label primitive_branch638))
compiled_branch639();
}
void compiled_branch639()
{// compiled_branch639
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch638()
{// primitive_branch638
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call640();
}
void after_call640()
{// after_call640
after_lambda634();
}
void after_lambda634()
{// after_lambda634
define_variable(new SchemeDataType(SchemeDataType::TypeId::Symbol, "true_p"), registers[VAL], registers[ENV]);// (perform (op define_variable) (const true_p) (reg val) (reg env))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "ok"));// (assign val (const ok))
assign(VAL, make_compiled_procedure("ENTRY641", entry641, registers[ENV]));// (assign val (op make_compiled_procedure) (label entry641) (reg env))
goto_with_label("AFTER_LAMBDA642");// (goto (label after_lambda642))

}
void entry641()
{// entry641
assign(ENV, compiled_procedure_env(PROC));// (assign env (op compiled_procedure_env) (reg proc))
assign(ENV, extend_environment(list(1, new SchemeDataType(SchemeDataType::TypeId::Symbol, "x")), registers[ARGL], registers[ENV]));// (assign env (op extend_environment) (const x) (reg argl) (reg env))
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "eq_p"), registers[ENV]));// (assign proc (op lookup_variable_value) (const eq_p) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "false"), registers[ENV]));// (assign val (op lookup_variable_value) (const false) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "x"), registers[ENV]));// (assign val (op lookup_variable_value) (const x) (reg env))
assign(ARGL, cons(registers[VAL], registers[ARGL]));// (assign argl (op cons) (reg val) (reg argl))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH643");
}// (branch (label primitive_branch643))
compiled_branch644();
}
void compiled_branch644()
{// compiled_branch644
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch643()
{// primitive_branch643
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call645();
}
void after_call645()
{// after_call645
after_lambda642();
}
void after_lambda642()
{// after_lambda642
define_variable(new SchemeDataType(SchemeDataType::TypeId::Symbol, "false_p"), registers[VAL], registers[ENV]);// (perform (op define_variable) (const false_p) (reg val) (reg env))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "ok"));// (assign val (const ok))
assign(VAL, make_compiled_procedure("ENTRY646", entry646, registers[ENV]));// (assign val (op make_compiled_procedure) (label entry646) (reg env))
goto_with_label("AFTER_LAMBDA647");// (goto (label after_lambda647))

}
void entry646()
{// entry646
assign(ENV, compiled_procedure_env(PROC));// (assign env (op compiled_procedure_env) (reg proc))
assign(ENV, extend_environment(list(3, new SchemeDataType(SchemeDataType::TypeId::Symbol, "parameters"), new SchemeDataType(SchemeDataType::TypeId::Symbol, "body"), new SchemeDataType(SchemeDataType::TypeId::Symbol, "env")), registers[ARGL], registers[ENV]));// (assign env (op extend_environment) (const (parameters body env)) (reg argl) (reg env))
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
return goto_with_label("PRIMITIVE_BRANCH648");
}// (branch (label primitive_branch648))
compiled_branch649();
}
void compiled_branch649()
{// compiled_branch649
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch648()
{// primitive_branch648
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call650();
}
void after_call650()
{// after_call650
after_lambda647();
}
void after_lambda647()
{// after_lambda647
define_variable(new SchemeDataType(SchemeDataType::TypeId::Symbol, "make_procedure"), registers[VAL], registers[ENV]);// (perform (op define_variable) (const make_procedure) (reg val) (reg env))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "ok"));// (assign val (const ok))
assign(VAL, make_compiled_procedure("ENTRY651", entry651, registers[ENV]));// (assign val (op make_compiled_procedure) (label entry651) (reg env))
goto_with_label("AFTER_LAMBDA652");// (goto (label after_lambda652))

}
void entry651()
{// entry651
assign(ENV, compiled_procedure_env(PROC));// (assign env (op compiled_procedure_env) (reg proc))
assign(ENV, extend_environment(list(1, new SchemeDataType(SchemeDataType::TypeId::Symbol, "p")), registers[ARGL], registers[ENV]));// (assign env (op extend_environment) (const p) (reg argl) (reg env))
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "tagged_list_p"), registers[ENV]));// (assign proc (op lookup_variable_value) (const tagged_list_p) (reg env))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "procedure"));// (assign val (const procedure))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "p"), registers[ENV]));// (assign val (op lookup_variable_value) (const p) (reg env))
assign(ARGL, cons(registers[VAL], registers[ARGL]));// (assign argl (op cons) (reg val) (reg argl))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH653");
}// (branch (label primitive_branch653))
compiled_branch654();
}
void compiled_branch654()
{// compiled_branch654
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch653()
{// primitive_branch653
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call655();
}
void after_call655()
{// after_call655
after_lambda652();
}
void after_lambda652()
{// after_lambda652
define_variable(new SchemeDataType(SchemeDataType::TypeId::Symbol, "compound_procedure_p"), registers[VAL], registers[ENV]);// (perform (op define_variable) (const compound_procedure_p) (reg val) (reg env))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "ok"));// (assign val (const ok))
assign(VAL, make_compiled_procedure("ENTRY656", entry656, registers[ENV]));// (assign val (op make_compiled_procedure) (label entry656) (reg env))
goto_with_label("AFTER_LAMBDA657");// (goto (label after_lambda657))

}
void entry656()
{// entry656
assign(ENV, compiled_procedure_env(PROC));// (assign env (op compiled_procedure_env) (reg proc))
assign(ENV, extend_environment(list(1, new SchemeDataType(SchemeDataType::TypeId::Symbol, "p")), registers[ARGL], registers[ENV]));// (assign env (op extend_environment) (const p) (reg argl) (reg env))
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "cadr"), registers[ENV]));// (assign proc (op lookup_variable_value) (const cadr) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "p"), registers[ENV]));// (assign val (op lookup_variable_value) (const p) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH658");
}// (branch (label primitive_branch658))
compiled_branch659();
}
void compiled_branch659()
{// compiled_branch659
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch658()
{// primitive_branch658
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call660();
}
void after_call660()
{// after_call660
after_lambda657();
}
void after_lambda657()
{// after_lambda657
define_variable(new SchemeDataType(SchemeDataType::TypeId::Symbol, "procedure_parameters"), registers[VAL], registers[ENV]);// (perform (op define_variable) (const procedure_parameters) (reg val) (reg env))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "ok"));// (assign val (const ok))
assign(VAL, make_compiled_procedure("ENTRY661", entry661, registers[ENV]));// (assign val (op make_compiled_procedure) (label entry661) (reg env))
goto_with_label("AFTER_LAMBDA662");// (goto (label after_lambda662))

}
void entry661()
{// entry661
assign(ENV, compiled_procedure_env(PROC));// (assign env (op compiled_procedure_env) (reg proc))
assign(ENV, extend_environment(list(1, new SchemeDataType(SchemeDataType::TypeId::Symbol, "p")), registers[ARGL], registers[ENV]));// (assign env (op extend_environment) (const p) (reg argl) (reg env))
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "caddr"), registers[ENV]));// (assign proc (op lookup_variable_value) (const caddr) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "p"), registers[ENV]));// (assign val (op lookup_variable_value) (const p) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH663");
}// (branch (label primitive_branch663))
compiled_branch664();
}
void compiled_branch664()
{// compiled_branch664
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch663()
{// primitive_branch663
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call665();
}
void after_call665()
{// after_call665
after_lambda662();
}
void after_lambda662()
{// after_lambda662
define_variable(new SchemeDataType(SchemeDataType::TypeId::Symbol, "procedure_body"), registers[VAL], registers[ENV]);// (perform (op define_variable) (const procedure_body) (reg val) (reg env))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "ok"));// (assign val (const ok))
assign(VAL, make_compiled_procedure("ENTRY666", entry666, registers[ENV]));// (assign val (op make_compiled_procedure) (label entry666) (reg env))
goto_with_label("AFTER_LAMBDA667");// (goto (label after_lambda667))

}
void entry666()
{// entry666
assign(ENV, compiled_procedure_env(PROC));// (assign env (op compiled_procedure_env) (reg proc))
assign(ENV, extend_environment(list(1, new SchemeDataType(SchemeDataType::TypeId::Symbol, "p")), registers[ARGL], registers[ENV]));// (assign env (op extend_environment) (const p) (reg argl) (reg env))
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "cadddr"), registers[ENV]));// (assign proc (op lookup_variable_value) (const cadddr) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "p"), registers[ENV]));// (assign val (op lookup_variable_value) (const p) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH668");
}// (branch (label primitive_branch668))
compiled_branch669();
}
void compiled_branch669()
{// compiled_branch669
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch668()
{// primitive_branch668
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call670();
}
void after_call670()
{// after_call670
after_lambda667();
}
void after_lambda667()
{// after_lambda667
define_variable(new SchemeDataType(SchemeDataType::TypeId::Symbol, "procedure_environment"), registers[VAL], registers[ENV]);// (perform (op define_variable) (const procedure_environment) (reg val) (reg env))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "ok"));// (assign val (const ok))
assign(VAL, make_compiled_procedure("ENTRY671", entry671, registers[ENV]));// (assign val (op make_compiled_procedure) (label entry671) (reg env))
goto_with_label("AFTER_LAMBDA672");// (goto (label after_lambda672))

}
void entry671()
{// entry671
assign(ENV, compiled_procedure_env(PROC));// (assign env (op compiled_procedure_env) (reg proc))
assign(ENV, extend_environment(list(1, new SchemeDataType(SchemeDataType::TypeId::Symbol, "env")), registers[ARGL], registers[ENV]));// (assign env (op extend_environment) (const env) (reg argl) (reg env))
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "cdr"), registers[ENV]));// (assign proc (op lookup_variable_value) (const cdr) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "env"), registers[ENV]));// (assign val (op lookup_variable_value) (const env) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH673");
}// (branch (label primitive_branch673))
compiled_branch674();
}
void compiled_branch674()
{// compiled_branch674
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch673()
{// primitive_branch673
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call675();
}
void after_call675()
{// after_call675
after_lambda672();
}
void after_lambda672()
{// after_lambda672
define_variable(new SchemeDataType(SchemeDataType::TypeId::Symbol, "enclosing_environment"), registers[VAL], registers[ENV]);// (perform (op define_variable) (const enclosing_environment) (reg val) (reg env))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "ok"));// (assign val (const ok))
assign(VAL, make_compiled_procedure("ENTRY676", entry676, registers[ENV]));// (assign val (op make_compiled_procedure) (label entry676) (reg env))
goto_with_label("AFTER_LAMBDA677");// (goto (label after_lambda677))

}
void entry676()
{// entry676
assign(ENV, compiled_procedure_env(PROC));// (assign env (op compiled_procedure_env) (reg proc))
assign(ENV, extend_environment(list(1, new SchemeDataType(SchemeDataType::TypeId::Symbol, "env")), registers[ARGL], registers[ENV]));// (assign env (op extend_environment) (const env) (reg argl) (reg env))
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "car"), registers[ENV]));// (assign proc (op lookup_variable_value) (const car) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "env"), registers[ENV]));// (assign val (op lookup_variable_value) (const env) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH678");
}// (branch (label primitive_branch678))
compiled_branch679();
}
void compiled_branch679()
{// compiled_branch679
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch678()
{// primitive_branch678
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call680();
}
void after_call680()
{// after_call680
after_lambda677();
}
void after_lambda677()
{// after_lambda677
define_variable(new SchemeDataType(SchemeDataType::TypeId::Symbol, "first_frame"), registers[VAL], registers[ENV]);// (perform (op define_variable) (const first_frame) (reg val) (reg env))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "ok"));// (assign val (const ok))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::Nil));// (assign val (const nil ))
define_variable(new SchemeDataType(SchemeDataType::TypeId::Symbol, "the_empty_environment"), registers[VAL], registers[ENV]);// (perform (op define_variable) (const the_empty_environment) (reg val) (reg env))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "ok"));// (assign val (const ok))
assign(VAL, make_compiled_procedure("ENTRY681", entry681, registers[ENV]));// (assign val (op make_compiled_procedure) (label entry681) (reg env))
goto_with_label("AFTER_LAMBDA682");// (goto (label after_lambda682))

}
void entry681()
{// entry681
assign(ENV, compiled_procedure_env(PROC));// (assign env (op compiled_procedure_env) (reg proc))
assign(ENV, extend_environment(list(2, new SchemeDataType(SchemeDataType::TypeId::Symbol, "variables"), new SchemeDataType(SchemeDataType::TypeId::Symbol, "values")), registers[ARGL], registers[ENV]));// (assign env (op extend_environment) (const (variables values)) (reg argl) (reg env))
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "cons"), registers[ENV]));// (assign proc (op lookup_variable_value) (const cons) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "values"), registers[ENV]));// (assign val (op lookup_variable_value) (const values) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "variables"), registers[ENV]));// (assign val (op lookup_variable_value) (const variables) (reg env))
assign(ARGL, cons(registers[VAL], registers[ARGL]));// (assign argl (op cons) (reg val) (reg argl))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH683");
}// (branch (label primitive_branch683))
compiled_branch684();
}
void compiled_branch684()
{// compiled_branch684
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch683()
{// primitive_branch683
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call685();
}
void after_call685()
{// after_call685
after_lambda682();
}
void after_lambda682()
{// after_lambda682
define_variable(new SchemeDataType(SchemeDataType::TypeId::Symbol, "make_frame"), registers[VAL], registers[ENV]);// (perform (op define_variable) (const make_frame) (reg val) (reg env))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "ok"));// (assign val (const ok))
assign(VAL, make_compiled_procedure("ENTRY686", entry686, registers[ENV]));// (assign val (op make_compiled_procedure) (label entry686) (reg env))
goto_with_label("AFTER_LAMBDA687");// (goto (label after_lambda687))

}
void entry686()
{// entry686
assign(ENV, compiled_procedure_env(PROC));// (assign env (op compiled_procedure_env) (reg proc))
assign(ENV, extend_environment(list(1, new SchemeDataType(SchemeDataType::TypeId::Symbol, "frame")), registers[ARGL], registers[ENV]));// (assign env (op extend_environment) (const frame) (reg argl) (reg env))
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "car"), registers[ENV]));// (assign proc (op lookup_variable_value) (const car) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "frame"), registers[ENV]));// (assign val (op lookup_variable_value) (const frame) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH688");
}// (branch (label primitive_branch688))
compiled_branch689();
}
void compiled_branch689()
{// compiled_branch689
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch688()
{// primitive_branch688
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call690();
}
void after_call690()
{// after_call690
after_lambda687();
}
void after_lambda687()
{// after_lambda687
define_variable(new SchemeDataType(SchemeDataType::TypeId::Symbol, "frame_variables"), registers[VAL], registers[ENV]);// (perform (op define_variable) (const frame_variables) (reg val) (reg env))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "ok"));// (assign val (const ok))
assign(VAL, make_compiled_procedure("ENTRY691", entry691, registers[ENV]));// (assign val (op make_compiled_procedure) (label entry691) (reg env))
goto_with_label("AFTER_LAMBDA692");// (goto (label after_lambda692))

}
void entry691()
{// entry691
assign(ENV, compiled_procedure_env(PROC));// (assign env (op compiled_procedure_env) (reg proc))
assign(ENV, extend_environment(list(1, new SchemeDataType(SchemeDataType::TypeId::Symbol, "frame")), registers[ARGL], registers[ENV]));// (assign env (op extend_environment) (const frame) (reg argl) (reg env))
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "cdr"), registers[ENV]));// (assign proc (op lookup_variable_value) (const cdr) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "frame"), registers[ENV]));// (assign val (op lookup_variable_value) (const frame) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH693");
}// (branch (label primitive_branch693))
compiled_branch694();
}
void compiled_branch694()
{// compiled_branch694
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch693()
{// primitive_branch693
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call695();
}
void after_call695()
{// after_call695
after_lambda692();
}
void after_lambda692()
{// after_lambda692
define_variable(new SchemeDataType(SchemeDataType::TypeId::Symbol, "frame_values"), registers[VAL], registers[ENV]);// (perform (op define_variable) (const frame_values) (reg val) (reg env))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "ok"));// (assign val (const ok))
assign(VAL, make_compiled_procedure("ENTRY696", entry696, registers[ENV]));// (assign val (op make_compiled_procedure) (label entry696) (reg env))
goto_with_label("AFTER_LAMBDA697");// (goto (label after_lambda697))

}
void entry696()
{// entry696
assign(ENV, compiled_procedure_env(PROC));// (assign env (op compiled_procedure_env) (reg proc))
assign(ENV, extend_environment(list(3, new SchemeDataType(SchemeDataType::TypeId::Symbol, "var"), new SchemeDataType(SchemeDataType::TypeId::Symbol, "val"), new SchemeDataType(SchemeDataType::TypeId::Symbol, "frame")), registers[ARGL], registers[ENV]));// (assign env (op extend_environment) (const (var val frame)) (reg argl) (reg env))
s.save(CONTINUE);// (save continue)
s.save(ENV);// (save env)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "set_car"), registers[ENV]));// (assign proc (op lookup_variable_value) (const set_car) (reg env))
s.save(PROC);// (save proc)
s.save(ENV);// (save env)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "cons"), registers[ENV]));// (assign proc (op lookup_variable_value) (const cons) (reg env))
s.save(PROC);// (save proc)
s.save(ENV);// (save env)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "car"), registers[ENV]));// (assign proc (op lookup_variable_value) (const car) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "frame"), registers[ENV]));// (assign val (op lookup_variable_value) (const frame) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH698");
}// (branch (label primitive_branch698))
compiled_branch699();
}
void compiled_branch699()
{// compiled_branch699
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL700"));// (assign continue (label after_call700))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch698()
{// primitive_branch698
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call700();
}
void after_call700()
{// after_call700
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
s.restore(ENV);// (restore env)
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "var"), registers[ENV]));// (assign val (op lookup_variable_value) (const var) (reg env))
assign(ARGL, cons(registers[VAL], registers[ARGL]));// (assign argl (op cons) (reg val) (reg argl))
s.restore(PROC);// (restore proc)
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH701");
}// (branch (label primitive_branch701))
compiled_branch702();
}
void compiled_branch702()
{// compiled_branch702
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL703"));// (assign continue (label after_call703))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch701()
{// primitive_branch701
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call703();
}
void after_call703()
{// after_call703
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
s.restore(ENV);// (restore env)
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "frame"), registers[ENV]));// (assign val (op lookup_variable_value) (const frame) (reg env))
assign(ARGL, cons(registers[VAL], registers[ARGL]));// (assign argl (op cons) (reg val) (reg argl))
s.restore(PROC);// (restore proc)
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH704");
}// (branch (label primitive_branch704))
compiled_branch705();
}
void compiled_branch705()
{// compiled_branch705
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL706"));// (assign continue (label after_call706))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch704()
{// primitive_branch704
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call706();
}
void after_call706()
{// after_call706
s.restore(ENV);// (restore env)
s.restore(CONTINUE);// (restore continue)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "set_cdr"), registers[ENV]));// (assign proc (op lookup_variable_value) (const set_cdr) (reg env))
s.save(CONTINUE);// (save continue)
s.save(PROC);// (save proc)
s.save(ENV);// (save env)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "cons"), registers[ENV]));// (assign proc (op lookup_variable_value) (const cons) (reg env))
s.save(PROC);// (save proc)
s.save(ENV);// (save env)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "cdr"), registers[ENV]));// (assign proc (op lookup_variable_value) (const cdr) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "frame"), registers[ENV]));// (assign val (op lookup_variable_value) (const frame) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH707");
}// (branch (label primitive_branch707))
compiled_branch708();
}
void compiled_branch708()
{// compiled_branch708
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL709"));// (assign continue (label after_call709))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch707()
{// primitive_branch707
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call709();
}
void after_call709()
{// after_call709
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
s.restore(ENV);// (restore env)
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "val"), registers[ENV]));// (assign val (op lookup_variable_value) (const val) (reg env))
assign(ARGL, cons(registers[VAL], registers[ARGL]));// (assign argl (op cons) (reg val) (reg argl))
s.restore(PROC);// (restore proc)
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH710");
}// (branch (label primitive_branch710))
compiled_branch711();
}
void compiled_branch711()
{// compiled_branch711
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL712"));// (assign continue (label after_call712))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch710()
{// primitive_branch710
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call712();
}
void after_call712()
{// after_call712
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
s.restore(ENV);// (restore env)
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "frame"), registers[ENV]));// (assign val (op lookup_variable_value) (const frame) (reg env))
assign(ARGL, cons(registers[VAL], registers[ARGL]));// (assign argl (op cons) (reg val) (reg argl))
s.restore(PROC);// (restore proc)
s.restore(CONTINUE);// (restore continue)
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH713");
}// (branch (label primitive_branch713))
compiled_branch714();
}
void compiled_branch714()
{// compiled_branch714
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch713()
{// primitive_branch713
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call715();
}
void after_call715()
{// after_call715
after_lambda697();
}
void after_lambda697()
{// after_lambda697
define_variable(new SchemeDataType(SchemeDataType::TypeId::Symbol, "add_binding_to_frame"), registers[VAL], registers[ENV]);// (perform (op define_variable) (const add_binding_to_frame) (reg val) (reg env))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "ok"));// (assign val (const ok))
assign(VAL, make_compiled_procedure("ENTRY716", entry716, registers[ENV]));// (assign val (op make_compiled_procedure) (label entry716) (reg env))
goto_with_label("AFTER_LAMBDA717");// (goto (label after_lambda717))

}
void entry716()
{// entry716
assign(ENV, compiled_procedure_env(PROC));// (assign env (op compiled_procedure_env) (reg proc))
assign(ENV, extend_environment(list(3, new SchemeDataType(SchemeDataType::TypeId::Symbol, "vars"), new SchemeDataType(SchemeDataType::TypeId::Symbol, "vals"), new SchemeDataType(SchemeDataType::TypeId::Symbol, "base_env")), registers[ARGL], registers[ENV]));// (assign env (op extend_environment) (const (vars vals base_env)) (reg argl) (reg env))
s.save(CONTINUE);// (save continue)
s.save(ENV);// (save env)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "="), registers[ENV]));// (assign proc (op lookup_variable_value) (const =) (reg env))
s.save(PROC);// (save proc)
s.save(ENV);// (save env)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "length"), registers[ENV]));// (assign proc (op lookup_variable_value) (const length) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "vals"), registers[ENV]));// (assign val (op lookup_variable_value) (const vals) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH724");
}// (branch (label primitive_branch724))
compiled_branch725();
}
void compiled_branch725()
{// compiled_branch725
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL726"));// (assign continue (label after_call726))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch724()
{// primitive_branch724
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call726();
}
void after_call726()
{// after_call726
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
s.restore(ENV);// (restore env)
s.save(ARGL);// (save argl)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "length"), registers[ENV]));// (assign proc (op lookup_variable_value) (const length) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "vars"), registers[ENV]));// (assign val (op lookup_variable_value) (const vars) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH721");
}// (branch (label primitive_branch721))
compiled_branch722();
}
void compiled_branch722()
{// compiled_branch722
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL723"));// (assign continue (label after_call723))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch721()
{// primitive_branch721
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call723();
}
void after_call723()
{// after_call723
s.restore(ARGL);// (restore argl)
assign(ARGL, cons(registers[VAL], registers[ARGL]));// (assign argl (op cons) (reg val) (reg argl))
s.restore(PROC);// (restore proc)
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH727");
}// (branch (label primitive_branch727))
compiled_branch728();
}
void compiled_branch728()
{// compiled_branch728
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL729"));// (assign continue (label after_call729))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch727()
{// primitive_branch727
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call729();
}
void after_call729()
{// after_call729
s.restore(ENV);// (restore env)
s.restore(CONTINUE);// (restore continue)
if ( false_p(registers[VAL]) ) {// (test (op false_p) (reg val))
return goto_with_label("FALSE_BRANCH719");
}// (branch (label false_branch719))
true_branch718();
}
void true_branch718()
{// true_branch718
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "cons"), registers[ENV]));// (assign proc (op lookup_variable_value) (const cons) (reg env))
s.save(CONTINUE);// (save continue)
s.save(PROC);// (save proc)
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "base_env"), registers[ENV]));// (assign val (op lookup_variable_value) (const base_env) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
s.save(ARGL);// (save argl)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "make_frame"), registers[ENV]));// (assign proc (op lookup_variable_value) (const make_frame) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "vals"), registers[ENV]));// (assign val (op lookup_variable_value) (const vals) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "vars"), registers[ENV]));// (assign val (op lookup_variable_value) (const vars) (reg env))
assign(ARGL, cons(registers[VAL], registers[ARGL]));// (assign argl (op cons) (reg val) (reg argl))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH730");
}// (branch (label primitive_branch730))
compiled_branch731();
}
void compiled_branch731()
{// compiled_branch731
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL732"));// (assign continue (label after_call732))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch730()
{// primitive_branch730
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call732();
}
void after_call732()
{// after_call732
s.restore(ARGL);// (restore argl)
assign(ARGL, cons(registers[VAL], registers[ARGL]));// (assign argl (op cons) (reg val) (reg argl))
s.restore(PROC);// (restore proc)
s.restore(CONTINUE);// (restore continue)
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH733");
}// (branch (label primitive_branch733))
compiled_branch734();
}
void compiled_branch734()
{// compiled_branch734
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch733()
{// primitive_branch733
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call735();
}
void after_call735()
{// after_call735

}
void false_branch719()
{// false_branch719
s.save(CONTINUE);// (save continue)
s.save(ENV);// (save env)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "<"), registers[ENV]));// (assign proc (op lookup_variable_value) (const <) (reg env))
s.save(PROC);// (save proc)
s.save(ENV);// (save env)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "length"), registers[ENV]));// (assign proc (op lookup_variable_value) (const length) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "vals"), registers[ENV]));// (assign val (op lookup_variable_value) (const vals) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH742");
}// (branch (label primitive_branch742))
compiled_branch743();
}
void compiled_branch743()
{// compiled_branch743
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL744"));// (assign continue (label after_call744))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch742()
{// primitive_branch742
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call744();
}
void after_call744()
{// after_call744
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
s.restore(ENV);// (restore env)
s.save(ARGL);// (save argl)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "length"), registers[ENV]));// (assign proc (op lookup_variable_value) (const length) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "vars"), registers[ENV]));// (assign val (op lookup_variable_value) (const vars) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH739");
}// (branch (label primitive_branch739))
compiled_branch740();
}
void compiled_branch740()
{// compiled_branch740
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL741"));// (assign continue (label after_call741))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch739()
{// primitive_branch739
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call741();
}
void after_call741()
{// after_call741
s.restore(ARGL);// (restore argl)
assign(ARGL, cons(registers[VAL], registers[ARGL]));// (assign argl (op cons) (reg val) (reg argl))
s.restore(PROC);// (restore proc)
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH745");
}// (branch (label primitive_branch745))
compiled_branch746();
}
void compiled_branch746()
{// compiled_branch746
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL747"));// (assign continue (label after_call747))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch745()
{// primitive_branch745
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call747();
}
void after_call747()
{// after_call747
s.restore(ENV);// (restore env)
s.restore(CONTINUE);// (restore continue)
if ( false_p(registers[VAL]) ) {// (test (op false_p) (reg val))
return goto_with_label("FALSE_BRANCH737");
}// (branch (label false_branch737))
true_branch736();
}
void true_branch736()
{// true_branch736
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "error"), registers[ENV]));// (assign proc (op lookup_variable_value) (const error) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "vals"), registers[ENV]));// (assign val (op lookup_variable_value) (const vals) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "vars"), registers[ENV]));// (assign val (op lookup_variable_value) (const vars) (reg env))
assign(ARGL, cons(registers[VAL], registers[ARGL]));// (assign argl (op cons) (reg val) (reg argl))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "Too many arguments supplied"));// (assign val (const Too many arguments supplied))
assign(ARGL, cons(registers[VAL], registers[ARGL]));// (assign argl (op cons) (reg val) (reg argl))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH748");
}// (branch (label primitive_branch748))
compiled_branch749();
}
void compiled_branch749()
{// compiled_branch749
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch748()
{// primitive_branch748
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call750();
}
void after_call750()
{// after_call750

}
void false_branch737()
{// false_branch737
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "error"), registers[ENV]));// (assign proc (op lookup_variable_value) (const error) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "vals"), registers[ENV]));// (assign val (op lookup_variable_value) (const vals) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "vars"), registers[ENV]));// (assign val (op lookup_variable_value) (const vars) (reg env))
assign(ARGL, cons(registers[VAL], registers[ARGL]));// (assign argl (op cons) (reg val) (reg argl))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "Too few arguments supplied"));// (assign val (const Too few arguments supplied))
assign(ARGL, cons(registers[VAL], registers[ARGL]));// (assign argl (op cons) (reg val) (reg argl))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH751");
}// (branch (label primitive_branch751))
compiled_branch752();
}
void compiled_branch752()
{// compiled_branch752
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch751()
{// primitive_branch751
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call753();
}
void after_call753()
{// after_call753
after_if738();
}
void after_if738()
{// after_if738
after_if720();
}
void after_if720()
{// after_if720
after_lambda717();
}
void after_lambda717()
{// after_lambda717
define_variable(new SchemeDataType(SchemeDataType::TypeId::Symbol, "extend_environment"), registers[VAL], registers[ENV]);// (perform (op define_variable) (const extend_environment) (reg val) (reg env))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "ok"));// (assign val (const ok))
assign(VAL, make_compiled_procedure("ENTRY754", entry754, registers[ENV]));// (assign val (op make_compiled_procedure) (label entry754) (reg env))
goto_with_label("AFTER_LAMBDA755");// (goto (label after_lambda755))

}
void entry754()
{// entry754
assign(ENV, compiled_procedure_env(PROC));// (assign env (op compiled_procedure_env) (reg proc))
assign(ENV, extend_environment(list(2, new SchemeDataType(SchemeDataType::TypeId::Symbol, "var"), new SchemeDataType(SchemeDataType::TypeId::Symbol, "env")), registers[ARGL], registers[ENV]));// (assign env (op extend_environment) (const (var env)) (reg argl) (reg env))
assign(VAL, make_compiled_procedure("ENTRY756", entry756, registers[ENV]));// (assign val (op make_compiled_procedure) (label entry756) (reg env))
goto_with_label("AFTER_LAMBDA757");// (goto (label after_lambda757))

}
void entry756()
{// entry756
assign(ENV, compiled_procedure_env(PROC));// (assign env (op compiled_procedure_env) (reg proc))
assign(ENV, extend_environment(list(1, new SchemeDataType(SchemeDataType::TypeId::Symbol, "env")), registers[ARGL], registers[ENV]));// (assign env (op extend_environment) (const env) (reg argl) (reg env))
assign(VAL, make_compiled_procedure("ENTRY758", entry758, registers[ENV]));// (assign val (op make_compiled_procedure) (label entry758) (reg env))
goto_with_label("AFTER_LAMBDA759");// (goto (label after_lambda759))

}
void entry758()
{// entry758
assign(ENV, compiled_procedure_env(PROC));// (assign env (op compiled_procedure_env) (reg proc))
assign(ENV, extend_environment(list(2, new SchemeDataType(SchemeDataType::TypeId::Symbol, "vars"), new SchemeDataType(SchemeDataType::TypeId::Symbol, "vals")), registers[ARGL], registers[ENV]));// (assign env (op extend_environment) (const (vars vals)) (reg argl) (reg env))
s.save(CONTINUE);// (save continue)
s.save(ENV);// (save env)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "null_p"), registers[ENV]));// (assign proc (op lookup_variable_value) (const null_p) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "vars"), registers[ENV]));// (assign val (op lookup_variable_value) (const vars) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH763");
}// (branch (label primitive_branch763))
compiled_branch764();
}
void compiled_branch764()
{// compiled_branch764
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL765"));// (assign continue (label after_call765))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch763()
{// primitive_branch763
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call765();
}
void after_call765()
{// after_call765
s.restore(ENV);// (restore env)
s.restore(CONTINUE);// (restore continue)
if ( false_p(registers[VAL]) ) {// (test (op false_p) (reg val))
return goto_with_label("FALSE_BRANCH761");
}// (branch (label false_branch761))
true_branch760();
}
void true_branch760()
{// true_branch760
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "env_loop"), registers[ENV]));// (assign proc (op lookup_variable_value) (const env_loop) (reg env))
s.save(CONTINUE);// (save continue)
s.save(PROC);// (save proc)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "enclosing_environment"), registers[ENV]));// (assign proc (op lookup_variable_value) (const enclosing_environment) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "env"), registers[ENV]));// (assign val (op lookup_variable_value) (const env) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH766");
}// (branch (label primitive_branch766))
compiled_branch767();
}
void compiled_branch767()
{// compiled_branch767
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL768"));// (assign continue (label after_call768))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch766()
{// primitive_branch766
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call768();
}
void after_call768()
{// after_call768
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
s.restore(PROC);// (restore proc)
s.restore(CONTINUE);// (restore continue)
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH769");
}// (branch (label primitive_branch769))
compiled_branch770();
}
void compiled_branch770()
{// compiled_branch770
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch769()
{// primitive_branch769
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call771();
}
void after_call771()
{// after_call771

}
void false_branch761()
{// false_branch761
s.save(CONTINUE);// (save continue)
s.save(ENV);// (save env)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "eq_p"), registers[ENV]));// (assign proc (op lookup_variable_value) (const eq_p) (reg env))
s.save(PROC);// (save proc)
s.save(ENV);// (save env)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "car"), registers[ENV]));// (assign proc (op lookup_variable_value) (const car) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "vars"), registers[ENV]));// (assign val (op lookup_variable_value) (const vars) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH775");
}// (branch (label primitive_branch775))
compiled_branch776();
}
void compiled_branch776()
{// compiled_branch776
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL777"));// (assign continue (label after_call777))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch775()
{// primitive_branch775
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call777();
}
void after_call777()
{// after_call777
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
s.restore(ENV);// (restore env)
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "var"), registers[ENV]));// (assign val (op lookup_variable_value) (const var) (reg env))
assign(ARGL, cons(registers[VAL], registers[ARGL]));// (assign argl (op cons) (reg val) (reg argl))
s.restore(PROC);// (restore proc)
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH778");
}// (branch (label primitive_branch778))
compiled_branch779();
}
void compiled_branch779()
{// compiled_branch779
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL780"));// (assign continue (label after_call780))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch778()
{// primitive_branch778
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call780();
}
void after_call780()
{// after_call780
s.restore(ENV);// (restore env)
s.restore(CONTINUE);// (restore continue)
if ( false_p(registers[VAL]) ) {// (test (op false_p) (reg val))
return goto_with_label("FALSE_BRANCH773");
}// (branch (label false_branch773))
true_branch772();
}
void true_branch772()
{// true_branch772
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "car"), registers[ENV]));// (assign proc (op lookup_variable_value) (const car) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "vals"), registers[ENV]));// (assign val (op lookup_variable_value) (const vals) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH781");
}// (branch (label primitive_branch781))
compiled_branch782();
}
void compiled_branch782()
{// compiled_branch782
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch781()
{// primitive_branch781
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call783();
}
void after_call783()
{// after_call783

}
void false_branch773()
{// false_branch773
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "scan"), registers[ENV]));// (assign proc (op lookup_variable_value) (const scan) (reg env))
s.save(CONTINUE);// (save continue)
s.save(PROC);// (save proc)
s.save(ENV);// (save env)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "cdr"), registers[ENV]));// (assign proc (op lookup_variable_value) (const cdr) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "vals"), registers[ENV]));// (assign val (op lookup_variable_value) (const vals) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH787");
}// (branch (label primitive_branch787))
compiled_branch788();
}
void compiled_branch788()
{// compiled_branch788
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL789"));// (assign continue (label after_call789))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch787()
{// primitive_branch787
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call789();
}
void after_call789()
{// after_call789
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
s.restore(ENV);// (restore env)
s.save(ARGL);// (save argl)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "cdr"), registers[ENV]));// (assign proc (op lookup_variable_value) (const cdr) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "vars"), registers[ENV]));// (assign val (op lookup_variable_value) (const vars) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH784");
}// (branch (label primitive_branch784))
compiled_branch785();
}
void compiled_branch785()
{// compiled_branch785
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL786"));// (assign continue (label after_call786))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch784()
{// primitive_branch784
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call786();
}
void after_call786()
{// after_call786
s.restore(ARGL);// (restore argl)
assign(ARGL, cons(registers[VAL], registers[ARGL]));// (assign argl (op cons) (reg val) (reg argl))
s.restore(PROC);// (restore proc)
s.restore(CONTINUE);// (restore continue)
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH790");
}// (branch (label primitive_branch790))
compiled_branch791();
}
void compiled_branch791()
{// compiled_branch791
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch790()
{// primitive_branch790
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call792();
}
void after_call792()
{// after_call792
after_if774();
}
void after_if774()
{// after_if774
after_if762();
}
void after_if762()
{// after_if762
after_lambda759();
}
void after_lambda759()
{// after_lambda759
define_variable(new SchemeDataType(SchemeDataType::TypeId::Symbol, "scan"), registers[VAL], registers[ENV]);// (perform (op define_variable) (const scan) (reg val) (reg env))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "ok"));// (assign val (const ok))
s.save(CONTINUE);// (save continue)
s.save(ENV);// (save env)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "eq_p"), registers[ENV]));// (assign proc (op lookup_variable_value) (const eq_p) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "the_empty_environment"), registers[ENV]));// (assign val (op lookup_variable_value) (const the_empty_environment) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "env"), registers[ENV]));// (assign val (op lookup_variable_value) (const env) (reg env))
assign(ARGL, cons(registers[VAL], registers[ARGL]));// (assign argl (op cons) (reg val) (reg argl))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH796");
}// (branch (label primitive_branch796))
compiled_branch797();
}
void compiled_branch797()
{// compiled_branch797
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL798"));// (assign continue (label after_call798))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch796()
{// primitive_branch796
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call798();
}
void after_call798()
{// after_call798
s.restore(ENV);// (restore env)
s.restore(CONTINUE);// (restore continue)
if ( false_p(registers[VAL]) ) {// (test (op false_p) (reg val))
return goto_with_label("FALSE_BRANCH794");
}// (branch (label false_branch794))
true_branch793();
}
void true_branch793()
{// true_branch793
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "error"), registers[ENV]));// (assign proc (op lookup_variable_value) (const error) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "var"), registers[ENV]));// (assign val (op lookup_variable_value) (const var) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "Unbound variable"));// (assign val (const Unbound variable))
assign(ARGL, cons(registers[VAL], registers[ARGL]));// (assign argl (op cons) (reg val) (reg argl))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH799");
}// (branch (label primitive_branch799))
compiled_branch800();
}
void compiled_branch800()
{// compiled_branch800
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch799()
{// primitive_branch799
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call801();
}
void after_call801()
{// after_call801

}
void false_branch794()
{// false_branch794
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "scan"), registers[ENV]));// (assign proc (op lookup_variable_value) (const scan) (reg env))
s.save(CONTINUE);// (save continue)
s.save(PROC);// (save proc)
s.save(ENV);// (save env)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "frame_values"), registers[ENV]));// (assign proc (op lookup_variable_value) (const frame_values) (reg env))
s.save(PROC);// (save proc)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "first_frame"), registers[ENV]));// (assign proc (op lookup_variable_value) (const first_frame) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "env"), registers[ENV]));// (assign val (op lookup_variable_value) (const env) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH808");
}// (branch (label primitive_branch808))
compiled_branch809();
}
void compiled_branch809()
{// compiled_branch809
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL810"));// (assign continue (label after_call810))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch808()
{// primitive_branch808
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call810();
}
void after_call810()
{// after_call810
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
s.restore(PROC);// (restore proc)
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH811");
}// (branch (label primitive_branch811))
compiled_branch812();
}
void compiled_branch812()
{// compiled_branch812
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL813"));// (assign continue (label after_call813))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch811()
{// primitive_branch811
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call813();
}
void after_call813()
{// after_call813
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
s.restore(ENV);// (restore env)
s.save(ARGL);// (save argl)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "frame_variables"), registers[ENV]));// (assign proc (op lookup_variable_value) (const frame_variables) (reg env))
s.save(PROC);// (save proc)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "first_frame"), registers[ENV]));// (assign proc (op lookup_variable_value) (const first_frame) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "env"), registers[ENV]));// (assign val (op lookup_variable_value) (const env) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH802");
}// (branch (label primitive_branch802))
compiled_branch803();
}
void compiled_branch803()
{// compiled_branch803
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL804"));// (assign continue (label after_call804))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch802()
{// primitive_branch802
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call804();
}
void after_call804()
{// after_call804
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
s.restore(PROC);// (restore proc)
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH805");
}// (branch (label primitive_branch805))
compiled_branch806();
}
void compiled_branch806()
{// compiled_branch806
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL807"));// (assign continue (label after_call807))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch805()
{// primitive_branch805
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call807();
}
void after_call807()
{// after_call807
s.restore(ARGL);// (restore argl)
assign(ARGL, cons(registers[VAL], registers[ARGL]));// (assign argl (op cons) (reg val) (reg argl))
s.restore(PROC);// (restore proc)
s.restore(CONTINUE);// (restore continue)
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH814");
}// (branch (label primitive_branch814))
compiled_branch815();
}
void compiled_branch815()
{// compiled_branch815
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch814()
{// primitive_branch814
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call816();
}
void after_call816()
{// after_call816
after_if795();
}
void after_if795()
{// after_if795
after_lambda757();
}
void after_lambda757()
{// after_lambda757
define_variable(new SchemeDataType(SchemeDataType::TypeId::Symbol, "env_loop"), registers[VAL], registers[ENV]);// (perform (op define_variable) (const env_loop) (reg val) (reg env))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "ok"));// (assign val (const ok))
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "env_loop"), registers[ENV]));// (assign proc (op lookup_variable_value) (const env_loop) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "env"), registers[ENV]));// (assign val (op lookup_variable_value) (const env) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH817");
}// (branch (label primitive_branch817))
compiled_branch818();
}
void compiled_branch818()
{// compiled_branch818
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch817()
{// primitive_branch817
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call819();
}
void after_call819()
{// after_call819
after_lambda755();
}
void after_lambda755()
{// after_lambda755
define_variable(new SchemeDataType(SchemeDataType::TypeId::Symbol, "lookup_variable_value"), registers[VAL], registers[ENV]);// (perform (op define_variable) (const lookup_variable_value) (reg val) (reg env))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "ok"));// (assign val (const ok))
assign(VAL, make_compiled_procedure("ENTRY820", entry820, registers[ENV]));// (assign val (op make_compiled_procedure) (label entry820) (reg env))
goto_with_label("AFTER_LAMBDA821");// (goto (label after_lambda821))

}
void entry820()
{// entry820
assign(ENV, compiled_procedure_env(PROC));// (assign env (op compiled_procedure_env) (reg proc))
assign(ENV, extend_environment(list(3, new SchemeDataType(SchemeDataType::TypeId::Symbol, "var"), new SchemeDataType(SchemeDataType::TypeId::Symbol, "val"), new SchemeDataType(SchemeDataType::TypeId::Symbol, "env")), registers[ARGL], registers[ENV]));// (assign env (op extend_environment) (const (var val env)) (reg argl) (reg env))
assign(VAL, make_compiled_procedure("ENTRY822", entry822, registers[ENV]));// (assign val (op make_compiled_procedure) (label entry822) (reg env))
goto_with_label("AFTER_LAMBDA823");// (goto (label after_lambda823))

}
void entry822()
{// entry822
assign(ENV, compiled_procedure_env(PROC));// (assign env (op compiled_procedure_env) (reg proc))
assign(ENV, extend_environment(list(1, new SchemeDataType(SchemeDataType::TypeId::Symbol, "env")), registers[ARGL], registers[ENV]));// (assign env (op extend_environment) (const env) (reg argl) (reg env))
assign(VAL, make_compiled_procedure("ENTRY824", entry824, registers[ENV]));// (assign val (op make_compiled_procedure) (label entry824) (reg env))
goto_with_label("AFTER_LAMBDA825");// (goto (label after_lambda825))

}
void entry824()
{// entry824
assign(ENV, compiled_procedure_env(PROC));// (assign env (op compiled_procedure_env) (reg proc))
assign(ENV, extend_environment(list(2, new SchemeDataType(SchemeDataType::TypeId::Symbol, "vars"), new SchemeDataType(SchemeDataType::TypeId::Symbol, "vals")), registers[ARGL], registers[ENV]));// (assign env (op extend_environment) (const (vars vals)) (reg argl) (reg env))
s.save(CONTINUE);// (save continue)
s.save(ENV);// (save env)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "null_p"), registers[ENV]));// (assign proc (op lookup_variable_value) (const null_p) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "vars"), registers[ENV]));// (assign val (op lookup_variable_value) (const vars) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH829");
}// (branch (label primitive_branch829))
compiled_branch830();
}
void compiled_branch830()
{// compiled_branch830
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL831"));// (assign continue (label after_call831))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch829()
{// primitive_branch829
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call831();
}
void after_call831()
{// after_call831
s.restore(ENV);// (restore env)
s.restore(CONTINUE);// (restore continue)
if ( false_p(registers[VAL]) ) {// (test (op false_p) (reg val))
return goto_with_label("FALSE_BRANCH827");
}// (branch (label false_branch827))
true_branch826();
}
void true_branch826()
{// true_branch826
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "env_loop"), registers[ENV]));// (assign proc (op lookup_variable_value) (const env_loop) (reg env))
s.save(CONTINUE);// (save continue)
s.save(PROC);// (save proc)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "enclosing_environment"), registers[ENV]));// (assign proc (op lookup_variable_value) (const enclosing_environment) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "env"), registers[ENV]));// (assign val (op lookup_variable_value) (const env) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH832");
}// (branch (label primitive_branch832))
compiled_branch833();
}
void compiled_branch833()
{// compiled_branch833
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL834"));// (assign continue (label after_call834))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch832()
{// primitive_branch832
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call834();
}
void after_call834()
{// after_call834
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
s.restore(PROC);// (restore proc)
s.restore(CONTINUE);// (restore continue)
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH835");
}// (branch (label primitive_branch835))
compiled_branch836();
}
void compiled_branch836()
{// compiled_branch836
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch835()
{// primitive_branch835
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call837();
}
void after_call837()
{// after_call837

}
void false_branch827()
{// false_branch827
s.save(CONTINUE);// (save continue)
s.save(ENV);// (save env)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "eq_p"), registers[ENV]));// (assign proc (op lookup_variable_value) (const eq_p) (reg env))
s.save(PROC);// (save proc)
s.save(ENV);// (save env)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "car"), registers[ENV]));// (assign proc (op lookup_variable_value) (const car) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "vars"), registers[ENV]));// (assign val (op lookup_variable_value) (const vars) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH841");
}// (branch (label primitive_branch841))
compiled_branch842();
}
void compiled_branch842()
{// compiled_branch842
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL843"));// (assign continue (label after_call843))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch841()
{// primitive_branch841
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call843();
}
void after_call843()
{// after_call843
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
s.restore(ENV);// (restore env)
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "var"), registers[ENV]));// (assign val (op lookup_variable_value) (const var) (reg env))
assign(ARGL, cons(registers[VAL], registers[ARGL]));// (assign argl (op cons) (reg val) (reg argl))
s.restore(PROC);// (restore proc)
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH844");
}// (branch (label primitive_branch844))
compiled_branch845();
}
void compiled_branch845()
{// compiled_branch845
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL846"));// (assign continue (label after_call846))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch844()
{// primitive_branch844
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call846();
}
void after_call846()
{// after_call846
s.restore(ENV);// (restore env)
s.restore(CONTINUE);// (restore continue)
if ( false_p(registers[VAL]) ) {// (test (op false_p) (reg val))
return goto_with_label("FALSE_BRANCH839");
}// (branch (label false_branch839))
true_branch838();
}
void true_branch838()
{// true_branch838
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "set_car"), registers[ENV]));// (assign proc (op lookup_variable_value) (const set_car) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "val"), registers[ENV]));// (assign val (op lookup_variable_value) (const val) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "vals"), registers[ENV]));// (assign val (op lookup_variable_value) (const vals) (reg env))
assign(ARGL, cons(registers[VAL], registers[ARGL]));// (assign argl (op cons) (reg val) (reg argl))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH847");
}// (branch (label primitive_branch847))
compiled_branch848();
}
void compiled_branch848()
{// compiled_branch848
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch847()
{// primitive_branch847
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call849();
}
void after_call849()
{// after_call849

}
void false_branch839()
{// false_branch839
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "scan"), registers[ENV]));// (assign proc (op lookup_variable_value) (const scan) (reg env))
s.save(CONTINUE);// (save continue)
s.save(PROC);// (save proc)
s.save(ENV);// (save env)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "cdr"), registers[ENV]));// (assign proc (op lookup_variable_value) (const cdr) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "vals"), registers[ENV]));// (assign val (op lookup_variable_value) (const vals) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH853");
}// (branch (label primitive_branch853))
compiled_branch854();
}
void compiled_branch854()
{// compiled_branch854
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL855"));// (assign continue (label after_call855))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch853()
{// primitive_branch853
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call855();
}
void after_call855()
{// after_call855
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
s.restore(ENV);// (restore env)
s.save(ARGL);// (save argl)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "cdr"), registers[ENV]));// (assign proc (op lookup_variable_value) (const cdr) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "vars"), registers[ENV]));// (assign val (op lookup_variable_value) (const vars) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH850");
}// (branch (label primitive_branch850))
compiled_branch851();
}
void compiled_branch851()
{// compiled_branch851
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL852"));// (assign continue (label after_call852))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch850()
{// primitive_branch850
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call852();
}
void after_call852()
{// after_call852
s.restore(ARGL);// (restore argl)
assign(ARGL, cons(registers[VAL], registers[ARGL]));// (assign argl (op cons) (reg val) (reg argl))
s.restore(PROC);// (restore proc)
s.restore(CONTINUE);// (restore continue)
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH856");
}// (branch (label primitive_branch856))
compiled_branch857();
}
void compiled_branch857()
{// compiled_branch857
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch856()
{// primitive_branch856
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call858();
}
void after_call858()
{// after_call858
after_if840();
}
void after_if840()
{// after_if840
after_if828();
}
void after_if828()
{// after_if828
after_lambda825();
}
void after_lambda825()
{// after_lambda825
define_variable(new SchemeDataType(SchemeDataType::TypeId::Symbol, "scan"), registers[VAL], registers[ENV]);// (perform (op define_variable) (const scan) (reg val) (reg env))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "ok"));// (assign val (const ok))
s.save(CONTINUE);// (save continue)
s.save(ENV);// (save env)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "eq_p"), registers[ENV]));// (assign proc (op lookup_variable_value) (const eq_p) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "the_empty_environment"), registers[ENV]));// (assign val (op lookup_variable_value) (const the_empty_environment) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "env"), registers[ENV]));// (assign val (op lookup_variable_value) (const env) (reg env))
assign(ARGL, cons(registers[VAL], registers[ARGL]));// (assign argl (op cons) (reg val) (reg argl))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH862");
}// (branch (label primitive_branch862))
compiled_branch863();
}
void compiled_branch863()
{// compiled_branch863
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL864"));// (assign continue (label after_call864))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch862()
{// primitive_branch862
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call864();
}
void after_call864()
{// after_call864
s.restore(ENV);// (restore env)
s.restore(CONTINUE);// (restore continue)
if ( false_p(registers[VAL]) ) {// (test (op false_p) (reg val))
return goto_with_label("FALSE_BRANCH860");
}// (branch (label false_branch860))
true_branch859();
}
void true_branch859()
{// true_branch859
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "error"), registers[ENV]));// (assign proc (op lookup_variable_value) (const error) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "var"), registers[ENV]));// (assign val (op lookup_variable_value) (const var) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "Unbound variable __ SET"));// (assign val (const Unbound variable __ SET))
assign(ARGL, cons(registers[VAL], registers[ARGL]));// (assign argl (op cons) (reg val) (reg argl))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH865");
}// (branch (label primitive_branch865))
compiled_branch866();
}
void compiled_branch866()
{// compiled_branch866
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch865()
{// primitive_branch865
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call867();
}
void after_call867()
{// after_call867

}
void false_branch860()
{// false_branch860
assign(PROC, make_compiled_procedure("ENTRY868", entry868, registers[ENV]));// (assign proc (op make_compiled_procedure) (label entry868) (reg env))
goto_with_label("AFTER_LAMBDA869");// (goto (label after_lambda869))

}
void entry868()
{// entry868
assign(ENV, compiled_procedure_env(PROC));// (assign env (op compiled_procedure_env) (reg proc))
assign(ENV, extend_environment(list(1, new SchemeDataType(SchemeDataType::TypeId::Symbol, "frame")), registers[ARGL], registers[ENV]));// (assign env (op extend_environment) (const frame) (reg argl) (reg env))
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "scan"), registers[ENV]));// (assign proc (op lookup_variable_value) (const scan) (reg env))
s.save(CONTINUE);// (save continue)
s.save(PROC);// (save proc)
s.save(ENV);// (save env)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "frame_values"), registers[ENV]));// (assign proc (op lookup_variable_value) (const frame_values) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "frame"), registers[ENV]));// (assign val (op lookup_variable_value) (const frame) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH873");
}// (branch (label primitive_branch873))
compiled_branch874();
}
void compiled_branch874()
{// compiled_branch874
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL875"));// (assign continue (label after_call875))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch873()
{// primitive_branch873
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call875();
}
void after_call875()
{// after_call875
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
s.restore(ENV);// (restore env)
s.save(ARGL);// (save argl)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "frame_variables"), registers[ENV]));// (assign proc (op lookup_variable_value) (const frame_variables) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "frame"), registers[ENV]));// (assign val (op lookup_variable_value) (const frame) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH870");
}// (branch (label primitive_branch870))
compiled_branch871();
}
void compiled_branch871()
{// compiled_branch871
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL872"));// (assign continue (label after_call872))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch870()
{// primitive_branch870
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call872();
}
void after_call872()
{// after_call872
s.restore(ARGL);// (restore argl)
assign(ARGL, cons(registers[VAL], registers[ARGL]));// (assign argl (op cons) (reg val) (reg argl))
s.restore(PROC);// (restore proc)
s.restore(CONTINUE);// (restore continue)
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH876");
}// (branch (label primitive_branch876))
compiled_branch877();
}
void compiled_branch877()
{// compiled_branch877
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch876()
{// primitive_branch876
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call878();
}
void after_call878()
{// after_call878
after_lambda869();
}
void after_lambda869()
{// after_lambda869
s.save(CONTINUE);// (save continue)
s.save(PROC);// (save proc)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "first_frame"), registers[ENV]));// (assign proc (op lookup_variable_value) (const first_frame) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "env"), registers[ENV]));// (assign val (op lookup_variable_value) (const env) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH879");
}// (branch (label primitive_branch879))
compiled_branch880();
}
void compiled_branch880()
{// compiled_branch880
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL881"));// (assign continue (label after_call881))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch879()
{// primitive_branch879
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call881();
}
void after_call881()
{// after_call881
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
s.restore(PROC);// (restore proc)
s.restore(CONTINUE);// (restore continue)
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH882");
}// (branch (label primitive_branch882))
compiled_branch883();
}
void compiled_branch883()
{// compiled_branch883
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch882()
{// primitive_branch882
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call884();
}
void after_call884()
{// after_call884
after_if861();
}
void after_if861()
{// after_if861
after_lambda823();
}
void after_lambda823()
{// after_lambda823
define_variable(new SchemeDataType(SchemeDataType::TypeId::Symbol, "env_loop"), registers[VAL], registers[ENV]);// (perform (op define_variable) (const env_loop) (reg val) (reg env))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "ok"));// (assign val (const ok))
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "env_loop"), registers[ENV]));// (assign proc (op lookup_variable_value) (const env_loop) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "env"), registers[ENV]));// (assign val (op lookup_variable_value) (const env) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH885");
}// (branch (label primitive_branch885))
compiled_branch886();
}
void compiled_branch886()
{// compiled_branch886
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch885()
{// primitive_branch885
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call887();
}
void after_call887()
{// after_call887
after_lambda821();
}
void after_lambda821()
{// after_lambda821
define_variable(new SchemeDataType(SchemeDataType::TypeId::Symbol, "set_variable_value"), registers[VAL], registers[ENV]);// (perform (op define_variable) (const set_variable_value) (reg val) (reg env))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "ok"));// (assign val (const ok))
assign(VAL, make_compiled_procedure("ENTRY888", entry888, registers[ENV]));// (assign val (op make_compiled_procedure) (label entry888) (reg env))
goto_with_label("AFTER_LAMBDA889");// (goto (label after_lambda889))

}
void entry888()
{// entry888
assign(ENV, compiled_procedure_env(PROC));// (assign env (op compiled_procedure_env) (reg proc))
assign(ENV, extend_environment(list(3, new SchemeDataType(SchemeDataType::TypeId::Symbol, "var"), new SchemeDataType(SchemeDataType::TypeId::Symbol, "val"), new SchemeDataType(SchemeDataType::TypeId::Symbol, "env")), registers[ARGL], registers[ENV]));// (assign env (op extend_environment) (const (var val env)) (reg argl) (reg env))
assign(VAL, make_compiled_procedure("ENTRY890", entry890, registers[ENV]));// (assign val (op make_compiled_procedure) (label entry890) (reg env))
goto_with_label("AFTER_LAMBDA891");// (goto (label after_lambda891))

}
void entry890()
{// entry890
assign(ENV, compiled_procedure_env(PROC));// (assign env (op compiled_procedure_env) (reg proc))
assign(ENV, extend_environment(list(2, new SchemeDataType(SchemeDataType::TypeId::Symbol, "vars"), new SchemeDataType(SchemeDataType::TypeId::Symbol, "vals")), registers[ARGL], registers[ENV]));// (assign env (op extend_environment) (const (vars vals)) (reg argl) (reg env))
s.save(CONTINUE);// (save continue)
s.save(ENV);// (save env)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "null_p"), registers[ENV]));// (assign proc (op lookup_variable_value) (const null_p) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "vars"), registers[ENV]));// (assign val (op lookup_variable_value) (const vars) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH895");
}// (branch (label primitive_branch895))
compiled_branch896();
}
void compiled_branch896()
{// compiled_branch896
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL897"));// (assign continue (label after_call897))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch895()
{// primitive_branch895
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call897();
}
void after_call897()
{// after_call897
s.restore(ENV);// (restore env)
s.restore(CONTINUE);// (restore continue)
if ( false_p(registers[VAL]) ) {// (test (op false_p) (reg val))
return goto_with_label("FALSE_BRANCH893");
}// (branch (label false_branch893))
true_branch892();
}
void true_branch892()
{// true_branch892
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "add_binding_to_frame"), registers[ENV]));// (assign proc (op lookup_variable_value) (const add_binding_to_frame) (reg env))
s.save(CONTINUE);// (save continue)
s.save(PROC);// (save proc)
s.save(ENV);// (save env)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "first_frame"), registers[ENV]));// (assign proc (op lookup_variable_value) (const first_frame) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "env"), registers[ENV]));// (assign val (op lookup_variable_value) (const env) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH898");
}// (branch (label primitive_branch898))
compiled_branch899();
}
void compiled_branch899()
{// compiled_branch899
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL900"));// (assign continue (label after_call900))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch898()
{// primitive_branch898
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call900();
}
void after_call900()
{// after_call900
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
s.restore(ENV);// (restore env)
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "val"), registers[ENV]));// (assign val (op lookup_variable_value) (const val) (reg env))
assign(ARGL, cons(registers[VAL], registers[ARGL]));// (assign argl (op cons) (reg val) (reg argl))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "var"), registers[ENV]));// (assign val (op lookup_variable_value) (const var) (reg env))
assign(ARGL, cons(registers[VAL], registers[ARGL]));// (assign argl (op cons) (reg val) (reg argl))
s.restore(PROC);// (restore proc)
s.restore(CONTINUE);// (restore continue)
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH901");
}// (branch (label primitive_branch901))
compiled_branch902();
}
void compiled_branch902()
{// compiled_branch902
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch901()
{// primitive_branch901
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call903();
}
void after_call903()
{// after_call903

}
void false_branch893()
{// false_branch893
s.save(CONTINUE);// (save continue)
s.save(ENV);// (save env)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "eq_p"), registers[ENV]));// (assign proc (op lookup_variable_value) (const eq_p) (reg env))
s.save(PROC);// (save proc)
s.save(ENV);// (save env)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "car"), registers[ENV]));// (assign proc (op lookup_variable_value) (const car) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "vars"), registers[ENV]));// (assign val (op lookup_variable_value) (const vars) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH907");
}// (branch (label primitive_branch907))
compiled_branch908();
}
void compiled_branch908()
{// compiled_branch908
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL909"));// (assign continue (label after_call909))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch907()
{// primitive_branch907
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call909();
}
void after_call909()
{// after_call909
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
s.restore(ENV);// (restore env)
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "var"), registers[ENV]));// (assign val (op lookup_variable_value) (const var) (reg env))
assign(ARGL, cons(registers[VAL], registers[ARGL]));// (assign argl (op cons) (reg val) (reg argl))
s.restore(PROC);// (restore proc)
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH910");
}// (branch (label primitive_branch910))
compiled_branch911();
}
void compiled_branch911()
{// compiled_branch911
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL912"));// (assign continue (label after_call912))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch910()
{// primitive_branch910
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call912();
}
void after_call912()
{// after_call912
s.restore(ENV);// (restore env)
s.restore(CONTINUE);// (restore continue)
if ( false_p(registers[VAL]) ) {// (test (op false_p) (reg val))
return goto_with_label("FALSE_BRANCH905");
}// (branch (label false_branch905))
true_branch904();
}
void true_branch904()
{// true_branch904
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "set_car"), registers[ENV]));// (assign proc (op lookup_variable_value) (const set_car) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "val"), registers[ENV]));// (assign val (op lookup_variable_value) (const val) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "vals"), registers[ENV]));// (assign val (op lookup_variable_value) (const vals) (reg env))
assign(ARGL, cons(registers[VAL], registers[ARGL]));// (assign argl (op cons) (reg val) (reg argl))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH913");
}// (branch (label primitive_branch913))
compiled_branch914();
}
void compiled_branch914()
{// compiled_branch914
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch913()
{// primitive_branch913
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call915();
}
void after_call915()
{// after_call915

}
void false_branch905()
{// false_branch905
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "scan"), registers[ENV]));// (assign proc (op lookup_variable_value) (const scan) (reg env))
s.save(CONTINUE);// (save continue)
s.save(PROC);// (save proc)
s.save(ENV);// (save env)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "cdr"), registers[ENV]));// (assign proc (op lookup_variable_value) (const cdr) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "vals"), registers[ENV]));// (assign val (op lookup_variable_value) (const vals) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH919");
}// (branch (label primitive_branch919))
compiled_branch920();
}
void compiled_branch920()
{// compiled_branch920
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL921"));// (assign continue (label after_call921))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch919()
{// primitive_branch919
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call921();
}
void after_call921()
{// after_call921
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
s.restore(ENV);// (restore env)
s.save(ARGL);// (save argl)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "cdr"), registers[ENV]));// (assign proc (op lookup_variable_value) (const cdr) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "vars"), registers[ENV]));// (assign val (op lookup_variable_value) (const vars) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH916");
}// (branch (label primitive_branch916))
compiled_branch917();
}
void compiled_branch917()
{// compiled_branch917
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL918"));// (assign continue (label after_call918))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch916()
{// primitive_branch916
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call918();
}
void after_call918()
{// after_call918
s.restore(ARGL);// (restore argl)
assign(ARGL, cons(registers[VAL], registers[ARGL]));// (assign argl (op cons) (reg val) (reg argl))
s.restore(PROC);// (restore proc)
s.restore(CONTINUE);// (restore continue)
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH922");
}// (branch (label primitive_branch922))
compiled_branch923();
}
void compiled_branch923()
{// compiled_branch923
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch922()
{// primitive_branch922
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call924();
}
void after_call924()
{// after_call924
after_if906();
}
void after_if906()
{// after_if906
after_if894();
}
void after_if894()
{// after_if894
after_lambda891();
}
void after_lambda891()
{// after_lambda891
define_variable(new SchemeDataType(SchemeDataType::TypeId::Symbol, "scan"), registers[VAL], registers[ENV]);// (perform (op define_variable) (const scan) (reg val) (reg env))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "ok"));// (assign val (const ok))
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "scan"), registers[ENV]));// (assign proc (op lookup_variable_value) (const scan) (reg env))
s.save(CONTINUE);// (save continue)
s.save(PROC);// (save proc)
s.save(ENV);// (save env)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "frame_values"), registers[ENV]));// (assign proc (op lookup_variable_value) (const frame_values) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "frame"), registers[ENV]));// (assign val (op lookup_variable_value) (const frame) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH931");
}// (branch (label primitive_branch931))
compiled_branch932();
}
void compiled_branch932()
{// compiled_branch932
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL933"));// (assign continue (label after_call933))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch931()
{// primitive_branch931
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call933();
}
void after_call933()
{// after_call933
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
s.restore(ENV);// (restore env)
s.save(ARGL);// (save argl)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "frame_variables"), registers[ENV]));// (assign proc (op lookup_variable_value) (const frame_variables) (reg env))
s.save(PROC);// (save proc)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "first_frame"), registers[ENV]));// (assign proc (op lookup_variable_value) (const first_frame) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "env"), registers[ENV]));// (assign val (op lookup_variable_value) (const env) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH925");
}// (branch (label primitive_branch925))
compiled_branch926();
}
void compiled_branch926()
{// compiled_branch926
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL927"));// (assign continue (label after_call927))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch925()
{// primitive_branch925
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call927();
}
void after_call927()
{// after_call927
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
s.restore(PROC);// (restore proc)
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH928");
}// (branch (label primitive_branch928))
compiled_branch929();
}
void compiled_branch929()
{// compiled_branch929
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL930"));// (assign continue (label after_call930))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch928()
{// primitive_branch928
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call930();
}
void after_call930()
{// after_call930
s.restore(ARGL);// (restore argl)
assign(ARGL, cons(registers[VAL], registers[ARGL]));// (assign argl (op cons) (reg val) (reg argl))
s.restore(PROC);// (restore proc)
s.restore(CONTINUE);// (restore continue)
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH934");
}// (branch (label primitive_branch934))
compiled_branch935();
}
void compiled_branch935()
{// compiled_branch935
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch934()
{// primitive_branch934
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call936();
}
void after_call936()
{// after_call936
after_lambda889();
}
void after_lambda889()
{// after_lambda889
define_variable(new SchemeDataType(SchemeDataType::TypeId::Symbol, "define_variable"), registers[VAL], registers[ENV]);// (perform (op define_variable) (const define_variable) (reg val) (reg env))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "ok"));// (assign val (const ok))
assign(VAL, make_compiled_procedure("ENTRY937", entry937, registers[ENV]));// (assign val (op make_compiled_procedure) (label entry937) (reg env))
goto_with_label("AFTER_LAMBDA938");// (goto (label after_lambda938))

}
void entry937()
{// entry937
assign(ENV, compiled_procedure_env(PROC));// (assign env (op compiled_procedure_env) (reg proc))
assign(ENV, extend_environment(list(1, new SchemeDataType(SchemeDataType::TypeId::Nil)), registers[ARGL], registers[ENV]));// (assign env (op extend_environment) (const nil ) (reg argl) (reg env))
s.save(CONTINUE);// (save continue)
s.save(ENV);// (save env)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "define_variable"), registers[ENV]));// (assign proc (op lookup_variable_value) (const define_variable) (reg env))
s.save(PROC);// (save proc)
s.save(ENV);// (save env)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "extend_environment"), registers[ENV]));// (assign proc (op lookup_variable_value) (const extend_environment) (reg env))
s.save(PROC);// (save proc)
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "the_empty_environment"), registers[ENV]));// (assign val (op lookup_variable_value) (const the_empty_environment) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
s.save(ENV);// (save env)
s.save(ARGL);// (save argl)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "primitive_procedure_objects"), registers[ENV]));// (assign proc (op lookup_variable_value) (const primitive_procedure_objects) (reg env))
assign(ARGL, new SchemeDataType(SchemeDataType::TypeId::Nil));// (assign argl (const nil ))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH942");
}// (branch (label primitive_branch942))
compiled_branch943();
}
void compiled_branch943()
{// compiled_branch943
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL944"));// (assign continue (label after_call944))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch942()
{// primitive_branch942
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call944();
}
void after_call944()
{// after_call944
s.restore(ARGL);// (restore argl)
assign(ARGL, cons(registers[VAL], registers[ARGL]));// (assign argl (op cons) (reg val) (reg argl))
s.restore(ENV);// (restore env)
s.save(ARGL);// (save argl)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "primitive_procedure_names"), registers[ENV]));// (assign proc (op lookup_variable_value) (const primitive_procedure_names) (reg env))
assign(ARGL, new SchemeDataType(SchemeDataType::TypeId::Nil));// (assign argl (const nil ))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH939");
}// (branch (label primitive_branch939))
compiled_branch940();
}
void compiled_branch940()
{// compiled_branch940
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL941"));// (assign continue (label after_call941))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch939()
{// primitive_branch939
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call941();
}
void after_call941()
{// after_call941
s.restore(ARGL);// (restore argl)
assign(ARGL, cons(registers[VAL], registers[ARGL]));// (assign argl (op cons) (reg val) (reg argl))
s.restore(PROC);// (restore proc)
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH945");
}// (branch (label primitive_branch945))
compiled_branch946();
}
void compiled_branch946()
{// compiled_branch946
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL947"));// (assign continue (label after_call947))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch945()
{// primitive_branch945
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call947();
}
void after_call947()
{// after_call947
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
s.restore(ENV);// (restore env)
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "true"), registers[ENV]));// (assign val (op lookup_variable_value) (const true) (reg env))
assign(ARGL, cons(registers[VAL], registers[ARGL]));// (assign argl (op cons) (reg val) (reg argl))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "true"));// (assign val (const true))
assign(ARGL, cons(registers[VAL], registers[ARGL]));// (assign argl (op cons) (reg val) (reg argl))
s.restore(PROC);// (restore proc)
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH948");
}// (branch (label primitive_branch948))
compiled_branch949();
}
void compiled_branch949()
{// compiled_branch949
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL950"));// (assign continue (label after_call950))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch948()
{// primitive_branch948
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call950();
}
void after_call950()
{// after_call950
s.restore(ENV);// (restore env)
s.restore(CONTINUE);// (restore continue)
s.save(CONTINUE);// (save continue)
s.save(ENV);// (save env)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "define_variable"), registers[ENV]));// (assign proc (op lookup_variable_value) (const define_variable) (reg env))
s.save(PROC);// (save proc)
s.save(ENV);// (save env)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "extend_environment"), registers[ENV]));// (assign proc (op lookup_variable_value) (const extend_environment) (reg env))
s.save(PROC);// (save proc)
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "the_empty_environment"), registers[ENV]));// (assign val (op lookup_variable_value) (const the_empty_environment) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
s.save(ENV);// (save env)
s.save(ARGL);// (save argl)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "primitive_procedure_objects"), registers[ENV]));// (assign proc (op lookup_variable_value) (const primitive_procedure_objects) (reg env))
assign(ARGL, new SchemeDataType(SchemeDataType::TypeId::Nil));// (assign argl (const nil ))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH954");
}// (branch (label primitive_branch954))
compiled_branch955();
}
void compiled_branch955()
{// compiled_branch955
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL956"));// (assign continue (label after_call956))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch954()
{// primitive_branch954
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call956();
}
void after_call956()
{// after_call956
s.restore(ARGL);// (restore argl)
assign(ARGL, cons(registers[VAL], registers[ARGL]));// (assign argl (op cons) (reg val) (reg argl))
s.restore(ENV);// (restore env)
s.save(ARGL);// (save argl)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "primitive_procedure_names"), registers[ENV]));// (assign proc (op lookup_variable_value) (const primitive_procedure_names) (reg env))
assign(ARGL, new SchemeDataType(SchemeDataType::TypeId::Nil));// (assign argl (const nil ))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH951");
}// (branch (label primitive_branch951))
compiled_branch952();
}
void compiled_branch952()
{// compiled_branch952
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL953"));// (assign continue (label after_call953))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch951()
{// primitive_branch951
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call953();
}
void after_call953()
{// after_call953
s.restore(ARGL);// (restore argl)
assign(ARGL, cons(registers[VAL], registers[ARGL]));// (assign argl (op cons) (reg val) (reg argl))
s.restore(PROC);// (restore proc)
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH957");
}// (branch (label primitive_branch957))
compiled_branch958();
}
void compiled_branch958()
{// compiled_branch958
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL959"));// (assign continue (label after_call959))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch957()
{// primitive_branch957
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call959();
}
void after_call959()
{// after_call959
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
s.restore(ENV);// (restore env)
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "false"), registers[ENV]));// (assign val (op lookup_variable_value) (const false) (reg env))
assign(ARGL, cons(registers[VAL], registers[ARGL]));// (assign argl (op cons) (reg val) (reg argl))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "false"));// (assign val (const false))
assign(ARGL, cons(registers[VAL], registers[ARGL]));// (assign argl (op cons) (reg val) (reg argl))
s.restore(PROC);// (restore proc)
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH960");
}// (branch (label primitive_branch960))
compiled_branch961();
}
void compiled_branch961()
{// compiled_branch961
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL962"));// (assign continue (label after_call962))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch960()
{// primitive_branch960
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call962();
}
void after_call962()
{// after_call962
s.restore(ENV);// (restore env)
s.restore(CONTINUE);// (restore continue)
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "initial_env"), registers[ENV]));// (assign val (op lookup_variable_value) (const initial_env) (reg env))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_lambda938();
}
void after_lambda938()
{// after_lambda938
define_variable(new SchemeDataType(SchemeDataType::TypeId::Symbol, "setup_environment"), registers[VAL], registers[ENV]);// (perform (op define_variable) (const setup_environment) (reg val) (reg env))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "ok"));// (assign val (const ok))
assign(VAL, make_compiled_procedure("ENTRY963", entry963, registers[ENV]));// (assign val (op make_compiled_procedure) (label entry963) (reg env))
goto_with_label("AFTER_LAMBDA964");// (goto (label after_lambda964))

}
void entry963()
{// entry963
assign(ENV, compiled_procedure_env(PROC));// (assign env (op compiled_procedure_env) (reg proc))
assign(ENV, extend_environment(list(1, new SchemeDataType(SchemeDataType::TypeId::Symbol, "proc")), registers[ARGL], registers[ENV]));// (assign env (op extend_environment) (const proc) (reg argl) (reg env))
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "tagged_list_p"), registers[ENV]));// (assign proc (op lookup_variable_value) (const tagged_list_p) (reg env))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "primitive"));// (assign val (const primitive))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "proc"), registers[ENV]));// (assign val (op lookup_variable_value) (const proc) (reg env))
assign(ARGL, cons(registers[VAL], registers[ARGL]));// (assign argl (op cons) (reg val) (reg argl))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH965");
}// (branch (label primitive_branch965))
compiled_branch966();
}
void compiled_branch966()
{// compiled_branch966
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch965()
{// primitive_branch965
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call967();
}
void after_call967()
{// after_call967
after_lambda964();
}
void after_lambda964()
{// after_lambda964
define_variable(new SchemeDataType(SchemeDataType::TypeId::Symbol, "primitive_procedure_p"), registers[VAL], registers[ENV]);// (perform (op define_variable) (const primitive_procedure_p) (reg val) (reg env))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "ok"));// (assign val (const ok))
assign(VAL, make_compiled_procedure("ENTRY968", entry968, registers[ENV]));// (assign val (op make_compiled_procedure) (label entry968) (reg env))
goto_with_label("AFTER_LAMBDA969");// (goto (label after_lambda969))

}
void entry968()
{// entry968
assign(ENV, compiled_procedure_env(PROC));// (assign env (op compiled_procedure_env) (reg proc))
assign(ENV, extend_environment(list(1, new SchemeDataType(SchemeDataType::TypeId::Symbol, "proc")), registers[ARGL], registers[ENV]));// (assign env (op extend_environment) (const proc) (reg argl) (reg env))
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "cadr"), registers[ENV]));// (assign proc (op lookup_variable_value) (const cadr) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "proc"), registers[ENV]));// (assign val (op lookup_variable_value) (const proc) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH970");
}// (branch (label primitive_branch970))
compiled_branch971();
}
void compiled_branch971()
{// compiled_branch971
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch970()
{// primitive_branch970
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call972();
}
void after_call972()
{// after_call972
after_lambda969();
}
void after_lambda969()
{// after_lambda969
define_variable(new SchemeDataType(SchemeDataType::TypeId::Symbol, "primitive_implementation"), registers[VAL], registers[ENV]);// (perform (op define_variable) (const primitive_implementation) (reg val) (reg env))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "ok"));// (assign val (const ok))
s.save(ENV);// (save env)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "list"), registers[ENV]));// (assign proc (op lookup_variable_value) (const list) (reg env))
s.save(PROC);// (save proc)
s.save(ENV);// (save env)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "list"), registers[ENV]));// (assign proc (op lookup_variable_value) (const list) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "null_p"), registers[ENV]));// (assign val (op lookup_variable_value) (const null_p) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "null_p"));// (assign val (const null_p))
assign(ARGL, cons(registers[VAL], registers[ARGL]));// (assign argl (op cons) (reg val) (reg argl))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH982");
}// (branch (label primitive_branch982))
compiled_branch983();
}
void compiled_branch983()
{// compiled_branch983
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL984"));// (assign continue (label after_call984))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch982()
{// primitive_branch982
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call984();
}
void after_call984()
{// after_call984
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
s.restore(ENV);// (restore env)
s.save(ENV);// (save env)
s.save(ARGL);// (save argl)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "list"), registers[ENV]));// (assign proc (op lookup_variable_value) (const list) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "cons"), registers[ENV]));// (assign val (op lookup_variable_value) (const cons) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "cons"));// (assign val (const cons))
assign(ARGL, cons(registers[VAL], registers[ARGL]));// (assign argl (op cons) (reg val) (reg argl))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH979");
}// (branch (label primitive_branch979))
compiled_branch980();
}
void compiled_branch980()
{// compiled_branch980
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL981"));// (assign continue (label after_call981))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch979()
{// primitive_branch979
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call981();
}
void after_call981()
{// after_call981
s.restore(ARGL);// (restore argl)
assign(ARGL, cons(registers[VAL], registers[ARGL]));// (assign argl (op cons) (reg val) (reg argl))
s.restore(ENV);// (restore env)
s.save(ENV);// (save env)
s.save(ARGL);// (save argl)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "list"), registers[ENV]));// (assign proc (op lookup_variable_value) (const list) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "cdr"), registers[ENV]));// (assign val (op lookup_variable_value) (const cdr) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "cdr"));// (assign val (const cdr))
assign(ARGL, cons(registers[VAL], registers[ARGL]));// (assign argl (op cons) (reg val) (reg argl))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH976");
}// (branch (label primitive_branch976))
compiled_branch977();
}
void compiled_branch977()
{// compiled_branch977
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL978"));// (assign continue (label after_call978))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch976()
{// primitive_branch976
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call978();
}
void after_call978()
{// after_call978
s.restore(ARGL);// (restore argl)
assign(ARGL, cons(registers[VAL], registers[ARGL]));// (assign argl (op cons) (reg val) (reg argl))
s.restore(ENV);// (restore env)
s.save(ARGL);// (save argl)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "list"), registers[ENV]));// (assign proc (op lookup_variable_value) (const list) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "car"), registers[ENV]));// (assign val (op lookup_variable_value) (const car) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "car"));// (assign val (const car))
assign(ARGL, cons(registers[VAL], registers[ARGL]));// (assign argl (op cons) (reg val) (reg argl))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH973");
}// (branch (label primitive_branch973))
compiled_branch974();
}
void compiled_branch974()
{// compiled_branch974
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL975"));// (assign continue (label after_call975))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch973()
{// primitive_branch973
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call975();
}
void after_call975()
{// after_call975
s.restore(ARGL);// (restore argl)
assign(ARGL, cons(registers[VAL], registers[ARGL]));// (assign argl (op cons) (reg val) (reg argl))
s.restore(PROC);// (restore proc)
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH985");
}// (branch (label primitive_branch985))
compiled_branch986();
}
void compiled_branch986()
{// compiled_branch986
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL987"));// (assign continue (label after_call987))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch985()
{// primitive_branch985
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call987();
}
void after_call987()
{// after_call987
s.restore(ENV);// (restore env)
define_variable(new SchemeDataType(SchemeDataType::TypeId::Symbol, "primitive_procedures"), registers[VAL], registers[ENV]);// (perform (op define_variable) (const primitive_procedures) (reg val) (reg env))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "ok"));// (assign val (const ok))
assign(VAL, make_compiled_procedure("ENTRY988", entry988, registers[ENV]));// (assign val (op make_compiled_procedure) (label entry988) (reg env))
goto_with_label("AFTER_LAMBDA989");// (goto (label after_lambda989))

}
void entry988()
{// entry988
assign(ENV, compiled_procedure_env(PROC));// (assign env (op compiled_procedure_env) (reg proc))
assign(ENV, extend_environment(list(1, new SchemeDataType(SchemeDataType::TypeId::Nil)), registers[ARGL], registers[ENV]));// (assign env (op extend_environment) (const nil ) (reg argl) (reg env))
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "map"), registers[ENV]));// (assign proc (op lookup_variable_value) (const map) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "primitive_procedures"), registers[ENV]));// (assign val (op lookup_variable_value) (const primitive_procedures) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "car"), registers[ENV]));// (assign val (op lookup_variable_value) (const car) (reg env))
assign(ARGL, cons(registers[VAL], registers[ARGL]));// (assign argl (op cons) (reg val) (reg argl))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH990");
}// (branch (label primitive_branch990))
compiled_branch991();
}
void compiled_branch991()
{// compiled_branch991
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch990()
{// primitive_branch990
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call992();
}
void after_call992()
{// after_call992
after_lambda989();
}
void after_lambda989()
{// after_lambda989
define_variable(new SchemeDataType(SchemeDataType::TypeId::Symbol, "primitive_procedure_names"), registers[VAL], registers[ENV]);// (perform (op define_variable) (const primitive_procedure_names) (reg val) (reg env))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "ok"));// (assign val (const ok))
assign(VAL, make_compiled_procedure("ENTRY993", entry993, registers[ENV]));// (assign val (op make_compiled_procedure) (label entry993) (reg env))
goto_with_label("AFTER_LAMBDA994");// (goto (label after_lambda994))

}
void entry993()
{// entry993
assign(ENV, compiled_procedure_env(PROC));// (assign env (op compiled_procedure_env) (reg proc))
assign(ENV, extend_environment(list(1, new SchemeDataType(SchemeDataType::TypeId::Nil)), registers[ARGL], registers[ENV]));// (assign env (op extend_environment) (const nil ) (reg argl) (reg env))
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "map"), registers[ENV]));// (assign proc (op lookup_variable_value) (const map) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "primitive_procedures"), registers[ENV]));// (assign val (op lookup_variable_value) (const primitive_procedures) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
assign(VAL, make_compiled_procedure("ENTRY995", entry995, registers[ENV]));// (assign val (op make_compiled_procedure) (label entry995) (reg env))
goto_with_label("AFTER_LAMBDA996");// (goto (label after_lambda996))

}
void entry995()
{// entry995
assign(ENV, compiled_procedure_env(PROC));// (assign env (op compiled_procedure_env) (reg proc))
assign(ENV, extend_environment(list(1, new SchemeDataType(SchemeDataType::TypeId::Symbol, "proc")), registers[ARGL], registers[ENV]));// (assign env (op extend_environment) (const proc) (reg argl) (reg env))
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "list"), registers[ENV]));// (assign proc (op lookup_variable_value) (const list) (reg env))
s.save(CONTINUE);// (save continue)
s.save(PROC);// (save proc)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "cadr"), registers[ENV]));// (assign proc (op lookup_variable_value) (const cadr) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "proc"), registers[ENV]));// (assign val (op lookup_variable_value) (const proc) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH997");
}// (branch (label primitive_branch997))
compiled_branch998();
}
void compiled_branch998()
{// compiled_branch998
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL999"));// (assign continue (label after_call999))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch997()
{// primitive_branch997
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call999();
}
void after_call999()
{// after_call999
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "primitive"));// (assign val (const primitive))
assign(ARGL, cons(registers[VAL], registers[ARGL]));// (assign argl (op cons) (reg val) (reg argl))
s.restore(PROC);// (restore proc)
s.restore(CONTINUE);// (restore continue)
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH1000");
}// (branch (label primitive_branch1000))
compiled_branch1001();
}
void compiled_branch1001()
{// compiled_branch1001
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch1000()
{// primitive_branch1000
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call1002();
}
void after_call1002()
{// after_call1002
after_lambda996();
}
void after_lambda996()
{// after_lambda996
assign(ARGL, cons(registers[VAL], registers[ARGL]));// (assign argl (op cons) (reg val) (reg argl))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH1003");
}// (branch (label primitive_branch1003))
compiled_branch1004();
}
void compiled_branch1004()
{// compiled_branch1004
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch1003()
{// primitive_branch1003
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call1005();
}
void after_call1005()
{// after_call1005
after_lambda994();
}
void after_lambda994()
{// after_lambda994
define_variable(new SchemeDataType(SchemeDataType::TypeId::Symbol, "primitive_procedure_objects"), registers[VAL], registers[ENV]);// (perform (op define_variable) (const primitive_procedure_objects) (reg val) (reg env))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "ok"));// (assign val (const ok))
assign(VAL, make_compiled_procedure("ENTRY1006", entry1006, registers[ENV]));// (assign val (op make_compiled_procedure) (label entry1006) (reg env))
goto_with_label("AFTER_LAMBDA1007");// (goto (label after_lambda1007))

}
void entry1006()
{// entry1006
assign(ENV, compiled_procedure_env(PROC));// (assign env (op compiled_procedure_env) (reg proc))
assign(ENV, extend_environment(list(2, new SchemeDataType(SchemeDataType::TypeId::Symbol, "proc"), new SchemeDataType(SchemeDataType::TypeId::Symbol, "args")), registers[ARGL], registers[ENV]));// (assign env (op extend_environment) (const (proc args)) (reg argl) (reg env))
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "apply_in_underlying_scheme"), registers[ENV]));// (assign proc (op lookup_variable_value) (const apply_in_underlying_scheme) (reg env))
s.save(CONTINUE);// (save continue)
s.save(PROC);// (save proc)
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "args"), registers[ENV]));// (assign val (op lookup_variable_value) (const args) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
s.save(ARGL);// (save argl)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "primitive_implementation"), registers[ENV]));// (assign proc (op lookup_variable_value) (const primitive_implementation) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "proc"), registers[ENV]));// (assign val (op lookup_variable_value) (const proc) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH1008");
}// (branch (label primitive_branch1008))
compiled_branch1009();
}
void compiled_branch1009()
{// compiled_branch1009
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL1010"));// (assign continue (label after_call1010))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch1008()
{// primitive_branch1008
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call1010();
}
void after_call1010()
{// after_call1010
s.restore(ARGL);// (restore argl)
assign(ARGL, cons(registers[VAL], registers[ARGL]));// (assign argl (op cons) (reg val) (reg argl))
s.restore(PROC);// (restore proc)
s.restore(CONTINUE);// (restore continue)
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH1011");
}// (branch (label primitive_branch1011))
compiled_branch1012();
}
void compiled_branch1012()
{// compiled_branch1012
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch1011()
{// primitive_branch1011
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call1013();
}
void after_call1013()
{// after_call1013
after_lambda1007();
}
void after_lambda1007()
{// after_lambda1007
define_variable(new SchemeDataType(SchemeDataType::TypeId::Symbol, "apply_primitive_procedure"), registers[VAL], registers[ENV]);// (perform (op define_variable) (const apply_primitive_procedure) (reg val) (reg env))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "ok"));// (assign val (const ok))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, ";;; M_Eval input:"));// (assign val (const ;;; M_Eval input:))
define_variable(new SchemeDataType(SchemeDataType::TypeId::Symbol, "input_prompt"), registers[VAL], registers[ENV]);// (perform (op define_variable) (const input_prompt) (reg val) (reg env))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "ok"));// (assign val (const ok))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, ";;; M_Eval value:"));// (assign val (const ;;; M_Eval value:))
define_variable(new SchemeDataType(SchemeDataType::TypeId::Symbol, "output_prompt"), registers[VAL], registers[ENV]);// (perform (op define_variable) (const output_prompt) (reg val) (reg env))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "ok"));// (assign val (const ok))
assign(VAL, make_compiled_procedure("ENTRY1014", entry1014, registers[ENV]));// (assign val (op make_compiled_procedure) (label entry1014) (reg env))
goto_with_label("AFTER_LAMBDA1015");// (goto (label after_lambda1015))

}
void entry1014()
{// entry1014
assign(ENV, compiled_procedure_env(PROC));// (assign env (op compiled_procedure_env) (reg proc))
assign(ENV, extend_environment(list(1, new SchemeDataType(SchemeDataType::TypeId::Nil)), registers[ARGL], registers[ENV]));// (assign env (op extend_environment) (const nil ) (reg argl) (reg env))
s.save(CONTINUE);// (save continue)
s.save(ENV);// (save env)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "prompt_for_input"), registers[ENV]));// (assign proc (op lookup_variable_value) (const prompt_for_input) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "input_prompt"), registers[ENV]));// (assign val (op lookup_variable_value) (const input_prompt) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH1016");
}// (branch (label primitive_branch1016))
compiled_branch1017();
}
void compiled_branch1017()
{// compiled_branch1017
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL1018"));// (assign continue (label after_call1018))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch1016()
{// primitive_branch1016
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call1018();
}
void after_call1018()
{// after_call1018
s.restore(ENV);// (restore env)
s.restore(CONTINUE);// (restore continue)
assign(PROC, make_compiled_procedure("ENTRY1019", entry1019, registers[ENV]));// (assign proc (op make_compiled_procedure) (label entry1019) (reg env))
goto_with_label("AFTER_LAMBDA1020");// (goto (label after_lambda1020))

}
void entry1019()
{// entry1019
assign(ENV, compiled_procedure_env(PROC));// (assign env (op compiled_procedure_env) (reg proc))
assign(ENV, extend_environment(list(1, new SchemeDataType(SchemeDataType::TypeId::Symbol, "input")), registers[ARGL], registers[ENV]));// (assign env (op extend_environment) (const input) (reg argl) (reg env))
assign(PROC, make_compiled_procedure("ENTRY1021", entry1021, registers[ENV]));// (assign proc (op make_compiled_procedure) (label entry1021) (reg env))
goto_with_label("AFTER_LAMBDA1022");// (goto (label after_lambda1022))

}
void entry1021()
{// entry1021
assign(ENV, compiled_procedure_env(PROC));// (assign env (op compiled_procedure_env) (reg proc))
assign(ENV, extend_environment(list(1, new SchemeDataType(SchemeDataType::TypeId::Symbol, "output")), registers[ARGL], registers[ENV]));// (assign env (op extend_environment) (const output) (reg argl) (reg env))
s.save(CONTINUE);// (save continue)
s.save(ENV);// (save env)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "announce_output"), registers[ENV]));// (assign proc (op lookup_variable_value) (const announce_output) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "output_prompt"), registers[ENV]));// (assign val (op lookup_variable_value) (const output_prompt) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH1023");
}// (branch (label primitive_branch1023))
compiled_branch1024();
}
void compiled_branch1024()
{// compiled_branch1024
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL1025"));// (assign continue (label after_call1025))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch1023()
{// primitive_branch1023
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call1025();
}
void after_call1025()
{// after_call1025
s.restore(ENV);// (restore env)
s.restore(CONTINUE);// (restore continue)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "user_print"), registers[ENV]));// (assign proc (op lookup_variable_value) (const user_print) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "output"), registers[ENV]));// (assign val (op lookup_variable_value) (const output) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH1026");
}// (branch (label primitive_branch1026))
compiled_branch1027();
}
void compiled_branch1027()
{// compiled_branch1027
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch1026()
{// primitive_branch1026
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call1028();
}
void after_call1028()
{// after_call1028
after_lambda1022();
}
void after_lambda1022()
{// after_lambda1022
s.save(CONTINUE);// (save continue)
s.save(PROC);// (save proc)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "eval"), registers[ENV]));// (assign proc (op lookup_variable_value) (const eval) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "the_global_environment"), registers[ENV]));// (assign val (op lookup_variable_value) (const the_global_environment) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "input"), registers[ENV]));// (assign val (op lookup_variable_value) (const input) (reg env))
assign(ARGL, cons(registers[VAL], registers[ARGL]));// (assign argl (op cons) (reg val) (reg argl))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH1029");
}// (branch (label primitive_branch1029))
compiled_branch1030();
}
void compiled_branch1030()
{// compiled_branch1030
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL1031"));// (assign continue (label after_call1031))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch1029()
{// primitive_branch1029
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call1031();
}
void after_call1031()
{// after_call1031
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
s.restore(PROC);// (restore proc)
s.restore(CONTINUE);// (restore continue)
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH1032");
}// (branch (label primitive_branch1032))
compiled_branch1033();
}
void compiled_branch1033()
{// compiled_branch1033
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch1032()
{// primitive_branch1032
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call1034();
}
void after_call1034()
{// after_call1034
after_lambda1020();
}
void after_lambda1020()
{// after_lambda1020
s.save(CONTINUE);// (save continue)
s.save(PROC);// (save proc)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "read"), registers[ENV]));// (assign proc (op lookup_variable_value) (const read) (reg env))
assign(ARGL, new SchemeDataType(SchemeDataType::TypeId::Nil));// (assign argl (const nil ))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH1035");
}// (branch (label primitive_branch1035))
compiled_branch1036();
}
void compiled_branch1036()
{// compiled_branch1036
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL1037"));// (assign continue (label after_call1037))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch1035()
{// primitive_branch1035
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call1037();
}
void after_call1037()
{// after_call1037
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
s.restore(PROC);// (restore proc)
s.restore(CONTINUE);// (restore continue)
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH1038");
}// (branch (label primitive_branch1038))
compiled_branch1039();
}
void compiled_branch1039()
{// compiled_branch1039
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch1038()
{// primitive_branch1038
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call1040();
}
void after_call1040()
{// after_call1040
after_lambda1015();
}
void after_lambda1015()
{// after_lambda1015
define_variable(new SchemeDataType(SchemeDataType::TypeId::Symbol, "driver_loop"), registers[VAL], registers[ENV]);// (perform (op define_variable) (const driver_loop) (reg val) (reg env))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "ok"));// (assign val (const ok))
assign(VAL, make_compiled_procedure("ENTRY1041", entry1041, registers[ENV]));// (assign val (op make_compiled_procedure) (label entry1041) (reg env))
goto_with_label("AFTER_LAMBDA1042");// (goto (label after_lambda1042))

}
void entry1041()
{// entry1041
assign(ENV, compiled_procedure_env(PROC));// (assign env (op compiled_procedure_env) (reg proc))
assign(ENV, extend_environment(list(1, new SchemeDataType(SchemeDataType::TypeId::Symbol, "string")), registers[ARGL], registers[ENV]));// (assign env (op extend_environment) (const string) (reg argl) (reg env))
s.save(CONTINUE);// (save continue)
s.save(ENV);// (save env)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "newline"), registers[ENV]));// (assign proc (op lookup_variable_value) (const newline) (reg env))
assign(ARGL, new SchemeDataType(SchemeDataType::TypeId::Nil));// (assign argl (const nil ))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH1043");
}// (branch (label primitive_branch1043))
compiled_branch1044();
}
void compiled_branch1044()
{// compiled_branch1044
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL1045"));// (assign continue (label after_call1045))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch1043()
{// primitive_branch1043
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call1045();
}
void after_call1045()
{// after_call1045
s.restore(ENV);// (restore env)
s.restore(CONTINUE);// (restore continue)
s.save(CONTINUE);// (save continue)
s.save(ENV);// (save env)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "newline"), registers[ENV]));// (assign proc (op lookup_variable_value) (const newline) (reg env))
assign(ARGL, new SchemeDataType(SchemeDataType::TypeId::Nil));// (assign argl (const nil ))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH1046");
}// (branch (label primitive_branch1046))
compiled_branch1047();
}
void compiled_branch1047()
{// compiled_branch1047
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL1048"));// (assign continue (label after_call1048))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch1046()
{// primitive_branch1046
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call1048();
}
void after_call1048()
{// after_call1048
s.restore(ENV);// (restore env)
s.restore(CONTINUE);// (restore continue)
s.save(CONTINUE);// (save continue)
s.save(ENV);// (save env)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "display"), registers[ENV]));// (assign proc (op lookup_variable_value) (const display) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "string"), registers[ENV]));// (assign val (op lookup_variable_value) (const string) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH1049");
}// (branch (label primitive_branch1049))
compiled_branch1050();
}
void compiled_branch1050()
{// compiled_branch1050
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL1051"));// (assign continue (label after_call1051))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch1049()
{// primitive_branch1049
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call1051();
}
void after_call1051()
{// after_call1051
s.restore(ENV);// (restore env)
s.restore(CONTINUE);// (restore continue)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "newline"), registers[ENV]));// (assign proc (op lookup_variable_value) (const newline) (reg env))
assign(ARGL, new SchemeDataType(SchemeDataType::TypeId::Nil));// (assign argl (const nil ))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH1052");
}// (branch (label primitive_branch1052))
compiled_branch1053();
}
void compiled_branch1053()
{// compiled_branch1053
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch1052()
{// primitive_branch1052
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call1054();
}
void after_call1054()
{// after_call1054
after_lambda1042();
}
void after_lambda1042()
{// after_lambda1042
define_variable(new SchemeDataType(SchemeDataType::TypeId::Symbol, "prompt_for_input"), registers[VAL], registers[ENV]);// (perform (op define_variable) (const prompt_for_input) (reg val) (reg env))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "ok"));// (assign val (const ok))
assign(VAL, make_compiled_procedure("ENTRY1055", entry1055, registers[ENV]));// (assign val (op make_compiled_procedure) (label entry1055) (reg env))
goto_with_label("AFTER_LAMBDA1056");// (goto (label after_lambda1056))

}
void entry1055()
{// entry1055
assign(ENV, compiled_procedure_env(PROC));// (assign env (op compiled_procedure_env) (reg proc))
assign(ENV, extend_environment(list(1, new SchemeDataType(SchemeDataType::TypeId::Symbol, "string")), registers[ARGL], registers[ENV]));// (assign env (op extend_environment) (const string) (reg argl) (reg env))
s.save(CONTINUE);// (save continue)
s.save(ENV);// (save env)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "newline"), registers[ENV]));// (assign proc (op lookup_variable_value) (const newline) (reg env))
assign(ARGL, new SchemeDataType(SchemeDataType::TypeId::Nil));// (assign argl (const nil ))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH1057");
}// (branch (label primitive_branch1057))
compiled_branch1058();
}
void compiled_branch1058()
{// compiled_branch1058
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL1059"));// (assign continue (label after_call1059))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch1057()
{// primitive_branch1057
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call1059();
}
void after_call1059()
{// after_call1059
s.restore(ENV);// (restore env)
s.restore(CONTINUE);// (restore continue)
s.save(CONTINUE);// (save continue)
s.save(ENV);// (save env)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "display"), registers[ENV]));// (assign proc (op lookup_variable_value) (const display) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "string"), registers[ENV]));// (assign val (op lookup_variable_value) (const string) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH1060");
}// (branch (label primitive_branch1060))
compiled_branch1061();
}
void compiled_branch1061()
{// compiled_branch1061
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL1062"));// (assign continue (label after_call1062))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch1060()
{// primitive_branch1060
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call1062();
}
void after_call1062()
{// after_call1062
s.restore(ENV);// (restore env)
s.restore(CONTINUE);// (restore continue)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "newline"), registers[ENV]));// (assign proc (op lookup_variable_value) (const newline) (reg env))
assign(ARGL, new SchemeDataType(SchemeDataType::TypeId::Nil));// (assign argl (const nil ))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH1063");
}// (branch (label primitive_branch1063))
compiled_branch1064();
}
void compiled_branch1064()
{// compiled_branch1064
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch1063()
{// primitive_branch1063
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call1065();
}
void after_call1065()
{// after_call1065
after_lambda1056();
}
void after_lambda1056()
{// after_lambda1056
define_variable(new SchemeDataType(SchemeDataType::TypeId::Symbol, "announce_output"), registers[VAL], registers[ENV]);// (perform (op define_variable) (const announce_output) (reg val) (reg env))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "ok"));// (assign val (const ok))
assign(VAL, make_compiled_procedure("ENTRY1066", entry1066, registers[ENV]));// (assign val (op make_compiled_procedure) (label entry1066) (reg env))
goto_with_label("AFTER_LAMBDA1067");// (goto (label after_lambda1067))

}
void entry1066()
{// entry1066
assign(ENV, compiled_procedure_env(PROC));// (assign env (op compiled_procedure_env) (reg proc))
assign(ENV, extend_environment(list(1, new SchemeDataType(SchemeDataType::TypeId::Symbol, "object")), registers[ARGL], registers[ENV]));// (assign env (op extend_environment) (const object) (reg argl) (reg env))
s.save(CONTINUE);// (save continue)
s.save(ENV);// (save env)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "compound_procedure_p"), registers[ENV]));// (assign proc (op lookup_variable_value) (const compound_procedure_p) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "object"), registers[ENV]));// (assign val (op lookup_variable_value) (const object) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH1071");
}// (branch (label primitive_branch1071))
compiled_branch1072();
}
void compiled_branch1072()
{// compiled_branch1072
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL1073"));// (assign continue (label after_call1073))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch1071()
{// primitive_branch1071
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call1073();
}
void after_call1073()
{// after_call1073
s.restore(ENV);// (restore env)
s.restore(CONTINUE);// (restore continue)
if ( false_p(registers[VAL]) ) {// (test (op false_p) (reg val))
return goto_with_label("FALSE_BRANCH1069");
}// (branch (label false_branch1069))
true_branch1068();
}
void true_branch1068()
{// true_branch1068
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
return goto_with_label("PRIMITIVE_BRANCH1077");
}// (branch (label primitive_branch1077))
compiled_branch1078();
}
void compiled_branch1078()
{// compiled_branch1078
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL1079"));// (assign continue (label after_call1079))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch1077()
{// primitive_branch1077
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call1079();
}
void after_call1079()
{// after_call1079
s.restore(ARGL);// (restore argl)
assign(ARGL, cons(registers[VAL], registers[ARGL]));// (assign argl (op cons) (reg val) (reg argl))
s.restore(ENV);// (restore env)
s.save(ARGL);// (save argl)
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "procedure_parameters"), registers[ENV]));// (assign proc (op lookup_variable_value) (const procedure_parameters) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "object"), registers[ENV]));// (assign val (op lookup_variable_value) (const object) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH1074");
}// (branch (label primitive_branch1074))
compiled_branch1075();
}
void compiled_branch1075()
{// compiled_branch1075
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL1076"));// (assign continue (label after_call1076))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch1074()
{// primitive_branch1074
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call1076();
}
void after_call1076()
{// after_call1076
s.restore(ARGL);// (restore argl)
assign(ARGL, cons(registers[VAL], registers[ARGL]));// (assign argl (op cons) (reg val) (reg argl))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "compound_procedure"));// (assign val (const compound_procedure))
assign(ARGL, cons(registers[VAL], registers[ARGL]));// (assign argl (op cons) (reg val) (reg argl))
s.restore(PROC);// (restore proc)
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH1080");
}// (branch (label primitive_branch1080))
compiled_branch1081();
}
void compiled_branch1081()
{// compiled_branch1081
assign(CONTINUE, new SchemeDataType(SchemeDataType::TypeId::String, "AFTER_CALL1082"));// (assign continue (label after_call1082))
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch1080()
{// primitive_branch1080
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
after_call1082();
}
void after_call1082()
{// after_call1082
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
s.restore(PROC);// (restore proc)
s.restore(CONTINUE);// (restore continue)
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH1083");
}// (branch (label primitive_branch1083))
compiled_branch1084();
}
void compiled_branch1084()
{// compiled_branch1084
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch1083()
{// primitive_branch1083
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call1085();
}
void after_call1085()
{// after_call1085

}
void false_branch1069()
{// false_branch1069
assign(PROC, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "display"), registers[ENV]));// (assign proc (op lookup_variable_value) (const display) (reg env))
assign(VAL, lookup_variable_value(new SchemeDataType(SchemeDataType::TypeId::Symbol, "object"), registers[ENV]));// (assign val (op lookup_variable_value) (const object) (reg env))
assign(ARGL, list(registers[VAL]));// (assign argl (op list) (reg val))
if ( primitive_procedure_p(registers[PROC]) ) {// (test (op primitive_procedure_p) (reg proc))
return goto_with_label("PRIMITIVE_BRANCH1086");
}// (branch (label primitive_branch1086))
compiled_branch1087();
}
void compiled_branch1087()
{// compiled_branch1087
assign(VAL, compiled_procedure_entry(registers[PROC]));// (assign val (op compiled_procedure_entry) (reg proc))
goto_with_label(registers[VAL]);// (goto (reg val))

}
void primitive_branch1086()
{// primitive_branch1086
assign(VAL, apply_primitive_procedure(registers[PROC], registers[ARGL]));// (assign val (op apply_primitive_procedure) (reg proc) (reg argl))
goto_with_label(registers[CONTINUE]);// (goto (reg continue))
after_call1088();
}
void after_call1088()
{// after_call1088
after_if1070();
}
void after_if1070()
{// after_if1070
after_lambda1067();
}
void after_lambda1067()
{// after_lambda1067
define_variable(new SchemeDataType(SchemeDataType::TypeId::Symbol, "user_print"), registers[VAL], registers[ENV]);// (perform (op define_variable) (const user_print) (reg val) (reg env))
assign(VAL, new SchemeDataType(SchemeDataType::TypeId::String, "ok"));// (assign val (const ok))
}
