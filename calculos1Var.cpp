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

double sumatoria(Vector &v1, unsigned int exponente) {
	unsigned int n = v1.size();
	double sumatoria = 0;
	for (unsigned int i = 0; i < n; i++) {
		sumatoria += potencia(v1[i], exponente);
	}
	return sumatoria;
}

double mediaAritmetica(Vector &v1) {
	unsigned int n = v1.size();
	double media = 0;
	media = (sumatoria(v1, 1) / n);
	return media;
}

double mediaGeometrica(Vector &v1) {
	unsigned int n = v1.size();
	double mediaGeometrica = 1;
	for (unsigned int i = 0; i < n; i++) {
		mediaGeometrica *= v1[i];
	}
	mediaGeometrica = pow(mediaGeometrica, 1.0 / n);
	return mediaGeometrica;
}

double mediaArmonica(Vector &v1) {
	unsigned int n = v1.size();
	double mediaArmonica = 0;
	for (unsigned int i = 0; i < n; i++) {
		mediaArmonica +=  1 / (potencia(v1[i], 1));
	}
	mediaArmonica = (n / mediaArmonica);
	return mediaArmonica;
}

double mediaCuadratica(Vector &v1) {
	unsigned int n = v1.size();
	double mediaCuadratica;
	mediaCuadratica = sumatoria(v1, 2) * (1.0 / n);
	mediaCuadratica = sqrt(mediaCuadratica);
	return mediaCuadratica;
}

//Suma de diferencias respecto a la media con exponente
double difRespecMedia(Vector &v1, int exponente) {
	unsigned int n = v1.size();
	double difRespecMedia = 0;
	for (unsigned int i = 0; i < n; i++) {
		difRespecMedia += pow(v1[i] - mediaAritmetica(v1), exponente);
	}
	return difRespecMedia;
}

double mediana(Vector &v1) {
	double mediana;
	unsigned int n, v;
	n = v1.size();
	v1.ordenarVector();
	v = n / 2;
	if (n % 2 == 0) {
		mediana = (v1[v] + v1[v - 1]) / 2;
	} else {
		mediana = v1[v];
	}
	return mediana;
}

double moda(Vector &v1) {
	double norma = 0;
	norma += sumatoria(v1, 2);
	norma = sqrt(norma);
	return norma;
}

double varianza(Vector &v1) {
	unsigned int n = v1.size();
	double varianza;
	varianza = (difRespecMedia(v1, 2)) / n;
	return varianza;
}

double varianzaMuestral(Vector &v1) {
	unsigned int n = v1.size();
	double varianzaMuestral;
	varianzaMuestral = (difRespecMedia(v1, 2)) / (n - 1);
	return varianzaMuestral;
}

double desviacionTipica(Vector &v1) {
	double desviacionTipica;
	desviacionTipica = sqrt(varianza(v1));
	return desviacionTipica;
}

double desviacionTipicaMuestral(Vector &v1) {
	double desviacionTipicaMuestral;
	desviacionTipicaMuestral = sqrt(varianzaMuestral(v1));
	return desviacionTipicaMuestral;
}

double momentosNoCentrados(Vector &v1, int exponente) {
	unsigned int n = v1.size();
	double momento;
	momento = difRespecMedia(v1, exponente) / n;
	return momento;
}

double coeficientePearson(Vector &v1) {
	double coeficientePearson;
	coeficientePearson = desviacionTipica(v1) / mediaAritmetica(v1);
	return coeficientePearson;
}

double coeficienteAsimetriaFisher(Vector &v1) {
	double coeficiente, mu;
	//unsigned int n = longitudVector;
	mu = difRespecMedia(v1, 3);
	coeficiente = mu / momentosNoCentrados(v1, 3);
	return coeficiente;
}

double curtosis(Vector &v1) {
	double curtosis, mu;
	mu = momentosNoCentrados(v1, 4);
	/*mu = 
momentosNoCentrados(4)-4*momentosNoCentrados(1)*momentosNoCentrados(3)+6*
potencia(momentosNoCentrados(1),2)-3*potencia(momentosNoCentrados(1),4);*/
	curtosis = (mu / potencia(varianza(v1), 2)) - 3;
	return curtosis;
}

double norma(Vector &v1) {
	double norma = 0;
	norma += sumatoria(v1, 2);
	norma = sqrt(norma);
	return norma;
}
