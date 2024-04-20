#include <iostream>
#include "../Headers/SelectDataType.h"
#include "../Headers/SelectWriteOrUse.h"

using namespace std;

vector<int> globalIntData;
vector<float> globalFloatData;
vector<char> globalCharData;
vector<double> globalDoubleData;

void SelectDataType::selectDataType() {
    cout << "\nMenu:" << endl;
    cout << "------------------------" << endl;
    cout << "1. Select -int" << endl;
    cout << "2. Select -float" << endl;
    cout << "3. Select -char" << endl;
    cout << "4. Select -double" << endl;
    cout << "------------------------" << endl;
    cout << "Select an option: ";
}

int SelectDataType::getSelection() {
    int selection;
    cout << "Select an option: ";
    cin >> selection;
    return selection;
}

void SelectDataType::processSelectFromLoadedFile(int selection) {
    const string basePath = "../Sources/";
    string filename;
    cout << "Write the name of the text file with the extension .txt: " << endl;
    cin >> filename;
    filename = basePath + filename;

    try {
        SelectWriteOrUse<int> intOptions;
        SelectWriteOrUse<float> floatOptions;
        SelectWriteOrUse<char> charOptions;

        switch (selection) {
            case 1: {
                globalIntData = fileReader.readData<int>(filename);
                SelectWriteOrUse<int> intOptions;
                intOptions.displayMenu();
                int choice = intOptions.getUserChoice();
                intOptions.processChoice(choice, globalIntData);
                break;
            }
            case 2: {
                globalFloatData = fileReader.readData<float>(filename);
                SelectWriteOrUse<float> floatOptions;
                floatOptions.displayMenu();
                int choice = floatOptions.getUserChoice(); // Zmienna 'choice' jest teraz zagnieżdżona w bloku.
                floatOptions.processChoice(choice, globalFloatData);
                break;
            }
            case 3: {
                globalCharData = fileReader.readData<char>(filename);
                SelectWriteOrUse<char> charOptions;
                charOptions.displayMenu();
                int choice = charOptions.getUserChoice(); // Tak samo tutaj.
                charOptions.processChoice(choice, globalCharData);
                break;
            }
            case 4: {
                globalDoubleData = fileReader.readData<double>(filename);
                SelectWriteOrUse<double> doubleOptions;
                doubleOptions.displayMenu();
                int choice = doubleOptions.getUserChoice();
                doubleOptions.processChoice(choice, globalDoubleData);
                break;
            }
            default:
                cout << "Invalid option, please try again!" << endl;
        }
    } catch (const runtime_error& e) {
        cerr << "Error: " << e.what() << endl;
    }
}