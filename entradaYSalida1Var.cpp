#include <iostream>
#include "calculos1Var.hpp"
#include<fstream>

using namespace std;

void Calculos1Var::leerArchivo() {
	fstream archivo;
	archivo.open ( "datos.dat", ios::in | ios::binary );
	if ( archivo.is_open() ) {
		cout << "Fichero leído" << endl;
		recogerDatosVector();
		crearVectorVacio();
		int n = getLongitudVector();
		for ( int i = 0; i < n; i++ ) {
			archivo >> vector[i];
		}
		mostrarVector();
		cout << endl;
		archivo.close();
	} else {
		cout << "Fichero inexistente" << endl;
	}
}

void Calculos1Var::guardarEnArchivo() {
	cout << "Estamos trabajando en ellouuu..." << endl;
	ofstream archivoSalida ( "resultado.dat" );
	//archivoSalida<<traza();
	archivoSalida.close();
}

void Calculos1Var::recogerDatosVector() {
	int n;
	cout << "Número de elementos: ";
	cin >> n;
	setLongitudVector ( n );
	//cout << "la variable X es de " << getLongitudVector() << " elementos" << endl;
}

void Calculos1Var::crearVectorVacio() {
	vector = new double [getLongitudVector()];
	setVector ( vector );
}

void Calculos1Var::editarVectorVacio() {
	for ( unsigned int i = 0; i < getLongitudVector(); i++ ) {
		cout << "Elemento " << i + 1  << ": ";
		cin >> vector[i];
	}
	cout << endl;
}

void Calculos1Var::mostrarVector() {
	cout << "la variable X es:" << endl;
	cout << endl;
	cout << "( ";
	for ( unsigned int i = 0; i < getLongitudVector(); i++ ) {
		cout << vector[i] << " ";
	}
	cout << ")";
	cout << endl;
}

void Calculos1Var::mostrarVectorResultado() {
	for ( unsigned int i = 0; i < getLongitudVector(); i++ ) {
		cout << "( ";
		cout << vectorResultado[i] << " ";
	}
	cout << ")";
	cout << endl;
}

void Calculos1Var::destructorVector() {
	delete vector;
}
