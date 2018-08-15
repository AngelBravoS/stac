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

#ifndef _DISTRIBUCIONESDISCRETAS_HPP_
#define _DISTRIBUCIONESDISCRETAS_HPP_

#include "distribucionesDiscretas.hpp"
#include <math.h>

double poisson ( float parametroP, unsigned int probabilidad ) {
    double resultado;
    float lambda = parametroP;
    unsigned int x = probabilidad;
    resultado = ( pow ( e(), -lambda ) ) * ( pow ( lambda, x ) / factorial ( x ) );
    //resultado = (potencia(e(), -lambda)) * (potencia(lambda, x) / factorial(x));
    return resultado;
}

double bernouilli ( float p, unsigned int x ) {
    double resultado;
    resultado = potencia ( p, x ) * potencia ( 1 - p, x - 1 );
    return resultado;
}

double binomial ( unsigned int n, float p,
                  unsigned int x ) {
    double resultado;
    float q = ( 1 - p );
    if ( n > 50 && p <= 0.1 ) {
        resultado = poisson ( n * convierteDoubleEnInt ( p ), x );
    } else {
        resultado = binomio ( n, x ) * potencia ( p, x ) * potencia ( q, n - x );
    }
    return resultado;
}

double binomialNegativa ( unsigned int parametron, float parametroP,
                          unsigned int probabilidad ) {
    double resultado;
    unsigned int n = parametron;
    float p = parametroP;
    unsigned int x = probabilidad;
    resultado = binomio ( n + ( x - 1 ), x ) * potencia ( p, n ) * potencia ( 1 - convierteDoubleEnInt ( p ), x );
    return resultado;
}

double hipergeometrica ( unsigned int N, unsigned int n,
                         unsigned int r,
                         unsigned int probabilidad ) {
    unsigned int x = probabilidad;
	 float p = convierteIntEnFloat(r)/convierteIntEnFloat(N);
    double resultado;
    if ( n<0.1*N ) {
        resultado = binomial ( n, p, x );
    } else {
        resultado = binomio ( r,x ) * binomio ( ( N-r ), ( n-x ) ) / binomio ( N,n );
    }
    return resultado;
}

double geometrica ( float parametroP, unsigned int probabilidad ) {
    double resultado;
    float p = parametroP;
    float q = 1 - p;
    unsigned int x = probabilidad;
    resultado = ( potencia ( p * q, x - 1 ) );
    return resultado;
}

#endif /* _DISTRIBUCIONESDISCRETAS_HPP_ */
