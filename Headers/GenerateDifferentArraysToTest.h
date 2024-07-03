#ifndef SORTINGALGORITHMSFORVARIOUSDATATYPES_GENERATEDIFFERENTARRAYSTOTEST_H
#define SORTINGALGORITHMSFORVARIOUSDATATYPES_GENERATEDIFFERENTARRAYSTOTEST_H

#include <vector>
#include <string>

// Class for generating different types of arrays to test
class GenerateDifferentArraysToTest {
public:
    GenerateDifferentArraysToTest();
    void generateAndSaveArrays();

private:
    void generateRandom(std::vector<int>& data); // Generates random data
    void generateSorted(std::vector<int>& data); // Generates sorted data in ascending order
    void generateReverseSorted(std::vector<int>& data); // Generates sorted data in descending order
    void generatePartiallySorted(std::vector<int>& data, int sortedPercentage); // Generates partially sorted data
    void saveToFile(const std::vector<int>& data, const std::string& filename); // Saves data to a file
};

#endif //SORTINGALGORITHMSFORVARIOUSDATATYPES_GENERATEDIFFERENTARRAYSTOTEST_H
