#include <iostream>
#include <vector>
#include <string>

#include "menu/Menu.h"
#include "util/parser.h"

int main()
{
    system("cls");
    std::cout << "Entrance campain automation" << std::endl;
    std::vector<MenuItem*> menu = getMenu();
    bool isWork = true;
    while (isWork)
    {
        std::cout << "Menu:" << std::endl;
        for (int i = 0; i < menu.size(); i++)
        {
            std::cout << "    " << (i + 1) << ". " << menu[i]->getName() << std::endl;
        }
        std::cout << std::endl;
        std::cout << "Enter menu item number > ";
        try
        {
            std::string userChoice;
            std::getline(std::cin, userChoice);
            int menuItemIndex = parseInt(userChoice) - 1;
            std::cout << std::endl;
            if (0 <= menuItemIndex && menuItemIndex < menu.size())
            {
                isWork = menu[menuItemIndex]->execute();
            }
            else
            {
                std::cout << "incorrect menu item number (should be between 1 and " << menu.size() << ")" << std::endl;
            }
        }
        catch (ParseException& e)
        {
            std::cout << "incorrect menu item number: " << e.getMessage() << std::endl;
        }
        std::cout << std::endl;
        system("pause");
        system("cls");
    }
    return 0;
}
