/*
 * Name Surname: Kerem Tekik
 *
 * Section : CS 201-2
 *
 * ID: 22002730
 *
 */

#ifndef MOVIERENTALSYSTEM_MOVIE_H
#define MOVIERENTALSYSTEM_MOVIE_H

#include "Node.h"

class Movie{
    int movieId;
    int copies;
public:
    Movie(int mID, int count);
    ~Movie();
    int getID();
    int getCopies();
    bool operator =(const Movie& rhs);
    bool operator <(const Movie& rhs);
};

#endif //MOVIERENTALSYSTEM_MOVIE_H
