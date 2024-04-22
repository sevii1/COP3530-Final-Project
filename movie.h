#ifndef MOVIE_H
#define MOVIE_H
#pragma once

#endif // MOVIE_H

#include <string>
#include <vector>

using namespace std;

struct Movie {
    string title;
    int year;
    int runtime;
    vector<string> genre;
    double rating;
};
