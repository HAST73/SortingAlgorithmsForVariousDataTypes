#ifndef PROJECT_AIZO_HEAPSORT_H
#define PROJECT_AIZO_HEAPSORT_H

#include <vector>
#include <string>

// Klasa realizująca algorytm sortowania przez kopcowanie
class HeapSort {
public:
    template<typename T>
    static void heapSort(std::vector<T>& data); // Metoda realizująca sortowanie przez kopcowanie

    template<typename T>
    static void sortAndSave(const std::vector<T>& data, const std::string& filename); // Zapisuje posortowane dane do pliku

private:
    template<typename T>
    static void heapify(std::vector<T>& data, int n, int i); // Funkcja pomocnicza do tworzenia kopca

    template<typename T>
    static void buildHeap(std::vector<T>& data); // Buduje kopiec na podstawie danych
};

#endif //PROJECT_AIZO_HEAPSORT_H
