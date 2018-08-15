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

#include "calculosIA.hpp"
#include "funcMatematicasBasicas.hpp"

CalculosIA::CalculosIA (){
	leerDesdeArchivo = false;
}

unsigned int CalculosIA::periodo(){
	return longitudVector;
}

//---función para el generador congruencial mixto--
unsigned int CalculosIA::congruencialMixto(unsigned int a, unsigned int b,
      unsigned int m, unsigned int X0) {
	unsigned int resultado ;
	resultado = a * X0 + b;
	if(resultado > m)
		resultado = resultado % m;
	return resultado;
}

//---función para el generador congruencial multiplicativo---
unsigned int CalculosIA::congruencialMultip(unsigned int a, unsigned int m,
      unsigned int X0) {
	unsigned int resultado;
	resultado = a * X0;
	if(resultado > m)
		resultado %=  m;
	return resultado;
}

void CalculosIA::crearSecuenciaMixto(unsigned int a, unsigned int b,
                                     unsigned int m, unsigned int X0) {
	//Desconocemos la longitud del vector hasta que la semilla se repite
	//por eso la llamada es redundante. Se llama en bucle dos veces, una
	//para saber la longitud y otra para crear el vector con la secuencia
	/*unsigned int i, Xn, n;
	Xn = congruencialMixto(a, b, m, X0);
	n = 1;
	while(X0 != Xn) {
		Xn = congruencialMixto(a, b, m, Xn);
		n++;
	}
	longitudVector = n;
	crearVectorVacio();
	vector[0] = congruencialMixto(a, b, m, X0);
	i = 0;
	while(X0 != vector[i]) {
		vector[i+1] = congruencialMixto(a, b, m, vector[i]);
		i++;
	}*/
}


void CalculosIA::crearSecuenciaMultip(unsigned int a, unsigned int m,
                                      unsigned int X0) {
	//Desconocemos la longitud del vector hasta que la semilla se repite
	//por eso la llamada es redundante. Se llama en bucle dos veces, una
	//para saber la longitud y otra para crear el vector con la secuencia
	/*unsigned int i, Xn, n;
	Xn = congruencialMultip(a, m, X0);
	n = 1;
	while(X0 != Xn) {
		Xn = congruencialMultip(a, m, Xn);
		n++;
	}
	longitudVector = n;
	crearVectorVacio();
	vector[0] = congruencialMultip(a, m, X0);
	i = 0;
	while(X0 != vector[i]) {
		vector[i+1] = congruencialMultip(a, m, vector[i]);
		i++;
	}*/
	//periodo(n);
}
