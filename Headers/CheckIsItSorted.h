#ifndef SORTINGALGORITHMSFORVARIOUSDATATYPES_CHECKISITSORTED_H
#define SORTINGALGORITHMSFORVARIOUSDATATYPES_CHECKISITSORTED_H

#include <vector>

// Class to check if an array is sorted
class CheckIsItSorted {
public:
    template<typename T>
    static bool isSorted(const std::vector<T>& data); // Static method to check if the array is sorted
};

#endif //SORTINGALGORITHMSFORVARIOUSDATATYPES_CHECKISITSORTED_H
