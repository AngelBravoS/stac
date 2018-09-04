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

//CLI => Command Line Interface.
#include <iostream>
#include "menuMuestreo.hpp"

void MenuMuestreo::menuSecundario() {
	char respuesta, tipoDeMuestreo;
	bool agrupados;
	unsigned int longitudFila;
	longitudFila = 3;
	//var = 1;
	listadOpcionesMuestreo();
	std::cin >> tipoDeMuestreo;
	std::cout << '\n';
	std::cout << "¿Los datos están agrupados?" << '\n';
	std::cout << "s/n:";
	std::cin >> respuesta;
	respuesta == 's' ? agrupados = true : agrupados = false;
	CalculosMuestreo muestra(desdeArchivoOTeclado(), tipoDeMuestreo, longitudFila, longitudColumna (agrupados), agrupados);
	muestra.asignar();
	muestra.desdeDondeLeeMatriz();
	std::cout << '\n';
	std::cout << "Tabla de datos:" << '\n';
	muestra.mostrarMatriz();
	std::cout << '\n';
	std::cout << "cosas:" << '\n';
	muestra.mostrarMatrizB();
	std::cout << '\n';
	std::cout << "∑Xi = " << muestra.sumatoria(0, 1);
	std::cout << ", ∑Xi^2 = " << muestra.sumatoria(0, 2);
	std::cout << ", media  = " << muestra.mediaAritmetica(0) << '\n';
	std::cout << ", cuasiVarianza  = " << muestra.cuasiVarianza(0) << '\n';
	//std::cout << ", total = " << muestra.total(0) << '\n';
	std::cout << '\n';
}

unsigned int MenuMuestreo::longitudColumna (bool agrupados) {
	unsigned int columna;
	if(agrupados == true) {
		std::cout << "Número de datos distintos que contiene la muestra: ";
	} else {
		std::cout << "Tamaño de la muestra: ";
	}
	std::cin >> columna;
	return columna;
}

void crearMuestra() {
}
