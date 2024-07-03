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
    cout << "1. Display Array" << endl;
    cout << "2. Sort" << endl;
    cout << "3. Check if array is sorted" << endl; // New option
    cout << "4. Exit" << endl; // Exit option
    cout << "------------------------" << endl;
    cout << "Select an option: ";
}

template<typename T>
void SelectWriteOrUse<T>::processChoice(vector<T>& data) {
    int choice;
    bool exit = false;
    while (!exit) {
        displayMenu();
        cin >> choice;
        switch (choice) {
            case 1:
                for (size_t i = 0; i < data.size(); ++i) {
                    cout << data[i] << " ";
                }
                cout << endl;
                break;
            case 2: {
                SortMenu sortMenu;
                sortMenu.displaySortMenu();
                int sortChoice = sortMenu.getSortChoice();
                sortMenu.performSort(sortChoice, data);
                break;
            }
            case 3:
                if (CheckIsItSorted::isSorted(data)) {
                    cout << "Array is sorted." << endl;
                } else {
                    cout << "Array is not sorted." << endl;
                }
                break;
            case 4:
                exit = true;
                break;
            default:
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
