#include "Menu.h"

#include "SpecListMenuItem.h"
#include "ExitMenuItem.h"

std::vector<MenuItem*> getMenu()
{
    return {
        new SpecListMenuItem(),
        new ExitMenuItem()
    };
}
