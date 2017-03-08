#include "funcMate.hpp"

typedef unsigned short int unShortInt;

double permutaciones(unShortInt n){
	double resultado;
	resultado=factorial(n);
	return resultado;
	}
	                  
double permutacionesRep(unShortInt m, unShortInt n, unShortInt numeroElementos){
	double resultado = 1;
	for (unShortInt i = 0; i < numeroElementos; i++ ) {
		resultado=resultado*factorial(n);
	}
	resultado=factorial(m)/resultado;
	return resultado;
	}

double variaciones(unShortInt m, unShortInt n){
	double resultado;
	resultado=factorial(m)/factorial(m-n);
	return resultado;
	}
	
double variacionesRep(unShortInt m, unShortInt n){
	double resultado;
	resultado=potencia(m,n);
	return resultado;
	}

double combinaciones(unShortInt m, unShortInt n){
	double resultado;
	resultado=factorial(m)/(factorial(n)*factorial(m-n));
	return resultado;
	}
	
double combinacionesRep(unShortInt m, unShortInt n){
	double resultado;
	unsigned int valorM=m;
	valorM=valorM+(n-1);
	resultado=(factorial(valorM))/(factorial(n)*factorial(valorM-n));
	return resultado;
	}
