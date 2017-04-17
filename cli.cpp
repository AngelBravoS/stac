//CLI => Command Line Interface.
#include "cli.hpp"
#include <iostream>

using namespace std;

char CLI::getOpcion() {
    return opcion;
    }

void CLI::setOpcion ( char opcionPrivada ) {
    opcion = opcionPrivada;
    }

void CLI::eleccion() {
    char eleccion;
    cin >> eleccion;
	 //eleccion='1';
    setOpcion ( eleccion );
    }

void CLI::menuPrincipal() {
    listadOpcionesPricipales();
    cout << "> ";
    eleccion();
    switch ( getOpcion() ) {
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
        case '0' :
            menuSinDatos();
            break;
        default :
            break;
        }
    }
