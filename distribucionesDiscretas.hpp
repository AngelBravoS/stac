/***************************************************************************														*
 *   Copyright (C) 2018 by Ángel Bravo Sáenz  										*
 *   angelbravosaenz@gmail.com  															*
 *																									*
 *   This file is part of Stac.                                            *
 *                                                                         *
 *   Stac is free software; you can redistribute it and/or modify          *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
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

double bernouilli(float parametroP, unsigned short int probabilidad);

double binomial(unsigned short int parametroN, float parametroP, 
	unsigned short int probabilidad);

double binomialNegativa(unsigned short int parametron, float parametroP, 
	unsigned short int probabilidad);

double hipergeometrica(unsigned short int parametroN, unsigned short int parametron, 
		unsigned short int parametror, unsigned short int probabilidad);

double poisson(float parametroP, unsigned short int probabilidad);

double geometrica(float parametroP, unsigned short int probabilidad);
