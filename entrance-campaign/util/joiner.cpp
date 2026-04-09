#include "joiner.h"

std::string join(std::vector<std::string> array, std::string delimeter)
{
	if (!array.empty())
	{
		std::vector<std::string>::iterator it = array.begin(), end = array.end();
		std::string result = *it++;
		while (it != end)
		{
			result += delimeter + *it++;
		}
		return result;
	}
	else
	{
		return "";
	}
}
