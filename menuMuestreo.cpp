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
	char tipoDeMuestreo, estimador = '\0';
	bool agrupados;
	agrupados = preguntarSiAgrupados();
	MAS muestra(preguntarDesdeArchivoOTeclado(), estimador, preguntarNumeroColumnas(agrupados), agrupados);
	muestra.desdeDondeLeeDatos();
//	muestra.crearMatrizParaCalculos();
	listadOpcionesMuestreo();
	std::cin >> tipoDeMuestreo;
	preguntarEstimador();
	std::cin >> estimador;
	std::cout << '\n' << "Tabla de datos" << '\n';
	//muestra.mostrarMatrizResuelta();
	std::cout << '\n';
	muestra.mostrarMatriz();
	std::cout << '\n';

	std::cout << "Sumatorias" << '\n';
	std::cout << '\n';
	std::cout << "∑Xi = " << muestra.sumatoria(0, 1) << '\n';
	std::cout << "   2" << '\n';
	std::cout << "∑Xi = " << muestra.sumatoria(0, 2) << '\n';
	std::cout << "     _ 2" << '\n';
	std::cout << "∑(Xi-X) = " << muestra.difRespecMedia(0, 2) << '\n';
	std::cout << '\n';

	std::cout << "Estimadores de las varianzas" << '\n';
	std::cout << '\n';
	std::cout << "Varianza = " << muestra.varianza(0) << '\n';
	std::cout << "Desviación típica = " << muestra.desviacionTipica(0) << '\n';

	std::cout << "Varianzas de los estimadores" << '\n';
	std::cout << '\n';
	}

unsigned int MenuMuestreo::preguntarNumeroColumnas(bool agrupados) {
	unsigned int columna;
	if (agrupados == true) {
		std::cout << "Número de datos distintos que contiene la muestra: ";
		}
	else {
		std::cout << "Tamaño de la muestra: ";
		}
	std::cin >> columna;
	return columna;
	}

bool MenuMuestreo::preguntarSiAgrupados() {
	char respuesta;
	bool agrupados;
	std::cout << '\n';
	std::cout << "¿Los datos están agrupados?" << '\n';
	std::cout << "s/n:";
	std::cin >> respuesta;
	respuesta == 's' ? agrupados = true : agrupados = false;
	return agrupados;
	}
