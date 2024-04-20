#include "../Headers/Menu.h"

using namespace std;

int main() {
    Menu menu;

    while (Menu::running) {
        menu.generateGeneralMenu();
        int choice = menu.getChoice();

        menu.processChoice(choice);
    }


    return 0;
}

