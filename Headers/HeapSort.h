#ifndef PROJECT_AIZO_HEAPSORT_H
#define PROJECT_AIZO_HEAPSORT_H

#include <vector>
#include <string>

class HeapSort {
public:
    template<typename T>
    static void heapSort(std::vector<T>& data);

    template<typename T>
    static void sortAndSave(const std::vector<T>& data, const std::string& filename);

private:
    template<typename T>
    static void heapify(std::vector<T>& data, int n, int i);

    template<typename T>
    static void buildHeap(std::vector<T>& data);
};

#endif //PROJECT_AIZO_HEAPSORT_H
