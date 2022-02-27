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

#include "calculosNVar.hpp"
#include "funcMatematicasBasicas.hpp"
#include <cmath>
#include <fstream>
 
class MAS : public CalculosNVar {
	public:
		MAS(bool archivo, unsigned int numeroColumnas, bool datosAgrupados);
		MAS(bool archivo, char estimadorElegido, unsigned int numeroColumnas, bool datosAgrupados);
		void editarMatrizVacia();
		//========  funciones de muestreo ======== 
		void desdeDondeLeeDatos();
		void leerDesdeTeclado();
		void leerDesdeArchivo();
		void asignarVariables();
		void desagruparElementos();
		void desagrupar();
		void incorporarXiYXi2();
		void crearMatrizParaCalculos();
		
		double calcularEstimador();
		double media(int indiceVariable );
		double proporcion(int indiceVariable );
		double total(int indiceVariable );
		
		double varianzaEstimador();		
		double estimadorVarianza();
	
		double calculoIC();
	protected:
		bool agrupados;
		unsigned int columnasMatrizResuelta, filasMatrizResuelta;
		unsigned int estimador;
		double mediaDeX, proporcionDeX, totalDeX;
		double sumatoriaDeX;
		double sumatoriaCuadradoDeX;
		double ic;
		
		double varianzaDelEstimador;
		double estimadorDeLaVarianza;
};
