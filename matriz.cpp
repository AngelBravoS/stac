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

double Matriz::getMatrizCopia() {
	return **copiaDeMatriz;
}

void Matriz::setMatrizCopia( double **copiaDeMatrizPublica ) {
	**copiaDeMatriz = **copiaDeMatrizPublica;
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
			cout << "Determinantes de orden >3 aún no disponible." << endl;
			break;
	}
	return determinante;
}

void Matriz::traspuesta() {
	copiarMatriz();
	for ( unsigned int i = 0; i < getFila(); i++ ) {
		for ( unsigned int j = 0; j < getColumna(); j++ ) {
			copiaDeMatriz[i][j] = matriz[j][i];
		}
	}
	//mostrarMatriz ( copiaDeMatriz );
	setMatrizCopia(copiaDeMatriz);
}

void Matriz::adjunta() {
}

void Matriz::inversa() {
	if ( determinante() != 0 ) {
		cout << "La matriz tiene inversa" << endl;
	} else {
		cout << "La matriz no tiene inversa" << endl;
	}
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
	copiarMatriz();
}

void Matriz::descomposicionLU() {
	unsigned int const n = getFila();
	unsigned int i, j, k;
	double matrizL [n][n];
	double matrizU [n][n];
	for ( i = 0; i < n; i++ ) {
		for ( j = 0; j < n; j++ ) {
			if ( j < i ) {
				matrizL[j][i] = 0;
			} else {
				matrizL [j][i] = matriz [j][i];
				for ( k = 0; k < i; k++ ) {
					matrizL [j][i] -= ( matrizL [j][k] * matrizU [k][i] );
				}
			}
		}
		for ( j = 0; j < n; j++ ) {
			if ( j < i ) {
				matrizU [i][j] = 0;
			} else if ( j == i ) {
				matrizU [i][j] = 1;
			} else {
				matrizU [i][j] = matriz[i][j] / matrizL [i][i];
				for ( k = 0; k < i; k++ ) {
					matrizU [i][j] -= ( ( matrizL [i][k] * matrizU [k][j] ) / matrizL [i][i] );
				}
			}
		}
	}
	copiarMatriz();
	for ( i = 0; i < n; i++ ) {
		for ( j = 0; j < n; j++ ) {
			copiaDeMatriz[i][j] = matrizL[i][j];
		}
	}
	mostrarMatrizCopia ( );
	for ( i = 0; i < n; i++ ) {
		for ( j = 0; j < n; j++ ) {
			copiaDeMatriz[i][j] = matrizU[i][j];
		}
	}
	mostrarMatrizCopia ( );
}
