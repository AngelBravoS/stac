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

//#include <math.h>

//----- Pide un exponente para poder hacer sumatorias de cuadrados,
// cubos, etc, sin necesitar otro método-----//
/*double sumatoria(int exponente, int n) {
	double sumatoria = 0;
    for (short int i = 0; i < n; i++) {
		sumatoria = sumatoria + Math.pow(vector[indiceVariable][j], exponente);
     }
    return sumatoria;
}*/

double factorial(double n) {
	if(n == 0) {
		// Aseguramos que tenga salida siempre
		return 1;
	} else {
		// Caso general
		return  n * factorial(n - 1);
	}
}

double potencia(double numero, unsigned short int  potencia) {
	double temporal = numero;
	if(potencia == 0) {
		numero = 1;
	} else {
		for(unsigned short int x = 1; x < potencia; x++) {
			numero *= temporal;
		}
	}
	return numero;
}

double binomio(double n, double k) {
	double resultado;
	if(k==0) {
		resultado = 1;
	} else if(n == 0) {
		resultado = 0;
	} else {
		resultado = factorial(n)/(factorial(k)*factorial(n-k));
	}
	return resultado;
}

unsigned int convierteDoubleEnInt(double doble) {
	unsigned int valorEntero = static_cast<unsigned int>(doble);
	return valorEntero;
}
