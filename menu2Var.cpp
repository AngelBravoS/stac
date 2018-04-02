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
#include "calculos2Var.hpp"

void CLI::menu2Var() {
	char eleccionNivel2, eligesArchivo;
	Calculos2Var variablesXeY;
	std::cout << "¿Leer desde un archivo?" << '\n';
	std::cout << "s/n:";
	std::cin >> eligesArchivo;
	if(eligesArchivo == 's') {
		variablesXeY.leerMatrizArchivo();
	} else {
		variablesXeY.setDimensionMatriz();
		variablesXeY.crearMatrizVacia();
		variablesXeY.editarMatrizVacia();
		variablesXeY.mostrarMatriz();
		std::cout << '\n';
	}
	do {
		std::cout << "'1' medias y sumatorias" << '\n';
		std::cout << "'2' medidas de dispersión" << '\n';
		std::cout << "'0' Salir." << '\n';
		std::cout << "> ";
		std::cin >> eleccionNivel2;
		variablesXeY.mostrarMatriz();
		std::cout << '\n';
		switch(eleccionNivel2) {
			case '1':
				//medidas de tendencia Central
				std::cout << "Media aritmética de X = " << variablesXeY.calculoMediaAritmetica(0) << '\n';
				std::cout << "Media aritmética de Y = " << variablesXeY.calculoMediaAritmetica(1) << '\n';
				std::cout << "Sumatoria de X = " << variablesXeY.calculoSumatoria(0,1) << '\n';
				std::cout << "Sumatoria de Y = " << variablesXeY.calculoSumatoria(1,1) << '\n';
				std::cout << "Sumatoria de X e Y = " << variablesXeY.sumatoria2Var(0,1,1,1) << '\n';
				std::cout << '\n';
				break;
			case '2':
				//std::cout << "Las diferencias respecto a la media son: " << variablesXeY.difRespecMedia() << endl;
				std::cout << "Varianza de X = " << variablesXeY.calculoVarianza(0) << '\n';
				std::cout << "Varianza de Y = " << variablesXeY.calculoVarianza(1) << '\n';
				std::cout << "Desviación típica de X = " << variablesXeY.desviacionTipica(0) << '\n';
				std::cout << "Desviación típica de Y = " << variablesXeY.desviacionTipica(1) << '\n';
				std::cout << "Covarianza de X e Y = " << variablesXeY.covarianza() << '\n';
				std::cout << "Coeficiente de correlación de X e Y =  " << variablesXeY.coeficienteCorrelacion() << '\n';
				std::cout << '\n';
				break;
		}
	} while(eleccionNivel2 != '0');
	//variablesXeY.destructorVector();
}
