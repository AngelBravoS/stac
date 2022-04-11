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
#include <iostream>
#include "menuMuestreo.hpp"

void MenuMuestreo::menuSecundario() {
	unsigned int longitudSelec = 0, valorDeN = 0, estimadorSelec = 0;
	bool agrupados = false, desdeArchivoOTeclado = false;

	desdeArchivoOTeclado = preguntarDesdeArchivoOTeclado();
	agrupados = preguntarSiAgrupados();
	longitudSelec = preguntarNumeroColumnas(agrupados);
	std::cout << "valor de N: ";
	std::cin >> valorDeN;
	estimadorSelec = preguntarEstimador();

	//MAS muestra(desdeArchivoOTeclado, longitudSelec, agrupados);
	MAS muestra(desdeArchivoOTeclado, longitudSelec, agrupados,
	            estimadorSelec);

	muestra.setValorN(valorDeN);
	muestra.leerDatos();
	std::cout << '\n' << "Datos de la muestra" << '\n';
	std::cout << '\n';
	muestra.mostrarVector();
	std::cout << '\n';

	//if(estimadorSeleccionado==2){}

	std::cout << '\n';
	std::cout << "Sumatorias, estadísticos y varianzas" << '\n';
	std::cout << '\n';
	std::cout << "∑Xi = " << muestra.sumatoria(1) << '\n';
	std::cout << "   2" << '\n';
	std::cout << "∑Xi = " << muestra.sumatoria(2) << '\n';
	std::cout << "     _ 2" << '\n';
	std::cout << "∑(Xi-X) = " << muestra.difRespecMedia(2) << '\n';
	std::cout << '\n';
	
	std::cout << "Estimador = " << muestra.calcularEstimador() << '\n';
	std::cout << '\n';
	
	std::cout << "Var = " << muestra.varianza() << '\n';
	std::cout << " 2" << '\n';
	std::cout << "S = " << muestra.varianzaMuestral() << '\n';
	std::cout << '\n';

	std::cout << "Varianzas del estimador = ";
	std::cout << muestra.varianzaEstimador() << '\n';
	std::cout << '\n';

	std::cout << "Error de estimación del parámetro = ";
	std::cout << muestra.em() << '\n';
	std::cout << '\n';
}

unsigned int MenuMuestreo::preguntarNumeroColumnas(bool agrupados) {
	unsigned int columna;
	if (agrupados == true) {
		std::cout << "Número de datos agrupados que contiene la muestra: ";
	} else {
		std::cout << "Tamaño de la muestra: ";
	}
	std::cin >> columna;
	return columna;
}

unsigned int MenuMuestreo::preguntarEstimador() {
	unsigned int estimador;
	std::cout << "Selecciona el estimador:" << '\n';
	std::cout << "'1' media" << '\n';
	std::cout << "'2' total" << '\n';
	std::cout << "'3' proporción" << '\n';
	std::cout << "> ";
	std::cin >> estimador;
	return estimador;
}

bool MenuMuestreo::preguntarSiAgrupados() {
	char respuesta;
	bool agrupados;
	std::cout << "¿Los datos están agrupados? s/n: ";
	std::cin >> respuesta;
	respuesta == 's' ? agrupados = true : agrupados = false;
	return agrupados;
}
