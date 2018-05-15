/***************************************************************************														*
 *   Copyright (C) 2018 by Ángel Bravo Sáenz  										*
 *   angelbravosaenz@gmail.com  															*
 *																									*
 *   This file is part of Stac.                                            *
 *                                                                         *
 *   Stac is free software; you can redistribute it and/or modify          *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
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

#include "funcMatematicasBasicas.hpp"
//#include "distribuciones.hpp"
#include <math.h>

double poisson(float parametroP, unsigned int probabilidad) {
	double resultado;
	float lambda = parametroP;
	double e = 2.7182818284590;
	unsigned int x = probabilidad;
	resultado = (pow(e, -lambda)) * (pow(lambda, x) / factorial(x));
	return resultado;
}

double bernouilli(float p, unsigned int x) {
	double resultado;
	resultado = potencia(p, x) * potencia(1 - p, x - 1);
	return resultado;
}

double binomial(unsigned int n, float p,
                unsigned int x) {
	double resultado;
	float q = (1 - p);
	if(n > 50 && p <= 0.1) {
		resultado = poisson(n * p, x);
	} else {
		resultado = binomio(n, x) * potencia(p, x) * potencia(q, n - x);
	}
	return resultado;
}

double binomialNegativa(unsigned int parametron, float parametroP,
                        unsigned int probabilidad) {
	double resultado;
	unsigned int n = parametron;
	float p = parametroP;
	int x = probabilidad;
	resultado = binomio(n + (x - 1), x) * potencia(p, n) * potencia(1 - p, x);
	return resultado;
}

double hipergeometrica(unsigned int parametroN, unsigned int parametron,
                       unsigned int parametror,
                       unsigned int probabilidad) {
	unsigned int N = parametroN;
	unsigned int x = probabilidad;
	unsigned int n = parametron;
	float r = parametror;
	float parametroP = r/N;
	double resultado;
	if(n<0.1*N) {
		resultado = binomial(parametron, parametroP, x);
	} else {
		resultado = binomio(r,x) * binomio((N-r),(n-x)) / binomio(N,n);
	}
	return resultado;
}

double geometrica(float parametroP, unsigned int probabilidad) {
	double resultado;
	float p = parametroP;
	float q = 1 - p;
	unsigned int x = probabilidad;
	resultado = (potencia(p * q, x - 1));
	return resultado;
}
