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

#include <iostream>
#include "menuIA.hpp"

void MenuIA::periodo() {

}

void MenuIA::menuSecundario() {
	unsigned int a, b, Xo, Xn, m;
	CalculosIA secuencia;
	std::cout << "Escribe x para el generador congruencial mixto." << '\n';
	std::cout << "Escribe m para el generador congruencial multiplicativo." << '\n';
	std::cout << "> ";
	unsigned int i = 1;
	eleccion();
	switch(getOpcionSeleccionada()) {
	case 'x':
		std::cout << "valor de a = ";
		std::cin >> a;
		std::cout << "valor de b = ";
		std::cin >> b;
		std::cout << "valor de m = ";
		std::cin >> m;
		std::cout << "valor de Xo = ";
		std::cin >> Xo;
		if(m <= a || m <= b) {
			std::cout << "secuencia no válida (m > a,b).";
			exit(-1);
		} else {
			std::cout << "Para a = " << a << ", b = " << b << ", m = "
			          << m << ", y Xo = " << Xo << ", el resultado es:" << '\n';
			std::cout << "(" << secuencia.congruencialMixto(a, b, m, Xo);
			//crea el primer valor X1 para usarlo como referencia
			//mientras no coincida con el siguiente sigue calculando
			Xn = secuencia.congruencialMixto(a, b, m, Xo);
			while(Xo != Xn) {
				std::cout << " " << secuencia.congruencialMixto(a, b, m, Xn);
				Xn = secuencia.congruencialMixto(a, b, m, Xn);
				i++;
			}
			std::cout << ")" << '\n';
			std::cout << "El período de la secuencia es " << i << '\n';
			if(i == m) {
				std::cout << "Es de período completo" << '\n';
			}
		}
		break;
	case 'm':
		std::cout << "valor de a = ";
		std::cin >> a;
		std::cout << "valor de m = ";
		std::cin >> m;
		std::cout << "valor de Xo = ";
		std::cin >> Xo;
		std::cout << "Para a = " << a << ", m = " << m << ", y Xo = "
		          << Xo << ", el resultado es:" << '\n';
		std::cout << "(" << secuencia.congruencialMultip(a, m, Xo);
		//crea el primer valor X1 para usarlo como referencia
		//mientras no coincida con el siguiente sigue calculando
		Xn = secuencia.congruencialMultip(a, m, Xo);
		i = 1;
		while(Xo != Xn) {
			std::cout << " " << secuencia.congruencialMultip(a, m, Xn);
			Xn = secuencia.congruencialMultip(a, m, Xn);
			i++;
		}
		std::cout << " " << secuencia.congruencialMultip(a, m, Xn);
		Xn = secuencia.congruencialMultip(a, m, Xn);
		i++;
		std::cout << ")" << '\n';
		std::cout << "El período de la secuencia es " << i << '\n';
		break;
	}
}
