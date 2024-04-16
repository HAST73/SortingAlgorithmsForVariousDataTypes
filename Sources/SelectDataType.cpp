#include <iostream>
#include "../Headers/SelectDataType.h"

using namespace std;

void SelectDataType::selectDataType() {
    cout << "\nMenu:" << endl;
    cout << "------------------------" << endl;
    cout << "1. Select -int" << endl;
    cout << "2. Select -float" << endl;
    cout << "3. Select -char" << endl;
    cout << "------------------------" << endl;
    cout << "Select an option: ";
}

int SelectDataType::getSelection() {
    int selection;
    cout << "Select an option: ";
    cin >> selection;
    return selection;
}

void SelectDataType::processSelect(int selection) {
    switch (selection) {
        case 1:
            cout << "Option 1 selected" << endl;
            // Tutaj możesz umieścić kod związany z opcją 1
            break;
        case 2:
            cout << "Option 2 selected" << endl;
            // Tutaj możesz umieścić kod związany z opcją 2
            break;
        case 3:
            cout << "Option 3 selected" << endl;
            // Tutaj możesz umieścić kod związany z opcją 3
            break;
        default:
            cout << "Invalid option, please try again!" << endl;
            break;
    }
}