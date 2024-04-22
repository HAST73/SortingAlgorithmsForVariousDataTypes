#ifndef PROJECT_AIZO_SHELLSORT_H
#define PROJECT_AIZO_SHELLSORT_H

#include <vector>
#include <string>
#include <functional>

// Klasa realizująca sortowanie Shella
class ShellSort {
public:
    enum GapSequence { SHELL, KNUTH, HIBBARD };  // Definicja dostępnych sekwencji odstępów

    template<typename T>
    static void shellSort(std::vector<T>& data, GapSequence gapSequence);  // Sortuje dane

    template<typename T>
    static void sortAndSave(const std::vector<T>& data, const std::string& filename, GapSequence gapSequence);  // Sortuje dane i zapisuje do pliku

    static void displayGapMenu();  // Wyświetla menu wyboru sekwencji odstępów
    static GapSequence getUserGapChoice();  // Pobiera wybór sekwencji od użytkownika
    static std::vector<int> generateGaps(size_t size, GapSequence sequence);  // Generuje sekwencję odstępów
};

#endif //PROJECT_AIZO_SHELLSORT_H
