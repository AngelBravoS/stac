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

#include "calculosNVar.hpp"
#include "funcMatematicasBasicas.hpp"
 
class CalculosMuestreo : public CalculosNVar {
	public:
		CalculosMuestreo(bool archivo, char muestreo, unsigned int longitudFila, unsigned int longitudColumna, bool datosAgrupados);
		//========  funciones de muestreo ======== 
		double getSumatoriaXi();
		void setSumatoriaXi ( double SumatoriaXiPublica );	
		double getSumatoriaXi2();
		void setSumatoriaXi2 ( double SumatoriaXi2Publica );	
		double getEstimador();
		void setEstimador ( double estimadorPublico );
		double getVarianzaDelEstimador();
		void setVarianzaDelEstimador ( double varianzaDelEstimadorPublica );
		double getEstimadorDeLaVarianza();
		void setEstimadorDeLaVarianza ( double estimadorDeLaVarianzaPublico );
		void editarMatrizVacia();
		//========  funciones de muestreo ======== 
		void desdeDondeLeeMatriz();
		void leerDatosDesdeTeclado();
		void leerDatosDesdeArchivo();
		void asignar();
		void desagrupar();
		void calculoXi2();
		void calculoXi();
		double estimador();
		
		double calculoIC();
		double varianzaEstimador();		
		double estimadorVarianza();
		void incorporarXiYXi2();
	protected:
		bool agrupados, reemplazo, probIguales, mismoTamanyo;
		//bool leeArchivo;
		char tipoMuestreo;
		double sumatoriaXi;
		double sumatoriaXi2;
		double ic;
		//double estimador;
		double varianzaDelEstimador;
		double estimadorDeLaVarianza;
};
