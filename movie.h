#ifndef MOVIE_H
#define MOVIE_H
#pragma once

#endif // MOVIE_H

#include <string>
#include <vector>

using namespace std;

//this entire file just exists so that the RB tree and hash map can use the same struct
struct Movie {
    string title;
    int year;
    int runtime;
    vector<string> genre;
    double rating;
};
