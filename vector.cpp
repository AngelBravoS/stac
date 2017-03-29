#include <iostream>
#include <cmath>
#include "vector.hpp"
#include "funcMate.hpp"

//Límite máximo en unsigned short int: 65535
//Límite máximo en unsigned int: 4294967295

using namespace std;
typedef unsigned short int unShortInt;

unsigned int Vector::getElementoVector() {
	return elementoVector;
	}

void Vector::setElementoVector ( unsigned int elementoVectorPublico ) {
	elementoVector = elementoVectorPublico;
	}

float Vector::getVector() {
	return *vector;
	}

void Vector::setVector ( float *vectorPublico ) {
	*vector = *vectorPublico;
	}

float Vector::getVectorResultado() {
	return *vectorResultado;
	}

void Vector::setVectorResultado ( float *vectorResultadoPublico ) {
	*vectorResultado = *vectorResultadoPublico;
	}

double  Vector::sumatoria ( unsigned short int exponente ) {
	unsigned int n = getElementoVector();
	double sumatoria = 0;
	for ( unsigned int i = 0; i < n; i++ ) {
		sumatoria += potencia ( vector[i], exponente );
		}
	return sumatoria;
	}

double  Vector::mediaAritmetica() {
	unsigned int n = getElementoVector();
	double media = 0;
	media = ( sumatoria ( 1 ) / n );
	return media;
	}

double Vector::mediaGeometrica() {
	unsigned int n = getElementoVector();
	double mediaGeometrica = 1;
	for ( unsigned int i = 0; i < n; i++ ) {
		mediaGeometrica *= vector[i];
		}
	mediaGeometrica = pow ( mediaGeometrica, 1.0 / n );
	return mediaGeometrica;
	}

double Vector::mediaArmonica() {
	unsigned int n = getElementoVector();
	double mediaArmonica = 0;
	for ( unsigned int i = 0; i < n; i++ ) {
		mediaArmonica +=  1 / ( potencia ( vector[i], 1 )  );
		}
	mediaArmonica = ( n / mediaArmonica );
	return mediaArmonica;
	}

double Vector::mediaCuadratica() {
	unsigned int n = getElementoVector();
	double mediaCuadratica;
	mediaCuadratica = sumatoria ( 2 ) * ( 1.0 / n );
	mediaCuadratica = sqrt ( mediaCuadratica );
	return mediaCuadratica;
	}

//Suma de diferencias respecto a la media con exponente
double Vector::difRespecMedia ( int exponente ) {
	unsigned int n = getElementoVector();
	double difRespecMedia = 0;
	for ( unsigned int i = 0; i < n; i++ ) {
		difRespecMedia += pow ( vector[i] - mediaAritmetica(), exponente );
		}
	return difRespecMedia;
	}

double Vector::varianza() {
	unsigned int n = getElementoVector();
	double varianza;
	varianza = ( difRespecMedia ( 2 ) ) / n;
	return varianza;
	}

double Vector::cuasiVarianza() {
	unsigned int n = getElementoVector();
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
	unsigned int n = getElementoVector();
	double momentos;
	momentos = difRespecMedia ( exponente ) / n;
	return momentos;
	}

double Vector::coeficientePearson() {
	double coeficientePearson;
	coeficientePearson = ( cuasiDesviacionTipica() / mediaAritmetica() );
	return coeficientePearson;
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



    //funciona MAAAAL
    double Vector::coeficienteAsimetriaFisher() {
        double coeficienteAsimetriaFisher;
        coeficienteAsimetriaFisher = (momentos(3) / Math.pow(cuasiDesviacionTipica(), 3));
        return coeficienteAsimetriaFisher;
    }

    double Vector::curtosis() {
        double curtosis;
        int n = vector.length;
        curtosis = ((difRespecMedia(4) / ((n - 1) * Math.pow(cuasiDesviacionTipica(), 4))));
        //curtosis = curtosis -3;
        return curtosis;
    }
}*/
