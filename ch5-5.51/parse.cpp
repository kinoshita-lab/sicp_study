#include <ctype.h>
#include "types.h"

namespace
{
bool numbers_p(const std::string& s)
{
	for (auto&& c : s) {
		if (!isdigit(c)) {
			return false;
		}
	}

	return true;
}

bool string_p(const std::string& s)
{
	return (s[0] == '\"' && s[s.length() - 1]  == '\"');
}

bool symbol_p(const std::string& s)
{
	for (auto&& c : s) {
		if (!isalpha(c)) {
			return false;
		}
	}

	return true;
}

}

RegisterElement parse(const std::string& s)
{
	if (numbers_p(s)) {
		RegisterElementCore c(std::stoi(s));
		RegisterElement e;
		e.push_front(c);		
		return e;
	}

	if (string_p(s)) {
		RegisterElementCore c(RegisterElementCore::String, s.c_str());
		RegisterElement e;
		e.push_front(c);		
		return e;
	}

	if (symbol_p(s)) {
		RegisterElementCore c(RegisterElementCore::Symbol, s.c_str());
		RegisterElement e;
		e.push_front(c);		
		return e;
	}

	RegisterElementCore c;
	RegisterElement e;
	e.push_front(c);
	
	return e;
}
