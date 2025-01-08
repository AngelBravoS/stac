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

// command-line interface (CLI)
#ifndef _CLI_HPP_
#define _CLI_HPP_

#include <iostream>
#include <fstream>

#include "entrada.hpp"
#include "salida.hpp"
#include "textosMenus.hpp"

class CLI {
		//Obtener = Get
		//Establecer = Set
	public:
		//======== funciones de menu ========
		void eleccion(unsigned int i);

		//======== subfunciones de menu ========
		void menuPrincipal();
		void menuSinDatos();
		void menuTablasCont();
		void menuSecundarioAlgebra();
		void menuSecundarioIA();
		void menuColExpo();
		void menuSecundario1Var();
		void menuSecundario2Var();
		void menuSecundarioNvar();
		void menuSecundarioInferencia();
		
		//======== funciones especificas de cada submenu ========
		void menu1Matriz();
		void menu2Matrices();
		void menuInferencia();
		void menuCombinatoria();
		void menuSimulacion();
		void menuColasExponencial();
		void menuDistribDiscreta();
		void menuProcesos();
		void resultadosColasExponencial(double lambdaUsuario, double muUsuario,
		                                unsigned int nUsuario, unsigned int 
																		cUsuario, unsigned int modeloSeleccionado);

	private:
		char opciones[5];
		bool archivoValido;
		bool desdeArchivo = false;
		unsigned int tamanyo = 0;
};

#endif /* _CLI_HPP_ */


