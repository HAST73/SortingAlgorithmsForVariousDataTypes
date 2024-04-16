#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <vector>

class Menu {
public:
    void generateGeneralMenu(); // Metoda generująca menu
    int getChoice(); // Metoda pobierająca wybór użytkownika
    void processChoice(int choice); // Metoda przetwarzająca wybór użytkownika
    static bool running;
};

#endif // MENU_H
