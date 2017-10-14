#include "ReadFromFile.h"

ReadFromFile::ReadFromFile(const std::string& filename):
infile{filename.c_str()}
{
	if ( !infile )
		throw FileCannotBeOpened();
}
std::vector<std::string> ReadFromFile::ExtractDataFromFile()
{
	std::vector<std::string> vector_of_lines;
	std::string text_line;
	while (getline(infile, text_line, '\n'))
	{
		vector_of_lines.push_back(text_line);
	}
	return vector_of_lines;
}


