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
				//medidas de tendencia Central
				cout << "Medidas de tendencia central" << endl;
				cout << "La media aritmética es: " << variableX.mediaAritmetica() << endl;
				cout << "La media geométrica es: " << variableX.mediaGeometrica() << endl;
				cout << "La media armónica es: " << variableX.mediaArmonica() << endl;
				cout << "La media cuadrática es: " << variableX.mediaCuadratica() << endl;
				cout << endl;
				break;
			case '2':
				//medidas de dispersión
				cout << "Medidas de dispersión" << endl;
				//cout << "Las diferencias respecto a la media son: " << variableX.difRespecMedia() << endl;
				cout << "La varianza es: " << variableX.varianza() << endl;
				cout << "La cuasivarianza es: " << variableX.cuasiVarianza() << endl;
				cout << "La desviación típica es: " << variableX.desviacionTipica() << endl;
				cout << "La cuasidesviación típica es: " << variableX.cuasiDesviacionTipica() << endl;
				cout << endl;
				break;
			case '3':
				cout << "Medidas de forma" << endl;
				break;
			case '4':
				cout << "Muestreo aleatorio simple" << endl;
				break;
			case '5':
				cout << "Muestreo con reposición" << endl;
				break;
			}
		}
	while ( eleccionCalculosVariableX != '0' );
	}
