CXX=        g++
CXXFLAGS=   -g -Wall -std=gnu++11
SHELL=      bash
all:        main 
main:   main.o College.o
    $(CXX) $(CXXFLAGS) main.o College.o -o main
main.o: main.cpp
    $(CXX) $(CXXFLAGS) -c main.cpp
CardDeck.o: College.cpp College.h
    $(CXX) $(CXXFLAGS) -c College.cpp
clean:
    rm -f *.o main
