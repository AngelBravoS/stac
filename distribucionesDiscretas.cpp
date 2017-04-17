#include "funcMate.hpp"
//#include "distribuciones.hpp"
#include <math.h>

double poisson ( float parametroP, unsigned short int probabilidad ) {
	double resultado;
	float lambda = parametroP;
	double e = 2.7182818284590;
	unsigned short int x = probabilidad;
	resultado = ( pow ( e, -lambda ) ) * ( pow ( lambda, x ) / factorial ( x ) );
	return resultado;
}

double bernouilli ( float p, unsigned short int x ) {
	double resultado;
	resultado = potencia ( p, x ) * potencia ( 1 - p, x - 1 );
	return resultado;
}

double binomial ( unsigned short int n, float p,
                  unsigned short int x ) {
	double resultado;
	float q = ( 1 - p );
	if ( n > 50 && p <= 0.1 ) {
		resultado = poisson ( n * p, x );
	} else {
		resultado = binomio ( n, x ) * potencia ( p, x ) * potencia ( q, n - x );
	}
	return resultado;
}

double binomialNegativa ( unsigned short int parametron, float parametroP,
                          unsigned short int probabilidad ) {
	double resultado;
	unsigned short int n = parametron;
	float p = parametroP;
	int x = probabilidad;
	resultado = binomio ( n + ( x - 1 ), x ) * potencia ( p, n ) * potencia ( 1 - p, x );
	return resultado;
}

double hipergeometrica ( unsigned short int parametroN, unsigned short int parametroD,
                         unsigned short int parametron, unsigned short int probabilidad ) {
	double resultado;
	unsigned short int N = parametroN;
	float D = parametroD;
	unsigned short int x = probabilidad;
	unsigned short int n = parametron;
	float parametroP = D / N;
	if ( n < 0.1 * N ) {
		resultado = binomial ( parametron, parametroP, x );
	} else {
		resultado = binomio ( D, x ) * binomio ( ( N - D ), ( n - x ) ) / binomio ( N, n );
	}
	return resultado;
}

double geometrica ( float parametroP, unsigned short int probabilidad ) {
	double resultado;
	float p = parametroP;
	float q = 1 - p;
	unsigned short int x = probabilidad;
	resultado = ( potencia ( p * q, x - 1 ) );
	return resultado;
}
