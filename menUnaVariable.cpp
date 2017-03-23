#include <iostream>
#include "cli.hpp"
#include "vector.hpp"

using namespace std;

void CLI::menUnaVariable() {
	char eleccionCalculosVariableX, eligesArchivo;
	Vector variableX;
	cout << "¿Leer desde un archivo?" << endl;
	cout << "s/n:";
	cin >> eligesArchivo;
	if ( eligesArchivo == 'n' ) {
		variableX.recogerDatosVector();
		variableX.crearVectorVacio();
		variableX.editarVectorVacio();
		variableX.mostrarVector();
		cout << endl;
		}
	else {
		variableX.leerArchivo();
		}
	do {
		cout << "'1' medidas de tendencia central" << endl;
		cout << "'2' medidas de dispersión" << endl;
		cout << "'3' medidas de forma" << endl;
		cout << "'4' muestreo aleatorio simple" << endl;
		cout << "'5' muestreo con reposición" << endl;
		cout << "'0' Salir." << endl;
		cout << "> ";
		cin >> eleccionCalculosVariableX;
		switch ( eleccionCalculosVariableX ) {
			case '1':
				//medidasTendenciaCentral();
				cout << "Medidas de tendencia central" << endl;
				cout << "La media aritmética es: " << variableX.mediaAritmetica() << endl;
				cout << "La media geométrica es: " << variableX.mediaGeometrica() << endl;
				cout << "La media armónica es: " << variableX.mediaArmonica() << endl;
				cout << "La media cuadrática es: " << variableX.mediaCuadratica() << endl;
				break;
			case '2':

				break;
			case '3':

				break;
			case '4':

				break;
			case '5':

				break;
			}
		}
	while ( eleccionCalculosVariableX != '0' );
	}
