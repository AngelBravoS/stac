#include <iostream>
#include "cli.hpp"
#include "distribucionesDiscretas.hpp"

using namespace std;

void CLI::menuDistribDiscreta(){
	unsigned short int parametron;
	float parametroP; 
	unsigned short int probabilidad;
	cout << "Distribuciones a elegir:" << endl;
	cout << "1.- Bernouilli." << endl;
	cout << "2.- Binomial." << endl;
	cout << "3.- Binomial negativa." << endl;
	cout << "4.- Hipergeométrica." << endl;
	cout << "5.- Poisson." << endl;
	cout << "6.- Geométrica." << endl;
	cout << "> ";
	eleccion();
	cout << "====================================== " << endl;
	cout << "Valor de x-> ";
	cin >> probabilidad;
	switch (getOpcion()) {
	case '1': //Bernouilli
		cout << "Valor de p-> ";
		cin >> parametroP;
		cout << "Distribución Bernuilli X~>B("<< parametroP << ")" << endl;
		cout << "P[X=" << probabilidad << "]" << " = "<< 
			bernouilli(parametroP, probabilidad) << endl;
		break;
	case '2': //Binomial
		cout << "Valor de p-> ";
		cin >> parametroP;
		cout << "Valor de n-> ";
		cin >> parametron;
		cout << "Distribución Binomial X~>B("<< parametron << ","<< 
			parametroP << ")" << endl;
		cout << "P[X=" << probabilidad << "]" << " = "<< 
			binomial(parametron, parametroP, probabilidad) << endl; 
		break;
	case '3': //Binomial negativa
		cout << "Valor de p-> ";
		cin >> parametroP;
		cout << "Valor de n-> ";
		cin >> parametron;
		cout << "Distribución Binomial negativa X~>BN("<< parametron << 
			"," << parametroP << ")" << endl;
		cout << "P[X=" << probabilidad << "]" << " = "<< 
			binomialNegativa(parametron, parametroP, probabilidad) << endl; 
		break;	
	case '4': //Hipergeometrica
		cout << "Valor de p-> ";
		cin >> parametroP;
		cout << "Valor de n-> ";
		cin >> parametron;
		cout << "Distribución Hipergeométrica X~>H("<< parametron << 
			","<< parametroP << ")" << endl;
		cout << "P[X=" << probabilidad << "]" << " = "<< endl;
		//faltan argumentos
		//hipergeometrica(parametron, parametroP, probabilidad) <<  
		break;	
	case '5': //Poisson
		cout << "Valor de lambda-> ";
		cin >> parametroP;
		cout << "Distribución Poisson X~>P("<< parametroP << ")" << endl;
		cout << "P[X=" << probabilidad << "]" << " = "<< 
		poisson(parametroP, probabilidad) << endl; 
		break;
	case '6': //Geometrica
		cout << "Valor de p-> ";
		cin >> parametroP;
		cout << "Distribución Geométrica X~>G(" << parametroP << ")" << endl;
		cout << "P[X=" << probabilidad << "]" << " = "<< geometrica(parametroP, probabilidad) << endl; 
		break;
	break;
	}
	cout << "====================================== " << endl;
	cout << endl;
}
