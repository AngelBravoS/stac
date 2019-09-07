cmake_minimum_required(VERSION 2.6)
project(stac)

set(lista_archivos
  #archivo principal
  main.cpp
  #Interfaz de linea de comandos, consiste en
  #el menu inicial y la gestion de los submenus
  cli.cpp
  textosMenus.cpp
  #Funciones matematicas basicas y avanzadas de cada tipo
  #Comunes a todas las clases de variables
  vector.cpp
  matriz.cpp
  funcMatematicasBasicas.cpp
  #Específicas
  calculos1Var.cpp
  calculos2Var.cpp
  calculosIA.cpp
  calculosNVar.cpp
  calculosAlgebra.cpp
  #calculosTablasContBid.cpp
  mas.cpp
  combinatoria.cpp 
  distribucionesDiscretas.cpp
  #Los submenus de cada tipo de operacion
  menu1Var.cpp
  menu2Var.cpp
  menuNVar.cpp
  menuAlgebra.cpp
  menuMuestreo.cpp
  menuSinDatos.cpp
  menuCombinatoria.cpp
  menuDistribDiscretas.cpp
  menuTablasCont.cpp  
  menuIA.cpp
  menuIO.cpp
  modelo.cpp
  mmi.cpp
  mmik.cpp
  mmc.cpp
  mmInfinit.cpp
  mgi.cpp
)

#Debug/Release

set(CMAKE_BUILD_TYPE Debug)

#-march=amdfam10/core2/native

set(CMAKE_CXX_FLAGS "-ansi -pedantic -Wall -W -Wconversion -Wshadow -Wcast-qual -Wwrite-strings -O0 -march=native -std=gnu++14")

set(CMAKE_CXX_FLAGS_DEBUG " -ggdb3 -DDEBUG")

add_executable(stac ${lista_archivos})

#install(TARGETS stac RUNTIME DESTINATION bin)
