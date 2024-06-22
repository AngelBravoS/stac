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

#ifndef _CALCULOS1VAR_HPP_
#define _CALCULOS1VAR_HPP_

#include <cmath>
#include "vector.hpp"

double sumatoria(Vector &variable, unsigned int exponente);
double mediaAritmetica(Vector &variable);
double mediaGeometrica(Vector &variable);
double mediaArmonica(Vector &variable);
double mediaCuadratica(Vector &variable);
double mediana(Vector &variable);
double moda(Vector &variable);

double difRespecMedia(Vector &variable, int exponente);
double momentosNoCentrados(Vector &variable, int exponente);

double varianza(Vector &variable);
double varianzaMuestral(Vector &variable);
double desviacionTipica(Vector &variable);
double desviacionTipicaMuestral(Vector &variable);

double coeficienteVarPearson(Vector &variable);

double coeficienteAsimetriaPearson(Vector &variable);
double coeficienteAsimetriaFisher(Vector &variable);
double coefApuntFisher(Vector &variable);
double norma(Vector &variable);

#endif /* _CALCULOS2VAR_HPP_ */
