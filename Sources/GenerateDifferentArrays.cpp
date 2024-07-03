#include "../Headers/GenerateDifferentArrays.h"
#include <algorithm>
#include <fstream>
#include <random>
#include <iostream>

using namespace std;

void GenerateDifferentArrays::generateRandom(vector<int>& data) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(1, 1000000);
    generate(data.begin(), data.end(), [&]() { return distrib(gen); });
}

void GenerateDifferentArrays::generateSorted(vector<int>& data) {
    generateRandom(data);
    sort(data.begin(), data.end());
}

void GenerateDifferentArrays::generateReverseSorted(vector<int>& data) {
    generateSorted(data);
    reverse(data.begin(), data.end());
}

void GenerateDifferentArrays::generatePartiallySorted(vector<int>& data, int sortedPercentage) {
    size_t sortedSize = data.size() * sortedPercentage / 100;
    generateSorted(data);
    shuffle(data.begin() + sortedSize, data.end(), mt19937(random_device()()));
}

void GenerateDifferentArrays::saveToFile(const vector<int>& data, const string& filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        cerr << "Unable to open file: " << filename << endl;
        return;
    }
    file << data.size() << endl;  // Write the size of the array
    for (const int& num : data) {
        file << num << endl;
    }
    file.close();
}
