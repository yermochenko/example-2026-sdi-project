#pragma once

#include "MenuItem.h"

class ExitMenuItem : public MenuItem
{
public:
    ExitMenuItem() : MenuItem("Exit") {}
    bool execute();
};
