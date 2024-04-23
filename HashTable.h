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
    //I feel like rehashing is pretty unnecessary here, I already know that it's a constant size
    //and that my function distributes things fairly evenly so I think rehashing would just worsen time complexity
    //Maybe I'm wrong though, who knows
};
