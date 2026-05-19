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

#include "mmInfinit.hpp"

MMINFINIT::MMINFINIT() {}

MMINFINIT::MMINFINIT(double lambda, double mu, unsigned int nUsuario)
    : ModeloColas(lambda, mu, nUsuario), r(lambda / mu) {}

double MMINFINIT::p0() const { return 1.0 / potencia(e(), convierteDoubleEnInt(r)); }

double MMINFINIT::pn() const { return (1.0 / factorial(n)) * potencia(r, n) * p0(); }

double MMINFINIT::lq() const { return 0.0; }

double MMINFINIT::wq() const { return 0.0; }

double MMINFINIT::w() const { return 1.0 / mu; }

double MMINFINIT::l() const { return r; }
