#ifndef PROJECT_AIZO_INSERTIONSORT_H
#define PROJECT_AIZO_INSERTIONSORT_H

#include <vector>
#include <string>

class InsertionSort {
public:
    template<typename T>
    static void sortAndSave(const std::vector<T>& data, const std::string& filename);
};

// Eksplicytne instancje szablonu
extern template void InsertionSort::sortAndSave<int>(const std::vector<int>& data, const std::string& filename);
extern template void InsertionSort::sortAndSave<float>(const std::vector<float>& data, const std::string& filename);
extern template void InsertionSort::sortAndSave<char>(const std::vector<char>& data, const std::string& filename);
extern template void InsertionSort::sortAndSave<double>(const std::vector<double>& data, const std::string& filename);

#endif //PROJECT_AIZO_INSERTIONSORT_H
