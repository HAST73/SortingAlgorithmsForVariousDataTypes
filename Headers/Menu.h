#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <vector>
#include <string>

class Menu {
public:
    static void generateGeneralMenu();
    static void generateRandomNumberFile(const std::string& filename); // Static method declaration
    static int getChoice();
    static void processChoice(int choice);
    static bool running;
};

#endif // MENU_H
