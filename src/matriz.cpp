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

#include "matriz.hpp"
#include <stdexcept>

Matriz::Matriz() {}

Matriz::Matriz(unsigned int filas, unsigned int cols) : cuadrada(filas == cols) {
  for (unsigned int i = 0; i < filas; ++i)
    datos.push_back(Vector(cols));
}

Vector &Matriz::operator[](unsigned int fila) {
  if (fila >= datos.size())
    throw std::out_of_range("Índice de fila fuera de rango");
  return datos[fila];
}

const Vector &Matriz::operator[](unsigned int fila) const {
  if (fila >= datos.size())
    throw std::out_of_range("Índice de fila fuera de rango");
  return datos[fila];
}

double &Matriz::operator()(unsigned int i, unsigned int j) {
  if (i >= datos.size())
    throw std::out_of_range("Índice de fila fuera de rango");
  return datos[i][j];
}

unsigned int Matriz::RowCount() const { return static_cast<unsigned int>(datos.size()); }

unsigned int Matriz::ColumnCount() const {
  if (datos.empty())
    return 0;
  return datos[0].size();
}
