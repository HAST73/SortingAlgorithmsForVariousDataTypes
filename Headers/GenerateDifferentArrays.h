#ifndef PROJECT_AIZO_GENERATEDIFFERENTARRAYS_H
#define PROJECT_AIZO_GENERATEDIFFERENTARRAYS_H

#include <vector>
#include <string>

// Klasa generująca różne typy tablic
class GenerateDifferentArrays {
public:
    // Metody do generowania danych
    void generateRandom(std::vector<int>& data); // Generuje dane losowe
    void generateSorted(std::vector<int>& data); // Generuje dane posortowane rosnąco
    void generateReverseSorted(std::vector<int>& data); // Generuje dane posortowane malejąco
    void generatePartiallySorted(std::vector<int>& data, int sortedPercentage); // Generuje dane częściowo posortowane

    // Metoda do zapisywania danych do pliku
    void saveToFile(const std::vector<int>& data, const std::string& filename);
};

#endif //PROJECT_AIZO_GENERATEDIFFERENTARRAYS_H
