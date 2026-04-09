#include "SpecAddMenuItem.h"

#include <iostream>
#include <regex>

#include "..\entity\Specialty.h"
#include "..\storage\SpecialtyStorage.h"
#include "..\util\parser.h"

bool SpecAddMenuItem::execute()
{
    Specialty specialty;
    std::string line;
    std::cout << "..:: Adding new specialty ::.." << std::endl;
    std::cout << "Enter information about new specialty: " << std::endl;

    std::cout << "1. Code (in format X-XX-XXXX-XX) > ";
    std::getline(std::cin, line);
    std::regex codeRegexp("\\d-\\d{2}-\\d{4}-\\d{2}");
    if (!std::regex_match(line, codeRegexp))
    {
        std::cout << "Incorrect code (not correspont format X-XX-XXXX-XX)" << std::endl;
        return true;
    }
    specialty.setCode(line);

    std::cout << "2. Name (not more than 50 characters) > ";
    std::getline(std::cin, line);
    if (line.empty())
    {
        std::cout << "Name must be not empty" << std::endl;
        return true;
    }
    if (line.size() > 50)
    {
        std::cout << "Name must contains not more than 50 characters" << std::endl;
    }
    specialty.setName(line);

    std::cout << "3. Short name (not more than 10 characters) > ";
    std::getline(std::cin, line);
    if (line.empty())
    {
        std::cout << "Short name must be not empty" << std::endl;
        return true;
    }
    if (line.size() > 10)
    {
        std::cout << "Short name must contains not more than 10 characters" << std::endl;
    }
    specialty.setShortName(line);

    std::cout << "4. Qualification (not more than 50 characters) > ";
    std::getline(std::cin, line);
    if (line.empty())
    {
        std::cout << "Qualification must be not empty" << std::endl;
        return true;
    }
    if (line.size() > 50)
    {
        std::cout << "Qualification must contains not more than 50 characters" << std::endl;
    }
    specialty.setQualification(line);

    std::cout << "5. Recruitment plan (empty value is equiv to zero) > ";
    std::getline(std::cin, line);
    if (!line.empty())
    {
        try
        {
            int recruitmentPlan = parseInt(line);
            if (recruitmentPlan < 0)
            {
                std::cout << "Number of students recruitment plan must be non negative" << std::endl;
                return true;
            }
            specialty.setRecruitmentPlan(recruitmentPlan);
        }
        catch (ParseException& e)
        {
            std::cout << "Incorrect number of students recruitment plan: " << e.getMessage() << std::endl;
            return true;
        }
    }

    SpecialtyStorage storage("specialities.csv");
    storage.create(&specialty);
    std::cout << "New specialty successfully added" << std::endl;

    return true;
}
