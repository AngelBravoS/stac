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

#include <algorithm>
#include <stdexcept>
#include <vector>

class Vector {
public:
  Vector();
  explicit Vector(unsigned int size);
  Vector(const Vector &otro);

  // Interfaz de contenedor
  double &operator[](unsigned int index);
  const double &operator[](unsigned int index) const;
  Vector &operator=(const Vector &otro);
  unsigned int size() const;

  // Operaciones estadísticas
  void ordenar();

  // Operadores aritméticos (útiles en regresión, ACP, etc.)
  Vector operator+(const Vector &otro) const;
  Vector operator-(const Vector &otro) const;
  Vector operator*(double escalar) const;
  friend Vector operator*(double escalar, const Vector &v);

private:
  std::vector<double> datos;
};

double productoEscalar(const Vector &v1, const Vector &v2);
