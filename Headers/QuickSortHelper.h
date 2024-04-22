#ifndef PROJECT_AIZO_QUICKSORTHELPER_H
#define PROJECT_AIZO_QUICKSORTHELPER_H

#include <vector>
#include <string>

// Klasa zawierająca algorytm QuickSort
template<typename T>
class QuickSortHelper {
public:
    enum PivotType { LEFT, MIDDLE, RIGHT, RANDOM }; // Typy pivota

    static void quickSort(std::vector<T>& data, int left, int right, PivotType pivotType); // Metoda QuickSort
    static void saveToFile(const std::vector<T>& data, const std::string& filename); // Zapisuje dane do pliku
};

#endif //PROJECT_AIZO_QUICKSORTHELPER_H
