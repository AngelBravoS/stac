#pragma once

#include "vector.hpp"
#include "matriz.hpp"
#include <fstream>
#include <cstdlib>

unsigned int numeroFilas();
unsigned int numeroColumnas();
unsigned int preguntarNumeroElementos();

Matriz editarMatrizVacia(Matriz &m1);
//Vector editarVectorVacio(Vector &v1);

bool preguntarDesdeArchivoOTeclado();

void verificarArchivo();
void leerDesdeArchivo(Matriz &m1, unsigned int columnas);
void leerDesdeArchivo(Vector &v1);
//void leerDesdeTeclado();

void setDimensionMatriz();
//void crearMatrizVacia();
void editarMatrizVacia();
