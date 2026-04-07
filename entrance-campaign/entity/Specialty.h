#pragma once

#include <string>

class Specialty
{
	std::string code;
	std::string name;
	std::string shortName;
	std::string qualification;
public:
	std::string getCode() const;
	void setCode(std::string code);
	std::string getName() const;
	void setName(std::string name);
	std::string getShortName() const;
	void setShortName(std::string shortName);
	std::string getQualification() const;
	void setQualification(std::string qualification);
};
