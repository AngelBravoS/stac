/***************************************************************************														*
 *   Copyright (C) 2018 by Ángel Bravo Sáenz  										*
 *   angelbravosaenz@gmail.com  															*
 *																									*
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

#ifndef _CALCULOSNVAR_HPP_
#define _CALCULOSNVAR_HPP_

#include "matriz.hpp"

class CalculosNVar : public Matriz {

	public:
		//========  getters & setters ======== 
		double getSumatoria();
		void setSumatoria ( double sumatoria );	
		double getVarianza();
		void setVarianza ( double varianzaPublica );	
		//========  funciones de estadística descriptiva ======== 
		double calculoSumatoria ( int indiceVariable, short unsigned int exponente );
		double calculoMediaAritmetica ( int indiceVariable );
		double calculoMediaGeometrica ( int indiceVariable ) ;
		double calculoMediaArmonica ( int indiceVariable );
		double calculoMediaCuadratica ( int indiceVariable );
		double difRespecMedia ( int indiceVariable, int exponente );
		double calculoVarianza ( int indiceVariable );
		double calculoCuasiVarianza ( int indiceVariable );
		double desviacionTipica ( int indiceVariable );
		double cuasiDesviacionTipica ( int indiceVariable );
		double momentos ( int indiceVariable, int exponente );
		double coeficientePearson ( int indiceVariable );
		double coeficienteAsimetriaFisher ( int indiceVariable );
		double curtosis ( int indiceVariable );
		double covarianza ( int indiceVariable );
		//========  funciones de tablas de contingencia ========
		
				
	protected:
		double sumatoria;
		double media;
		double varianza;
		double cuasiVarianza;
};

#endif /* _MATRIZ_HPP_ */
