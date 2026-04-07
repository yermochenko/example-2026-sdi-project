#include "SpecialtyStorage.h"

#include <sstream>

#include "..\file\CsvReader.h"

std::vector<Specialty*>* SpecialtyStorage::readAll() const
{
	std::vector<Specialty*>* result = new std::vector<Specialty*>();
	CsvReader reader(filename);
	int lineNumber = 0;
	while (std::vector<std::string>* row = reader.readLine())
	{
		if (row->size() == 4)
		{
			Specialty* specialty = new Specialty();
			specialty->setCode(row->at(0));
			specialty->setName(row->at(1));
			specialty->setShortName(row->at(2));
			specialty->setQualification(row->at(3));
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
