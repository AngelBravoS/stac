/***************************************************************************
 *   Copyright (C) 2018 by Ángel Bravo Sáenz                               *
 *   angelbravosaenz@gmail.com                                             *
 *                                                                         *
 *   This file is part of Stac.                                            *
 *                                                                         *
 *   Stac is free software; you can redistribute it and/or modify          *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; version 2 of the License.               *
 *                                                                         *
 *   Stac is distributed in the hope that it will be useful,               *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with Stac; if not, write to the                                 *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/


#include "mas.hpp"
MAS::MAS() {}

MAS::MAS(Matriz muestra){
		
}


MAS::MAS(unsigned int filas, unsigned int columnas) {
		//Matriz muestra(filas, columnas);
}


MAS::MAS(bool desdeArchivo, unsigned int longitudSelec, bool datosAgrupados) {
	enArchivo = desdeArchivo;
	longitudVector = longitudSelec;
	agrupados = datosAgrupados;
}

MAS::MAS(bool desdeArchivo, unsigned int longitudSelec, bool datosAgrupados,
         unsigned int estimadorSelec) {
	enArchivo = desdeArchivo;
	longitudVector = longitudSelec;
	agrupados = datosAgrupados;
	estimador = estimadorSelec;
}

void MAS::setValorN(unsigned int valorNObtenido) {
	N = valorNObtenido;
}
/*
unsigned int MAS::getSizeVector() {
	return	convierteLongEnInt(vector.size());
}

void MAS::leerDatos() {
	if (enArchivo == true) {
		verificarArchivo();
		leerDesdeArchivo();
	} else {
		leerDesdeTeclado();
		if (agrupados == true) desagruparDesdeTeclado();
		else crearVector();
	}
}

void MAS::leerDesdeArchivo() {
	if (agrupados == true) {
		desagruparDesdeArchivo();
	} else {
		leerDesdeArchivo();
	}
}

void MAS::crearVector() {
	double xi;
	for (unsigned int i = 0; i < longitudVector; i++) {
		std::cin >> xi;
		vector.push_back(xi);
	}
	std::cout << '\n';
}

void MAS::desagruparDesdeTeclado() {
	double xi;
	double totalElementos = 0;

	unsigned int fi;
	unsigned int longitudVectorInicial = longitudVector;
	unsigned int x = 0;
	unsigned int n = 0;

	std::vector<unsigned int> vectorfi;
	std::vector<double> vectorxi;

	for (unsigned int i = 0; i < longitudVector; i++) {
		std::cin >> fi;
		vectorfi.push_back(fi);
	}
	std::cout << '\n';

	for (unsigned int i = 0; i < longitudVector; i++) {
		std::cin >> xi;
		vectorxi.push_back(xi);
	}
	std::cout << '\n';

	for (unsigned int i = 0; i < longitudVector; i++) {
		totalElementos += potencia(vectorfi[i], 1);
	}
	longitudVector = convierteDoubleEnInt(totalElementos);

	for (unsigned int j = 0; j < longitudVectorInicial; j++) {
		n = vectorfi[j];
		for (unsigned int i = 0; i < n; i++) {
			vector.push_back(vectorxi[x]);
		}
		x++;
	}
}

void MAS::desagruparDesdeArchivo() {
	std::fstream archivo;
	archivo.open("datos.dat", std::ios::in | std::ios::binary);

	double elem = 0;
	double totalElementos = 0;

	unsigned int longitudVectorInicial = longitudVector;
	unsigned int x = 0;
	unsigned int n = 0;

	std::vector<double> vectorxi;
	std::vector<unsigned int> vectorfi;
	std::vector<double> vectorArchivo;

	while (!archivo.eof()) {
		archivo >> elem;
		vectorArchivo.push_back(elem);
	}
	
	for (unsigned int i = 0; i < longitudVector; i++) {
		vectorfi.push_back(convierteDoubleEnInt(vectorArchivo[i]));
		vectorxi.push_back(vectorArchivo[i+longitudVector]);
	}

	for (unsigned int i = 0; i < longitudVector; i++) {
		totalElementos += potencia(vectorfi[i], 1);
	}
	longitudVector = convierteDoubleEnInt(totalElementos);

	for (unsigned int j = 0; j < longitudVectorInicial; j++) {
		n = vectorfi[j];
		for (unsigned int i = 0; i < n; i++) {
			vector.push_back(vectorxi[x]);
		}
		x++;
	}
}

void MAS::leerDesdeTeclado() {
	if (agrupados == true) {
		std::cout << "Introduce la frecuencia (fi) de los datos " << "\n";
		std::cout << "uno a uno separados por un espacio, después " << "\n";
		std::cout << "pulsa intro para escribir el valor (xi)" << "\n";
		std::cout << "\n";
	} else {
		std::cout << "Introduce los elementos uno a uno " << "\n";
		std::cout << "después pulsa intro" << "\n";
		std::cout << "\n";
	}
}

double MAS::calcularEstimador() {
	double resultado = 0;
	switch (estimador) {
		case 1 :
			resultado = mediaAritmetica();
			break;
		case 2 :
			resultado = N * mediaAritmetica();
			break;
		case 3 :
			resultado = mediaAritmetica();
			break;
	}
	return resultado;
}

double MAS::calculoIC() {
	double resultado = 0;
	return resultado;
}

double MAS::varianzaEstimador() {
	double resultado = 0;
	unsigned int n = longitudVector;
	double f = n / (double)N;
	double S2 = varianzaMuestral();
	double N2 = potencia(N, 2);
	double P = 0;
	double Q = 0;
	switch (estimador) {
		case 1 :
			resultado = (1 - f) * (S2 / n);
			break;
		case 2 :
			resultado = N2 * (1 - f) * (S2 / n);
			break;
		case 3 :
			P = mediaAritmetica();
			Q = 1 - P;
			resultado = ((N - n) / (N - 1)) * ((P * Q) / (n - 1));
			break;
	}
	return resultado;
}
*/
double MAS::em() {
	double resultado = 0;
	resultado = sqrt(varianzaEstimador());
	return resultado;
}

double MAS::estimadorVarianza() {
	double resultado = 0;
	return resultado;
}
