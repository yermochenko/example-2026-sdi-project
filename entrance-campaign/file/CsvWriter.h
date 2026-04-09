#pragma once

#include <fstream>
#include <string>
#include <vector>

class CsvWriter
{
	std::ofstream fout;
public:
	CsvWriter(std::string filename, bool append = false);
	void writeLine(std::vector<std::string>* row);
	void close();
	~CsvWriter();
};
