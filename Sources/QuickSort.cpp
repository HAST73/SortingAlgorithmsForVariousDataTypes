#include "../Headers/QuickSort.h"
#include "../Headers/Sort.h"

#include <iostream>

using namespace std;

void QuickSort::displaySortMenu() {
    cout << "\nSort Options Menu:" << endl;
    cout << "------------------------" << endl;
    cout << "1. QuickSort - Left Pivot" << endl;
    cout << "2. QuickSort - Middle Pivot" << endl;
    cout << "3. QuickSort - Right Pivot" << endl;
    cout << "4. QuickSort - Random Pivot" << endl;
    cout << "------------------------" << endl;
    cout << "Select a sorting method: ";
}

int QuickSort::getSortChoice() {
    int choice;
    cin >> choice;
    return choice;
}

template<typename T>
void QuickSort::performSort(int choice, vector<T>& data) {
    // We need to specify 'T' here to make sure 'Sort' is properly instantiated.
    typename Sort<T>::PivotType pivotType = Sort<T>::LEFT; // Default
    string pivotName;

    switch (choice) {
        case 1:
            pivotType = Sort<T>::LEFT;
            pivotName = "left";
            break;
        case 2:
            pivotType = Sort<T>::MIDDLE;
            pivotName = "middle";
            break;
        case 3:
            pivotType = Sort<T>::RIGHT;
            pivotName = "right";
            break;
        case 4:
            pivotType = Sort<T>::RANDOM;
            pivotName = "random";
            break;
        default:
            cout << "Invalid sort choice, please try again." << endl;
            return;
    }
    Sort<T>::quickSort(data, 0, data.size() - 1, pivotType);

    // Create a filename with a pivot type pattern
    std::string filename = "quicksort_" + pivotName + ".txt";

    // Prepend the relative directory path to the filename
    std::string filepath = "../Sources/" + filename;

    // Save the sorted data to the file in the desired directory
    Sort<T>::saveToFile(data, filepath);
    std::cout << "Data sorted using " << pivotName << " pivot and saved to " << filepath << std::endl;
}

// Potrzebne eksplicytna instancja szablonu dla używanych typów
template void QuickSort::performSort<int>(int choice, vector<int>& data);
template void QuickSort::performSort<float>(int choice, vector<float>& data);
template void QuickSort::performSort<char>(int choice, vector<char>& data);
template void QuickSort::performSort<double>(int choice, vector<double>& data);
