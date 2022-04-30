#pragma once

#include "matriz.hpp"
#include <fstream>
#include <cstdlib>

unsigned int numeroFilas();
unsigned int numeroColumnas();

Matriz editarMatrizVacia(Matriz &m1);

bool preguntarDesdeArchivoOTeclado();

void leerMatriz(bool archivo);
void verificarArchivo();
void leerDesdeArchivo(Matriz &m1, unsigned int columnas);
void leerDesdeTeclado();

void setDimensionMatriz();
void crearMatrizVacia();
void editarMatrizVacia();
