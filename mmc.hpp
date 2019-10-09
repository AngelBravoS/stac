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

#ifndef _MMC_HPP_
#define _MMC_HPP_

#include "modelo.hpp"

class MMC : public Modelo {
    protected:
    double r;
    unsigned int c;
    bool nMayorC;
    public:
    //======== Constructores ========
    MMC ();
    MMC ( double lambda, double mu, unsigned int n, unsigned int c );
    //======== Funciones específicas ========
    double p0 () {
        double resultado, primerSumando, segundoSumando;
		  unsigned int i = 0;
		  unsigned int fin = c-1;
        primerSumando = 0;
        segundoSumando = 0;
        while (i <= fin) {
            primerSumando += potencia ( r, i ) / factorial ( i );
				++i;
		}
        segundoSumando = ( c*potencia ( r,c ) ) / ( factorial ( c ) * ( c-r ) );
        resultado = 1/(primerSumando+segundoSumando);
        return resultado;
    }
    double pn () {
        double resultado;
    	if (nMayorC == false) {
			resultado = 1/factorial(n)*potencia(r,n)*p0();
    	} else {
			resultado = 1/(potencia(c,n-c)*factorial(c))*potencia(r,n)*p0();
    	}
		return resultado;
    }
    double lq () {
        double resultado;
			resultado = p0()*(ro*potencia(r,c))/(factorial(c)*potencia((1-ro),2));
        return resultado;
    }
    double wq () {
        double resultado;
        resultado = lq() / lambda;
        return resultado;
    }
    double w() {
        double resultado;
        resultado = wq () + ( 1/mu );
        return resultado;
    }
    double l () {
        double resultado;
        resultado = lambda * w();
        return resultado;
    }
};

#endif /* _MMC_HPP_ */
