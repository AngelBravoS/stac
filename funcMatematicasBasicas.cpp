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

double factorial(double n) {
	if(n == 0) {
		// Aseguramos que tenga salida siempre
		return 1;
	} else {
		// Caso general
		return  n * factorial(n - 1);
	}
}

double potencia(double numero, unsigned int  potencia) {
	double temporal = numero;
	if(potencia == 0) {
		numero = 1;
	} else {
		for(unsigned int x = 1; x < potencia; x++) {
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

double e (){
	double resultado, producto;
	resultado = 1;
	producto = 1;
	for (unsigned int i = 1; i <= 17; i++) {
		producto *= i;
		resultado += 1/producto;
	}
	return resultado;
}

unsigned int convierteDoubleEnInt(double doble) {
	unsigned int valorEntero = static_cast<unsigned int>(doble);
	return valorEntero;
}

float convierteIntEnFloat(unsigned int entero) {
	float valorFloat = static_cast<float>(entero);
	return valorFloat;
}
