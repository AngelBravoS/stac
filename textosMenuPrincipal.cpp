#include "cli.hpp"
#include <iostream>

using namespace std;

void CLI::hasElegido() {
	cout << '\n';
	cout << "has elegido: " << getOpcion() << '\n';
	cout << '\n';
	}

void CLI::introduccion() {
	cout << '\n';
	cout << "             ======================= " << '\n';
	cout << "             Programa de estadística" << '\n';
	cout << "                      STAC" << '\n';
	cout << "             ======================= " << '\n';
	cout << '\n';
	}

void CLI::acercaDe() {
	cout << '\n';
	cout << "             ======================= " << '\n';
	cout << "               Versión alpha 0.7.1" << '\n';
	cout << "                  Escrito en c++" << '\n';
	cout << "                Ángel Bravo Sáenz" << '\n';
	cout << "             ======================= " << '\n';
	cout << '\n';
	}

void CLI::ayuda() {
	cout << "                      Ayuda" << '\n';
	cout << "-------------------------------------------------" << '\n';
	cout << "Análisis estadístico de una variable:" << '\n';
	cout << "	Resúmenes descriptivos:" << '\n';
	cout << "		Medidas de posición central,  " << '\n';
	cout << "		de dispersión, kurtosis, asimetría" << '\n';
	cout << "	Inferencia" << '\n';
	cout << "		Contrastes en poblaciones normales" << '\n';
	cout << "			Relativo a la media" << '\n';
	cout << "			Relativo a la varianza" << '\n';
	cout << "		Test de la Chi-Cuadrado" << '\n';
	cout << "		Test de la t de Student" << '\n';
	cout << "	Muestreo" << '\n';

	cout << "Análisis estadístico de dos variables:"  << '\n';
	cout << "	Rectas de regresión" << '\n';
	cout << "	Independencia" << '\n';
	cout << "	Muestreo" << '\n';

	cout << "Análisis estadístico de n-variables:" << '\n';
	cout << "	Análisis multivariante " << '\n';

	cout << "Cálculo matricial:" << '\n';
	cout << "	De una matriz" << '\n';
	cout << "		Traza" << '\n';
	cout << "		Determinante" << '\n';
	cout << "		Matriz traspuesta" << '\n';
	cout << "		Matriz adjunta" << '\n';
	cout << "		Matriz inversa" << '\n';
	cout << "		Vectores y valores propios" << '\n';
	cout << "		Gauss" << '\n';
	cout << "	De dos matrices" << '\n';
	cout << "		Sumar matrices" << '\n';
	cout << "		Multiplicar matrices" << '\n';
	cout << "		Kronecker" << '\n';

	cout << "Análisis que no requiere datos:" << '\n';
	cout << "	Combinatoria" << '\n';
	cout << "	Distribuciones discretas de probabilidad" << '\n';
	cout << "	Inteligencia Artificial" << '\n';
	cout << "		Generador congruencial multiplicativo" << '\n';
	cout << "		Generador congruencia mixto" << '\n';
	cout << "	Distribuciones discretas de probabilidad" << '\n';
	cout << '\n';
	}

void CLI::listadOpcionesPricipales() {
	cout << "		  Menú principal" << '\n';
	cout << "             ======================= " << '\n';
	cout << '\n';
	cout << "'1' Análisis estadístico de una variable." << '\n';
	cout << "'2' Análisis estadístico de dos variables."  << '\n';
	cout << "'n' Análisis estadístico de n-variables." << '\n';
	cout << "'m' Cálculo matricial." << '\n';
	cout << "'s' Análisis que no requiere datos." << '\n';
	cout << "'a' Ayuda." << '\n';
	cout << "'0'  Salir." << '\n';
	}
