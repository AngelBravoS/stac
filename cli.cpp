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
#include "menu1Var.hpp"
#include "menu2Var.hpp"
#include "menuNVar.hpp"
#include "menuAlgebra.hpp"
#include "menuMuestreo.hpp"
#include <iostream>

void CLI::eleccion (unsigned int i) {
	std::cin >> opciones[i];
}

void CLI::menuPrincipal() {
	do {
		listadOpcionesPricipales();
		std::cout << "> ";
		eleccion(0);
		switch(opciones[0]) {
			case '1' : {
				Menu1Var univariante;
				univariante.menuSecundario();
				break;
			}
			case '2' : {
				Menu2Var bivariante;
				bivariante.menuSecundario();
				break;
			}
			case 'n' : {
				MenuNVar multivariante;
				multivariante.menuSecundario();
				break;
			}
			case 'a' : {
				MenuAlgebra algebra;
				algebra.menuSecundario();
				break;
			}
			case 'm' : {
				MenuMuestreo muestreo;
				muestreo.menuSecundario();
				break;
			}
			case 'h' : {
				ayuda();
				break;
			}
			case 's' : {
				menuSinDatos();
				break;
			}
		}
	} while(opciones[0] != '0');
}

unsigned int CLI::preguntarTamanoVector(){
	unsigned int tamano;
	std::cout << "Tamaño del vector: ";
	std::cin >> tamano;
	return  tamano;
}

unsigned int CLI::preguntarNumeroFilas() {
	unsigned int fila;
	std::cout << "Número de filas: ";
	std::cin >> fila;
	return fila;
}

unsigned int CLI::preguntarNumeroColumnas() {
	unsigned int col;
	std::cout << "Número de columnas: ";
	std::cin >> col;
	return col;
}

bool CLI::preguntarDesdeArchivoOTeclado() {
	char opcion;
	bool eligesArchivo;
	std::cout << "¿Leer desde un archivo?" << '\n';
	std::cout << "s/n:";
	std::cin >> opcion;
	opcion == 's'? eligesArchivo = true: eligesArchivo = false;
	return eligesArchivo;
}
