cmake_minimum_required(VERSION 3.6)
project(stac)

# Especificación de C++ estándar
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF) # Para evitar extensiones específicas del compilador
#set(CMAKE_CXX_COMPILER "clang++") # Alt "g++" GCC
#set(CMAKE_CXX_COMPILER_ID "Clang")

# Verificación y configuración del compilador
find_program(CLANGPP_EXECUTABLE clang++)
if(CLANGPP_EXECUTABLE)
  set(CMAKE_CXX_COMPILER "${CLANGPP_EXECUTABLE}")
endif()

# Configuración de compilación (Debug/Release)
#set(CMAKE_BUILD_TYPE Debug CACHE STRING "Choose the type of build: Debug or Release")
set(CMAKE_BUILD_TYPE Debug)

# Configuración específica del compilador
if (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    message(STATUS "Configurando para compilador Clang")
    add_compile_options(
        "$<$<CONFIG:Debug>:-Wpedantic;-Wall;-Wextra;-Wconversion;-Wshadow;-Wcast-qual;-Wwrite-strings;-g3;-O0;-ggdb3;-DDEBUG>"
        "$<$<CONFIG:Release>:-Wpedantic;-Wall;-O3>"
    )
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    message(STATUS "Configurando para compilador GCC")
    add_compile_options(
        "$<$<CONFIG:Debug>:-Wpedantic;-Wall;-Wextra;-Wconversion;-Wshadow;-Wcast-qual;-Wwrite-strings;-O0;-ggdb3;-DDEBUG>"
        "$<$<CONFIG:Release>:-Wpedantic;-Wall;-O3>"
    )
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    message(STATUS "Configurando para compilador Microsoft Visual C++")
    add_compile_options(
        "$<$<CONFIG:Debug>:/MDd;/RTC1;/permissive;/W3;/Wall;/DDEBUG;/Od;/Ob0;/Zi;/utf-8;/MP;/wd4820;/wd5045;/wd4668>"
        "$<$<CONFIG:Release>:/O2;/W3>"
   )
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "Intel")
    message(STATUS "Configurando para Intel Compiler")
    if (MSVC)
        message(STATUS "Intel Compiler en modo MSVC")
    else()
        message(STATUS "Intel Compiler en modo GCC/Clang")
    endif()
    add_compile_options(
        "$<$<CONFIG:Debug>:-Wpedantic;-Wall;-Wextra;-Wconversion;-Wshadow;-Wcast-qual;-Wwrite-strings;-DDEBUG;-g;-O0>"
        "$<$<CONFIG:Release>:-Wpedantic;-Wall;-O3>"
    )
else()
    message(WARNING "Compilador no soportado (${CMAKE_CXX_COMPILER_ID}). No se aplican banderas específicas.")
endif()

# Verificar compilador activo

message(STATUS "CMAKE_CXX_COMPILER: ${CMAKE_CXX_COMPILER}")
message(STATUS "CMAKE_CXX_COMPILER_ID: ${CMAKE_CXX_COMPILER_ID}")
message(STATUS "CMAKE_CXX_COMPILER_VERSION: ${CMAKE_CXX_COMPILER_VERSION}")

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
    src/menuNVar.cpp
    src/menuInferencia.cpp
    src/menuSinDatos.cpp
    src/menuCombinatoria.cpp
    src/menuDistribDiscretas.cpp
    src/menuSimula.cpp
    src/generadoresCongruenciales.cpp
    src/menuColExpo.cpp
    src/modeloColas.cpp
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

# Pruebas automáticas para verificar la configuración
enable_testing()

add_test(
    NAME CompiladorCorrecto
    COMMAND ${CMAKE_COMMAND} -E echo "Compilador: ${CMAKE_CXX_COMPILER_ID}, Versión: ${CMAKE_CXX_COMPILER_VERSION}"
)
