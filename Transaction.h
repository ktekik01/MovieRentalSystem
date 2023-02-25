/*
 * Name Surname: Kerem Tekik
 *
 * Section : CS 201-2
 *
 * ID: 22002730
 *
 */

#ifndef MOVIERENTALSYSTEM_TRANSACTION_H
#define MOVIERENTALSYSTEM_TRANSACTION_H


class Transaction {
    int subscriberID;
    int movieID;
    bool isReturned;
public:
    Transaction(int sub, int mov);
    ~Transaction();
    bool returned();
    int getSubscriberID();
    int getMovieID();
    void setReturned();
    bool operator =(const Transaction& rhs);
    bool operator <(const Transaction& rhs);
};

#endif //MOVIERENTALSYSTEM_TRANSACTION_H
