cmake_minimum_required(VERSION 3.6)
project(stac)

# Especificación de C++ estándar
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF) # Para evitar extensiones específicas del compilador
#set(CMAKE_CXX_COMPILER "clang++") # Alt "g++" GCC

# Configuración de compilación (Debug/Release)
#set(CMAKE_BUILD_TYPE Debug CACHE STRING "Choose the type of build: Debug or Release")
set(CMAKE_BUILD_TYPE Debug)

# Establecer las banderas de compilación
add_compile_options(
  "$<$<CONFIG:Debug>:-pedantic;-Wall;-Wextra;-Wconversion;-Wshadow;-Wcast-qual;-Wwrite-strings;-O0;-ggdb3;-DDEBUG>"
  "$<$<CONFIG:Release>:-pedantic;-Wall;-O3>"
)

set(lista_archivos
    src/main.cpp
    src/cli.cpp
    src/entrada.cpp
    src/salida.cpp
    src/textosMenus.cpp
    src/vector.cpp
    src/row.cpp
    src/matriz.cpp
    src/funcMatematicasBasicas.cpp
    src/calculos1Var.cpp
    src/calculos2Var.cpp
    src/calculosNVar.cpp
    src/calculosAlgebra.cpp
    src/combinatoria.cpp
    src/distribucionesDiscretas.cpp
    src/menu1Var.cpp
    src/menu2Var.cpp
    src/menuNVar.cpp
    src/menuAlgebra.cpp
    src/menuInferencia.cpp
    src/menuSinDatos.cpp
    src/menuCombinatoria.cpp
    src/menuDistribDiscretas.cpp
    src/menuSimula.cpp
    src/generadoresCongruenciales.cpp
    src/menuColExpo.cpp
    src/modelo.cpp
    src/mmi.cpp
    src/mmik.cpp
    src/mmc.cpp
    src/mmInfinit.cpp
    src/mgi.cpp
)

# Configuración del ejecutable
add_executable(stac ${lista_archivos})

# Configuración de los encabezados
target_include_directories(stac PRIVATE ${PROJECT_SOURCE_DIR}/include)

# Directorio de salida
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Instalación
install(TARGETS stac RUNTIME DESTINATION bin)
