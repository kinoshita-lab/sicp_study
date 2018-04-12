#pragma once
#include "types.h"

void ev_self_eval();
void ev_variable();
void ev_quoted();

void ev_lambda();

void ev_application();
void ev_appl_did_operator();
void ev_appl_operand_loop();
void ev_appl_accumulate_arg();
void ev_appl_last_arg();
void apply_dispatch();
void primitive_apply();
void compound_apply();

void ev_begin();
void ev_sequence();
void ev_sequence_continue();
void ev_sequence_last_exp();

void ev_if();
void ev_if_decide();
void ev_if_alternative();
void ev_if_consequent();

void ev_assignment();
void ev_assignment_1();


void ev_definition();
void ev_definition_1();
