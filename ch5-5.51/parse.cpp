#include <string>
#include <vector>
#include <ctype.h>
#include <list>

#include "types.h"

using namespace std;

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

SchemeDataType* atom(const std::string& s)
{
	if (numbers_p(s)) {
		return new SchemeDataType(SchemeDataType::Integer, std::stoi(s));
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

// based on https://gist.github.com/ofan/721464
// convert given string to list of tokens
std::list<std::string> tokenize(const std::string & str)
{
    std::list<std::string> tokens;
    const char * s = str.c_str();
    while (*s) {
        while (*s == ' ') // ここはかえないと "  a   b   c" みたいなのがうまくいかない
            ++s;
        if (*s == '(' || *s == ')')
            tokens.push_back(*s++ == '(' ? "(" : ")");
        else {
            const char * t = s;
            while (*t && *t != ' ' && *t != '(' && *t != ')')
                ++t;
            tokens.push_back(std::string(s, t));
            s = t;
        }
    }
    return tokens;
}


// based on https://gist.github.com/ofan/721464
// return the Lisp expression in the given tokens
SchemeDataType* read_from(std::list<std::string> & tokens)
{
    const std::string token(tokens.front());
    tokens.pop_front();
    if (token == "(") {
        ConsCell* c = new ConsCell;
        while (tokens.front() != ")")
            c->listPush(read_from(tokens));
        tokens.pop_front();
        return new SchemeDataType(*c);
    }
    else
        return atom(token);
}

}

SchemeDataType* parse(std::string& s)
{
	auto tokenized = tokenize(s);

	SchemeDataType* parsed = read_from(tokenized);

	return parsed;
}