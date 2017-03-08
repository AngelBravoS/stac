cmake_minimum_required(VERSION 2.6)
project(stac)

set(lista_archivos
  #archivo principal
  main.cpp
  #Interfaz de linea de comandos, consiste en
  #el menu inicial y la gestion de los submenus
  cli.cpp
  textosMenuPrincipal.cpp
  entradaYSalidaMatriz.cpp
  #Funciones matematicas basicas y avanzadas de cada tipo
  funcMate.cpp
  combinatoria.cpp
  matriz.cpp
  inteligenciArtificial.cpp
  distribucionesDiscretas.cpp
  #Los submenus de cada tipo de operacion
  menUnaVariable.cpp
  menuDosVariables.cpp
  menuNVariables.cpp
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
