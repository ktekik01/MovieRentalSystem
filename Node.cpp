/*
 * Name Surname: Kerem Tekik
 *
 * Section : CS 201-2
 *
 * ID: 22002730
 *
 */

#include "Node.h"
#include <cstddef>

MovieNode::MovieNode() {
    value = NULL;
    next = NULL;
}
MovieNode::MovieNode(const Movie* mov) {
    next = NULL;
    value = (Movie*)mov;
}
MovieNode::MovieNode(const Movie* mov, MovieNode* nextNodePtr) {
    next = nextNodePtr;
    value = (Movie*)mov;
}
MovieNode::~MovieNode() {
    delete this->value;
}

void MovieNode::setMovie(const Movie* mov) {
    value = (Movie*)mov;
}
void MovieNode::setNextNode(MovieNode* nextMov) {
    //Note: Does not free next node.
    next = nextMov;
}
Movie* MovieNode::getItem() const {
    return value;
}
MovieNode* MovieNode::getNext() const {
    return next;
}

SubscriberNode::SubscriberNode() {
    value = NULL;
    next = NULL;
}
SubscriberNode::SubscriberNode(const Subscriber* sub) {
    next = NULL;
    value = (Subscriber*)sub;
}
SubscriberNode::SubscriberNode(const Subscriber* sub, SubscriberNode* nextNodePtr) {
    next = nextNodePtr;
    value = (Subscriber*)sub;
}

SubscriberNode::~SubscriberNode() {
    delete this->value;
}
void SubscriberNode::setSubscriber(const Subscriber* sub) {
    value = (Subscriber*)sub;
}
void SubscriberNode::setNextNode(SubscriberNode* nextSub) {
    //Note: Does not free next node.
    next = nextSub;
}
Subscriber* SubscriberNode::getItem() const {
    return value;
}
SubscriberNode* SubscriberNode::getNext() const {
    return next;
}


TransactionNode::TransactionNode(){
    value = NULL;
    next = NULL;
}
TransactionNode::TransactionNode(const Transaction* sub){
    next = NULL;
    value = (Transaction*) sub;
}
TransactionNode::TransactionNode(const Transaction* sub, TransactionNode* nextNodePtr){
    next = nextNodePtr;
    value = (Transaction*)sub;
}
TransactionNode::~TransactionNode() {
    if(this->value != NULL)
    delete this->value;
}
void TransactionNode::setTransaction(const Transaction* sub){
    value = (Transaction*)sub;
}
void TransactionNode::setNextNode(TransactionNode* nextSub) {
    //Note: Does not free next node.
    next = nextSub;
}
Transaction* TransactionNode::getItem() const{
    return value;
}
TransactionNode* TransactionNode::getNext() const {
    return next;
}
