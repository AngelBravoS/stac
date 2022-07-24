/***************************************************************************
 *   Copyright (C) 2018 by Ángel Bravo Sáenz                               *
 *   angelbravosaenz@gmail.com                                             *
 *                                                                         *
 *   This file is part of Stac.                                            *
 *                                                                         *
 *   Stac is free software; you can redistribute it and/or modify          *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; version 2 of the License.               *
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

#include "calculosNVar.hpp"

double sumatoria (Matriz &m1, unsigned int indiceVariable, short unsigned
                 int exponente) {
	unsigned int n = m1.ColumnCount();
	double resultado = 0;
	for(unsigned int j = 0; j < n; j++) {
		resultado += potencia(m1[indiceVariable][j], exponente);
	}
	return resultado;
}

/*
double total(int indiceVariable) {
	unsigned int n = columnas;
	double resultado = 0;
	resultado = (n* mediaAritmetica(indiceVariable));
	return resultado;
}

double mediaAritmetica(int indiceVariable) {
	unsigned int n = columnas;
	double resultado = 0;
	resultado = ( sumatoria (indiceVariable, 1) / n);
	return resultado;
}

double mediaGeometrica(int indiceVariable) {
	unsigned int n = columnas;
	double mediaGeometrica = 1;
	for(unsigned int j = 0; j < n; j++) {
		mediaGeometrica *= matriz[indiceVariable][j];
	}
	mediaGeometrica = pow(mediaGeometrica, 1.0 / n);
	return mediaGeometrica;
}

double mediaArmonica(int indiceVariable) {
	unsigned int n = columnas;
	double mediaArmonica = 0;
	for(unsigned int j = 0; j < n; j++) {
		mediaArmonica +=  1 / (potencia(matriz[indiceVariable][j], 1));
	}
	mediaArmonica = (n / mediaArmonica);
	return mediaArmonica;
}

double mediaCuadratica(int indiceVariable) {
	unsigned int n = columnas;
	double mediaCuadratica;
	mediaCuadratica = sumatoria (indiceVariable, 2) * (1.0 / n);
	mediaCuadratica = sqrt(mediaCuadratica);
	return mediaCuadratica;
}

//Suma de diferencias respecto a la media con exponente
double difRespecMedia(int indiceVariable, int exponente) {
	unsigned int n = columnas;
	double difRespecMedia = 0;
	for(unsigned int j = 0; j < n; j++) {
		difRespecMedia += pow(matriz[indiceVariable][j] - mediaAritmetica(indiceVariable), exponente);
	}
	return difRespecMedia;
}

double varianza(int indiceVariable) {
	unsigned int n = columnas;
	double resultado;
	resultado = (difRespecMedia(indiceVariable, 2)) / n;
	return resultado;
}

double cuasiVarianza(int indiceVariable) {
	unsigned int n = columnas;
	double resultado;
	resultado = (difRespecMedia(indiceVariable, 2)) / (n - 1);
	return resultado;
}

double desviacionTipica(int indiceVariable) {
	double desviacionTipica;
	desviacionTipica = sqrt(varianza(indiceVariable));
	return desviacionTipica;
}

double CalculosNVar::cuasiDesviacionTipica(int indiceVariable) {
	double cuasiDesviacionTipica;
	cuasiDesviacionTipica = sqrt(cuasiVarianza(indiceVariable));
	return cuasiDesviacionTipica;
}

double CalculosNVar::momentos(int indiceVariable, int exponente) {
	unsigned int n = columnas;
	double momentos;
	momentos = difRespecMedia(indiceVariable, exponente) / n;
	return momentos;
}

double CalculosNVar::coeficientePearson(int indiceVariable) {
	double coeficientePearson;
	coeficientePearson = cuasiDesviacionTipica(indiceVariable) / mediaAritmetica(indiceVariable);
	return coeficientePearson;
}

//funciona MAAAAL
double CalculosNVar::coeficienteAsimetriaFisher(int indiceVariable) {
	double coeficienteAsimetriaFisher;
	coeficienteAsimetriaFisher = (momentos(indiceVariable, 3) / pow(cuasiDesviacionTipica(indiceVariable), 3));
	return coeficienteAsimetriaFisher;
}

double CalculosNVar::curtosis(int indiceVariable) {
	double curtosis;
	unsigned int n = columnas;
	curtosis = ((difRespecMedia(indiceVariable, 4) / ((n - 1) * pow(cuasiDesviacionTipica(indiceVariable), 4))));
	//curtosis = curtosis -3;
	return curtosis;
}

void matrizTransicionP(unsigned int n){
	//crearMatrizResueltaVacia();
	//copiarMatrizA();
	unsigned int x = 0;
	while (x != n){
		for (unsigned int i = 0; i < filas; i++) {
			for (unsigned int j = 0; j < columnas; j++) {
				//matrizResuelta[i][j] = 0;
				for (unsigned int k = 0; k < filas; k++) {
					//matrizResuelta[i][j] += matriz[i][k] * matriz[k][j];
				}
			}
		}
	x++;
	}
}*/
