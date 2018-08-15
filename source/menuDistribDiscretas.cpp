/***************************************************************************
 *   Copyright (C) 2018 by Ángel Bravo Sáenz                               *
 *   angelbravosaenz@gmail.com                                             *
 *                                                                         *
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
#include "distribucionesDiscretas.hpp"

void CLI::menuDistribDiscreta() {
    char eleccionNivel2;
	 unsigned int n, N, r, k, probabilidad;
	 float p; 
    do {
        std::cout << "Distribuciones a elegir:" << '\n';
        std::cout << "'1' Bernouilli." << '\n';
        std::cout << "'2' Binomial." << '\n';
        std::cout << "'3' Binomial negativa." << '\n';
        std::cout << "'4' Hipergeométrica." << '\n';
        std::cout << "'5' Poisson." << '\n';
        std::cout << "'6' Geométrica." << '\n';
        std::cout << "'0' Volver al menú principal." << '\n';
        std::cout << "> ";
        std::cin >> eleccionNivel2;
		  std::cout << "======================================= " << '\n';
        std::cout << "Valor de x: ";
        std::cin >> probabilidad;
        switch ( eleccionNivel2 ) {
        case '1': //Bernouilli
			  std::cout << "Valor de p: ";
			  std::cin >> p;
			  std::cout << "Distribución Bernuilli X~>B("<< p << ")" << '\n';
			  std::cout << "P[X=" << probabilidad << "]" << " = "<<
			  bernouilli ( p, probabilidad ) << '\n';
            break;
        case '2': //Binomial
			  std::cout << "Valor de p: ";
			  std::cin >> p;
			  std::cout << "Valor de n: ";
			  std::cin >> n;
			  std::cout << "Distribución Binomial X~>B("<< n << ","<<
			  p << ")" << '\n';
				std::cout << "P[X=" << probabilidad << "]" << " = "<<
				binomial ( n, p, probabilidad ) << '\n';
            break;
        case '3': //Binomial negativa
			  std::cout << "Valor de p: ";
			  std::cin >> p;
			  std::cout << "Valor de n: ";
			  std::cin >> n;
			  std::cout << "Distribución Binomial negativa X~>BN("<< n <<
			  "," << p << ")" << '\n';
				std::cout << "P[X=" << probabilidad << "]" << " = "<<
				binomialNegativa ( n, p, probabilidad ) << '\n';
            break;
        case '4': //Hipergeometrica
			  std::cout << "Parámetro N: ";
			  std::cin >> N;
			  std::cout << "Parámetro n: ";
			  std::cin >> n;
			  std::cout << "Parámetro r: ";
			  std::cin >> r;
			  std::cout << "Distribución Hipergeométrica X~>H("<< N <<
			  ","<< n << "," << r << ")" << '\n';
				std::cout << "P[X=" << probabilidad << "]" << " = "<<
				hipergeometrica ( N, n, r, probabilidad ) << '\n';
            break;
        case '5': //Poisson
			  std::cout << "Valor de lambda: ";
			  std::cin >> p;
			  std::cout << "Distribución Poisson X~>P("<< p << ")" << '\n';
			  std::cout << "P[X=" << probabilidad << "]" << " = "<<
			  poisson ( p, probabilidad ) << '\n';
            break;
        case '6': //Geometrica
			  std::cout << "Valor de p: ";
			  std::cin >> p;
			  std::cout << "Distribución Geométrica X~>G(" << p << ")" << '\n';
			  std::cout << "P[X=" << probabilidad << "]" << " = "<< geometrica ( p, probabilidad ) << '\n';
            break;
        case '7': //Multinomial
			  std::cout << "Número de probabilidades asociadas: ";
			  std::cin >> k;
            /*crearMultinomial(k);
             f or ( unsign*ed short int i = 0; i < k; i++ ) {
            }
            */
				std::cout << "Distribución Multinomial X~>M(" << p << ")" << '\n';
				std::cout << "P[X=" << probabilidad << "]" << " = "<< geometrica ( p, probabilidad ) << '\n';
            break;
            break;
        }
        std::cout << "============================================= " << '\n';
        std::cout << '\n';
    } while ( eleccionNivel2 != '0' );
}
