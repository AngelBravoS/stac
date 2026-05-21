cmake_minimum_required(VERSION 3.12)
project(stac LANGUAGES CXX)

# ========================================
# Configuración del estándar de C++
# ========================================
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# ========================================
# Tipo de compilación (Debug/Release)
# ========================================
# Si no se especifica, por defecto será Debug
#if(NOT CMAKE_BUILD_TYPE)
#    set(CMAKE_BUILD_TYPE Debug CACHE STRING "Choose the type of build: Debug or Release" FORCE)
#endif()
set(CMAKE_BUILD_TYPE Debug)

# Verificación y configuración del compilador
find_program(CLANGPP_EXECUTABLE clang++)
if(CLANGPP_EXECUTABLE)
  set(CMAKE_CXX_COMPILER "${CLANGPP_EXECUTABLE}")
endif()

# ========================================
# Directorio de salida
# ========================================
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# ========================================
# Archivos fuente
# ========================================
set(lista_archivos
    src/main.cpp
    src/cli.cpp
    src/entrada.cpp
    src/salida.cpp
    src/textosMenus.cpp
    src/vector.cpp
    src/matriz.cpp
    src/funcMatematicasBasicas.cpp
    src/calculos1Var.cpp
    src/calculos2Var.cpp
    src/calculosNVar.cpp
    src/calculosAlgebra.cpp
    src/combinatoria.cpp
    src/distribucionesDiscretas.cpp
    src/generadoresCongruenciales.cpp
    src/modeloColas.cpp
    src/mmi.cpp
    src/mmik.cpp
    src/mmc.cpp
    src/mmInfinit.cpp
    src/mgi.cpp
)

# ========================================
# Ejecutable
# ========================================
add_executable(stac ${lista_archivos})

# ========================================
# Opciones de compilación por compilador
# ========================================
message(STATUS "Compilador: ${CMAKE_CXX_COMPILER_ID} ${CMAKE_CXX_COMPILER_VERSION}")

if(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
  target_compile_options(stac PRIVATE
    $<$<CONFIG:Debug>:-Wall -Wextra -Wpedantic -Wconversion -Wshadow -Wcast-qual -g3 -O0 -ggdb3 -DDEBUG>
    $<$<CONFIG:Release>:-Wall -Wpedantic -O3>)
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
  target_compile_options(stac PRIVATE
    $<$<CONFIG:Debug>:-Wall -Wextra -Wpedantic -Wconversion -Wshadow -Wcast-qual -g3 -O0 -ggdb3 -DDEBUG>
    $<$<CONFIG:Release>:-Wall -Wpedantic -O3>)
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
  target_compile_options(stac PRIVATE
    $<$<CONFIG:Debug>:/W4 /permissive- /DDEBUG /Od /Zi /utf-8 /MP>
    $<$<CONFIG:Release>:/W4 /O2 /utf-8 /MP>)
else()
  message(WARNING "Compilador no reconocido: ${CMAKE_CXX_COMPILER_ID}")
endif()

target_include_directories(stac PRIVATE ${PROJECT_SOURCE_DIR}/include)

# ========================================
# Instalación
# ========================================
install(TARGETS stac RUNTIME DESTINATION bin)

# ========================================
# Verificar compilador activo
# ========================================
message(STATUS "CMAKE_CXX_COMPILER: ${CMAKE_CXX_COMPILER}")
message(STATUS "CMAKE_CXX_COMPILER_ID: ${CMAKE_CXX_COMPILER_ID}")
message(STATUS "CMAKE_CXX_COMPILER_VERSION: ${CMAKE_CXX_COMPILER_VERSION}")

# ========================================
# Tests (Test)
# ========================================
enable_testing()

add_test(
    NAME CompiladorCorrecto
    COMMAND ${CMAKE_COMMAND} -E echo "Compilador: ${CMAKE_CXX_COMPILER_ID}, Versión: ${CMAKE_CXX_COMPILER_VERSION}"
)
