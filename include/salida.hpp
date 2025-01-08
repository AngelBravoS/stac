#pragma once

#include <iostream>
#include "vector.hpp"
#include "matriz.hpp"

//void guardarEnArchivo(); <- no implementado todavía.
void mostrarVector(Vector &v1);
void mostrarMatriz(Matriz &m1);
void imprimirResultado(const std::string &descripcion, double valor);
