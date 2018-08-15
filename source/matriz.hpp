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

#ifndef _MATRIZ_HPP_
#define _MATRIZ_HPP_

class Matriz {
	public:
		//======== constructor ======== 
		Matriz();
		//======== setters y getters ======== 
		double getMatriz();
		void setMatriz ( double **matrizPublica );
		double getMatrizB();
		void setMatrizB ( double **matrizBPublica );
		//======== entrada/salida ========  
		void desdeDondeLeeMatriz();
		void verificarArchivo();
		void leerDatosDesdeArchivo();
		void leerDatosDesdeTeclado();
		void guardarEnArchivo();
		//======== funciones de la matriz de datos ======== 
		void setDimensionMatriz();
		void crearMatrizVacia();
		void crearMatrizVaciaB();
		void editarMatrizVacia();
		void mostrarMatriz ();
		void mostrarMatrizB ();
		void copiarDimensionMatriz();
		void copiarMatriz();
	protected:
		unsigned int fila, filaB;
		unsigned int columna, columnaB;
		double **matriz;
		double **matrizB;
		bool leerDesdeArchivo;
};

#endif /* _MATRIZ_HPP_ */
