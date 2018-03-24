#include <iostream>
#include<fstream>
#include "funcDatosBasicas.hpp"

//======== funciones de vectores ========

unsigned int  FuncDatosBasicas::getLongitudVector() {
	return longitudVector;
}

void FuncDatosBasicas::setLongitudVector(unsigned int longitudVectorPublico) {
	longitudVector = longitudVectorPublico;
}

double FuncDatosBasicas::getVector() {
	return *vector;
}

void FuncDatosBasicas::setVector(double *vectorPublico) {
	*vector = *vectorPublico;
}

double FuncDatosBasicas::getVectorCopia() {
	return *vectorCopia;
}

void FuncDatosBasicas::setVectorCopia(double vectorCopiaPublico) {
	*vectorCopia = vectorCopiaPublico;
}

void FuncDatosBasicas::leerVectorArchivo() {
	std::fstream archivo;
	archivo.open("vector.dat", std::ios::in | std::ios::binary);
	if(archivo.is_open()) {
		std::cout << "Fichero leído" << '\n';
		std::cout << "Número de elementos: ";
		numElementosVector();
		crearVectorVacio();
		int n = getLongitudVector();
		for(int i = 0; i < n; i++) {
			archivo >> vector[i];
		}
		archivo.close();
	} else {
		std::cout << "Fichero inexistente" << '\n';
	}
}

void FuncDatosBasicas::numElementosVector() {
	int n;
	std::cin >> n;
	setLongitudVector(n);
}

void FuncDatosBasicas::crearVectorVacio() {
	vector = new double [getLongitudVector()];
	setVector(vector);
}

void FuncDatosBasicas::editarVectorVacio() {
	for(unsigned int i = 0; i < getLongitudVector(); i++) {
		std::cout << "Elemento " << i + 1  << ": ";
		std::cin >> vector[i];
	}
	std::cout << '\n';
}

void FuncDatosBasicas::mostrarVector() {
	std::cout << "( ";
	for(unsigned int i = 0; i < getLongitudVector(); i++) {
		std::cout << vector[i] << " ";
	}
	std::cout << ")";
	std::cout << '\n';
	
}

void FuncDatosBasicas::copiarvector() {
	vectorCopia = new double [getLongitudVector()];
	for(unsigned int i = 0; i < getLongitudVector(); i++)     {
		vectorCopia[i] = vector[i];
	}
}

void FuncDatosBasicas::mostrarVectorCopia() {
	std::cout << "( ";
	for(unsigned int i = 0; i < getLongitudVector(); i++) {
		std::cout << vectorCopia[i] << " ";
	}
	std::cout << ")";
	std::cout << '\n';
}

void FuncDatosBasicas::destructorVector() {
	delete vector;
}

void FuncDatosBasicas::destructorVectorCopia() {
	delete vectorCopia;
}

//======== funciones de matrices ========

unsigned int FuncDatosBasicas::getFila() {
	return fila;
}

void FuncDatosBasicas::setFila(unsigned int filaPublica) {
	fila = filaPublica;
}

unsigned int FuncDatosBasicas::getColumna() {
	return columna;
}

void FuncDatosBasicas::setColumna(unsigned int columnaPublica) {
	columna = columnaPublica;
}

double FuncDatosBasicas::getMatriz() {
	return **matriz;
}

void FuncDatosBasicas::setMatriz(double **matrizPublica) {
	**matriz = **matrizPublica;
}

double FuncDatosBasicas::getMatrizCopia() {
	return **copiaDeMatriz;
}

void FuncDatosBasicas::setMatrizCopia(double **copiaDeMatrizPublica) {
	**copiaDeMatriz = **copiaDeMatrizPublica;
}

void FuncDatosBasicas::leerMatrizArchivo() {
	std::fstream archivo;
	archivo.open("datosMatriz.dat", std::ios::in | std::ios::binary);
	if(archivo.is_open()) {
		std::cout << "Fichero leído" << '\n';
		setDimensionMatriz();
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
		std::cout << '\n';
		archivo.close();
	} else std::cout << "Fichero inexistente" << '\n';
}

void FuncDatosBasicas::guardarEnArchivo() {
	std::cout << "Aún no disponible" << '\n';
	std::ofstream archivoSalida("resultado.dat");
	//archivoSalida << traza();
	archivoSalida.close();
}

void FuncDatosBasicas::setDimensionMatriz() {
	unsigned int m, n;
	std::cout << "Número de filas: ";
	std::cin >> m;
	setFila(m);
	std::cout << "Número de columnas: ";
	std::cin >> n;
	setColumna(n);
	std::cout << "la nueva matriz es de " << getFila() << "x" << getColumna() << '\n';
}

void FuncDatosBasicas::crearMatrizVacia() {
	matriz = new double *[getFila()];
	for(unsigned int i = 0; i < getFila(); i++)     {
		matriz[i] = new double [getColumna()];
	}
	setMatriz(matriz);
}

void FuncDatosBasicas::editarMatrizVacia() {
	for(unsigned int i = 0; i < getFila(); i++) {
		for(unsigned int j = 0; j < getColumna(); j++) {
			std::cout << "Elemento " << i + 1 << "," << j + 1 << ": ";
			std::cin >> matriz[i][j];
		}
	}
	std::cout << '\n';
}

void FuncDatosBasicas::copiarMatriz() {
	copiaDeMatriz = new double *[getFila()];
	for(unsigned int i = 0; i < getFila(); i++)     {
		copiaDeMatriz[i] = new double[getColumna()];
	}
}

void FuncDatosBasicas::mostrarMatrizOriginal() {
	//std::cout << "la matriz es:" << '\n';
	std::cout << '\n';
	for(unsigned int i = 0; i < getFila(); i++) {
		std::cout << "( ";
		for(unsigned int j = 0; j < getColumna(); j++) {
			std::cout << matriz[i][j] << " ";
		}
		std::cout << ")";
		std::cout << '\n';
	}
}

void FuncDatosBasicas::mostrarMatrizCopia() {
	std::cout << '\n';
	for(unsigned int i = 0; i < getFila(); i++) {
		std::cout << "( ";
		for(unsigned int j = 0; j < getColumna(); j++) {
			std::cout << copiaDeMatriz[i][j] << " ";
		}
		std::cout << ")";
		std::cout << '\n';
	}
}
