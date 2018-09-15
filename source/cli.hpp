/***************************************************************************
 *   Copyright (C) 2018 by Ángel Bravo Sáenz                               *
 *   angelbravosaenz@gmail.com                                             *
 *                                                                         *
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

// command-line interface (CLI)
#ifndef _CLI_HPP_
#define _CLI_HPP_

class CLI {
		//Obtener = Get
		//Establecer = Set
	public:
		//======== setters y getters ========
		char getOpcionSeleccionada();
		void setOpcionSeleccionada(char respuestaUsuarioPublica);
		//======== funciones de menu ========
		void introduccion();
		void acercaDe();
		void ayuda();
		void eleccion();
		void hasElegido();
		//======== subfunciones de menu ========
		void menuPrincipal();
		void menuSinDatos();
		void menuTablasCont();
		//======== funciones especificas de cada submenu ========
		void menuInferencia();
		void menuCombinatoria();
		void menuColasExponencial();
		void menuDistribDiscreta();
		//======== Entrada/Salida vectores ========
		bool preguntarDesdeArchivoOTeclado();
		//void verificarArchivo();
		unsigned int preguntarTamanoVector();
		unsigned int preguntarNumeroFilas();
		unsigned int preguntarNumeroColumnas();
		//void numElementosVector();
		//======== Textos de menús ========
		void listadOpcionesPricipales();
		void listadOpcionesMuestreo();
		void listadOpciones1Variable();
		void listadOpciones2Variables();
		void listadOpcionesColasExponencial();

	protected:
		char respuestaUsuario;
		bool archivoValido;
};

#endif /* _CLI_HPP_ */


