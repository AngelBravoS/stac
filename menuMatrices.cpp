#include <iostream>
#include "cli.hpp"
#include "calculosMatriz.hpp"

void CLI::menuMatrices() {
	char elegir1o2Matrices, eleccionCalculosMatriz, eligesArchivo;
	do {
		std::cout << "'1' Cálculos con una matriz" << '\n';
		std::cout << "'2' Cálculos con dos matrices" << '\n';
		std::cout << "'0' Salir al menú principal." << '\n';
		std::cout << "> ";
		std::cin >> elegir1o2Matrices;
		switch ( elegir1o2Matrices ) {
			case '1':
				CalculosMatriz matrizA;
				std::cout << "¿Leer desde un archivo?" << '\n';
				std::cout << "s/n:";
				std::cin >> eligesArchivo;
				if ( eligesArchivo == 's' ) {
					matrizA.leerMatrizArchivo();
				} else {
					matrizA.setDimensionMatriz();
					matrizA.crearMatrizVacia();
					matrizA.editarMatrizVacia();
					matrizA.mostrarMatrizOriginal();
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
							matrizA.mostrarMatrizOriginal();
							std::cout << '\n';
							std::cout << "La traza de la matriz A es: " <<
							     matrizA.traza() << '\n';
							break;
						case '2':
							matrizA.mostrarMatrizOriginal();
							std::cout << '\n';
							if ( matrizA.getFila() != matrizA.getColumna() ) {
								std::cout << "La matriz no es cuadrada. " << '\n';
							} else {
								std::cout << "El determinante de la matriz A es: " <<
								     matrizA.determinante() << '\n';
							}
							break;
						case '3':
							matrizA.mostrarMatrizOriginal();
							std::cout << '\n';
							std::cout << "La matriz traspuesta de A es: " << '\n';
							matrizA.traspuesta();
							matrizA.mostrarMatrizCopia();
							std::cout << '\n';
							break;
						case '4':
							matrizA.mostrarMatrizOriginal();
							std::cout << '\n';
							std::cout << "La matriz A por Gauss es : " << '\n';
							matrizA.gauss();
							matrizA.mostrarMatrizCopia();
							std::cout << '\n';
							break;
						case '5':
							matrizA.mostrarMatrizOriginal();
							std::cout << "La matriz adjunta de A es: " << '\n';
							std::cout << '\n';
							matrizA.adjunta();
							break;
						case '6':
							matrizA.mostrarMatrizOriginal();
							std::cout << "La matriz inversa de A es: " << '\n';
							std::cout << '\n';
							matrizA.inversa();
							break;
						case '7':
							matrizA.mostrarMatrizOriginal();
							std::cout << '\n';
							std::cout << "La matrices L y U son : " << '\n';
							matrizA.descomposicionLU();
							std::cout << '\n';
							break;
						case '8':
							matrizA.mostrarMatrizOriginal();
							std::cout << '\n';
							std::cout << "Métodos numéricos aún no disponibles : " << '\n';
							std::cout << '\n';
							break;
					}
					/*if ( eleccionCalculosMatriz != '0' ) {
						std::cout << "¿Copiar el resultado a un archivo?" << endl;
						std::cout << "s/n:";
						std::cin >> eligesArchivo;
						}
					if ( eligesArchivo == 's' ) {
						matrizA.guardarEnArchivo();
						}*/
				} while ( eleccionCalculosMatriz != '0' );
				break;
			case '2':
				CalculosMatriz matrizB;
				matrizB.setDimensionMatriz();
				matrizB.crearMatrizVacia();
				matrizB.editarMatrizVacia();
				matrizA.mostrarMatrizOriginal();
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
	} while ( elegir1o2Matrices != '0' );
}
