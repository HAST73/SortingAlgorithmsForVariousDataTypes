#ifndef PROJECT_AIZO_SELECTDATATYPE_H
#define PROJECT_AIZO_SELECTDATATYPE_H

#include <iostream>
#include <vector>
#include <string>
#include "../Headers/ReadFile.h"

// Klasa umożliwiająca wybór typu danych do przetwarzania
class SelectDataType {
    ReadFile fileReader;  // Czytnik plików

public:
    void selectDataType();  // Wyświetla menu wyboru typu danych
    int getSelection();  // Pobiera wybór typu danych od użytkownika
    void processSelectFromLoadedFile(int selection);  // Obsługuje przetwarzanie danych na podstawie wybranego typu
};

#endif //PROJECT_AIZO_SELECTDATATYPE_H
