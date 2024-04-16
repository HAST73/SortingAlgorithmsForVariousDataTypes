#include <iostream>
#include "../Headers/Menu.h"
#include "../Headers/SelectDataType.h"

using namespace std;

bool Menu::running = true;

void Menu::generateGeneralMenu() {
    cout << "\nMenu:" << endl;
    cout << "------------------------" << endl;
    cout << "1. Load data from a file" << endl;
    cout << "2. Generate arrays with random values" << endl;
    cout << "3. View arrays" << endl;
    cout << "4. Sort arrays" << endl;
    cout << "5. Exit the program" << endl;
    cout << "------------------------" << endl;
    cout << "Select an option: ";
}

int Menu::getChoice() {
    int choice;
    cout << "Select an option: ";
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
            cout << "Option 2 selected" << endl;
            // Tutaj możesz umieścić kod związany z opcją 2
            break;
        case 3:
            cout << "Option 3 selected" << endl;
            // Tutaj możesz umieścić kod związany z opcją 3
            break;
        case 4:
            cout << "Option 4 selected" << endl;
            // Tutaj możesz umieścić kod związany z opcją 4
            break;
        case 5:
            cout << "End of program" << endl;
            running = false;
            break;
        default:
            cout << "Invalid option, please try again!" << endl;
            break;
    }
}

