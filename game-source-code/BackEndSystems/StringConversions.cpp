#include "StringConversions.h"

double StringConversions::string2double(const std::string& str)
{
	double converted_string;
	std::stringstream stream{str};
	stream >> converted_string;
	return converted_string;
}
unsigned int StringConversions::string2uint(const std::string& str)
{
	unsigned int converted_string;
	std::stringstream stream{str};
	stream >> converted_string;
	return converted_string;
}
