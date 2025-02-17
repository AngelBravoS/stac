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

#ifndef _MODELO_HPP_
#define _MODELO_HPP_

#include "funcMatematicasBasicas.hpp"

class ModeloColas {
protected:
  double lambda;
  double mu;
  double ro;
  unsigned int n;

public:
  //======== Constructores ========
  ModeloColas();
  ModeloColas(double lambdaUsuario, double muUsuario, unsigned int nUsuario);
  //======== Cálculos básicos ========
  double factorial(unsigned int k) {
    if (k == 0) {
      // Aseguramos que tenga salida siempre
      return 1;
    } else {
      // Caso general
      return k * factorial(k - 1);
    }
  }
  double potencia(double numero, unsigned int exponente) {
    double temporal = numero;
    if (exponente == 0) {
      numero = 1;
    } else {
      for (unsigned int x = 1; x < exponente; x++) {
        numero *= temporal;
      }
    }
    return numero;
  }
  double e() {
    double resultado, producto;
    resultado = 1;
    producto = 1;
    for (unsigned int i = 1; i <= 50; i++) {
      producto *= i;
      resultado += 1 / producto;
    }
    return resultado;
  }
  //======== Funciones base de todos los modelos ========
  double p0() {
    double resultado;
    resultado = 1 - ro;
    return resultado;
  }
  double pn() {
    double resultado;
    resultado = potencia(ro, n) * p0();
    return resultado;
  };
  double lq() {
    double resultado;
    resultado = potencia(ro, 2) / (1 - ro);
    return resultado;
  }
  double wq() {
    double resultado;
    resultado = lq() / lambda;
    return resultado;
  }
  double w() {
    double resultado;
    resultado = wq() + (1 / mu);
    return resultado;
  }
  double l() {
    double resultado;
    resultado = lambda * w();
    return resultado;
  }
};

#endif /* _MODELO_HPP_ */
