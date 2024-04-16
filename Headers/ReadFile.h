#ifndef PROJECT_AIZO_READFILE_H
#define PROJECT_AIZO_READFILE_H

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

class ReadFile {
public:
    template<typename T>
    vector<T> readData(const string& filename);
};

#endif //PROJECT_AIZO_READFILE_H
