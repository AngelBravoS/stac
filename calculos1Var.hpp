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

#ifndef _CALCULOS1VAR_HPP_
#define _CALCULOS1VAR_HPP_

#include "vector.hpp"
#include "funcMatematicasBasicas.hpp"

class Calculos1Var : public Vector {
public:
	//======== constructor ========
	Calculos1Var(bool leerArchivo, unsigned int longitudVector);
	//========  funciones de estadística descriptiva ========
	double sumatoria(unsigned int exponente);
	double mediaAritmetica();
	double mediaGeometrica() ;
	double mediaArmonica();
	double mediaCuadratica();
	double mediana();
	double moda();
	double difRespecMedia(int exponente);
	double varianza();
	double varianzaMuestral();
	double desviacionTipica();
	double desviacionTipicaMuestral();
	double momentosNoCentrados(int exponente);
	double coeficientePearson();
	double coeficienteAsimetriaFisher();
	double curtosis();
	double norma();
	//======== funciones de inferencia ========
	//-------- Contrastes en poblaciones normales --------
	//-------- de una muestra. Relativo a la media--------
	double media1MuestraSigmaConocida();
	double media1MuestraSigmaDesconocida();
	//-------- relativo a la varianza --------
	double var1MuestraMuConocida();
	double var1MuestraMuDesconocida();
	//-------- Aplicaciones del test de razón --------
	//-------- de verosimilitudes --------
	//-------- Test de Chi-cuadrado sobre Sigma^2--------
	double testChiMuConocida();
	double testChiMuDesconocida();
	//-------- Test t Student sobre mu --------
	double testStudentVarConocida();
	double testStudentVarDesconocida();
	};

#endif /* _CALCULOS2VAR_HPP_ */
