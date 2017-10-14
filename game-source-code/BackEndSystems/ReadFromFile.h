#ifndef READ_FROM_FILE_H
#define READ_FROM_FILE_H
#include <string>
#include <vector>
#include <fstream>
class FileCannotBeOpened{};

class ReadFromFile
{
public: 
	ReadFromFile(const std::string& filename);
	std::vector<std::string> ExtractDataFromFile();
private:
	std::ifstream infile; // input file stream
};

#endif