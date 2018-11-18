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
		if (!isalpha(c) && !isdigit(c) && c != '\''
        && c != '+' && c != '*' && c != '-' && c != '=' && c != '/' && c != '>' && c != '<') {
			return false;
		}
	}

	return true;
}

SchemeDataType* atom(const std::string& s)
{
	if (numbers_p(s)) {
		return new SchemeDataType(SchemeDataType::TypeId::Integer, std::stoi(s));
	}

	if (string_p(s)) {
		return new SchemeDataType(SchemeDataType::TypeId::String, s.c_str());
	}

	if (symbol_p(s)) {
		return new SchemeDataType(SchemeDataType::TypeId::Symbol, s.c_str());
	}

	// error strings 
	return new SchemeDataType(SchemeDataType::TypeId::Unknown, s.c_str());
}

std::vector<std::string> make_quote(const char* s, int* increment) 
{
    std::vector<std::string> ret;
    ret.push_back("(");
    ret.push_back("quote");
    auto internal_increment = 0;
    auto t_increment = 0;
    auto parenCounter = 0;
    s++; internal_increment++;

    while (*s) {
        if (*s == ' ') {
            if (parenCounter == 0) { // end of quote
                break;
            }
            ++s; ++internal_increment;
        }
        if (*s == '(' || *s == ')') {
            parenCounter += *s == '(' ? 1 : -1;
            ret.push_back(*s++ == '(' ? "(" : ")");
            internal_increment++;
        } else {
            const char * t = s;
            if (*s == '\"') {
                do {
                    ++t; t_increment++;
                } while (*t != '\"');
                ret.push_back(std::string(s,++t)); ++t_increment;
                s = t; internal_increment += t_increment; t_increment = 0;
                continue;
            }
            while (*t && *t != ' ' && *t != '(' && *t != ')') {
                ++t; ++t_increment;
            }
            ret.push_back(std::string(s, t));
            s = t; internal_increment += t_increment; t_increment = 0;
        }
    }
    ret.push_back(")");
    *increment = internal_increment;
    return ret;
}

// based on https://gist.github.com/ofan/721464
// convert given string to list of tokens
std::list<std::string> tokenize(const std::string & str)
{
    std::list<std::string> tokens;

    const char* s = str.c_str();
    while (*s) {
        while (*s == ' ')
            ++s;
        if (*s == '(' || *s == ')') {
            tokens.push_back(*s++ == '(' ? "(" : ")");
        } else if (*s == '\'') {
            int increment = 0;
            const auto quoted = make_quote(s, &increment);
            s += increment; 
            for (auto && q : quoted) {
                tokens.push_back(q);
            }
            continue;
        } else {
            const char * t = s;
            if (*s == '\"') {
                do {
                    ++t;
                } while (*t != '\"');
                tokens.push_back(std::string(s,++t));
                s = t;
                continue;
            }
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
        
        while (tokens.front() != ")") {
            c->listPush(read_from(tokens));
        }

        tokens.pop_front();
        return new SchemeDataType(c);
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