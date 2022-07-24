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

#ifndef _CALCULOSALGEBRA_HPP_
#define _CALCULOSALGEBRA_HPP_

#include "vector.hpp"
#include "matriz.hpp"

Matriz operator+(Matriz &m1, Matriz &m2);

Matriz operator*(Matriz &m1, double scalar);
Matriz operator*(double scalar, Matriz &m1);
Matriz operator*(Matriz &m1, Matriz &m2);

Matriz scalar_multiplication(Matriz &m1, double scalar);

Vector vectorDiagonal(Matriz &m1);

double traza(Matriz &m1);
double determinante(Matriz &m1);

Matriz identidad(unsigned int rows, unsigned int cols);
Matriz traspuesta(Matriz &m1);
Matriz adjunta(Matriz &m1);
Matriz triangular(Matriz &m1);
Matriz inversa(Matriz &m1);
Matriz gauss(Matriz &m1);
Matriz gaussJordan(Matriz &m1);
Matriz descomposicionLU(Matriz &m1, bool devolverL);
Matriz Kronecker();


#endif /* _CALCULOSALGEBRA_HPP_ */

