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
#include "cli.hpp"
#include "menu1Var.hpp"
#include "menu2Var.hpp"
#include "menuMuestreo.hpp"
#include <iostream>

char CLI::getOpcionSeleccionada() {
	return respuestaUsuario;
}

void CLI::setOpcionSeleccionada(char respuestaUsuarioPublica) {
	respuestaUsuario = respuestaUsuarioPublica;
}

void CLI::eleccion() {
	char opcionElegida;
	std::cin >> opcionElegida;
	//eleccion='1';
	setOpcionSeleccionada(opcionElegida);
}

void CLI::menuPrincipal() {
	do {
		listadOpcionesPricipales();
		std::cout << "> ";
		eleccion();
		switch(getOpcionSeleccionada()) {
			case '1' :
				Menu1Var variableX;
				variableX.menuSecundario();
				break;
			case '2' :
				Menu2Var variableXeY;
				variableX.menuSecundario();
				break;
			case 'n' :
				menuNVar();
				break;
			case 'a' :
				menuAlgebra();
				break;
			case 'm' :
				MenuMuestreo muestra;
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
	} while(getOpcionSeleccionada() != '0');
}
