#include "CsvReader.h"

#include "..\util\splitter.h"

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
		return split(row, ';');
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
