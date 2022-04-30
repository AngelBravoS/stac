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

#ifndef _CALCULOSNVAR_HPP_
#define _CALCULOSNVAR_HPP_

#include "matriz.hpp"

class CalculosNVar {
	public:
		//======== constructor ======== 
		CalculosNVar();
		CalculosNVar(bool archivo, unsigned int longitudFila, unsigned int 
longitudColumna);
		//======== funciones de la matriz de datos ======== 
		void crearMatrizResultado();
		void mostrarMatrizResultado();
		//========  funciones de estadística descriptiva ======== 
		double sumatoria ( int indiceVariable, short unsigned int exponente );
		double total (int indiceVariable);
		double mediaAritmetica ( int indiceVariable );
		double mediaGeometrica ( int indiceVariable ) ;
		double mediaArmonica ( int indiceVariable );
		double mediaCuadratica ( int indiceVariable );
		double difRespecMedia ( int indiceVariable, int exponente );
		double varianza ( int indiceVariable );
		double cuasiVarianza ( int indiceVariable );
		double desviacionTipica ( int indiceVariable );
		double cuasiDesviacionTipica ( int indiceVariable );
		double momentos ( int indiceVariable, int exponente );
		double coeficientePearson ( int indiceVariable );
		double coeficienteAsimetriaFisher ( int indiceVariable );
		double curtosis ( int indiceVariable );
		double covarianza ( int indiceVariable );
		//========  funciones de procesos estocásticos ========
		void matrizTransicionP(unsigned int n);
		
	protected:
		double **resultado;
		//double sumatoria;
		//double media;
		//double varianza;
		//double cuasiVarianza;
};

#endif /* _MATRIZ_HPP_ */
