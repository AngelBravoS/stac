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

#include <iostream>
#include "menu1Var.hpp"

unsigned int Menu1Var::preguntarNumeroElementos() {
	unsigned int col;
	std::cout << "Número de elementos: ";
	std::cin >> col;
	return col;
}

/*bool Menu1Var::preguntarSiAgrupados(){
	char respuesta;
	bool agrupados;
	std::cout << '\n';
	std::cout << "¿Los datos están agrupados?" << '\n';
	std::cout << "s/n:";
	std::cin >> respuesta;
	respuesta == 's' ? agrupados = true : agrupados = false;
	return agrupados;
}*/

void Menu1Var::menuSecundario() {
	char eleccionNivel2, eleccionNivel3, eleccionNivel4;
	Calculos1Var variable(preguntarDesdeArchivoOTeclado(),
	                      preguntarNumeroElementos());
	variable.desdeDondeLeeVector();
	std::cout << '\n';
	std::cout << "Vector" << '\n';
	variable.mostrarVector();
	do {
		listadOpciones1Variable();
		std::cin >> eleccionNivel2;
		std::cout << "Vector" << '\n';
		variable.mostrarVector();
		std::cout << '\n';
		switch (eleccionNivel2) {
			case '1':
				std::cout << "Sumatorias" << '\n';
				std::cout << "∑Xi = " << variable.sumatoria(1) << " , ∑Xi^2 = " << 
variable.sumatoria(2) << '\n';
				std::cout << '\n';

				std::cout << "Medidas de tendencia central" << '\n';

				std::cout << "Medias" << '\n';
				std::cout << "_" << '\n';
				std::cout << "Xa = " << variable.mediaAritmetica() << '\n';
				std::cout << "_" << '\n';
				std::cout << "Xg = " << variable.mediaGeometrica() << '\n';
				std::cout << "_" << '\n';
				std::cout << "Xa = " << variable.mediaArmonica() << '\n';
				std::cout << "_" << '\n';
				std::cout << "Xc = " << variable.mediaCuadratica() << '\n';
				std::cout << '\n';

				std::cout << "Innecesario en la versión final" << '\n';
				std::cout << "Diferencias respecto a la media ^2 = " << 
variable.difRespecMedia(2) << '\n';
				std::cout << "Diferencias respecto a la media ^3 = " << 
variable.difRespecMedia(3) << '\n';
				std::cout << "Momentos centrados de orden 2 (Varianza) = " << 
variable.momentosNoCentrados(2) << '\n';
				std::cout << "Momentos centrados de orden 3 = " << 
variable.momentosNoCentrados(3) << '\n';
				//std::cout << "n * desviacionTipica al cubo" 
				//<< variable.desviacionTipica() << '\n';
				std::cout << '\n';

				std::cout << "Medidas de dispersión" << '\n';

				std::cout << "     _ 2" << '\n';
				std::cout << "∑(Xi-X) = " << variable.difRespecMedia(2) << '\n';

				std::cout << "                _ 2" << '\n';
				std::cout << "           ∑(Xi-X)" << '\n';
				std::cout << "varianza = ------- = "  << variable.varianza() << '\n';
				std::cout << "              1  " << '\n';

				std::cout << "                         _ 2" << '\n';
				std::cout << "                    ∑(Xi-X)" << '\n';
				std::cout << "varianza muestral = ------- = "
				          << variable.varianzaMuestral() << '\n';
				std::cout << "                     (n-1)  " << '\n';
				std::cout << '\n';
				std::cout << "Desviación típica = sqrt(varianza) = "
				          << variable.desviacionTipica() << '\n';
				std::cout << "Desviación típica muestral = sqrt(varianza muestral) = "
				          << variable.desviacionTipicaMuestral() << '\n';
				std::cout << '\n';
				std::cout << "Coef. variación Pearson = "
				          << variable.coeficientePearson() << '\n';
				std::cout << "Norma = " << variable.norma() << '\n';
				std::cout << "Medidas de forma" << '\n';
				std::cout << "Coef. asímetría de Fisher = "
				          << variable.coeficienteAsimetriaFisher() << '\n';
				std::cout << "Curtosis = " << variable.curtosis() << '\n';
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
					switch (eleccionNivel3) {
						case '1':
							do {
								std::cout << "'1' Sigma conocida" << '\n';
								std::cout << "'2' Sigma desconocida" << '\n';
								std::cout << "'0' Volver al menú anterior." << '\n';
								std::cout << "> ";
								std::cin >> eleccionNivel4;
								switch (eleccionNivel4) {
									case '1':
										std::cout << "Sigma conocida" << '\n';
										variable.media1MuestraSigmaConocida();
										break;
									case '2':
										variable.media1MuestraSigmaDesconocida();
										break;
								}
							} while (eleccionNivel4 != '0');
							break;
						case '2':
							do {
								std::cout << "'1' Mu conocida" << '\n';
								std::cout << "'2' Mu desconocida" << '\n';
								std::cout << "'0' Volver al menú anterior." << '\n';
								std::cout << "> ";
								std::cin >> eleccionNivel4;
								switch (eleccionNivel4) {
									case '1':
										variable.var1MuestraMuConocida();
										break;
									case '2':
										variable.var1MuestraMuDesconocida();
										break;
								}
							} while (eleccionNivel4 != '0');
							break;
					}
				} while (eleccionNivel3 != '0');
				break;
		}
	} while (eleccionNivel2 != '0');
}


