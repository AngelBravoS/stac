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

#include "mmc.hpp"

MMC::MMC() {}

MMC::MMC(double lambda, double mu, unsigned int nUsuario, unsigned int cUsuario)
    : ModeloColas(lambda, mu, nUsuario), r(lambda / mu), c(cUsuario),
      nMayorC(!(1 <= nUsuario && nUsuario < cUsuario)) {
  ro = lambda / (c * mu);
}

double MMC::p0() const {
  double suma = 0.0;
  for (unsigned int i = 0; i < c; ++i)
    suma += potencia(r, i) / factorial(i);
  double segundo = (c * potencia(r, c)) / (factorial(c) * (c - r));
  return 1.0 / (suma + segundo);
}

double MMC::pn() const {
  if (!nMayorC)
    return (1.0 / factorial(n)) * potencia(r, n) * p0();
  return (1.0 / (potencia(c, n - c) * factorial(c))) * potencia(r, n) * p0();
}

double MMC::lq() const {
  return p0() * (ro * potencia(r, c)) / (factorial(c) * potencia(1.0 - ro, 2));
}

double MMC::wq() const { return lq() / lambda; }

double MMC::w() const { return wq() + 1.0 / mu; }

double MMC::l() const { return lambda * w(); }
