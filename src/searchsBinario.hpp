/*
 * searchsBinario.hpp
 *
 *  Created on: 21 de jun de 2016
 *      Author: deko
 */

#ifndef SEARCHSBINARIO_HPP_
#define SEARCHSBINARIO_HPP_

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
#define QUANTIDADEGENES 4
#define QUANTIDADEBITS 3

int fullyDeceptiveF3(string bits);
int deceptive(string bits);
void buscaAnnealingBinario(int geracoes);



#endif /* SEARCHSBINARIO_HPP_ */
