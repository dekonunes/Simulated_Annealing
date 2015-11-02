/*
 * map.cpp
 *
 *  Created on: 30 de out de 2015
 *      Author: dekonunes
 */
#include "map.hpp"
#include "ParserCSV.hpp"

void criaMatrixDistancias(char* file, vector<vector<int> > *matriz,vector<vector<float> > *matrizDistances, int *numberOfCitys) {
	string f(file);
	CsvFile arquivo(file, ' ', 1);
	for (int i = 0; i < arquivo.lines; i++) {
		vector<int> row;
		for (int j = 0; j < arquivo.columns; j++) {
			row.push_back(atoi(arquivo.info[i][j].c_str()));
		}
		matriz->push_back(row);
	}
	*numberOfCitys = arquivo.lines;

	// cria matrix de distancias
	for (int i = 0; i < *numberOfCitys; i++) {
		vector<float> temp;
		for (int j = 0; j < *numberOfCitys; j++)
			temp.push_back(distance(matriz->at(i).at(1), matriz->at(i).at(2), matriz->at(j).at(1),	matriz->at(j).at(2)));
		matrizDistances->push_back(temp);
	}
}

float distance(int x1, int y1, int x2, int y2) {
	return sqrt(pow(x1-x2,2)+pow(y1-y2,2));
}

