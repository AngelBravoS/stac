/***************************************************************************														*
 *   Copyright (C) 2018 by Ángel Bravo Sáenz  										*
 *   angelbravosaenz@gmail.com  															*
 *																									*
 *   This file is part of Stac.                                            *
 *                                                                         *
 *   Stac is free software; you can redistribute it and/or modify          *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   Stac is distributed in the hope that it will be useful,               *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with Stac; if not, write to the                                 *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#include <iostream>
#include<fstream>
#include "matriz.hpp"

//======== funciones de matrices ========

unsigned int Matriz::getFila() {
	return fila;
}

void Matriz::setFila(unsigned int filaPublica) {
	fila = filaPublica;
}

unsigned int Matriz::getColumna() {
	return columna;
}

void Matriz::setColumna(unsigned int columnaPublica) {
	columna = columnaPublica;
}

unsigned int Matriz::getFilaB() {
	return filaB;
}

void Matriz::setFilaB(unsigned int filaPublicaB) {
	filaB = filaPublicaB;
}

unsigned int Matriz::getColumnaB() {
	return columnaB;
}

void Matriz::setColumnaB(unsigned int columnaPublicaB) {
	columnaB = columnaPublicaB;
}

double Matriz::getMatriz() {
	return **matriz;
}

void Matriz::setMatriz(double **matrizPublica) {
	**matriz = **matrizPublica;
}

double Matriz::getMatrizB() {
	return **matrizB;
}

void Matriz::setMatrizB(double **matrizBPublica) {
	**matrizB = **matrizBPublica;
}

void Matriz::leerMatrizArchivo() {
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
		mostrarMatriz();
		std::cout << '\n';
		archivo.close();
	} else std::cout << "Fichero inexistente" << '\n';
}

void Matriz::guardarEnArchivo() {
	std::cout << "Aún no disponible" << '\n';
	std::ofstream archivoSalida("resultado.dat");
	//archivoSalida << traza();
	archivoSalida.close();
}

void Matriz::setDimensionMatriz() {
	unsigned int m, n;
	std::cout << "Número de filas: ";
	std::cin >> m;
	setFila(m);
	std::cout << "Número de columnas: ";
	std::cin >> n;
	setColumna(n);
	std::cout << "la nueva matriz es de " << getFila() << "x" << getColumna() << '\n';
}

void Matriz::crearMatrizVacia() {
	matriz = new double *[getFila()];
	for(unsigned int i = 0; i < getFila(); i++)     {
		matriz[i] = new double [getColumna()];
	}
	setMatriz(matriz);
}

void Matriz::crearMatrizVaciaB() {
	matrizB = new double *[getFilaB()];
	for(unsigned int i = 0; i < getFilaB(); i++)     {
		matrizB[i] = new double [getColumnaB()];
	}
	setMatrizB(matrizB);
}

void Matriz::editarMatrizVacia() {
	for(unsigned int i = 0; i < getFila(); i++) {
		for(unsigned int j = 0; j < getColumna(); j++) {
			std::cout << "Elemento " << i + 1 << "," << j + 1 << ": ";
			std::cin >> matriz[i][j];
		}
	}
	std::cout << '\n';
}

void Matriz::copiarDimensionMatriz() {
	matrizB = new double *[getFila()];
	for(unsigned int i = 0; i < getFila(); i++)     {
		matrizB[i] = new double[getColumna()];
	}
}

void Matriz::copiarMatriz() {
	for(unsigned int i = 0; i < getFila(); i++) {
		for(unsigned int j = 0; j < getColumna(); j++) {
			matrizB[i][j] = matriz[i][j];
		}
	}
}

void Matriz::mostrarMatriz() {
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

void Matriz::mostrarMatrizB() {
	std::cout << '\n';
	for(unsigned int i = 0; i < getFilaB(); i++) {
		std::cout << "( ";
		for(unsigned int j = 0; j < getColumnaB(); j++) {
			std::cout << matrizB[i][j] << " ";
		}
		std::cout << ")";
		std::cout << '\n';
	}
}
