#include <iostream>
#include "../Headers/Menu.h"
#include "../Headers/SelectDataType.h"
#include <cstdlib>
#include <ctime>
#include <fstream>

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
            cout << "Option 2 selected - Generate random numbers file" << endl;
            cout << "Enter a filename for the random numbers: ";
            string filename;
            cin >> filename;
            string filepath = "../Sources/" + filename; // Prepend the folder path
            generateRandomNumberFile(filepath);
            break;
        }
        case 5:
            running = false;
            break;
        default:
            cout << "Invalid option, please try again!" << endl;
            break;
    }
}

void Menu::generateRandomNumberFile(const std::string& filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Unable to open file: " + filename);
    }

    std::srand(std::time(nullptr)); // Use current time as seed for random generator
    int count = std::rand() % 1000 + 1; // Generate a random count of numbers between 1 and 100

    file << count << std::endl; // First line is the count of random numbers
    for (int i = 0; i < count; ++i) {
        int randomNumber = std::rand() % 1001; // Generate a random number between 0 and 100
        file << randomNumber << std::endl;
    }

    file.close();
}

