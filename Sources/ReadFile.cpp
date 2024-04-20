#include "../Headers/ReadFile.h"

using namespace std;

template<typename T>
vector<T> ReadFile::readData(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        throw runtime_error("Unable to open file: " + filename);
    }

    int size;
    file >> size; // Czytanie rozmiaru tablicy

    vector<T> data;
    T value;
    while(file >> value) {
        data.push_back(value);
    }
    if (data.size() != size) {
        throw runtime_error("File content does not match the specified size.");
    }

    file.close();
    return data;
}

// Explicit template instantiation
template vector<int> ReadFile::readData<int>(const string& filename);
template vector<float> ReadFile::readData<float>(const string& filename);
template vector<char> ReadFile::readData<char>(const string& filename);
template vector<double> ReadFile::readData<double>(const string& filename);
