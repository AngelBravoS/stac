#include <iostream>
#include "vector.hpp"
#include<fstream>

using namespace std;

void Vector::leerArchivo() {
	fstream archivo;
	archivo.open ( "datos.dat", ios::in | ios::binary );
	if ( archivo.is_open() ) {
		cout << "Fichero leído" << endl;
		recogerDatosVector();
		crearVectorVacio();
		int n = getElementoVector();
		for ( int i = 0; i < n; i++ ) {
			archivo >> vector[i];
			}
		mostrarVector();
		cout << endl;
		archivo.close();
		}
	else cout << "Fichero inexistente" << endl;
	}

void Vector::guardarEnArchivo() {
	cout << "Estamos trabajando en ellouuu..." << endl;
	ofstream archivoSalida ( "resultado.dat" );
	//archivoSalida<<traza();
	archivoSalida.close();
	}

void Vector::recogerDatosVector() {
	int n;
	cout << "Número de elementos: ";
	cin >> n;
	setElementoVector ( n );
	cout << "la variable X es de " << getElementoVector() << " elementos" << endl;
	}

void Vector::crearVectorVacio() {
	vector = new float [getElementoVector()];
	setVector ( vector );
	}

void Vector::editarVectorVacio() {
	for ( unsigned int i = 0; i < getElementoVector(); i++ ) {
		cout << "Elemento " << i + 1  << ": ";
		cin >> vector[i];
		}
	cout << endl;
	}

void Vector::mostrarVector() {
	cout << "la variable X es:" << endl;
	cout << endl;
	cout << "( ";
	for ( unsigned int i = 0; i < getElementoVector(); i++ ) {
		cout << vector[i] << " ";
		}
	cout << ")";
	cout << endl;
	}

void Vector::mostrarVectorResultado() {
	for ( unsigned int i = 0; i < getElementoVector(); i++ ) {
		cout << "( ";
		cout << vectorResultado[i] << " ";
		}
	cout << ")";
	cout << endl;
	}
