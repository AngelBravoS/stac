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

void mostrarMedidasTendenciaCentral(Vector &datos) {
	std::cout << "\nSumatorias" << std::endl;
	imprimirResultado("∑Xi", sumatoria(datos, 1));
	imprimirResultado("∑Xi^2", sumatoria(datos, 2));

	std::cout << "\nMedidas de tendencia central" << std::endl;
	imprimirResultado("Media aritmética", mediaAritmetica(datos));
	imprimirResultado("Media geométrica", mediaGeometrica(datos));
	imprimirResultado("Media armónica", mediaArmonica(datos));
	imprimirResultado("Media cuadrática", mediaCuadratica(datos));
	imprimirResultado("Mediana", mediana(datos));
	imprimirResultado("Moda", moda(datos));
}

void mostrarMedidasDispersion(Vector &datos) {
	std::cout << "\nMedidas de dispersión" << std::endl;
	imprimirResultado("Varianza", varianza(datos));
	imprimirResultado("Varianza muestral", varianzaMuestral(datos));
	imprimirResultado("Desviación típica", desviacionTipica(datos));
	imprimirResultado("Desviación típica muestral", desviacionTipicaMuestral(datos));
	imprimirResultado("Coef. variación Pearson", coeficienteVarPearson(datos));
	imprimirResultado("Norma", norma(datos));

	std::cout << "\nMedidas de forma" << std::endl;
	imprimirResultado("Coef. asimetría de Fisher", coeficienteAsimetriaFisher(datos));
	imprimirResultado("Coeficiente de apuntamiento de Fisher", coefApuntFisher(datos));
}

void CLI::menuSecundario1Var() {
	tamanyo = preguntarNumeroElementos();
	desdeArchivo = preguntarDesdeArchivoOTeclado();
	Vector datos(tamanyo);

	// Entrada de datos
	if (desdeArchivo) {
		verificarArchivo();
		leerDesdeArchivo(datos);
	} else {
		leerDatosDesdeTeclado(datos);
	}

	std::cout << "\nVector " << std::endl;
	mostrarVector(datos);

	// Cálculos y resultados
	mostrarMedidasTendenciaCentral(datos);
	mostrarMedidasDispersion(datos);
	std::cout << std::endl;
}

