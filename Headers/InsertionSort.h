#ifndef SORTINGALGORITHMSFORVARIOUSDATATYPES_INSERTIONSORT_H
#define SORTINGALGORITHMSFORVARIOUSDATATYPES_INSERTIONSORT_H

#include <vector>
#include <string>

// Class implementing insertion sort
class InsertionSort {
public:
    template<typename T>
    static void sortAndSave(const std::vector<T>& data, const std::string& filename); // Sorts data and saves it to a file
};

#endif //SORTINGALGORITHMSFORVARIOUSDATATYPES_INSERTIONSORT_H
