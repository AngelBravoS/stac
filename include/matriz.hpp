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

#pragma once

#include "funcMatematicasBasicas.hpp"
#include "vector.hpp"

class Matriz {
public:
  Matriz();
  Matriz(unsigned int filas, unsigned int cols);

  Vector &operator[](unsigned int fila);
  const Vector &operator[](unsigned int fila) const;
  double &operator()(unsigned int i, unsigned int j);

  unsigned int RowCount() const;
  unsigned int ColumnCount() const;

  bool cuadrada;

private:
  std::vector<Vector> datos;
};
