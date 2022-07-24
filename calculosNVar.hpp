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

#ifndef _CALCULOSNVAR_HPP_
#define _CALCULOSNVAR_HPP_

#include <iostream>
#include <cmath>
#include "funcMatematicasBasicas.hpp"
#include "matriz.hpp"

double sumatoria(Matriz &m1, unsigned int indiceVariable, short unsigned
                 int exponente);
double total(Matriz &m1, unsigned int indiceVariable);
double mediaAritmetica(Matriz &m1, unsigned int indiceVariable);
double mediaGeometrica(Matriz &m1, unsigned int indiceVariable) ;
double mediaArmonica(Matriz &m1, unsigned int indiceVariable);
double mediaCuadratica(Matriz &m1, unsigned int indiceVariable);
double difRespecMedia(Matriz &m1, unsigned int indiceVariable, short
                      unsigned
                      int exponente);
double varianza(Matriz &m1, unsigned int indiceVariable);
double cuasiVarianza(Matriz &m1, unsigned int indiceVariable);
double desviacionTipica(Matriz &m1, unsigned int indiceVariable);
double cuasiDesviacionTipica(Matriz &m1, unsigned int indiceVariable);
double momentos(Matriz &m1, unsigned int indiceVariable);
double coeficientePearson(Matriz &m1, unsigned int indiceVariable);
double coeficienteAsimetriaFisher(Matriz &m1, unsigned int indiceVariable);
double curtosis(Matriz &m1, unsigned int indiceVariable);
double covarianza(Matriz &m1, unsigned int indiceVariable);
//========  funciones de procesos estocásticos ========
void matrizTransicionP(Matriz &m1, unsigned int n);

#endif /* _MATRIZ_HPP_ */
