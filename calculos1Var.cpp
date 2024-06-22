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

#include "calculos1Var.hpp"

//Límite máximo en unsigned short int: 65535
//Límite máximo en unsigned int: 4.294.967.295

double sumatoria(Vector &variable, unsigned int exponente) {
	unsigned int n = variable.size();
	double sumatoria = 0;
	for(unsigned int i = 0; i < n; i++) {
		sumatoria += potencia(variable[i], exponente);
	}
	return sumatoria;
}

double mediaAritmetica(Vector &variable) {
	unsigned int n = variable.size();
	double media = 0;
	media = (sumatoria(variable, 1) / n);
	return media;
}

double mediaGeometrica(Vector &variable) {
	unsigned int n = variable.size();
	double mediaGeometrica = 1;
	for(unsigned int i = 0; i < n; i++) {
		mediaGeometrica *= variable[i];
	}
	mediaGeometrica = pow(mediaGeometrica, 1.0 / n);
	return mediaGeometrica;
}

double mediaArmonica(Vector &variable) {
	unsigned int n = variable.size();
	double mediaArmonica = 0;
	for(unsigned int i = 0; i < n; i++) {
		mediaArmonica +=  1 / (potencia(variable[i], 1));
	}
	mediaArmonica = (n / mediaArmonica);
	return mediaArmonica;
}

double mediaCuadratica(Vector &variable) {
	unsigned int n = variable.size();
	double mediaCuadratica;
	mediaCuadratica = sumatoria(variable, 2) * (1.0 / n);
	mediaCuadratica = sqrt(mediaCuadratica);
	return mediaCuadratica;
}

//Suma de diferencias respecto a la media con exponente
double difRespecMedia(Vector &variable, int exponente) {
	unsigned int n = variable.size();
	double difRespecMedia = 0;
	for(unsigned int i = 0; i < n; i++) {
		difRespecMedia += pow(variable[i] - mediaAritmetica(variable), exponente);
	}
	return difRespecMedia;
}

double mediana(Vector &variable) {
	double mediana;
	unsigned int n, v;
	n = variable.size();
	variable.ordenarVector();
	v = n / 2;
	if(n % 2 == 0) {
		mediana = (variable[v] + variable[v - 1]) / 2;
	} else {
		mediana = variable[v];
	}
	return mediana;
}

double moda(Vector &variable) {
	unsigned int valoresDistintos = 1;
	unsigned int n = variable.size();
	//unsigned int moda = 0;

	std::vector<unsigned int>frecuencia(n);
	variable.ordenarVector();

	for(unsigned int i=0; i<(n-1); i++) {
		if(variable[i] != variable[i+1]) {
			valoresDistintos++;
		}
	}
	std::vector<double>varAux(valoresDistintos++);

	for(unsigned int i=0; i<(n-1); i++) {
		if(variable[i] == variable[i+1]) {
			frecuencia[i]+=1;
			varAux[i]=variable[i];
		}
	}

	//std::sort(frecuencia.begin(), frecuencia.end());

	return valoresDistintos;
}

double varianza(Vector &variable) {
	unsigned int n = variable.size();
	double varianza;
	varianza = (difRespecMedia(variable, 2)) / n;
	return varianza;
}

double varianzaMuestral(Vector &variable) {
	unsigned int n = variable.size();
	double varianzaMuestral;
	varianzaMuestral = (difRespecMedia(variable, 2)) / (n - 1);
	return varianzaMuestral;
}

double desviacionTipica(Vector &variable) {
	double desviacionTipica;
	desviacionTipica = sqrt(varianza(variable));
	return desviacionTipica;
}

double desviacionTipicaMuestral(Vector &variable) {
	double desviacionTipicaMuestral;
	desviacionTipicaMuestral = sqrt(varianzaMuestral(variable));
	return desviacionTipicaMuestral;
}

double momentosNoCentrados(Vector &variable, int exponente) {
	unsigned int n = variable.size();
	double momento;
	momento = difRespecMedia(variable, exponente) / n;
	return momento;
}

double coeficienteVarPearson(Vector &variable) {
	double coeficientePearson;
	coeficientePearson = desviacionTipica(variable) / mediaAritmetica(variable);
	return coeficientePearson;
}

double coeficienteAsimetriaPearson(Vector &variable) {
	double coeficiente=0, numerador=0;
	numerador = mediaAritmetica(variable)-moda(variable);
	coeficiente = numerador/desviacionTipica(variable);
	return coeficiente;
}

double coeficienteAsimetriaFisher(Vector &variable) {
	double coeficiente=0, mu=0;
	mu = difRespecMedia(variable, 3);
	coeficiente = mu / momentosNoCentrados(variable, 3);
	return coeficiente;
}

double coefApuntFisher(Vector &variable) {
	double coeficiente=0, mu=0;
	mu = momentosNoCentrados(variable, 4);
	coeficiente = (mu / potencia(varianza(variable), 2)) - 3;
	return coeficiente;
}

double norma(Vector &variable) {
	double norma = 0;
	norma += sumatoria(variable, 2);
	norma = sqrt(norma);
	return norma;
}
