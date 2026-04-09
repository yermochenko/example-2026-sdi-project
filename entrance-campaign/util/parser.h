#pragma once

#include <string>

int parseInt(std::string s);

class ParseException
{
	const std::string message;
	const std::string source;
public:
	ParseException(std::string _message, std::string _source) : message(_message), source(_source) {}
	std::string getMessage() const;
	std::string getSource() const;
};
