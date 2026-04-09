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

unsigned int Specialty::getRecruitmentPlan() const
{
	return recruitmentPlan;
}

void Specialty::setRecruitmentPlan(unsigned int recruitmentPlan)
{
	this->recruitmentPlan = recruitmentPlan;
}

std::map<std::string, int> Specialty::getCTSubjects() const
{
	return ctSubjects;
}

void Specialty::setCTSubjects(std::map<std::string, int> ctSubjects)
{
	this->ctSubjects = ctSubjects;
}
