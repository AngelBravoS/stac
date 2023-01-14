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

//CLI => Command Line Interface.
#include "cli.hpp"
#include "mas.hpp"
#include "calculos1Var.hpp"
#include "calculosNVar.hpp"

void CLI::menuSecundarioMuestreo() {
	unsigned int valorDeN = 0, estimadorSelec = 0, tipoMuestreo = 0, filas = 1;
	bool agrupados;

	tipoMuestreo = preguntarTipoDeMuestreo();

	desdeArchivo = preguntarDesdeArchivoOTeclado();
	agrupados = preguntarSiAgrupados();

	if (agrupados == true) {
		filas++;
	}

	if (preguntarSiNExiste() == true) {
		std::cout << "valor de N: ";
		std::cin >> valorDeN;
	}

	tamanyo = preguntarNumeroColumnas(agrupados);
	estimadorSelec = preguntarEstimador();

	Matriz muestra(filas, tamanyo);

	if (desdeArchivo == true) {
		verificarArchivo();
		leerDesdeArchivo(muestra, tamanyo);
	}

	switch (tipoMuestreo) {
		case 1: {  //MAS
			if (agrupados == true) {
				std::cout << "Introduce cada dato de la muestra uno a uno " << "\n";
				std::cout << "y después pulsa intro para escribir su total" << "\n";
				std::cout << "\n";
			} else {
				std::cout << "Introduce cada dato de la muestra uno a uno " << "\n";
				std::cout << "\n";
			}
			MAS muestreo(muestra);
			
		}
		break;
		case 2:
			//MuestreoConReempIguales muestra(filas, tamanyo);
			if (agrupados == true) {
				std::cout << "Introduce cada dato de la muestra uno a uno " << "\n";
				std::cout << "y después pulsa intro para escribir su total" << "\n";
				std::cout << "\n";
			} else {
				std::cout << "Introduce cada dato de la muestra uno a uno " << "\n";
				std::cout << "\n";
			}
			break;
		case 3:
			filas ++;
			//MuestreoSinReempDesigual muestra(filas, tamanyo);

			break;
		case 4:
			filas ++;
			//MuestreoConReempDesigual muestra(filas, tamanyo);

			break;
	}

	editarMatrizVacia(muestra);
	mostrarMatriz(muestra);
	std::cout << '\n';
	std::cout << "Sumatorias, estadísticos y varianzas" << '\n';
	std::cout << '\n';
	std::cout << "∑Xi = " << sumatoria(muestra, 0, 1) << '\n';
	std::cout << "   2" << '\n';
	std::cout << "∑Xi = " << sumatoria(muestra, 0, 2) << '\n';
	std::cout << "     _ 2" << '\n';
	std::cout << "∑(Xi-X) = " << difRespecMedia(muestra, 0, 2) << '\n';
	std::cout << '\n';

	/*
		std::cout << "Estimador = " << calcularEstimador() << '\n';
		std::cout << '\n';

		std::cout << "Var = " << varianza() << '\n';
		std::cout << " 2" << '\n';
		std::cout << "S = " << varianzaMuestral() << '\n';
		std::cout << '\n';

		std::cout << "Varianzas del estimador = ";
		std::cout << varianzaEstimador() << '\n';
		std::cout << '\n';

		std::cout << "Error de estimación del parámetro = ";
		std::cout << em() << '\n';
		std::cout << '\n';*/
}
