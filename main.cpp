#include <iostream>
#include "MovieRentalSystem.h"
#include <string>
#include "Node.h"

int main() {


    //TEST CASE 1
    /*
    MovieRentalSystem firstMRS( "my_movies.txt", "subscribers.txt" );
    cout << endl;

    MovieRentalSystem MRS( "movies.txt", "subscribers.txt" );
    cout << endl;

    MRS.showAllMovies();
    cout << endl;
    MRS.showAllSubscribers();
    cout << endl;

    MRS.removeMovie( 600 );
    MRS.removeMovie( 600 );
    MRS.removeMovie( 70 );
    cout << endl;

    MRS.addMovie( 99, 3 );
    cout << endl;
    MRS.showAllMovies();
    cout << endl;

    MRS.rentMovie( 1111, 10 );
    MRS.rentMovie( 1111, 20 );
    MRS.rentMovie( 7777, 10 );
    MRS.rentMovie( 6666, 10 );
    MRS.rentMovie( 7777, 80 );
    MRS.rentMovie( 6666, 100 );
    MRS.rentMovie( 4444, 40 );
    MRS.rentMovie( 4444, 50 );
    MRS.rentMovie( 1234, 30 );
    MRS.rentMovie( 1111, 33 );
    MRS.rentMovie( 1234, 33 );
    cout << endl;

    MRS.returnMovie( 7777, 80 );
    MRS.returnMovie( 6666, 100 );
    MRS.returnMovie( 1111, 20 );
    MRS.returnMovie( 4444, 10 );
    MRS.returnMovie( 1111, 20 );
    cout << endl;
    MRS.rentMovie( 3333, 80 );
    MRS.rentMovie( 8888, 100 );
    MRS.rentMovie( 1111, 100 );
    MRS.rentMovie( 1111, 100 );
    cout << endl;
    MRS.rentMovie( 1111, 20 );
    MRS.returnMovie( 1111, 20 );
    MRS.rentMovie( 1111, 20 );
    cout << endl;
    MRS.showMoviesRentedBy( 1111 );
    MRS.showMoviesRentedBy( 8888 );
    MRS.showMoviesRentedBy( 2222 );
    MRS.showMoviesRentedBy( 1234 );
    cout << endl;
    MRS.showSubscribersWhoRentedMovie( 10 );
    MRS.showSubscribersWhoRentedMovie( 100 );
    MRS.showSubscribersWhoRentedMovie( 30 );
    MRS.showSubscribersWhoRentedMovie( 70 );
    cout << endl;

    MRS.removeMovie( 100 );
    cout << endl;

    MRS.removeSubscriber( 1111 );
    cout << endl;

    MRS.removeSubscriber( 5555 );
    cout << endl;
    MRS.removeSubscriber( 6666 );
    cout << endl;
    MRS.showAllSubscribers();
    cout << endl;
    MRS.showAllMovies();
    cout << endl;
    */

    //TEST CASE 2
    /*
    MovieRentalSystem firstMRS( "movies.txt", "lol.txt" );
    MovieRentalSystem secondMRS( "xd.txt", "lol.txt" );
    MovieRentalSystem thirdMRS("xd.txt", "subscribers.txt");

    cout << endl;
    */
    // TEST CASE 3

    MovieRentalSystem MRS("movies.txt", "subscribers.txt");
    MRS.showAllMovies();
    MRS.showAllSubscribers();


    MRS.rentMovie(1111,40);
    MRS.rentMovie(1111,40);
    MRS.returnMovie(1111,40);
    MRS.returnMovie(1111,40);
    MRS.showMoviesRentedBy(1111);

    MRS.rentMovie(2222, 60);
    MRS.rentMovie(3333, 60);
    MRS.rentMovie(2222, 60);
    MRS.returnMovie(2222, 60);
    cout<<endl;
    MRS.rentMovie(2222,50);
    MRS.rentMovie(2222,50);
    MRS.rentMovie(3333,50);
    MRS.rentMovie(3333,50);
    MRS.rentMovie(2222,50);
    MRS.rentMovie(3333,50);
    cout<<endl;
    MRS.showSubscribersWhoRentedMovie(50);
    cout<<endl;
    MRS.showSubscribersWhoRentedMovie(60);
    cout<<endl;
    MRS.showMoviesRentedBy(2222);
    cout<<endl;
    MRS.showMoviesRentedBy(3333);
    cout<<endl;

    MRS.removeMovie(60);

    MRS.removeSubscriber(3333);

    MRS.showAllMovies();
    MRS.showAllSubscribers();


    MRS.returnMovie(2222, 50);
    cout<<endl;
    MRS.returnMovie(3333, 50);
    cout<<endl;
    MRS.showMoviesRentedBy(2222);
    cout<<endl;
    MRS.showMoviesRentedBy(3333);
    cout<<endl;
    MRS.showSubscribersWhoRentedMovie(50);
    cout<<endl;
    MRS.showSubscribersWhoRentedMovie(60);
    cout<<endl;
    MRS.returnMovie(2222,50);
    MRS.showSubscribersWhoRentedMovie(50);
    cout<<endl;

    MRS.showMoviesRentedBy(2222);
    cout<<endl;
    MRS.removeSubscriber(2222);
    cout<<endl;
    MRS.showSubscribersWhoRentedMovie(50);
    cout<<endl;
    MRS.removeMovie(50);
    cout<<endl;

    MRS.showAllMovies();
    cout<<endl;
    MRS.showAllSubscribers();
    cout<<endl;


    MRS.removeMovie(10);
    MRS.removeMovie(20);
    MRS.removeMovie(30);
    MRS.removeMovie(40);
    MRS.removeMovie(50);
    MRS.removeMovie(60);
    MRS.removeMovie(70);
    MRS.removeMovie(80);
    MRS.removeMovie(90);
    MRS.removeMovie(100);
    MRS.removeMovie(200);
    MRS.removeMovie(300);
    MRS.removeMovie(400);
    MRS.removeMovie(500);
    MRS.removeMovie(600);

    MRS.returnMovie(2222, 50);
    MRS.returnMovie(3333, 50);
    MRS.returnMovie(3333, 50);

    MRS.removeMovie(50);

    MRS.returnMovie(2222, 60);
    MRS.returnMovie(3333, 60);

    MRS.removeMovie(60);

    MRS.showAllMovies();
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;

    MRS.removeSubscriber(1111);
    MRS.removeSubscriber(2222);
    MRS.removeSubscriber(3333);
    MRS.removeSubscriber(4444);
    MRS.removeSubscriber(5555);
    MRS.removeSubscriber(6666);
    MRS.removeSubscriber(7777);

    cout<<endl;
    MRS.showAllSubscribers();
    cout<<endl;
    MRS.addMovie(25, 5);
    MRS.addMovie(35,3);
    MRS.addMovie(45,1);
    cout<<endl;
    MRS.showAllMovies();
    cout<<endl;
    MRS.rentMovie(9999, 25);
    MRS.rentMovie(7777,25);
    MRS.rentMovie(9999,25);
    MRS.returnMovie(9999,25);
    MRS.rentMovie(9999,35);
    MRS.rentMovie(9999,35);
    MRS.returnMovie(9999,35);
    MRS.rentMovie(9999,45);
    MRS.returnMovie(9999,45);
    MRS.showMoviesRentedBy(9999);
    cout<<endl;
    MRS.rentMovie(8888,25);
    MRS.rentMovie(8888,25);
    MRS.returnMovie(8888,25);
    MRS.showSubscribersWhoRentedMovie(25);
    cout<<endl;
    MRS.removeMovie(25);
    MRS.removeMovie(35);
    MRS.removeMovie(45);
    MRS.removeSubscriber(8888);
    MRS.removeSubscriber(9999);
    cout<<endl;
    MRS.returnMovie(9999,25);
    MRS.returnMovie(8888,25);
    MRS.removeMovie(25);
    cout<<endl;
    MRS.returnMovie(9999,35);
    MRS.removeMovie(35);

    MRS.removeSubscriber(8888);
    MRS.removeSubscriber(9999);

    MRS.showAllMovies();
    MRS.showAllSubscribers();

    //TEST 1




    return 0;
}
