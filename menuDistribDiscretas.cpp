#include <iostream>
#include "cli.hpp"
#include "distribucionesDiscretas.hpp"

void CLI::menuDistribDiscreta() {
	char eleccionNivel2;
	unsigned short int parametron;
	unsigned short int probabilidad;
	unsigned short int parametroN;
	unsigned short int parametror;
	float parametroP;
	do {
		std::cout << "Distribuciones a elegir:" << '\n';
		std::cout << "'1' Bernouilli." << '\n';
		std::cout << "'2' Binomial." << '\n';
		std::cout << "'3' Binomial negativa." << '\n';
		std::cout << "'4' Hipergeométrica." << '\n';
		std::cout << "'5' Poisson." << '\n';
		std::cout << "'6' Geométrica." << '\n';
		std::cout << "'0' Volver al menú principal." << '\n';
		std::cout << "> ";
		std::cin >> eleccionNivel2;
		switch(eleccionNivel2) {
		case '1': //Bernouilli
			std::cout << "============================================= " << '\n';
			std::cout << "Valor de x = ";
			std::cin >> probabilidad;
			std::cout << "Parámetro p = ";
			std::cin >> parametroP;
			std::cout << "Distribución Bernuilli X~>B("<< parametroP << ")" << '\n';
			std::cout << "P[X=" << probabilidad << "]" << " = "<<
			     bernouilli(parametroP, probabilidad) << '\n';
			break;
		case '2': //Binomial
			std::cout << "============================================= " << '\n';
			std::cout << "Valor de x = ";
			std::cin >> probabilidad;
			std::cout << "Parámetro p = ";
			std::cin >> parametroP;
			std::cout << "Parámetro n = ";
			std::cin >> parametron;
			std::cout << "Distribución Binomial X~>B("<< parametron << ","<<
			     parametroP << ")" << '\n';
			std::cout << "P[X=" << probabilidad << "]" << " = "<<
			     binomial(parametron, parametroP, probabilidad) << '\n';
			break;
		case '3': //Binomial negativa
			std::cout << "============================================= " << '\n';
			std::cout << "Valor de x = ";
			std::cin >> probabilidad;
			std::cout << "Parámetro p = ";
			std::cin >> parametroP;
			std::cout << "Parámetro n = ";
			std::cin >> parametron;
			std::cout << "Distribución Binomial negativa X~>BN("<< parametron <<
			     "," << parametroP << ")" << '\n';
			std::cout << "P[X=" << probabilidad << "]" << " = "<<
			     binomialNegativa(parametron, parametroP, probabilidad) << '\n';
			break;
		case '4': //Hipergeometrica
			std::cout << "============================================= " << '\n';
			std::cout << "Valor de x = ";
			std::cin >> probabilidad;
			std::cout << "Parámetro N = ";
			std::cin >> parametroN;
			std::cout << "Parámetro n = ";
			std::cin >> parametron;
			std::cout << "Parámetro r = ";
			std::cin >> parametror;
			std::cout << "Distribución Hipergeométrica X~>H("<< parametroN <<
			     ","<< parametron << "," << parametror << ")" << '\n';
			std::cout << "P[X=" << probabilidad << "]" << " = "<<
			     hipergeometrica(parametroN, parametron, parametror, probabilidad) << '\n';
			break;
		case '5': //Poisson
			std::cout << "============================================= " << '\n';
			std::cout << "Valor de x = ";
			std::cin >> probabilidad;
			std::cout << "Parámetro lambda = ";
			std::cin >> parametroP;
			std::cout << "Distribución Poisson X~>P("<< parametroP << ")" << '\n';
			std::cout << "P[X=" << probabilidad << "]" << " = "<<
			     poisson(parametroP, probabilidad) << '\n';
			break;
		case '6': //Geometrica
			std::cout << "============================================= " << '\n';
			std::cout << "Valor de x = ";
			std::cin >> probabilidad;
			std::cout << "Parámetro p = ";
			std::cin >> parametroP;
			std::cout << "Distribución Geométrica X~>G(" << parametroP << ")" << '\n';
			std::cout << "P[X=" << probabilidad << "]" << " = "<< geometrica(parametroP, probabilidad) << '\n';
			break;
		}
		std::cout << "============================================= " << '\n';
		std::cout << '\n';
	} while(eleccionNivel2 != '0');
}
