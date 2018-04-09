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
#include <cmath>
#include<fstream>
#include "calculosMuestreo.hpp"

//Límite máximo en unsigned short int: 65535
//Límite máximo en unsigned int: 4.294.967.295

char CalculosMuestreo::getTipoMuestreo() {
	return tipoMuestreo;
}

void CalculosMuestreo::setTipoMuestreo(char tipoMuestreoPublico) {
	tipoMuestreo = tipoMuestreoPublico;
}

bool CalculosMuestreo::getAgrupados() {
	return agrupados;
}

void CalculosMuestreo::setAgrupados(bool agrupadosPublico) {
	agrupados = agrupadosPublico;
}

bool CalculosMuestreo::getLeeArchivo() {
	return leeArchivo;
}

void CalculosMuestreo::setLeeArchivo(bool leeArchivoPublico) {
	leeArchivo = leeArchivoPublico;
}

bool CalculosMuestreo::getReemplazo() {
	return reemplazo;
}

void CalculosMuestreo::setReemplazo(bool reemplazoPublico) {
	reemplazo = reemplazoPublico;
}

bool CalculosMuestreo::getProbIguales() {
	return probIguales;
}

void CalculosMuestreo::setProbIguales(bool probIgualesPublico) {
	probIguales = probIgualesPublico;
}

bool CalculosMuestreo::getMismoTamanyo() {
	return mismoTamanyo;
}

void CalculosMuestreo::setMismoTamanyo(bool mismoTamanyoPublico) {
	mismoTamanyo = mismoTamanyoPublico;
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

void CalculosMuestreo::editarMatrizVacia() {
	for(unsigned int i = 0; i < getFila(); i++) {
		for(unsigned int j = 0; j < getColumna(); j++) {
			std::cout << "Elemento " << i + 1 << "," << j + 1 << ": ";
			std::cin >> matriz[i][j];
		}
	}
	std::cout << '\n';
}

void CalculosMuestreo::desagrupar() {
	double n;
	int x = 0; //entender por qué así funciona.
	double totalElementos = calculoSumatoria(1, 1);
	setFilaB(getFila());
	setColumnaB(convierteDoubleEnInt(totalElementos));
	crearMatrizVaciaB();
	for(unsigned int j = 0; j < getColumna(); j++) {
		n = matriz[1][j];
		for(unsigned int i = 0; i < n; i++) {
			matrizB[0][x] = matriz[0][j];
			x++;
		}
	}
	// incluir operador ternario para Probabilidades desiguales
	for(unsigned int k = 0; k < totalElementos; k++) {
		matrizB[1][k] = 1;
		matrizB[2][k] = 1 / totalElementos;
		matrizB[3][k] = matrizB[0][k] * matrizB[1][k];
		matrizB[4][k] = matrizB[3][k] * matrizB[3][k];
	}
	std::cout << "matrices no mostradas en la versión final" << '\n';
	mostrarMatriz();
	mostrarMatrizB();
}

// añade ∑Xi Y ∑Xi2
void CalculosMuestreo::incorporarXiYXi2() {
	int i = getFila();
	for(unsigned int j = 0; j < getColumna(); j++) {
		matriz[i - 2][j] = matriz[0][j] * matriz[1][j];
		matriz[i - 1][j] = matriz[i - 2][j] * matriz[i - 2][j];
	}
}

void CalculosMuestreo::leerDatosDesdeArchivo() {
	std::fstream archivo;
	archivo.open("datos.dat", std::ios::in | std::ios::binary);
	int n = getColumna();
	double prob = (double) n;
	if(agrupados == true) {
		if(probIguales == true) { // Probabilidades iguales y datos agrupados
			unsigned int i = 0, j = 0;
			while(!archivo.eof()) {
				archivo >> matriz[i][j];
				j++; //avanza en la fila
				i += j / n; //si pasó de N, le suma a 1 a i (siguiente columna)
				j = j % n; //se asegura que esté entre 0 y N-1
			}
			for(int k = 0; k < n; k++) {
				matriz[2][k] = 1 / prob;
			}
			desagrupar();
		} else {// Probabilidades desiguales y datos agrupados
			unsigned int i = 0, j = 0;
			while(!archivo.eof()) {
				archivo >> matriz[i][j];
				j++; //avanza en la fila
				i += j / n; //si pasó de N, le suma a 1 a i (siguiente columna)
				j = j % n; //se asegura que esté entre 0 y N-1
			}
			desagrupar();
		}
	} else {
		if(probIguales == true) { //Probabilidades iguales y datos desagrupados
			for(int j = 0; j < n; j++) {
				archivo >> matriz[0][j];
				matriz[1][j] = 1;
				matriz[2][j] = 1 / prob;
			}
		} else { // Probabilidades desiguales y datos desagrupados => leer directamente
			unsigned int i = 0, j = 0;
			while(!archivo.eof()) {
				archivo >> matriz[i][j];
				j++; //avanza en la fila
				i += j / n; //si pasó de N, le suma a 1 a i (siguiente columna)
				j = j % n; //se asegura que esté entre 0 y N-1
			}
		}
	}
	archivo.close();
}

void CalculosMuestreo::leerDatosDesdeTeclado() {
	int n = getColumna();
	double prob = (double) n;
	for(unsigned int j = 0; j < getColumna(); j++) {
		std::cout << "Elemento " << j + 1 << " de la muestra: ";
		std::cin >> matriz[0][j];
	}
	if(agrupados == true) {
		for(unsigned int j = 0; j < getColumna(); j++) {
			std::cout << "Nº de veces que el elemento " << j + 1 << " de la muestra aparece en ella: ";
			std::cin >> matriz[1][j];
		}
		desagrupar();
	} else {
		for(unsigned int j = 0; j < getColumna(); j++) {
			matriz[1][j] = 1;
		}
	}
	if(probIguales == true) {
		for(unsigned int j = 0; j < getColumna(); j++) {
			matriz[2][j] = 1 / prob;
		}
	} else {
		for(unsigned int j = 0; j < getColumna(); j++) {
			std::cout << "Probabilidad del elemento " << j + 1 << " de la muestra: ";
			std::cin >> matriz[2][j];
		}
	}
}
