cmake_minimum_required(VERSION 3.6)
project(stac)

set(lista_archivos
  #archivo principal
  main.cpp
  #Interfaz de linea de comandos, consiste en
  #el menu inicial y la gestion de los submenus
  cli.cpp
  entrada.cpp
  salida.cpp
  textosMenus.cpp
  #Funciones matematicas basicas y avanzadas de cada tipo
  #Comunes a todas las clases de variables
  vector.cpp
  row.cpp
  matriz.cpp
  funcMatematicasBasicas.cpp
  #Específicas
  calculos1Var.cpp
  calculos2Var.cpp
  calculosNVar.cpp
  calculosAlgebra.cpp
  #calculosTablasContBid.cpp
  #mas.cpp
  combinatoria.cpp 
  distribucionesDiscretas.cpp
  #Los submenus de cada tipo de operacion
  menu1Var.cpp
  menu2Var.cpp
  menuNVar.cpp
  menuAlgebra.cpp
  menuInferencia.cpp
  menuSinDatos.cpp
  menuCombinatoria.cpp
  menuDistribDiscretas.cpp
  menuSimula.cpp
  #menuTablasCont.cpp  
  generadoresCongruenciales.cpp
  menuColExpo.cpp
  modelo.cpp
  mmi.cpp
  mmik.cpp
  mmc.cpp
  mmInfinit.cpp
  mgi.cpp
)

#Debug/Release

set(CMAKE_BUILD_TYPE Debug)

#set(CMAKE_CXX_FLAGS_DEBUG "-ansi -pedantic -Wall -W -Wconversion -O0 -ggdb -std=gnu++11")
#set(CMAKE_CXX_FLAGS_RELEASE "-ansi -pedantic -Wall -O3 -std=gnu++11")

# Clang++ especificado en la configuración del IDE
set(CMAKE_CXX_COMPILER "clang++")
#SET (CMAKE_AR      "/usr/bin/llvm-ar")
#SET (CMAKE_LINKER  "/usr/bin/llvm-ld")
#SET (CMAKE_NM      "/usr/bin/llvm-nm")
#SET (CMAKE_OBJDUMP "/usr/bin/llvm-objdump")
#SET (CMAKE_RANLIB  "/usr/bin/llvm-ranlib")
#SET (CMAKE_CXX_FLAGS_DEBUG "-g -Wall -Wextra -Wnon-gcc -std=gnu++17 -O2")

add_executable(stac ${lista_archivos})

#install(TARGETS stac RUNTIME DESTINATION /bin)
