#pragma once

#include "vector.hpp"
#include "matriz.hpp"
#include "mas.hpp"
#include "textosMenus.hpp"
#include <fstream>
#include <cstdlib>

unsigned int numeroFilas();
unsigned int numeroColumnas();
unsigned int preguntarNumeroElementos();
unsigned int preguntarNumeroColumnas(bool agrupados);

bool preguntarSiAgrupados();
bool preguntarSiNExiste();
unsigned int preguntarEstimador();
unsigned int preguntarTipoDeMuestreo();

Matriz crearMatriz();
Matriz crearMatrizVacia();
Matriz editarMatrizVacia(Matriz &m1);
//Vector editarVectorVacio(Vector &v1);

bool preguntarDesdeArchivoOTeclado();

void verificarArchivo();
void leerDesdeArchivo(Matriz &m1, unsigned int columnas);
void leerDesdeArchivo(Vector &v1);

void leerVectorDesdeTeclado(Vector &datos);
void desagruparDesdeTeclado();
void desagruparDesdeArchivo();

void setDimensionMatriz();
//void crearMatrizVacia();
void editarMatrizVacia();
