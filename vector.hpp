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

class Vector {
		//Obtener = Get
		//Establecer = Set
	public:
		//======== setters y getters ======== 
		unsigned int getLongitudVector();
		void setLongitudVector ( unsigned int longitudVectorPublico );
		double getVector();
		void setVector ( double *vectorPublico );
		double getVectorCopia();
		void setVectorCopia ( double vectorCopiaPublico );
		//======== funciones de vectores ======== 
		void numElementosVector();
		void crearVectorVacio();
		void editarVectorVacio();
		void mostrarVector();
		void copiarvector();
		void mostrarVectorCopia();
		void destructorVector();
		void destructorVectorCopia();		
		//======== trabajo con archivos ======== 
		void leerVectorArchivo();
		void guardarEnArchivo();
	protected:
		
		unsigned int longitudVector;
		double *vector;
		double *vectorCopia;
		bool leerDesdeArchivo;
};
