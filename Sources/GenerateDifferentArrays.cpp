#include "../Headers/GenerateDifferentArrays.h"

#include <algorithm>
#include <fstream>
#include <random>
#include <iostream>

void GenerateDifferentArrays::generateRandom(std::vector<int>& data) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(1, 1000000);
    std::generate(data.begin(), data.end(), [&]() { return distrib(gen); });
}

void GenerateDifferentArrays::generateSorted(std::vector<int>& data) {
    generateRandom(data);
    std::sort(data.begin(), data.end());
}

void GenerateDifferentArrays::generateReverseSorted(std::vector<int>& data) {
    generateSorted(data);
    std::reverse(data.begin(), data.end());
}

void GenerateDifferentArrays::generatePartiallySorted(std::vector<int>& data, int sortedPercentage) {
    size_t sortedSize = data.size() * sortedPercentage / 100;
    generateSorted(data);
    std::shuffle(data.begin() + sortedSize, data.end(), std::mt19937(std::random_device()()));
}

void GenerateDifferentArrays::saveToFile(const std::vector<int>& data, const std::string& filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Unable to open file: " << filename << std::endl;
        return;
    }
    file << data.size() << std::endl;  // Zapis rozmiaru tablicy
    for (const int& num : data) {
        file << num << std::endl;
    }
    file.close();
}
