#pragma once
#include "types.h"

// 引数いらなくね？
void ev_self_eval(SchemeDataType* const reg);
void ev_variable(SchemeDataType* const reg);
void ev_quoted(SchemeDataType* const reg);

void ev_lambda(SchemeDataType* const reg);

void ev_application(SchemeDataType* const reg);
void ev_appl_did_operator(SchemeDataType* const reg);
void ev_appl_operand_loop(SchemeDataType* const reg);
void ev_appl_accumulate_arg(SchemeDataType* const reg);
void ev_appl_last_arg(SchemeDataType* const reg);
void apply_dispatch(SchemeDataType* const reg);
void primitive_apply(SchemeDataType* const reg);
void compound_apply(SchemeDataType* const reg);

void ev_begin(SchemeDataType* const reg);
void ev_sequence(SchemeDataType* const reg);
void ev_sequence_continue(SchemeDataType* const reg);
void ev_sequence_last_exp(SchemeDataType* const reg);

void ev_if(SchemeDataType* const reg);
void ev_if_decide(SchemeDataType* const reg);
void ev_if_alternative(SchemeDataType* const reg);
void ev_if_consequent(SchemeDataType* const reg);

void ev_assignment(SchemeDataType* const reg);
void ev_assignment_1(SchemeDataType* const reg);


void ev_definition(SchemeDataType* const reg);
void ev_definition_1(SchemeDataType* const reg);