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

#include "funcMatematicasBasicas.hpp"

double poisson ( float p, unsigned int probabilidad );

double bernouilli ( float p, unsigned int probabilidad );
double binomial ( unsigned int N, float p,
                  unsigned int probabilidad );
double binomialNegativa ( unsigned int n, float p,
                          unsigned int probabilidad );
double hipergeometrica ( unsigned int N, unsigned int n,
                         unsigned int r, unsigned int probabilidad );

double geometrica ( float p, unsigned int probabilidad );
double multinomial ( unsigned int n, float p,
                     unsigned int probabilidad );
