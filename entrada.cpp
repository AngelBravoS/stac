#include "entrada.hpp"

void leerMatriz(bool archivo) {
}

void verificarArchivo() {
    std::fstream archivo;
    archivo.open("datos.dat", std::ios::in | std::ios::binary);
    if (archivo.is_open()) {
        std::cout << "Fichero leído" << '\n';
    }
    else {
        std::cout << "Fichero inexistente" << '\n';
        exit(-1);
    }
    archivo.close();
}

void leerDesdeArchivo(Matriz &m1, unsigned int columnas) {
    std::fstream archivo;
    archivo.open("datos.dat", std::ios::in | std::ios::binary);
    unsigned int n = columnas;
    unsigned int i = 0, j = 0;
    while (!archivo.eof()) {
        archivo >> m1[i][j];
        j++; //avanza en la fila
        i += j / n; //si pasó de N, le suma a 1 a i (siguiente columna)
        j = j % n; //se asegura que esté entre 0 y N-1
    }
    archivo.close();
}

unsigned int numeroFilas() {
    unsigned int filas;
    std::cout << "Número de filas: ";
    std::cin >> filas;
    return filas;
}
unsigned int numeroColumnas() {
    unsigned int columnas;
    std::cout << "Número de columnas: ";
    std::cin >> columnas;
    return columnas;
}

Matriz editarMatrizVacia(Matriz &m1) {
    for (unsigned int i = 0; i < m1.RowCount(); i++) {
        for (unsigned int j = 0; j < m1.ColumnCount(); j++) {
            std::cin >> m1[i][j];
        }
    }
    std::cout << '\n';
    return m1;
}

bool preguntarDesdeArchivoOTeclado() {
	char opcion;
	bool eligesArchivo;
	std::cout << "¿Leer desde un archivo? s/n: ";
	std::cin >> opcion;
	opcion == 's' ? eligesArchivo = true : eligesArchivo = false;
	return eligesArchivo;
}
