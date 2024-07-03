#include "../Headers/SortMenu.h"
#include "../Headers/QuickSort.h"
#include "../Headers/InsertionSort.h"
#include "../Headers/HeapSort.h"
#include "../Headers/ShellSort.h"
#include <iostream>

using namespace std;

void SortMenu::displaySortMenu() {
    cout << "\nSort Options Menu:" << endl;
    cout << "------------------------" << endl;
    cout << "1. QuickSort" << endl;
    cout << "2. ShellSort" << endl;
    cout << "3. HeapSort" << endl;
    cout << "4. InsertionSort" << endl;
    cout << "------------------------" << endl;
    cout << "Select a sorting method: ";
}

int SortMenu::getSortChoice() {
    int choice;
    cin >> choice;
    return choice;
}

template<typename T>
void SortMenu::performSort(int choice, vector<T>& data) {
    switch (choice) {
        case 1:
        {
            QuickSort sorter; // Declaration of sorter object
            sorter.displaySortMenu();
            int sortChoice = sorter.getSortChoice(); // Declaration of sortChoice variable
            sorter.performSort(sortChoice, data);
            break;
        }
        case 2:
        {
            ShellSort::displayGapMenu();
            ShellSort::GapSequence seq = ShellSort::getUserGapChoice();
            // Pass only the base part of the filename
            ShellSort::sortAndSave(data, "../Sources/shell_sort", seq);
            break;
        }

        case 3:
            HeapSort::sortAndSave(data, "../Sources/heap_sort.txt");
            break;
        case 4:
        {
            InsertionSort::sortAndSave(data, "../Sources/insertion_sort.txt");
            break;
        }
        default:
            cout << "Invalid sort choice, please try again." << endl;
            break;
    }
}

// Explicit template instantiation for used types
template void SortMenu::performSort<int>(int choice, std::vector<int>& data);
template void SortMenu::performSort<float>(int choice, std::vector<float>& data);
template void SortMenu::performSort<char>(int choice, std::vector<char>& data);
template void SortMenu::performSort<double>(int choice, std::vector<double>& data);
