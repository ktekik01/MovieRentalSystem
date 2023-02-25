/*
 * Name Surname: Kerem Tekik
 *
 * Section : CS 201-2
 *
 * ID: 22002730
 *
 */

#include "Subscriber.h"
#include "cstddef"

Subscriber::Subscriber(int sID) {
    subId = sID;
    myList = NULL;
}

Subscriber::~Subscriber() {
    TransactionNode* temp = this->myList;
    TransactionNode* temp2 = NULL;
    while(temp != NULL){
        temp2 = temp;
        temp = temp->getNext();
        delete temp2;
    }
}
int Subscriber::getID(){
    return subId;
}

TransactionNode* Subscriber::getTransactionList() {
    return myList;
}
bool Subscriber::operator =(const Subscriber& rhs) {
    if(this->subId == rhs.subId) return true;
    return false;
}
bool Subscriber::operator <(const Subscriber& rhs) {
    if(this->subId < rhs.subId) return true;
    return false;
}

void Subscriber::sortTransactions() {
    TransactionNode* currentNode = this->myList;
    TransactionNode* indexNode = NULL;
    Transaction* temp = NULL;

    if(this->myList == NULL)return;
    else{
        while(currentNode != NULL){
            indexNode = currentNode->getNext();

            while(indexNode != NULL){
                if(currentNode->getItem()->getMovieID() > indexNode->getItem()->getMovieID()){
                    temp = currentNode->getItem();
                    currentNode->setTransaction(indexNode->getItem());
                    indexNode->setTransaction(temp);
                }
                indexNode = indexNode->getNext();
            }
            currentNode = currentNode->getNext();
        }
    }

    currentNode = this->myList;
    indexNode = NULL;
    temp = NULL;

    if(this->myList == NULL)return;
    else{
        while(currentNode != NULL){
            indexNode = currentNode->getNext();

            while(indexNode != NULL){
                if(currentNode->getItem()->getMovieID() == indexNode->getItem()->getMovieID()){
                    if((!(currentNode->getItem()->returned())) && indexNode->getItem()->returned()){
                        temp = currentNode->getItem();
                        currentNode->setTransaction(indexNode->getItem());
                        indexNode->setTransaction(temp);
                    }
                }
                indexNode = indexNode->getNext();
            }
            currentNode = currentNode->getNext();
        }
    }
}

void Subscriber::rentMovie(int movieID) {

    TransactionNode* tail = myList;
    if(tail == NULL) {
        myList = new TransactionNode(new Transaction(subId, movieID));
        return;
    }

    while(tail->getNext() != NULL) {
        tail = tail->getNext();
    }
    tail->setNextNode(new TransactionNode(new Transaction(subId, movieID)));

    sortTransactions();
}