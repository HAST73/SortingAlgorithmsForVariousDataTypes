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

void SelectDataType::processSelectFromLoadedFile(int selection) {
    const string basePath = "../Sources/";
    string filename;
    cout << "Write the name of the text file with the extension .txt: " << endl;
    cin >> filename;
    filename = basePath + filename;

    try {
        switch (selection) {
            case 1: {
                cout << "Option 1 selected - int" << endl;
                vector<int> data = fileReader.readData<int>(filename);

                break;
            }
            case 2: {
                cout << "Option 2 selected - float" << endl;
                vector<float> data = fileReader.readData<float>(filename);
                // Process data as needed.
                break;
            }
            case 3: {
                cout << "Option 3 selected - char" << endl;
                vector<char> data = fileReader.readData<char>(filename);
                // Process data as needed.
                break;
            }
            default:
                cout << "Invalid option, please try again!" << endl;
                break;
        }
    } catch (const runtime_error& e) {
        cerr << "Error: " << e.what() << endl;
    }
}