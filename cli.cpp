//CLI => Command Line Interface.
#include "cli.hpp"
#include <iostream>
#include "calculos1Var.hpp"

using namespace std;

char CLI::getOpcion() {
	return opcion;
}

void CLI::setOpcion(char opcionPrivada) {
	opcion = opcionPrivada;
}

void CLI::eleccion() {
	char opcionElegida;
	cin >> opcionElegida;
	//eleccion='1';
	setOpcion(opcionElegida);
}

void CLI::menuPrincipal() {
	do {
		listadOpcionesPricipales();
		cout << "> ";
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
			case 'm' :
				menuMatrices();
				break;
			case 'a' :
				ayuda();
				break;
			case 's' :
				menuSinDatos();
				break;
			//default :
			//	ayuda();
			//	break;
		}
	} while(getOpcion() != '0');
}
