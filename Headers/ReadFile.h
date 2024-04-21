#ifndef PROJECT_AIZO_READFILE_H
#define PROJECT_AIZO_READFILE_H

#include <string>
#include <vector>

class ReadFile {
public:
    template<typename T>
    static std::vector<T> readData(const std::string& filename, bool fullRead = false);
};

#endif //PROJECT_AIZO_READFILE_H
