#include "../Headers/HeapSort.h"
#include <fstream>
#include <iostream>
#include <chrono>  // Include for high-resolution timing
#include <vector>

template<typename T>
void HeapSort::heapify(std::vector<T>& data, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && data[left] > data[largest])
        largest = left;

    if (right < n && data[right] > data[largest])
        largest = right;

    if (largest != i) {
        std::swap(data[i], data[largest]);
        heapify(data, n, largest);
    }
}

template<typename T>
void HeapSort::buildHeap(std::vector<T>& data) {
    int n = data.size();
    for (int i = n / 2 - 1; i >= 0; --i)
        heapify(data, n, i);
}

template<typename T>
void HeapSort::heapSort(std::vector<T>& data) {
    buildHeap(data);
    int n = data.size();
    for (int i = n - 1; i > 0; --i) {
        std::swap(data[0], data[i]);
        heapify(data, i, 0);
    }
}

template<typename T>
void HeapSort::sortAndSave(const std::vector<T>& data, const std::string& filename) {
    std::vector<T> localData = data;

    auto start = std::chrono::high_resolution_clock::now();  // Start timing the sort process
    heapSort(localData);  // Perform the heap sort
    auto end = std::chrono::high_resolution_clock::now();  // End timing the sort process

    std::chrono::duration<double, std::milli> duration = end - start;  // Calculate duration in milliseconds

    std::ofstream outFile(filename);
    if (outFile.is_open()) {
        for (const T& element : localData) {
            outFile << element << '\n';
        }
        outFile.close();
        std::cout << "Sorted data saved to " << filename << std::endl;
        std::cout << "Time taken for sorting: " << duration.count() << " ms" << std::endl;  // Output the time taken for sorting
    } else {
        std::cerr << "Unable to open file for writing: " << filename << '\n';
    }
}

// Eksplicytne instancje szablonu
template void HeapSort::heapSort<int>(std::vector<int>& data);
template void HeapSort::heapSort<float>(std::vector<float>& data);
template void HeapSort::heapSort<char>(std::vector<char>& data);
template void HeapSort::heapSort<double>(std::vector<double>& data);

template void HeapSort::sortAndSave<int>(const std::vector<int>& data, const std::string& filename);
template void HeapSort::sortAndSave<float>(const std::vector<float>& data, const std::string& filename);
template void HeapSort::sortAndSave<char>(const std::vector<char>& data, const std::string& filename);
template void HeapSort::sortAndSave<double>(const std::vector<double>& data, const std::string& filename);


