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
#include "calculosNVar.hpp"

void CLI::menuSecundarioNvar() {
		//char opciones;
    unsigned int filas, columnas;
    filas = numeroFilas();
    columnas = numeroColumnas();
    //bool desdeArchivo;
    desdeArchivo = preguntarDesdeArchivoOTeclado();
    Matriz matrizA(filas, columnas);
    if (desdeArchivo == true) {
        verificarArchivo();
        leerDesdeArchivo(matrizA, columnas);
    } else {
        std::cout << "Introduce los elementos uno a uno " << "\n";
        std::cout << "pulsa intro para escribir la fila siguiente" << "\n";
        std::cout << "\n";
        editarMatrizVacia(matrizA);
    }
    std::cout << '\n';
    std::cout << ("Matriz ") << "\n";
    mostrarMatriz(matrizA);
    std::cout << '\n';
    std::cout << sumatoria(matrizA, 1, 1) << '\n';
		/*char eleccionNivel2;
	std::cout << "'1' Funciones de estadística descriptiva n-dimensional." << '\n';
	std::cout << "'2' Matriz P (Procesos estocásticos)"  << '\n';
	std::cout << "'0' Salir." << '\n';
	std::cout << "> ";
	std::cin >> eleccionNivel2;
	switch ( eleccionNivel2 ) {
		case '1' :
			///menuNVar();
			break;
		case '2' :
			menuProcesos(); 
			break;
	}*/
}

void CLI::menuProcesos() {
	/*unsigned int n;
	CalculosNVar matrizA (preguntarDesdeArchivoOTeclado(), preguntarNumeroFilas(), preguntarNumeroColumnas());
	matrizA.leerMatriz();
	std::cout << '\n';
	std::cout << "Valor de n: ";
	std::cin >> n;
	std::cout << "Matriz A" << '\n';
	matrizA.mostrarMatriz();
	matrizA.matrizTransicionP(n);
	std::cout << "Matriz P" << '\n';
	//matrizA.mostrarMatrizResuelta();*/
}
