#include "../Headers/ReadFile.h"
#include <fstream>
#include <vector>
#include <stdexcept>

using namespace std;

template<typename T>
vector<T> ReadFile::readData(const string& filename, bool fullRead) {
    ifstream file(filename);
    if (!file.is_open()) {
        throw runtime_error("Unable to open file: " + filename);
    }

    vector<T> data;
    if (!fullRead) {
        int size;
        file >> size;
        data.resize(size);
        for (int i = 0; i < size; ++i) {
            if (!(file >> data[i])) {
                throw runtime_error("Error reading data from file.");
            }
        }
    } else {
        T temp;
        while (file >> temp) {
            data.push_back(temp);
        }
        if (!file.eof()) {
            file.close();
            throw runtime_error("Input error occurred while reading the file.");
        }
    }
    file.close();
    return data;
}

// Explicit template instantiation
template vector<int> ReadFile::readData<int>(const string& filename, bool fullRead);
template vector<float> ReadFile::readData<float>(const string& filename, bool fullRead);
template vector<char> ReadFile::readData<char>(const string& filename, bool fullRead);
template vector<double> ReadFile::readData<double>(const string& filename, bool fullRead);