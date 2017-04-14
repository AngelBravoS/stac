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
	if ( eligesArchivo == 's' ) {
		variableX.leerArchivo();
	} else {
		variableX.recogerDatosVector();
		variableX.crearVectorVacio();
		variableX.editarVectorVacio();
		variableX.mostrarVector();
		cout << endl;
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
		variableX.mostrarVector();
		cout << endl;
		switch ( eleccionCalculosVariableX ) {
			case '1':
				//medidas de tendencia Central
				cout << "Media aritmética = " << variableX.mediaAritmetica() << endl;
				cout << "Media geométrica = " << variableX.mediaGeometrica() << endl;
				cout << "Media armónica = " << variableX.mediaArmonica() << endl;
				cout << "Media cuadrática = " << variableX.mediaCuadratica() << endl;
				cout << endl;
				break;
			case '2':
				//cout << "Las diferencias respecto a la media son: " << variableX.difRespecMedia() << endl;
				cout << "Varianza = " << variableX.varianza() << endl;
				cout << "Cuasivarianza = " << variableX.cuasiVarianza() << endl;
				cout << "Desviación típica = " << variableX.desviacionTipica() << endl;
				cout << "Cuasidesviación típica = " << variableX.cuasiDesviacionTipica() << endl;
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
	} while ( eleccionCalculosVariableX != '0' );
	variableX.destructorVector();
}
