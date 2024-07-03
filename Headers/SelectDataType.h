#ifndef SORTINGALGORITHMSFORVARIOUSDATATYPES_SELECTDATATYPE_H
#define SORTINGALGORITHMSFORVARIOUSDATATYPES_SELECTDATATYPE_H

#include <iostream>
#include <vector>
#include <string>
#include "../Headers/ReadFile.h"

// Class allowing selection of data type for processing
class SelectDataType {
    ReadFile fileReader;  // File reader object

public:
    void selectDataType();  // Displays menu for selecting data type
    int getSelection();  // Gets user's selection of data type
    void processSelectFromLoadedFile(int selection);  // Handles data processing based on selected type
};

#endif //SORTINGALGORITHMSFORVARIOUSDATATYPES_SELECTDATATYPE_H
