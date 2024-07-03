#ifndef SORTINGALGORITHMSFORVARIOUSDATATYPES_QUICKSORT_H
#define SORTINGALGORITHMSFORVARIOUSDATATYPES_QUICKSORT_H

#include <vector>
#include <iostream>

// Class implementing quick sort (QuickSort)
class QuickSort {
public:
    void displaySortMenu(); // Displays the menu for selecting the pivot type
    int getSortChoice(); // Gets the user's choice

    template<typename T>
    void performSort(int choice, std::vector<T>& data); // Performs sorting based on the selected pivot type
};

#endif //SORTINGALGORITHMSFORVARIOUSDATATYPES_QUICKSORT_H
