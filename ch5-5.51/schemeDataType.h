#pragma once
#include <list>
#include <string>


struct SchemeDataElement
{
	
};

typedef std::list<SchemeDataElement> SchemeDataType;

SchemeDataType parseString(std::string& s);
