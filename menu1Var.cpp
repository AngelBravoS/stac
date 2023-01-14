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

#include "cli.hpp"
#include "calculos1Var.hpp"

/*bool Menu1Var::preguntarSiAgrupados(){
	char respuesta;
	bool agrupados;
	std::cout << '\n';
	std::cout << "¿Los datos están agrupados?" << '\n';
	std::cout << "s/n:";
	std::cin >> respuesta;
	respuesta == 's' ? agrupados = true : agrupados = false;
	return agrupados;
}*/

void CLI::menuSecundario1Var() {
	tamanyo = preguntarNumeroElementos();
	desdeArchivo = preguntarDesdeArchivoOTeclado();
	Vector vectorA(tamanyo);
	
	if (desdeArchivo == true) {
		verificarArchivo();
		leerDesdeArchivo(vectorA);
	} else {
		std::cout << "Introduce los elementos uno a uno" << "\n";
		std::cout << "separando con un espacio." << "\n";
		for (unsigned int i = 0; i < vectorA.size(); i++) {
			std::cin >> vectorA[i];
		}
		std::cout << '\n';
	}
	std::cout << '\n';
	std::cout << ("vector ") << "\n";
	mostrarVector(vectorA);

	std::cout << '\n';
	std::cout << "Sumatorias" << '\n';
	std::cout << "∑Xi = " << sumatoria(vectorA, 1) << '\n';
	std::cout << "∑Xi^2 = " << sumatoria(vectorA, 2) << '\n';
	std::cout << '\n';
	std::cout << '\n';
	std::cout << "Medidas de tendencia central" << '\n';

	std::cout << "Medias" << '\n';
	std::cout << "_" << '\n';
	std::cout << "Xa = " << mediaAritmetica(vectorA) << '\n';
	std::cout << "_" << '\n';
	std::cout << "Xg = " << mediaGeometrica(vectorA) << '\n';
	std::cout << "_" << '\n';
	std::cout << "Xa = " << mediaArmonica(vectorA) << '\n';
	std::cout << "_" << '\n';
	std::cout << "Xc = " << mediaCuadratica(vectorA);
	std::cout << '\n';
	std::cout << '\n';

	std::cout << "Mediana = " << mediana(vectorA) << '\n';
	std::cout << '\n';
	std::cout << "Vector ordenado" << '\n';
	mostrarVector(vectorA);
	std::cout << '\n';

	std::cout << "Diferencias respecto a la media ^2 = " <<
	          difRespecMedia(vectorA, 2) << '\n';
	std::cout << "Diferencias respecto a la media ^3 = " <<
	          difRespecMedia(vectorA, 3) << '\n';
	std::cout << '\n';
	std::cout << "Momentos centrados de orden 2 (Varianza) = " <<
	          momentosNoCentrados(vectorA, 2) << '\n';
	std::cout << "Momentos centrados de orden 3 = " <<
	          momentosNoCentrados(vectorA, 3) << '\n';
	std::cout << '\n';

	std::cout << "Medidas de dispersión" << '\n';
	std::cout << '\n';
	std::cout << "     _ 2" << '\n';
	std::cout << "∑(Xi-X) = " << difRespecMedia(vectorA, 2) << '\n';

	std::cout << "                _ 2" << '\n';
	std::cout << "           ∑(Xi-X)" << '\n';
	std::cout << "varianza = ------- = "  << varianza(vectorA) << '\n';
	std::cout << "              1  " << '\n';

	std::cout << "                         _ 2" << '\n';
	std::cout << "                    ∑(Xi-X)" << '\n';
	std::cout << "varianza muestral = ------- = "
	          << varianzaMuestral(vectorA) << '\n';
	std::cout << "                     (n-1)  " << '\n';
	std::cout << '\n';
	std::cout << "Desviación típica = sqrt(varianza) = "
	          << desviacionTipica(vectorA) << '\n';
	std::cout << "Desviación típica muestral = sqrt(varianza muestral) = "
	          << desviacionTipicaMuestral(vectorA) << '\n';
	std::cout << '\n';
	std::cout << "Coef. variación Pearson = "
	          << coeficientePearson(vectorA) << '\n';
	std::cout << "Norma = " << norma(vectorA) << '\n';
	std::cout << '\n';
	std::cout << "Medidas de forma" << '\n';
	std::cout << "Coef. asímetría de Fisher = "
	          << coeficienteAsimetriaFisher(vectorA) << '\n';
	std::cout << "Curtosis = " << curtosis(vectorA) << '\n';
	std::cout << '\n';
}
