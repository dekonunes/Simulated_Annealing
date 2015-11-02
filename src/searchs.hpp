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
#include <random>
#include <fstream>
#include "node.hpp"
using namespace std;

void buscaAnnealing(int,int, vector<vector<float> > *);
double distanciaEuclid(int, int, int, int);
float calculaValorCaminho(vector<int>, int, vector<vector<float> > *);
double fRand(double, double);

#endif /* SRC_BLIND_PURSUIT_ROBOT_SEARCHS_HPP_ */
