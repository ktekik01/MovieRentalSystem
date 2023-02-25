/*
 * Name Surname: Kerem Tekik
 *
 * Section : CS 201-2
 *
 * ID: 22002730
 *
 */


#ifndef MOVIERENTALSYSTEM_SUBSCRIBER_H
#define MOVIERENTALSYSTEM_SUBSCRIBER_H

#include "Node.h"
class TransactionNode;

class Subscriber{
    int subId;
    TransactionNode* myList;
public:
    Subscriber(int sID);
    ~Subscriber();
    int getID();
    TransactionNode* getTransactionList();
    bool operator =(const Subscriber& rhs);
    bool operator <(const Subscriber& rhs);
    void sortTransactions();
    void rentMovie(int movieID);
};

#endif //MOVIERENTALSYSTEM_SUBSCRIBER_H
