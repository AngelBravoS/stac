#include <iostream>
#include "cli.hpp"
#include "calculosIA.hpp"

void CLI::menuIA() {
	unsigned short int a, b, X0;
	unsigned int m;
	CalculosIA secuencia;
	std::cout << "Escribe x para el generador congruencial mixto." << '\n';
	std::cout << "Escribe m para el generador congruencial multiplicativo." << '\n';
	std::cout << "> ";
	eleccion();
	switch(getOpcion()) {
	case 'x':
		std::cout << "valor de a = ";
		std::cin >> a;
		std::cout << "valor de b = ";
		std::cin >> b;
		std::cout << "valor de m = ";
		std::cin >> m;
		std::cout << "valor de Xo = ";
		std::cin >> X0;
		if(m <= a || m <= b)
			std::cout << "secuencia no válida (m > a,b).";
		else {
			std::cout << "Para a = " << a << ", b = " << b << ", m = "
			     << m << ", y Xo = " << X0 << ", el resultado es:" << '\n';
			secuencia.crearSecuenciaMixto(a, b, m, X0);
		}
		break;
	case 'm':
		std::cout << "valor de a = ";
		std::cin >> a;
		std::cout << "valor de m = ";
		std::cin >> m;
		std::cout << "valor de Xo = ";
		std::cin >> X0;
		std::cout << "Para a = " << a << ", m = " << m << ", y Xo = "
		     << X0 << ", el resultado es:" << '\n';
		secuencia.crearSecuenciaMultip(a, m, X0);
		break;
	}
	std::cout << "El período de la secuencia es " << secuencia.getLongitudVector() << '\n';
	std::cout << '\n';
}
