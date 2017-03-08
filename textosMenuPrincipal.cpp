#include "cli.hpp"
#include <iostream>

using namespace std;

void CLI::hasElegido() {
    cout << endl;
    cout << "has elegido: " << getOpcion() << endl;
    cout << endl;
    }

void CLI::introduccion() {
    cout << endl;
    cout << " =======================" << endl;
    cout << "|            Programa de estadística            |" << endl;
    cout << "|                           STAC                           |" << endl;
    cout << " =======================" << endl;
    cout << endl;
    }

void CLI::acercaDe() {
    cout << endl;
    cout << " ======================= " << endl;
    cout << "|               Versión alpha 0.5.0               |" << endl;
    cout << "|                  Escrito en c++                   |" << endl;
    cout << "|               Ángel Bravo Sáenz                |" << endl;
    cout << " ======================= " << endl;
    cout << endl;
    }

void CLI::ayuda() {
    cout << "                      Ayuda" << endl;
    cout << "-------------------------------------------------" << endl;
    cout << "Análisis estadístico de una variable:" << endl;
    cout << "	Resúmenes descriptivos:" << endl;
    cout << "		Medidas de posición central,  " << endl;
    cout << "		de dispersión, kurtosis, asimetría" << endl;
    cout << "	Muestreo" << endl;

    cout << "Análisis estadístico de dos variables:"  << endl;
    cout << "	Rectas de regresión" << endl;
    cout << "	Independencia" << endl;
    cout << "	Muestreo" << endl;


    cout << "Análisis estadístico de n variables:" << endl;
    cout << "	Análisis multivariante " << endl;

    cout << "Cálculo matricial:" << endl;
    cout << "	De una matriz" << endl;
    cout << "		Traza" << endl;
    cout << "		Determinante" << endl;
    cout << "		Matriz traspuesta" << endl;
    cout << "		Matriz adjunta" << endl;
    cout << "		Matriz inversa" << endl;
    cout << "		Vectores y valores propios" << endl;
    cout << "		Gauss" << endl;
    cout << "	De dos matrices" << endl;
    cout << "		Sumar matrices" << endl;
    cout << "		Multiplicar matrices" << endl;
    cout << "		Kronecker" << endl;

    cout << "Análisis que no requiere datos:" << endl;
    cout << "	Combinatoria" << endl;
    cout << "	Inteligencia Artificial" << endl;
    cout << "		Generador congruencial multiplicativo" << endl;
    cout << "		Generador congruencia mixto" << endl;
    cout << "	Distribuciones discretas de probabilidad" << endl;
    cout << endl;
    }

void CLI::listadOpcionesPricipales() {
    cout << "Escribe: " << endl;
    cout << "'1' Análisis estadístico de una variable." << endl;
    cout << "'2' Análisis estadístico de dos variables."  << endl;
    cout << "'n' Análisis estadístico de n variables." << endl;
    cout << "'m' Cálculo matricial." << endl;
    cout << "'0' Análisis que no requiere datos." << endl;
    cout << "'a' Ayuda." << endl;
    cout << "Cualquier otra tecla para salir." << endl;
    }
