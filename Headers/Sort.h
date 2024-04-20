#ifndef PROJECT_AIZO_SORT_H
#define PROJECT_AIZO_SORT_H

#include <vector>
#include <string>

template<typename T>
class Sort {
public:
    enum PivotType { LEFT, MIDDLE, RIGHT, RANDOM };

    static void quickSort(std::vector<T>& data, int left, int right, PivotType pivotType);
    static void saveToFile(const std::vector<T>& data, const std::string& filename);
};

#endif //PROJECT_AIZO_SORT_H
