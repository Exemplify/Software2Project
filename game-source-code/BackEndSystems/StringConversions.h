#ifndef STRING_CONVERT_H
#define STRING_CONVERT_H
#include <string>
#include <sstream>

class StringConversions
{
public:
	static double  string2double(const std::string& str);
	static unsigned int string2uint(const std::string& str);
};
#endif