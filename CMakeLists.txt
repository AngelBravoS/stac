cmake_minimum_required(VERSION 2.6)
project(stac)

set(lista_archivos
  #archivo principal
  main.cpp
  #Interfaz de linea de comandos, consiste en
  #el menu inicial y la gestion de los submenus
  cli.cpp
  textosMenuPrincipal.cpp
  entradaYSalida1Var.cpp
  entradaYSalida2Var.cpp
  #entradaYSalidaNVar.cpp
  entradaYSalidaMatriz.cpp
  #Funciones matematicas basicas y avanzadas de cada tipo
  funcMate.cpp
  combinatoria.cpp
  calculos1Var.cpp
  calculos2Var.cpp
  calculosMatriz.cpp
  inteligenciArtificial.cpp
  distribucionesDiscretas.cpp
  #Los submenus de cada tipo de operacion
  menu1Var.cpp
  menu2Var.cpp
  menuNVar.cpp
  menuMatrices.cpp
  menuSinDatos.cpp
  menuCombinatoria.cpp 
  menuInteligenciArtificial.cpp
  menuDistribDiscretas.cpp
)

#-march=amdfam10/core2/native

set(CMAKE_CXX_FLAGS "\
-ansi -pedantic -Wall -W -Wconversion -Wshadow -Wcast-qual \
-Wwrite-strings -O2 -g -march=native -std=gnu++14")

set(CMAKE_CXX_FLAGS_DEBUG " -O0 -ggdb3 -DDEBUG")

add_executable(stac ${lista_archivos})
