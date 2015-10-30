PARAMS=-g -lm -c -Wall -std=c++11

all: caxeiro

caxeiro: searchs.o ParserCSV.o main.o node.o map.o
	g++ main.o searchs.o ParserCSV.o node.o map.o -o caxeiro

main.o: main.cpp
	g++ $(PARAMS) main.cpp

map.o: map.cpp
	g++ $(PARAMS) map.cpp

searchs.o: searchs.cpp
	g++ $(PARAMS) searchs.cpp

ParserCSV.o: ParserCSV.cpp
	g++ $(PARAMS) ParserCSV.cpp

node.o: node.cpp
	g++ $(PARAMS) node.cpp

clean:
	rm *~ *.o caxeiro; clear;

god:
	make clean; make; ./caxeiro eil51.tsp

plot:
	gnuplot -e "file='saida.csv'" plot.plg