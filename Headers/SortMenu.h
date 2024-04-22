#ifndef PROJECT_AIZO_SORTMENU_H
#define PROJECT_AIZO_SORTMENU_H

#include <vector>

// Klasa menu wyboru metody sortowania
class SortMenu {
public:
    void displaySortMenu();  // Wyświetla menu wyboru algorytmu sortowania
    int getSortChoice();  // Pobiera wybór metody sortowania od użytkownika
    template<typename T>
    void performSort(int choice, std::vector<T>& data);  // Realizuje sortowanie zgodnie z wybraną metodą
};

#endif //PROJECT_AIZO_SORTMENU_H
