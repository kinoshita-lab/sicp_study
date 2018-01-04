#include <iostream>
#include "types.h"
#include "eceval.h"
#include "dispatch.h"
#include "eval.h"

using namespace std;

namespace
{
RegisterType the_global_environment;

// function protos
void user_print(RegisterType& reg);
void read_eval_print_loop();
void print_result();
void eval_dispatch();

RegisterType& get_global_environment()
{
	return the_global_environment;
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

	cout << "LABEL NOT FOUND!" << l;
}

void goto_with_label(string& label)
{
	goto_with_label(label.c_str());
}


void assign(int registerId, string& contents)
{
	registers[registerId].push_front(contents);
}

void assign(int registerId, const char* const contents)
{
	string c = contents;
	registers[registerId].push_front(c);
}

void assign(int registerId, RegisterType& r)
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

void user_print(RegisterType& reg)
{
	if (reg.size()) {
		cout << reg.front() << endl;
		return;
	}

	cout << "Register is Empty!" << endl;
}

void read_eval_print_loop()
{
	// [pending] initialize_stack();
	prompt_for_input(";;; C++-EC-Eval input:");
	
	string tmp;
	std::getline(std::cin, tmp);

	assign(EXP, tmp);
	assign(ENV, get_global_environment());
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
	
end_of_dispatch:
	registers[VAL].push_front("eval'ed value");
	goto_with_label(registers[CONTINUE].front());
}

}

void eceval()
{	
	read_eval_print_loop();
}
