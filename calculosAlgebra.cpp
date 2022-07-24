/***************************************************************************
 *   Copyright (C) 2018 by Ángel Bravo Sáenz                               *
 *   angelbravosaenz@gmail.com                                             *
 *                                                                         *
 *   This file is part of Stac.                                            *
 *                                                                         *
 *   Stac is free software; you can redistribute it and/or modify          *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; version 2 of the License.               *
 *                                                                         *
 *   Stac is distributed in the hope that it will be useful,               *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with Stac; if not, write to the                                 *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#include "calculosAlgebra.hpp"

Matriz operator+(Matriz &m1, Matriz &m2) {
	// Here, we need to check that the rows and
	// columns of the two are the same.
	if (m1.RowCount() != m2.RowCount()) {
		std::cout << "Tamaño de filas incorrecto" << "\n";
		exit(-1);
	}
	if (m1.ColumnCount() != m2.ColumnCount()) {
		std::cout << "Tamaño de columnas incorrecto" << "\n";
		exit(-1);
	}

	Matriz m(m1.RowCount(), m1.ColumnCount());

	for (unsigned int r = 0; r < m1.RowCount(); ++ r) {
		for (unsigned int c = 0; c < m1.ColumnCount(); ++c)
			m[r][c] = m1[r][c] + m2[r][c];
	}

	return m;
}

Matriz scalar_multiplication(Matriz &m1, double scalar) {
	Matriz m(m1.RowCount(), m1.ColumnCount());
	for (unsigned int r = 0; r < m1.RowCount(); ++ r) {
		for (unsigned int c = 0; c < m1.ColumnCount(); ++c)
			m[r][c] = m1[r][c] * scalar;
	}

	return m;
}

Matriz operator*(Matriz &m1, double scalar) {
	return scalar_multiplication(m1, scalar);
}

Matriz operator*(double scalar, Matriz &m1) {
	return scalar_multiplication(m1, scalar);
}

Matriz operator*(Matriz &m1, Matriz &m2) {
	if (m1.RowCount() != m2.ColumnCount())
		throw "Adding Matrices: Invalid Rows";

	Matriz m(m1.RowCount(), m2.ColumnCount());

	for (unsigned int r = 0; r < m1.RowCount(); ++ r) {
		for (unsigned int c = 0; c < m1.ColumnCount(); ++c)
			m[r][c] = m1[r][c] + m2[r][c];
	}
	return m;
}

Vector vectorDiagonal(Matriz &m1) {
	unsigned int n = m1.RowCount();
	Vector resultado(n);
	for (unsigned int i = 0; i < n; i++) {
		for (unsigned int j = 0; j < n; j++) {
			resultado[i] = m1[i][i];
		}
	}
	return resultado;
}

Matriz identidad(unsigned int rows, unsigned int cols) {
	Matriz m(rows, cols);
	for (unsigned int r = 0; r < rows; ++ r) {
		for (unsigned int c = 0; c < cols; ++c)
			m[c][c] = 1;
	}
	return m;
}

double traza(Matriz &m1) {
	unsigned int n = m1.RowCount();
	double traza = 0;
	for (unsigned int i = 0; i < n; i++) {
		traza += m1[i][i];
	}
	return traza;
}

double determinante(Matriz &m1) {
	if (m1.cuadrada == false) {
		std::cout << "La matriz no es cuadrada. " << '\n';
		return 0;
	} else {
		unsigned int size = m1.RowCount();
		double determinante = 0;
		switch (size) {
			case 1:
				determinante = m1[0][0];
				break;
			case 2://caso base para la recursividad
				determinante = m1[0][0] * m1[1][1] - m1[0][1] *
				               m1[1][0];
				break;
			case 3://por sarrus
				determinante = (m1[0][0] * m1[1][1] * m1[2][2] +
				                m1[0][2] * m1[1][0] * m1[2][1] +
				                m1[0][1] * m1[1][2] * m1[2][0]) -
				               (m1[0][2] * m1[1][1] * m1[2][0] +
				                m1[0][1] * m1[1][0] * m1[2][2] +
				                m1[0][0] * m1[1][2] * m1[2][1]);
				break;
			default :
				Vector resultadoVec;
				Matriz resultadoMat;
				resultadoMat = descomposicionLU(m1, false);
				resultadoVec = vectorDiagonal(resultadoMat);
				determinante = 1;
				for (unsigned int i = 0; i < size; i++) {
					determinante *= resultadoVec[i];
				}
				break;
		}
		return determinante;
	}
}

Matriz traspuesta(Matriz &m1) {
	Matriz m(m1.RowCount(), m1.ColumnCount());
	for (unsigned int r = 0; r < m1.RowCount(); ++ r) {
		for (unsigned int c = 0; c < m1.ColumnCount(); ++c)
			m[r][c] = m1[c][r];
	}
	return m;
}

Matriz adjunta(Matriz &m1) {
	Matriz m(m1.RowCount(), m1.ColumnCount());
	unsigned int size = m1.RowCount();
	switch (size) {
		case 1:
			m[0][0] = m1[0][0];
			break;
		case 2:
			m[0][0] = m1[1][1];
			m[0][1] = -m1[0][1];
			m[1][0] = -m1[1][0];
			m[1][1] = m1[0][0];
			break;
		case 3:
			m[0][0] = (m1[1][1] * m1[2][2]) - (m1[1][2] *
			                                   m1[2][1]);
			m[0][1] = (m1[1][2] * m1[2][0]) - (m1[1][0] *
			                                   m1[2][2]);
			m[0][2] = (m1[1][0] * m1[2][1]) - (m1[1][1] *
			                                   m1[2][0]);
			m[1][0] = (m1[2][1] * m1[0][2]) - (m1[2][2] *
			                                   m1[0][1]);
			m[1][1] = (m1[2][2] * m1[0][0]) - (m1[2][0] *
			                                   m1[0][2]);
			m[1][2] = (m1[2][0] * m1[0][1]) - (m1[2][1] *
			                                   m1[0][0]);
			m[2][0] = (m1[0][1] * m1[1][2]) - (m1[0][2] *
			                                   m1[1][1]);
			m[2][1] = (m1[0][2] * m1[1][0]) - (m1[0][0] *
			                                   m1[1][2]);
			m[2][2] = (m1[0][0] * m1[1][1]) - (m1[0][1] *
			                                   m1[1][0]);
			break;
		default:
			std::cout << "aún no disponible" << '\n';
			exit(-1);
	}
	return m;
}

Matriz inversa(Matriz &m1) {
	Matriz m(m1.RowCount(), m1.ColumnCount());
	double det = determinante(m1);
	unsigned int size = m1.RowCount();
	double frac = 1 / det;
	if (det != 0) {
		switch (size) {
			case 1:
				m[0][0] = m1[0][0];
				break;
			case 2:
				m[0][0] = frac * m1[1][1];
				m[0][1] = frac * (-m1[0][1]);
				m[1][0] = frac * (-m1[1][0]);
				m[1][1] = frac * m1[0][0];
				break;
			case 3:
				m[0][0] = frac * ((m1[1][1] * m1[2][2]) -
				                  (m1[1][2]
				                   * m1[2][1]));
				m[1][0] = frac * ((m1[1][2] * m1[2][0]) -
				                  (m1[1][0]
				                   * m1[2][2]));
				m[2][0] = frac * ((m1[1][0] * m1[2][1]) -
				                  (m1[1][1]
				                   * m1[2][0]));
				m[0][1] = frac * ((m1[2][1] * m1[0][2]) -
				                  (m1[2][2]
				                   * m1[0][1]));
				m[1][1] = frac * ((m1[2][2] * m1[0][0]) -
				                  (m1[2][0]
				                   * m1[0][2]));
				m[2][1] = frac * ((m1[2][0] * m1[0][1]) -
				                  (m1[2][1]
				                   * m1[0][0]));
				m[0][2] = frac * ((m1[0][1] * m1[1][2]) -
				                  (m1[0][2]
				                   * m1[1][1]));
				m[1][2] = frac * ((m1[0][2] * m1[1][0]) -
				                  (m1[0][0]
				                   * m1[1][2]));
				m[2][2] = frac * ((m1[0][0] * m1[1][1]) -
				                  (m1[0][1]
				                   * m1[1][0]));
				break;
			default:
				std::cout << "aún no disponible" << '\n';
				exit(-1);
		}
		return m;
	} else {
		std::cout << "La matriz no tiene inversa" << '\n';
	}
}

Matriz gauss(Matriz &m1) {
	Matriz matrizResultado(m1.RowCount(), m1.ColumnCount());
	unsigned int m = m1.RowCount();
	unsigned int n = m1.ColumnCount();
	double temp;

	for (unsigned int j = 0; j < m - 1; j++) {
		for (unsigned int i = j + 1; i < m; i++) {
			temp = m1[i][j] / m1[j][j];
			for (unsigned int k = 0; k < n; k++)
				m1[i][k] -= m1[j][k] * temp;
		}
	}
	return m1;
}

Matriz gaussJordan(Matriz &m1) {
	Matriz m(m1.RowCount(), m1.ColumnCount());
	double b;
	unsigned int k;
	unsigned int n = m1.RowCount();
	for (unsigned int j = 1; j <= n; j++) {
		for (unsigned int i = 1; i <= n; i++) {
			if (i != j) {
				b = m1[i][j] / m1[j][j];
				for (k = 1; k <= n + 1; k++) {
					m[i][k] = m1[i][k] - b * m1[j][k];
				}
			}
		}
	}
	return m;
}

Matriz descomposicionLU(Matriz &m1, bool devolverL) {
	Matriz L(m1.RowCount(), m1.ColumnCount());
	Matriz U(m1.RowCount(), m1.ColumnCount());
	unsigned int n = m1.RowCount();
	for (unsigned int i = 0; i < n; i++) {
		for (unsigned int j = 0; j < n; j++) {
			double sum = 0;
			if (i <= j) {
				for (unsigned int k = 0; k < n; k++)
					if (k != i)
						sum = sum + L[i][k] * U[k][j];
				U[i][j] = m1[i][j] - sum;
			} else {
				for (unsigned int k = 0; k < n; k++)
					if (k != j)
						sum = sum + L[i][k] * U[k][j];
				L[i][j] = (m1[i][j] - sum) / U[j][j];
			}
		}
	}
	for (unsigned int i = 0; i < n; i++) {
		for (unsigned int j = 0; j < n; j++) {
			L[i][i] = 1;
		}
	}
	if (devolverL == true) {
		return L;
	} else {
		return U;
	}
}

Matriz Kronecker() {
}


