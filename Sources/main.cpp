#include <iostream>
#include "../Headers/Menu.h"
#include "../Headers/SelectDataType.h"

using namespace std;

int main() {
    Menu menu;
    SelectDataType selectDataType;

    while(Menu::running){
        selectDataType.selectDataType();
        int selection = selectDataType.getSelection();

        selectDataType.processSelect(selection);
        while (Menu::running) {
            menu.generateGeneralMenu();
            int choice = menu.getChoice();

            menu.processChoice(choice);
        }
    }
    return 0;
}
