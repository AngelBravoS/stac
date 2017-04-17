#include <iostream>
#include <cmath>
#include "calculos2Var.hpp"
#include "funcMate.hpp"

//Límite máximo en unsigned short int: 65535
//Límite máximo en unsigned int: 4.294.967.295

using namespace std;
typedef unsigned short int unShortInt;

unsigned int Calculos2Var::getFila() {
	return fila;
}

void Calculos2Var::setFila ( unsigned int filaPublica ) {
	fila = filaPublica;
}

unsigned int Calculos2Var::getColumna() {
	return columna;
}

void Calculos2Var::setColumna ( unsigned int columnaPublica ) {
	columna = columnaPublica;
}

double Calculos2Var::getMatriz() {
	return **vectorBi;
}

void Calculos2Var::setMatriz ( double **matrizPublica ) {
	**vectorBi = **matrizPublica;
}

double Calculos2Var::getMatrizCopia() {
	return **copiaDeVectorBi;
}

void Calculos2Var::setMatrizCopia( double **copiaDeMatrizPublica ) {
	**copiaDeVectorBi = **copiaDeMatrizPublica;
}


double  Calculos2Var::sumatoria ( int indiceVariable, unsigned short int exponente ) {
	unsigned int n = getColumna();
	double sumatoria = 0;
	for ( unsigned int j = 0; j < n; j++ ) {
		sumatoria += potencia ( vectorBi[indiceVariable][j], exponente );
	}
	return sumatoria;
}

double  Calculos2Var::mediaAritmetica ( int indiceVariable ) {
	unsigned int n = getColumna();
	double media = 0;
	media = ( sumatoria ( indiceVariable, 1 ) / n );
	return media;
}

double Calculos2Var::mediaGeometrica ( int indiceVariable ) {
	unsigned int n = getColumna();
	double mediaGeometrica = 1;
	for ( unsigned int j = 0; j < n; j++ ) {
		mediaGeometrica *= vectorBi[indiceVariable][j];
	}
	mediaGeometrica = pow ( mediaGeometrica, 1.0 / n );
	return mediaGeometrica;
}

double Calculos2Var::mediaArmonica ( int indiceVariable ) {
	unsigned int n = getColumna();
	double mediaArmonica = 0;
	for ( unsigned int j = 0; j < n; j++ ) {
		mediaArmonica +=  1 / ( potencia ( vectorBi[indiceVariable][j], 1 ) );
	}
	mediaArmonica = ( n / mediaArmonica );
	return mediaArmonica;
}

double Calculos2Var::mediaCuadratica ( int indiceVariable ) {
	unsigned int n = getColumna();
	double mediaCuadratica;
	mediaCuadratica = sumatoria ( indiceVariable, 2 ) * ( 1.0 / n );
	mediaCuadratica = sqrt ( mediaCuadratica );
	return mediaCuadratica;
}

//Suma de diferencias respecto a la media con exponente
double Calculos2Var::difRespecMedia ( int indiceVariable, int exponente ) {
	unsigned int n = getColumna();
	double difRespecMedia = 0;
	for ( unsigned int j = 0; j < n; j++ ) {
		difRespecMedia += pow ( vectorBi[indiceVariable][j] - mediaAritmetica ( indiceVariable ), exponente );
	}
	return difRespecMedia;
}

double Calculos2Var::varianza ( int indiceVariable ) {
	unsigned int n = getColumna();
	double varianza;
	varianza = ( difRespecMedia ( indiceVariable, 2 ) ) / n;
	return varianza;
}

double Calculos2Var::cuasiVarianza ( int indiceVariable ) {
	unsigned int n = getColumna();
	double cuasiVarianza;
	cuasiVarianza = ( difRespecMedia ( indiceVariable, 2 ) ) / ( n - 1 );
	return cuasiVarianza;
}

double Calculos2Var::desviacionTipica ( int indiceVariable ) {
	double desviacionTipica;
	desviacionTipica = sqrt ( varianza ( indiceVariable ) );
	return desviacionTipica;
}

double Calculos2Var::cuasiDesviacionTipica ( int indiceVariable ) {
	double cuasiDesviacionTipica;
	cuasiDesviacionTipica = sqrt ( cuasiVarianza ( indiceVariable ) );
	return cuasiDesviacionTipica;
}

double Calculos2Var::momentos ( int indiceVariable, int exponente ) {
	unsigned int n = getColumna();
	double momentos;
	momentos = difRespecMedia ( indiceVariable, exponente ) / n;
	return momentos;
}

double Calculos2Var::coeficientePearson ( int indiceVariable ) {
	double coeficientePearson;
	coeficientePearson = cuasiDesviacionTipica ( indiceVariable ) / mediaAritmetica ( indiceVariable );
	return coeficientePearson;
}

//funciona MAAAAL
double Calculos2Var::coeficienteAsimetriaFisher ( int indiceVariable ) {
	double coeficienteAsimetriaFisher;
	coeficienteAsimetriaFisher = ( momentos ( indiceVariable, 3 ) / pow ( cuasiDesviacionTipica ( indiceVariable ), 3 ) );
	return coeficienteAsimetriaFisher;
}

double Calculos2Var::curtosis ( int indiceVariable ) {
	double curtosis;
	unsigned int n = getColumna();
	curtosis = ( ( difRespecMedia ( indiceVariable, 4 ) / ( ( n - 1 ) * pow ( cuasiDesviacionTipica ( indiceVariable ), 4 ) ) ) );
	//curtosis = curtosis -3;
	return curtosis;
}

//-----Pide un exponente para poder hacer cosumatorias de cuadrados, cubos, etc, sin necesitar otro método-----//
//-----recibe el exponente de cada variable así como su índice dentro de la matriz (0, 1, 2...)-----//
//-----como las dos variables tienen la misma longitud (vector[0].length = vector[1].length) y solo hay que indicar
//-----una de ellas, se elige la primera.
double Calculos2Var::sumatoria2Var ( int variableX, int variableY, int exponenteX, int exponenteY ) {
	double sumatoria2Variables = 0;
	unsigned int n = getColumna();
	for ( int i = 0; i < n; i++ ) {
		sumatoria2Variables += pow ( vectorBi[variableX][i], exponenteX ) * pow ( vectorBi[variableY][i], exponenteY );
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


/*
unsigned int Vector::getLongitudVector() {
	return longitudVector;
}

void Vector::setLongitudVector ( unsigned int longitudVectorPublico ) {
	longitudVector = longitudVectorPublico;
}

double Vector::getVector() {
	return *vector;
}

void Vector::setVector ( double *vectorPublico ) {
	*vector = *vectorPublico;
}

double Vector::getVectorResultado() {
	return *vectorResultado;
}

void Vector::setVectorResultado ( double vectorResultadoPublico ) {
	*vectorResultado = vectorResultadoPublico;
}

double  Vector::sumatoria ( unsigned short int exponente ) {
	unsigned int n = getLongitudVector();
	double sumatoria = 0;
	for ( unsigned int i = 0; i < n; i++ ) {
		sumatoria += potencia ( vector[i], exponente );
	}
	return sumatoria;
}

double  Vector::mediaAritmetica() {
	unsigned int n = getLongitudVector();
	double media = 0;
	media = ( sumatoria ( 1 ) / n );
	return media;
}

double Vector::mediaGeometrica() {
	unsigned int n = getLongitudVector();
	double mediaGeometrica = 1;
	for ( unsigned int i = 0; i < n; i++ ) {
		mediaGeometrica *= vector[i];
	}
	mediaGeometrica = pow ( mediaGeometrica, 1.0 / n );
	return mediaGeometrica;
}

double Vector::mediaArmonica() {
	unsigned int n = getLongitudVector();
	double mediaArmonica = 0;
	for ( unsigned int i = 0; i < n; i++ ) {
		mediaArmonica +=  1 / ( potencia ( vector[i], 1 ) );
	}
	mediaArmonica = ( n / mediaArmonica );
	return mediaArmonica;
}

double Vector::mediaCuadratica() {
	unsigned int n = getLongitudVector();
	double mediaCuadratica;
	mediaCuadratica = sumatoria ( 2 ) * ( 1.0 / n );
	mediaCuadratica = sqrt ( mediaCuadratica );
	return mediaCuadratica;
}

//Suma de diferencias respecto a la media con exponente
double Vector::difRespecMedia ( int exponente ) {
	unsigned int n = getLongitudVector();
	double difRespecMedia = 0;
	for ( unsigned int i = 0; i < n; i++ ) {
		difRespecMedia += pow ( vector[i] - mediaAritmetica(), exponente );
	}
	return difRespecMedia;
}

double Vector::varianza() {
	unsigned int n = getLongitudVector();
	double varianza;
	varianza = ( difRespecMedia ( 2 ) ) / n;
	return varianza;
}

double Vector::cuasiVarianza() {
	unsigned int n = getLongitudVector();
	double cuasiVarianza;
	cuasiVarianza = ( difRespecMedia ( 2 ) ) / ( n - 1 );
	return cuasiVarianza;
}

double Vector::desviacionTipica() {
	double desviacionTipica;
	desviacionTipica = sqrt ( varianza() );
	return desviacionTipica;
}

double Vector::cuasiDesviacionTipica() {
	double cuasiDesviacionTipica;
	cuasiDesviacionTipica = sqrt ( cuasiVarianza() );
	return cuasiDesviacionTipica;
}

double Vector::momentos ( int exponente ) {
	unsigned int n = getLongitudVector();
	double momentos;
	momentos = difRespecMedia ( exponente ) / n;
	return momentos;
}

double Vector::coeficientePearson() {
	double coeficientePearson;
	coeficientePearson = ( cuasiDesviacionTipica() / mediaAritmetica() );
	return coeficientePearson;
}

//funciona MAAAAL
double Vector::coeficienteAsimetriaFisher() {
	double coeficienteAsimetriaFisher;
	coeficienteAsimetriaFisher = ( momentos ( 3 ) / pow ( cuasiDesviacionTipica(), 3 ) );
	return coeficienteAsimetriaFisher;
}

double Vector::curtosis() {
	double curtosis;
	int n =  getLongitudVector();
	curtosis = ( ( difRespecMedia ( 4 ) / ( ( n - 1 ) * pow ( cuasiDesviacionTipica(), 4 ) ) ) );
	//curtosis = curtosis -3;
	return curtosis;
}


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
