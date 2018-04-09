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

//CLI => Command Line Interface.
#include <iostream>
#include "menuMuestreo.hpp"

void MenuMuestreo::menuMuestreo() {
   listadOpcionesMuestreo();
	eleccion();
	std::cout << '\n';
	switch(muestra.getTipoMuestreo()) {
		case '1' :
			muestra.setReemplazo(false);
			muestra.setProbIguales(true);
			break;
		case '2' :
			muestra.setReemplazo(true);
			muestra.setProbIguales(true);
			break;
		case '3' :
			muestra.setReemplazo(false);
			muestra.setProbIguales(false);
			break;
		case '4' :
			muestra.setReemplazo(true);
			muestra.setProbIguales(false);
			break;
		case '8' :
			std::cout << "¿Los conglomerados tienen el mismo tamaño?" << '\n';
			std::cout << "s/n:";
			eleccion();
			if (getOpcionSeleccionada() == 's'){muestra.setMismoTamanyo(true);} else {muestra.setMismoTamanyo(false);}
			break;
	}
	std::cout << "¿Los datos se leerán desde un archivo?" << '\n';
	std::cout << "s/n:";
	eleccion();
	if (getOpcionSeleccionada() == 's'){muestra.setLeeArchivo(true);} else {muestra.setLeeArchivo(false);}
	std::cout << "¿Están agrupados?" << '\n';
	std::cout << "s/n:";
	eleccion();
	if (getOpcionSeleccionada() == 's'){muestra.setAgrupados(true);} else {muestra.setAgrupados(false);}
}

void MenuMuestreo::definirTipoMuestreo() {	
	int n;
	if(muestra.getAgrupados() == true) {
		std::cout << "Número de datos distintos que contiene la muestra: ";
	} else {
		std::cout << "Tamaño de la muestra: ";
	}
	std::cin >> n;
	muestra.setColumna(n);
}

void MenuMuestreo::recogerDatosMuestra() {
	muestra.setFila(5);
	muestra.crearMatrizVacia();
	switch(muestra.getTipoMuestreo()) {
	case '1' :
	case '2' :
	case '3' :
	case '4' :
		if(muestra.getLeeArchivo() == true) {
			verificarArchivo();
			muestra.leerDatosDesdeArchivo();
		} else {
			muestra.leerDatosDesdeTeclado();
		}
		muestra.incorporarXiYXi2();
		break;
	case '5' :
	case '6' :
	case '7' :
	case '8' :
		std::cout << "No tan deprisa...";
		std::cout << '\n';
		break;
	}
}

void MenuMuestreo::mostrarDatosMuestra() {
	std::cout << '\n';
	std::cout << "Tabla de datos:" << '\n';
	muestra.mostrarMatriz();
	std::cout << '\n';
	muestra.setSumatoriaXi(muestra.calculoSumatoria(0, 1));
	muestra.setSumatoriaXi2(muestra.calculoSumatoria(0, 2));
	muestra.setMedia(muestra.calculoMediaAritmetica(0));
	std::cout << "∑Xi = " << muestra.getSumatoriaXi();
	std::cout << ", ∑Xi^2 = " << muestra.getSumatoriaXi2();
	std::cout << ", media  = " << muestra.getMedia() << '\n';
	std::cout << '\n';
}

void MenuMuestreo::verificarArchivo() {
	std::fstream archivo;
	archivo.open("datos.dat", std::ios::in | std::ios::binary);
	if(archivo.is_open()) {
		std::cout << "Fichero leído" << '\n';
	} else {
		std::cout << "Fichero inexistente" << '\n';
		exit(-1);
	}
}
