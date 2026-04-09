#include "Menu.h"

#include "SpecListMenuItem.h"
#include "SpecAddMenuItem.h"
#include "ExitMenuItem.h"

std::vector<MenuItem*> getMenu()
{
    return {
        new SpecListMenuItem(),
        new SpecAddMenuItem(),
        new ExitMenuItem()
    };
}
