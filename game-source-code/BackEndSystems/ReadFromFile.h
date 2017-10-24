#ifndef READ_FROM_FILE_H
#define READ_FROM_FILE_H
#include <string>
#include <vector>
#include <fstream>
/**
 * @class FileCannotBeOpened
 * @brief Exception thrown if the file inputed cannot be opened
 */
class FileCannotBeOpened{};
/**
 * @class ReadFromFile
 * @brief Reads information from a text file and converts it into a vector of strings where each element represents a line of the text file
 */
class ReadFromFile
{
public: 
	/**
	* Constructs a file stream object for the specific filename provided
	*/
	ReadFromFile(const std::string& filename);
	/**
	 * @brief Extracts the data from the filestream constructed
	 * @return Returns a vector of string, where each string represents a line of the file
	 */
	std::vector<std::string> ExtractDataFromFile();
private:
	std::ifstream infile; /**<The Input FileStream*/
};

#endif