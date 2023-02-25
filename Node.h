/*
 * Name Surname: Kerem Tekik
 *
 * Section : CS 201-2
 *
 * ID: 22002730
 *
 */


#ifndef MOVIERENTALSYSTEM_NODE_H
#define MOVIERENTALSYSTEM_NODE_H

class Movie;
class Subscriber;
class Transaction;
#include "Movie.h"
#include "Subscriber.h"
#include "Transaction.h"



class MovieNode{
private:
    Movie* value;
    MovieNode* next;
public:
    MovieNode();
    ~MovieNode();
    MovieNode(const Movie* mov);
    MovieNode(const Movie* mov, MovieNode* nextNodePtr);
    void setMovie(const Movie* mov);
    void setNextNode(MovieNode* nextMov);
    Movie* getItem() const;
    MovieNode* getNext() const;
};

class SubscriberNode{
private:
    Subscriber* value;
    SubscriberNode* next;
public:
    SubscriberNode();
    ~SubscriberNode();
    SubscriberNode(const Subscriber* sub);
    SubscriberNode(const Subscriber* sub, SubscriberNode* nextNodePtr);
    void setSubscriber(const Subscriber* sub);
    void setNextNode(SubscriberNode* nextSub);
    Subscriber* getItem() const;
    SubscriberNode* getNext() const;
};


class TransactionNode{
private:
    Transaction* value;
    TransactionNode* next;
public:
    TransactionNode();
    ~TransactionNode();
    TransactionNode(const Transaction* sub);
    TransactionNode(const Transaction* sub, TransactionNode* nextNodePtr);
    void setTransaction(const Transaction* sub);
    void setNextNode(TransactionNode* nextSub);
    Transaction* getItem() const;
    TransactionNode* getNext() const;

};



#endif //MOVIERENTALSYSTEM_NODE_H
