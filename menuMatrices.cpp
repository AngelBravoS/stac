#include <iostream>
#include "cli.hpp"
#include "calculosMatriz.hpp"

using namespace std;

void CLI::menuMatrices() {
	char elegir1o2Matrices, eleccionCalculosMatriz, eligesArchivo;
	do {
		cout << "'1' Cálculos con una matriz" << '\n';
		cout << "'2' Cálculos con dos matrices" << '\n';
		cout << "'0' Salir al menú principal." << '\n';
		cout << "> ";
		cin >> elegir1o2Matrices;
		switch ( elegir1o2Matrices ) {
			case '1':
				CalculosMatriz matrizA;
				cout << "¿Leer desde un archivo?" << '\n';
				cout << "s/n:";
				cin >> eligesArchivo;
				if ( eligesArchivo == 's' ) {
					matrizA.leerMatrizArchivo();
				} else {
					matrizA.recogerDatosMatriz();
					matrizA.crearMatrizVacia();
					matrizA.editarMatrizVacia();
					matrizA.mostrarMatrizOriginal();
					cout << '\n';
				}
				do {
					cout << "Cálculos de una matriz" << '\n';
					cout << "'1' Traza" << '\n';
					cout << "'2' Determinante" << '\n';
					cout << "'3' Matriz traspuesta" << '\n';
					cout << "'4' Método de Gauss" << '\n';
					cout << "'5' Matriz adjunta" << '\n';
					cout << "'6' Matriz inversa" << '\n';
					cout << "'7' Descomposición LU" << '\n';
					cout << "'8' Métodos numéricos" << '\n';
					cout << "'0' Volver al menú anterior." << '\n';
					cout << "> ";
					cin >> eleccionCalculosMatriz;
					cout << '\n';
					switch ( eleccionCalculosMatriz ) {
						case '1':
							matrizA.mostrarMatrizOriginal();
							cout << '\n';
							cout << "La traza de la matriz A es: " <<
							     matrizA.traza() << '\n';
							break;
						case '2':
							matrizA.mostrarMatrizOriginal();
							cout << '\n';
							if ( matrizA.getFila() != matrizA.getColumna() ) {
								cout << "La matriz no es cuadrada. " << '\n';
							} else {
								cout << "El determinante de la matriz A es: " <<
								     matrizA.determinante() << '\n';
							}
							break;
						case '3':
							matrizA.mostrarMatrizOriginal();
							cout << '\n';
							cout << "La matriz traspuesta de A es: " << '\n';
							matrizA.traspuesta();
							matrizA.mostrarMatrizCopia();
							cout << '\n';
							break;
						case '4':
							matrizA.mostrarMatrizOriginal();
							cout << '\n';
							cout << "La matriz A por Gauss es : " << '\n';
							matrizA.gauss();
							matrizA.mostrarMatrizCopia();
							cout << '\n';
							break;
						case '5':
							matrizA.mostrarMatrizOriginal();
							cout << "La matriz adjunta de A es: " << '\n';
							cout << '\n';
							matrizA.adjunta();
							break;
						case '6':
							matrizA.mostrarMatrizOriginal();
							cout << "La matriz inversa de A es: " << '\n';
							cout << '\n';
							matrizA.inversa();
							break;
						case '7':
							matrizA.mostrarMatrizOriginal();
							cout << '\n';
							cout << "La matrices L y U son : " << '\n';
							matrizA.descomposicionLU();
							cout << '\n';
							break;
						case '8':
							matrizA.mostrarMatrizOriginal();
							cout << '\n';
							cout << "Métodos numéricos aún no disponibles : " << '\n';
							cout << '\n';
							break;
					}
					/*if ( eleccionCalculosMatriz != '0' ) {
						cout << "¿Copiar el resultado a un archivo?" << endl;
						cout << "s/n:";
						cin >> eligesArchivo;
						}
					if ( eligesArchivo == 's' ) {
						matrizA.guardarEnArchivo();
						}*/
				} while ( eleccionCalculosMatriz != '0' );
				break;
			case '2':
				CalculosMatriz matrizB;
				matrizB.recogerDatosMatriz();
				matrizB.crearMatrizVacia();
				matrizB.editarMatrizVacia();
				matrizA.mostrarMatrizOriginal();
				do {
					cout << "Cálculos de dos matrices" << '\n';
					cout << "'1' Suma" << '\n';
					cout << "'2' Multiplicación" << '\n';
					cout << "'3' Kronecker" << '\n';
					cout << "'0' Menú anterior." << '\n';
					cout << "> ";
					cin >> eleccionCalculosMatriz;
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
					cout << "¿Copiar el resultado a un archivo?" << '\n';
				} while ( eleccionCalculosMatriz != '0' );
				break;
		}
	} while ( elegir1o2Matrices != '0' );
}
