#include <iostream>
#include <vector>
#include <string>
#include "../Headers/Menu.h"

using namespace std;

bool Menu::running = true;

void Menu::generateGeneralMenu() {
    cout << "\nMenu:" << endl;
    cout << "------------------------" << endl;
    cout << "1. Load data from a file" << endl;
    cout << "2. Generate arrays with random values in a new text file" << endl;
    cout << "5. Exit the program" << endl;
    cout << "------------------------" << endl;
    cout << "In case when you don't see a text file after sorting, just insert this hot key : CTRL + ALT + Y" << endl;
    cout << "------------------------" << endl;
    cout << "Select an option: ";
}

int Menu::getChoice() {
    int choice;
    cin >> choice;
    return choice;
}

void Menu::processChoice(int choice) {
    SelectDataType selectDataType;
    switch (choice) {
        case 1:
        {
            cout << "Option 1 selected" << endl;
            selectDataType.selectDataType();
            int selection = selectDataType.getSelection();
            selectDataType.processSelectFromLoadedFile(selection);
            break;
        }
        case 2:
        {
            displayGenerateArrayMenu();
            break;
        }
        case 5:
        {
            running = false;
            break;
        }
        default:
        {
            cout << "Invalid option, please try again!" << endl;
            break;
        }
    }
}

void Menu::displayGenerateArrayMenu() {
    cout << "Select type of array to generate:" << endl;
    cout << "1. Random" << endl;
    cout << "2. Sorted" << endl;
    cout << "3. Reverse Sorted" << endl;
    cout << "4. Partially Sorted" << endl;
    cout << "0. Return to Main Menu" << endl;
    cout << "Enter your choice: ";
    int type;
    cin >> type;
    if (type == 0) {
        return; // Return to main menu
    }
    generateAndSaveArray(type);
}

int Menu::getArraySize() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;
    return size;
}

void Menu::generateAndSaveArray(int type) {
    int arraySize = getArraySize();
    vector<int> data(arraySize);
    string filename;
    cout << "Enter filename: ";
    cin >> filename;
    string fullFilename = "../Sources/" + filename;

    switch (type) {
        case 1:
            arrayGenerator.generateRandom(data);
            break;
        case 2:
            arrayGenerator.generateSorted(data);
            break;
        case 3:
            arrayGenerator.generateReverseSorted(data);
            break;
        case 4:
            int percentage;
            cout << "Enter sorted percentage: ";
            cin >> percentage;
            arrayGenerator.generatePartiallySorted(data, percentage);
            break;
        default:
            cout << "Invalid selection, generating random array by default.\n";
            arrayGenerator.generateRandom(data);
            break;
    }

    arrayGenerator.saveToFile(data, fullFilename);
    cout << "Data saved to " << fullFilename << endl;
}

