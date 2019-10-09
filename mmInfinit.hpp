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

#ifndef _MMINFINIT_HPP_
#define _MMINFINIT_HPP_

#include "modelo.hpp"

class MMINFINIT : public Modelo {
    protected:
    double r;
    public:
    //======== Constructores ========
    MMINFINIT ();
    MMINFINIT ( double lambda, double mu, unsigned int n );
    //======== Funciones específicas ========
    double p0 () {
        double resultado;
        resultado = 1/potencia ( e(), r );
		  return resultado;
    }
    double pn () {
        double resultado;
			resultado = 1/factorial(n)*potencia(r,n)*p0();
        return resultado;
    }
    double lq () {
        double resultado = 0;
        return resultado;
    }
    double wq () {
        double resultado = 0;
        return resultado;
    }
    double w () {
        double resultado = 1/mu;
        return resultado;
    }
    double l () {
        double resultado = r;
        return resultado;
    }
};

#endif /* _MMINFINIT_HPP_ */
