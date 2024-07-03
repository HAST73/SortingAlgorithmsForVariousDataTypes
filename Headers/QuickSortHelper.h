#ifndef SORTINGALGORITHMSFORVARIOUSDATATYPES_QUICKSORTHELPER_H
#define SORTINGALGORITHMSFORVARIOUSDATATYPES_QUICKSORTHELPER_H

#include <vector>
#include <string>

// Class containing the QuickSort algorithm
template<typename T>
class QuickSortHelper {
public:
    enum PivotType { LEFT, MIDDLE, RIGHT, RANDOM }; // Pivot types

    static void quickSort(std::vector<T>& data, int left, int right, PivotType pivotType); // QuickSort method
    static void saveToFile(const std::vector<T>& data, const std::string& filename); // Saves data to a file
};

#endif //SORTINGALGORITHMSFORVARIOUSDATATYPES_QUICKSORTHELPER_H
