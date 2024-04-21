#include "../Headers/SelectWriteOrUse.h"
#include "../Headers/SortMenu.h"
#include "../Headers/CheckIsItSorted.h"

#include <iostream>
#include <vector>

using namespace std;

template<typename T>
void SelectWriteOrUse<T>::displayMenu() {
    cout << "\nData Options Menu:" << endl;
    cout << "------------------------" << endl;
    cout << "1. Display Array (First number is size)" << endl;
    cout << "2. Sort" << endl;
    cout << "3. Check if array is sorted" << endl; // New option
    cout << "------------------------" << endl;
    cout << "Select an option: ";
}

template<typename T>
int SelectWriteOrUse<T>::getUserChoice() {
    int choice;
    cin >> choice;
    return choice;
}

template<typename T>
void SelectWriteOrUse<T>::processChoice(int choice, vector<T>& data) {
    switch (choice) {
        case 1: {
            // Pomijamy pierwszy element, który jest rozmiarem tablicy
            for (size_t i = 0; i < data.size(); ++i) {
                cout << data[i] << " ";
            }
            cout << endl;
            break;
        }
        case 2: {
            cout << "Processing data..." << endl;
            SortMenu sortMenu;
            sortMenu.displaySortMenu();
            int sortChoice = sortMenu.getSortChoice();
            sortMenu.performSort(sortChoice, data); // Możliwe, że będziesz musiał zaimplementować tę metodę w SortMenu
            break;
        }
        case 3: {
            // New case to check if the array is sorted
            if (CheckIsItSorted::isSorted(data)) {
                cout << "Array is sorted." << endl;
            } else {
                cout << "Array is not sorted." << endl;
            }
            break;
        }
        default: {
            cout << "Invalid choice, please try again." << endl;
            break;
        }
    }
}

// Explicit template instantiation to avoid linker errors
template class SelectWriteOrUse<int>;
template class SelectWriteOrUse<float>;
template class SelectWriteOrUse<char>;
template class SelectWriteOrUse<double>;