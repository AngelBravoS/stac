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

#include "calculos2Var.hpp"

//Límite máximo en unsigned short int: 65535
//Límite máximo en unsigned int: 4.294.967.295
/*
Vector extraerVariable(Matriz &m1, unsigned int variable) {
	unsigned int n = m1.ColumnCount();
	Vector resultado(n);
	for (unsigned int i = 0; i < n; i++) {
		resultado[i] = m1[variable][i];
	}
	return resultado;
}



//-----Pide un exponente para poder hacer cosumatorias de cuadrados, cubos, etc,
//sin necesitar otro método
//-----recibe el exponente de cada variable así como su índice dentro de la
//matriz (0, 1, 2...)
//-----como las dos variables tienen la misma longitud (vector[0].length
//= vector[1].length) y solo hay que indicar
//-----una de ellas, se elige la primera.

double sumatoria2Var(Matriz &m1, int exponenteX, int exponenteY) {
	double sumatoria2Variables = 0;
	unsigned int n = m1.ColumnCount();
	for (unsigned int i = 0; i < n; i++) {
		sumatoria2Variables += pow(m1[0][i], exponenteX) * pow(m1[1][i],
		                       exponenteY);
	}
	return sumatoria2Variables;
}

double covarianza(Matriz &m1) {
	unsigned int n = m1.ColumnCount();
	double resultado = 0;
	resultado += (sumatoria2Var(m1, 1, 1));

	Vector x(n);
	x = extraerVariable(m1, 0);

	Vector y(n);
	y = extraerVariable(m1, 1);

	resultado = (resultado / n) - (mediaAritmetica(x) * mediaAritmetica(y));
	return resultado;
}

double rectaRegresion(Matriz &m1, Vector &v1) {
	double resultado = 0;
	resultado = -1 * mediaAritmetica(v1) * coeficienteRegresion(m1, v1);
	return resultado;
}

double curvaRegresion(Matriz &m1, Vector &v1) {
	double resultado = 0;
	
	resultado = -1 * mediaAritmetica(v1) * coeficienteRegresion(m1, v1);
	return resultado;
}

double coeficienteRegresion(Matriz &m1, Vector &v1) {
	double resultado;
	//unsigned int n = m1.ColumnCount();
	resultado = covarianza(m1) / varianza(v1);
	return resultado;
}

double coeficienteCorrelacion(Matriz &m1) {
	double resultado;
	unsigned int n = m1.ColumnCount();
	Vector x(n);
	x = extraerVariable(m1, 0);
	Vector y(n);
	y = extraerVariable(m1, 1);
	resultado = (covarianza(m1)) / (desviacionTipica(x) * desviacionTipica(y));
	return resultado;
}
*/
//Distancias
/*
double distanciaEuclidea() {
	double distanciaEuclidea = 0;

	unsigned int n = getColumna();
	for (unsigned int x = 0; x < n; x++ ) {
		distanciaEuclidea = pow ( ( matriz[i][j] - matriz[i][j + x] ), 2 )
		                    + pow ( ( matriz[i + x][j] - matriz[i + x][j + x] ), 2
);
	}
	return distanciaEuclidea;
}
*/
