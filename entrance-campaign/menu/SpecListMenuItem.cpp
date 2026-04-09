#include "SpecListMenuItem.h"

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

#include "..\entity\Specialty.h"
#include "..\storage\SpecialtyStorage.h"
#include "..\util\formatter.h"

bool SpecListMenuItem::execute()
{
    SpecialtyStorage storage("specialities.csv");
    std::vector<Specialty*>* specialities = storage.readAll();
    std::cout << "List of specialities:" << std::endl;
    std::string horisontalLine = columnsFormat({ 14, 52, 6, 22 }, '-', '+');
    std::string emptyCells = columnsFormat({ 14, 52, 6 }, ' ', '|');
    std::cout << horisontalLine << std::endl;
    std::cout << '|'
        << columnHeadFormat("code", 14) << '|'
        << columnHeadFormat("name", 52) << '|'
        << columnHeadFormat("plan", 6) << '|'
        << columnHeadFormat("CT", 22) << '|' << std::endl;
    std::cout << horisontalLine << std::endl;
    std::cout << std::left;
    for (Specialty* specialty : *specialities)
    {
        std::map<std::string, int> ctSubjects = specialty->getCTSubjects();
        std::map<std::string, int>::iterator it = ctSubjects.begin(), end = ctSubjects.end();
        std::cout << "| "
            << std::setw(12) << specialty->getCode() << " | "
            << std::setw(50) << specialty->getName() << " | "
            << std::setw(4)  << specialty->getRecruitmentPlan() << " | "
            << std::setw(20) << it->first << " |" << std::endl;
        for(it++; it != end; it++)
        {
            std::cout << emptyCells << ' '
                << std::setw(20) << it->first << " |" << std::endl;
        }
        std::cout << horisontalLine << std::endl;
        delete specialty;
    }
    std::cout << std::right;
    delete specialities;
    return true;
}
