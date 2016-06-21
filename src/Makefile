CC=g++
LIBS=-g -lm -Wall -Wextra -lboost_iostreams -lboost_system -lboost_filesystem
CPP11=-std=c++11
PARAMS=-g -lm -c -Wall -std=c++11 -lboost_iostreams -lboost_system -lboost_filesystem

all: simullate

simullate: searchs.o main.o
	$(CC) main.o searchs.o -o simullate $(LIBS)

main.o: main.cpp
	$(CC) $(PARAMS) main.cpp

searchs.o: searchs.cpp
	$(CC) $(PARAMS) searchs.cpp

clean:
	rm *~ *.o caxeiro; clear;

god:
	make clean; make; ./simullate	