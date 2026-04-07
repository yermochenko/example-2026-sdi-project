#pragma once

#include <fstream>
#include <string>
#include <vector>

class CsvReader
{
	std::ifstream fin;
public:
	CsvReader(std::string filename);
	std::vector<std::string>* readLine();
	void close();
	~CsvReader();
};
