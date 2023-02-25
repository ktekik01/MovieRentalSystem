cmake_minimum_required(VERSION 3.21)
project(MovieRentalSystem)

set(CMAKE_CXX_STANDARD 98)

add_executable(MovieRentalSystem main.cpp MovieRentalSystem.cpp MovieRentalSystem.h Transaction.cpp Transaction.h Node.cpp Node.h Movie.cpp Movie.h Subscriber.cpp Subscriber.h)
