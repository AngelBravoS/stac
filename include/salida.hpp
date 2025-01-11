#pragma once

#include "calculos1Var.hpp"
#include "calculos2Var.hpp"
#include "calculosAlgebra.hpp"
#include "matriz.hpp"
#include "textosMenus.hpp"
#include "vector.hpp"
#include <iostream>

// void guardarEnArchivo(); <- no implementado todavía.
void mostrarVector(Vector &v1);
void mostrarMatriz(Matriz &m1);
void imprimirResultado(const std::string &descripcion, double valor);
void mostrarMedidasTendenciaCentral(Vector &datos);
void mostrarMedidasDispersion(Vector &datos);
void mostrarMedidasRegresionCorrelacion(Matriz &varXeY, Vector &varX,
                                        Vector &varY);
void mostrarCalculos1Matriz(Matriz &matrizA);
void mostrarCalculos2Matrices(Matriz &matrizA, Matriz &matrizB);
