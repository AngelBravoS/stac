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
#include "menuAlgebra.hpp"

bool MenuAlgebra::desdeArchivoOTeclado() {
	char opcion;
	bool eligesArchivo;
	std::cout << "¿Leer desde un archivo?" << '\n';
	std::cout << "s/n:";
	std::cin >> opcion;
	opcion == 's'? eligesArchivo = true: eligesArchivo = false;
	return eligesArchivo;
}

void MenuAlgebra::menuSecundario() {
	/*char elegir1o2Matrices, eleccionCalculosMatriz, eligesArchivo;
	do {
		std::cout << "'1' Cálculos con una matriz" << '\n';
		std::cout << "'2' Cálculos con dos matrices" << '\n';
		std::cout << "'0' Salir al menú principal." << '\n';
		std::cout << "> ";
		std::cin >> elegir1o2Matrices;
		switch ( elegir1o2Matrices ) {
			case '1': {
				CalculosAlgebra matrizA;
				std::cout << "¿Leer desde un archivo?" << '\n';
				std::cout << "s/n:";
				std::cin >> eligesArchivo;
				if ( eligesArchivo == 's' ) {
					matrizA.leerArchivo();
				} else {
					matrizA.setDimensionMatriz();
					matrizA.crearMatrizVacia();
					matrizA.editarMatrizVacia();
					matrizA.mostrarMatriz();
					std::cout << '\n';
				}
				do {
					std::cout << "Cálculos de una matriz" << '\n';
					std::cout << "'1' Traza" << '\n';
					std::cout << "'2' Determinante" << '\n';
					std::cout << "'3' Matriz traspuesta" << '\n';
					std::cout << "'4' Método de Gauss" << '\n';
					std::cout << "'5' Matriz adjunta" << '\n';
					std::cout << "'6' Matriz inversa" << '\n';
					std::cout << "'7' Descomposición LU" << '\n';
					std::cout << "'8' Métodos numéricos" << '\n';
					std::cout << "'0' Volver al menú anterior." << '\n';
					std::cout << "> ";
					std::cin >> eleccionCalculosMatriz;
					std::cout << '\n';
					switch ( eleccionCalculosMatriz ) {
						case '1':
							matrizA.mostrarMatriz();
							std::cout << '\n';
							std::cout << "La traza de la matriz A es: " <<
							     matrizA.traza() << '\n';
							break;
						case '2':
							matrizA.mostrarMatriz();
							std::cout << '\n';
							if ( matrizA.getFila() != matrizA.getColumna() ) {
								std::cout << "La matriz no es cuadrada. " << '\n';
							} else {
								std::cout << "El determinante de la matriz A es: " <<
								     matrizA.determinante() << '\n';
							}
							break;
						case '3':
							matrizA.mostrarMatriz();
							std::cout << '\n';
							std::cout << "La matriz traspuesta de A es: " << '\n';
							matrizA.traspuesta();
							matrizA.mostrarMatrizB();
							std::cout << '\n';
							break;
						case '4':
							matrizA.mostrarMatriz();
							std::cout << '\n';
							std::cout << "La matriz A por Gauss es : " << '\n';
							matrizA.gauss();
							matrizA.mostrarMatrizB();
							std::cout << '\n';
							break;
						case '5':
							matrizA.mostrarMatriz();
							std::cout << "La matriz adjunta de A es: " << '\n';
							std::cout << '\n';
							matrizA.adjunta();
							break;
						case '6':
							matrizA.mostrarMatriz();
							std::cout << "La matriz inversa de A es: " << '\n';
							std::cout << '\n';
							matrizA.inversa();
							break;
						case '7':
							matrizA.mostrarMatriz();
							std::cout << '\n';
							std::cout << "La matrices L y U son : " << '\n';
							matrizA.descomposicionLU();
							std::cout << '\n';
							break;
						case '8':
							matrizA.mostrarMatriz();
							std::cout << '\n';
							std::cout << "Métodos numéricos aún no disponibles : " << '\n';
							std::cout << '\n';
							break;
					}
					//if ( eleccionCalculosMatriz != '0' ) {
				//		std::cout << "¿Copiar el resultado a un archivo?" << endl;
				//		std::cout << "s/n:";
				//		std::cin >> eligesArchivo;
				//		}
				//	if ( eligesArchivo == 's' ) {
				//		matrizA.guardarEnArchivo();
						//}
				} while ( eleccionCalculosMatriz != '0' );
				break;
			}
			case '2': {
				CalculosAlgebra matrizB;
				matrizB.setDimensionMatriz();
				matrizB.crearMatrizVacia();
				matrizB.editarMatrizVacia();
				matrizA.mostrarMatriz();
				do {
					std::cout << "Cálculos de dos matrices" << '\n';
					std::cout << "'1' Suma" << '\n';
					std::cout << "'2' Multiplicación" << '\n';
					std::cout << "'3' Kronecker" << '\n';
					std::cout << "'0' Menú anterior." << '\n';
					std::cout << "> ";
					std::cin >> eleccionCalculosMatriz;
					switch ( eleccionCalculosMatriz ) {
						case '1':
							//sumaMatrices();
							break;
						case '2':
							//multiplicMatrices();
							break;
						case '3':
							//kronecker();
							break;
					}
					std::cout << "¿Copiar el resultado a un archivo?" << '\n';
				} while ( eleccionCalculosMatriz != '0' );
				break;
			}
		}
	} while ( elegir1o2Matrices != '0' );*/
}
