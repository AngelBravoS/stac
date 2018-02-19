#include <iostream>
#include "cli.hpp"
#include "calculosNVar.hpp"

void CLI::menuNVar() {
	char eleccionNivel2;
	std::cout << "'1' Funciones de estadística descriptiva n-dimensional." << '\n';
	std::cout << "'2' Análisis de tablas de contingencia."  << '\n';
	std::cout << "'0' Salir." << '\n';
	std::cout << "> ";
	std::cin >> eleccionNivel2;
	switch ( eleccionNivel2 ) {
		case '1' :
			///menuNVar();
			break;
		case '2' :
			//menuTablasCont();
			break;
	}
}
