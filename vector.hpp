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

#ifndef _VECTOR_HPP_
#define _VECTOR_HPP_
#include <bits/stdc++.h>
#include <vector>

class Vector {
public:
	//======== constructor ========
	Vector();
	//======== funciones de vectores ========
	void numElementosVector();
	void crearVector();
	void mostrarVector();
	void copiarvector();
	void ordenarVector();
	void destructorVector();
	//======== entrada/salida ========
	void desdeDondeLeeVector();
	void verificarArchivo();
	void leerArchivo();
	void guardarEnArchivo();
protected:
	unsigned int longitudVector;
	bool leerDesdeArchivo;
	double *vector;
	std::vector<double> variable;
	};

#endif /* _VECTOR_HPP_ */

