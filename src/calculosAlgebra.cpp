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
  if (m1.RowCount() != m2.RowCount()) {
    std::cout << "Tamaño de filas incorrecto" << "\n";
    exit(-1);
  }

  if (m1.ColumnCount() != m2.ColumnCount()) {
    std::cout << "Tamaño de columnas incorrecto" << "\n";
    exit(-1);
  }

  Matriz m(m1.RowCount(), m1.ColumnCount());

  for (unsigned int f = 0; f < m1.RowCount(); ++f) {
    for (unsigned int c = 0; c < m1.ColumnCount(); ++c) {
      m[f][c] = m1[f][c] + m2[f][c];
    }
  }

  return m;
}

Matriz scalar_multiplication(Matriz &m1, double scalar) {
  Matriz m(m1.RowCount(), m1.ColumnCount());

  for (unsigned int f = 0; f < m1.RowCount(); ++f) {
    for (unsigned int c = 0; c < m1.ColumnCount(); ++c) {
      m[f][c] = m1[f][c] * scalar;
    }
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
  if (m1.RowCount() != m2.ColumnCount()) {
    std::cout << "Tamaño de filas/columnas incorrecto" << "\n";
    exit(-1);
  }

  Matriz m(m1.RowCount(), m2.ColumnCount());

  for (unsigned int f = 0; f < m1.RowCount(); ++f) {
    for (unsigned int c = 0; c < m1.ColumnCount(); ++c) {
      m[f][c] = 0;

      for (unsigned int i = 0; i < m1.RowCount(); ++i) {
        m[f][c] += m1[f][i] * m2[i][c];
      }
    }
  }

  return m;
}

Matriz kronecker(Matriz &m1, Matriz &m2) {
  if (m1.RowCount() != m2.RowCount()) {
    std::cout << "Tamaño de filas incorrecto" << "\n";
    exit(-1);
  }

  if (m1.ColumnCount() != m2.ColumnCount()) {
    std::cout << "Tamaño de columnas incorrecto" << "\n";
    exit(-1);
  }

  Matriz m(m1.RowCount(), m1.ColumnCount());

  for (unsigned int f = 0; f < m1.RowCount(); ++f) {
    for (unsigned int c = 0; c < m1.ColumnCount(); ++c) {
      m[f][c] = m1[f][c] * m2[f][c];
    }
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

  for (unsigned int r = 0; r < rows; ++r) {
    for (unsigned int c = 0; c < cols; ++c) {
      m[c][c] = 1;
    }
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

Matriz menor(Matriz &m1, unsigned int fila, unsigned int columna) {
  unsigned int size = m1.RowCount();
  Matriz menor(size - 1, size - 1);

  unsigned int rowOffset = 0;
  for (unsigned int i = 0; i < size; i++) {
    if (i == fila) {
      rowOffset = 1;
      continue;
    }
    unsigned int colOffset = 0;
    for (unsigned int j = 0; j < size; j++) {
      if (j == columna) {
        colOffset = 1;
        continue;
      }
      menor[i - rowOffset][j - colOffset] = m1[i][j];
    }
  }

  return menor;
}

double determinante(Matriz &m1) {

  if (m1.cuadrada == false) {
    std::cout << "La matriz no es cuadrada. " << '\n';
    return 0;
  } else {
    unsigned int size = m1.RowCount();
    double resultado = 0;

    switch (size) {
    case 1:
      resultado = m1[0][0];
      break;

    case 2: // caso base para la recursividad
      resultado = m1[0][0] * m1[1][1] - m1[0][1] * m1[1][0];
      break;

    case 3: // por sarrus
      resultado =
          (m1[0][0] * m1[1][1] * m1[2][2] + m1[0][2] * m1[1][0] * m1[2][1] +
           m1[0][1] * m1[1][2] * m1[2][0]) -
          (m1[0][2] * m1[1][1] * m1[2][0] + m1[0][1] * m1[1][0] * m1[2][2] +
           m1[0][0] * m1[1][2] * m1[2][1]);
      break;

    default:
      for (unsigned int j = 0; j < size; j++) {
        Matriz menoradj =
            menor(m1, 0, j); // Eliminamos la fila 0 y la columna j
        int signo = (j % 2 == 0) ? 1 : -1; // Alternancia de signos
        resultado += signo * m1[0][j] * determinante(menoradj);
      }
      break;
    }

    return resultado;
  }
}

Matriz traspuesta(Matriz &m1) {
  unsigned int fila = m1.RowCount();
  unsigned int columna = m1.ColumnCount();
  Matriz m(columna, fila);

  for (unsigned int c = 0; c < fila; ++c) {
    for (unsigned int f = 0; f < columna; ++f) {
      m[f][c] = m1[c][f];
    }
  }

  return m;
}

Matriz adjunta(Matriz &m1) {
  Matriz m(m1.RowCount(), m1.ColumnCount());
  unsigned int size = m1.RowCount();
  // unsigned int n = size;

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
    m[0][0] = (m1[1][1] * m1[2][2]) - (m1[1][2] * m1[2][1]);
    m[0][1] = (m1[1][2] * m1[2][0]) - (m1[1][0] * m1[2][2]);
    m[0][2] = (m1[1][0] * m1[2][1]) - (m1[1][1] * m1[2][0]);
    m[1][0] = (m1[2][1] * m1[0][2]) - (m1[2][2] * m1[0][1]);
    m[1][1] = (m1[2][2] * m1[0][0]) - (m1[2][0] * m1[0][2]);
    m[1][2] = (m1[2][0] * m1[0][1]) - (m1[2][1] * m1[0][0]);
    m[2][0] = (m1[0][1] * m1[1][2]) - (m1[0][2] * m1[1][1]);
    m[2][1] = (m1[0][2] * m1[1][0]) - (m1[0][0] * m1[1][2]);
    m[2][2] = (m1[0][0] * m1[1][1]) - (m1[0][1] * m1[1][0]);
    break;
  // Para matrices de mayor tamaño
  default:
    for (unsigned int i = 0; i < size; i++) {
      for (unsigned int j = 0; j < size; j++) {
        // Obtenemos el menor de la submatriz excluyendo la fila i y columna j
        Matriz menoradj = menor(m1, i, j);

        // Calculamos el signo del cofactor: (-1)^(i+j)
        int signo = ((i + j) % 2 == 0) ? 1 : -1;

        // Calculamos el cofactor como el determinante del menor, ajustado por
        // el signo
        m[i][j] = signo * determinante(menoradj);
      }
    }

    // La adjunta es la transpuesta de la matriz de cofactores
    m = traspuesta(m);
    break;
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
      m[0][0] = frac * ((m1[1][1] * m1[2][2]) - (m1[1][2] * m1[2][1]));
      m[1][0] = frac * ((m1[1][2] * m1[2][0]) - (m1[1][0] * m1[2][2]));
      m[2][0] = frac * ((m1[1][0] * m1[2][1]) - (m1[1][1] * m1[2][0]));
      m[0][1] = frac * ((m1[2][1] * m1[0][2]) - (m1[2][2] * m1[0][1]));
      m[1][1] = frac * ((m1[2][2] * m1[0][0]) - (m1[2][0] * m1[0][2]));
      m[2][1] = frac * ((m1[2][0] * m1[0][1]) - (m1[2][1] * m1[0][0]));
      m[0][2] = frac * ((m1[0][1] * m1[1][2]) - (m1[0][2] * m1[1][1]));
      m[1][2] = frac * ((m1[0][2] * m1[1][0]) - (m1[0][0] * m1[1][2]));
      m[2][2] = frac * ((m1[0][0] * m1[1][1]) - (m1[0][1] * m1[1][0]));
      break;

    default:
      m = adjunta(m1);
      // m=traspuesta(m);
      m = frac * m;
      break;
    }
  }

  return m;
}

Matriz gauss(Matriz &m1) {
  Matriz Gauss(m1.RowCount(), m1.ColumnCount());
  Gauss = m1;

  unsigned int m = m1.RowCount();
  unsigned int i, j, k;
  double temp;

  /*if (m != m + 1) {
    throw std::invalid_argument("Error: La matriz no es compatible.");
  }*/

  for (j = 0; j < m; j++) {
    for (i = j + 1; i < m; i++) {
      //temp = Gauss[i][j] / Gauss[j][j];
      // Falla cuando el pivote superior es 0, probar con matriz
      //1 2 3 4
      //0 1 2 4
      //2 3 4 5
      //2 0 1 2
      //¿intercambiar valores i por j? prueba pendiente
      temp = Gauss[j][j]==0 ? 1 : Gauss[i][j] / Gauss[j][j];
      for (k = 0; k < m + 1; k++) {
        Gauss[i][k] = Gauss[i][k] - temp * Gauss[j][k];
      }
    }
  }

  return Gauss;
}

Vector gaussJordan(Matriz &m1) {
  Matriz matrizGaussJordan = gauss(m1);
  double s;
  unsigned int i, j;
  unsigned int m = matrizGaussJordan.RowCount();
  Vector soluciones(m);

  for (i = m - 1; i > 0; i--) {
    s = 0;
    for (j = i + 1; j < m; j++) {
      s += matrizGaussJordan[i][j] * soluciones[j];
    }
    soluciones[i] = (matrizGaussJordan[i][m] - s) / matrizGaussJordan[i][i];
  }
  return soluciones;
}

Matriz descomposicionLU(Matriz &m1, char LoU) {
  Matriz L(m1.RowCount(), m1.ColumnCount());
  Matriz U(m1.RowCount(), m1.ColumnCount());
  unsigned int n = m1.RowCount();

  for (unsigned int i = 0; i < n; i++) {
    for (unsigned int j = 0; j < n; j++) {
      double sum = 0;

      if (i <= j) {
        for (unsigned int k = 0; k < n; k++)
          if (k != i) {
            sum = sum + L[i][k] * U[k][j];
          }

        U[i][j] = m1[i][j] - sum;
      } else {
        for (unsigned int k = 0; k < n; k++)
          if (k != j) {
            sum = sum + L[i][k] * U[k][j];
          }

        L[i][j] = (m1[i][j] - sum) / U[j][j];
      }
    }
  }

  for (unsigned int i = 0; i < n; i++) {
    L[i][i] = 1;
  }

  if (LoU == 'L') {
    return L;
  } else {
    return U;
  }
}

Matriz descomposicionCholesky(Matriz &m1) {
  if (!m1.cuadrada) {
    std::cout << "La matriz no es cuadrada." << '\n';
    exit(-1);
  }

  unsigned int n = m1.RowCount();
  Matriz cholesky(n, n);

  for (unsigned int i = 0; i < n; ++i) {
    for (unsigned int j = 0; j <= i; ++j) {
      double sum = 0;

      if (j == i) { // Diagonal elements
        for (unsigned int k = 0; k < j; ++k) {
          sum += cholesky[j][k] * cholesky[j][k];
        }
        cholesky[j][j] = sqrt(m1[j][j] - sum);
      } else {
        for (unsigned int k = 0; k < j; ++k) {
          sum += cholesky[i][k] * cholesky[j][k];
        }
        cholesky[i][j] = (m1[i][j] - sum) / cholesky[j][j];
      }
    }
  }

  return cholesky;
}
