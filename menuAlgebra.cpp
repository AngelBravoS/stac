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

#include "cli.hpp"
#include "calculosAlgebra.hpp"

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
        }
        else if (elegir1o2Matrices == '2') {
            menu2Matrices();
        }
    }
    while (elegir1o2Matrices != '0');
}

void CLI::menu1Matriz() {
    char opciones;
    unsigned int filas, columnas;
    filas = numeroFilas();
    columnas = numeroColumnas();
    bool desdeArchivo;
    desdeArchivo = preguntarDesdeArchivoOTeclado();
    Matriz matrizA(filas, columnas);
    if (desdeArchivo == true) {
        verificarArchivo();
        leerDesdeArchivo(matrizA, columnas);
    } else {
        std::cout << "Introduce los elementos uno a uno " << "\n";
        std::cout << "pulsa intro para escribir la fila siguiente" << "\n";
        std::cout << "\n";
        editarMatrizVacia(matrizA);
    }
    std::cout << '\n';
    std::cout << ("Matriz ") << "\n";
    mostrarMatriz(matrizA);
    std::cout << '\n';

    do {
        std::cout << "Cálculos de una matriz" << "\n";
        std::cout << "'1' Traza" << "\n";
        std::cout << "'2' Determinante" << "\n";
        std::cout << "'3' Matriz traspuesta" << "\n";
        std::cout << "'4' Matriz adjunta" << "\n";
        std::cout << "'5' Matriz inversa" << "\n";
        std::cout << "'6' Descomposicion LU" << "\n";
        std::cout << "'7' Gauss" << "\n";
        std::cout << "'8' Valores y vectores propios" << "\n";
        std::cout << "'0' para volver al menu anterior." << "\n";
        std::cout << "=> ";
        std::cin >> opciones;
        switch (opciones) {
        case '1':
            mostrarMatriz(matrizA);
            std::cout << '\n';
            std::cout << "Traza: " << traza(matrizA) << "\n" ;
            std::cout << '\n';
            break;
        case '2':
            mostrarMatriz(matrizA);
            std::cout << '\n';
            std::cout << "Determinante: " << determinante(matrizA) << "\n" ;
            std::cout << '\n';
            break;
        case '3':{
            mostrarMatriz(matrizA);
            Matriz resultado(filas, columnas);
            resultado = traspuesta(matrizA);
            std::cout << '\n';
            std::cout << ("Matriz A traspuesta ") << "\n";
            mostrarMatriz(resultado);
            std::cout << '\n';}
            break;
        case '4':{
            mostrarMatriz(matrizA);
            Matriz resultado(filas, columnas);
            resultado = adjunta(matrizA);
            std::cout << '\n';
            std::cout << ("Matriz A adjunta ") << "\n";
            mostrarMatriz(resultado);
            std::cout << '\n';}
            break;
        case '5':{
            mostrarMatriz(matrizA);
            Matriz resultado(filas, columnas);
            resultado = inversa(matrizA);
            std::cout << '\n';
            std::cout << ("Matriz A inversa ") << "\n";
            mostrarMatriz(resultado);
            std::cout << '\n';}
            break;
        case '6':{
            mostrarMatriz(matrizA);
            Matriz resultado(filas, columnas);
            resultado = descomposicionLU(matrizA, true);
            std::cout << '\n';
            std::cout << ("Matriz L ") << "\n";
            mostrarMatriz(resultado);
            std::cout << '\n';
            resultado = descomposicionLU(matrizA, false);
            std::cout << '\n';
            std::cout << ("Matriz U ") << "\n";
            mostrarMatriz(resultado);
            std::cout << '\n';}
            break;
        case '7':{
            Matriz resultado(filas, columnas);
            resultado = gauss(matrizA);
            std::cout << '\n';
            std::cout << ("Matriz A Gauss ") << "\n";
            mostrarMatriz(resultado);
            std::cout << '\n';}
            break;
        }
    } while (opciones != '0');
}

void CLI::menu2Matrices() {
    char opciones;

    unsigned int filas, columnas;
    filas = numeroFilas();
    columnas = numeroColumnas();
    bool desdeArchivo;
    std::cout << "Matriz A" << "\n";
    desdeArchivo = preguntarDesdeArchivoOTeclado();
    Matriz matrizA(filas, columnas);
    if (desdeArchivo == true) {
        verificarArchivo();
        leerDesdeArchivo(matrizA, columnas);
    } else {
        std::cout << "Introduce los elementos uno a uno " << "\n";
        std::cout << "pulsa intro para escribir la fila siguiente" << "\n";
        std::cout << "\n";
        editarMatrizVacia(matrizA);
    }

    std::cout << "Matriz B" << "\n";
    Matriz matrizB(numeroFilas(), numeroColumnas());
    desdeArchivo = preguntarDesdeArchivoOTeclado();
    if (desdeArchivo == true) {
        verificarArchivo();
        leerDesdeArchivo(matrizB, columnas);
    } else {
        std::cout << "Introduce los elementos uno a uno " << "\n";
        std::cout << "pulsa intro para escribir la fila siguiente" << "\n";
        std::cout << "\n";
        editarMatrizVacia(matrizB);
    }


    std::cout << '\n';
    std::cout << ("Matriz A") << "\n";
    mostrarMatriz(matrizA);
    std::cout << '\n';

    std::cout << '\n';
    std::cout << ("Matriz B") << "\n";
    mostrarMatriz(matrizB);
    std::cout << '\n';

    do {
        std::cout << "Cálculos de dos matrices" << "\n";
        std::cout << "'1' Suma" << "\n";
        std::cout << "'2' Multiplicación" << "\n";
        std::cout << "'3' Kronecker" << "\n";
        std::cout << "'0' para volver al menu anterior." << "\n";
        std::cout << "=> ";
        std::cin >> opciones;
        switch (opciones) {
        case '1': {
            Matriz resultado = matrizA + matrizB;
            mostrarMatriz(resultado);
        }
        break;
        case '2': {
            Matriz resultado = matrizA * matrizB;
            mostrarMatriz(resultado);
        }
        break;
        case '3':
            //kronecker();
            break;
        }
    } while (opciones != '0');
}

