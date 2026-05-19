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

#pragma once

#include "funcMatematicasBasicas.hpp"

class ModeloColas {
protected:
  double lambda;
  double mu;
  unsigned int n;
  double ro;

public:
  ModeloColas();
  ModeloColas(double lambda, double mu, unsigned int n);

  double p0() const;
  double pn() const;
  double lq() const;
  double wq() const;
  double w() const;
  double l() const;
};
