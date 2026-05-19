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

#include "modeloColas.hpp"

ModeloColas::ModeloColas() {}

ModeloColas::ModeloColas(double lambdaUsuario, double muUsuario,
                         unsigned int nUsuario)
    : lambda(lambdaUsuario), mu(muUsuario), n(nUsuario),
      ro(lambdaUsuario / muUsuario) {}

double ModeloColas::p0() const {
  return 1.0 - ro;
}

double ModeloColas::pn() const {
  return potencia(ro, n) * p0();

}

double ModeloColas::lq() const {
  return potencia(ro, 2) / (1.0 - ro);

}

double ModeloColas::wq() const {
  return lq() / lambda;

}

double ModeloColas::w() const {
  return wq() + 1.0 / mu;

}

double ModeloColas::l() const {
  return lambda * w();

}
