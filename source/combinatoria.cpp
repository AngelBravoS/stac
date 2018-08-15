/***************************************************************************
 *   Copyright (C) 2018 by Ángel Bravo Sáenz                               *
 *   angelbravosaenz@gmail.com                                             *
 *                                                                         *
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

//typedef unsigned short int unShortInt;
//Límite máximo en unsigned short int: 65535

double permutaciones(unsigned short int n) {
	double resultado;
	resultado = factorial(n);
	return resultado;
}

double permutacionesRep(unsigned short int m, unsigned short int n, unsigned short int numeroElementos) {
	double resultado = 1;
	for(unsigned short int i = 0; i < numeroElementos; i++) {
		resultado *= factorial(n);
	}
	resultado = factorial(m) / resultado;
	return resultado;
}

double variaciones(unsigned short int m, unsigned short int n) {
	double resultado;
	resultado = factorial(m) / factorial(m - n);
	return resultado;
}

double variacionesRep(unsigned short int m, unsigned short int n) {
	double resultado;
	resultado = potencia(m, n);
	return resultado;
}

double combinaciones(unsigned short int m, unsigned short int n) {
	double resultado;
	resultado = factorial(m) / (factorial(n) * factorial(m - n));
	return resultado;
}

double combinacionesRep(unsigned short int m, unsigned short int n) {
	double resultado;
	unsigned int valorM = m;
	valorM = valorM + (n - 1);
	resultado = (factorial(valorM)) / (factorial(n) * factorial(valorM - n));
	return resultado;
}
