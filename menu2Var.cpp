#include <iostream>
#include "cli.hpp"
#include "calculos2Var.hpp"

using namespace std;

void CLI::menu2Var() {
	char eleccionNivel2, eligesArchivo;
	Calculos2Var variablesXeY;
	cout << "¿Leer desde un archivo?" << '\n';
	cout << "s/n:";
	cin >> eligesArchivo;
	if(eligesArchivo == 's') {
		variablesXeY.leerMatrizArchivo();
	} else {
		variablesXeY.recogerDatosMatriz();
		variablesXeY.crearMatrizVacia();
		variablesXeY.editarMatrizVacia();
		variablesXeY.mostrarMatrizOriginal();
		cout << '\n';
	}
	do {
		cout << "'1' medias y sumatorias" << '\n';
		cout << "'2' medidas de dispersión" << '\n';
		cout << "'0' Salir." << '\n';
		cout << "> ";
		cin >> eleccionNivel2;
		variablesXeY.mostrarMatrizOriginal();
		cout << '\n';
		switch(eleccionNivel2) {
			case '1':
				//medidas de tendencia Central
				cout << "Media aritmética de X = " << variablesXeY.mediaAritmetica(0) << '\n';
				cout << "Media aritmética de Y = " << variablesXeY.mediaAritmetica(1) << '\n';
				cout << "Sumatoria de X = " << variablesXeY.sumatoria(0,1) << '\n';
				cout << "Sumatoria de Y = " << variablesXeY.sumatoria(1,1) << '\n';
				cout << "Sumatoria de X e Y = " << variablesXeY.sumatoria2Var(0,1,1,1) << '\n';
				cout << '\n';
				break;
			case '2':
				//cout << "Las diferencias respecto a la media son: " << variablesXeY.difRespecMedia() << endl;
				cout << "Varianza de X = " << variablesXeY.varianza(0) << '\n';
				cout << "Varianza de Y = " << variablesXeY.varianza(1) << '\n';
				cout << "Desviación típica de X = " << variablesXeY.desviacionTipica(0) << '\n';
				cout << "Desviación típica de Y = " << variablesXeY.desviacionTipica(1) << '\n';
				cout << "Covarianza de X e Y = " << variablesXeY.covarianza() << '\n';
				cout << "Coeficiente de correlación de X e Y =  " << variablesXeY.coeficienteCorrelacion() << '\n';
				cout << '\n';
				break;
		}
	} while(eleccionNivel2 != '0');
	variablesXeY.destructorVector();
}
