#include "../Headers/ViewArrays.h"

using namespace std;

template<typename T>
void ViewArrays::displayArray(const vector<T>& data) {
    for (const T& element : data) {
        cout << element << " ";
    }
    cout << endl;
}

// Eksplicytna instancja szablonu dla typów, które mogą być używane
template void ViewArrays::displayArray<int>(const vector<int>&);
template void ViewArrays::displayArray<float>(const vector<float>&);
template void ViewArrays::displayArray<char>(const vector<char>&);
template void ViewArrays::displayArray<double>(const vector<double>&);