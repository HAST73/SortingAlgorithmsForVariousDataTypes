#ifndef SORTINGALGORITHMSFORVARIOUSDATATYPES_SHELLSORT_H
#define SORTINGALGORITHMSFORVARIOUSDATATYPES_SHELLSORT_H

#include <vector>
#include <string>
#include <functional>

// Class implementing Shell sort
class ShellSort {
public:
    enum GapSequence { SHELL, KNUTH, HIBBARD };  // Definition of available gap sequences

    template<typename T>
    static void shellSort(std::vector<T>& data, GapSequence gapSequence);  // Sorts the data

    template<typename T>
    static void sortAndSave(const std::vector<T>& data, const std::string& filename, GapSequence gapSequence);  // Sorts the data and saves to file

    static void displayGapMenu();  // Displays menu for selecting gap sequence
    static GapSequence getUserGapChoice();  // Gets user's choice of gap sequence
    static std::vector<int> generateGaps(size_t size, GapSequence sequence);  // Generates gap sequence
};

#endif //SORTINGALGORITHMSFORVARIOUSDATATYPES_SHELLSORT_H
