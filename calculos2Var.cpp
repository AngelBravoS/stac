/***************************************************************************
 *   Copyright (C) 2018 by Ángel Bravo Sáenz                               *
 *   angelbravosaenz@gmail.com                                             *
 *                                                                         *
 *   This file is part of Stac.                                            *
 *                                                                         *
 *   Stac is free software; you can redistribute it and/or modify          *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; version 2 of the License.               *
 *                                                                         *
 *   Stac is distributed in the hope that it will be useful,               *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with Stac; if not, write to the                                 *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#include <iostream>
#include <cmath>
#include "calculos2Var.hpp"
#include "funcMatematicasBasicas.hpp"

//Límite máximo en unsigned short int: 65535
//Límite máximo en unsigned int: 4.294.967.295
/*
Calculos2Var::Calculos2Var(bool archivo, unsigned int longitudFila, unsigned int longitudColumna) {
	desdeArchivo = archivo;
	filas = longitudFila;
	columnas = longitudColumna;
}

//-----Pide un exponente para poder hacer cosumatorias de cuadrados, cubos, etc, sin necesitar otro método
//-----recibe el exponente de cada variable así como su índice dentro de la matriz (0, 1, 2...)
//-----como las dos variables tienen la misma longitud (vector[0].length = vector[1].length) y solo hay que indicar
//-----una de ellas, se elige la primera.
double Calculos2Var::sumatoria2Var(int variableX, int variableY, int exponenteX, int exponenteY) {
	double sumatoria2Variables = 0;
	unsigned int n = columnas;
	for(unsigned int i = 0; i < n; i++) {
		sumatoria2Variables += pow(matriz[variableX][i], exponenteX) * pow(matriz[variableY][i], exponenteY);
	}
	return sumatoria2Variables;
}

double Calculos2Var::covarianza() {
	unsigned int n = columnas;
	double resultado = 0;
	resultado += (sumatoria2Var(0, 1, 1, 1));
	resultado = (resultado / n) - (mediaAritmetica(0) * mediaAritmetica(1));
	return resultado;
}

double Calculos2Var::rectaRegresion(int variable) {
	double resultado = 0;
	resultado = -1 * mediaAritmetica(variable) * coeficienteRegresion(variable);
	return resultado;
}

double Calculos2Var::curvaRegresion(int variable) {
	double resultado = 0;
	resultado = -1 * mediaAritmetica(variable) * coeficienteRegresion(variable);
	return resultado;
}

double Calculos2Var::coeficienteRegresion(int variable) {
	double resultado;
	resultado = covarianza() / varianza(variable);
	return resultado;
}

double Calculos2Var::coeficienteCorrelacion() {
	double resultado;
	resultado = (covarianza()) / (desviacionTipica(0) * desviacionTipica(1));
	return resultado;
}

//Distancias

double Calculos2Var::distanciaEuclidea() {
	double distanciaEuclidea = 0;

	unsigned int n = getColumna();
	for (unsigned int x = 0; x < n; x++ ) {
		distanciaEuclidea = pow ( ( matriz[i][j] - matriz[i][j + x] ), 2 )
		                    + pow ( ( matriz[i + x][j] - matriz[i + x][j + x] ), 2 );
	}
	return distanciaEuclidea;
}
*/
