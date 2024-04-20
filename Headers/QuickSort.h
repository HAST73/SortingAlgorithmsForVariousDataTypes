#ifndef PROJECT_AIZO_QUICKSORT_H
#define PROJECT_AIZO_QUICKSORT_H

using namespace std;

#include <vector>
#include <iostream>
#include "../Headers/Sort.h"

class QuickSort {
public:
    void displaySortMenu();
    int getSortChoice();

    // Declare the template function inside the class definition
    template<typename T>
    void performSort(int choice, std::vector<T>& data);
};

#endif //PROJECT_AIZO_QUICKSORT_H
