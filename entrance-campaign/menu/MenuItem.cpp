#include "MenuItem.h"

MenuItem::MenuItem(std::string name)
{
    this->name = name;
}

std::string MenuItem::getName() const
{
    return name;
}
