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

#include "calculosIA.hpp"

CalculosIA::CalculosIA(unsigned int parametro_a, unsigned int parametro_b,
                       unsigned int parametro_m, unsigned int parametro_X0) {
	a = parametro_a;
	b = parametro_b;
	m = parametro_m;
	X0 = parametro_X0;
}

CalculosIA::CalculosIA(unsigned int parametro_a, unsigned int parametro_b,
                       unsigned int parametro_m) {
	a = parametro_a;
	b = parametro_b;
	m = parametro_m;
}

//---función para el generador congruencial mixto y multiplicativo--
unsigned int CalculosIA::generador(unsigned int semilla) {
	unsigned int resultado ;
	resultado = a * semilla + b;
	if (resultado > m)
		resultado = resultado % m;
	return resultado;
}

void CalculosIA::crearSecuencia() {
	unsigned int Xn = generador(X0);
	secuencia.push_back(Xn);
	while (X0 != Xn) {
		Xn = generador(Xn);
		secuencia.push_back(Xn);
	}
}

void CalculosIA::mostrarSecuencia() {
	std::cout << "( ";
	for (unsigned int i = 0; i < secuencia.size(); i++) {
		std::cout << secuencia[i] << ", ";
	}
	std::cout << ")" << "\n";
	std::cout << "Y su longitud es " << secuencia.size();
	if (m == secuencia.size()) {
		std::cout << ", por tanto es de período completo." << "\n";
	}
}

bool CalculosIA::sonCongruentesFactoresPrimoQ() {
	std::vector<unsigned int> valoresPrimosM;
	for (unsigned int i = 1; i <= m; i++) {
		if (m % i == 0 && esPrimo(i) == true) {
			valoresPrimosM.push_back(i);
		}
	}

	for (unsigned int i = 0; i < valoresPrimosM.size(); i++) {
		if (sonCongruentes(a, 1, valoresPrimosM[i]) == false) {
			return false;
		}
	}
	return true;
}

bool CalculosIA::sonCongruentesFactoresPrimoP() {
	std::vector<unsigned int> valoresPrimosM;
	for (unsigned int i = 1; i <= m; i++) {
		if (m % i == 0 && esPrimo(i) == true) {
			valoresPrimosM.push_back(i);
		}
	}

	for (unsigned int i = 0; i < valoresPrimosM.size(); i++) {
		if (sonCongruentes(pow(a, valoresPrimosM[i]), 1, m) == false) {
			return false;
		}
	}
	return true;
}

bool CalculosIA::esMCongruente4() {
	if (m % 4 != 0) { //Si el módulo es distinto de 0, m no es un múltiplo de 4
		//y la norma se ignora
		return true;
	} else if ((sonCongruentes(a, 1, 4)) == true) {
		return true;
	} else {
		return false;
	}
}

bool CalculosIA::mEsPotenciaDe2() {
	return (m != 0) && ((m & (m - 1)) == 0);
}

bool CalculosIA::cumpleTeoremaKnuth() {
	if ((sonCoprimos(b, m) == false) || (sonCongruentesFactoresPrimoQ() ==
	                                     false) || (esMCongruente4() == false)) {
		return false;
	} else {
		return true;
	}
}

void CalculosIA::comprobarPeriodo(char tipoGenerador) {
	if (tipoGenerador == 'x') { // 'x' -> Mixto
		if (cumpleTeoremaKnuth() == true) {
			periodoMaximo = true;
		} else {
			periodoMaximo = false;
		}

	} else { // 'm' -> multiplicativo
		if (mEsPotenciaDe2() == true) {
			if ((esMultiplo(a, 2) == false) && (esMultiplo(X0, 2) == false)
			    && ((sonCongruentes(a, 3, 8) == true) || (sonCongruentes(a, 5, 8) ==
			        true))) {
				periodoMaximo = true;
			} else {
				periodoMaximo = false;
			}
		} else if (sonCongruentesFactoresPrimoP() == false) {
			periodoMaximo = true;
		} else {
			periodoMaximo = false;
		}
	}
}

void CalculosIA::mostrarComprobacionPeriodo() {
	if (periodoMaximo == true) {
		std::cout << "El período SI es máximo." << "\n";
	} else {
		std::cout << "El período NO es máximo." << "\n";
	}
}
