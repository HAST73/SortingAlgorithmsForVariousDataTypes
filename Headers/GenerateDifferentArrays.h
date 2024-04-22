#ifndef PROJECT_AIZO_GENERATEDIFFERENTARRAYS_H
#define PROJECT_AIZO_GENERATEDIFFERENTARRAYS_H

#include <vector>
#include <string>

class GenerateDifferentArrays {
public:
    // Konstruktor (opcjonalnie jeśli potrzebny)
    GenerateDifferentArrays();

    // Metody do generowania danych
    void generateRandom(std::vector<int>& data);
    void generateSorted(std::vector<int>& data);
    void generateReverseSorted(std::vector<int>& data);
    void generatePartiallySorted(std::vector<int>& data, int sortedPercentage);

    // Metoda do zapisywania danych do pliku
    void saveToFile(const std::vector<int>& data, const std::string& filename);
};

#endif //PROJECT_AIZO_GENERATEDIFFERENTARRAYS_H
