/***************************************************************************
 *   Copyright (C) 2018 by Ángel Bravo Sáenz                               *
 *   angelbravosaenz@gmail.com                                             *
 *                                                                         *
 *   This file is part of Stac.                                            *
 *                                                                         *
 *   Stac is free software; you can redistribute it and/or modify          *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
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

#include "cli.hpp"
#include "calculos2Var.hpp"

/*void CLI::menuSecundario2Var() {
	char eleccionNivel2;
	do {
		listadOpciones2Variables();
		std::cin >> eleccionNivel2;
		switch (eleccionNivel2) {
			case '1':
				if(esMuestra() == true) {
					menuMuestra2Var();
				} else {
					menuFmp2Var();
				}
			break;
			case '2':
				menuFmp2Var();
			break;
		}
	} while (eleccionNivel2 != '0');
}*/

void CLI::menuSecundario2Var() {
	unsigned int filas, columnas;
	filas = 2;
	columnas = preguntarNumeroElementos();
	desdeArchivo = preguntarDesdeArchivoOTeclado();

	Matriz varXeY(filas, columnas);
	if (desdeArchivo == true) {
		verificarArchivo();
		leerDesdeArchivo(varXeY, columnas);
	} else {
		std::cout << "Introduce los elementos uno a uno " << "\n";
		std::cout << "pulsa intro para escribir la fila siguiente" << "\n";
		std::cout << "\n";
		editarMatrizVacia(varXeY);
	}
	Vector varX(columnas);
	varX = extraerVariable(varXeY, 0);
	std::cout << ("Variable X") << "\n";
	mostrarVector(varX);
	std::cout << '\n';
	Vector varY(columnas);
	varY = extraerVariable(varXeY, 1);
	std::cout << ("Variables Y") << "\n";
	mostrarVector(varY);

	std::cout << '\n';
	std::cout << "Medidas de tendencia Central" << '\n';
	std::cout << " _" << '\n';
	std::cout << " X = " << mediaAritmetica(varX) << '\n';
	std::cout << " _" << '\n';
	std::cout << " Y = " << mediaAritmetica(varY) << '\n';
	std::cout << '\n';
	std::cout << " ∑Xi = " << sumatoria(varX, 1) << '\n';
	std::cout << "    2" << '\n';
	std::cout << " ∑Xi = " << sumatoria(varX, 2) << '\n';
	std::cout << '\n';
	std::cout << " ∑Yi = " << sumatoria(varY, 1) << '\n';
	std::cout << "    2" << '\n';
	std::cout << " ∑Yi = " << sumatoria(varY, 2) << '\n';
	std::cout << '\n';
	std::cout << " ∑XYi = " << sumatoria2Var(varXeY, 1, 1) << '\n';
	std::cout << '\n';

	std::cout << "Medidas de dispersión" << '\n';
	std::cout << "                      _ 2" << '\n';
	std::cout << "                 ∑(Xi-X)" << '\n';
	std::cout << " varianza de X = ------- = "  << varianza(varX) << '\n';
	std::cout << "                    1  " << '\n';
	std::cout << "                      _ 2" << '\n';
	std::cout << "                 ∑(Xi-X)" << '\n';
	std::cout << " varianza de Y = ------- = "  << varianza(varY) << '\n';
	std::cout << "                    1  " << '\n';
	std::cout << '\n';
	std::cout << " Desviación típica de X = " << desviacionTipica(varX) << '\n';
	std::cout << " Desviación típica de Y = " << desviacionTipica(varY) << '\n';
	std::cout << " Covarianza de X e Y = " << covarianza(varXeY) << '\n';
	std::cout << '\n';
	std::cout << "Regresión" << '\n';
	std::cout << "	Rectas de regresión:" << '\n';

	std::cout << "		Recta de Y sobre X: y = " <<
	          coeficienteRegresion(varXeY, varX) << "x" << " + (" <<
	          rectaRegresion(varXeY, varX) + mediaAritmetica(varY) << ")" << '\n';

	std::cout << "		Recta de X sobre Y: x = " <<
	          coeficienteRegresion(varXeY, varY) << "y" << " + (" <<
	          rectaRegresion(varXeY, varY) + mediaAritmetica(varX) << ")" << '\n';

	std::cout << "	Coeficientes de regresión:" << '\n';

	std::cout << "		Coeficiente de Y sobre X: " <<
	          coeficienteRegresion(varXeY, varX) << '\n';
	std::cout << "		Coeficiente de X sobre Y: " <<
	          coeficienteRegresion(varXeY, varY) << '\n';
	std::cout << '\n';
	std::cout << "Correlación" << '\n';
	std::cout << "	Coeficiente de correlación lineal: " <<
	          coeficienteCorrelacion(varXeY) << '\n';
}

/*void CLI::menuFmp2Var(){
	CalculosTablasContBid variables(preguntarDesdeArchivoOTeclado(),
preguntarNumeroFilas(), preguntarNumeroColumnas());
	variables.leerMatriz();
	std::cout << "Variables X e Y:" << '\n';
	variables.mostrarMatriz();
	std::cout << '\n';
	}

unsigned int CLI::preguntarNumeroColumnas() {
	unsigned int col;
	std::cout << "Número de elementos de cada variable: ";
	std::cin >> col;
	return col;
	}

bool CLI::esMuestra(){
	char resultado;
	bool muestra;
	std::cout << "'s' si es una muestra de dos variables" << '\n';
	std::cout << "'n' si quieres calcular a partir de la fmp: " << '\n';
	std::cout << ": ";
	std::cin >> resultado;
	resultado == 's' ? muestra = true: muestra = false;
	return muestra;
	}
*/
