#include "parser.h"

#include <stdexcept>

int parseInt(std::string s)
{
	try
	{
		size_t pos;
		int result = std::stoi(s, &pos);
		if (pos != s.size())
		{
			throw ParseException("string contains non digits data", s);
		}
		return result;
	}
	catch (std::invalid_argument& e)
	{
		throw ParseException("no conversion could be performed", s);
	}
	catch (std::out_of_range& e)
	{
		throw ParseException("converted value would fall out of the range of the type int", s);
	}
}

std::string ParseException::getMessage() const
{
	return message;
}

std::string ParseException::getSource() const
{
	return source;
}
