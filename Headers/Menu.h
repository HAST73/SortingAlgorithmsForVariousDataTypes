#ifndef MENU_H
#define MENU_H

#include "../Headers/SelectDataType.h"
#include "../Headers/GenerateDifferentArrays.h"
#include <iostream>
#include <vector>
#include <string>

// Class managing the main application menu
class Menu {
public:
    static bool running;  // Flag for continuing program operation

    void generateGeneralMenu();  // Generates the main menu
    int getChoice();  // Gets the user's choice
    void processChoice(int choice);  // Processes the user's choice
    void generateAndSaveArray(int type);  // Generates and saves arrays
    void displayGenerateArrayMenu();  // Displays the array generation menu
    int getArraySize();  // Gets the array size from the user

private:
    GenerateDifferentArrays arrayGenerator;  // Array generator
};

#endif // MENU_H
