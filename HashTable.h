#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <list>
#include "movie.h"

#pragma once

#endif // HASHTABLE_H

class HashTable {
private:
    int cap;
public:
    //I know making something like this a public member is a bad idea but whatever this project needs to get done
    std::list<Movie> *table;
    HashTable();
    ~HashTable();
    int hashFunction(Movie in);
    void insert(Movie val);
    void display();
    std::list<Movie> *getTable();
    int getCap();
};
