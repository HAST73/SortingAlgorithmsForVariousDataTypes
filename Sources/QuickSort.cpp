#include "../Headers/QuickSort.h"
#include "../Headers/QuickSortHelper.h"
#include <iostream>
#include <chrono>

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
    typename QuickSortHelper<T>::PivotType pivotType = QuickSortHelper<T>::LEFT; // Default
    string pivotName;

    switch (choice) {
        case 1:
            pivotType = QuickSortHelper<T>::LEFT;
            pivotName = "left";
            break;
        case 2:
            pivotType = QuickSortHelper<T>::MIDDLE;
            pivotName = "middle";
            break;
        case 3:
            pivotType = QuickSortHelper<T>::RIGHT;
            pivotName = "right";
            break;
        case 4:
            pivotType = QuickSortHelper<T>::RANDOM;
            pivotName = "random";
            break;
        default:
            cout << "Invalid sort choice, please try again." << endl;
            return;
    }

    auto start = chrono::high_resolution_clock::now();
    QuickSortHelper<T>::quickSort(data, 0, data.size() - 1, pivotType);
    auto end = chrono::high_resolution_clock::now();

    chrono::duration<double, milli> duration = end - start;

    string filename = "quicksort_" + pivotName + ".txt";
    string filepath = "../Sources/" + filename;
    QuickSortHelper<T>::saveToFile(data, filepath);

    cout << "Data sorted using " << pivotName << " pivot and saved to " << filepath << endl;
    cout << "Sorting time: " << duration.count() << " ms" << endl;
}

// Explicit template instantiation for the used types
template void QuickSort::performSort<int>(int choice, vector<int>& data);
template void QuickSort::performSort<float>(int choice, vector<float>& data);
template void QuickSort::performSort<char>(int choice, vector<char>& data);
template void QuickSort::performSort<double>(int choice, vector<double>& data);
