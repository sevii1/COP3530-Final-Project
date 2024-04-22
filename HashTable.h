#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <vector>
#include <string>
#include <list>


#endif // HASHTABLE_H

struct Movie {
    std::string title;
    int year;
    int runtime;
    std::vector<std::string> genre;
    double rating;
};

class HashTable {
private:
    int cap;
    std::list<Movie> *table;
public:
    HashTable();
    ~HashTable();
    int hashFunction(Movie key);
    void insert(Movie val);
};
