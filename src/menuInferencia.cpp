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

#include "cli.hpp"
#include "calculos1Var.hpp"

/*bool Menu1Var::preguntarSiAgrupados(){
	char respuesta;
	bool agrupados;
	std::cout << '\n';
	std::cout << "¿Los datos están agrupados?" << '\n';
	std::cout << "s/n:";
	std::cin >> respuesta;
	respuesta == 's' ? agrupados = true : agrupados = false;
	return agrupados;
}*/

void CLI::menuSecundarioInferencia() {
	tamanyo = preguntarNumeroElementos();
	desdeArchivo = preguntarDesdeArchivoOTeclado();
	Vector vectorA(tamanyo);
	
	if (desdeArchivo == true) {
		verificarArchivo();
		leerDesdeArchivo(vectorA);
	} else {
		std::cout << "Introduce los elementos uno a uno" << "\n";
		std::cout << "separando con un espacio." << "\n";
		for (unsigned int i = 0; i < vectorA.size(); i++) {
			std::cin >> vectorA[i];
		}
		std::cout << '\n';
	}
	std::cout << '\n';
	std::cout << ("vector ") << "\n";
	mostrarVector(vectorA);
}
