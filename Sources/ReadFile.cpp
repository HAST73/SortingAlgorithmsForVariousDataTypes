#include "../Headers/ReadFile.h"

using namespace std;

template<typename T>
vector<T> ReadFile::readData(const string& filename) {
    vector<T> data;
    ifstream file(filename);

    if (!file.is_open()) {
        throw runtime_error("Unable to open file: " + filename);
    }

    T value;
    while (file >> value) {
        data.push_back(value);
    }

    file.close();
    return data;
}

// Explicit template instantiation
template vector<int> ReadFile::readData<int>(const string& filename);
template vector<float> ReadFile::readData<float>(const string& filename);
template vector<char> ReadFile::readData<char>(const string& filename);
