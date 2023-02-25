/*
 * Name Surname: Kerem Tekik
 *
 * Section : CS 201-2
 *
 * ID: 22002730
 *
 */

#include "Transaction.h"

Transaction::Transaction(int sub, int mov) {
    isReturned = false;
    subscriberID = sub;
    movieID = mov;
}
Transaction::~Transaction() {

}
bool Transaction::returned() {
    return isReturned;
}
int Transaction::getSubscriberID() {
    return subscriberID;
}
int Transaction::getMovieID() {
    return movieID;
}
void Transaction::setReturned(){
    isReturned = true;
}

bool Transaction::operator<(const Transaction &rhs) {
    if(this->movieID < rhs.movieID) return true;
    return false;
}

bool Transaction::operator=(const Transaction &rhs) {
    if(this->movieID == rhs.movieID) return true;
    return false;
}

