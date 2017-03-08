#include <iostream>
#include "cli.hpp"
#include "matriz.hpp"

using namespace std;

void CLI::menuMatrices() {
    char primeraEleccion, segundaEleccion;
    do {
        cout << "'1' Cálculos con una matriz" << endl;
        cout << "'2' Cálculos con dos matrices" << endl;
        cout << "'0' Salir." << endl;
        cout << "> ";
        cin >> primeraEleccion;
        switch ( primeraEleccion ) {
            case '1':
                Matriz matrizA;
                matrizA.recogerDatosMatriz();
                matrizA.crearMatrizVacia();
                matrizA.editarMatrizVacia();
                matrizA.mostrarMatriz();
                cout << endl;
                do {
                    cout << "Cálculos de una matriz" << endl;
                    cout << "'1' Traza" << endl;
                    cout << "'2' Determinante" << endl;
                    cout << "'3' Matriz traspuesta" << endl;
                    cout << "'4' Matriz adjunta" << endl;
                    cout << "'5' Matriz inversa" << endl;
                    cout << "'6' Vectores y valores propios" << endl;
                    cout << "'7' Métodos numéricos" << endl;
                    cout << "'0' Volver al menú anterior." << endl;
                    cout << "> ";
                    cin >> segundaEleccion;
                    cout << endl;
                    switch ( segundaEleccion ) {
                        case '1':
                            matrizA.mostrarMatriz();
                            cout << endl;
                            cout << "La traza de la matriz A es: " <<
                                 matrizA.traza() << endl;
                            cout << endl;
                            break;
                        case '2':
                            matrizA.mostrarMatriz();
                            cout << endl;
                            cout << "El determinante de la matriz A es: " <<
                                 matrizA.determinante() << endl;
                            cout << endl;
                            break;
                        case '3':
                            matrizA.mostrarMatriz();
                            cout << endl;
                            matrizA.traspuesta();
                            cout << "La matriz traspuesta de A es: " << endl;
                            matrizA.mostrarMatrizResultado();
                            cout << endl;
                            break;
                        case '4':
                            //matrizA.adjunta();
                            break;
                        case '5':
                            matrizA.mostrarMatriz();
                            cout << endl;
                            matrizA.inversa();
                            cout << endl;
                            break;
                        case '6':
                            //matrizA.vectoresProp();
                            break;
                        }
                    }
                while ( segundaEleccion != '0' );
                break;
            case '2':
                Matriz matrizB;
                matrizB.recogerDatosMatriz();
                matrizB.crearMatrizVacia();
                matrizB.editarMatrizVacia();
                matrizB.mostrarMatriz();
                do {
                    cout << "Cálculos de dos matrices" << endl;
                    cout << "'1' Suma" << endl;
                    cout << "'2' Multiplicación" << endl;
                    cout << "'3' Kronecker" << endl;
                    cout << "'0' Menú anterior." << endl;
                    cout << "> ";
                    cin >> segundaEleccion;
                    switch ( segundaEleccion ) {
                        case '1':
                            //sumaMatrices();
                            break;
                        case '2':
                            //multiplicMatrices();
                            break;
                        case '3':
                            //kronecker();
                            break;
                        }
                    }
                while ( segundaEleccion != '0' );
                break;
            }
        }
    while ( primeraEleccion != '0' );
    }
