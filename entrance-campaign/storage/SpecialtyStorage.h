#pragma once

#include <string>
#include <vector>

#include "..\entity\Specialty.h"

class SpecialtyStorage
{
	const std::string filename;
public:
	SpecialtyStorage(std::string _filename) : filename(_filename) {}
	void create(Specialty* specialty) const;
	std::vector<Specialty*>* readAll() const;
};
