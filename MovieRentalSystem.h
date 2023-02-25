/*
 * Name Surname: Kerem Tekik
 *
 * Section : CS 201-2
 *
 * ID: 22002730
 *
 */

#ifndef MOVIERENTALSYSTEM_MOVIERENTALSYSTEM_H
#define MOVIERENTALSYSTEM_MOVIERENTALSYSTEM_H

using namespace std;
#include <string>
#include <fstream>
#include <cstdlib>
#include "Node.h"

class MovieRentalSystem {
    MovieNode* moviesHead = NULL;
    SubscriberNode* subscribersHead = NULL;
    TransactionNode* transactionsHead = NULL;
public:
    MovieRentalSystem( const string movieInfoFileName,
                       const string subscriberInfoFileName );
    ~MovieRentalSystem();
    void removeMovie( const int movieId );
    void addMovie( const int movieId, const int numCopies );
    void removeSubscriber( const int subscriberId );
    void rentMovie( const int subscriberId, const int movieId );
    void returnMovie( const int subscriberId, const int movieId );
    void showMoviesRentedBy( const int subscriberId ) const;
    void showSubscribersWhoRentedMovie( const int movieId ) const;
    void showAllMovies() const;
    void showAllSubscribers() const;
    void sortMovies();
    void sortSubscribers();
};

#endif //MOVIERENTALSYSTEM_MOVIERENTALSYSTEM_H
