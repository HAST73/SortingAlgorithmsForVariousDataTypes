#ifndef PROJECT_AIZO_SELECTSORT_H
#define PROJECT_AIZO_SELECTSORT_H

using namespace std;

#include <vector>

class SelectSort {
public:
    void displaySortMenu();
    int getSortChoice();
    template<typename T>
    void performSort(int choice, vector<T>& data);
};

#endif //PROJECT_AIZO_SELECTSORT_H
