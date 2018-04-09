#include <iostream>
#include "types.h"
#include "eceval.h"
#include "syntax.h"
#include "parse.h"
#include "eval.h"
#include "user_print.h"
#include "global.h"
#include "stack.h"

using namespace std;

Stack s; // bimyou

namespace
{

// function protos
void read_eval_print_loop();
void print_result();
}

void goto_with_label(const char* const label)
{
	string l = label;
    
	if (l == "GOTO_PRINT_RESULT") {
		print_result();
		return;
	}
	
	if (l == "GOTO_EVAL_DISPATCH") {
		eval_dispatch();
		return;
	}

	if (l == "GOTO_READ_EVAL_PRINT_LOOP") {
		read_eval_print_loop();
		return;
	}

    if (l == "UNKNOWN_EXPRESSION_TYPE") {
        unknown_expression_type();
        return;
    }
    

	cout << "LABEL NOT FOUND!: " << l << endl;
}

void goto_with_label(SchemeDataType* const reg)
{
	if (reg->type != SchemeDataType::String) {
		cout << "goto_with_label: not a label" << endl;
		exit(0);
	}
    
	goto_with_label(reg->stringValue);
}

void assign(int registerId, SchemeDataType* const r)
{
	registers[registerId] = r;
}

/**
unknown-expression-type
  (assign val (const unknown-expression-type-error))
  (goto (label signal-error))
  */
void unknown_expression_type()
{
    assign(VAL, new SchemeDataType(SchemeDataType::String, "Unknown-expression-type-error"));
    signal_error();
}


/**
unknown-procedure-type   
  (restore continue)
  (assign val (const unknown-procedure-type-error))
  (goto (label signal-error))
  */
void unknown_procedure_type()
{
    registers[CONTINUE] = s.restore();
    assign(VAL, new SchemeDataType(SchemeDataType::String, "Unknown-procedure-type-error"));
    signal_error();           
}

/**
signal-error
  (perform (op user-print) (reg val))
  (goto (label read-eval-print-loop))
  */
void signal_error()
{
    user_print(registers[VAL]);
    read_eval_print_loop();    
}


namespace
{
void assign(int registerId, const char* const s)
{
	SchemeDataType* sdt = new SchemeDataType(SchemeDataType::String, s);
	registers[registerId] = sdt;
} 


void prompt_for_input(const char* const message)
{
	cout << message << endl;
}

void print_result()
{
	s.print_statistics();
	cout << ";;; C++-EC-Eval value:" << endl;
	user_print(registers[VAL]);
}

/**
read-eval-print-loop
  (perform (op initialize-stack))
  (perform
   (op prompt-for-input) (const ";;; EC-Eval input:"))
  (assign exp (op read))
  (assign env (op get-global-environment))
  (assign continue (label print-result))
  (goto (label eval-dispatch))
  */
void read_eval_print_loop()
{
	s.initialize();

	// [pending] initialize_stack();
	prompt_for_input(";;; C++-EC-Eval input:");
	
	string input;

	string tmp;
	
	std::getline(std::cin, tmp);
		input += tmp;

	if (input == "!exit") {
		exit(0);
	}
	auto* parsed = parse(input);
	
	assign(EXP, parsed);
	assign(ENV, the_global_environment);
	assign(CONTINUE, "GOTO_PRINT_RESULT");
	goto_with_label("GOTO_EVAL_DISPATCH");
}

}

/*
  eval-dispatch
  (perform (op user-print) (reg exp))
  (test (op self-evaluating?) (reg exp))
  (branch (label ev-self-eval))
  (test (op variable?) (reg exp))
  (branch (label ev-variable))
  (test (op quoted?) (reg exp))
  (branch (label ev-quoted))
  (test (op assignment?) (reg exp))
  (branch (label ev-assignment))
  (test (op definition?) (reg exp))
  (branch (label ev-definition))
  (test (op if?) (reg exp))
  (branch (label ev-if))
  (test (op lambda?) (reg exp))
  (branch (label ev-lambda))
  (test (op begin?) (reg exp))
  (branch (label ev-begin))
  (test (op application?) (reg exp))
  (branch (label ev-application))
  (goto (label unknown-expression-type))
*/
void eval_dispatch()
{
    // (perform (op user-print) (reg exp))
	user_print(registers[EXP]);

    // (test (op self-evaluating?) (reg exp))
    // (branch (label ev-self-eval))
	if (self_evaluating_p(registers[EXP])) {
		ev_self_eval(registers[EXP]);
		return;
	}
    
    // (test (op variable?) (reg exp))
    // (branch (label ev-variable))
	if (variable_p(registers[EXP])) {
		ev_variable(registers[EXP]);
		return;
	}

    // (test (op quoted?) (reg exp))
    // (branch (label ev-quoted))
	if (quoted_p(registers[EXP])) {
		ev_quoted(registers[EXP]);
		return;
	}
    
    // (test (op assignment?) (reg exp))
    // (branch (label ev-assignment))
	if (assignment_p(registers[EXP])) {
		ev_assignment(registers[EXP]);
		return;
	}
    // (test (op definition?) (reg exp))
    // (branch (label ev-definition))
	if (definition_p(registers[EXP])) {
		ev_definition(registers[EXP]);
		return;
	}
    
    // (test (op if?) (reg exp))
    // (branch (label ev-if))
	if (if_p(registers[EXP])) {
		ev_if(registers[EXP]);
		return;
	}
    
    // (test (op lambda?) (reg exp))
    // (branch (label ev-lambda))
	if (lambda_p(registers[EXP])) {
		ev_lambda(registers[EXP]);
		return;
	}
    
    // (test (op begin?) (reg exp))
    // (branch (label ev-begin))
    if (begin_p(registers[EXP])) {
		ev_begin(registers[EXP]);
		return;
	}

    // (test (op application?) (reg exp))
    // (branch (label ev-application))
    if (application_p(registers[EXP])) {
		ev_application(registers[EXP]);
		return;
	}
	
    // (goto (label unknown-expression-type))
	goto_with_label("UNKNOWN_EXPRESSION_TYPE");
}


void eceval()
{	
	read_eval_print_loop();
}

