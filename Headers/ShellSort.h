#ifndef PROJECT_AIZO_SHELLSORT_H
#define PROJECT_AIZO_SHELLSORT_H

#include <vector>
#include <string>

class ShellSort {
public:
    enum GapSequence { SHELL, KNUTH, HIBBARD }; // Added HIBBARD sequence

    template<typename T>
    static void shellSort(std::vector<T>& data, GapSequence gapSequence);

    template<typename T>
    static void sortAndSave(const std::vector<T>& data, const std::string& filename, GapSequence gapSequence);

    static void displayGapMenu(); // For displaying the gap sequence menu
    static GapSequence getUserGapChoice(); // For getting user's choice
    static std::vector<int> generateGaps(size_t size, GapSequence sequence); // To calculate gaps
};


#endif //PROJECT_AIZO_SHELLSORT_H
