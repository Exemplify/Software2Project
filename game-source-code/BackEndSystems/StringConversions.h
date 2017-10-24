#ifndef STRING_CONVERT_H
#define STRING_CONVERT_H
#include <string>
#include <sstream>
/**
 * @class StringConversions
 * @brief Converts a string to the various datatypes required by the implementation
 */
class StringConversions
{
public:
	/**
	 * @brief Convertes a string to a double 
	 * @param str the string that is converted 
	 * @return the double that is determined from the string
	 */
	static double  string2double(const std::string& str);
	/**
	 * @brief converts a string to an unsigned integer 
	 * @param str the string that is converted 
	 * @return the unsigned int that is determined from the string
	 */
	static unsigned int string2uint(const std::string& str);
};
#endif