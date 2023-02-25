/*
 * Name Surname: Kerem Tekik
 *
 * Section : CS 201-2
 *
 * ID: 22002730
 *
 */

#include "Movie.h"


Movie::Movie(int mID, int count){
    movieId = mID;
    copies = count;
}

Movie::~Movie() {

}

int Movie::getID(){
    return movieId;
}

int Movie::getCopies(){
    return copies;
}

bool Movie::operator =(const Movie& rhs){
    if(this->movieId == rhs.movieId) return true;
    return false;
}

bool Movie::operator <(const Movie& rhs){
    if(this->movieId < rhs.movieId) return true;
    return false;
}