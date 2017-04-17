#include <iostream>
#include "cli.hpp"
#include "funcMate.hpp"
#include "combinatoria.hpp"

using namespace std;

void CLI::menuCombinatoria() {
	unsigned short int m, n, cantidadn;
	double resultado;
	char seleccion1, seleccion2;
	cout << "¿(p)ermutaciones, (v)ariaciones o (c)ombinaciones?." << endl;
	cout << "> ";
	cin >> seleccion1;
	cout << "¿Repetición? (s)í/(n)o" << endl;
	cout << "> ";
	cin >> seleccion2;
	switch ( seleccion1 ) {
		case 'p':
			switch ( seleccion2 ) {
				case 's':
					cout << "Permutaciones con repetición " << endl;
					cout << "============================ " << endl;
					cout << "" << endl;
					cout << "Valor de m -> ";
					cin >> m;
					cout << "Cantidad de n diferentes -> ";
					cin >> cantidadn;
					resultado = 1;
					for ( unsigned short int i = 0; i < cantidadn; i++ ) {
						cout << "Introducir valor de n" << ( i + 1 ) << " " << "=> ";
						cin >> n;
						resultado = resultado * factorial ( n );
					}
					resultado = int ( convierteDoubleEnInt ( ( factorial ( m ) / resultado ) ) );
					cout << "" << endl;
					cout << "              m! " << endl;
					cout << "PRm,n = -------------- = " << resultado << endl;
					cout << "         n1!*n2!..nK! " << endl;
					cout << "" << endl;
					break;

				case 'n':
					cout << "Permutaciones sin repetición " << endl;
					cout << "============================ " << endl;
					cout << "" << endl;
					cout << "Valor de n -> ";
					cin >> n;
					resultado = int ( convierteDoubleEnInt ( permutaciones ( n ) ) );
					cout << "" << endl;
					cout << "Pn = n! = " << resultado << endl;
					break;
			}

			break;
		case 'v':
			switch ( seleccion2 ) {
				case 's':
					cout << "Variaciones con repetición " << endl;
					cout << "============================ " << endl;
					cout << "" << endl;
					cout << "Valor de m -> ";
					cin >> m;
					cout << "Valor de n -> ";
					cin >> n;
					resultado = int ( convierteDoubleEnInt ( variacionesRep ( m, n ) ) );
					cout << "" << std::endl;
					cout << "         n" << endl;
					cout << "VRm,n = m = " <<  resultado << endl;;
					break;

				case 'n':
					cout << "Variaciones sin repetición " << endl;
					cout << "============================ " << endl;
					cout << "" << endl;
					cout << "valor de m -> ";
					cin >> m;
					cout << "valor de n -> ";
					cin >> n;
					resultado = int ( convierteDoubleEnInt ( variaciones ( m, n ) ) );
					cout << "" << endl;
					cout << "           m! " << endl;
					cout << "Vm,n = ---------- = " << resultado << endl;
					cout << "         (m-n)! " << endl;
					cout << "" << endl;
					break;
			}

			break;
		case 'c':
			switch ( seleccion2 ) {
				case 's':
					cout << "Combinaciones con repetición " << endl;
					cout << "============================ " << endl;
					cout << "" << endl;
					cout << "Valor de m -> ";
					cin >> m;
					cout << "Valor de n -> ";
					cin >> n;
					resultado = int ( convierteDoubleEnInt ( combinacionesRep ( m, n ) ) );
					cout << "" << endl;
					cout << "         (m + n-1) " << endl;
					cout << "CRm,n =  (       ) = " << resultado << endl;
					cout << "         (   n   ) " << endl;
					cout << "" << endl;
					break;

				case 'n':
					cout << "Combinaciones sin repetición " << endl;
					cout << "============================ " << endl;
					cout << "" << endl;
					cout << "Valor de m -> ";
					cin >> m;
					cout << "Valor de n -> ";
					cin >> n;
					resultado = int ( convierteDoubleEnInt ( combinaciones ( m, n ) ) );
					cout << "" << std::endl;
					cout << "        (m)        m! " << endl;
					cout << "Cm,n =  ( ) = ---------- = " <<  resultado << endl;
					cout << "        (n)     n!(m-n)! " << endl;
					cout << "" << endl;
					break;
			}
			break;
	}
}
