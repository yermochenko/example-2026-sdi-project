#include "ExitMenuItem.h"

#include <iostream>

bool ExitMenuItem::execute()
{
    std::cout << "Good Bye" << std::endl;
    return false;
}
