#ifndef PROJECT_AIZO_SELECTWRITEORUSE_H
#define PROJECT_AIZO_SELECTWRITEORUSE_H

#include <vector>

template<typename T>
class SelectWriteOrUse {
public:
    void displayMenu();
    void processChoice(std::vector<T>& data);
};

#endif //PROJECT_AIZO_SELECTWRITEORUSE_H
