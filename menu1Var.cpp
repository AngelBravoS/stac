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

#include <iostream>
#include "menu1Var.hpp"

unsigned int Menu1Var::preguntarNumeroElementos() {
	unsigned int col;
	std::cout << "Número de elementos: ";
	std::cin >> col;
	return col;
}

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

void Menu1Var::menuSecundario() {
	Calculos1Var variable(preguntarDesdeArchivoOTeclado(),
	                      preguntarNumeroElementos());
	variable.desdeDondeLeeVector();
	std::cout << '\n';
	std::cout << "Vector" << '\n';
	variable.mostrarVector();
	std::cout << '\n';
	std::cout << "Sumatorias" << '\n';
	std::cout << "∑Xi = " << variable.sumatoria(1) << '\n';
	std::cout << "∑Xi^2 = " << variable.sumatoria(2) << '\n';
	std::cout << '\n';
	std::cout << '\n';
	std::cout << "Medidas de tendencia central" << '\n';

	std::cout << "Medias" << '\n';
	std::cout << "_" << '\n';
	std::cout << "Xa = " << variable.mediaAritmetica() << '\n';
	std::cout << "_" << '\n';
	std::cout << "Xg = " << variable.mediaGeometrica() << '\n';
	std::cout << "_" << '\n';
	std::cout << "Xa = " << variable.mediaArmonica() << '\n';
	std::cout << "_" << '\n';
	std::cout << "Xc = " << variable.mediaCuadratica();
	std::cout << '\n';
	std::cout << '\n';

	std::cout << "Mediana = " << variable.mediana() << '\n';
	std::cout << '\n';
	std::cout << "Vector ordenado"<< '\n';
	variable.mostrarVector();
	std::cout << '\n';
	
	std::cout << "Diferencias respecto a la media ^2 = " <<
	          variable.difRespecMedia(2) << '\n';
	std::cout << "Diferencias respecto a la media ^3 = " <<
	          variable.difRespecMedia(3) << '\n';
		std::cout << '\n';         
	std::cout << "Momentos centrados de orden 2 (Varianza) = " <<
	          variable.momentosNoCentrados(2) << '\n';
	std::cout << "Momentos centrados de orden 3 = " <<
	          variable.momentosNoCentrados(3) << '\n';
	std::cout << '\n';

	std::cout << "Medidas de dispersión" << '\n';
	std::cout << '\n';
	std::cout << "     _ 2" << '\n';
	std::cout << "∑(Xi-X) = " << variable.difRespecMedia(2) << '\n';

	std::cout << "                _ 2" << '\n';
	std::cout << "           ∑(Xi-X)" << '\n';
	std::cout << "varianza = ------- = "  << variable.varianza() << '\n';
	std::cout << "              1  " << '\n';

	std::cout << "                         _ 2" << '\n';
	std::cout << "                    ∑(Xi-X)" << '\n';
	std::cout << "varianza muestral = ------- = "
	          << variable.varianzaMuestral() << '\n';
	std::cout << "                     (n-1)  " << '\n';
	std::cout << '\n';
	std::cout << "Desviación típica = sqrt(varianza) = "
	          << variable.desviacionTipica() << '\n';
	std::cout << "Desviación típica muestral = sqrt(varianza muestral) = "
	          << variable.desviacionTipicaMuestral() << '\n';
	std::cout << '\n';
	std::cout << "Coef. variación Pearson = "
	          << variable.coeficientePearson() << '\n';
	std::cout << "Norma = " << variable.norma() << '\n';
	std::cout << '\n';
	std::cout << "Medidas de forma" << '\n';
	std::cout << "Coef. asímetría de Fisher = "
	          << variable.coeficienteAsimetriaFisher() << '\n';
	std::cout << "Curtosis = " << variable.curtosis() << '\n';
	std::cout << '\n';
}
