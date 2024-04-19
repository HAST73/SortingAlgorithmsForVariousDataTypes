#ifndef PROJECT_AIZO_VIEWARRAYS_H
#define PROJECT_AIZO_VIEWARRAYS_H

#include <vector>
#include <iostream>

using namespace std;

class ViewArrays {
public:
    template<typename T>
    static void displayArray(const vector<T>& data);
};

#endif //PROJECT_AIZO_VIEWARRAYS_H
