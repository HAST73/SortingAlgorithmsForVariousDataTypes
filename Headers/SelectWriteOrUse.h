#ifndef PROJECT_AIZO_SELECTWRITEORUSE_H
#define PROJECT_AIZO_SELECTWRITEORUSE_H

#include <vector>
#include <iostream>

using namespace std;

template<typename T>
class SelectWriteOrUse {
public:
    void displayMenu();
    int getUserChoice();
    void processChoice(int choice, vector<T>& data);
};

#endif //PROJECT_AIZO_SELECTWRITEORUSE_H
