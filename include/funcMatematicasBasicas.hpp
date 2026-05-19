#ifndef FUNCMATEMATICASBASICAS_HPP_INCLUDED
#define FUNCMATEMATICASBASICAS_HPP_INCLUDED

#include <algorithm> 
#include <cmath>

double factorial(unsigned int  n);
double potencia(double numero, unsigned int potencia);
double potenciaDouble(double numero, double potencia);
double binomio(double a, double b);
double e();

unsigned int gcd(unsigned int a , unsigned int b);
bool esMultiplo(unsigned int numero1, unsigned int numero2);
bool esPrimo (unsigned int numero);
bool sonCoprimos (unsigned int numero1, unsigned int numero2);
bool sonCongruentes (unsigned int numero1, unsigned int numero2, unsigned int numero3);

unsigned int convierteDoubleEnInt (double doble);
unsigned int convierteLongEnInt(unsigned long unsignedlong);
float convierteIntEnFloat(unsigned int entero);
double convierteIntEnDouble(unsigned int entero);

#endif // FUNCMATEMATICASBASICAS_HPP_INCLUDED
