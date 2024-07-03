#ifndef SORTINGALGORITHMSFORVARIOUSDATATYPES_SORTMENU_H
#define SORTINGALGORITHMSFORVARIOUSDATATYPES_SORTMENU_H

#include <vector>

// Class for sorting method selection menu
class SortMenu {
public:
    void displaySortMenu();  // Displays the sorting algorithm selection menu
    int getSortChoice();  // Gets the user's choice of sorting method
    template<typename T>
    void performSort(int choice, std::vector<T>& data);  // Performs sorting according to the chosen method
};

#endif //SORTINGALGORITHMSFORVARIOUSDATATYPES_SORTMENU_H
