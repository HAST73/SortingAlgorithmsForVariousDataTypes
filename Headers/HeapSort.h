#ifndef SORTINGALGORITHMSFORVARIOUSDATATYPES_HEAPSORT_H
#define SORTINGALGORITHMSFORVARIOUSDATATYPES_HEAPSORT_H

#include <vector>
#include <string>

// Class implementing the heap sort algorithm
class HeapSort {
public:
    template<typename T>
    static void heapSort(std::vector<T>& data); // Method implementing heap sort

    template<typename T>
    static void sortAndSave(const std::vector<T>& data, const std::string& filename); // Saves sorted data to a file

private:
    template<typename T>
    static void heapify(std::vector<T>& data, int n, int i); // Helper function to create a heap

    template<typename T>
    static void buildHeap(std::vector<T>& data); // Builds a heap from the data
};

#endif //SORTINGALGORITHMSFORVARIOUSDATATYPES_HEAPSORT_H
