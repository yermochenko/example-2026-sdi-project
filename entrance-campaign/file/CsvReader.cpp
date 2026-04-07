#include "CsvReader.h"

#include <sstream>

CsvReader::CsvReader(std::string filename)
{
	fin.open(filename);
	if (!fin.is_open())
	{
		throw "File \"" + filename + "\" is not found";
	}
}

std::vector<std::string>* CsvReader::readLine()
{
	std::string row;
	if (std::getline(fin, row))
	{
		std::vector<std::string>* result = new std::vector<std::string>();
		std::istringstream sin(row);
		std::string cell;
		while (std::getline(sin, cell, ';'))
		{
			result->push_back(cell);
		}
		return result;
	}
	else
	{
		return nullptr;
	}
}

void CsvReader::close()
{
	fin.close();
}

CsvReader::~CsvReader()
{
	fin.close();
}
