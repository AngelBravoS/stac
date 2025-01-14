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

#include "textosMenus.hpp"
#include "cli.hpp"

void introduccion() {
  std::cout << '\n'
            << "	╔══════════════════════════╗" << '\n'
            << "	║           STAC           ║" << '\n'
            << "	║        Estadística       ║" << '\n'
            << "	║   en línea de comandos   ║" << '\n'
            << "	╚══════════════════════════╝" << '\n'
            << "			       0.90.3" << '\n'
            << '\n';
}

void ayuda() {
  std::cout << "                      Ayuda" << '\n'
            << "-------------------------------------------------" << '\n'
            << "Análisis estadístico de una variable:" << '\n'
            << "	Resúmenes descriptivos:" << '\n'
            << "		Medidas de posición central,  " << '\n'
            << "		de dispersión, kurtosis, asimetría" << '\n'
            << "	Inferencia" << '\n'
            << "		Contrastes en poblaciones normales" << '\n'
            << "			Relativo a la media" << '\n'
            << "			Relativo a la varianza" << '\n'
            << "		Test de la Chi-Cuadrado" << '\n'
            << "		Test de la t de Student" << '\n'

            << "Análisis estadístico de dos variables:" << '\n'
            << "	Rectas de regresión" << '\n'
            << "	Independencia" << '\n'

            << "Análisis estadístico de n-variables:" << '\n'
            << "	Análisis multivariante " << '\n'
            << "	Procesos estocásticos " << '\n'

            << "Cálculo álgebra matricial:" << '\n'
            << "	De una matriz" << '\n'
            << "		Traza" << '\n'
            << "		Determinante" << '\n'
            << "		Matriz traspuesta" << '\n'
            << "		Matriz adjunta" << '\n'
            << "		Matriz inversa" << '\n'
            << "		Vectores y valores propios" << '\n'
            << "		Gauss" << '\n'
            << "	De dos matrices" << '\n'
            << "		Sumar matrices" << '\n'
            << "		Multiplicar matrices" << '\n'
            << "		Kronecker" << '\n'

            << "Muestreo:" << '\n'
            << "	aleatorio simple (MAS)" << '\n'
            << "	con reemplazo y probabilidades iguales" << '\n'
            << "	sin reemplazo y probabilidades desiguales" << '\n'
            << "	con reemplazo y probabilidades desiguales" << '\n'
            << '\n'

            << "Análisis que no requiere datos:" << '\n'
            << "	Combinatoria" << '\n'
            << "	Distribuciones discretas de probabilidad" << '\n'
            << "	Inteligencia Artificial" << '\n'
            << "		Generador congruencial multiplicativo" << '\n'
            << "		Generador congruencia mixto" << '\n'
            << "	Distribuciones discretas de probabilidad" << '\n'
            << '\n';
}

void listadOpcionesPrincipales() {
  std::cout << "		Menú principal" << '\n'
            << "	=========================== " << '\n'
            << '\n'
            << "'1' Análisis de una variable." << '\n'
            << "'2' Análisis de dos variables." << '\n'
            << "'3' Análisis de n-variables." << '\n'
            << "'4' Álgebra matricial." << '\n'
            << "'5' Inferencia." << '\n'
            << "'6' Análisis que no requiere datos." << '\n'
            << "'7' Ayuda." << '\n'
            << "'0' Salir." << '\n';
}

void listadOpcionesMuestreo() {
  std::cout << '\n'
            << "Selecciona el tipo de muestreo:" << '\n'
            << "'1' MAS (Sin reemplazo y probabilidades iguales)" << '\n'
            << "'2' Con reemplazo y probabilidades iguales" << '\n'
            << "'3' Sin reemplazo y probabilidades desiguales." << '\n'
            << "'4' Con reemplazo y probabilidades desiguales" << '\n'
            << "'5' Muestreo sistemático" << '\n'
            << "'6' Métodos indirectos de estimación" << '\n'
            << "'7' Muestreo estratificado" << '\n'
            << "'8' Muestreo por conglomerados" << '\n'
            << "'0' Volver al menú principal" << '\n'
            << "> ";
}

void listadOpciones2Variables() {
  std::cout << '\n'
            << "'1' Medidas estadísticas básicas." << '\n'
            << "'2' Tablas de contingencia bidimensionales." << '\n'
            << "'0' Volver al menú principal." << '\n'
            << "> ";
}

void listadOpciones1Matriz() {
  std::cout << "Cálculos de una matriz" << "\n"
            << "'1' Traza" << "\n"
            << "'2' Determinante" << "\n"
            << "'3' Matriz traspuesta" << "\n"
            << "'4' Matriz adjunta" << "\n"
            << "'5' Matriz inversa" << "\n"
            << "'6' Descomposicion LU" << "\n"
            << "'7' Gauss" << "\n"
			<< "'8' Gauss-Jordan" << "\n"
            << "'9' Valores y vectores propios" << "\n"
            << "'0' para volver al menu anterior." << "\n"
            << "> ";
}

void listadOpciones2Matrices() {
  std::cout << "Cálculos de dos matrices" << "\n"
            << "'1' Suma" << "\n"
            << "'2' Multiplicación" << "\n"
            << "'3' Kronecker" << "\n"
            << "'0' para volver al menu anterior." << "\n"
            << "> ";
}

void listadoMenuSinDatos() {
  std::cout << "'1' Combinatoria." << '\n'
            << "'2' Simulación." << '\n'
            << "'3' Colas exponenciales." << '\n'
            << "'4' Distribuciones de probabilidad discretas." << '\n'
            << "'0' Volver al menú principal." << '\n'
            << "> ";
}

void listadOpcionesColasExponencial() {
  std::cout << '\n'
  << "Modelos de colas exponenciales: " << "\n"
  << "'1' M/M/1" << "\n"
  << "'2' M/M/1/K" << "\n"
  << "'3' M/M/C" << "\n"
  << "'4' M/M/Inf" << "\n"
  << "'5' M/G/I" << "\n"
  << "'0' Menú anterior." << "\n"
  << "> ";
}

void listadOpcionesSimula() {
  //  << "	=========================== " << '\n';
  std::cout << '\n'
            << "'1' Calcular la secuencia de generadores congruenciales."
            << '\n'
            << "'2' Comprobar el período de un generador congruencial." << '\n'
            << "'3' Generar valores aleatorios de distribuciones aleatorias."
            << '\n'
            << "'0' Menú anterior." << '\n'
            << "> ";
}

void listadOpcionestipoGenerador() {
  std::cout << "'1' Generador congruencial mixto." << '\n'
            << "'2' Generador congruencial multiplicativo." << '\n'
            << "'0' Menú anterior." << "\n"
            << "> ";
}

void textoLeerDesdeTeclado() {
  std::cout << "Introduce los elementos uno a " << "\n"
            << "uno separando con un espacio." << "\n"
            << "Pulsa intro para terminar o" << "\n"
            << "escribir la fila siguiente" << "\n"
            << "\n";
}
