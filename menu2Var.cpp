#include <iostream>
#include "cli.hpp"
#include "calculos2Var.hpp"

void CLI::menu2Var() {
	char eleccionNivel2, eligesArchivo;
	Calculos2Var variablesXeY;
	std::cout << "¿Leer desde un archivo?" << '\n';
	std::cout << "s/n:";
	std::cin >> eligesArchivo;
	if(eligesArchivo == 's') {
		variablesXeY.leerMatrizArchivo();
	} else {
		variablesXeY.setDimensionMatriz();
		variablesXeY.crearMatrizVacia();
		variablesXeY.editarMatrizVacia();
		variablesXeY.mostrarMatrizOriginal();
		std::cout << '\n';
	}
	do {
		std::cout << "'1' medias y sumatorias" << '\n';
		std::cout << "'2' medidas de dispersión" << '\n';
		std::cout << "'0' Salir." << '\n';
		std::cout << "> ";
		std::cin >> eleccionNivel2;
		variablesXeY.mostrarMatrizOriginal();
		std::cout << '\n';
		switch(eleccionNivel2) {
			case '1':
				//medidas de tendencia Central
				std::cout << "Media aritmética de X = " << variablesXeY.mediaAritmetica(0) << '\n';
				std::cout << "Media aritmética de Y = " << variablesXeY.mediaAritmetica(1) << '\n';
				std::cout << "Sumatoria de X = " << variablesXeY.sumatoria(0,1) << '\n';
				std::cout << "Sumatoria de Y = " << variablesXeY.sumatoria(1,1) << '\n';
				std::cout << "Sumatoria de X e Y = " << variablesXeY.sumatoria2Var(0,1,1,1) << '\n';
				std::cout << '\n';
				break;
			case '2':
				//std::cout << "Las diferencias respecto a la media son: " << variablesXeY.difRespecMedia() << endl;
				std::cout << "Varianza de X = " << variablesXeY.varianza(0) << '\n';
				std::cout << "Varianza de Y = " << variablesXeY.varianza(1) << '\n';
				std::cout << "Desviación típica de X = " << variablesXeY.desviacionTipica(0) << '\n';
				std::cout << "Desviación típica de Y = " << variablesXeY.desviacionTipica(1) << '\n';
				std::cout << "Covarianza de X e Y = " << variablesXeY.covarianza() << '\n';
				std::cout << "Coeficiente de correlación de X e Y =  " << variablesXeY.coeficienteCorrelacion() << '\n';
				std::cout << '\n';
				break;
		}
	} while(eleccionNivel2 != '0');
	variablesXeY.destructorVector();
}
