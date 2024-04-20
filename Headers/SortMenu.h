#ifndef PROJECT_AIZO_SORTMENU_H
#define PROJECT_AIZO_SORTMENU_H

#include <vector>

class SortMenu {
public:
    void displaySortMenu();
    int getSortChoice();
    template<typename T>
    void performSort(int choice, std::vector<T>& data); // Tylko deklaracja.
};

#endif //PROJECT_AIZO_SORTMENU_H
