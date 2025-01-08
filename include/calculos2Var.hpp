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

#ifndef _CALCULOS2VAR_HPP_
#define _CALCULOS2VAR_HPP_

#include "vector.hpp"
#include "matriz.hpp"
#include "calculos1Var.hpp"

		Vector extraerVariable(Matriz &m1, unsigned int variable); 
		double sumatoria2Var (Matriz &m1, int exponenteX, int exponenteY );
		double covarianza(Matriz &m1);
		
		double rectaRegresion(Matriz &m1, Vector &v1);
		double curvaRegresion(Matriz &m1, Vector &v1);
		double coeficienteRegresion(Matriz &m1, Vector &v1);
		
		double coeficienteCorrelacion(Matriz &m1);		
		
		double distanciaEuclidea();
		//double ecm(double variableDependiente, double variableIndependiente);

#endif /* _CALCULOS2VAR_HPP_ */
