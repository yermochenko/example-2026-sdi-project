#include "splitter.h"

#include <sstream>

std::vector<std::string>* split(std::string str, char delimeter)
{
	std::vector<std::string>* result = new std::vector<std::string>();
	std::istringstream sin(str);
	std::string cell;
	while (std::getline(sin, cell, delimeter))
	{
		result->push_back(cell);
	}
	return result;
}
