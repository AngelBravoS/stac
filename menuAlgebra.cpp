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

void MenuAlgebra::menuSecundario() {
	char elegir1o2Matrices;
	do {
		std::cout << "'1' Cálculos con una matriz" << '\n';
		std::cout << "'2' Cálculos con dos matrices" << '\n';
		std::cout << "'0' Salir al menú principal." << '\n';
		std::cout << "> ";
		std::cin >> elegir1o2Matrices;
		if (elegir1o2Matrices == '1') {
			menu1Matriz();
			}
		else if (elegir1o2Matrices == '2') {
			menu2Matrices();
			}
		}
	while (elegir1o2Matrices != '0');
	}

void MenuAlgebra::menu1Matriz() { //Descomponer en 2 funciones
	char opcionElegida;
	CalculosAlgebra matrizA(preguntarDesdeArchivoOTeclado(),
									preguntarNumeroFilas(), preguntarNumeroColumnas());
	matrizA.desdeDondeLeeMatriz();
	do {
		std::cout << '\n';
		std::cout << "Matriz A" << '\n';
		matrizA.mostrarMatriz();
		std::cout << '\n';
		listadOpciones1Matriz();
		std::cin >> opcionElegida;
		std::cout << '\n';
		switch (opcionElegida) {
			case '1':
				std::cout << "La traza de la matriz A es: " <<
							 matrizA.traza() << '\n';
				break;
			case '2':
				std::cout << "El determinante de la matriz A es: " <<
							 matrizA.determinante() << '\n';
				break;
			case '3':
				std::cout << "La matriz traspuesta de A es: " << '\n';
				matrizA.traspuesta();
				std::cout << '\n';
				break;
			case '4':
				std::cout << "La matriz A por Gauss es : " << '\n';
				matrizA.gauss();
				std::cout << '\n';
				break;
			case '5':
				std::cout << "La matriz adjunta de A es: " << '\n';
				std::cout << '\n';
				matrizA.adjunta();
				std::cout << '\n';
				break;
			case '6':
				std::cout << "La matriz inversa de A es: " << '\n';
				std::cout << '\n';
				matrizA.inversa();
				std::cout << '\n';
				break;
			case '7':
				std::cout << "La matrices L y U son : " << '\n';
				matrizA.descomposicionLU();
				std::cout << '\n';
				break;
			case '8':
				std::cout << "Métodos numéricos aún no disponibles : " << '\n';
				std::cout << '\n';
				break;
			}
		}
	while (opcionElegida != '0');
	}

void bucleOpciones1Matriz() {
	
}	

void MenuAlgebra::menu2Matrices() {
	char opcionElegida;
	std::cout << "Matriz A" << '\n';
	CalculosAlgebra matrizA(preguntarDesdeArchivoOTeclado(),
									preguntarNumeroFilas(), preguntarNumeroColumnas());
	std::cout << '\n';
	
	matrizA.desdeDondeLeeMatriz();
	std::cout << "Matriz B" << '\n';
	CalculosAlgebra matrizB(preguntarDesdeArchivoOTeclado(),
									preguntarNumeroFilas(), preguntarNumeroColumnas());
	std::cout << '\n';
	
	matrizB.desdeDondeLeeMatriz();
	do {
		std::cout << '\n';
		std::cout << "Matriz A" << '\n';
		matrizA.mostrarMatriz();
		std::cout << '\n';
		std::cout << '\n';
		std::cout << "Matriz B" << '\n';
		matrizB.mostrarMatriz();
		std::cout << '\n';
		listadOpciones2Matrices();
		std::cin >> opcionElegida;
		std::cout << '\n';
		switch (opcionElegida) {
			case '1':
				std::cout << "Suma matricial de A y B" << '\n';
				std::cout << '\n';
				matrizA.sumaDeMatrices();
				break;
			case '2':
				std::cout << "Multiplicación matricial de A y B" << '\n';
				std::cout << '\n';
				matrizA.multiplicacionDeMatrices();
				break;
			case '3':
				std::cout << "Matriz de Kronecker de A y B" << '\n';
				std::cout << '\n';
				matrizA.Kronecker();
				break;
			}
		//std::cout << eleccionCalculosMatrices << '\n';
		}
	while (opcionElegida != '0');


	//CalculosAlgebra matrizResuelta;
	/*
	 *

	matrizResuelta.setDimensionMatriz();
	matrizResuelta.crearMatrizVacia();
	matrizResuelta.editarMatrizVacia();
	matrizA.mostrarMatriz();



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
	std::cout << "¿Copiar el resultado a un archivo?" << '\n';*/
	}

