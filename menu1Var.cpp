#include <iostream>
#include "cli.hpp"
#include "calculos1Var.hpp"

using namespace std;

void CLI::menu1Var() {
	char eligesArchivo, eleccionNivel2, eleccionNivel3, eleccionNivel4;
	Calculos1Var variableX;
	cout << "¿Leer desde un archivo?" << '\n';
	cout << "s/n:";
	cin >> eligesArchivo;
	if(eligesArchivo == 's') {
		variableX.leerVectorArchivo();
	} else {
		variableX.recogerDatosVector();
		variableX.crearVectorVacio();
		variableX.editarVectorVacio();
		//cout << endl;
	}
	do {
		variableX.mostrarVector();
		cout << '\n';
		cout << "'1' Medidas de tendencia central" << '\n';
		cout << "'2' Medidas de dispersión" << '\n';
		cout << "'3' Medidas de forma" << '\n';
		cout << "'4' Muestreo" << '\n';
		cout << "'5' Inferencia" << '\n';
		cout << "'0' Volver al menú principal." << '\n';
		cout << "> ";
		cin >> eleccionNivel2;
		switch(eleccionNivel2) {
		case '1':
			cout << "Media aritmética = " << variableX.mediaAritmetica() << '\n';
			cout << "Media geométrica = " << variableX.mediaGeometrica() << '\n';
			cout << "Media armónica = " << variableX.mediaArmonica() << '\n';
			cout << "Media cuadrática = " << variableX.mediaCuadratica() << '\n';
			cout << '\n';
			break;
		case '2':
			//cout << "Las diferencias respecto a la media son: " << variableX.difRespecMedia() << endl;
			cout << "Varianza = " << variableX.varianza() << '\n';
			cout << "Cuasivarianza = " << variableX.cuasiVarianza() << '\n';
			cout << "Desviación típica = " << variableX.desviacionTipica() << '\n';
			cout << "Cuasidesviación típica = " << variableX.cuasiDesviacionTipica() << '\n';
			cout << '\n';
			break;
		case '3':
			cout << "Norma = " << variableX.norma() << '\n';
			cout << '\n';
			break;
		case '4':
			cout << "Muestreo aleatorio simple" << '\n';
			break;
		case '5':
			do {
				cout << "Contrastes en poblaciones normales" << '\n';
				cout << "'1' Relativo a la media" << '\n';
				cout << "'2' Relativo a la varianza" << '\n';
				cout << "'3' Test de la Chi-Cuadrado" << '\n';
				cout << "'4' Test de la t de Student" << '\n';
				cout << "'0' Volver al menú anterior." << '\n';
				cout << "> ";
				cin >> eleccionNivel3;
				switch(eleccionNivel3) {
				case '1':
					do {
						cout << "'1' Sigma conocida" << '\n';
						cout << "'2' Sigma desconocida" << '\n';
						cout << "'0' Volver al menú anterior." << '\n';
						cout << "> ";
						cin >> eleccionNivel4;
						switch(eleccionNivel4) {
						case '1':
							cout << "Sigma conocida" << '\n';
							variableX.media1MuestraSigmaConocida();
							break;
						case '2':
							variableX.media1MuestraSigmaDesconocida();
							break;
						}
					} while(eleccionNivel4 != '0');
					break;
				case '2':
					do {
						cout << "'1' Mu conocida" << '\n';
						cout << "'2' Mu desconocida" << '\n';
						cout << "'0' Volver al menú anterior." << '\n';
						cout << "> ";
						cin >> eleccionNivel4;
						switch(eleccionNivel4) {
						case '1':
							variableX.var1MuestraMuConocida();
							break;
						case '2':
							variableX.var1MuestraMuDesconocida();
							break;
						}
					} while(eleccionNivel4 != '0');
					break;
				}
			} while(eleccionNivel3 != '0');
			break;
		}
	} while(eleccionNivel2 != '0');
	variableX.destructorVector();
}
