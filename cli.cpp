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
 
//CLI => Command Line Interface.
//#include "cli.hpp"
#include "muestreo.hpp"
#include <iostream>

char CLI::getOpcion() {
	return opcion;
}

void CLI::setOpcion(char opcionPrivada) {
	opcion = opcionPrivada;
}

void CLI::eleccion() {
	char opcionElegida;
	std::cin >> opcionElegida;
	//eleccion='1';
	setOpcion(opcionElegida);
}

void CLI::menuPrincipal() {
	do {
		listadOpcionesPricipales();
		std::cout << "> ";
		eleccion();
		switch(getOpcion()) {
			case '1' :
				menu1Var();
				break;
			case '2' :
				menu2Var();
				break;
			case 'n' :
				menuNVar();
				break;
			case 'a' :
				menuAlgebra();
				break;
			case 'm' :
				Muestreo muestra;
				muestra.menuMuestreo();
				muestra.definirTipoMuestreo();
				muestra.recogerDatosMuestra();
				muestra.mostrarDatosMuestra();
				break;
			case 'h' :
				ayuda();
				break;
			case 's' :
				menuSinDatos();
				break;
		}
	} while(getOpcion() != '0');
}
