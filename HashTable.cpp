#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <locale>
#include <list>
#include "HashTable.h"

// Helper functions to handle conversions safely
int safeStoi(const std::string& str, int defaultVal = 0) {
    try {
        return std::stoi(str);
    } catch (...) {
        return defaultVal;
    }
}

float safeStof(const std::string& str, float defaultVal = 0.0f) {
    try {
        return std::stof(str);
    } catch (...) {
        return defaultVal;
    }
}

HashTable::HashTable(){
    cap = 200000;
    table = new std::list<Movie>[cap];
}

HashTable::~HashTable(){
    delete table;
}

int HashTable::hashFunction(Movie in) {
    int key = 0;
    for (int i = 0; i < in.title.length(); i++) {
        char letter = in.title.at(i);
        key = (key * 31) + int(letter);
    }
    key = key % cap;
    return key;
}

void HashTable::insert(Movie val) {
    int key = hashFunction(val);
    table[key].push_back(val);
}

/*
std::unordered_map<std::string, Movie> loadMovies(const std::string& filename) {
    std::locale::global(std::locale("C"));  // Ensure correct numeric formatting
    std::ifstream file(filename);
    std::string line, word;

    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << filename << std::endl;
        return movies;
    }

    std::getline(file, line);  // Skip the header line

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        Movie movie;
        std::string genreWord;

        std::getline(ss, word, ','); // Skip titleType
        std::getline(ss, word, ','); // Read primaryTitle
        std::string primaryTitle = word;
        std::getline(ss, movie.originalTitle, ',');
        std::getline(ss, word, ','); movie.startYear = safeStoi(word);
        std::getline(ss, word, ','); movie.runtimeMinutes = safeStoi(word);
        std::getline(ss, genreWord, ',');
        std::getline(ss, word, ','); movie.averageRating = safeStof(word);

        // Parse genres
        std::stringstream genreStream(genreWord);
        while (std::getline(genreStream, word, '|')) {
            movie.genres.push_back(word);
        }

        movies[primaryTitle] = movie;  // Use primary title as key
    }

    file.close();
    return movies;

}*/

int main() {
    std::string filename = "Project3DatabaseMOVIESONLY.csv";  // Adjust the path as necessary
    auto movies = loadMovies(filename);

    int year, maxRuntime;
    float minRating;
    std::string genre;

    std::cout << "Enter release year: ";
    std::cin >> year;
    std::cout << "Enter genre: ";
    std::cin >> genre;
    std::cout << "Enter maximum runtime (minutes): ";
    std::cin >> maxRuntime;
    std::cout << "Enter minimum rating: ";
    std::cin >> minRating;

    // Filtering and displaying movies
    bool found = false;
    for (const auto& pair : movies) {
        const Movie& movie = pair.second;
        if (movie.startYear == year &&
            std::find(movie.genres.begin(), movie.genres.end(), genre) != movie.genres.end() &&
            movie.runtimeMinutes <= maxRuntime &&
            movie.averageRating >= minRating) {
            std::cout << "Movie: " << pair.first << " - " << movie.originalTitle << "\n";
            found = true;
        }
    }

    if (!found) {
        std::cout << "No movies found matching criteria." << std::endl;
    }

    return 0;
}
