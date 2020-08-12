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

#include <iostream>
#include "calculosAlgebra.hpp"

CalculosAlgebra::CalculosAlgebra() {
	}

CalculosAlgebra::CalculosAlgebra(unsigned int longitudFila, unsigned int longitudColumna) {
		filas = longitudFila;
		columnas = longitudColumna;
		crearMatrizVacia();
		filas == columnas ? cuadrada = true : cuadrada = false;
		if (cuadrada == true) {dimension = filas;}
	}	
	
CalculosAlgebra::CalculosAlgebra(bool archivo, unsigned int longitudFila, unsigned int longitudColumna) {
	desdeArchivo = archivo;
	filas = longitudFila;
	columnas = longitudColumna;
	filas == columnas ? cuadrada = true : cuadrada = false;
	if (cuadrada == true) {dimension = filas;}
	}

double CalculosAlgebra::traza() {
	double traza = 0;
	for (unsigned int i = 0; i < filas; i++) {
		traza += matriz[i][i];
		}
	return traza;
	}

double CalculosAlgebra::determinante() {
	if ( cuadrada == false ) {
		std::cout << "La matriz no es cuadrada. " << '\n';
		return 0;
	} else {
		double determinante = 0;
		switch (filas) {
			case 1:
				determinante = matriz[0][0];
				break;
			case 2://caso base para la recursividad
				determinante = matriz[0][0] * matriz[1][1] - matriz[0][1] * matriz[1][0];
				break;
			case 3://por sarrus
				determinante = (matriz[0][0] * matriz[1][1] * matriz[2][2] +
									matriz[0][2] * matriz[1][0] * matriz[2][1] +
									matriz[0][1] * matriz[1][2] * matriz[2][0]) -
									(matriz[0][2] * matriz[1][1] * matriz[2][0] +
									matriz[0][1] * matriz[1][0] * matriz[2][2] +
									matriz[0][0] * matriz[1][2] * matriz[2][1]);
				break;
			default :
				gauss();
				determinante = 1;
				for(unsigned int i = 0; i < dimension; i++) {
					determinante *= resultado[i][i];
				}
				break;
			}
		return determinante;
	}
	}

void CalculosAlgebra::traspuesta() {
    Matriz matrizResultado(filas, columnas);
	for (unsigned int i = 0; i < filas; i++) {
		for (unsigned int j = 0; j < columnas; j++) {
			//resultado[i][j] = matriz[j][i];
            //matrizResultado.matriz[i][j] = matriz[j][i];
		}
	}
}

void CalculosAlgebra::adjunta() {
	switch (filas){
		case 1:
			resultado[0][0] = matriz[0][0];
			break;
		case 2:
			resultado[0][0] = matriz[1][1];
			resultado[0][1] = -matriz[0][1];
			resultado[1][0] = -matriz[1][0];
			resultado[1][1] = matriz[0][0];
			break;
		case 3:
			resultado[0][0] = (matriz[1][1]*matriz[2][2]) - (matriz[1][2]*matriz[2][1]);
			resultado[0][1] = (matriz[1][2]*matriz[2][0]) - (matriz[1][0]*matriz[2][2]);
			resultado[0][2] = (matriz[1][0]*matriz[2][1]) - (matriz[1][1]*matriz[2][0]);
			resultado[1][0] = (matriz[2][1]*matriz[0][2]) - (matriz[2][2]*matriz[0][1]);
			resultado[1][1] = (matriz[2][2]*matriz[0][0]) - (matriz[2][0]*matriz[0][2]);
			resultado[1][2] = (matriz[2][0]*matriz[0][1]) - (matriz[2][1]*matriz[0][0]);
			resultado[2][0] = (matriz[0][1]*matriz[1][2]) - (matriz[0][2]*matriz[1][1]);
			resultado[2][1] = (matriz[0][2]*matriz[1][0]) - (matriz[0][0]*matriz[1][2]);
			resultado[2][2] = (matriz[0][0]*matriz[1][1]) - (matriz[0][1]*matriz[1][0]);
			break;
		default:
			std::cout << "aún no disponible" << '\n';
	}
	}

void CalculosAlgebra::inversa() {
	double det = determinante();
	double frac = 1/det;
	if (determinante() != 0) {
		switch (filas){
			case 1:
				resultado[0][0] = matriz[0][0];
				break;
			case 2:
				resultado[0][0] = frac * matriz[1][1];
				resultado[0][1] = frac * (-matriz[0][1]);
				resultado[1][0] = frac * (-matriz[1][0]);
				resultado[1][1] = frac * matriz[0][0];
				break;
			case 3:
				resultado[0][0] = frac * ((matriz[1][1]*matriz[2][2]) - (matriz[1][2]*matriz[2][1]));
				resultado[1][0] = frac * ((matriz[1][2]*matriz[2][0]) - (matriz[1][0]*matriz[2][2]));
				resultado[2][0] = frac * ((matriz[1][0]*matriz[2][1]) - (matriz[1][1]*matriz[2][0]));
				resultado[0][1] = frac * ((matriz[2][1]*matriz[0][2]) - (matriz[2][2]*matriz[0][1]));
				resultado[1][1] = frac * ((matriz[2][2]*matriz[0][0]) - (matriz[2][0]*matriz[0][2]));
				resultado[2][1] = frac * ((matriz[2][0]*matriz[0][1]) - (matriz[2][1]*matriz[0][0]));
				resultado[0][2] = frac * ((matriz[0][1]*matriz[1][2]) - (matriz[0][2]*matriz[1][1]));
				resultado[1][2] = frac * ((matriz[0][2]*matriz[1][0]) - (matriz[0][0]*matriz[1][2]));
				resultado[2][2] = frac * ((matriz[0][0]*matriz[1][1]) - (matriz[0][1]*matriz[1][0]));
				break;
			default:
				std::cout << "aún no disponible" << '\n';
		}
	} else {
		std::cout << "La matriz no tiene inversa" << '\n';
		}
	}

void CalculosAlgebra::triangular() {
	/*for ( int i = 1, i <= n, i++ ) {
		if ( matriz[i, i] = 0 ) {
			for ( j = i + 1, j <= n, j++ ) {
				if ( matriz[j, i] != 0 ) {
				k = j:
					}

				}
			}
		}*/
	}
/*
Si A11=0, se busca el primer coeficiente no nulo de la getColumna
e intercambiamos fila.
Si A11 =/= 0 para i = 2...n, mi1=-ai1/a11, así hacemos 0 todo elemento
de la columna debajo del pivote
*/
//Aviso chapuza mucho que mejorar
//
void CalculosAlgebra::gauss() {
	CalculosAlgebra matrizL(filas, columnas);
	CalculosAlgebra matrizU(filas, columnas);
	unsigned int n = dimension;
	for (unsigned int i = 0; i < n; i++) {
		for (unsigned int j = 0; j < n; j++) {
			if (j < i)
				matrizL.matriz[j][i] = 0;
			else {
				matrizL.matriz[j][i] = matriz[j][i];
				for (unsigned int k = 0; k < i; k++) {
					matrizL.matriz[j][i] = matrizL.matriz[j][i] - matrizL.matriz[j][k] * matrizU.matriz[k][i];
				}
			}
		}		
		for (unsigned int j = 0; j < n; j++) {
			if (j < i)
				matrizU.matriz[i][j] = 0;
			else if (j == i)
				matrizU.matriz[i][j] = 1;
			else {
				matrizU.matriz[i][j] = matriz[i][j] / matrizL.matriz[i][i];
				for (unsigned int k = 0; k < i; k++) {
					matrizU.matriz[i][j] = matrizU.matriz[i][j] - ((matrizL.matriz[i][k] * matrizU.matriz[k][j]) / matrizL.matriz[i][i]);
				}
			}
		}
		for (unsigned int x = 0; x < n; x++) {
			for (unsigned int z = 0; z < n; z++) {
				resultado[x][z] = matrizL.matriz[x][z];
			}
		}
	}
}

void CalculosAlgebra::descomposicionLU() {
	CalculosAlgebra matrizL(filas, columnas);
	CalculosAlgebra matrizU(filas, columnas);
	unsigned int n = dimension;
	for (unsigned int i = 0; i < n; i++) {
		for (unsigned int j = 0; j < n; j++) {
			if (j < i)
				matrizL.matriz[j][i] = 0;
	      else {
				matrizL.matriz[j][i] = matriz[j][i];
	         for (unsigned int k = 0; k < i; k++) {
					matrizL.matriz[j][i] = matrizL.matriz[j][i] - matrizL.matriz[j][k] * matrizU.matriz[k][i];
				}
			}
		}		
		for (unsigned int j = 0; j < n; j++) {
			if (j < i)
				matrizU.matriz[i][j] = 0;
			else if (j == i)
				matrizU.matriz[i][j] = 1;
			else {
				matrizU.matriz[i][j] = matriz[i][j] / matrizL.matriz[i][i];
				for (unsigned int k = 0; k < i; k++) {
					matrizU.matriz[i][j] = matrizU.matriz[i][j] - ((matrizL.matriz[i][k] * matrizU.matriz[k][j]) / matrizL.matriz[i][i]);
				}
			}
		}
	}
	std::cout << "Matriz L"<< "\n";
	matrizL.mostrarMatriz();
	
	std::cout << "\n" << "Matriz U"<< "\n";
	matrizU.mostrarMatriz();
}

void CalculosAlgebra::sumaDeMatrices() {
	//CalculosAlgebra matrizResultado(filas, columnas);
	//matrizResultado.mostrarMatriz();
	for (unsigned int i = 0; i < filas; i++) {
		for (unsigned int j = 0; j < columnas; j++) {
			resultado[i][j] = matriz[i][j]+matriz[i][j];
		}
	}
}

void CalculosAlgebra::Kronecker() {
	}

void CalculosAlgebra::multiplicacionDeMatrices() {
	Matriz matrizResultado(filas, columnas);
	matrizResultado.crearMatrizVacia();
	for (unsigned int i = 0; i < filas; i++) {
		for (unsigned int j = 0; j < columnas; j++) {
			//matrizResuelta[i][j] = 0;
			for (unsigned int k = 0; k < filas; k++) {
				//matrizResuelta[i][j] += matriz[i][k] * matriz[k][j];
			}
		}
	}
}

/*
(*---procedimiento para multiplicar matrices---*)

Procedure MultiplicarMat(m1,m2: Matriz; var resul:Matriz);
	Var
		i,j,k:1 .. W;
	Begin
		for i:=1 to dimension do
		for j:=1 to dimension do
		begin
			resul[i,j]:=0;
			for k:=1 to dimension do
			resul[i,j]:=resul[i,j]+m1[i,k]*m2[k,j];
		end;
	End;	(*MultiplicarMat*)*/
