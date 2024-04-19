#include "../Headers/SelectSort.h"

#include <iostream>

using namespace std;

void SelectSort::displaySortMenu() {
    cout << "\nSort Options Menu:" << endl;
    cout << "------------------------" << endl;
    cout << "1. QuickSort" << endl;
    cout << "2. ShellSort" << endl;
    cout << "3. HeapSort" << endl;
    cout << "4. InsertionSort" << endl;
    cout << "------------------------" << endl;
    cout << "Select a sorting method: ";
}

int SelectSort::getSortChoice() {
    int choice;
    cin >> choice;
    return choice;
}

template<typename T>
void SelectSort::performSort(int choice, vector<T>& data) {
    switch (choice) {
        case 1:
            // Call QuickSort on data
            break;
        case 2:
            // Call ShellSort on data
            break;
        case 3:
            // Call HeapSort on data
            break;
        case 4:
            // Call InsertionSort on data
            break;
        default:
            cout << "Invalid sort choice, please try again." << endl;
            break;
    }
}

// Potrzebne eksplicytna instancja szablonu dla używanych typów
template void SelectSort::performSort<int>(int choice, vector<int>& data);
template void SelectSort::performSort<float>(int choice, vector<float>& data);
template void SelectSort::performSort<char>(int choice, vector<char>& data);
