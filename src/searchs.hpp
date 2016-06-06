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
#include "node.hpp"
#include "gnuplot-iostream/gnuplot-iostream.h"
using namespace std;

void buscaAnnealing(int,int, vector<vector<float> > *);
double distanciaEuclid(int, int, int, int);
float calculaValorCaminho(vector<int>, int, vector<vector<float> > *);
double fRand(double, double);
void plot(vector<double>, string);

#endif /* SRC_BLIND_PURSUIT_ROBOT_SEARCHS_HPP_ */
