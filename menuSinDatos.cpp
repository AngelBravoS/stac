#include <iostream>
#include "cli.hpp"

using namespace std;

void CLI::menuSinDatos() {
	//cout << "Escribe: " << '\n';
	char eleccionNivel2;
	cout << "'1' Combinatoria." << '\n';
	cout << "'2' Inteligencia artificial."  << '\n';
	cout << "'3' Distribuciones de probabilidad discretas." << '\n';
	cout << "'0' Salir." << '\n';
	cout << "> ";
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
