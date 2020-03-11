/***************************************************************************
 *   Copyright (C) 2018 by Ángel Bravo Sáenz                               *
 *   angelbravosaenz@gmail.com                                             *
 *                                                                         *
 *   This file is part of Stac.                                            *
 *                                                                         *
 *   Stac is free software; you can redistribute it and/or modify          *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; version 2 of the License.               *
 *                                                                         *
 *   Stac is distributed in the hope that it will be useful,               *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with Stac; if not, write to the                                 *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#include "cli.hpp"
#include <iostream>

void CLI::introduccion() {
	std::cout << '\n';
	std::cout << "	╔══════════════════════════╗" << '\n';
	std::cout << "	║           STAC           ║" << '\n';
	std::cout << "	║        Estadística       ║" << '\n';
	std::cout << "	║   en línea de comandos   ║" << '\n';
	std::cout << "	╚══════════════════════════╝" << '\n';
	std::cout << "			       a0.89" << '\n';
	std::cout << '\n';
}

void CLI::ayuda() {
	std::cout << "                      Ayuda" << '\n';
	std::cout << "-------------------------------------------------" << '\n';
	std::cout << "Análisis estadístico de una variable:" << '\n';
	std::cout << "	Resúmenes descriptivos:" << '\n';
	std::cout << "		Medidas de posición central,  " << '\n';
	std::cout << "		de dispersión, kurtosis, asimetría" << '\n';
	std::cout << "	Inferencia" << '\n';
	std::cout << "		Contrastes en poblaciones normales" << '\n';
	std::cout << "			Relativo a la media" << '\n';
	std::cout << "			Relativo a la varianza" << '\n';
	std::cout << "		Test de la Chi-Cuadrado" << '\n';
	std::cout << "		Test de la t de Student" << '\n';

	std::cout << "Análisis estadístico de dos variables:"  << '\n';
	std::cout << "	Rectas de regresión" << '\n';
	std::cout << "	Independencia" << '\n';

	std::cout << "Análisis estadístico de n-variables:" << '\n';
	std::cout << "	Análisis multivariante " << '\n';
	std::cout << "	Procesos estocásticos " << '\n';

	std::cout << "Cálculo álgebra matricial:" << '\n';
	std::cout << "	De una matriz" << '\n';
	std::cout << "		Traza" << '\n';
	std::cout << "		Determinante" << '\n';
	std::cout << "		Matriz traspuesta" << '\n';
	std::cout << "		Matriz adjunta" << '\n';
	std::cout << "		Matriz inversa" << '\n';
	std::cout << "		Vectores y valores propios" << '\n';
	std::cout << "		Gauss" << '\n';
	std::cout << "	De dos matrices" << '\n';
	std::cout << "		Sumar matrices" << '\n';
	std::cout << "		Multiplicar matrices" << '\n';
	std::cout << "		Kronecker" << '\n';

	std::cout << "Muestreo:" << '\n';
	std::cout << "	aleatorio simple (MAS)" << '\n';
	std::cout << "	con reemplazo y probabilidades iguales" << '\n';
	std::cout << "	sin reemplazo y probabilidades desiguales" << '\n';
	std::cout << "	con reemplazo y probabilidades desiguales" << '\n';
	std::cout << '\n';

	std::cout << "Análisis que no requiere datos:" << '\n';
	std::cout << "	Combinatoria" << '\n';
	std::cout << "	Distribuciones discretas de probabilidad" << '\n';
	std::cout << "	Inteligencia Artificial" << '\n';
	std::cout << "		Generador congruencial multiplicativo" << '\n';
	std::cout << "		Generador congruencia mixto" << '\n';
	std::cout << "	Distribuciones discretas de probabilidad" << '\n';
	std::cout << '\n';
}

void CLI::listadOpcionesPricipales() {
	std::cout << "		Menú principal" << '\n';
	std::cout << "	=========================== " << '\n';
	std::cout << '\n';
	std::cout << "'1' Análisis de una variable." << '\n';
	std::cout << "'2' Análisis de dos variables."  << '\n';
	std::cout << "'n' Análisis de n-variables." << '\n';
	std::cout << "'a' Álgebra matricial." << '\n';
	std::cout << "'m' Muestreo." << '\n';
	std::cout << "'s' Análisis que no requiere datos." << '\n';
	std::cout << "'h' Ayuda." << '\n';
	std::cout << "'0'  Salir." << '\n';
}

void CLI::listadOpcionesMuestreo() {
	std::cout << '\n';
	std::cout << "Selecciona el tipo de muestreo:" << '\n';
	std::cout << "'1' MAS (Sin reemplazo y probabilidades iguales)" << '\n';
	std::cout << "'2' Con reemplazo y probabilidades iguales"  << '\n';
	std::cout << "'3' Sin reemplazo y probabilidades desiguales." << '\n';
	std::cout << "'4' Con reemplazo y probabilidades desiguales"  << '\n';
	std::cout << "'5' Muestreo sistemático" << '\n';
	std::cout << "'6' Métodos indirectos de estimación" << '\n';
	std::cout << "'7' Muestreo estratificado" << '\n';
	std::cout << "'8' Muestreo por conglomerados" << '\n';
	std::cout << "'0' Volver al menú principal" << '\n';
	std::cout << "> ";
}

void CLI::preguntarEstimador() {
	std::cout << "Selecciona parámetro:" << '\n';
	std::cout << "'1' para la media" << '\n';
	std::cout << "'2' para el total" << '\n';
	std::cout << "'3' para la proporción" << '\n';
	std::cout << "> ";
}

void CLI::listadOpciones1Variable() {
	std::cout << '\n';
	std::cout << "'1' Medidas estadísticas básicas" << '\n';
	std::cout << "'2' Inferencia" << '\n';
	std::cout << "'0' Volver al menú principal" << '\n';
	std::cout << "> ";
}

void CLI::listadOpciones2Variables() {
	std::cout << '\n';
	std::cout << "'1' Medidas estadísticas básicas" << '\n';
	std::cout << "'2' Tablas de contingencia bidimensionales" << '\n';
	std::cout << "'0' Volver al menú principal" << '\n';
	std::cout << "> ";
}

void CLI::listadOpciones1Matriz() {
	std::cout << "Cálculos de una matriz" << '\n';
	std::cout << "'1' Traza" << '\n';
	std::cout << "'2' Determinante" << '\n';
	std::cout << "'3' Matriz traspuesta" << '\n';
	std::cout << "'4' Método de Gauss" << '\n';
	std::cout << "'5' Matriz adjunta" << '\n';
	std::cout << "'6' Matriz inversa" << '\n';
	std::cout << "'7' Descomposición LU" << '\n';
	std::cout << "'8' Métodos numéricos" << '\n';
	std::cout << "'0' Menú anterior." << '\n';
	std::cout << "> ";
}

void CLI::listadOpciones2Matrices() {
	std::cout << "Cálculos de dos matrices" << '\n';
	std::cout << "'1' Suma" << '\n';
	std::cout << "'2' Multiplicación" << '\n';
	std::cout << "'3' Kronecker" << '\n';
	std::cout << "'0' Menú anterior." << '\n';
	std::cout << "> ";
}

void CLI::listadOpcionesColasExponencial() {
	std::cout << '\n';
	std::cout << "Modelos de colas exponenciales: " << "\n";
	std::cout << "'1' M/M/1" << "\n";
	std::cout << "'2' M/M/1/K" << "\n";
	std::cout << "'3' M/M/C" << "\n";
	std::cout << "'4' M/M/Inf" << "\n";
	std::cout << "'5' M/G/I" << "\n";
	std::cout << "'0' Menú anterior." << "\n";
	std::cout << "> ";
}

void CLI::listadOpcionestipoGenerador() {
	std::cout << "Escribe x para el generador congruencial mixto." << '\n';
	std::cout << "Escribe m para el generador congruencial multiplicativo." << '\n';
	std::cout << "> ";
}
