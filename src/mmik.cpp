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

#include "mmik.hpp"

MMIK::MMIK() {}

MMIK::MMIK(double lambda, double mu, unsigned int nUsuario)
    : ModeloColas(lambda, mu, nUsuario), k(nUsuario), r(lambda / mu),
      lambdaA(lambda * (1.0 - pn())), rIgual1(r == 1.0) {
  ro = r * (1.0 - pn());
}

double MMIK::p0() const {
  if (rIgual1)
    return 1.0 / (k + 1);
  return (1.0 - r) / (1.0 - potencia(r, k + 1));
}

double MMIK::pn() const {
  if (rIgual1)
    return 1.0 / (k + 1);
  return potencia(r, k) * p0();
}

double MMIK::lq() const {
  if (rIgual1)
    return (k / 2.0) - ro;
  double numerador = r * (k * potencia(r, k + 1) - (k + 1) * potencia(r, k) + 1.0);
  double denominador = (1.0 - potencia(r, k + 1)) * (1.0 - r);
  return (numerador / denominador) - ro;
}

double MMIK::wq() const { return lq() / lambdaA; }

double MMIK::w() const { return wq() + 1.0 / mu; }

double MMIK::l() const { return lambdaA * w(); }
