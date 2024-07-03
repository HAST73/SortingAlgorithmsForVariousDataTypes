#ifndef SORTINGALGORITHMSFORVARIOUSDATATYPES_READFILE_H
#define SORTINGALGORITHMSFORVARIOUSDATATYPES_READFILE_H

#include <string>
#include <vector>

// Class for reading data from a file
class ReadFile {
public:
    template<typename T>
    static std::vector<T> readData(const std::string& filename, bool fullRead = false);  // Reads data from a file, 'fullRead' indicates if the first number is data size
};

#endif //SORTINGALGORITHMSFORVARIOUSDATATYPES_READFILE_H