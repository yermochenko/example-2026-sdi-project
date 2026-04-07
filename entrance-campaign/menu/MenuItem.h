#pragma once

#include <string>

class MenuItem
{
    std::string name;
public:
    MenuItem(std::string name);
    std::string getName() const;
    virtual bool execute() = 0;
};
