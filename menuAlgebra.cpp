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

#include "cli.hpp"
#include "calculosAlgebra.hpp"

void CLI::menuSecundarioAlgebra() {
	char elegir1o2Matrices;
	do {
		std::cout << "'1' Cálculos con una matriz" << '\n';
		std::cout << "'2' Cálculos con dos matrices" << '\n';
		std::cout << "'0' Salir al menú principal." << '\n';
		std::cout << "> ";
		std::cin >> elegir1o2Matrices;
		if(elegir1o2Matrices == '1') {
			menu1Matriz();
		} else if(elegir1o2Matrices == '2') {
			menu2Matrices();
		}
	} while(elegir1o2Matrices != '0');
}

void CLI::menu1Matriz() {
	char opciones;
	unsigned int filas, columnas;
	filas = numeroFilas();
	columnas = numeroColumnas();
	bool desdeArchivo;
	desdeArchivo = preguntarDesdeArchivoOTeclado();
	Matriz matrizA(filas, columnas);

	if(desdeArchivo == true) {
		verificarArchivo();
		leerDesdeArchivo(matrizA, columnas);
	} else {
		std::cout << "Introduce los elementos uno a uno " << "\n";
		std::cout << "pulsa intro para escribir la fila siguiente" << "\n";
		std::cout << "\n";
		editarMatrizVacia(matrizA);
	}
	std::cout << '\n';
	std::cout << ("Matriz A") << "\n";
	mostrarMatriz(matrizA);
	std::cout << '\n';

	do {
		listadOpciones1Matriz();
		std::cin >> opciones;
		std::cout << ("Matriz A") << "\n";
		mostrarMatriz(matrizA);
		std::cout << '\n';
		switch(opciones) {
		case '1': {
			std::cout << "Traza: " << traza(matrizA) << "\n" ;
			std::cout << '\n';
			break;
		}
		case '2': {

			std::cout << "Determinante: " << determinante(matrizA) << "\n" ;
			std::cout << '\n';
			break;
		}
		case '3': {
			Matriz resultado;
			resultado = traspuesta(matrizA);
			std::cout << ("Matriz A traspuesta ") << "\n";
			mostrarMatriz(resultado);
			std::cout << '\n';
		}
		break;
		case '4': {
			Matriz resultado;
			resultado = adjunta(matrizA);
			std::cout << ("Matriz A adjunta ") << "\n";
			mostrarMatriz(resultado);
			std::cout << '\n';
		}
		break;
		case '5': {
			Matriz resultado;
			resultado = inversa(matrizA);
			std::cout << ("Matriz A inversa ") << "\n";
			mostrarMatriz(resultado);
			std::cout << '\n';
		}
		break;
		case '6': {
			Matriz resultado;
			resultado = descomposicionLU(matrizA, true);
			std::cout << '\n';
			std::cout << ("Matriz L ") << "\n";
			mostrarMatriz(resultado);
			std::cout << '\n';
			resultado = descomposicionLU(matrizA, false);
			std::cout << '\n';
			std::cout << ("Matriz U ") << "\n";
			mostrarMatriz(resultado);
			std::cout << '\n';
		}
		break;
		case '7': {
			Matriz resultado;
			resultado = gauss(matrizA);
			std::cout << ("Matriz A Gauss ") << "\n";
			mostrarMatriz(resultado);
			std::cout << '\n';
		}
		break;
		}
	} while(opciones != '0');
}

void CLI::menu2Matrices() {
	char opciones;
	bool desdeArchivo;

	std::cout << "Matriz A" << "\n";
	Matriz matrizA(numeroFilas(), numeroColumnas());
	desdeArchivo = preguntarDesdeArchivoOTeclado();
	unsigned int valorm = matrizA.ColumnCount();
	if(desdeArchivo == true) {
		verificarArchivo();
		leerDesdeArchivo(matrizA, valorm);
	} else {
		std::cout << "Introduce los elementos uno a uno " << "\n";
		std::cout << "pulsa intro para escribir la fila siguiente" << "\n";
		std::cout << "\n";
		editarMatrizVacia(matrizA);
	}

	std::cout << "Matriz B" << "\n";
	Matriz matrizB(numeroFilas(), numeroColumnas());
	desdeArchivo = preguntarDesdeArchivoOTeclado();
	if(desdeArchivo == true) {
		verificarArchivo();
		unsigned int valorm = matrizB.ColumnCount();
		leerDesdeArchivo(matrizB, valorm);
	} else {
		std::cout << "Introduce los elementos uno a uno " << "\n";
		std::cout << "pulsa intro para escribir la fila siguiente" << "\n";
		std::cout << "\n";
		editarMatrizVacia(matrizB);
	}

	std::cout << '\n';
	std::cout << ("Matriz A") << "\n";
	mostrarMatriz(matrizA);
	std::cout << '\n';

	std::cout << '\n';
	std::cout << ("Matriz B") << "\n";
	mostrarMatriz(matrizB);
	std::cout << '\n';

	do {
		listadOpciones2Matrices();
		std::cin >> opciones;

		std::cout << '\n';
		std::cout << ("Matriz A") << "\n";
		mostrarMatriz(matrizA);
		std::cout << '\n';

		std::cout << '\n';
		std::cout << ("Matriz B") << "\n";
		mostrarMatriz(matrizB);
		std::cout << '\n';

		switch(opciones) {
		case '1': {
			Matriz resultado = matrizA + matrizB;
			mostrarMatriz(resultado);
		}
		break;
		case '2': {
			Matriz resultado = matrizA * matrizB;
			mostrarMatriz(resultado);
		}
		break;
		case '3':
			Matriz resultado;
			resultado=kronecker(matrizA, matrizB);
			mostrarMatriz(resultado);
			break;
		}
		std::cout << '\n';
	} while(opciones != '0');
}

