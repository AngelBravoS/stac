#include <iostream>
#include <cmath>
#include "calculosNVar.hpp"
#include "funcMate.hpp"

//Límite máximo en unsigned short int: 65535
//Límite máximo en unsigned int: 4.294.967.295

using namespace std;
typedef unsigned short int unShortInt;

unsigned int CalculosNVar::getFila() {
	return fila;
}

void CalculosNVar::setFila ( unsigned int filaPublica ) {
	fila = filaPublica;
}

unsigned int CalculosNVar::getColumna() {
	return columna;
}

void CalculosNVar::setColumna ( unsigned int columnaPublica ) {
	columna = columnaPublica;
}

double CalculosNVar::getMatriz() {
	return **matriz;
}

void CalculosNVar::setMatriz ( double **matrizPublica ) {
	**matriz = **matrizPublica;
}

double CalculosNVar::getMatrizCopia() {
	return **copiaDeMatriz;
}

void CalculosNVar::setMatrizCopia ( double **copiaDeMatrizPublica ) {
	**copiaDeMatriz = **copiaDeMatrizPublica;
}

double  CalculosNVar::sumatoria ( int indiceVariable, unsigned short int exponente ) {
	unsigned int n = getColumna();
	double sumatoria = 0;
	for ( unsigned int j = 0; j < n; j++ ) {
		sumatoria += potencia ( matriz[indiceVariable][j], exponente );
	}
	return sumatoria;
}

double  CalculosNVar::mediaAritmetica ( int indiceVariable ) {
	unsigned int n = getColumna();
	double media = 0;
	media = ( sumatoria ( indiceVariable, 1 ) / n );
	return media;
}

double CalculosNVar::mediaGeometrica ( int indiceVariable ) {
	unsigned int n = getColumna();
	double mediaGeometrica = 1;
	for ( unsigned int j = 0; j < n; j++ ) {
		mediaGeometrica *= matriz[indiceVariable][j];
	}
	mediaGeometrica = pow ( mediaGeometrica, 1.0 / n );
	return mediaGeometrica;
}

double CalculosNVar::mediaArmonica ( int indiceVariable ) {
	unsigned int n = getColumna();
	double mediaArmonica = 0;
	for ( unsigned int j = 0; j < n; j++ ) {
		mediaArmonica +=  1 / ( potencia ( matriz[indiceVariable][j], 1 ) );
	}
	mediaArmonica = ( n / mediaArmonica );
	return mediaArmonica;
}

double CalculosNVar::mediaCuadratica ( int indiceVariable ) {
	unsigned int n = getColumna();
	double mediaCuadratica;
	mediaCuadratica = sumatoria ( indiceVariable, 2 ) * ( 1.0 / n );
	mediaCuadratica = sqrt ( mediaCuadratica );
	return mediaCuadratica;
}

//Suma de diferencias respecto a la media con exponente
double CalculosNVar::difRespecMedia ( int indiceVariable, int exponente ) {
	unsigned int n = getColumna();
	double difRespecMedia = 0;
	for ( unsigned int j = 0; j < n; j++ ) {
		difRespecMedia += pow ( matriz[indiceVariable][j] - mediaAritmetica ( indiceVariable ), exponente );
	}
	return difRespecMedia;
}

double CalculosNVar::varianza ( int indiceVariable ) {
	unsigned int n = getColumna();
	double varianza;
	varianza = ( difRespecMedia ( indiceVariable, 2 ) ) / n;
	return varianza;
}

double CalculosNVar::cuasiVarianza ( int indiceVariable ) {
	unsigned int n = getColumna();
	double cuasiVarianza;
	cuasiVarianza = ( difRespecMedia ( indiceVariable, 2 ) ) / ( n - 1 );
	return cuasiVarianza;
}

double CalculosNVar::desviacionTipica ( int indiceVariable ) {
	double desviacionTipica;
	desviacionTipica = sqrt ( varianza ( indiceVariable ) );
	return desviacionTipica;
}

double CalculosNVar::cuasiDesviacionTipica ( int indiceVariable ) {
	double cuasiDesviacionTipica;
	cuasiDesviacionTipica = sqrt ( cuasiVarianza ( indiceVariable ) );
	return cuasiDesviacionTipica;
}

double CalculosNVar::momentos ( int indiceVariable, int exponente ) {
	unsigned int n = getColumna();
	double momentos;
	momentos = difRespecMedia ( indiceVariable, exponente ) / n;
	return momentos;
}

double CalculosNVar::coeficientePearson ( int indiceVariable ) {
	double coeficientePearson;
	coeficientePearson = cuasiDesviacionTipica ( indiceVariable ) / mediaAritmetica ( indiceVariable );
	return coeficientePearson;
}

//funciona MAAAAL
double CalculosNVar::coeficienteAsimetriaFisher ( int indiceVariable ) {
	double coeficienteAsimetriaFisher;
	coeficienteAsimetriaFisher = ( momentos ( indiceVariable, 3 ) / pow ( cuasiDesviacionTipica ( indiceVariable ), 3 ) );
	return coeficienteAsimetriaFisher;
}

double CalculosNVar::curtosis ( int indiceVariable ) {
	double curtosis;
	unsigned int n = getColumna();
	curtosis = ( ( difRespecMedia ( indiceVariable, 4 ) / ( ( n - 1 ) * pow ( cuasiDesviacionTipica ( indiceVariable ), 4 ) ) ) );
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
