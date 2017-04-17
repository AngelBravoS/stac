#include <iostream>
#include "calculos2Var.hpp"
#include<fstream>

using namespace std;

void Calculos2Var::leerArchivo() {
	fstream archivo;
	archivo.open ( "datos.dat", ios::in | ios::binary );
	if ( archivo.is_open() ) {
		cout << "Fichero leído" << endl;
		recogerDatosVector();
		crearVectorVacio();
		unsigned int n = getColumna();
		unsigned int i = 0, j = 0;
		while ( !archivo.eof() ) {
			archivo >> vectorBi[i][j];
			j++; //avanza en la fila
			i += j / n; //si pasó de N, le suma a 1 a i (siguiente columna)
			j = j % n; //se asegura que esté entre 0 y N-1
		}
		mostrarVectorOriginal();
		cout << endl;
		archivo.close();
	} else cout << "Fichero inexistente" << endl;
}

void Calculos2Var::guardarEnArchivo() {
	cout << "Estamos trabajando en ellouuu..." << endl;
	ofstream archivoSalida ( "resultado.dat" );
	//archivoSalida << traza();
	archivoSalida.close();
}

void Calculos2Var::recogerDatosVector() {
	unsigned int n;
	cout << "Longitud de las variables X e Y: ";
	cin >> n;
	setColumna ( n );
	setFila ( 2 );
	cout << "variables de longitud " << getColumna() << endl;
}

void Calculos2Var::crearVectorVacio() {
	vectorBi = new double *[getFila()];
	for ( unsigned int i = 0; i < getFila(); i++ )     {
		vectorBi[i] = new double [getColumna()];
	}
	setMatriz ( vectorBi );
}

void Calculos2Var::editarVectorVacio() {
	for ( unsigned int i = 0; i < getFila(); i++ ) {
		for ( unsigned int j = 0; j < getColumna(); j++ ) {
			cout << "Elemento " << i + 1 << "," << j + 1 << ": ";
			cin >> vectorBi[i][j];
		}
	}
	cout << endl;
}

void Calculos2Var::copiarMatriz() {
	copiaDeVectorBi = new double *[getFila()];
	for ( unsigned int i = 0; i < getFila(); i++ )     {
		copiaDeVectorBi[i] = new double[getColumna()];
	}
}

void Calculos2Var::mostrarVectorOriginal() {
	cout << "las variables X e Y son :" << endl;
	cout << endl;
	for ( unsigned int i = 0; i < getFila(); i++ ) {
		cout << "( ";
		for ( unsigned int j = 0; j < getColumna(); j++ ) {
			cout << vectorBi[i][j] << " ";
		}
		cout << ")";
		cout << endl;
	}
}

void Calculos2Var::mostrarCopiaVector() {
	cout << endl;
	for ( unsigned int i = 0; i < getFila(); i++ ) {
		cout << "( ";
		for ( unsigned int j = 0; j < getColumna(); j++ ) {
			cout << copiaDeVectorBi[i][j] << " ";
		}
		cout << ")";
		cout << endl;
	}
}
