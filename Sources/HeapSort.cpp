#include "../Headers/HeapSort.h"
#include <fstream>
#include <iostream>
#include <chrono>
#include <vector>

using namespace std;

template<typename T>
void HeapSort::heapify(vector<T>& data, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && data[left] > data[largest])
        largest = left;

    if (right < n && data[right] > data[largest])
        largest = right;

    if (largest != i) {
        swap(data[i], data[largest]);
        heapify(data, n, largest);
    }
}

template<typename T>
void HeapSort::buildHeap(vector<T>& data) {
    int n = data.size();
    for (int i = n / 2 - 1; i >= 0; --i)
        heapify(data, n, i);
}

template<typename T>
void HeapSort::heapSort(vector<T>& data) {
    buildHeap(data);
    int n = data.size();
    for (int i = n - 1; i > 0; --i) {
        swap(data[0], data[i]);
        heapify(data, i, 0);
    }
}

template<typename T>
void HeapSort::sortAndSave(const vector<T>& data, const string& filename) {
    vector<T> localData = data;

    auto start = chrono::high_resolution_clock::now();  // Start timing the sort process
    heapSort(localData);  // Perform the heap sort
    auto end = chrono::high_resolution_clock::now();  // End timing the sort process

    chrono::duration<double, milli> duration = end - start;  // Calculate duration in milliseconds

    ofstream outFile(filename);
    if (outFile.is_open()) {
        for (const T& element : localData) {
            outFile << element << '\n';
        }
        outFile.close();
        cout << "Sorted data saved to " << filename << endl;
        cout << "Time taken for sorting: " << duration.count() << " ms" << endl;  // Output the time taken for sorting
    } else {
        cerr << "Unable to open file for writing: " << filename << '\n';
    }
}

// Explicit template instantiation
template void HeapSort::heapSort<int>(vector<int>& data);
template void HeapSort::heapSort<float>(vector<float>& data);
template void HeapSort::heapSort<char>(vector<char>& data);
template void HeapSort::heapSort<double>(vector<double>& data);

template void HeapSort::sortAndSave<int>(const vector<int>& data, const string& filename);
template void HeapSort::sortAndSave<float>(const vector<float>& data, const string& filename);
template void HeapSort::sortAndSave<char>(const vector<char>& data, const string& filename);
template void HeapSort::sortAndSave<double>(const vector<double>& data, const string& filename);
