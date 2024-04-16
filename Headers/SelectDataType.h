#ifndef PROJECT_AIZO_SELECTDATATYPE_H
#define PROJECT_AIZO_SELECTDATATYPE_H

#include <iostream>
#include <vector>
#include "../Headers/ReadFile.h"

using namespace std;

class SelectDataType {
public:
    void selectDataType(); // Metoda generująca menu z wyborem typu danych
    int getSelection(); // Metoda pobierająca wybór użytkownika
    void processSelectFromLoadedFile(int selection); // Metoda przetwarzająca wybór użytkownika
private:
    ReadFile fileReader;  // Instance of ReadFile to use for reading.
};

#endif //PROJECT_AIZO_SELECTDATATYPE_H
