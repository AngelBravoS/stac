/***************************************************************************
 *   Copyright (C) 2018 by Ángel Bravo Sáenz                               *
 *   angelbravosaenz@gmail.com                                             *
 *                                                                         *
 *   This file is part of Stac.                                            *
 *                                                                         *
 *   Stac is free software; you can redistribute it and/or modify          *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
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

#include <iostream>
#include <cmath>
#include <fstream>
#include "calculosMuestreo.hpp"

//Límite máximo en unsigned short int: 65535
//Límite máximo en unsigned int: 4.294.967.295

CalculosMuestreo::CalculosMuestreo(bool archivo, char muestreo, unsigned int numeroColumnas, bool datosAgrupados) {
   tipoMuestreo = muestreo;
   desdeArchivo = archivo;
   //fila = numeroFilas;
   columnaB = numeroColumnas;
   agrupados = datosAgrupados;
   }

void CalculosMuestreo::asignarVariables() {
   char mismoTamanyoConglomerado;
   switch (tipoMuestreo) {
	  case '1' : // MAS
		 reemplazo = false;
		 probIguales = true;
		 agrupados == true ? filaB = 2 : filaB = 1;
		 break;
	  case '2' :
		 reemplazo = true;
		 probIguales = true;
		 agrupados == true ? filaB = 2 : filaB = 1;
		 break;
	  case '3' :
		 reemplazo = false;
		 probIguales = false;
		 agrupados == true ? filaB = 3 : filaB = 2;
		 break;
	  case '4' :
		 reemplazo = true;
		 probIguales = false;
		 agrupados == true ? filaB = 3 : filaB = 2;
		 break;
	  case '8' :
		 std::cout << "¿Los conglomerados tienen el mismo tamaño?" << '\n';
		 std::cout << "s/n:";
		 std::cin >> mismoTamanyoConglomerado;
		 if (mismoTamanyoConglomerado == 's') {
			mismoTamanyo = true;
			}
		 else {
			mismoTamanyo = false;
			}
		 break;
	  }
   fila = filaB;
   }

void CalculosMuestreo::desdeDondeLeeDatos() {
   crearMatrizVaciaB();
   if (desdeArchivo == true) {
	  verificarArchivo();
	  leerDesdeArchivo();
	  }
   else {
	  leerDesdeTeclado();
	  }
   }

void CalculosMuestreo::leerDesdeArchivo() {
   std::fstream archivo;
   archivo.open("datos.dat", std::ios::in | std::ios::binary);
   int unsigned n = columnaB;
   if (agrupados == true) {
	  unsigned int i = 0, j = 0;
	  while (!archivo.eof()) {
		 archivo >> matrizB[i][j];
		 j++; //avanza en la fila
		 i += j / n; //si pasó de N, le suma a 1 a i (siguiente columna)
		 j = j % n; //se asegura que esté entre 0 y N-1
		 }
	  }
   else {
	  for (unsigned int j = 0; j < n; j++) {
		 archivo >> matrizB[0][j];
		 }
	  }
   archivo.close();
   }

void CalculosMuestreo::crearMatrizParaCalculos() {
   if (agrupados == true) {
	  desagruparElementos();
	  }
   else {
	  columna = columnaB;
	  crearMatrizVacia();
	  copiarMatrizB();
	  }
   }

void CalculosMuestreo::desagruparElementos() {
   double n;
   double totalElementos = 0;
   int x = 0; //entender por qué así funciona.
   for (unsigned int j = 0; j < columnaB; j++) {
	  totalElementos += potencia(matrizB[1][j], 1);
	  }
   columna = convierteDoubleEnInt(totalElementos);
   crearMatrizVacia();
   for (unsigned int j = 0; j < columnaB; j++) {
	  n = matrizB[1][j];
	  for (unsigned int i = 0; i < n; i++) {
		 matriz[0][x] = matrizB[0][j];
		 matriz[1][x] = 1;
		 x++;
		 }
	  }
   }

void CalculosMuestreo::leerDesdeTeclado() {
   if (agrupados == true) {
	  for (unsigned int j = 0; j < columnaB; j++) {
		 std::cout << "x" << j + 1 << " = ";
		 std::cin >> matrizB[0][j];
		 std::cout << "f" << j + 1 << " = ";
		 std::cin >> matrizB[1][j];
		 }
	  desagruparElementos();
	  }
   else {
	  for (unsigned int j = 0; j < columnaB; j++) {
		 std::cout << "x" << j + 1 << " = ";
		 std::cin >> matrizB[0][j];
		 }
	  }
   if ((agrupados == true) && (probIguales == false)) {
	  for (unsigned int j = 0; j < columnaB; j++) {
		  std::cout << "p" << j + 1 << " = ";
		 std::cin >> matrizB[2][j];
		 }
	  }
   if ((agrupados == false) && (probIguales == false)) {
	  for (unsigned int j = 0; j < columnaB; j++) {
		  std::cout << "p" << j + 1 << " = ";
		 std::cin >> matrizB[1][j];
		 }
	  }
   }
// añade ∑Xi Y ∑Xi2 a la matriz
void CalculosMuestreo::incorporarXiYXi2() {
   unsigned int i = fila;
   if (agrupados == true) {
	  for (unsigned int j = 0; j < columna; j++) {
		 matriz[i - 2][j] = matriz[0][j] * matriz[1][j];
		 matriz[i - 1][j] = matriz[i - 2][j] * matriz[i - 2][j];
		 }
	  }
   else {
	  matriz[i - 2][0] = matriz[0][0];
	  matriz[i - 1][0] = matriz[0][0] * matriz[0][0];
	  for (unsigned int j = 1; j < columna; j++) {
		 matriz[i - 2][j] = matriz[0][j] * matriz[1][j];
		 matriz[i - 1][j] = matriz[i - 2][j] * matriz[i - 2][j];
		 }
	  }
   }

double CalculosMuestreo::estimador(char estimador) {
	double resultado = 0;
	switch(estimador) {
		case 'm' :
			resultado = mediaAritmetica(0);
			break;
		case 't' :
			//resultado = N * mediaAritmetica(0);
			break;
		case 'p' :
			resultado = mediaAritmetica(0);
			break;
	}
	return resultado;
}

double CalculosMuestreo::calculoIC() {
   double resultado = 0;
   switch (tipoMuestreo) {
	  case '1' :
		 break;
	  case '2' :
		 break;
	  case '3' :
		 break;
	  case '4' :
		 break;
	  }
   return resultado;
   }

double CalculosMuestreo::varianzaEstimador() {
   double resultado = 0;
   switch (tipoMuestreo) {
	  case '1' :
		 resultado = cuasiVarianza(0);
		 break;
	  case '2' :
		 break;
	  case '3' :
		 break;
	  case '4' :
		 break;
	  }
   return resultado;
   }

double CalculosMuestreo::estimadorVarianza() {
   double resultado = 0;
   switch (tipoMuestreo) {
	  case '1' :
		 break;
	  case '2' :
		 break;
	  case '3' :
		 break;
	  case '4' :
		 break;
	  }
   return resultado;
   }




