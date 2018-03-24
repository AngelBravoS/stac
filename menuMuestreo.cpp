#include <iostream>
#include "cli.hpp"
#include "calculosMuestreo.hpp"

void CLI::menuMuestreo() {
	char respuestaTipoMuestreo, respuestaElegirArchivo, respuestaDatosAgrupados;
	CalculosMuestreo muestreo;
	std::cout << '\n';
	std::cout << "'1' Muestreo aleatorio simple" << '\n';
	std::cout << "'2' Muestreo con reemplazo y probabilidades iguales"  << '\n';
	std::cout << "'3' Muestreo sin reemplazo y probabilidades desiguales." << '\n';
	std::cout << "'4' Muestreo con reemplazo y probabilidades desiguales"  << '\n';
	std::cout << "'5' Muestreo sistemático" << '\n';
	std::cout << "'6' Muestreo estratificado" << '\n';
	std::cout << "'7' Muestreo por conglomerados" << '\n';
	std::cout << "'0' Salir." << '\n';
	std::cout << "> ";
	std::cin >> respuestaTipoMuestreo;
	muestreo.setTipoMuestreo(respuestaTipoMuestreo);
	std::cout << '\n';
	std::cout << "¿Los datos están agrupados?" << '\n';
	std::cout << "s/n:";
	std::cin >> respuestaDatosAgrupados;
	std::cout << "¿Leer desde un archivo?" << '\n';
	std::cout << "s/n:";
	std::cin >> respuestaElegirArchivo;
	if(respuestaElegirArchivo == 's') {
		muestreo.setSiLeeArchivo(true);
	} else {
		muestreo.setSiLeeArchivo(false);
	}
	if(respuestaDatosAgrupados == 's') {
		muestreo.setSiDatosEstanAgrupados(true);
	} else {
		muestreo.setSiDatosEstanAgrupados(false);
	}	
	//muestreo.establecerOrigenDatos();
	muestreo.crearDatosMuestra();
	muestreo.mostrarDatosMuestra();
	muestreo.setSumatoriaXi(muestreo.calculoSumatoria(0, 1));
	muestreo.setSumatoriaXi2(muestreo.calculoSumatoria(0, 2));
	muestreo.setMedia(muestreo.calculoMediaAritmetica(0));
	std::cout << "∑Xi = " << muestreo.getSumatoriaXi();
	std::cout << ", ∑Xi^2 = " << muestreo.getSumatoriaXi2();
	std::cout << ", media  = " << muestreo.getMedia() << '\n';
	std::cout << '\n';
}
