#include "../Headers/Sort.h"
#include <fstream>
#include <cstdlib>
#include <ctime>

template<typename T>
void Sort<T>::quickSort(std::vector<T>& data, int left, int right, PivotType pivotType) {
    if (left < right) {
        int pivotIndex = left; // Default to left pivot
        int i = left, j = right;
        T pivot = data[left];

        // Pivot selection
        switch (pivotType) {
            case MIDDLE:
                pivotIndex = left + (right - left) / 2;
                pivot = data[pivotIndex];
                break;
            case RIGHT:
                pivotIndex = right;
                pivot = data[right];
                break;
            case RANDOM:
                std::srand(std::time(nullptr));
                pivotIndex = left + std::rand() % (right - left + 1);
                pivot = data[pivotIndex];
                break;
        }

        std::swap(data[pivotIndex], data[left]); // Move pivot to the start

        for (int k = left + 1; k <= right; k++) {
            if (data[k] < pivot) {
                i++;
                std::swap(data[i], data[k]);
            }
        }
        std::swap(data[i], data[left]); // Place pivot in the correct position

        quickSort(data, left, i - 1, pivotType);
        quickSort(data, i + 1, right, pivotType);
    }
}

template<typename T>
void Sort<T>::saveToFile(const std::vector<T>& data, const std::string& filename) {
    std::ofstream file(filename);
    if (file.is_open()) {
        for (const T& element : data) {
            file << element << "\n";
        }
        file.close();
    } else {
        throw std::runtime_error("Unable to open file: " + filename);
    }
}

// Explicit template instantiation
template class Sort<int>;
template class Sort<float>;
template class Sort<char>;
template class Sort<double>;