//CLI => Command Line Interface.
#include "cli.hpp"
#include <iostream>

char CLI::getOpcion() {
	return opcion;
}

void CLI::setOpcion(char opcionPrivada) {
	opcion = opcionPrivada;
}

void CLI::eleccion() {
	char opcionElegida;
	std::cin >> opcionElegida;
	//eleccion='1';
	setOpcion(opcionElegida);
}

void CLI::menuPrincipal() {
	do {
		listadOpcionesPricipales();
		std::cout << "> ";
		eleccion();
		switch(getOpcion()) {
			case '1' :
				menu1Var();
				break;
			case '2' :
				menu2Var();
				break;
			case 'n' :
				menuNVar();
				break;
			case 'a' :
				menuMatrices();
				break;
			case 'm' :
				menuMuestreo();
				break;
			case 'h' :
				ayuda();
				break;
			case 's' :
				menuSinDatos();
				break;
		}
	} while(getOpcion() != '0');
}
