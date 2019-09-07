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
#include "mas.hpp"

//Límite máximo en unsigned short int: 65535
//Límite máximo en unsigned int: 4.294.967.295

MAS::MAS(bool archivo, char estimadorElegido, unsigned int numeroColumnas, bool datosAgrupados) {
   desdeArchivo = archivo;
	estimador = estimadorElegido;
   //columnasMatrizResuelta = numeroColumnas;
   agrupados = datosAgrupados;
   }

void MAS::desdeDondeLeeDatos() {
	//agrupados == true ? filasMatrizResuelta = 2 : filasMatrizResuelta = 1;
	//filas = filasMatrizResuelta;
   //crearMatrizResueltaVacia();
   if (desdeArchivo == true) {
	  verificarArchivo();
	  leerDesdeArchivo();
	  }
   else {
	  //leerDesdeTeclado();
	  }
   }

void MAS::leerDesdeArchivo() {
/*   std::fstream archivo;
   archivo.open("datos.dat", std::ios::in | std::ios::binary);
   int unsigned n = columnasMatrizResuelta;
   if (agrupados == true) {
	  unsigned int i = 0, j = 0;
	  while (!archivo.eof()) {
		 archivo >> matrizResuelta[i][j];
		 j++; //avanza en la fila
		 i += j / n; //si pasó de N, le suma a 1 a i (siguiente columna)
		 j = j % n; //se asegura que esté entre 0 y N-1
		 }
	  }
   else {
	  for (unsigned int j = 0; j < n; j++) {
		 archivo >> matrizResuelta[0][j];
		 }
	  }
   archivo.close();*/
   }

/*void MAS::crearMatrizParaCalculos() {
   if (agrupados == true) {
	  desagruparElementos();
	  }
   else {
	  columnas = columnasMatrizResuelta;
	  crearMatrizResueltaVacia();
	  copiarMatrizResuelta();
	  }
   }*/

/*void MAS::desagruparElementos() {
   double n;
   double totalElementos = 0;
   int x = 0; //entender por qué así funciona.
   for (unsigned int j = 0; j < columnasMatrizResuelta; j++) {
	  totalElementos += potencia(matrizResuelta[1][j], 1);
	  }
   columnas = convierteDoubleEnInt(totalElementos);
   crearMatrizResueltaVacia();
   for (unsigned int j = 0; j < columnasMatrizResuelta; j++) {
	  n = matrizResuelta[1][j];
	  for (unsigned int i = 0; i < n; i++) {
		 matriz[0][x] = matrizResuelta[0][j];
		 matriz[1][x] = 1;
		 x++;
		 }
	  }
   }*/
/*
void MAS::leerDesdeTeclado() {
   if (agrupados == true) {
	  for (unsigned int j = 0; j < columnasMatrizResuelta; j++) {
		 std::cout << "x" << j + 1 << " = ";
		 std::cin >> matrizResuelta[0][j];
		 std::cout << "f" << j + 1 << " = ";
		 std::cin >> matrizResuelta[1][j];
		 }
	  desagruparElementos();
	  }
   else {
	  for (unsigned int j = 0; j < columnasMatrizResuelta; j++) {
		 std::cout << "x" << j + 1 << " = ";
		 std::cin >> matrizResuelta[0][j];
		 }
	  }
   }*/
   
// añade ∑Xi Y ∑Xi2 a la matriz
void MAS::incorporarXiYXi2() {
   unsigned int i = filas;
   if (agrupados == true) {
	  for (unsigned int j = 0; j < columnas; j++) {
		 matriz[i - 2][j] = matriz[0][j] * matriz[1][j];
		 matriz[i - 1][j] = matriz[i - 2][j] * matriz[i - 2][j];
		 }
	  }
   else {
	  matriz[i - 2][0] = matriz[0][0];
	  matriz[i - 1][0] = matriz[0][0] * matriz[0][0];
	  for (unsigned int j = 1; j < columnas; j++) {
		 matriz[i - 2][j] = matriz[0][j] * matriz[1][j];
		 matriz[i - 1][j] = matriz[i - 2][j] * matriz[i - 2][j];
		 }
	  }
   }

double MAS::calcularEstimador() {
	double resultado = 0;
	/*switch(estimador) {
		case '1' :
			resultado = mediaAritmetica(0);
			break;
		case '2' :
			//resultado = N * mediaAritmetica(0);
			break;
		case '3' :
			resultado = mediaAritmetica(0);
			break;
	}*/
	return resultado;
}

double MAS::calculoIC() {
   double resultado = 0;
   return resultado;
   }

double MAS::varianzaEstimador() {
   double resultado = 0;
   return resultado;
   }

double MAS::estimadorVarianza() {
   double resultado = 0;
   return resultado;
   }




