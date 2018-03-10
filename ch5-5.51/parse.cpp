#include <string>
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

SchemeDataType* parse(const std::string& s)
{
	if (numbers_p(s)) {
		return new SchemeDataType(std::stoi(s));
	}

	if (string_p(s)) {
		return new SchemeDataType(SchemeDataType::String, s.c_str());
	}

	if (symbol_p(s)) {
		return new SchemeDataType(SchemeDataType::Symbol, s.c_str());
	}

	// error strings 
	return new SchemeDataType(SchemeDataType::Unknown, s.c_str());
}