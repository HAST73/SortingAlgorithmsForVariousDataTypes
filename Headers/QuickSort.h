#ifndef PROJECT_AIZO_QUICKSORT_H
#define PROJECT_AIZO_QUICKSORT_H

#include <vector>
#include <iostream>

// Klasa realizująca sortowanie szybkie (QuickSort)
class QuickSort {
public:
    void displaySortMenu(); // Wyświetla menu wyboru typu pivota
    int getSortChoice(); // Pobiera wybór użytkownika

    template<typename T>
    void performSort(int choice, std::vector<T>& data); // Wykonuje sortowanie na podstawie wybranego typu pivota
};

#endif //PROJECT_AIZO_QUICKSORT_H
