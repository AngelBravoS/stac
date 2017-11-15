#include <iostream>
#include<fstream>
#include "funcionesDatosBasicas.hpp"

using namespace std;

// Funciones de un vector

unsigned int FuncionesDatosBasicas::getLongitudVector() {
	return longitudVector;
}

void FuncionesDatosBasicas::setLongitudVector(unsigned int longitudVectorPublico) {
	longitudVector = longitudVectorPublico;
}

double FuncionesDatosBasicas::getVector() {
	return *vector;
}

void FuncionesDatosBasicas::setVector(double *vectorPublico) {
	*vector = *vectorPublico;
}

double FuncionesDatosBasicas::getVectorResultado() {
	return *vectorResultado;
}

void FuncionesDatosBasicas::setVectorResultado(double vectorResultadoPublico) {
	*vectorResultado = vectorResultadoPublico;
}

void FuncionesDatosBasicas::leerVectorArchivo() {
	fstream archivo;
	archivo.open("vector.dat", ios::in | ios::binary);
	if(archivo.is_open()) {
		cout << "Fichero leído" << endl;
		recogerDatosVector();
		crearVectorVacio();
		int n = getLongitudVector();
		for(int i = 0; i < n; i++) {
			archivo >> vector[i];
		}
		archivo.close();
	} else {
		cout << "Fichero inexistente" << endl;
	}
}

void FuncionesDatosBasicas::recogerDatosVector() {
	int n;
	cout << "Número de elementos: ";
	cin >> n;
	setLongitudVector(n);
	//cout << "la variable X es de " << getLongitudVector() << " elementos" << endl;
}

void FuncionesDatosBasicas::crearVectorVacio() {
	vector = new double [getLongitudVector()];
	setVector(vector);
}

void FuncionesDatosBasicas::editarVectorVacio() {
	for(unsigned int i = 0; i < getLongitudVector(); i++) {
		cout << "Elemento " << i + 1  << ": ";
		cin >> vector[i];
	}
	cout << endl;
}

void FuncionesDatosBasicas::mostrarVector() {
	cout << "la variable X es:" << endl;
	cout << endl;
	cout << "( ";
	for(unsigned int i = 0; i < getLongitudVector(); i++) {
		cout << vector[i] << " ";
	}
	cout << ")";
	cout << endl;
}

void FuncionesDatosBasicas::mostrarVectorResultado() {
	for(unsigned int i = 0; i < getLongitudVector(); i++) {
		cout << "( ";
		cout << vectorResultado[i] << " ";
	}
	cout << ")";
	cout << endl;
}

void FuncionesDatosBasicas::destructorVector() {
	delete vector;
}

// Funciones de una matriz

unsigned int FuncionesDatosBasicas::getFila() {
	return fila;
}

void FuncionesDatosBasicas::setFila(unsigned int filaPublica) {
	fila = filaPublica;
}

unsigned int FuncionesDatosBasicas::getColumna() {
	return columna;
}

void FuncionesDatosBasicas::setColumna(unsigned int columnaPublica) {
	columna = columnaPublica;
}

double FuncionesDatosBasicas::getMatriz() {
	return **matriz;
}

void FuncionesDatosBasicas::setMatriz(double **matrizPublica) {
	**matriz = **matrizPublica;
}

double FuncionesDatosBasicas::getMatrizCopia() {
	return **copiaDeMatriz;
}

void FuncionesDatosBasicas::setMatrizCopia(double **copiaDeMatrizPublica) {
	**copiaDeMatriz = **copiaDeMatrizPublica;
}

void FuncionesDatosBasicas::leerMatrizArchivo() {
	fstream archivo;
	archivo.open("datosMatriz.dat", ios::in | ios::binary);
	if(archivo.is_open()) {
		cout << "Fichero leído" << endl;
		recogerDatosMatriz();
		crearMatrizVacia();
		unsigned int n = getColumna();
		unsigned int i = 0, j = 0;
		while(!archivo.eof()) {
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

void FuncionesDatosBasicas::guardarEnArchivo() {
	cout << "Estamos trabajando en ellouuu..." << endl;
	ofstream archivoSalida("resultado.dat");
	//archivoSalida << traza();
	archivoSalida.close();
}

void FuncionesDatosBasicas::recogerDatosMatriz() {
	unsigned int m, n;
	cout << "Número de filas: ";
	cin >> m;
	setFila(m);
	cout << "Número de columnas: ";
	cin >> n;
	setColumna(n);
	cout << "la nueva matriz es de " << getFila() << "x" << getColumna() << endl;
}

void FuncionesDatosBasicas::crearMatrizVacia() {
	matriz = new double *[getFila()];
	for(unsigned int i = 0; i < getFila(); i++)     {
		matriz[i] = new double [getColumna()];
	}
	setMatriz(matriz);
}

void FuncionesDatosBasicas::editarMatrizVacia() {
	for(unsigned int i = 0; i < getFila(); i++) {
		for(unsigned int j = 0; j < getColumna(); j++) {
			cout << "Elemento " << i + 1 << "," << j + 1 << ": ";
			cin >> matriz[i][j];
		}
	}
	cout << endl;
}

void FuncionesDatosBasicas::copiarMatriz() {
	copiaDeMatriz = new double *[getFila()];
	for(unsigned int i = 0; i < getFila(); i++)     {
		copiaDeMatriz[i] = new double[getColumna()];
	}
}

void FuncionesDatosBasicas::mostrarMatrizOriginal() {
	cout << "la matriz es:" << endl;
	cout << endl;
	for(unsigned int i = 0; i < getFila(); i++) {
		cout << "( ";
		for(unsigned int j = 0; j < getColumna(); j++) {
			cout << matriz[i][j] << " ";
		}
		cout << ")";
		cout << endl;
	}
}

void FuncionesDatosBasicas::mostrarMatrizCopia() {
	cout << endl;
	for(unsigned int i = 0; i < getFila(); i++) {
		cout << "( ";
		for(unsigned int j = 0; j < getColumna(); j++) {
			cout << copiaDeMatriz[i][j] << " ";
		}
		cout << ")";
		cout << endl;
	}
}
