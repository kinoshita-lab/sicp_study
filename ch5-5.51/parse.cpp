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

SchemeDataType parse(const std::string& s)
{
	if (numbers_p(s)) {
		SchemeDataType sdt(std::stoi(s));
		return sdt;
	}

	if (string_p(s)) {
		SchemeDataType sdt(SchemeDataType::String, s.c_str());
		return sdt;
	}

	if (symbol_p(s)) {
		SchemeDataType sdt(SchemeDataType::Symbol, s.c_str());
		return sdt;
	}

	SchemeDataType sdt;
	return sdt;
}
