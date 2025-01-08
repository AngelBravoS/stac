#include <iostream>
#include "salida.hpp"

void mostrarVector(Vector &v1) {
	std::cout << "( ";
	for (unsigned int i = 0; i < v1.size(); i++) {
		std::cout << v1[i] << " ";
	}
	std::cout << ")" << '\n';
}

void mostrarMatriz(Matriz &m1) {
	std::cout << '\n';
	for (unsigned int i = 0; i < m1.RowCount(); i++) {
		std::cout << "( ";
		for (unsigned int j = 0; j < m1.ColumnCount(); j++) {
			std::cout << m1[i][j] << " ";
		}
		std::cout << ")";
		std::cout << '\n';
	}
}

void imprimirResultado(const std::string &descripcion, double valor) {
	std::cout << descripcion << " = " << valor << std::endl;
}
