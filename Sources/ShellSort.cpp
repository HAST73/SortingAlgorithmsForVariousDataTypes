#include "../Headers/ShellSort.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <chrono>
#include <cmath>

using namespace std;

void ShellSort::displayGapMenu() {
    cout << "Select gap sequence for ShellSort:" << endl;
    cout << "1. Shell sequence" << endl;
    cout << "2. Knuth sequence" << endl;
    cout << "3. Hibbard sequence" << endl;
    cout << "Choice: ";
}

ShellSort::GapSequence ShellSort::getUserGapChoice() {
    int choice;
    cin >> choice;
    switch (choice) {
        case 1: return SHELL;
        case 2: return KNUTH;
        case 3: return HIBBARD;
        default:
            cout << "Invalid choice, defaulting to Shell sequence." << endl;
            return SHELL;
    }
}

vector<int> ShellSort::generateGaps(size_t size, GapSequence sequence) {
    vector<int> gaps;
    if (sequence == KNUTH) {
        for (int k = 1; ; ) {
            int gap = (pow(3, k++) - 1) / 2;
            if (gap > size) break;
            gaps.push_back(gap);
        }
    } else if (sequence == HIBBARD) {
        for (int k = 1; ; k++) {
            int gap = pow(2, k) - 1;
            if (gap > size) break;
            gaps.push_back(gap);
        }
    } else {
        for (int gap = size / 2; gap > 0; gap /= 2) {
            gaps.push_back(gap);
        }
    }
    reverse(gaps.begin(), gaps.end()); // Ensure the gaps are in descending order
    return gaps;
}

template<typename T>
void ShellSort::shellSort(vector<T>& data, GapSequence gapSequence) {
    vector<int> gaps = generateGaps(data.size(), gapSequence);
    auto start = chrono::high_resolution_clock::now();  // Start time measurement

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

    auto end = chrono::high_resolution_clock::now();  // End time measurement
    chrono::duration<double, milli> duration = end - start;  // Calculate duration
    cout << "Sorting completed in " << duration.count() << " ms" << endl;  // Print time taken
}

template<typename T>
void ShellSort::sortAndSave(const vector<T>& data, const string& filename, GapSequence gapSequence) {
    vector<T> localData = data;
    shellSort(localData, gapSequence); // Perform sorting

    // Generate full filename based on selected gap sequence
    string fullFilename = filename + "_";
    switch (gapSequence) {
        case SHELL: fullFilename += "default"; break;
        case KNUTH: fullFilename += "knuth"; break;
        case HIBBARD: fullFilename += "hibbard"; break;
    }
    fullFilename += ".txt"; // Add file extension

    // Write data to file
    ofstream outFile(fullFilename);
    if (outFile.is_open()) {
        for (const T& element : localData) {
            outFile << element << '\n';
        }
        outFile.close();
        cout << "Data saved to " << fullFilename << endl;
    } else {
        cerr << "Unable to open file for writing: " << fullFilename << '\n';
    }
}

// Explicit template instantiation
template void ShellSort::shellSort<int>(vector<int>& data, GapSequence gapSequence);
template void ShellSort::shellSort<float>(vector<float>& data, GapSequence gapSequence);
template void ShellSort::shellSort<char>(vector<char>& data, GapSequence gapSequence);
template void ShellSort::shellSort<double>(vector<double>& data, GapSequence gapSequence);

template void ShellSort::sortAndSave<int>(const vector<int>& data, const string& filename, GapSequence gapSequence);
template void ShellSort::sortAndSave<float>(const vector<float>& data, const string& filename, GapSequence gapSequence);
template void ShellSort::sortAndSave<char>(const vector<char>& data, const string& filename, GapSequence gapSequence);
template void ShellSort::sortAndSave<double>(const vector<double>& data, const string& filename, GapSequence gapSequence);
