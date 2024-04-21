#ifndef PROJECT_AIZO_SELECTDATATYPE_H
#define PROJECT_AIZO_SELECTDATATYPE_H

#include <iostream>
#include <vector>
#include <string>
#include "../Headers/ReadFile.h"

using namespace std;

class SelectDataType {
    ReadFile fileReader; // Add this line to declare fileReader
public:
    void selectDataType();
    int getSelection();
    void processSelectFromLoadedFile(int selection);
};

#endif //PROJECT_AIZO_SELECTDATATYPE_H
