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
#include "menu1Var.hpp"

void Menu1Var::menuSecundario() {
	char eligesArchivo, eleccionNivel2, eleccionNivel3, eleccionNivel4;
	listadOpciones1Variable();
	//Calculos1Var variableX;
	std::cout << "¿Leer desde un archivo?" << '\n';
	std::cout << "s/n:";
	std::cin >> eligesArchivo;
	if(eligesArchivo == 's') {
		variableX.leerVectorArchivo();
	} else {
		std::cout << "Número de elementos: ";
		variableX.numElementosVector();
		variableX.crearVectorVacio();
		variableX.editarVectorVacio();
	}
	do {
		std::cout << "Vector:" << '\n';
		variableX.mostrarVector();
		listadOpciones1Variable();
		std::cin >> eleccionNivel2;
		switch(eleccionNivel2) {
		case '1':
			std::cout << "Medidas de tendencia central" << '\n';
			std::cout << "Media aritmética = " << variableX.mediaAritmetica() << '\n';
			std::cout << "Media geométrica = " << variableX.mediaGeometrica() << '\n';
			std::cout << "Media armónica = " << variableX.mediaArmonica() << '\n';
			std::cout << "Media cuadrática = " << variableX.mediaCuadratica() << '\n';
			std::cout << '\n';
			std::cout << "Medidas de dispersión" << '\n';
			//std::cout << "Las diferencias respecto a la media son: " << variableX.difRespecMedia() << endl;
			std::cout << "Varianza = " << variableX.varianza() << '\n';
			std::cout << "Cuasivarianza = " << variableX.cuasiVarianza() << '\n';
			std::cout << "Desviación típica = " << variableX.desviacionTipica() << '\n';
			std::cout << "Cuasidesviación típica = " << variableX.cuasiDesviacionTipica() << '\n';
			std::cout << '\n';
			std::cout << "Medidas de forma" << '\n';
			std::cout << "Norma = " << variableX.norma() << '\n';
			std::cout << '\n';
			break;
		case '2':
			do {
				std::cout << "Contrastes en poblaciones normales" << '\n';
				std::cout << "'1' Relativo a la media" << '\n';
				std::cout << "'2' Relativo a la varianza" << '\n';
				std::cout << "'3' Test de la Chi-Cuadrado" << '\n';
				std::cout << "'4' Test de la t de Student" << '\n';
				std::cout << "'0' Volver al menú anterior." << '\n';
				std::cout << "> ";
				std::cin >> eleccionNivel3;
				switch(eleccionNivel3) {
				case '1':
					do {
						std::cout << "'1' Sigma conocida" << '\n';
						std::cout << "'2' Sigma desconocida" << '\n';
						std::cout << "'0' Volver al menú anterior." << '\n';
						std::cout << "> ";
						std::cin >> eleccionNivel4;
						switch(eleccionNivel4) {
						case '1':
							std::cout << "Sigma conocida" << '\n';
							variableX.media1MuestraSigmaConocida();
							break;
						case '2':
							variableX.media1MuestraSigmaDesconocida();
							break;
						}
					} while(eleccionNivel4 != '0');
					break;
				case '2':
					do {
						std::cout << "'1' Mu conocida" << '\n';
						std::cout << "'2' Mu desconocida" << '\n';
						std::cout << "'0' Volver al menú anterior." << '\n';
						std::cout << "> ";
						std::cin >> eleccionNivel4;
						switch(eleccionNivel4) {
						case '1':
							variableX.var1MuestraMuConocida();
							break;
						case '2':
							variableX.var1MuestraMuDesconocida();
							break;
						}
					} while(eleccionNivel4 != '0');
					break;
				}
			} while(eleccionNivel3 != '0');
			break;
		}
	} while(eleccionNivel2 != '0');
	variableX.destructorVector();
}


