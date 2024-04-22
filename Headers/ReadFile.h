#ifndef PROJECT_AIZO_READFILE_H
#define PROJECT_AIZO_READFILE_H

#include <string>
#include <vector>

// Klasa służąca do odczytu danych z pliku
class ReadFile {
public:
    template<typename T>
    static std::vector<T> readData(const std::string& filename, bool fullRead = false);  // Czyta dane z pliku, 'fullRead' określa czy pierwsza liczba to rozmiar danych
};

#endif //PROJECT_AIZO_READFILE_H
