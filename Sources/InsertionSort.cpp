#include "../Headers/InsertionSort.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

template<typename T>
void InsertionSort::sortAndSave(const vector<T>& data, const string& filename) {
    // Creating a local copy of the data because we want to sort it
    vector<T> localData = data;

    // Start of time measurement
    auto start = chrono::high_resolution_clock::now();

    // Insertion sort
    for (int i = 1; i < localData.size(); ++i) {
        T key = localData[i];
        int j = i - 1;

        while (j >= 0 && localData[j] > key) {
            localData[j + 1] = localData[j];
            j = j - 1;
        }
        localData[j + 1] = key;
    }

    // End of time measurement
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> duration = end - start;

    // Saving sorted data to a file
    ofstream outFile(filename);
    if (outFile.is_open()) {
        for (const T& element : localData) {
            outFile << element << '\n';
        }
        outFile.close();
        cout << "Sorted data saved to " << filename << ". Time taken: " << duration.count() << " ms" << endl;
    } else {
        cerr << "Unable to open file for writing: " << filename << '\n';
    }
}

template void InsertionSort::sortAndSave<int>(const vector<int>& data, const string& filename);
template void InsertionSort::sortAndSave<float>(const vector<float>& data, const string& filename);
template void InsertionSort::sortAndSave<char>(const vector<char>& data, const string& filename);
template void InsertionSort::sortAndSave<double>(const vector<double>& data, const string& filename);
