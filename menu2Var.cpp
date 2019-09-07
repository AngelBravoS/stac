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
}

void Menu2Var::menuMuestra2Var(){
	Calculos2Var variables(preguntarDesdeArchivoOTeclado(), 2, preguntarNumeroColumnas());
	variables.desdeDondeLeeMatriz();
	std::cout << "Variables X e Y:" << '\n';
	variables.mostrarMatriz();
	std::cout << '\n';
	std::cout << "Medidas de tendencia Central" << '\n';
	std::cout << " _" << '\n';
	std::cout << " X = " << variables.mediaAritmetica(0) << '\n';
	std::cout << " _" << '\n';
	std::cout << " Y = " << variables.mediaAritmetica(1) << '\n';
	std::cout << '\n';
	std::cout << " ∑Xi = " << variables.sumatoria(0, 1) << '\n';
	std::cout << "    2" << '\n';
	std::cout << " ∑Xi = " << variables.sumatoria(0, 2) << '\n';
	std::cout << '\n';
	std::cout << " ∑Yi = " << variables.sumatoria(1, 1) << '\n';
	std::cout << "    2" << '\n';
	std::cout << " ∑Yi = " << variables.sumatoria(1, 2) << '\n';
	std::cout << '\n';
	std::cout << " ∑XYi = " << variables.sumatoria2Var(0, 1, 1, 1) << '\n';
	std::cout << '\n';
	std::cout << "Medidas de dispersión" << '\n';
	std::cout << "                      _ 2" << '\n';
	std::cout << "                 ∑(Xi-X)" << '\n';
	std::cout << " varianza de X = ------- = "  << variables.varianza(0) << '\n';
	std::cout << "                    1  " << '\n';
	std::cout << "                      _ 2" << '\n';
	std::cout << "                 ∑(Xi-X)" << '\n';
	std::cout << " varianza de Y = ------- = "  << variables.varianza(1) << '\n';
	std::cout << "                    1  " << '\n';
	std::cout << " Desviación típica de X = " << variables.desviacionTipica(0) << '\n';
	std::cout << " Desviación típica de Y = " << variables.desviacionTipica(1) << '\n';
	std::cout << " Covarianza de X e Y = " << variables.covarianza() << '\n';
	std::cout << "Regresión" << '\n';
	std::cout << "	Rectas de regresión:" << '\n';
	std::cout << "		Recta de Y sobre X: y = " << variables.coeficienteRegresion(0) << "x" << " + (" << variables.rectaRegresion(0) + variables.mediaAritmetica(1) << ")" << '\n';
	std::cout << "		Recta de X sobre Y: x = " << variables.coeficienteRegresion(1) << "y" << " + (" << variables.rectaRegresion(1) + variables.mediaAritmetica(0) << ")" << '\n';
	std::cout << "	Coeficientes de regresión:" << '\n';
	std::cout << "		Coeficiente de Y sobre X: " << variables.coeficienteRegresion(0) << '\n';
	std::cout << "		Coeficiente de X sobre Y: " << variables.coeficienteRegresion(1) << '\n';
	std::cout << "Correlación" << '\n';
	std::cout << "	Coeficiente de correlación lineal: " << variables.coeficienteCorrelacion() << '\n';
}

void Menu2Var::menuFmp2Var(){
	/*CalculosTablasContBid variables(preguntarDesdeArchivoOTeclado(), preguntarNumeroFilas(), preguntarNumeroColumnas());
	variables.desdeDondeLeeMatriz();
	std::cout << "Variables X e Y:" << '\n';
	variables.mostrarMatriz();
	std::cout << '\n';*/
	}

unsigned int Menu2Var::preguntarNumeroColumnas() {
	unsigned int col;
	std::cout << "Número de elementos de cada variable: ";
	std::cin >> col;
	return col;
	}

bool Menu2Var::esMuestra(){
	char resultado;
	bool muestra;
	std::cout << "'s' si es una muestra de dos variables" << '\n';
	std::cout << "'n' si quieres calcular a partir de la fmp: " << '\n';
	std::cout << ": ";
	std::cin >> resultado;
	resultado == 's' ? muestra = true: muestra = false;
	return muestra;
	}

