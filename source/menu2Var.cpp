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

#include <iostream>
#include "menu2Var.hpp"

void Menu2Var::menuSecundario() {
	char eleccionNivel2;
	Calculos2Var variables(desdeArchivoOTeclado(), 2, tamanoColumna());
	variables.desdeDondeLeeMatriz();
	std::cout << "Variables X e Y:" << '\n';
	variables.mostrarMatriz();
	std::cout << '\n';
	do {
		listadOpciones2Variables();
		std::cin >> eleccionNivel2;
		std::cout << "Variables X e Y:" << '\n';
		variables.mostrarMatriz();
		std::cout << '\n';
		switch(eleccionNivel2) {
		case '1':
			std::cout << "Medidas de tendencia Central" << '\n';
			std::cout << "	Media aritmética de X = " << variables.mediaAritmetica(0) << '\n';
			std::cout << "	Media aritmética de Y = " << variables.mediaAritmetica(1) << '\n';
			std::cout << "	Sumatoria de X = " << variables.sumatoria(0, 1) << '\n';
			std::cout << "	Sumatoria de X^2 = " << variables.sumatoria(0, 2) << '\n';
			std::cout << "	Sumatoria de Y = " << variables.sumatoria(1, 1) << '\n';
			std::cout << "	Sumatoria de Y^2 = " << variables.sumatoria(1, 2) << '\n';
			std::cout << "	Sumatoria de X e Y = " << variables.sumatoria2Var(0, 1, 1, 1) << '\n';
			std::cout << '\n';
			std::cout << "Medidas de dispersión" << '\n';
			std::cout << "	Varianza de X = " << variables.varianza(0) << '\n';
			std::cout << "	Varianza de Y = " << variables.varianza(1) << '\n';
			std::cout << "	Desviación típica de X = " << variables.desviacionTipica(0) << '\n';
			std::cout << "	Desviación típica de Y = " << variables.desviacionTipica(1) << '\n';
			std::cout << "	Covarianza de X e Y = " << variables.covarianza() << '\n';			
			break;
		case '2':
			//std::cout << "Las diferencias respecto a la media son: " << variablesXeY.difRespecMedia() << endl;

			break;
		case '3':
			// regresión y correlación
			std::cout << "Regresión" << '\n';
			std::cout << "	Rectas de regresión:" << '\n';
			std::cout << "		Recta de Y sobre X: y = " << variables.coeficienteRegresion(0) << "x" << " + (" << variables.rectaRegresion(0) + variables.mediaAritmetica(1) << ")" << '\n';
			std::cout << "		Recta de X sobre Y: x = " << variables.coeficienteRegresion(1) << "y" << " + (" << variables.rectaRegresion(1) + variables.mediaAritmetica(0) << ")" << '\n';
			std::cout << "	Coeficientes de regresión:" << '\n';
			std::cout << "		Coeficiente de Y sobre X: " << variables.coeficienteRegresion(0) << '\n';
			std::cout << "		Coeficiente de X sobre Y: " << variables.coeficienteRegresion(1) << '\n';
			std::cout << "Correlación" << '\n';
			std::cout << "Coeficiente de correlación lineal: " << variables.coeficienteCorrelacion()<<'\n';
			//std::cout << "" << '\n';
			/*std::cout << " = " << variables. << '\n';
			std::cout << " = " << variables. << '\n';
			std::cout << " = " << variables. << '\n';
			std::cout << " = " << variables. << '\n';*/
			break;
		}
	} while(eleccionNivel2 != '0');
	//variables.destructorVector();
}

unsigned int Menu2Var::tamanoColumna() {
	unsigned int col;
	std::cout << "Número de elementos de cada variable: ";
	std::cin >> col;
	return col;
}
