/*
 * searchs.cpp
 *
 *  Created on: 6 de out de 2015
 *      Author: dekonunes
 */
#include "searchs.hpp"
//https://github.com/AlgorithmsMeetup/SimulatedAnnealing
void buscaAnnealing(int geracoes) {
	vector<double> solution, new_solution, individuoAntigo;
	vector<double> vectorPlot;
	double delta, old_cost = 0.0, new_cost = 0.0, T = 100000, T_min = 0.00001, alpha = 0.9;

	for (int i = 0; i < QUANTIDADEGENES; i++)
		solution.push_back(fRand(-4, 4));

	old_cost = xQuadrado(solution);

	while (T > T_min) {
		for (int count = 0; count < 100; ++count) {
			new_solution = solution;
			perturbacao(&new_solution);
			new_cost = ackley(new_solution);
			delta = new_cost - old_cost;
			if (fRand(0, 1) < exp(-delta / T)) {
				solution = new_solution;
				old_cost = new_cost;
				//vectorPlot.push_back(xQuadrado(solution));
				vectorPlot.push_back(ackley(solution));
			}
		}
		T = T*alpha;
	}
	cout << "Quantidade de gerações: " << geracoes << endl;
	cout << "Quantidade de Dimensões: " << QUANTIDADEGENES << endl;
	cout << "Resultado: " << ackley(solution) << endl;
	plot(vectorPlot, "Valores");
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

double xQuadrado(vector<double> individuo) {
	double resultado = 0;
	for (int var = 0; var < QUANTIDADEGENES - 1; ++var)
		resultado += individuo[var] * individuo[var];
	return resultado;
}

double rastrigin(vector<double> individuo) {
	double resultado = 0;
	for (int var = 0; var < QUANTIDADEGENES; ++var)
		resultado += (pow(individuo[var], (double) 2)
				- 10 * cos(2 * M_PI * individuo[var]) + (10*QUANTIDADEGENES));
	return resultado;
}

double ackley(vector<double> individuo) {
	double aux = 0, aux1 = 0;
	for (int var = 0; var < QUANTIDADEGENES; ++var) {
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

