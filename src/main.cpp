//============================================================================
// Name        : Simulated_Annealing.cpp
// Author      : Deko
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "main.hpp"

//kroA100 : 21282
//eil51 : 426

int main(int argc, char **argv) {
	cout << "Caxeiro viajante" << endl; // prints !!!Hello World!!!
	int numCidades = 0;
	vector<vector<int> > matriz;
	vector<vector<float> > matrizDistances;
	criaMatrixDistancias(argv[1],&matriz,&matrizDistances,&numCidades);
	buscaAnnealing(500000, numCidades, &matrizDistances);
	return 0;
}
