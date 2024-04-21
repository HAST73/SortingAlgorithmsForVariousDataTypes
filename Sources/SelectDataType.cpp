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
    cin >> selection;
    return selection;
}

void SelectDataType::processSelectFromLoadedFile(int selection) {
    const string basePath = "../Sources/";
    string filename;
    cout << "Write the name of the text file with the extension .txt: ";
    cin >> filename;
    filename = basePath + filename;

    cout << "Do you want the first number to represent the size of the array? (yes/no): ";
    string readMode;
    cin >> readMode;
    bool fullRead = (readMode == "no");

    try {
        switch (selection) {
            case 1:
                globalIntData = fileReader.readData<int>(filename, fullRead);
                SelectWriteOrUse<int> intOptions;
                intOptions.displayMenu();
                intOptions.processChoice(globalIntData);
                break;
            case 2:
                globalFloatData = fileReader.readData<float>(filename, fullRead);
                SelectWriteOrUse<float> floatOptions;
                floatOptions.displayMenu();
                floatOptions.processChoice(globalFloatData);
                break;
            case 3:
                globalCharData = fileReader.readData<char>(filename, fullRead);
                SelectWriteOrUse<char> charOptions;
                charOptions.displayMenu();
                charOptions.processChoice(globalCharData);
                break;
            case 4:
                globalDoubleData = fileReader.readData<double>(filename, fullRead);
                SelectWriteOrUse<double> doubleOptions;
                doubleOptions.displayMenu();
                doubleOptions.processChoice(globalDoubleData);
                break;
            default:
                cout << "Invalid choice, defaulting to -int type." << endl;
                globalIntData = fileReader.readData<int>(filename, fullRead);
                intOptions.displayMenu();
                intOptions.processChoice(globalIntData);
                break;
        }
    } catch (const runtime_error& e) {
        cerr << "Error: " << e.what() << endl;
    }
}