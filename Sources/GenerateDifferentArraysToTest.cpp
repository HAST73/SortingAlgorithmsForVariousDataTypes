#include "../Headers/GenerateDifferentArraysToTest.h"
#include <algorithm>
#include <fstream>
#include <random>
#include <iostream>

using namespace std;

GenerateDifferentArraysToTest::GenerateDifferentArraysToTest() {}

void GenerateDifferentArraysToTest::generateAndSaveArrays() {
    const int numArrays = 100;
    const int arraySize = 400000;

    vector<int> data(arraySize);

    // Generating and saving Random arrays
    for (int i = 0; i < numArrays; ++i) {
        generateRandom(data);
        saveToFile(data, "../Sources/Random_" + to_string(i) + ".txt");
    }

    // Generating and saving Sorted arrays
    for (int i = 0; i < numArrays; ++i) {
        generateSorted(data);
        saveToFile(data, "../Sources/Sorted_" + to_string(i) + ".txt");
    }

    // Generating and saving Reverse Sorted arrays
    for (int i = 0; i < numArrays; ++i) {
        generateReverseSorted(data);
        saveToFile(data, "../Sources/Reverse_Sorted_" + to_string(i) + ".txt");
    }

    // Generating and saving Partially Sorted 33% arrays
    for (int i = 0; i < numArrays; ++i) {
        generatePartiallySorted(data, 33);
        saveToFile(data, "../Sources/Partially_Sorted_33_" + to_string(i) + ".txt");
    }

    // Generating and saving Partially Sorted 66% arrays
    for (int i = 0; i < numArrays; ++i) {
        generatePartiallySorted(data, 66);
        saveToFile(data, "../Sources/Partially_Sorted_66_" + to_string(i) + ".txt");
    }
}

void GenerateDifferentArraysToTest::generateRandom(vector<int>& data) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(1, 1000000);
    generate(data.begin(), data.end(), [&]() { return distrib(gen); });
}

void GenerateDifferentArraysToTest::generateSorted(vector<int>& data) {
    generateRandom(data);
    sort(data.begin(), data.end());
}

void GenerateDifferentArraysToTest::generateReverseSorted(vector<int>& data) {
    generateSorted(data);
    reverse(data.begin(), data.end());
}

void GenerateDifferentArraysToTest::generatePartiallySorted(vector<int>& data, int sortedPercentage) {
    size_t sortedSize = data.size() * sortedPercentage / 100;
    generateSorted(data);
    shuffle(data.begin() + sortedSize, data.end(), mt19937(random_device()()));
}

void GenerateDifferentArraysToTest::saveToFile(const vector<int>& data, const string& filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        cerr << "Unable to open file: " << filename << endl;
        return;
    }
    file << data.size() << '\n';
    for (int num : data) {
        file << num << '\n';
    }
    file.close();
}
