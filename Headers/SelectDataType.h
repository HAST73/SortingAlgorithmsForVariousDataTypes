#ifndef PROJECT_AIZO_SELECTDATATYPE_H
#define PROJECT_AIZO_SELECTDATATYPE_H

#include <iostream>
#include <vector>
#include <limits>

class SelectDataType {
public:
    void selectDataType(); // Metoda generująca menu z wyborem typu danych
    int getSelection(); // Metoda pobierająca wybór użytkownika
    void processSelect(int selection); // Metoda przetwarzająca wybór użytkownika
};

#endif //PROJECT_AIZO_SELECTDATATYPE_H
