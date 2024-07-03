#include "../Headers/QuickSortHelper.h"
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

template<typename T>
void QuickSortHelper<T>::quickSort(vector<T>& data, int left, int right, PivotType pivotType) {
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
                srand(time(nullptr));
                pivotIndex = left + rand() % (right - left + 1);
                pivot = data[pivotIndex];
                break;
        }

        swap(data[pivotIndex], data[left]); // Move pivot to the start

        for (int k = left + 1; k <= right; k++) {
            if (data[k] < pivot) {
                i++;
                swap(data[i], data[k]);
            }
        }
        swap(data[i], data[left]); // Place pivot in the correct position

        quickSort(data, left, i - 1, pivotType);
        quickSort(data, i + 1, right, pivotType);
    }
}

template<typename T>
void QuickSortHelper<T>::saveToFile(const vector<T>& data, const string& filename) {
    ofstream file(filename);
    if (file.is_open()) {
        for (const T& element : data) {
            file << element << "\n";
        }
        file.close();
    } else {
        throw runtime_error("Unable to open file: " + filename);
    }
}

// Explicit template instantiation
template class QuickSortHelper<int>;
template class QuickSortHelper<float>;
template class QuickSortHelper<char>;
template class QuickSortHelper<double>;