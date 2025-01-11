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

// CLI => Command Line Interface.
#include "cli.hpp"

void CLI::eleccion(unsigned int i) { std::cin >> opciones[i]; }

void CLI::menuPrincipal() {
  do {
    listadOpcionesPrincipales();
    std::cout << "> ";
    eleccion(0);
    switch (opciones[0]) {
    case '1':
      menuSecundario1Var();
      break;
    case '2':
      menuSecundario2Var();
      break;
    case '3':
      menuSecundarioNvar();
      break;
    case '4':
      menuSecundarioAlgebra();
      break;
    case '5':
      menuSecundarioInferencia();
      break;
    case '6':
      menuSinDatos();
      break;
    case '7':
      ayuda();
      break;
    }
  } while (opciones[0] != '0');
}

void CLI::menuSecundario1Var() {
  tamanyo = preguntarNumeroElementos();
  desdeArchivo = preguntarDesdeArchivoOTeclado();
  Vector datos(tamanyo);

  if (desdeArchivo) {
    verificarArchivo();
    leerDesdeArchivo(datos);
  } else {
    leerVectorDesdeTeclado(datos);
  }

  std::cout << "\nVector " << std::endl;
  mostrarVector(datos);

  mostrarMedidasTendenciaCentral(datos);
  mostrarMedidasDispersion(datos);
  std::cout << std::endl;
}

void CLI::menuSecundario2Var() {
  unsigned int filas, columnas;
  filas = 2;
  columnas = preguntarNumeroElementos();
  desdeArchivo = preguntarDesdeArchivoOTeclado();

  Matriz varXeY(filas, columnas);
  if (desdeArchivo == true) {
    verificarArchivo();
    leerDesdeArchivo(varXeY, columnas);
  } else {
    textoLeerDesdeTeclado();
    editarMatrizVacia(varXeY);
  }

  Vector varX = extraerVariable(varXeY, 0);
  std::cout << '\n';
  std::cout << ("Variable X") << "\n";
  mostrarVector(varX);
  std::cout << '\n';
  mostrarMedidasTendenciaCentral(varX);
  mostrarMedidasDispersion(varX);

  Vector varY = extraerVariable(varXeY, 1);
  std::cout << '\n';
  std::cout << ("Variable Y") << "\n";
  mostrarVector(varY);
  std::cout << '\n';
  mostrarMedidasTendenciaCentral(varY);
  mostrarMedidasDispersion(varY);

  std::cout << '\n';
  mostrarMedidasRegresionCorrelacion(varXeY, varX, varY);
  std::cout << '\n';
}

void CLI::menuSecundarioAlgebra() {
  char elegir1o2Matrices;
  do {
    std::cout << "'1' Cálculos con una matriz" << '\n';
    std::cout << "'2' Cálculos con dos matrices" << '\n';
    std::cout << "'0' Salir al menú principal." << '\n';
    std::cout << "> ";
    std::cin >> elegir1o2Matrices;
    if (elegir1o2Matrices == '1') {
      menu1Matriz();
    } else if (elegir1o2Matrices == '2') {
      menu2Matrices();
    }
  } while (elegir1o2Matrices != '0');
}

void CLI::menu1Matriz() {
  Matriz matrizA = crearMatriz();
  std::cout << '\n';
  std::cout << ("Matriz A") << "\n";
  mostrarMatriz(matrizA);
  std::cout << '\n';
  mostrarCalculos1Matriz(matrizA);
}

void CLI::menu2Matrices() {
  std::cout << "Matriz A" << "\n";
  Matriz matrizA = crearMatriz();

  std::cout << "Matriz B" << "\n";
  Matriz matrizB = crearMatriz();

  std::cout << '\n';
  std::cout << ("Matriz A") << "\n";
  mostrarMatriz(matrizA);
  std::cout << '\n';

  std::cout << '\n';
  std::cout << ("Matriz B") << "\n";
  mostrarMatriz(matrizB);
  std::cout << '\n';

  mostrarCalculos2Matrices(matrizA, matrizB);
}
