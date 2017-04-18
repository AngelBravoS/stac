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
double Calculos2Var::sumatoria2Var ( int variableX, int variableY, int exponenteX, int exponenteY ) {
	double sumatoria2Variables = 0;
	unsigned int n = getColumna();
	for ( int i = 0; i < n; i++ ) {
		sumatoria2Variables += pow ( matriz[variableX][i], exponenteX ) * pow ( matriz[variableY][i], exponenteY );
	}
	return sumatoria2Variables;
	
}

double Calculos2Var::covarianza() {
	unsigned int n = getColumna();
	double covarianza = 0;
	covarianza += ( sumatoria2Var ( 0, 1, 1, 1 ) );
	covarianza = ( covarianza / n) - ( mediaAritmetica ( 0 ) * mediaAritmetica ( 1 ) );
	return covarianza;
}

double Calculos2Var::coeficienteCorrelacion() {
	double coeficienteCorrelacion;
	coeficienteCorrelacion = ( covarianza() ) / ( desviacionTipica ( 0 ) * desviacionTipica ( 1 ) );
	return coeficienteCorrelacion;
}


/*
double Calculos2Var::distanciaEuclidea ( int i, int j ) {
	double distanciaEuclidea = 0;
	for ( byte x = 0; x < 3; x++ ) {
		distanciaEuclidea = Math.pow ( ( vector[i][j] - vector[i][j + x] ), 2 )
		                    + Math.pow ( ( vector[i + x][j] - vector[i + x][j + x] ), 2 );
	}
	System.out.println ( distanciaEuclidea );
	return distanciaEuclidea;
}
*/
