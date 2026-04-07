#pragma once

#include "MenuItem.h"

class SpecListMenuItem : public MenuItem
{
public:
    SpecListMenuItem() : MenuItem("List of specialities") {}
    bool execute();
};
