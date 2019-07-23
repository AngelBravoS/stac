/***************************************************************************
 *   Copyright (C) 2018 by Ángel Bravo Sáenz                               *
 *   angelbravosaenz@gmail.com                                             *
 *                                                                         *
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

Matriz::Matriz(unsigned int longitudFila, unsigned int longitudColumna) {
	filas = longitudFila;
	columnas = longitudColumna;
}

void Matriz::verificarArchivo() {
	std::fstream archivo;
	archivo.open("datos.dat", std::ios::in | std::ios::binary);
	if (archivo.is_open()) {
		std::cout << "Fichero leído" << '\n';
		}
	else {
		std::cout << "Fichero inexistente" << '\n';
		exit(-1);
		}
	archivo.close();
	}

void Matriz::desdeDondeLeeMatriz() {
	crearMatrizVacia();
	if (desdeArchivo == true) {
		verificarArchivo();
		leerDesdeArchivo();
		}
	else {
		editarMatrizVacia();
		}
	}

void Matriz::leerDesdeArchivo() {
	std::fstream archivo;
	archivo.open("datos.dat", std::ios::in | std::ios::binary);
	unsigned int n = columnas;
	unsigned int i = 0, j = 0;
	while (!archivo.eof()) {
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
	matriz = new double *[filas];
	for (unsigned int i = 0; i < filas; i++)     {
		matriz[i] = new double [columnas];
		}
	}

void Matriz::crearMatrizVaciaB() {
	matrizB = new double *[filasDeB];
	for (unsigned int i = 0; i < filasDeB; i++)     {
		matrizB[i] = new double [columnasDeB];
		}
	}

void Matriz::editarMatrizVacia() {
	for (unsigned int i = 0; i < filas; i++) {
		for (unsigned int j = 0; j < columnas; j++) {
			std::cout << "Elemento " << i + 1 << "," << j + 1 << ": ";
			std::cin >> matriz[i][j];
			}
		}
	std::cout << '\n';
	}

void Matriz::copiarDimensionMatriz() {
	matrizB = new double *[filas];
	for (unsigned int i = 0; i < filas; i++)     {
		matrizB[i] = new double[columnas];
		}
	}

void Matriz::copiarMatrizA() {
	crearMatrizVaciaB();
	for (unsigned int i = 0; i < filas; i++) {
		for (unsigned int j = 0; j < columnas; j++) {
			matrizB[i][j] = matriz[i][j];
			}
		}
	}

void Matriz::copiarMatrizB() {
	for (unsigned int i = 0; i < filasDeB; i++) {
		for (unsigned int j = 0; j < columnasDeB; j++) {
			matriz[i][j] = matrizB[i][j];
			}
		}
	}

void Matriz::mostrarMatriz() {
	std::cout << '\n';
	for (unsigned int i = 0; i < filas; i++) {
		std::cout << "( ";
		for (unsigned int j = 0; j < columnas; j++) {
			std::cout << matriz[i][j] << " ";
			}
		std::cout << ")";
		std::cout << '\n';
		}
	}

void Matriz::mostrarMatrizB() {
	std::cout << '\n';
	for (unsigned int i = 0; i < filasDeB; i++) {
		std::cout << "( ";
		for (unsigned int j = 0; j < columnasDeB; j++) {
			std::cout << matrizB[i][j] << " ";
			}
		std::cout << ")";
		std::cout << '\n';
		}
	}
