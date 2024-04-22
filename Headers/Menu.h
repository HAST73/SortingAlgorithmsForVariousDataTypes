#ifndef MENU_H
#define MENU_H
#include "../Headers/SelectDataType.h"
#include "../Headers/GenerateDifferentArrays.h"

#include <iostream>
#include <vector>
#include <string>

class Menu {
public:
    static bool running;

    void generateGeneralMenu();
    int getChoice();
    void processChoice(int choice);
    void generateAndSaveArray(int type);
    void displayGenerateArrayMenu();
    int getArraySize(); // Nowa metoda do pobierania rozmiaru tablicy

private:
    GenerateDifferentArrays arrayGenerator; // Umieszczony tutaj, aby był dostępny dla wszystkich metod
};

#endif // MENU_H
