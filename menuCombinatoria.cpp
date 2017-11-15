#include <iostream>
#include "cli.hpp"
#include "funcMatematicasBasicas.hpp"
#include "combinatoria.hpp"

using namespace std;

void CLI::menuCombinatoria() {
	unsigned short int m, n, cantidadn;
	double resultado;
	char eleccionNivel2, eleccionNivel3;
	cout << "¿(p)ermutaciones, (v)ariaciones o (c)ombinaciones?." << '\n';
	cout << "> ";
	cin >> eleccionNivel2;
	cout << "¿Repetición? (s)í/(n)o" << '\n';
	cout << "> ";
	cin >> eleccionNivel3;
	switch(eleccionNivel2) {
		case 'p':
			switch(eleccionNivel3) {
				case 's':
					cout << "Permutaciones con repetición " << '\n';
					cout << "============================ " << '\n';
					cout << "" << '\n';
					cout << "Valor de m -> ";
					cin >> m;
					cout << "Cantidad de n diferentes -> ";
					cin >> cantidadn;
					resultado = 1;
					for(unsigned short int i = 0; i < cantidadn; i++) {
						cout << "Introducir valor de n" << (i + 1) << " " << "=> ";
						cin >> n;
						resultado = resultado * factorial(n);
					}
					resultado = int (convierteDoubleEnInt((factorial(m) / resultado)));
					cout << "" << '\n';
					cout << "              m! " << '\n';
					cout << "PRm,n = -------------- = " << resultado << '\n';
					cout << "         n1!*n2!..nK! " << '\n';
					cout << "" << '\n';
					break;

				case 'n':
					cout << "Permutaciones sin repetición " << '\n';
					cout << "============================ " << '\n';
					cout << "" << '\n';
					cout << "Valor de n -> ";
					cin >> n;
					resultado = int (convierteDoubleEnInt(permutaciones(n)));
					cout << "" << '\n';
					cout << "Pn = n! = " << resultado << '\n';
					break;
			}

			break;
		case 'v':
			switch(eleccionNivel3) {
				case 's':
					cout << "Variaciones con repetición " << '\n';
					cout << "============================ " << '\n';
					cout << "" << '\n';
					cout << "Valor de m -> ";
					cin >> m;
					cout << "Valor de n -> ";
					cin >> n;
					resultado = int (convierteDoubleEnInt(variacionesRep(m, n)));
					cout << "" << '\n';
					cout << "         n" << '\n';
					cout << "VRm,n = m = " <<  resultado << '\n';;
					break;

				case 'n':
					cout << "Variaciones sin repetición " << '\n';
					cout << "============================ " << '\n';
					cout << "" << '\n';
					cout << "valor de m -> ";
					cin >> m;
					cout << "valor de n -> ";
					cin >> n;
					resultado = int (convierteDoubleEnInt(variaciones(m, n)));
					cout << "" << '\n';
					cout << "           m! " << '\n';
					cout << "Vm,n = ---------- = " << resultado << '\n';
					cout << "         (m-n)! " << '\n';
					cout << "" << '\n';
					break;
			}

			break;
		case 'c':
			switch(eleccionNivel3) {
				case 's':
					cout << "Combinaciones con repetición " << '\n';
					cout << "============================ " << '\n';
					cout << "" << '\n';
					cout << "Valor de m -> ";
					cin >> m;
					cout << "Valor de n -> ";
					cin >> n;
					resultado = int (convierteDoubleEnInt(combinacionesRep(m, n)));
					cout << "" << '\n';
					cout << "         (m + n-1) " << '\n';
					cout << "CRm,n =  (       ) = " << resultado << '\n';
					cout << "         (   n   ) " << '\n';
					cout << "" << '\n';
					break;

				case 'n':
					cout << "Combinaciones sin repetición " << '\n';
					cout << "============================ " << '\n';
					cout << "" << '\n';
					cout << "Valor de m -> ";
					cin >> m;
					cout << "Valor de n -> ";
					cin >> n;
					resultado = int (convierteDoubleEnInt(combinaciones(m, n)));
					cout << "" << '\n';
					cout << "        (m)        m! " << '\n';
					cout << "Cm,n =  ( ) = ---------- = " <<  resultado << '\n';
					cout << "        (n)     n!(m-n)! " << '\n';
					cout << "" << '\n';
					break;
			}
			break;
	}
}
