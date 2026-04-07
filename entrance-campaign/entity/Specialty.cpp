#include "Specialty.h"

std::string Specialty::getCode() const
{
	return code;
}

void Specialty::setCode(std::string code)
{
	this->code = code;
}

std::string Specialty::getName() const
{
	return name;
}

void Specialty::setName(std::string name)
{
	this->name = name;
}

std::string Specialty::getShortName() const
{
	return shortName;
}

void Specialty::setShortName(std::string shortName)
{
	this->shortName = shortName;
}

std::string Specialty::getQualification() const
{
	return qualification;
}

void Specialty::setQualification(std::string qualification)
{
	this->qualification = qualification;
}
