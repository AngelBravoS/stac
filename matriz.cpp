#include <iostream>
#include "matriz.hpp"

using namespace std;

unsigned int Matriz::getFila() {
	return fila;
	}

void Matriz::setFila ( unsigned int filaPublica ) {
	fila = filaPublica;
	}

unsigned int Matriz::getColumna() {
	return columna;
	}

void Matriz::setColumna ( unsigned int columnaPublica ) {
	columna = columnaPublica;
	}

double Matriz::getMatriz() {
	return **matriz;
	}

void Matriz::setMatriz ( double **matrizPublica ) {
	**matriz = **matrizPublica;
	}

double Matriz::getMatrizResultado() {
	return **matrizResultado;
	}

void Matriz::setMatrizResultado ( double **matrizResultadoPublica ) {
	**matrizResultado = **matrizResultadoPublica;
	}

double Matriz::traza() {
	double traza = 0;
	for ( unsigned int i = 0; i < getFila(); i++ ) {
		traza = traza + matriz[i][i];
		}
	return traza;
	}

double  Matriz::determinante() {
	double determinante = 0;
	switch ( getFila() ) {
		case 1:
			determinante = matriz[0][0];
			break;
		case 2://caso base para la recursividad
			determinante = matriz[0][0] * matriz[1][1] - matriz[0][1] * matriz[1][0];
			break;
		case 3://por sarrus
			determinante = ( matriz[0][0] * matriz[1][1] * matriz[2][2] +
			                 matriz[0][2] * matriz[1][0] * matriz[2][1] +
			                 matriz[0][1] * matriz[1][2] * matriz[2][0] ) -
			               ( matriz[0][2] * matriz[1][1] * matriz[2][0] +
			                 matriz[0][1] * matriz[1][0] * matriz[2][2] +
			                 matriz[0][0] * matriz[1][2] * matriz[2][1] );
			break;
		default :
			cout << "El determinante de la matriz A aún no está disponible. " << endl;
			break;
		}
	return determinante;
	}

void Matriz::traspuesta() {
	matrizResultado = new double *[getFila()];
	for ( unsigned int i = 0; i < getFila(); i++ )     {
		matrizResultado[i] = new double[getColumna()];
		}
	for ( unsigned int i = 0; i < getFila(); i++ ) {
		for ( unsigned int j = 0; j < getColumna(); j++ ) {
			matrizResultado[i][j] = matriz[j][i];
			}
		}
	setMatrizResultado ( matrizResultado );
	}

void Matriz::adjunta() {
	}

void Matriz::inversa() {
	if ( determinante() != 0 )
		cout << "La matriz tiene inversa" << endl;
	else
		cout << "La matriz no tiene inversa" << endl;
	}

void Matriz::triangular() {
	/*for ( int i = 1, i <= n, i++ ) {
		if ( matriz[i, i] = 0 ) {
			for ( j = i + 1, j <= n, j++ ) {
				if ( matriz[j, i] != 0 ) {
				k = j:
					}

				}
			}
		}*/
	}

void Matriz::gauss() {
	matrizResultado = new double *[getFila()];
	for ( unsigned int i = 0; i < getFila(); i++ )     {
		matrizResultado[i] = new double [getColumna()];
		}
	/*unsigned int n = getFila();
	for ( unsigned int i = 0; i < n; i++ ) {
		for ( unsigned int j = 0; j < n; j++ ) {
			if ( j < i )
				matriz[i][j] = 0;
			else if ( j == i )
				matriz[i][j] = 1;
			else {
				matriz[i][j] = a[i][j] / l[i][i];
				for ( unsigned int k = 0; k < i; k++ ) {
					matriz[i][j] = matriz[i][j] - ( ( l[i][k] * matriz[k][j] ) / l[i][i] );
					}
				}
			}*/
	setMatrizResultado ( matrizResultado );
	}
