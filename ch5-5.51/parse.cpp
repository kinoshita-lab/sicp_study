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
		RegisterElementCore c(s.c_str());
		RegisterElement e;
		e.push_front(c);		
		return e;
	}

	RegisterElementCore c;
	RegisterElement e;
	e.push_front(c);
	
	return e;
}
