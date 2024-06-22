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
	Vector datos(tamanyo);
	
	if (desdeArchivo == true) {
		verificarArchivo();
		leerDesdeArchivo(datos);
	} else {
		std::cout << "Introduce los elementos uno a uno" << "\n";
		std::cout << "separando con un espacio." << "\n";
		for (unsigned int i = 0; i < datos.size(); i++) {
			std::cin >> datos[i];
		}
		std::cout << '\n';
	}
	std::cout << '\n';
	std::cout << ("vector ") << "\n";
	mostrarVector(datos);

	std::cout << '\n';
	std::cout << "Sumatorias" << '\n';
	std::cout << "∑Xi = " << sumatoria(datos, 1) << '\n';
	std::cout << "∑Xi^2 = " << sumatoria(datos, 2) << '\n';
	std::cout << '\n';
	std::cout << '\n';
	std::cout << "Medidas de tendencia central" << '\n';

	std::cout << "Medias" << '\n';
	std::cout << "_" << '\n';
	std::cout << "Xa = " << mediaAritmetica(datos) << '\n';
	std::cout << "_" << '\n';
	std::cout << "Xg = " << mediaGeometrica(datos) << '\n';
	std::cout << "_" << '\n';
	std::cout << "Xa = " << mediaArmonica(datos) << '\n';
	std::cout << "_" << '\n';
	std::cout << "Xc = " << mediaCuadratica(datos);
	std::cout << '\n';
	std::cout << '\n';

	std::cout << "Mediana = " << mediana(datos) << '\n';
	std::cout << '\n';

	std::cout << "Moda = " << moda(datos) << '\n';
	std::cout << '\n';

	std::cout << "Vector ordenado" << '\n';
	mostrarVector(datos);
	std::cout << '\n';

	std::cout << "Diferencias respecto a la media ^2 = " <<
	          difRespecMedia(datos, 2) << '\n';
	std::cout << "Diferencias respecto a la media ^3 = " <<
	          difRespecMedia(datos, 3) << '\n';
	std::cout << '\n';
	std::cout << "Momentos centrados de orden 2 (Varianza) = " <<
	          momentosNoCentrados(datos, 2) << '\n';
	std::cout << "Momentos centrados de orden 3 = " <<
	          momentosNoCentrados(datos, 3) << '\n';
	std::cout << '\n';

	std::cout << "Medidas de dispersión" << '\n';
	std::cout << '\n';
	std::cout << "     _ 2" << '\n';
	std::cout << "∑(Xi-X) = " << difRespecMedia(datos, 2) << '\n';

	std::cout << "                _ 2" << '\n';
	std::cout << "           ∑(Xi-X)" << '\n';
	std::cout << "varianza = ------- = "  << varianza(datos) << '\n';
	std::cout << "              1  " << '\n';

	std::cout << "                         _ 2" << '\n';
	std::cout << "                    ∑(Xi-X)" << '\n';
	std::cout << "varianza muestral = ------- = "
	          << varianzaMuestral(datos) << '\n';
	std::cout << "                     (n-1)  " << '\n';
	std::cout << '\n';
	std::cout << "Desviación típica = sqrt(varianza) = "
	          << desviacionTipica(datos) << '\n';
	std::cout << "Desviación típica muestral = sqrt(varianza muestral) = "
	          << desviacionTipicaMuestral(datos) << '\n';
	std::cout << '\n';
	std::cout << "Coef. variación Pearson = "
	          << coeficienteVarPearson(datos) << '\n';
	std::cout << "Norma = " << norma(datos) << '\n';
	std::cout << '\n';

	std::cout << "Medidas de forma" << '\n';
	std::cout << "Coef. asímetría de Fisher = "
	          << coeficienteAsimetriaFisher(datos) << '\n';

	double g2=coefApuntFisher(datos);
	std::cout << "Coeficiente de apuntamiento de Fisher = " << g2 << '\n';
	std::cout << '\n';
	if(g2<0){
		std::cout << "Coeficiente de apuntamiento de Fisher = ";
		std::cout << '\n';
	}else if(g2>0){
		std::cout << "Coeficiente de apuntamiento de Fisher = ";
		std::cout << '\n';
	}else{
		std::cout << "Coeficiente de apuntamiento de Fisher = ";
		std::cout << '\n';
	}
}
