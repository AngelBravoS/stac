#include <iostream>
#include "calculosNVar.hpp"
#include<fstream>

using namespace std;

void CalculosNVar::leerArchivo() {
	fstream archivo;
	archivo.open ( "datos.dat", ios::in | ios::binary );
	if ( archivo.is_open() ) {
		cout << "Fichero leído" << endl;
		recogerDatosMatriz();
		crearMatrizVacia();
		unsigned int n = getColumna();
		unsigned int i = 0, j = 0;
		while ( !archivo.eof() ) {
			archivo >> matriz[i][j];
			j++; //avanza en la fila
			i += j / n; //si pasó de N, le suma a 1 a i (siguiente columna)
			j = j % n; //se asegura que esté entre 0 y N-1
		}
		mostrarMatrizOriginal();
		cout << endl;
		archivo.close();
	} else cout << "Fichero inexistente" << endl;
}

void CalculosNVar::guardarEnArchivo() {
	cout << "Estamos trabajando en ellouuu..." << endl;
	ofstream archivoSalida ( "resultado.dat" );
	archivoSalida << traza();
	archivoSalida.close();
}

void CalculosNVar::recogerDatosMatriz() {
	unsigned int m, n;
	cout << "Número de filas: ";
	cin >> m;
	setFila ( m );
	cout << "Número de columnas: ";
	cin >> n;
	setColumna ( n );
	cout << "la nueva matriz es de " << getFila() << "x" << getColumna() << endl;
}

void CalculosNVar::crearMatrizVacia() {
	matriz = new double *[getFila()];
	for ( unsigned int i = 0; i < getFila(); i++ )     {
		matriz[i] = new double [getColumna()];
	}
	setMatriz ( matriz );
}

void CalculosNVar::editarMatrizVacia() {
	for ( unsigned int i = 0; i < getFila(); i++ ) {
		for ( unsigned int j = 0; j < getColumna(); j++ ) {
			cout << "Elemento " << i + 1 << "," << j + 1 << ": ";
			cin >> matriz[i][j];
		}
	}
	cout << endl;
}

void CalculosNVar::copiarMatriz() {
	copiaDeMatriz = new double *[getFila()];
	for ( unsigned int i = 0; i < getFila(); i++ )     {
		copiaDeMatriz[i] = new double[getColumna()];
	}
}

void CalculosNVar::mostrarMatrizOriginal() {
	cout << "la matriz es:" << endl;
	cout << endl;
	for ( unsigned int i = 0; i < getFila(); i++ ) {
		cout << "( ";
		for ( unsigned int j = 0; j < getColumna(); j++ ) {
			cout << matriz[i][j] << " ";
		}
		cout << ")";
		cout << endl;
	}
}

void CalculosNVar::mostrarMatrizCopia ( ) {
	cout << endl;
	for ( unsigned int i = 0; i < getFila(); i++ ) {
		cout << "( ";
		for ( unsigned int j = 0; j < getColumna(); j++ ) {
			cout << copiaDeMatriz[i][j] << " ";
		}
		cout << ")";
		cout << endl;
	}
}
