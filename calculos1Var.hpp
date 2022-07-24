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

double sumatoria(Vector &v1, unsigned int exponente);
double mediaAritmetica(Vector &v1);
double mediaGeometrica(Vector &v1);
double mediaArmonica(Vector &v1);
double mediaCuadratica(Vector &v1);
double mediana(Vector &v1);
double moda(Vector &v1);
double difRespecMedia(Vector &v1, int exponente);
double varianza(Vector &v1);
double varianzaMuestral(Vector &v1);
double desviacionTipica(Vector &v1);
double desviacionTipicaMuestral(Vector &v1);
double momentosNoCentrados(Vector &v1, int exponente);
double coeficientePearson(Vector &v1);
double coeficienteAsimetriaFisher(Vector &v1);
double curtosis(Vector &v1);
double norma(Vector &v1);

#endif /* _CALCULOS2VAR_HPP_ */
