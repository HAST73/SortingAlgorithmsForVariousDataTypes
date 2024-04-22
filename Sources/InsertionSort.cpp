#include "../Headers/InsertionSort.h"


#include <fstream>
#include <iostream>
#include <vector>
#include <chrono>

template<typename T>
void InsertionSort::sortAndSave(const std::vector<T>& data, const std::string& filename) {
    // Tworzymy lokalną kopię danych, ponieważ chcemy je posortować
    std::vector<T> localData = data;

    // Rozpoczęcie pomiaru czasu
    auto start = std::chrono::high_resolution_clock::now();

    // Sortowanie przez wstawianie
    for (int i = 1; i < localData.size(); ++i) {
        T key = localData[i];
        int j = i - 1;

        while (j >= 0 && localData[j] > key) {
            localData[j + 1] = localData[j];
            j = j - 1;
        }
        localData[j + 1] = key;
    }

    // Zakończenie pomiaru czasu
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration = end - start;

    // Zapisanie posortowanych danych do pliku
    std::ofstream outFile(filename);
    if (outFile.is_open()) {
        for (const T& element : localData) {
            outFile << element << '\n';
        }
        outFile.close();
        std::cout << "Sorted data saved to " << filename << ". Time taken: " << duration.count() << " ms" << std::endl;
    } else {
        std::cerr << "Unable to open file for writing: " << filename << '\n';
    }
}

// Eksplikacje instancji szablonu
template void InsertionSort::sortAndSave<int>(const std::vector<int>& data, const std::string& filename);
template void InsertionSort::sortAndSave<float>(const std::vector<float>& data, const std::string& filename);
template void InsertionSort::sortAndSave<char>(const std::vector<char>& data, const std::string& filename);
template void InsertionSort::sortAndSave<double>(const std::vector<double>& data, const std::string& filename);
