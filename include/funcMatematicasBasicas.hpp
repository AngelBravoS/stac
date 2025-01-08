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
#ifndef FUNCMATEMATICASBASICAS_HPP_INCLUDED
#define FUNCMATEMATICASBASICAS_HPP_INCLUDED

#include <algorithm> 
#include <math.h>

double factorial(double n);
double potencia(double numero, unsigned int potencia);
double potenciaDouble(double numero, double potencia);
double binomio(double a, double b);
double e();

unsigned int gcd(unsigned int a , unsigned int b);
bool esMultiplo(unsigned int numero1, unsigned int numero2);
bool esPrimo (unsigned int numero);
bool sonCoprimos (unsigned int numero1, unsigned int numero2);
bool sonCongruentes (unsigned int numero1, unsigned int numero2, unsigned int numero3);

unsigned int convierteDoubleEnInt (double doble);
unsigned int convierteLongEnInt(unsigned long unsignedlong);
float convierteIntEnFloat(unsigned int entero);
double convierteIntEnDouble(unsigned int entero);

#endif // FUNCMATEMATICASBASICAS_HPP_INCLUDED
