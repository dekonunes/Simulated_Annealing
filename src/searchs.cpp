/*
 * searchs.cpp
 *
 *  Created on: 6 de out de 2015
 *      Author: dekonunes
 */
#include "searchs.hpp"

void buscaAnnealing(int geracoes) {
	vector<double> individuo;
	vector<double> vectorPlot;
	double fitness = 0.0, fitnessNovo = 0.0;

	for (int i = 0; i < QUANTIDADEGENES; i++)
		individuo.push_back(fRand(-4, 4));

	double temperatura = 200;
	double decaimento = temperatura / geracoes;
	double delta;
	for (int i = 0; i < geracoes; i++) {
		fitness = ackley(individuo);
		cout << fitness << endl;
		perturbacao(&individuo);
		fitnessNovo = ackley(individuo);
		if (fitnessNovo < fitness) {
			delta = fitnessNovo - fitness;
			if (fRand(0, 1) > exp(-delta / temperatura)) {
				perturbacao(&individuo);
				//vectorPlot.push_back(exp(-delta / temperatura));
				vectorPlot.push_back(fitness);
			}
		}
		temperatura -= decaimento;
	}
	plot(vectorPlot, "Valores");
	//printa resultado
}

void perturbacao(vector<double> *individuo) {
	static mt19937 mt(time(NULL));
	static uniform_int_distribution<int> bit(0,
	QUANTIDADEGENES - 1);
	int numRandom = bit(mt);
	individuo->at(numRandom) = individuo->at(numRandom)
			+ mutacao(individuo->at(numRandom));
}

double mutacao(double gene) {
	static mt19937 mt(time(NULL));
	double delta = gene / 10;
	static uniform_real_distribution<double> numDelta(-delta, delta);
	return numDelta(mt);
}

double fRand(double fMin, double fMax) {
	static mt19937 mt(time(NULL));
	static uniform_real_distribution<double> bit(fMin, fMax);
	return bit(mt);
}

double rastrigin(vector<double> individuo) {
	double resultado = 0;
	for (int var = 0; var < QUANTIDADEGENES - 1; ++var)
		resultado += (pow(individuo[var], (double) 2)
				- 10 * cos(2 * M_PI * individuo[var]) + 10);
	return resultado;
}

double ackley(vector<double> individuo) {
	double aux = 0, aux1 = 0;
	for (int var = 0; var < QUANTIDADEGENES - 1; ++var) {
		aux += individuo[var] * individuo[var];
		aux1 += cos(2.0 * M_PI * individuo[var]);
	}
	return (-20.0 * (exp(-0.2 * sqrt(1.0 / (double) QUANTIDADEGENES * aux)))
			- exp(1.0 / (double) QUANTIDADEGENES * aux1) + 20.0 + exp(1));
}

void plot(vector<double> vectorPlot, string titulo) {
	Gnuplot gp;
	gp << "plot" << gp.file1d(vectorPlot) << "with lines title '" << titulo
			<< "'" << endl;

}

