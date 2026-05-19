/***************************************************************************
 *   Copyright (C) 2018 by Ángel Bravo Sáenz                               *
 *   angelbravosaenz@gmail.com                                             *
 *                                                                         *
 *   This file is part of Stac.                                            *
 *                                                                         *
 *   Stac is free software; you can redistribute it and/or modify          *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; version 2 of the License.               *
 ***************************************************************************/

#include "calculosAlgebra.hpp"
#include <cmath>
#include <stdexcept>

Matriz operator+(Matriz &m1, Matriz &m2) {
  if (m1.RowCount() != m2.RowCount() || m1.ColumnCount() != m2.ColumnCount())
    throw std::invalid_argument(
        "Las matrices no tienen las mismas dimensiones");

  Matriz m(m1.RowCount(), m1.ColumnCount());
  for (unsigned int f = 0; f < m1.RowCount(); ++f)
    for (unsigned int c = 0; c < m1.ColumnCount(); ++c)
      m[f][c] = m1[f][c] + m2[f][c];
  return m;
}

Matriz scalar_multiplication(Matriz &m1, double scalar) {
  Matriz m(m1.RowCount(), m1.ColumnCount());
  for (unsigned int f = 0; f < m1.RowCount(); ++f)
    for (unsigned int c = 0; c < m1.ColumnCount(); ++c)
      m[f][c] = m1[f][c] * scalar;
  return m;
}

Matriz operator*(Matriz &m1, double scalar) {
  return scalar_multiplication(m1, scalar);
}

Matriz operator*(double scalar, Matriz &m1) {
  return scalar_multiplication(m1, scalar);
}

Matriz operator*(Matriz &m1, Matriz &m2) {
  if (m1.ColumnCount() != m2.RowCount())
    throw std::invalid_argument(
        "Dimensiones incompatibles para multiplicación de matrices");

  Matriz m(m1.RowCount(), m2.ColumnCount());
  for (unsigned int f = 0; f < m1.RowCount(); ++f)
    for (unsigned int c = 0; c < m2.ColumnCount(); ++c) {
      m[f][c] = 0;
      for (unsigned int i = 0; i < m1.ColumnCount(); ++i)
        m[f][c] += m1[f][i] * m2[i][c];
    }
  return m;
}

Matriz kronecker(Matriz &m1, Matriz &m2) {
  if (m1.RowCount() != m2.RowCount() || m1.ColumnCount() != m2.ColumnCount())
    throw std::invalid_argument(
        "Las matrices no tienen las mismas dimensiones");

  Matriz m(m1.RowCount(), m1.ColumnCount());
  for (unsigned int f = 0; f < m1.RowCount(); ++f)
    for (unsigned int c = 0; c < m1.ColumnCount(); ++c)
      m[f][c] = m1[f][c] * m2[f][c];
  return m;
}

Vector vectorDiagonal(Matriz &m1) {
  unsigned int n = m1.RowCount();
  Vector resultado(n);
  for (unsigned int i = 0; i < n; i++)
    resultado[i] = m1[i][i];
  return resultado;
}

Matriz identidad(unsigned int rows, unsigned int cols) {
  Matriz m(rows, cols);
  for (unsigned int i = 0; i < std::min(rows, cols); ++i)
    m[i][i] = 1;
  return m;
}

double traza(Matriz &m1) {
  unsigned int n = m1.RowCount();
  double resultado = 0;
  for (unsigned int i = 0; i < n; i++)
    resultado += m1[i][i];
  return resultado;
}

Matriz menor(Matriz &m1, unsigned int fila, unsigned int columna) {
  unsigned int size = m1.RowCount();
  Matriz m(size - 1, size - 1);
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
      m[i - rowOffset][j - colOffset] = m1[i][j];
    }
  }
  return m;
}

double determinante(Matriz &m1) {
  if (!m1.cuadrada)
    throw std::invalid_argument(
        "El determinante solo está definido para matrices cuadradas");

  unsigned int size = m1.RowCount();
  switch (size) {
  case 1:
    return m1[0][0];
  case 2:
    return m1[0][0] * m1[1][1] - m1[0][1] * m1[1][0];
  case 3:
    return (m1[0][0] * m1[1][1] * m1[2][2] + m1[0][2] * m1[1][0] * m1[2][1] +
            m1[0][1] * m1[1][2] * m1[2][0]) -
           (m1[0][2] * m1[1][1] * m1[2][0] + m1[0][1] * m1[1][0] * m1[2][2] +
            m1[0][0] * m1[1][2] * m1[2][1]);
  default:
    double resultado = 0;
    for (unsigned int j = 0; j < size; j++) {
      Matriz sub = menor(m1, 0, j);
      int signo = (j % 2 == 0) ? 1 : -1;
      resultado += signo * m1[0][j] * determinante(sub);
    }
    return resultado;
  }
}

Matriz traspuesta(Matriz &m1) {
  unsigned int filas = m1.RowCount();
  unsigned int columnas = m1.ColumnCount();
  Matriz m(columnas, filas);
  for (unsigned int c = 0; c < filas; ++c)
    for (unsigned int f = 0; f < columnas; ++f)
      m[f][c] = m1[c][f];
  return m;
}

Matriz adjunta(Matriz &m1) {
  unsigned int size = m1.RowCount();
  Matriz m(size, size);
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
  default:
    for (unsigned int i = 0; i < size; i++)
      for (unsigned int j = 0; j < size; j++) {
        Matriz sub = menor(m1, i, j);
        int signo = ((i + j) % 2 == 0) ? 1 : -1;
        m[i][j] = signo * determinante(sub);
      }
    m = traspuesta(m);
    break;
  }
  return m;
}

Matriz inversa(Matriz &m1) {
  double det = determinante(m1);
  if (det == 0)
    throw std::invalid_argument(
        "La matriz no es invertible (determinante = 0)");

  unsigned int size = m1.RowCount();
  double frac = 1.0 / det;
  Matriz m(size, size);

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
    m = frac * m;
    break;
  }
  return m;
}

Matriz gauss(Matriz &m1) {
  Matriz g = m1;
  unsigned int filas = g.RowCount();

  for (unsigned int j = 0; j < filas; j++)
    for (unsigned int i = j + 1; i < filas; i++) {
      double temp = (g[j][j] == 0) ? 1 : g[i][j] / g[j][j];
      for (unsigned int k = 0; k < filas + 1; k++)
        g[i][k] = g[i][k] - temp * g[j][k];
    }
  return g;
}

Vector gaussJordan(Matriz &m1) {
  Matriz g = gauss(m1);
  unsigned int filas = g.RowCount();
  Vector soluciones(filas);

  for (unsigned int i = filas - 1; i > 0; i--) {
    double s = 0;
    for (unsigned int j = i + 1; j < filas; j++)
      s += g[i][j] * soluciones[j];
    soluciones[i] = (g[i][filas] - s) / g[i][i];
  }
  return soluciones;
}

Matriz descomposicionLU(Matriz &m1, char LoU) {
  unsigned int n = m1.RowCount();
  Matriz L(n, n);
  Matriz U(n, n);

  for (unsigned int i = 0; i < n; i++) {
    for (unsigned int j = 0; j < n; j++) {
      double sum = 0;
      if (i <= j) {
        for (unsigned int k = 0; k < n; k++)
          if (k != i)
            sum += L[i][k] * U[k][j];
        U[i][j] = m1[i][j] - sum;
      } else {
        for (unsigned int k = 0; k < n; k++)
          if (k != j)
            sum += L[i][k] * U[k][j];
        L[i][j] = (m1[i][j] - sum) / U[j][j];
      }
    }
    L[i][i] = 1;
  }
  return (LoU == 'L') ? L : U;
}

Matriz descomposicionCholesky(Matriz &m1) {
  if (!m1.cuadrada)
    throw std::invalid_argument(
        "La descomposición de Cholesky requiere una matriz cuadrada");

  unsigned int n = m1.RowCount();
  Matriz cholesky(n, n);

  for (unsigned int i = 0; i < n; ++i)
    for (unsigned int j = 0; j <= i; ++j) {
      double sum = 0;
      if (j == i) {
        for (unsigned int k = 0; k < j; ++k)
          sum += cholesky[j][k] * cholesky[j][k];
        cholesky[j][j] = std::sqrt(m1[j][j] - sum);
      } else {
        for (unsigned int k = 0; k < j; ++k)
          sum += cholesky[i][k] * cholesky[j][k];
        cholesky[i][j] = (m1[i][j] - sum) / cholesky[j][j];
      }
    }
  return cholesky;
}
