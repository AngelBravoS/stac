#include <iostream>
#include "cli.hpp"
#include "calculos2Var.hpp"

using namespace std;

void CLI::menu2Var() {
	char eleccionCalculosVariableXeY, eligesArchivo;
	Calculos2Var variablesXeY;
	cout << "¿Leer desde un archivo?" << endl;
	cout << "s/n:";
	cin >> eligesArchivo;
	if ( eligesArchivo != 's' ) {
		variablesXeY.leerArchivo();
	} else {
		variablesXeY.recogerDatosMatriz();
		variablesXeY.crearMatrizVacia();
		variablesXeY.editarMatrizVacia();
		variablesXeY.mostrarMatrizOriginal();
		cout << endl;
	}
	do {
		cout << "'1' medias y sumatorias" << endl;
		cout << "'2' medidas de dispersión" << endl;
		cout << "'0' Salir." << endl;
		cout << "> ";
		cin >> eleccionCalculosVariableXeY;
		variablesXeY.mostrarMatrizOriginal();
		cout << endl;
		switch ( eleccionCalculosVariableXeY ) {
			case '1':
				//medidas de tendencia Central
				cout << "Media aritmética de X = " << variablesXeY.mediaAritmetica(0) << endl;
				cout << "Media aritmética de Y = " << variablesXeY.mediaAritmetica(1) << endl;
				cout << "Sumatoria de X = " << variablesXeY.sumatoria(0,1) << endl;
				cout << "Sumatoria de Y = " << variablesXeY.sumatoria(1,1) << endl;
				cout << "Sumatoria de X e Y = " << variablesXeY.sumatoria2Var(0,1,1,1) << endl;
				cout << endl;
				break;
			case '2':
				//cout << "Las diferencias respecto a la media son: " << variablesXeY.difRespecMedia() << endl;
				cout << "Varianza de X = " << variablesXeY.varianza(0) << endl;
				cout << "Varianza de Y = " << variablesXeY.varianza(1) << endl;
				cout << "Desviación típica de X = " << variablesXeY.desviacionTipica(0) << endl;
				cout << "Desviación típica de Y = " << variablesXeY.desviacionTipica(1) << endl;
				cout << "Covarianza de X e Y = " << variablesXeY.covarianza() << endl;
				cout << "Coeficiente de correlación de X e Y =  " << variablesXeY.coeficienteCorrelacion() << endl;
				cout << endl;
				break;
		}
	} while ( eleccionCalculosVariableXeY != '0' );
	//variablesXeY.destructorVector();
}
