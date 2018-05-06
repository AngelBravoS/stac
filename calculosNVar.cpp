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
#include "calculosNVar.hpp"
#include "funcMatematicasBasicas.hpp"

//Límite máximo en unsigned short int: 65535
//Límite máximo en unsigned int: 4.294.967.295

using namespace std;
typedef unsigned short int unShortInt;

double CalculosNVar::getSumatoria() {
	return sumatoria;
	}

void CalculosNVar::setSumatoria ( double sumatoriaPublica ) {
	sumatoria = sumatoriaPublica;
	}	

double  CalculosNVar::calculoSumatoria(int indiceVariable, unsigned short int exponente) {
	unsigned int n = columna;
	double resultado = 0;
	for(unsigned int j = 0; j < n; j++) {
		resultado += potencia(matriz[indiceVariable][j], exponente);
	}
	return resultado;
}

double  CalculosNVar::total(int indiceVariable) {
	unsigned int n = columna;
	double resultado = 0;
	resultado = (n* mediaAritmetica(indiceVariable));
	return resultado;
}

double  CalculosNVar::mediaAritmetica(int indiceVariable) {
	unsigned int n = columna;
	double resultado = 0;
	resultado = (calculoSumatoria(indiceVariable, 1) / n);
	return resultado;
}

double CalculosNVar::mediaGeometrica(int indiceVariable) {
	unsigned int n = columna;
	double mediaGeometrica = 1;
	for(unsigned int j = 0; j < n; j++) {
		mediaGeometrica *= matriz[indiceVariable][j];
	}
	mediaGeometrica = pow(mediaGeometrica, 1.0 / n);
	return mediaGeometrica;
}

double CalculosNVar::mediaArmonica(int indiceVariable) {
	unsigned int n = columna;
	double mediaArmonica = 0;
	for(unsigned int j = 0; j < n; j++) {
		mediaArmonica +=  1 / (potencia(matriz[indiceVariable][j], 1));
	}
	mediaArmonica = (n / mediaArmonica);
	return mediaArmonica;
}

double CalculosNVar::mediaCuadratica(int indiceVariable) {
	unsigned int n = columna;
	double mediaCuadratica;
	mediaCuadratica = calculoSumatoria(indiceVariable, 2) * (1.0 / n);
	mediaCuadratica = sqrt(mediaCuadratica);
	return mediaCuadratica;
}

//Suma de diferencias respecto a la media con exponente
double CalculosNVar::difRespecMedia(int indiceVariable, int exponente) {
	unsigned int n = columna;
	double difRespecMedia = 0;
	for(unsigned int j = 0; j < n; j++) {
		difRespecMedia += pow(matriz[indiceVariable][j] - mediaAritmetica(indiceVariable), exponente);
	}
	return difRespecMedia;
}

double CalculosNVar::varianza(int indiceVariable) {
	unsigned int n = columna;
	double resultado;
	resultado = (difRespecMedia(indiceVariable, 2)) / n;
	return resultado;
}

double CalculosNVar::cuasiVarianza(int indiceVariable) {
	unsigned int n = columna;
	double resultado;
	resultado = (difRespecMedia(indiceVariable, 2)) / (n - 1);
	return resultado;
}

double CalculosNVar::desviacionTipica(int indiceVariable) {
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
	unsigned int n = columna;
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
	unsigned int n = columna;
	curtosis = ((difRespecMedia(indiceVariable, 4) / ((n - 1) * pow(cuasiDesviacionTipica(indiceVariable), 4))));
	//curtosis = curtosis -3;
	return curtosis;
}

/*
	// Método Quicksort y opción de Arrays.sort(vectorOrdenado);
	// con import java.util.Arrays; habilitado
	double Vector::ordenamientoVector() {
        double [] vectorOrdenado = (double[])vector.clone(); //===> Clonar ==> al clonar el vector original no se modifica
        Arrays.sort(vectorOrdenado);
        return vectorOrdenado;
    }

    double Vector::mediana(double []vectorOrdenado) {
        double [] vector = vectorOrdenado;
        double mediana=0;
        if (vector.length mod 2) = 1
			mediana = orden[i,(vector.length div 2)+1]
		else
			mediana = orden[i,(vector.length div 2)] + orden[i,(vector.length div 2)+1])  /  2
        return mediana;
    }
    void Vector::moda() {
    }
}*/
