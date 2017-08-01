#include <iostream>
#include "cli.hpp"
#include "calculosMatriz.hpp"

using namespace std;

void CLI::menuMatrices() {
	char elegir1o2Matrices, eleccionCalculosMatriz, eligesArchivo;
	do {
		cout << "'1' Cálculos con una matriz" << endl;
		cout << "'2' Cálculos con dos matrices" << endl;
		cout << "'0' Salir al menú principal." << endl;
		cout << "> ";
		cin >> elegir1o2Matrices;
		switch ( elegir1o2Matrices ) {
			case '1':
				CalculosMatriz matrizA;
				cout << "¿Leer desde un archivo?" << endl;
				cout << "s/n:";
				cin >> eligesArchivo;
				if ( eligesArchivo == 's' ) {
					matrizA.leerMatrizArchivo();
				} else {
					matrizA.recogerDatosMatriz();
					matrizA.crearMatrizVacia();
					matrizA.editarMatrizVacia();
					matrizA.mostrarMatrizOriginal();
					cout << endl;
				}
				do {
					cout << "Cálculos de una matriz" << endl;
					cout << "'1' Traza" << endl;
					cout << "'2' Determinante" << endl;
					cout << "'3' Matriz traspuesta" << endl;
					cout << "'4' Método de Gauss" << endl;
					cout << "'5' Matriz adjunta" << endl;
					cout << "'6' Matriz inversa" << endl;
					cout << "'7' Descomposición LU" << endl;
					cout << "'8' Métodos numéricos" << endl;
					cout << "'0' Volver al menú anterior." << endl;
					cout << "> ";
					cin >> eleccionCalculosMatriz;
					cout << endl;
					switch ( eleccionCalculosMatriz ) {
						case '1':
							matrizA.mostrarMatrizOriginal();
							cout << endl;
							cout << "La traza de la matriz A es: " <<
							     matrizA.traza() << endl;
							break;
						case '2':
							matrizA.mostrarMatrizOriginal();
							cout << endl;
							if ( matrizA.getFila() != matrizA.getColumna() ) {
								cout << "La matriz no es cuadrada. " << endl;
							} else {
								cout << "El determinante de la matriz A es: " <<
								     matrizA.determinante() << endl;
							}
							break;
						case '3':
							matrizA.mostrarMatrizOriginal();
							cout << endl;
							cout << "La matriz traspuesta de A es: " << endl;
							matrizA.traspuesta();
							matrizA.mostrarMatrizCopia();
							cout << endl;
							break;
						case '4':
							matrizA.mostrarMatrizOriginal();
							cout << endl;
							cout << "La matriz A por Gauss es : " << endl;
							matrizA.gauss();
							matrizA.mostrarMatrizCopia();
							cout << endl;
							break;
						case '5':
							matrizA.mostrarMatrizOriginal();
							cout << "La matriz adjunta de A es: " << endl;
							cout << endl;
							matrizA.adjunta();
							break;
						case '6':
							matrizA.mostrarMatrizOriginal();
							cout << "La matriz inversa de A es: " << endl;
							cout << endl;
							matrizA.inversa();
							break;
						case '7':
							matrizA.mostrarMatrizOriginal();
							cout << endl;
							cout << "La matrices L y U son : " << endl;
							matrizA.descomposicionLU();
							cout << endl;
							break;
						case '8':
							matrizA.mostrarMatrizOriginal();
							cout << endl;
							cout << "Métodos numéricos aún no disponibles : " << endl;
							cout << endl;
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
					cout << "Cálculos de dos matrices" << endl;
					cout << "'1' Suma" << endl;
					cout << "'2' Multiplicación" << endl;
					cout << "'3' Kronecker" << endl;
					cout << "'0' Menú anterior." << endl;
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
					cout << "¿Copiar el resultado a un archivo?" << endl;
				} while ( eleccionCalculosMatriz != '0' );
				break;
		}
	} while ( elegir1o2Matrices != '0' );
}
