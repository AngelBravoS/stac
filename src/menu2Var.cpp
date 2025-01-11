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

#include "cli.hpp"
#include "calculos2Var.hpp"

/*void CLI::menuSecundario2Var() {
	char eleccionNivel2;
	do {
		listadOpciones2Variables();
		std::cin >> eleccionNivel2;
		switch (eleccionNivel2) {
			case '1':
				if(esMuestra() == true) {
					menuMuestra2Var();
				} else {
					menuFmp2Var();
				}
			break;
			case '2':
				menuFmp2Var();
			break;
		}
	} while (eleccionNivel2 != '0');
}*/

/*void CLI::menuFmp2Var(){
	CalculosTablasContBid variables(preguntarDesdeArchivoOTeclado(),
preguntarNumeroFilas(), preguntarNumeroColumnas());
	variables.leerMatriz();
	std::cout << "Variables X e Y:" << '\n';
	variables.mostrarMatriz();
	std::cout << '\n';
	}

unsigned int CLI::preguntarNumeroColumnas() {
	unsigned int col;
	std::cout << "Número de elementos de cada variable: ";
	std::cin >> col;
	return col;
	}

bool CLI::esMuestra(){
	char resultado;
	bool muestra;
	std::cout << "'s' si es una muestra de dos variables" << '\n';
	std::cout << "'n' si quieres calcular a partir de la fmp: " << '\n';
	std::cout << ": ";
	std::cin >> resultado;
	resultado == 's' ? muestra = true: muestra = false;
	return muestra;
	}
*/
