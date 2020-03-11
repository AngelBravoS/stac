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
#include "menuIA.hpp"

void MenuIA::menuSecundario() {
	//std::cout << "Escribe ''e'' para el cálculo de funciones exponenciales." << '\n';
	std::cout << "Escribe ''g'' para el cálculo con generadores congruenciales." << '\n';
	std::cout << "> ";
	eleccion(2);
	switch(opciones[2]) {
		case 'e':
			menuColasExponencial();
			break;
		case 'g':
			menuCongruencial();
			break;
	}
}

void MenuIA::menuCongruencial() {
	unsigned int a, b, m, X0;
	do {
		listadOpcionesPricipales();
		eleccion (3);
        switch (opciones[3]) {
			case '1' : {
				listadOpcionestipoGenerador();
				eleccion (4);
				std::cout << "valor de a = ";
				std::cin >> a;
				if (opciones[4] == 'x') {
					std::cout << "valor de b = ";
					std::cin >> b;
				} else {
					b = 0;
				}
				std::cout << "valor de m = ";
				std::cin >> m;
				std::cout << "valor de Xo = ";
				std::cin >> X0;
				if ( (m <= a || m <= b) && opciones[1] == 'x') {
					std::cout << "secuencia no válida (m > a,b)." << "\n";
					exit (-1);
				} else {
					std::cout << "La secuencia es:" << '\n';
					CalculosIA gc (a, b, m, X0);
					gc.crearSecuencia();
					gc.mostrarSecuencia();
				}
            break;
			}
			case '2' : {
				listadOpcionestipoGenerador();
				eleccion (4);
                std::cout << "valor de a = ";
				std::cin >> a;
				if (opciones[4] == 'x') {
					std::cout << "valor de b = ";
					std::cin >> b;
				} else {
					b = 0;
				}
				std::cout << "valor de m = ";
				std::cin >> m;
                if (opciones[4] == 'm'){
                    std::cout << "valor de Xo = ";
                    std::cin >> X0;
                }
                switch(opciones[4]){
                    case 'x':{
                        CalculosIA gc (a, b, m);
                        gc.comprobarPeriodo (opciones[4]);
                        gc.mostrarComprobacionPeriodo();
                        break;
                    }
                    case 'm':{
                        CalculosIA gc (a, b, m, X0);
                        gc.comprobarPeriodo (opciones[4]);
                        gc.mostrarComprobacionPeriodo();
                        break;
                    }
                }
            break;
			}
            case '3' : {
                std::cout << "Uniforme= ";
                std::cout << "Bernuilli= ";
                std::cout << "Binomial= ";
            break;
			}
		}
		
	} while (opciones[2] != '0');
}

void MenuIA::menuColasExponencial() {

	
}
