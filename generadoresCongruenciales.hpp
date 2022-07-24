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

#ifndef CALCULOSIA_HPP_INCLUDED
#define CALCULOSIA_HPP_INCLUDED

#include <vector>
#include <iostream>
#include "vector.hpp"
#include "funcMatematicasBasicas.hpp"

class GeneradoresCongruenciales : public Vector {
	public:
		//======== constructor ========
		GeneradoresCongruenciales();
		GeneradoresCongruenciales(unsigned int parametro_a, unsigned int 
parametro_b,
		           unsigned int parametro_m, unsigned int parametro_X0);
		GeneradoresCongruenciales(unsigned int parametro_a, unsigned int 
parametro_b,
		           unsigned int parametro_m);

		//========  funciones  ========
		bool sonCongruentesFactoresPrimoQ();
		bool sonCongruentesFactoresPrimoP();
		bool esMCongruente4();

		bool mEsPotenciaDe2();
		unsigned int generador(unsigned int X0);

		void crearSecuencia();
		void mostrarSecuencia();

		bool cumpleTeoremaKnuth();
		void comprobarPeriodo(char tipoGenerador);
		void mostrarComprobacionPeriodo();

	protected:
		unsigned int a;
		unsigned int b;
		unsigned int m;
		unsigned int X0;
		bool periodoCompleto;
		bool periodoMaximo;
		std::vector<unsigned int> secuencia;
};

#endif // CALCULOSIA_HPP_INCLUDED
