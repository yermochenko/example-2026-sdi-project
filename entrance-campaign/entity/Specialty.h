#pragma once

#include <string>
#include <map>

class Specialty
{
	std::string code;
	std::string name;
	std::string shortName;
	std::string qualification;
	unsigned int recruitmentPlan;
	std::map<std::string, int> ctSubjects;
public:
	std::string getCode() const;
	void setCode(std::string code);
	std::string getName() const;
	void setName(std::string name);
	std::string getShortName() const;
	void setShortName(std::string shortName);
	std::string getQualification() const;
	void setQualification(std::string qualification);
	unsigned int getRecruitmentPlan() const;
	void setRecruitmentPlan(unsigned int recruitmentPlan);
	std::map<std::string, int> getCTSubjects() const;
	void setCTSubjects(std::map<std::string, int> ctSubjects);
};
