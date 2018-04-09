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
#include "cli.hpp"
#include "calculosIA.hpp"

void CLI::menuIA() {
	unsigned short int a, b, X0;
	unsigned int m;
	CalculosIA secuencia;
	std::cout << "Escribe x para el generador congruencial mixto." << '\n';
	std::cout << "Escribe m para el generador congruencial multiplicativo." << '\n';
	std::cout << "> ";
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
		std::cin >> X0;
		if(m <= a || m <= b)
			std::cout << "secuencia no válida (m > a,b).";
		else {
			std::cout << "Para a = " << a << ", b = " << b << ", m = "
			     << m << ", y Xo = " << X0 << ", el resultado es:" << '\n';
			secuencia.crearSecuenciaMixto(a, b, m, X0);
		}
		break;
	case 'm':
		std::cout << "valor de a = ";
		std::cin >> a;
		std::cout << "valor de m = ";
		std::cin >> m;
		std::cout << "valor de Xo = ";
		std::cin >> X0;
		std::cout << "Para a = " << a << ", m = " << m << ", y Xo = "
		     << X0 << ", el resultado es:" << '\n';
		secuencia.crearSecuenciaMultip(a, m, X0);
		break;
	}
	std::cout << "El período de la secuencia es " << secuencia.getLongitudVector() << '\n';
	std::cout << '\n';
}
