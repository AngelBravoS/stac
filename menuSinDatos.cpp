#include <iostream>
#include "cli.hpp"

void CLI::menuSinDatos() {
	char eleccionNivel2;
	std::cout << "'1' Combinatoria." << '\n';
	std::cout << "'2' Inteligencia artificial."  << '\n';
	std::cout << "'3' Distribuciones de probabilidad discretas." << '\n';
	std::cout << "'0' Salir." << '\n';
	std::cout << "> ";
	std::cin >> eleccionNivel2;
	switch ( eleccionNivel2 ) {
		case '1' :
			menuCombinatoria();
			break;
		case '2' :
			menuIA();
			break;
		case '3' :
			menuDistribDiscreta();
			break;
	}
}
