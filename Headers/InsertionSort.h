#ifndef PROJECT_AIZO_INSERTIONSORT_H
#define PROJECT_AIZO_INSERTIONSORT_H

#include <vector>
#include <string>

// Klasa realizująca sortowanie przez wstawianie
class InsertionSort {
public:
    template<typename T>
    static void sortAndSave(const std::vector<T>& data, const std::string& filename); // Sortuje dane i zapisuje je do pliku
};

#endif //PROJECT_AIZO_INSERTIONSORT_H
