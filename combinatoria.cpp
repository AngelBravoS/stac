#include "funcMate.hpp"

//typedef unsigned short int unShortInt;
//Límite máximo en unsigned short int: 65535

double permutaciones(unsigned short int n){
	double resultado;
	resultado=factorial(n);
	return resultado;
	}
	                  
double permutacionesRep(unsigned short int m, unsigned short int n, unsigned short int numeroElementos){
	double resultado = 1;
	for (unsigned short int i = 0; i < numeroElementos; i++ ) {
		resultado=resultado*factorial(n);
	}
	resultado=factorial(m)/resultado;
	return resultado;
	}

double variaciones(unsigned short int m, unsigned short int n){
	double resultado;
	resultado=factorial(m)/factorial(m-n);
	return resultado;
	}
	
double variacionesRep(unsigned short int m, unsigned short int n){
	double resultado;
	resultado=potencia(m,n);
	return resultado;
	}

double combinaciones(unsigned short int m, unsigned short int n){
	double resultado;
	resultado=factorial(m)/(factorial(n)*factorial(m-n));
	return resultado;
	}
	
double combinacionesRep(unsigned short int m, unsigned short int n){
	double resultado;
	unsigned int valorM=m;
	valorM=valorM+(n-1);
	resultado=(factorial(valorM))/(factorial(n)*factorial(valorM-n));
	return resultado;
	}
