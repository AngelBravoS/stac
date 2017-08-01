#include <iostream>
#include "cli.hpp"

using namespace std;

void CLI::menuSinDatos() {
	//cout << "Escribe: " << endl;
	char eleccionNivel2;
	cout << "'1' Combinatoria." << endl;
	cout << "'2' Inteligencia artificial."  << endl;
	cout << "'3' Distribuciones de probabilidad discretas." << endl;
	cout << "'0' Salir." << endl;
	cout << ">";
	cin >> eleccionNivel2;
	switch ( eleccionNivel2 ) {
		case '1' :
			menuCombinatoria();
			break;
		case '2' :
			menuInteligenciArtificial();
			break;
		case '3' :
			menuDistribDiscreta();
			break;
	}
}
