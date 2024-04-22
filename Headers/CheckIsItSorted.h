#ifndef PROJECT_AIZO_CHECKISITSORTED_H
#define PROJECT_AIZO_CHECKISITSORTED_H

#include <vector>

// Klasa sprawdzająca, czy tablica jest posortowana
class CheckIsItSorted {
public:
    template<typename T>
    static bool isSorted(const std::vector<T>& data); // Metoda statyczna sprawdzająca posortowanie
};

#endif //PROJECT_AIZO_CHECKISITSORTED_H
