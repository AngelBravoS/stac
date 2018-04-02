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

#include <iostream>
#include "cli.hpp"

void CLI::menuSinDatos() {
	char eleccionNivel2;
	std::cout << "'1' Combinatoria." << '\n';
	std::cout << "'2' Inteligencia artificial."  << '\n';
	std::cout << "'3' Distribuciones de probabilidad discretas." << '\n';
	std::cout << "'0' Salir." << '\n';
	std::cout << "> ";
	std::cin >> eleccionNivel2;
	switch ( eleccionNivel2 ) {
		case '1' :
			menuCombinatoria();
			break;
		case '2' :
			menuIA();
			break;
		case '3' :
			menuDistribDiscreta();
			break;
	}
}
