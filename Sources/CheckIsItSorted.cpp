#include "../Headers/CheckIsItSorted.h"

using namespace std;

template<typename T>
bool CheckIsItSorted::isSorted(const vector<T>& data) {
    for (size_t i = 0; i < data.size() - 1; ++i) {
        if (data[i] > data[i + 1]) {
            return false; // If any element is greater than the next, not sorted
        }
    }
    return true; // All elements are in order, sorted
}

// Explicit template instantiation for common types
template bool CheckIsItSorted::isSorted<int>(const vector<int>& data);
template bool CheckIsItSorted::isSorted<float>(const vector<float>& data);
template bool CheckIsItSorted::isSorted<char>(const vector<char>& data);
template bool CheckIsItSorted::isSorted<double>(const vector<double>& data);
