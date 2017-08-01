#include <iostream>
#include <cmath>
#include "calculos1Var.hpp"
#include "funcMatematicasBasicas.hpp"

//Límite máximo en unsigned short int: 65535
//Límite máximo en unsigned int: 4.294.967.295

using namespace std;
typedef unsigned short int unShortInt;

double  Calculos1Var::sumatoria ( unsigned short int exponente ) {
	unsigned int n = getLongitudVector();
	double sumatoria = 0;
	for ( unsigned int i = 0; i < n; i++ ) {
		sumatoria += potencia ( vector[i], exponente );
	}
	return sumatoria;
}

double  Calculos1Var::mediaAritmetica() {
	unsigned int n = getLongitudVector();
	double media = 0;
	media = ( sumatoria ( 1 ) / n );
	return media;
}

double Calculos1Var::mediaGeometrica() {
	unsigned int n = getLongitudVector();
	double mediaGeometrica = 1;
	for ( unsigned int i = 0; i < n; i++ ) {
		mediaGeometrica *= vector[i];
	}
	mediaGeometrica = pow ( mediaGeometrica, 1.0 / n );
	return mediaGeometrica;
}

double Calculos1Var::mediaArmonica() {
	unsigned int n = getLongitudVector();
	double mediaArmonica = 0;
	for ( unsigned int i = 0; i < n; i++ ) {
		mediaArmonica +=  1 / ( potencia ( vector[i], 1 ) );
	}
	mediaArmonica = ( n / mediaArmonica );
	return mediaArmonica;
}

double Calculos1Var::mediaCuadratica() {
	unsigned int n = getLongitudVector();
	double mediaCuadratica;
	mediaCuadratica = sumatoria ( 2 ) * ( 1.0 / n );
	mediaCuadratica = sqrt ( mediaCuadratica );
	return mediaCuadratica;
}

//Suma de diferencias respecto a la media con exponente
double Calculos1Var::difRespecMedia ( int exponente ) {
	unsigned int n = getLongitudVector();
	double difRespecMedia = 0;
	for ( unsigned int i = 0; i < n; i++ ) {
		difRespecMedia += pow ( vector[i] - mediaAritmetica(), exponente );
	}
	return difRespecMedia;
}

double Calculos1Var::varianza() {
	unsigned int n = getLongitudVector();
	double varianza;
	varianza = ( difRespecMedia ( 2 ) ) / n;
	return varianza;
}

double Calculos1Var::cuasiVarianza() {
	unsigned int n = getLongitudVector();
	double cuasiVarianza;
	cuasiVarianza = ( difRespecMedia ( 2 ) ) / ( n - 1 );
	return cuasiVarianza;
}

double Calculos1Var::desviacionTipica() {
	double desviacionTipica;
	desviacionTipica = sqrt ( varianza() );
	return desviacionTipica;
}

double Calculos1Var::cuasiDesviacionTipica() {
	double cuasiDesviacionTipica;
	cuasiDesviacionTipica = sqrt ( cuasiVarianza() );
	return cuasiDesviacionTipica;
}

double Calculos1Var::momentos ( int exponente ) {
	unsigned int n = getLongitudVector();
	double momentos;
	momentos = difRespecMedia ( exponente ) / n;
	return momentos;
}

double Calculos1Var::coeficientePearson() {
	double coeficientePearson;
	coeficientePearson = ( cuasiDesviacionTipica() / mediaAritmetica() );
	return coeficientePearson;
}

//funciona MAAAAL
double Calculos1Var::coeficienteAsimetriaFisher() {
	double coeficienteAsimetriaFisher;
	coeficienteAsimetriaFisher = ( momentos ( 3 ) / pow ( cuasiDesviacionTipica(), 3 ) );
	return coeficienteAsimetriaFisher;
}

double Calculos1Var::curtosis() {
	double curtosis;
	int n =  getLongitudVector();
	curtosis = ( ( difRespecMedia ( 4 ) / ( ( n - 1 ) * pow ( cuasiDesviacionTipica(), 4 ) ) ) );
	//curtosis = curtosis -3;
	return curtosis;
}

double Calculos1Var::norma() {
	double norma = 0;
	norma+=sumatoria(2);
	norma=sqrt(norma);
	return norma;
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

double Calculos1Var::media1MuestraSigmaConocida(){
	double resultado = 0;
	cout << "ok."<<endl;
	return resultado;
	
}

double Calculos1Var::media1MuestraSigmaDesconocida(){
	double resultado = 0;
	return resultado;
	
}
	
double Calculos1Var::var1MuestraMuConocida(){
	double resultado = 0;
	return resultado;
	
}
	
double Calculos1Var::var1MuestraMuDesconocida(){
	double resultado = 0;
	return resultado;
	
}
	
double Calculos1Var::testChiMuConocida(){
	double resultado = 0;
	return resultado;
	
}
	
double Calculos1Var::testChiMuDesconocida(){
	double resultado = 0;
	return resultado;
	
}

double Calculos1Var::testStudentVarConocida(){
	double resultado = 0;
	return resultado;
	
}

double Calculos1Var::testStudentVarDesconocida(){
	double resultado = 0;
	return resultado;
	
}
