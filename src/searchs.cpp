/*
 * searchs.cpp
 *
 *  Created on: 6 de out de 2015
 *      Author: dekonunes
 */

#include "searchs.hpp"
vector<vector<float> > *matrizDistances;

void buscaAnnealing(int geracoes, int numCidades) {
	vector<int> cidades;
	float caminho = 0.0, novo = 0.0;
	for(int i=1; i <= numCidades; i++)
		cidades.push_back(i);

	ofstream myfile; myfile.open("saida.csv");

	std::random_shuffle( cidades.begin(), cidades.end() );
	double temperatura = 700;
	double decaimento = temperatura/geracoes;
	for(int i=0; i < geracoes; i++) {
		caminho = calculaValorCaminho(cidades, numCidades);
		int x1 = 0, x2 = 0;
		while(x1 == x2){
			x1 = rand()%(numCidades-1);
			x2 = rand()%(numCidades-1);
		}
		swap(cidades[x1],cidades[x2]);
		novo = calculaValorCaminho(cidades, numCidades);
		if(novo > caminho) {
			float delta = novo-caminho;
			double aux = fRand(0,1);
			if(aux > 1/exp(delta/temperatura)) {
				swap(cidades[x1],cidades[x2]);
			}
			myfile << 1/exp(delta/temperatura) << "\n";
		}
		temperatura = temperatura - decaimento;
	}
	myfile.close();
	cout << "caminho: ";
	for(int i = 0; i< numCidades; i++)
		cout << cidades[i] << " ";
	cout << endl;
	cout << "Custo do Caminho Final:  " << caminho << endl;
}

double distanciaEuclid(int x, int y, int xFinal, int yFinal) {
	return sqrt(pow(x - xFinal, 2) + pow(y - yFinal, 2));
}

double fRand(double fMin, double fMax){
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}

float calculaValorCaminho(vector<int> cidades, int numCidades) {
	float result = 0.0;
	for(int i=0; i < numCidades; i++) {
		if(i!=numCidades-1)
			result += matrizDistances->at(cidades[i]-1).at(cidades[i+1]-1);
		else
			result += matrizDistances->at(cidades[i]-1).at(cidades[0]-1);
	}
	return result;
}


