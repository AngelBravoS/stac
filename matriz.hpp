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

#ifndef _MATRIZ_HPP_
#define _MATRIZ_HPP_

class Matriz {
	public:
		//======== constructor ======== 
		Matriz();
		Matriz(unsigned int longitudFila, unsigned int longitudColumna);
		//======== entrada/salida ========  
		void leerMatriz();
		void verificarArchivo();
		void leerDesdeArchivo();
		void leerDesdeTeclado();
		void guardarEnArchivo();
		//======== funciones de la matriz de datos ======== 
		void setDimensionMatriz();
		void crearMatrizVacia();
		void editarMatrizVacia();
		void mostrarMatriz();
		void crearMatrizResultado();
		void mostrarResultado();
		double **resultado;
	protected:
		unsigned int filas;
		unsigned int columnas;
		unsigned int dimension;
		double **matriz;
		
		bool desdeArchivo;
		bool cuadrada;
		bool regular;
};

#endif /* _MATRIZ_HPP_ */
