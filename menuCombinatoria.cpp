#include <iostream>
#include "cli.hpp"
#include "funcMatematicasBasicas.hpp"
#include "combinatoria.hpp"

void CLI::menuCombinatoria() {
	unsigned short int m, n, cantidadn;
	double resultado;
	char eleccionNivel2, eleccionNivel3;
	std::cout << "¿(p)ermutaciones, (v)ariaciones o (c)ombinaciones?." << '\n';
	std::cout << "> ";
	std::cin >> eleccionNivel2;
	std::cout << "¿Repetición? (s)í/(n)o" << '\n';
	std::cout << "> ";
	std::cin >> eleccionNivel3;
	switch(eleccionNivel2) {
		case 'p':
			switch(eleccionNivel3) {
				case 's':
					std::cout << "Permutaciones con repetición " << '\n';
					std::cout << "============================ " << '\n';
					std::cout << "" << '\n';
					std::cout << "Valor de m -> ";
					std::cin >> m;
					std::cout << "Cantidad de n diferentes -> ";
					std::cin >> cantidadn;
					resultado = 1;
					for(unsigned short int i = 0; i < cantidadn; i++) {
						std::cout << "Introducir valor de n" << (i + 1) << " " << "=> ";
						std::cin >> n;
						resultado = resultado * factorial(n);
					}
					resultado = int (convierteDoubleEnInt((factorial(m) / resultado)));
					std::cout << "" << '\n';
					std::cout << "              m! " << '\n';
					std::cout << "PRm,n = -------------- = " << resultado << '\n';
					std::cout << "         n1!*n2!..nK! " << '\n';
					std::cout << "" << '\n';
					break;

				case 'n':
					std::cout << "Permutaciones sin repetición " << '\n';
					std::cout << "============================ " << '\n';
					std::cout << "" << '\n';
					std::cout << "Valor de n -> ";
					std::cin >> n;
					resultado = int (convierteDoubleEnInt(permutaciones(n)));
					std::cout << "" << '\n';
					std::cout << "Pn = n! = " << resultado << '\n';
					break;
			}

			break;
		case 'v':
			switch(eleccionNivel3) {
				case 's':
					std::cout << "Variaciones con repetición " << '\n';
					std::cout << "============================ " << '\n';
					std::cout << "" << '\n';
					std::cout << "Valor de m -> ";
					std::cin >> m;
					std::cout << "Valor de n -> ";
					std::cin >> n;
					resultado = int (convierteDoubleEnInt(variacionesRep(m, n)));
					std::cout << "" << '\n';
					std::cout << "         n" << '\n';
					std::cout << "VRm,n = m = " <<  resultado << '\n';;
					break;

				case 'n':
					std::cout << "Variaciones sin repetición " << '\n';
					std::cout << "============================ " << '\n';
					std::cout << "" << '\n';
					std::cout << "valor de m -> ";
					std::cin >> m;
					std::cout << "valor de n -> ";
					std::cin >> n;
					resultado = int (convierteDoubleEnInt(variaciones(m, n)));
					std::cout << "" << '\n';
					std::cout << "           m! " << '\n';
					std::cout << "Vm,n = ---------- = " << resultado << '\n';
					std::cout << "         (m-n)! " << '\n';
					std::cout << "" << '\n';
					break;
			}

			break;
		case 'c':
			switch(eleccionNivel3) {
				case 's':
					std::cout << "Combinaciones con repetición " << '\n';
					std::cout << "============================ " << '\n';
					std::cout << "" << '\n';
					std::cout << "Valor de m -> ";
					std::cin >> m;
					std::cout << "Valor de n -> ";
					std::cin >> n;
					resultado = int (convierteDoubleEnInt(combinacionesRep(m, n)));
					std::cout << "" << '\n';
					std::cout << "         (m + n-1) " << '\n';
					std::cout << "CRm,n =  (       ) = " << resultado << '\n';
					std::cout << "         (   n   ) " << '\n';
					std::cout << "" << '\n';
					break;

				case 'n':
					std::cout << "Combinaciones sin repetición " << '\n';
					std::cout << "============================ " << '\n';
					std::cout << "" << '\n';
					std::cout << "Valor de m -> ";
					std::cin >> m;
					std::cout << "Valor de n -> ";
					std::cin >> n;
					resultado = int (convierteDoubleEnInt(combinaciones(m, n)));
					std::cout << "" << '\n';
					std::cout << "        (m)        m! " << '\n';
					std::cout << "Cm,n =  ( ) = ---------- = " <<  resultado << '\n';
					std::cout << "        (n)     n!(m-n)! " << '\n';
					std::cout << "" << '\n';
					break;
			}
			break;
	}
}
