#ifndef PROJECT_AIZO_SELECTWRITEORUSE_H
#define PROJECT_AIZO_SELECTWRITEORUSE_H

#include <vector>

// Klasa zarządzająca wyborem operacji na danych
template<typename T>
class SelectWriteOrUse {
public:
    void displayMenu();  // Wyświetla menu opcji dla danych
    void processChoice(std::vector<T>& data);  // Obsługuje wybraną opcję
};

#endif //PROJECT_AIZO_SELECTWRITEORUSE_H
