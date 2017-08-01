#include <iostream>
#include "cli.hpp"
#include "calculos1Var.hpp"

using namespace std;

void CLI::menu1Var() {
	char eligesArchivo, eleccionNivel2, eleccionNivel3, eleccionNivel4;;
	Calculos1Var variableX;
	cout << "¿Leer desde un archivo?" << endl;
	cout << "s/n:";
	cin >> eligesArchivo;
	if ( eligesArchivo == 's' ) {
		variableX.leerVectorArchivo();
	} else {
		variableX.recogerDatosVector();
		variableX.crearVectorVacio();
		variableX.editarVectorVacio();
		//cout << endl;
	}
	do {
		variableX.mostrarVector();
		cout << endl;
		cout << "'1' Medidas de tendencia central" << endl;
		cout << "'2' Medidas de dispersión" << endl;
		cout << "'3' Medidas de forma" << endl;
		cout << "'4' Muestreo" << endl;
		cout << "'5' Inferencia" << endl;
		cout << "'0' Volver al menú principal." << endl;
		cout << "> ";
		cin >> eleccionNivel2;
		switch ( eleccionNivel2 ) {
			case '1':
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
				cout << "Norma = " << variableX.norma() << endl;
				cout << endl;
				break;
			case '4':
				cout << "Muestreo aleatorio simple" << endl;
				break;
			case '5':
				do {
					cout << "Contrastes en poblaciones normales" << endl;
					cout << "'1' Relativo a la media" << endl;
					cout << "'2' Relativo a la varianza" << endl;
					cout << "'3' Test de la Chi-Cuadrado" << endl;
					cout << "'4' Test de la t de Student" << endl;
					cout << "'0' Volver al menú anterior." << endl;
					cout << "> ";
					cin >> eleccionNivel3;
					switch ( eleccionNivel3 ) {
						case '1':
							do {
								cout << "'1' Sigma conocida" << endl;
								cout << "'2' Sigma desconocida" << endl;
								cout << "'0' Volver al menú anterior." << endl;
								cout << "> ";
								cin >> eleccionNivel4;
								switch ( eleccionNivel4 ) {
									case '1':
										cout << "Sigma conocida" << endl;
										variableX.media1MuestraSigmaConocida();
										break;
									case '2':
										variableX.media1MuestraSigmaDesconocida();
										break;
								}
							} while ( eleccionNivel4 != '0' );
							break;
						case '2':
							do {
								cout << "'1' Mu conocida" << endl;
								cout << "'2' Mu desconocida" << endl;
								cout << "'0' Volver al menú anterior." << endl;
								cout << "> ";
								cin >> eleccionNivel4;
								switch ( eleccionNivel4 ) {
									case '1':
										variableX.var1MuestraMuConocida();
										break;
									case '2':
										variableX.var1MuestraMuDesconocida();
										break;
								}
							} while ( eleccionNivel4 != '0' );
							break;
					}
				} while ( eleccionNivel3 != '0' );
				break;
		}
	} while ( eleccionNivel2 != '0' );
	variableX.destructorVector();
}
