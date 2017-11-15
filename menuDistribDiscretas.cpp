#include <iostream>
#include "cli.hpp"
#include "distribucionesDiscretas.hpp"

using namespace std;

void CLI::menuDistribDiscreta() {
	char eleccionNivel2;
	unsigned short int parametron;
	unsigned short int probabilidad;
	unsigned short int parametroN;
	unsigned short int parametror;
	float parametroP;
	do {
		cout << "Distribuciones a elegir:" << '\n';
		cout << "'1' Bernouilli." << '\n';
		cout << "'2' Binomial." << '\n';
		cout << "'3' Binomial negativa." << '\n';
		cout << "'4' Hipergeométrica." << '\n';
		cout << "'5' Poisson." << '\n';
		cout << "'6' Geométrica." << '\n';
		cout << "'0' Volver al menú principal." << '\n';
		cout << "> ";
		cin >> eleccionNivel2;
		switch(eleccionNivel2) {
		case '1': //Bernouilli
			cout << "============================================= " << '\n';
			cout << "Valor de x = ";
			cin >> probabilidad;
			cout << "Parámetro p = ";
			cin >> parametroP;
			cout << "Distribución Bernuilli X~>B("<< parametroP << ")" << '\n';
			cout << "P[X=" << probabilidad << "]" << " = "<<
			     bernouilli(parametroP, probabilidad) << '\n';
			break;
		case '2': //Binomial
			cout << "============================================= " << '\n';
			cout << "Valor de x = ";
			cin >> probabilidad;
			cout << "Parámetro p = ";
			cin >> parametroP;
			cout << "Parámetro n = ";
			cin >> parametron;
			cout << "Distribución Binomial X~>B("<< parametron << ","<<
			     parametroP << ")" << '\n';
			cout << "P[X=" << probabilidad << "]" << " = "<<
			     binomial(parametron, parametroP, probabilidad) << '\n';
			break;
		case '3': //Binomial negativa
			cout << "============================================= " << '\n';
			cout << "Valor de x = ";
			cin >> probabilidad;
			cout << "Parámetro p = ";
			cin >> parametroP;
			cout << "Parámetro n = ";
			cin >> parametron;
			cout << "Distribución Binomial negativa X~>BN("<< parametron <<
			     "," << parametroP << ")" << '\n';
			cout << "P[X=" << probabilidad << "]" << " = "<<
			     binomialNegativa(parametron, parametroP, probabilidad) << '\n';
			break;
		case '4': //Hipergeometrica
			cout << "============================================= " << '\n';
			cout << "Valor de x = ";
			cin >> probabilidad;
			cout << "Parámetro N = ";
			cin >> parametroN;
			cout << "Parámetro n = ";
			cin >> parametron;
			cout << "Parámetro r = ";
			cin >> parametror;
			cout << "Distribución Hipergeométrica X~>H("<< parametroN <<
			     ","<< parametron << "," << parametror << ")" << '\n';
			cout << "P[X=" << probabilidad << "]" << " = "<<
			     hipergeometrica(parametroN, parametron, parametror, probabilidad) << '\n';
			break;
		case '5': //Poisson
			cout << "============================================= " << '\n';
			cout << "Valor de x = ";
			cin >> probabilidad;
			cout << "Parámetro lambda = ";
			cin >> parametroP;
			cout << "Distribución Poisson X~>P("<< parametroP << ")" << '\n';
			cout << "P[X=" << probabilidad << "]" << " = "<<
			     poisson(parametroP, probabilidad) << '\n';
			break;
		case '6': //Geometrica
			cout << "============================================= " << '\n';
			cout << "Valor de x = ";
			cin >> probabilidad;
			cout << "Parámetro p = ";
			cin >> parametroP;
			cout << "Distribución Geométrica X~>G(" << parametroP << ")" << '\n';
			cout << "P[X=" << probabilidad << "]" << " = "<< geometrica(parametroP, probabilidad) << '\n';
			break;
		}
		cout << "============================================= " << '\n';
		cout << '\n';
	} while(eleccionNivel2 != '0');
}
