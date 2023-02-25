/*
 * Name Surname: Kerem Tekik
 *
 * Section : CS 201-2
 *
 * ID: 22002730
 *
 */

#include "MovieRentalSystem.h"
#include "string"
#include "iostream"

MovieRentalSystem::MovieRentalSystem( const string movieInfoFileName,
                   const string subscriberInfoFileName ) {


    int movID, copies;
    int movieNumber;
    ifstream moviesFile;
    moviesFile.open( movieInfoFileName.c_str(), ios_base::in );
    /*
    if(!moviesFile.is_open()){
        cout<<"Input file "<<movieInfoFileName<<" does not exist"<<endl;
        return;
    }
     */
    int subID;
    int subNumber;
    ifstream subscribersFile;
    subscribersFile.open(subscriberInfoFileName.c_str(), ios_base::in);
    /*
    if(!subscribersFile.is_open()){
        cout<<"Input file "<<subscriberInfoFileName<<" does not exist"<<endl;
        return;
    }
     */

    if(!moviesFile.is_open() && subscribersFile.is_open()){
        cout<<"Input file "<<movieInfoFileName<<" does not exist"<<endl;
        return;
    }
    if(moviesFile.is_open() && !subscribersFile.is_open()){
        cout<<"Input file "<<subscriberInfoFileName<<" does not exist"<<endl;
        return;
    }
    if(!moviesFile.is_open() && !subscribersFile.is_open()){
        cout<<"Input file "<<movieInfoFileName<<" does not exist"<<endl;
        cout<<"Input file "<<subscriberInfoFileName<<" does not exist"<<endl;
        return;
    }

    moviesFile >> movieNumber;
    while ( moviesFile.eof() == false ) {

        moviesFile >> movID;
        moviesFile >> copies;
        if(moviesHead == NULL) {
            moviesHead = new MovieNode(new Movie(movID, copies));
        }
        else {
            bool flag = false;
            MovieNode* nde = moviesHead;
            Movie* mov = new Movie(movID, copies);
            while(nde != NULL ) {
                if(nde->getItem()->getID() == movID){
                    flag = true;
                    break;
                }
                nde = nde->getNext();
            }
            if(flag){
                delete mov;
                continue;
            }
            MovieNode* mn = new MovieNode(mov);
            mn->setNextNode(moviesHead);
            moviesHead = mn;
        }

    }
    moviesFile.close();



    subscribersFile >> subNumber;
    while ( subscribersFile.eof() == false ) {

        subscribersFile >> subID;
        if(subscribersHead == NULL) {
            subscribersHead = new SubscriberNode(new Subscriber(subID));
        }
        else {
            bool flag = false;
            SubscriberNode* nde = subscribersHead;
            Subscriber* sub = new Subscriber(subID);
            while(nde != NULL) {
                if(nde->getItem()->getID() == subID) {
                    flag = true;
                    break;
                }
                nde = nde->getNext();
            }
            if(flag){
                delete sub;
                continue;
            }
            SubscriberNode* sn = new SubscriberNode(sub);
            sn->setNextNode(subscribersHead);
            subscribersHead = sn;
        }

    }
    subscribersFile.close();

    cout<<subNumber<<" subscribers and "<<movieNumber<<" movies have been loaded"<<endl;

    sortMovies();
    sortSubscribers();
}
MovieRentalSystem::~MovieRentalSystem() {
    //TODO: Free movies list
    MovieNode* mn = moviesHead;
    MovieNode* mnn = NULL;
    SubscriberNode* sn = subscribersHead;
    SubscriberNode* snn = NULL;
    TransactionNode* tr = transactionsHead;
    TransactionNode* trn = NULL;
    //TODO: Free subscribers list
    while(mn != NULL){
        mnn = mn;
        mn = mn->getNext();
        delete mnn;
    }
    while(sn != NULL){
        snn = sn;
        sn = sn->getNext();
        delete snn;
    }
}
void MovieRentalSystem::removeMovie( const int movieId ) {
    MovieNode* mn = moviesHead;
    MovieNode* mnn= NULL;

    while(mn->getItem()->getID() != movieId) {
        if(mn->getNext() == NULL) {
            cout<<"Movie "<<movieId<<" does not exist"<<endl;
            return;
        }
        mnn = mn;
        mn = mn->getNext();
    }
    SubscriberNode* sn = subscribersHead;
    while(sn != NULL){
        TransactionNode* tr = sn->getItem()->getTransactionList();
        if(tr == NULL){

        }
        else{
            while(tr != NULL){
                if((tr->getItem()->getMovieID() == movieId) && !(tr->getItem()->returned())) {
                    cout<<"Movie "<<movieId<<" cannot be removed -- at least one copy has not been returned"<<endl;
                    return;
                }
                tr = tr->getNext();
            }
        }
        sn = sn->getNext();
    }
    if(mnn == NULL){
        moviesHead = moviesHead->getNext();
        delete mn;
    }
    else{
        mnn->setNextNode(mn->getNext());
        delete mn;
    }

    cout<<"Movie "<<movieId<<" has been removed"<<endl;
}

void MovieRentalSystem::addMovie( const int movieId, const int numCopies ) {
    MovieNode* mn = moviesHead;
    MovieNode* mnn= NULL;

    if(mn == NULL) {
        moviesHead = new MovieNode(new Movie(movieId, numCopies));
        cout<<"Movie "<<movieId<<" has been added"<<endl;
        return;
    }

    while(mn != NULL) {
        if(mn->getItem()->getID() == movieId) {
            cout<<"Movie "<<movieId<<" already exists"<<endl;
            return;
        }
        mn = mn->getNext();
    }

    mn = moviesHead;
    Movie* mov = new Movie(movieId, numCopies);
    while(mn->getNext() != NULL) {
        mn = mn->getNext();
    }
    mnn = new MovieNode(mov);
    mnn->setNextNode(mn->getNext());
    mn->setNextNode(mnn);
    cout<<"Movie "<<movieId<<" has been added"<<endl;
    sortMovies();
}
void MovieRentalSystem::removeSubscriber( const int subscriberId ) {
    //TODO: Check if exists
    SubscriberNode* sn = subscribersHead;
    SubscriberNode* snn = NULL;
    TransactionNode* tr = sn->getItem()->getTransactionList();
    TransactionNode* trn = NULL;

    while(sn->getItem()->getID() != subscriberId){
        if(sn->getNext() == NULL){
            cout<<"Subscriber "<<subscriberId<<" does not exist"<<endl;
            return;
        }
        snn =sn;
        sn = sn->getNext();
    }
    //TODO: Check if has a movie rented

    tr = sn->getItem()->getTransactionList(); //asdasdasdasdasdasdasdasdas
    //asdasdasdasdasdasdasdasdsad
    while(tr != NULL && tr->getItem()->getSubscriberID() == subscriberId) {
        if (!(tr->getItem()->returned())) {
            cout<<"Subscriber "<<subscriberId<<" cannot be removed -- at least one movie has not been returned"<<endl;
            return;
        }
        trn = tr;
        tr = tr->getNext();
    }
    tr = sn->getItem()->getTransactionList();
    TransactionNode* foo;

    while(sn->getItem()->getID() != subscriberId){
        if(sn->getNext() == NULL){
            break;
        }
        snn = sn;
        sn = sn->getNext();
    }

    if(snn == NULL){
        subscribersHead = subscribersHead->getNext();
        delete sn;
    }
    else{
        snn->setNextNode(sn->getNext());
        delete sn;
    }

    cout<<"Subscriber "<<subscriberId<<" has been removed"<<endl;

    //TODO: Remove transactions
    //TODO: Remove subscriber

}
void MovieRentalSystem::rentMovie( const int subscriberId, const int movieId ) {
    //TODO: Check if movie exists
    MovieNode* mn = moviesHead;
    MovieNode* mnn= NULL;
    bool movieCheck = true;
    bool subsCheck = true;

    while(mn != NULL && mn->getItem()->getID() != movieId) {
        if(mn->getNext() == NULL) {
            movieCheck = false;
        }
        mnn = mn;
        mn = mn->getNext();
    }

    //TODO: Check subscriber exists

    SubscriberNode* sn = subscribersHead;
    SubscriberNode* snn = NULL;

    while(sn!= NULL && sn->getItem()->getID() != subscriberId){
        if(sn->getNext() == NULL){
            subsCheck = false;
        }
        snn =sn;
        sn = sn->getNext();
    }

    if(!subsCheck && movieCheck){
        cout<<"Subscriber "<<subscriberId<<" does not exist"<<endl;
        return;
    }
    if(subsCheck && !movieCheck){
        cout<<"Movie "<<movieId<<" does not exist"<<endl;
        return;
    }
    if(!subsCheck && !movieCheck){
        cout<<"Subscriber "<<subscriberId<<" and movie "<<movieId<<" do not exist"<<endl;
        return;
    }

    //TODO: Check if free copy exists
    mn = moviesHead;
    mnn = NULL;
    sn = subscribersHead;
    snn = NULL;
    TransactionNode* tr = sn->getItem()->getTransactionList();

    int copiesOccupied = 0;
    int availableCopies = 0;

    while(sn != NULL){
        if(sn->getItem()->getID() == subscriberId){
            break;
        }
        sn = sn->getNext();
    }

    snn = subscribersHead;
    while(snn != NULL){
        tr = snn->getItem()->getTransactionList();
        while(tr != NULL){
            if( tr->getItem()->getMovieID() == movieId && !(tr->getItem()->returned())){
                copiesOccupied++;
            }
            tr = tr->getNext();
        }
        snn = snn->getNext();
    }


    while(mn != NULL){
        if(mn->getItem()->getID() == movieId){
            availableCopies = mn->getItem()->getCopies() - copiesOccupied;
            break;
        }

        mn = mn->getNext();
    }


    if(availableCopies > 0) {
       sn->getItem()->rentMovie(movieId);
        cout<<"Movie "<<movieId<<" has been rented by subscriber "<<subscriberId<<""<<endl;
    }
    else{
        cout<<"Movie "<<movieId<<" has no available copy for renting"<<endl;
    }

}
void MovieRentalSystem::returnMovie( const int subscriberId, const int movieId ) {
    //TODO: Look for transaction list to check if valid
    SubscriberNode* sn = subscribersHead;
    SubscriberNode* snn = NULL;
    MovieNode* mn = moviesHead;
    bool flagForSub = false;
    bool flagForMov = false;

    while(sn != NULL){
        if(sn->getItem()->getID() == subscriberId){
            flagForSub = true;
            break;
        }
        sn = sn->getNext();
    }

    while(mn != NULL){
        if(mn->getItem()->getID() == movieId){
            flagForMov = true;
            break;
        }
        mn = mn->getNext();
    }

    if(!flagForSub && flagForMov){
        cout<<"Subscriber "<<subscriberId<<" does not exist"<<endl;
        return;
    }
    if(flagForSub && !flagForMov){
        cout<<"Movie "<<movieId<<" does not exist"<<endl;
        return;
    }
    if(!flagForSub && !flagForMov){
        cout<<"Subscriber "<<subscriberId<<" and movie "<<movieId<<" do not exist"<<endl;
        return;
    }
    TransactionNode* tr = sn->getItem()->getTransactionList();
    TransactionNode* trn = NULL;
    bool notReturned = false;
    bool traBetween = false;
        if(sn->getItem()->getID() == subscriberId){
            tr = sn->getItem()->getTransactionList();
            while(tr != NULL){
                if(tr->getItem()->getMovieID() == movieId){
                    traBetween = true;
                    if(!tr->getItem()->returned()){
                        notReturned = true;
                        break;
                    }
                }
                tr = tr->getNext();
            }
        }

    if(traBetween == false){
        cout<<"No rental transaction for subscriber "<<subscriberId<<" and movie "<<movieId<<endl;
        return;
    }

    if(!notReturned){
        cout<<"No rental transaction for subscriber "<<subscriberId<<" and movie "<<movieId<<endl;
        return;
    }
    else{
        tr->getItem()->setReturned();
        sn->getItem()->sortTransactions(); // 2131eefdstrgxfdhdxfghfhgfdgşfdgfgmdlşgfgdflg
        cout<<"Movie "<<movieId<<" has been returned by subscriber "<<subscriberId<<endl;
    }
    /*
    while(tr != NULL){
        if((tr->getItem()->getSubscriberID() == subscriberId) && (tr->getItem()->getMovieID() == movieId)){
            if(!tr->getItem()->returned()){
                notReturned = true;
                break;
            }
            else{
                trn = tr;
            }
        }
        tr = tr->getNext();
    }
    if(tr == NULL ){
        //        //error message
        return;
    }
    else if(!notReturned){
        // Error message
        return;
    }

    tr->getItem()->setReturned();
    //DONE MESSAGE
    */

    //TODO: Check if the movie is already returned
    //TODO: If valid, free a copy of the movie
}
void MovieRentalSystem::showMoviesRentedBy( const int subscriberId ) const {
    //TODO: Check if subscriber is valid

    SubscriberNode* sn = subscribersHead;
    TransactionNode* tr;

    while(sn != NULL){
        if(sn->getItem()->getID() == subscriberId){
            break;
        }
        if(sn->getNext() == NULL){
            cout<<"Subscriber "<<subscriberId<<" does not exist"<<endl;
            return;
        }
        sn = sn->getNext();
    }
    tr = sn->getItem()->getTransactionList();
    if(tr == NULL){
        cout<<"Subscriber "<<subscriberId<<" has not rented any movies"<<endl;
        return;
    }
    cout<<"Subscriber "<<subscriberId<<" has rented the following movies:"<<endl;
    while(tr != NULL){
        cout<<tr->getItem()->getMovieID();
        if(tr->getItem()->returned()){
            cout<<" returned"<<endl;
        }
        else{
            cout<<" not returned"<<endl;
        }
        tr = tr->getNext();
        //if(tr == NULL) break;
        //if(tr->getNext() == NULL) break;
    }


    //TODO: If none, a warning message should appear
    //TODO: Display all, rented or returned
}
void MovieRentalSystem::showSubscribersWhoRentedMovie( const int movieId ) const {
    //TODO: If the movie does not exist, warn
    MovieNode* mn = moviesHead;
    TransactionNode* tr = transactionsHead;

    while(mn != NULL){
        if(mn->getNext() == NULL){
            cout<<"Movie "<<movieId<<" does not exist"<<endl;
            return;
        }
        if(mn->getItem()->getID() == movieId){
            break;
        }
        mn = mn->getNext();
    }

    SubscriberNode* sn = subscribersHead;
    if(sn != NULL){
        tr = sn->getItem()->getTransactionList();
    }
    bool check = false;
    bool flag = false;

    while(sn != NULL){
        tr = sn->getItem()->getTransactionList();
        while(tr != NULL){
            if(tr->getItem()->getMovieID() == movieId){
                check = true;
                if(!flag){
                    cout<<"Movie "<<movieId<<" has been rented by the following subscribers:"<<endl;
                    flag = true;
                }
                cout<<sn->getItem()->getID();
                if(tr->getItem()->returned()){
                    cout<<" returned"<<endl;
                }
                else{
                    cout<<" not returned"<<endl;
                }
            }
            tr = tr->getNext();
        }
        sn = sn->getNext();
    }

    if(!check){
        cout<<"Movie "<<movieId<<" has not been rented by any subscriber"<<endl;
    }
    //TODO: If no one rented, warn
    //TODO: This list includes, for each subscriber, the subscriber id and whether the movie was returned or not
}
void MovieRentalSystem::showAllMovies() const {
    //TODO: the movie id and the number of copies
    MovieNode* mn = moviesHead;
    cout<<"Movies in the movie rental system:"<<endl;
    while(mn != NULL){
        //display
        cout<<mn->getItem()->getID()<<" "<<mn->getItem()->getCopies()<<endl;
        mn = mn->getNext();
    }
}
void MovieRentalSystem::showAllSubscribers() const {
    //TODO: only includes the subscriber id for these subscribers.

    SubscriberNode* sn = subscribersHead;
    cout<<"Subscribers in the movie rental system:"<<endl;
    while (sn != NULL){
        //display
        cout<<sn->getItem()->getID()<<endl;
        sn = sn->getNext();
    }
}

void MovieRentalSystem::sortMovies() {
    MovieNode* currentNode = moviesHead;
    MovieNode* indexNode = NULL;
    Movie* temp = NULL;

    if(moviesHead == NULL)return;
    else{
        while(currentNode != NULL){
            indexNode = currentNode->getNext();

            while(indexNode != NULL){
                if(currentNode->getItem()->getID() > indexNode->getItem()->getID()){
                    temp = currentNode->getItem();
                    currentNode->setMovie(indexNode->getItem());
                    indexNode->setMovie(temp);
                }
                indexNode = indexNode->getNext();
            }
            currentNode = currentNode->getNext();
        }
    }
}

void MovieRentalSystem::sortSubscribers() {
    SubscriberNode* currentNode = subscribersHead;
    SubscriberNode* indexNode = NULL;
    Subscriber* temp = NULL;

    if(subscribersHead == NULL)return;
    else{
        while(currentNode != NULL){
            indexNode = currentNode->getNext();

            while(indexNode != NULL){
                if(currentNode->getItem()->getID() > indexNode->getItem()->getID()){
                    temp = currentNode->getItem();
                    currentNode->setSubscriber(indexNode->getItem());
                    indexNode->setSubscriber(temp);
                }
                indexNode = indexNode->getNext();
            }
            currentNode = currentNode->getNext();
        }
    }
}
