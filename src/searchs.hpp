/*
 * searchs.hpp
 *
 *  Created on: 6 de out de 2015
 *      Author: dekonunes
 */

#ifndef SRC_BLIND_PURSUIT_ROBOT_SEARCHS_HPP_
#define SRC_BLIND_PURSUIT_ROBOT_SEARCHS_HPP_

#include <vector>
#include <iostream>
#include <ctime>
#include <unistd.h>
#include <algorithm>
#include <iterator>
#include <cmath>
#include <string>
#include <random>
#include <fstream>
#include "gnuplot-iostream/gnuplot-iostream.h"
#define QUANTIDADEGENES 10
#define QUANTIDADEBITS 3

using namespace std;

double ackley(vector<double> );
double rastrigin(vector<double>);
void perturbacao(vector<double> *);
void buscaAnnealing(int);
void buscaAnnealingBinario(int);
string geraIndividuoBinario();
double mutacao(double);
float calculaValorCaminho(vector<int>, int, vector<vector<float> > *);
double fRand(double, double);
void plot(vector<double>, string);
double xQuadrado(vector<double> individuo);

#endif /* SRC_BLIND_PURSUIT_ROBOT_SEARCHS_HPP_ */
