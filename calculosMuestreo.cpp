#include <iostream>
#include <cmath>
#include<fstream>
#include "calculosMuestreo.hpp"

//Límite máximo en unsigned short int: 65535
//Límite máximo en unsigned int: 4.294.967.295

bool CalculosMuestreo::getDatosEstanAgrupados() {
	return datosAgrupados;
}

void CalculosMuestreo::setDatosEstanAgrupados(bool datosAgrupadosPublico) {
	datosAgrupados = datosAgrupadosPublico;
}

bool CalculosMuestreo::getLeeArchivo() {
	return leeArchivo;
}

void CalculosMuestreo::setLeeArchivo(bool leeArchivoPublico) {
	leeArchivo = leeArchivoPublico;
}

int CalculosMuestreo::getTipoMuestreo() {
	return tipoMuestreoElegido;
}

void CalculosMuestreo::setTipoMuestreo(int tipoMuestreoPublico) {
	tipoMuestreoElegido = tipoMuestreoPublico;
}

double CalculosMuestreo::getSumatoriaXi() {
	return sumatoriaXi;
}

void CalculosMuestreo::setSumatoriaXi(double sumatoriaXiPublica) {
	sumatoriaXi = sumatoriaXiPublica;
}

double CalculosMuestreo::getSumatoriaXi2() {
	return sumatoriaXi2;
}

void CalculosMuestreo::setSumatoriaXi2(double sumatoriaXi2Publica) {
	sumatoriaXi2 = sumatoriaXi2Publica;
}

double CalculosMuestreo::getMedia() {
	return media;
}

void CalculosMuestreo::setMedia(double mediaPublica) {
	media = mediaPublica;
}

void CalculosMuestreo::leerVectorArchivo() {
	std::fstream archivo;
	archivo.open("vector.dat", std::ios::in | std::ios::binary);
	if(archivo.is_open()) {
		std::cout << "Fichero leído" << '\n';
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

void CalculosMuestreo::desagrupar() {
	mostrarMatrizOriginal();
	double n;
	int x = 0; //entender por qué así funciona.
	double sumYi = calculoSumatoria(1, 1);
	setLongitudVector(convierteDoubleEnInt(sumYi));
	crearVectorVacio();
	for(unsigned int j = 0; j < getColumna(); j++) {
		n = matriz[1][j];
		for(unsigned int i = 0; i < n; i++) {
			vector[x] = matriz[0][j];
			x++;
		}
	}
	setColumna(getLongitudVector());
}


void CalculosMuestreo::calculoXi() {
	for(unsigned int j = 0; j < getColumna(); j++) {
		matriz[0][j] = vector[j];
	}
}

void CalculosMuestreo::calculoXi2() {
	int i = getFila();
	for(unsigned int j = 0; j < getColumna(); j++) {
		matriz[i - 1][j] = matriz[0][j] * matriz[0][j];
	}
}

void CalculosMuestreo::leerDatosArchivo() {
	std::fstream archivo;
	if(datosAgrupados == true) {
		archivo.open("matriz.dat", std::ios::in | std::ios::binary);
		if(archivo.is_open()) {
			std::cout << "Fichero leído" << '\n';
			setFila(2);
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
	} else {
		archivo.open("vector.dat", std::ios::in | std::ios::binary);
		if(archivo.is_open()) {
			std::cout << "Fichero leído" << '\n';
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
}

void CalculosMuestreo::crearDatosMuestra() {
	int tipoMuestreo = getTipoMuestreo();
	std::cout << "Tamaño de la muestra: ";
	numElementosVector();
	setColumna(getLongitudVector());

	switch(tipoMuestreo) {
	case '1' :
	case '2' :
		setFila(2);
		if(leeArchivo == true) {
			leerDatosArchivo();
			desagrupar();
		}	else if(datosAgrupados == true) {
			crearMatrizVacia();
			editarMatrizVacia();
			desagrupar();
		}	else {
			crearVectorVacio();
			editarVectorVacio();
		}
		break;
	case '3' :
	case '4' :
		setFila(2);
		if(datosAgrupados == true) {
			std::cout << "Tamaño de la muestra: ";
			numElementosVector();
			setColumna(getLongitudVector());
			crearMatrizVacia();
			editarMatrizVacia();
			desagrupar();
		} else {
			if(leeArchivo == true) {
				leerVectorArchivo();
				setColumna(getLongitudVector());
			} else {
				std::cout << "Tamaño de la muestra: ";
				numElementosVector();
				setColumna(getLongitudVector());
				crearVectorVacio();
				editarVectorVacio();
				//mostrarVector();
			}
		}
		//mostrarDatosMuestra();
		break;
	}
}

void CalculosMuestreo::mostrarDatosMuestra() {
	//std::cout << '\n';
	std::cout << "Tabla de datos:" << '\n';
	crearMatrizVacia();
	calculoXi();
	calculoXi2();
	mostrarMatrizOriginal();
	std::cout << '\n';
}


