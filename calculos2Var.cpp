#include <iostream>
#include <cmath>
#include "calculos2Var.hpp"
#include "funcMatematicasBasicas.hpp"

//Límite máximo en unsigned short int: 65535
//Límite máximo en unsigned int: 4.294.967.295

//-----Pide un exponente para poder hacer cosumatorias de cuadrados, cubos, etc, sin necesitar otro método-----//
//-----recibe el exponente de cada variable así como su índice dentro de la matriz (0, 1, 2...)-----//
//-----como las dos variables tienen la misma longitud (vector[0].length = vector[1].length) y solo hay que indicar
//-----una de ellas, se elige la primera.
double Calculos2Var::sumatoria2Var(int variableX, int variableY, int exponenteX, int exponenteY) {
	double sumatoria2Variables = 0;
	unsigned int n = getColumna();
	for(unsigned int i = 0; i < n; i++) {
		sumatoria2Variables += pow(matriz[variableX][i], exponenteX) * pow(matriz[variableY][i], exponenteY);
	}
	return sumatoria2Variables;
}

double Calculos2Var::covarianza() {
	unsigned int n = getColumna();
	double covarianza = 0;
	covarianza += (sumatoria2Var(0, 1, 1, 1));
	covarianza = (covarianza / n) - (calculoMediaAritmetica(0) * calculoMediaAritmetica(1));
	return covarianza;
}

double Calculos2Var::coeficienteCorrelacion() {
	double coeficienteCorrelacion;
	coeficienteCorrelacion = (covarianza()) / (desviacionTipica(0) * desviacionTipica(1));
	return coeficienteCorrelacion;
}

double Calculos2Var::distanciaEuclidea() {
	double distanciaEuclidea = 0;
	/*
	unsigned int n = getColumna();
	for (unsigned int x = 0; x < n; x++ ) {
		distanciaEuclidea = pow ( ( matriz[i][j] - matriz[i][j + x] ), 2 )
		                    + pow ( ( matriz[i + x][j] - matriz[i + x][j + x] ), 2 );
	}*/
	return distanciaEuclidea;
}
