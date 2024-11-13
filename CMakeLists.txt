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

# Especificación de C++ estándar
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF) # Para evitar extensiones específicas del compilador
set(CMAKE_CXX_COMPILER "clang++") # Alt "g++" GCC

# Configuración de compilación (Debug/Release)
#set(CMAKE_BUILD_TYPE Debug CACHE STRING "Choose the type of build: Debug or Release")
set(CMAKE_BUILD_TYPE Debug)


# Establecer las banderas de compilación
add_compile_options(
  "$<$<CONFIG:Debug>:-pedantic;-Wall;-Wextra;-Wconversion;-Wshadow;-Wcast-qual;-Wwrite-strings;-O0;-ggdb3;-DDEBUG>"
  "$<$<CONFIG:Release>:-pedantic;-Wall;-O3>"
)

# Configuración del ejecutable
add_executable(stac ${lista_archivos})

# Directorio de salida
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)


# Instalación
install(TARGETS stac RUNTIME DESTINATION bin)
