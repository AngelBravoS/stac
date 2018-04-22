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
		//Obtener = Get
		//Establecer = Set
	public:
		//========  funciones de muestreo ======== 
		
		char getTipoMuestreo();
		void setTipoMuestreo ( char tipoMuestreoPublico );			
		
		bool getAgrupados();
		void setAgrupados ( bool agrupadosPublico );
		
		bool getLeeArchivo();
		void setLeeArchivo(bool leeArchivoPublico);		
		
		bool getReemplazo();
		void setReemplazo ( bool reemplazoPublico );		
		
		bool getProbIguales();
		void setProbIguales(bool probIgualesPublico);
		
		bool getMismoTamanyo();
		void setMismoTamanyo(bool mismoTamanyoPublico);	
	
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

		void leerDatosDesdeTeclado();
		void leerDatosDesdeArchivo();
		void desagrupar();
		
		void calculoXi2();
		void calculoXi();
		void calculoEstimador();
		void calculoIC();
		void varianzaEstimador();		
		void estimadorVarianza();
		
		void incorporarXiYXi2();
		
	protected:

		bool agrupados, leeArchivo, reemplazo, probIguales, mismoTamanyo;
		char tipoMuestreo;
		double sumatoriaXi;
		double sumatoriaXi2;
		double estimador;
		double varianzaDelEstimador;
		double estimadorDeLaVarianza;
};
