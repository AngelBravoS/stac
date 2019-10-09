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

#include <iostream>
#include "menuIO.hpp"

void MenuIO::menuSecundario() {
	unsigned int modeloSeleccionado;
	unsigned int nUsuario, cUsuario = 0;
	double lambdaUsuario, muUsuario;
	listadOpcionesColasExponencial();
	std::cin >> modeloSeleccionado;
	if (modeloSeleccionado != 0) {
		std::cout << "Valor Lambda = ";
		std::cin >> lambdaUsuario;
		std::cout << "Valor Mu = ";
		std::cin >> muUsuario;
		switch (modeloSeleccionado) {
			case 2 :
				std::cout << "Valor k para calcular Pk -0 para ninguno- = ";
				std::cin >> nUsuario;
				break;
			case 3 :
				std::cout << "Valor n para calcular Pn -0 para ninguno- = ";
				std::cin >> nUsuario;
				std::cout << "Valor c = ";
				std::cin >> cUsuario;
				break;
			default :
				std::cout << "Valor n para calcular Pn -0 para ninguno- = ";
				std::cin >> nUsuario;
				break;
			}
		std::cout << "\n";
		resultados(lambdaUsuario, muUsuario, nUsuario, cUsuario, modeloSeleccionado);
	}
	}

	void MenuIO::resultados(double lambdaUsuario, double muUsuario, unsigned int nUsuario, unsigned int cUsuario, unsigned int modeloSeleccionado) {
	std::cout << "	======== Resultados ========" << '\n';
	std::cout << "\n";
	switch (modeloSeleccionado) {
		case 1 : {
				MMI colaMMI(lambdaUsuario, muUsuario, nUsuario);
				std::cout << "Lq (Número medio de clientes en cola) = " << colaMMI.lq() << "\n";
				std::cout << "L'q (Número medio de clientes en cola cuando no está vacía) = " << colaMMI.lq2() << "\n";
				std::cout << "L (Número medio de clientes en el sistema) = " << colaMMI.l() << "\n";
				std::cout << "Wq (Tiempo medio de espera en cola) = " << colaMMI.wq() << "\n";
				//std::cout << "W'q = Tiempo medio de espera en cola cuando no está vacía" << cola.wq2() << "\n";
				std::cout << "W (Tiempo medio de espera en el sistema) = " << colaMMI.w() << "\n";
				std::cout << "P0 (Tiempo del sistema ocioso) = " << colaMMI.p0() << "\n";
				if (nUsuario != 0) {
					std::cout << "Valor P" << nUsuario << " = " << colaMMI.pn() << "\n";
					}
				break;
				}
		case 2 : {
				MMIK colaMMIK(lambdaUsuario, muUsuario, nUsuario);
				std::cout << "Valor P0" << " = " << colaMMIK.p0() << "\n";
				std::cout << "Valor P" << nUsuario << " = " << colaMMIK.pn() << "\n";
				std::cout << "Lq (Número medio de clientes en cola) = " << colaMMIK.lq() << "\n";
				std::cout << "L (Número medio de clientes en el sistema) = " << colaMMIK.l() << "\n";
				std::cout << "Wq (Tiempo medio de espera en cola) = " << colaMMIK.wq() << "\n";
				std::cout << "W (Tiempo medio de espera en el sistema) = " << colaMMIK.w() << "\n";
				break;
				}
		case 3 : {
				MMC colaMMC(lambdaUsuario, muUsuario, nUsuario, cUsuario);
				std::cout << "Valor P0" << " = " << colaMMC.p0() << "\n";
				std::cout << "Valor P" << nUsuario << " = " << colaMMC.pn() << "\n";
				std::cout << "Lq (Número medio de clientes en cola) = " << colaMMC.lq() << "\n";
				std::cout << "L (Número medio de clientes en el sistema) = " << colaMMC.l() << "\n";
				std::cout << "Wq (Tiempo medio de espera en cola) = " << colaMMC.wq() << "\n";
				std::cout << "W (Tiempo medio de espera en el sistema) = " << colaMMC.w() << "\n";
				break;
				}
		case 4 : {
				MMINFINIT colaMMINFINIT(lambdaUsuario, muUsuario, nUsuario);
				std::cout << "Valor P0" << " = " << colaMMINFINIT.p0() << "\n";
				std::cout << "Valor Pn" << " = " << colaMMINFINIT.pn() << "\n";
				std::cout << "Lq (Número medio de clientes en cola) = " << colaMMINFINIT.lq() << "\n";
				std::cout << "L (Número medio de clientes en el sistema) = " << colaMMINFINIT.l() << "\n";
				std::cout << "Wq (Tiempo medio de espera en cola) = " << colaMMINFINIT.wq() << "\n";
				std::cout << "W (Tiempo medio de espera en el sistema) = " << colaMMINFINIT.w() << "\n";
				break;
				}
		case 5 : {
				MGI colaMGI(lambdaUsuario, muUsuario, nUsuario);
				//std::cout << "Lq (Número medio de clientes en cola) = " << colaMGI.lq() << "\n";
				std::cout << "L (Número medio de clientes en el sistema) = " << colaMGI.l() << "\n";
				//std::cout << "Wq (Tiempo medio de espera en cola) = " << colaMGI.wq() << "\n";
				//std::cout << "W (Tiempo medio de espera en el sistema) = " << colaMGI.w() << "\n";
				break;
				}
		}
	std::cout << "\n";	
	}

