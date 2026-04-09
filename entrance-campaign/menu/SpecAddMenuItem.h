#pragma once

#include "MenuItem.h"

class SpecAddMenuItem : public MenuItem
{
public:
    SpecAddMenuItem() : MenuItem("Add new specialty") {}
    bool execute();
};
