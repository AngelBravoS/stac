#include "calculosIA.hpp"
#include "funcMatematicasBasicas.hpp"

//---función para el generador congruencial mixto--
unsigned int CalculosIA::congruencialMixto(unsigned short int a, unsigned short int b,
      unsigned int m, unsigned int X0) {
	int resultado ;
	resultado = a * X0 + b;
	if(resultado > m)
		resultado = resultado % m;
	return resultado;
}

//---función para el generador congruencial multiplicativo---
unsigned int CalculosIA::congruencialMultip(unsigned short int a, unsigned int m,
      unsigned int X0) {
	unsigned int resultado;
	resultado = a * X0;
	if(resultado > m)
		resultado %=  m;
	return resultado;
}

void CalculosIA::crearSecuenciaMixto(unsigned short int a, unsigned short int b,
                                     unsigned int m, unsigned int X0) {
	//Desconocemos la longitud del vector hasta que la semilla se repite
	//por eso la llamada es redundante. Se llama en bucle dos veces, una
	//para saber la longitud y otra para crear el vector con la secuencia
	unsigned int i, Xn, n;
	Xn = congruencialMixto(a, b, m, X0);
	n = 1;
	while(X0 != Xn) {
		Xn = congruencialMixto(a, b, m, Xn);
		n++;
	}
	setLongitudVector(n);
	crearVectorVacio();
	vector[0] = congruencialMixto(a, b, m, X0);
	i = 0;
	while(X0 != vector[i]) {
		vector[i+1] = congruencialMixto(a, b, m, vector[i]);
		i++;
	}
	mostrarVector();
}


void CalculosIA::crearSecuenciaMultip(unsigned short int a, unsigned int m,
                                      unsigned int X0) {
	//Desconocemos la longitud del vector hasta que la semilla se repite
	//por eso la llamada es redundante. Se llama en bucle dos veces, una
	//para saber la longitud y otra para crear el vector con la secuencia
	unsigned int i, Xn, n;
	Xn = congruencialMultip(a, m, X0);
	n = 1;
	while(X0 != Xn) {
		Xn = congruencialMultip(a, m, Xn);
		n++;
	}
	setLongitudVector(n);
	crearVectorVacio();
	vector[0] = congruencialMultip(a, m, X0);
	i = 0;
	while(X0 != vector[i]) {
		vector[i+1] = congruencialMultip(a, m, vector[i]);
		i++;
	}
	mostrarVector();
}
