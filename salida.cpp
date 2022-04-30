#include <iostream>
#include "salida.hpp"

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
