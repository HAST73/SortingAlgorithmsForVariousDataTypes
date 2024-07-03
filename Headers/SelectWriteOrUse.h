#ifndef SORTINGALGORITHMSFORVARIOUSDATATYPES_SELECTWRITEORUSE_H
#define SORTINGALGORITHMSFORVARIOUSDATATYPES_SELECTWRITEORUSE_H

#include <vector>

// Class managing the selection of operations on data
template<typename T>
class SelectWriteOrUse {
public:
    void displayMenu();  // Displays menu options for data
    void processChoice(std::vector<T>& data);  // Handles the chosen option
};

#endif //SORTINGALGORITHMSFORVARIOUSDATATYPES_SELECTWRITEORUSE_H
