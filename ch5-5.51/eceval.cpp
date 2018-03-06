#include <iostream>
#include "types.h"
#include "eceval.h"
#include "dispatch.h"
#include "parse.h"
#include "eval.h"
#include "user_print.h"
#include "global.h"

using namespace std;

namespace
{
// function protos
void read_eval_print_loop();
void print_result();
void eval_dispatch();

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

void goto_with_label(string& label)
{
	goto_with_label(label.c_str());
}

void assign(int registerId, const char* const s)
{
	SchemeDataType* sdt = new SchemeDataType(SchemeDataType::String, s);
	registers[registerId] = sdt;
} 

void assign(int registerId, SchemeDataType* const r)
{
	registers[registerId] = r;
}

void prompt_for_input(const char* const message)
{
	cout << message << endl;
}

void print_result()
{
	// [pending] print_stack_statistics();
	cout << ";;; C++-EC-Eval output:" << endl;
	user_print(registers[VAL]);
}


void read_eval_print_loop()
{
	// [pending] initialize_stack();
	prompt_for_input(";;; C++-EC-Eval input:");
	
	string tmp;
	std::getline(std::cin, tmp);

	if (tmp == "!exit") {
		exit(0);
	}
	auto* parsed = parse(tmp);
	
	assign(EXP, parsed);
	assign(ENV, the_global_environment);
	assign(CONTINUE, "GOTO_PRINT_RESULT");
	goto_with_label("GOTO_EVAL_DISPATCH");
}

void eval_dispatch()
{
	user_print(registers[EXP]);

	if (self_evaluating_p(registers[EXP])) {
		ev_self_eval(registers[EXP]);
		goto end_of_dispatch;
	}

	if (variable_p(registers[EXP])) {
		ev_variable(registers[EXP]);
		goto end_of_dispatch;
	}
	
	
end_of_dispatch:
	goto_with_label(registers[CONTINUE]);
}

}

void eceval()
{	
	read_eval_print_loop();
}
