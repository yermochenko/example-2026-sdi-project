#include "SpecListMenuItem.h"

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

#include "..\entity\Specialty.h"
#include "..\storage\SpecialtyStorage.h"

bool SpecListMenuItem::execute()
{
    SpecialtyStorage storage("specialities.csv");
    std::vector<Specialty*>* specialities = storage.readAll();
    std::cout << "List of specialities:" << std::endl;
    std::cout << "+--------------+----------------------------------------------------+" << std::endl;
    std::cout << "|     code     |                        name                        |" << std::endl;
    std::cout << "+--------------+----------------------------------------------------+" << std::endl;
    std::cout << std::setiosflags(std::ios::left);
    for (Specialty* specialty : *specialities)
    {
        std::cout << "| " << specialty->getCode() << " | " << std::setw(50) << specialty->getName() << " |" << std::endl;
        delete specialty;
    }
    std::cout << "+--------------+----------------------------------------------------+" << std::endl;
    std::cout << std::setiosflags(std::ios::right);
    delete specialities;
    return true;
}
