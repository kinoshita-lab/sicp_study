#include <string>
#include <array>
#include <list>
#include <iostream>

#include "eceval.h"

using namespace std;

namespace
{
enum RegisterId
{
	EXP,
	ENV,
	VAL,
	PROC,
	ARGL,
	CONTINUE,
	UNEV,
	NumberOfRegisters
};

// function protos
void read_eval_print_loop();
void print_result();
void eval_dispatch();

typedef list<string> RegisterType; // 前が最新
array<RegisterType, NumberOfRegisters> registers;
RegisterType the_global_environment;

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
	if (registers[VAL].size()) {
		const auto val = registers[VAL].front();
		cout << val << endl;
	}

	goto_with_label("GOTO_READ_EVAL_PRINT_LOOP");
}

// under construction
void eval_dispatch()
{
	registers[VAL].push_front("eval'ed value");
	goto_with_label(registers[CONTINUE].front());
}

void read_eval_print_loop()
{
	// [pending] initialize_stack();
	prompt_for_input(";;; C++-EC-Eval input:");
	
	string tmp;
	cin >> tmp;
	assign(EXP, tmp);
	assign(ENV, get_global_environment());
	assign(CONTINUE, "GOTO_PRINT_RESULT");
	goto_with_label("GOTO_EVAL_DISPATCH");
}


}

void eceval()
{	
	read_eval_print_loop();
}
