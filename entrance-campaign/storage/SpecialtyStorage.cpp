#include "SpecialtyStorage.h"

#include <map>
#include <sstream>

#include "..\file\CsvReader.h"
#include "..\file\CsvWriter.h"
#include "..\util\parser.h"
#include "..\util\splitter.h"

void SpecialtyStorage::create(Specialty* specialty) const
{
	std::vector<std::string> newRow = {
		specialty->getCode(),
		specialty->getName(),
		specialty->getShortName(),
		specialty->getQualification(),
		std::to_string(specialty->getRecruitmentPlan())
	};
	CsvWriter writer(filename, true);
	writer.writeLine(&newRow);
	writer.close();
}

std::vector<Specialty*>* SpecialtyStorage::readAll() const
{
	std::vector<Specialty*>* result = new std::vector<Specialty*>();
	CsvReader reader(filename);
	int lineNumber = 0;
	while (std::vector<std::string>* row = reader.readLine())
	{
		if (row->size() == 6 || row->size() == 5)
		{
			Specialty* specialty = new Specialty();
			specialty->setCode(row->at(0));
			specialty->setName(row->at(1));
			specialty->setShortName(row->at(2));
			specialty->setQualification(row->at(3));
			specialty->setRecruitmentPlan(parseInt(row->at(4)));
			if (row->size() == 6)
			{
				std::vector<std::string>* ctSubjectsPairs = split(row->at(5), ',');
				std::map<std::string, int> ctSubjects;
				for (std::string ctSubjectPair : *ctSubjectsPairs)
				{
					std::vector<std::string>* ctSubject = split(ctSubjectPair, '=');
					if (ctSubject->size() == 2)
					{
						ctSubjects[ctSubject->at(0)] = parseInt(ctSubject->at(1));
						delete ctSubject;
					}
					else
					{
						std::ostringstream sout;
						sout << "Incorrect format of file \"" << filename << "\" in line" << lineNumber << ", cell 6";
						throw sout.str();
					}
				}
				delete ctSubjectsPairs;
				specialty->setCTSubjects(ctSubjects);
			}
			result->push_back(specialty);
			delete row;
			lineNumber++;
		}
		else
		{
			std::ostringstream sout;
			sout << "Incorrect format of file \"" << filename << "\" in line " << lineNumber;
			throw sout.str();
		}
	}
	return result;
}
