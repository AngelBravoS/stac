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
#include <fstream>
#include "matriz.hpp"

//======== funciones de matrices ========

Matriz::Matriz() {}

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

void Matriz::verificarArchivo() {
	std::fstream archivo;
	archivo.open("datos.dat", std::ios::in | std::ios::binary);
	if(archivo.is_open()) {
		std::cout << "Fichero leído" << '\n';
	} else {
		std::cout << "Fichero inexistente" << '\n';
		exit(-1);
	}
	archivo.close();
}

void Matriz::desdeDondeLeeMatriz() {
	crearMatrizVacia();
	if(leerDesdeArchivo == true) {
		verificarArchivo();
		leerDatosDesdeArchivo();
	} else {
		editarMatrizVacia();
	}
}

void Matriz::leerDatosDesdeArchivo() {
	std::fstream archivo;
	archivo.open("datos.dat", std::ios::in | std::ios::binary);
	unsigned int n = columna;
	unsigned int i = 0, j = 0;
	while(!archivo.eof()) {
		archivo >> matriz[i][j];
		j++; //avanza en la fila
		i += j / n; //si pasó de N, le suma a 1 a i (siguiente columna)
		j = j % n; //se asegura que esté entre 0 y N-1
	}
	archivo.close();
}

void Matriz::guardarEnArchivo() {
	std::cout << "Aún no disponible" << '\n';
	std::ofstream archivoSalida("resultado.dat");
	//archivoSalida << traza();
	archivoSalida.close();
}

void Matriz::crearMatrizVacia() {
	matriz = new double *[fila];
	for(unsigned int i = 0; i < fila; i++)     {
		matriz[i] = new double [columna];
	}
	setMatriz(matriz);
}

void Matriz::crearMatrizVaciaB() {
	matrizB = new double *[filaB];
	for(unsigned int i = 0; i < filaB; i++)     {
		matrizB[i] = new double [columnaB];
	}
	setMatrizB(matrizB);
}

void Matriz::editarMatrizVacia() {
	for(unsigned int i = 0; i < fila; i++) {
		for(unsigned int j = 0; j < columna; j++) {
			std::cout << "Elemento " << i + 1 << "," << j + 1 << ": ";
			std::cin >> matriz[i][j];
		}
	}
	std::cout << '\n';
}

void Matriz::copiarDimensionMatriz() {
	matrizB = new double *[fila];
	for(unsigned int i = 0; i < fila; i++)     {
		matrizB[i] = new double[columna];
	}
}

void Matriz::copiarMatriz() {
	for(unsigned int i = 0; i < fila; i++) {
		for(unsigned int j = 0; j < columna; j++) {
			matrizB[i][j] = matriz[i][j];
		}
	}
}

void Matriz::mostrarMatriz() {
	std::cout << '\n';
	for(unsigned int i = 0; i < fila; i++) {
		std::cout << "( ";
		for(unsigned int j = 0; j < columna; j++) {
			std::cout << matriz[i][j] << " ";
		}
		std::cout << ")";
		std::cout << '\n';
	}
}

void Matriz::mostrarMatrizB() {
	std::cout << '\n';
	for(unsigned int i = 0; i < filaB; i++) {
		std::cout << "( ";
		for(unsigned int j = 0; j < columnaB; j++) {
			std::cout << matrizB[i][j] << " ";
		}
		std::cout << ")";
		std::cout << '\n';
	}
}
