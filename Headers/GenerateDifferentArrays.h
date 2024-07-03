#ifndef SORTINGALGORITHMSFORVARIOUSDATATYPES_GENERATEDIFFERENTARRAYS_H
#define SORTINGALGORITHMSFORVARIOUSDATATYPES_GENERATEDIFFERENTARRAYS_H

#include <vector>
#include <string>

// Class for generating different types of arrays
class GenerateDifferentArrays {
public:
    // Methods for generating data
    void generateRandom(std::vector<int>& data); // Generates random data
    void generateSorted(std::vector<int>& data); // Generates sorted data in ascending order
    void generateReverseSorted(std::vector<int>& data); // Generates sorted data in descending order
    void generatePartiallySorted(std::vector<int>& data, int sortedPercentage); // Generates partially sorted data

    // Method for saving data to a file
    void saveToFile(const std::vector<int>& data, const std::string& filename);
};

#endif //SORTINGALGORITHMSFORVARIOUSDATATYPES_GENERATEDIFFERENTARRAYS_H
