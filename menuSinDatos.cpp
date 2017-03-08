#include <iostream>
#include "cli.hpp"

using namespace std;

void CLI::menuSinDatos(){
	//cout << "Escribe: " << endl;
	cout << "c Combinatoria." << endl;
	cout << "i Inteligencia artificial."  << endl;
	cout << "d Distribuciones de probabilidad discretas." << endl;
	cout << "0 Salir." << endl;
	cout << ">";
	eleccion();
	switch (getOpcion()){
		case 'c' :
			menuCombinatoria();
			break;
		case 'i' :
			menuInteligenciArtificial();
			break;	
		case 'd' :
			menuDistribDiscreta();
			break;
	}
}
