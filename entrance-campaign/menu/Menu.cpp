#include "Menu.h"

#include "ExitMenuItem.h"

std::vector<MenuItem*> getMenu()
{
    return {
        new ExitMenuItem()
    };
}
