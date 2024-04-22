#ifndef MENU_H
#define MENU_H

#include "../Headers/SelectDataType.h"
#include "../Headers/GenerateDifferentArrays.h"
#include <iostream>
#include <vector>
#include <string>

// Klasa zarządzająca głównym menu aplikacji
class Menu {
public:
    static bool running;  // Flaga kontynuacji działania programu

    void generateGeneralMenu();  // Generuje główne menu
    int getChoice();  // Pobiera wybór użytkownika
    void processChoice(int choice);  // Obsługuje wybór użytkownika
    void generateAndSaveArray(int type);  // Generuje i zapisuje tablice
    void displayGenerateArrayMenu();  // Wyświetla menu generacji tablic
    int getArraySize();  // Pobiera rozmiar tablicy od użytkownika

private:
    GenerateDifferentArrays arrayGenerator;  // Generator tablic
};

#endif // MENU_H
