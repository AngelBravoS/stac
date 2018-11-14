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

#ifndef _MMIK_HPP_
#define _MMIK_HPP_

#include "modelo.hpp"

class MMIK : public Modelo {
    protected:
    unsigned int k;
    double r, lambdaA;
    bool rIgual1;
    public:
    //======== Constructores ========
    MMIK ();
    MMIK ( double lambda, double mu, unsigned int n );
    //======== Funciones específicas ========
    double p0 () {
        double resultado;
        if ( rIgual1 == true ) {
            resultado = 1/ ( k+1 );
        } else {
            resultado = ( 1-r ) / ( 1 - potencia ( r, k+1 ) );
        }
        return resultado;
    }
    double pn () {
        double resultado;
        if ( rIgual1 == true ) { // Distribución uniforme
            resultado = 1/ ( k+1 );
        } else { //Distribución geométrica truncada
            resultado = potencia ( r, k ) * p0();
        }
        return resultado;
    }
    double lq () {
        double resultado;
        if ( rIgual1 == true ) { // Distribución uniforme
            resultado = ( k/2 )-ro;
        } else { //Distribución geométrica truncada
            double numerador;
            double denominador;
            numerador = r* ( k*potencia ( r, k+1 )- ( k+1 ) *potencia ( r,k )+1 );
            denominador = ( 1-potencia ( r, k+1 ) ) * ( 1-r );
            resultado = ( numerador/denominador )-ro;
        }
        return resultado;
    }
    double wq () {
        double resultado;
        resultado = lq() / lambdaA;
        return resultado;
    }
    double w() {
        double resultado;
        resultado = wq () + ( 1/mu );
        return resultado;
    }
    double l () {
        double resultado;
        resultado = lambdaA * w();
        return resultado;
    }
};

#endif /* _MMIK_HPP_ */
