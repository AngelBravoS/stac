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

//CLI => Command Line Interface.
#include "cli.hpp"

void CLI::eleccion(unsigned int i) {
	std::cin >> opciones[i];
}

void CLI::menuPrincipal() {
	do {
		listadOpcionesPrincipales();
		std::cout << "> ";
		eleccion(0);
		switch (opciones[0]) {
			case '1' : 
				menuSecundario1Var();
				break;
			case '2' :
				menuSecundario2Var();
				break;
			case '3' :
				menuSecundarioNvar();
				break;
			case '4' :
				menuSecundarioAlgebra(); 
				break;
			case '5' :
				//menuSecundarioMuestreo();
				break;
			case '6' :
				menuSinDatos();
				break;
			case '7' :
				ayuda();
				break;
		}
	} while (opciones[0] != '0');
}
