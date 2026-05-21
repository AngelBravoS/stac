/***************************************************************************
 *   Copyright (C) 2018 by Ángel Bravo Sáenz                               *
 *   angelbravosaenz@gmail.com                                             *
 *                                                                         *
 *   This file is part of Stac.                                            *
 *                                                                         *
 *   Stac is free software; you can redistribute it and/or modify          *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; version 2 of the License.               *
 ***************************************************************************/

#pragma once

#include <cmath>
#include "funcMatematicasBasicas.hpp"
#include "vector.hpp"

double sumatoria(Vector &variable, unsigned int exponente);
double mediaAritmetica(Vector &variable);
double mediaGeometrica(Vector &variable);
double mediaArmonica(Vector &variable);
double mediaCuadratica(Vector &variable);
double mediana(Vector &variable);
Vector moda(Vector &variable);

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
