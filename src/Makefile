CC=g++
LIBS=-g -lm -Wall -Wextra -lboost_iostreams -lboost_system -lboost_filesystem
CPP11=-std=c++11
PARAMS=-g -lm -c -Wall -std=c++11 -lboost_iostreams -lboost_system -lboost_filesystem

all: caxeiro

caxeiro: searchs.o ParserCSV.o main.o node.o map.o
	$(CC) main.o searchs.o ParserCSV.o node.o map.o -o caxeiro $(LIBS)

main.o: main.cpp
	$(CC) $(PARAMS) main.cpp

map.o: map.cpp
	$(CC) $(PARAMS) map.cpp

searchs.o: searchs.cpp
	$(CC) $(PARAMS) searchs.cpp

ParserCSV.o: ParserCSV.cpp
	$(CC) $(PARAMS) ParserCSV.cpp

node.o: node.cpp
	$(CC) $(PARAMS) node.cpp

clean:
	rm *~ *.o caxeiro; clear;

god:
	make clean; make; ./caxeiro eil51.tsp

plot:
	gnuplot -e "file='saida.csv'" 
	