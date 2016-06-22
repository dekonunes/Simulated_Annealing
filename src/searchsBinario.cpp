/*
 * searchsBinario.cpp
 *
 *  Created on: 21 de jun de 2016
 *      Author: deko
 */

#include "searchsBinario.hpp"

void buscaAnnealingBinario(int geracoes) {
	string individuo = geraIndividuoBinario();
	vector<double> vectorPlot;
	double fitness = 0.0, fitnessNovo = 0.0;

	double temperatura = 2000000;
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

string geraIndividuoBinario() {
	static mt19937 mt(time(NULL));
	static uniform_int_distribution<int> bit(0, 1);
	string individuo;
	for (int var = 0; var < QUANTIDADEGENES; ++var)
		for (int i = 0; i < QUANTIDADEBITS; i++)
			individuo += static_cast<ostringstream*>(&(ostringstream()
					<< bit(mt)))->str();

	return individuo;
}

int deceptive(string bits) {
	int resultado = 0;
	for (int count = 0; count < 4; ++count)
		if (bits[count] == '1')
			resultado++;
	if (resultado == 0)
		resultado = 5;
	return resultado;
}

int fullyDeceptiveF3(string bits) {
	if (bits == "000") {
		return 28;
	}
	if (bits == "001") {
		return 26;
	}
	if (bits == "010") {
		return 22;
	}
	if (bits == "011") {
		return 0;
	}
	if (bits == "100") {
		return 14;
	}
	if (bits == "101") {
		return 0;
	}
	if (bits == "110") {
		return 0;
	}
	if (bits == "111") {
		return 30;
	}
	return 0;
}


