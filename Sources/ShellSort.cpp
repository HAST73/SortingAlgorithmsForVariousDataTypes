#include "../Headers/ShellSort.h"

#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>

void ShellSort::displayGapMenu() {
    std::cout << "Select gap sequence for ShellSort:" << std::endl;
    std::cout << "1. Shell sequence" << std::endl;
    std::cout << "2. Knuth sequence" << std::endl;
    std::cout << "3. Hibbard sequence" << std::endl;
    std::cout << "Choice: ";
}

ShellSort::GapSequence ShellSort::getUserGapChoice() {
    int choice;
    std::cin >> choice;
    switch (choice) {
        case 1: return SHELL;
        case 2: return KNUTH;
        case 3: return HIBBARD;
        default:
            std::cout << "Invalid choice, defaulting to Shell sequence." << std::endl;
            return SHELL;
    }
}

std::vector<int> ShellSort::generateGaps(size_t size, GapSequence sequence) {
    std::vector<int> gaps;
    if (sequence == KNUTH) {
        for (int k = 1; ; ) {
            int gap = (std::pow(3, k++) - 1) / 2;
            if (gap > size) break;
            gaps.push_back(gap);
        }
    } else if (sequence == HIBBARD) {
        for (int k = 1; ; k++) {
            int gap = std::pow(2, k) - 1;
            if (gap > size) break;
            gaps.push_back(gap);
        }
    } else {
        for (int gap = size / 2; gap > 0; gap /= 2) {
            gaps.push_back(gap);
        }
    }
    std::reverse(gaps.begin(), gaps.end()); // Ensure the gaps are in descending order
    return gaps;
}

template<typename T>
void ShellSort::shellSort(std::vector<T>& data, GapSequence gapSequence) {
    std::vector<int> gaps = generateGaps(data.size(), gapSequence);
    for (int gap : gaps) {
        for (size_t i = gap; i < data.size(); i++) {
            T temp = data[i];
            size_t j;
            for (j = i; j >= gap && data[j - gap] > temp; j -= gap) {
                data[j] = data[j - gap];
            }
            data[j] = temp;
        }
    }
}

template<typename T>
void ShellSort::sortAndSave(const std::vector<T>& data, const std::string& filename, GapSequence gapSequence) {
    std::vector<T> localData = data;
    shellSort(localData, gapSequence);

    // Generate the full filename based on the gap sequence
    std::string fullFilename = filename + "_";
    switch (gapSequence) {
        case SHELL: fullFilename += "default"; break;
        case KNUTH: fullFilename += "knuth"; break;
        case HIBBARD: fullFilename += "hibbard"; break;
    }
    fullFilename += ".txt"; // Append the file extension

    std::ofstream outFile(fullFilename);
    if (outFile.is_open()) {
        for (const T& element : localData) {
            outFile << element << '\n';
        }
        outFile.close();
        std::cout << "Sorted data saved to " << fullFilename << std::endl;
    } else {
        std::cerr << "Unable to open file for writing: " << fullFilename << '\n';
    }
}

// Explicit template instantiation
template void ShellSort::shellSort<int>(std::vector<int>& data, GapSequence gapSequence);
template void ShellSort::shellSort<float>(std::vector<float>& data, GapSequence gapSequence);
template void ShellSort::shellSort<char>(std::vector<char>& data, GapSequence gapSequence);
template void ShellSort::shellSort<double>(std::vector<double>& data, GapSequence gapSequence);

template void ShellSort::sortAndSave<int>(const std::vector<int>& data, const std::string& filename, GapSequence gapSequence);
template void ShellSort::sortAndSave<float>(const std::vector<float>& data, const std::string& filename, GapSequence gapSequence);
template void ShellSort::sortAndSave<char>(const std::vector<char>& data, const std::string& filename, GapSequence gapSequence);
template void ShellSort::sortAndSave<double>(const std::vector<double>& data, const std::string& filename, GapSequence gapSequence);