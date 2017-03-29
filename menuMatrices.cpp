#include <iostream>
#include "cli.hpp"
#include "matriz.hpp"

using namespace std;

void CLI::menuMatrices() {
	char elegir1o2Matrices, eleccionCalculosMatriz, eligesArchivo;
	do {
		cout << "'1' Cálculos con una matriz" << endl;
		cout << "'2' Cálculos con dos matrices" << endl;
		cout << "'0' Salir." << endl;
		cout << "> ";
		cin >> elegir1o2Matrices;
		switch ( elegir1o2Matrices ) {
			case '1':
				Matriz matrizA;
				cout << "¿Leer desde un archivo?" << endl;
				cout << "s/n:";
				cin >> eligesArchivo;
				if ( eligesArchivo == 'n' ) {
					matrizA.recogerDatosMatriz();
					matrizA.crearMatrizVacia();
					matrizA.editarMatrizVacia();
					matrizA.mostrarMatriz();
					cout << endl;
					}
				else {
					matrizA.leerArchivo();
					}
				do {
					cout << "Cálculos de una matriz" << endl;
					cout << "'1' Traza" << endl;
					cout << "'2' Determinante" << endl;
					cout << "'3' Matriz traspuesta" << endl;
					cout << "'4' Matriz adjunta xxxx GAUSS" << endl;
					cout << "'5' Matriz inversa" << endl;
					cout << "'6' Vectores y valores propios" << endl;
					cout << "'7' Métodos numéricos" << endl;
					cout << "'0' Volver al menú anterior." << endl;
					cout << "> ";
					cin >> eleccionCalculosMatriz;
					cout << endl;
					switch ( eleccionCalculosMatriz ) {
						case '1':
							matrizA.mostrarMatriz();
							cout << endl;
							cout << "La traza de la matriz A es: " <<
							     matrizA.traza() << endl;
							break;
						case '2':
							matrizA.mostrarMatriz();
							cout << endl;
							if ( matrizA.getFila() != matrizA.getColumna() ) {
								cout << "La matriz no es cuadrada. " << endl;
								}
							else {
								cout << endl;
								cout << "El determinante de la matriz A es: " <<
								     matrizA.determinante() << endl;
								}
							break;
						case '3':
							matrizA.mostrarMatriz();
							cout << endl;
							matrizA.traspuesta();
							cout << "La matriz traspuesta de A es: " << endl;
							matrizA.mostrarMatrizResultado();
							break;
						case '4':
							matrizA.mostrarMatriz();
							cout << endl;
							matrizA.gauss();
							cout << "Gauss: " << endl;
							matrizA.mostrarMatrizResultado();
							break;
						case '5':
							matrizA.mostrarMatriz();
							cout << endl;
							matrizA.inversa();
							break;
						case '6':
							//matrizA.vectoresProp();
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
					}
				while ( eleccionCalculosMatriz != '0' );
				break;
			case '2':
				Matriz matrizB;
				matrizB.recogerDatosMatriz();
				matrizB.crearMatrizVacia();
				matrizB.editarMatrizVacia();
				matrizB.mostrarMatriz();
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
					}
				while ( eleccionCalculosMatriz != '0' );
				break;
			}
		}
	while ( elegir1o2Matrices != '0' );
	}
