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

#include "mmi.hpp"

MMI::MMI() {}

MMI::MMI(double lambda, double mu, unsigned int n) : ModeloColas(lambda, mu, n) {}

double MMI::lq2() const { return 1.0 / (1.0 - ro); }
