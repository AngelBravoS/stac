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

#include "vector.hpp"

Vector::Vector() {}

Vector::Vector(unsigned int size) : datos(size, 0.0) {}

Vector::Vector(const Vector &otro) : datos(otro.datos) {}

double &Vector::operator[](unsigned int index) {
  if (index >= datos.size())
    throw std::out_of_range("Índice fuera de rango");
  return datos[index];
}

const double &Vector::operator[](unsigned int index) const {
  if (index >= datos.size())
    throw std::out_of_range("Índice fuera de rango");
  return datos[index];
}

Vector &Vector::operator=(const Vector &otro) {
  if (this != &otro)
    datos = otro.datos;
  return *this;
}

unsigned int Vector::size() const { return static_cast<unsigned int>(datos.size()); }

void Vector::ordenar() { std::sort(datos.begin(), datos.end()); }

Vector Vector::operator+(const Vector &otro) const {
  if (size() != otro.size())
    throw std::invalid_argument("Tamaños incompatibles");
  Vector resultado(size());
  for (unsigned int i = 0; i < size(); ++i)
    resultado[i] = datos[i] + otro.datos[i];
  return resultado;
}

Vector Vector::operator-(const Vector &otro) const {
  if (size() != otro.size())
    throw std::invalid_argument("Tamaños incompatibles");
  Vector resultado(size());
  for (unsigned int i = 0; i < size(); ++i)
    resultado[i] = datos[i] - otro.datos[i];
  return resultado;
}

Vector Vector::operator*(double escalar) const {
  Vector resultado(size());
  for (unsigned int i = 0; i < size(); ++i)
    resultado[i] = datos[i] * escalar;
  return resultado;
}

Vector operator*(double escalar, const Vector &v) { return v * escalar; }

double productoEscalar(const Vector &v1, const Vector &v2) {
  if (v1.size() != v2.size())
    throw std::invalid_argument("Tamaños incompatibles");
  double resultado = 0.0;
  for (unsigned int i = 0; i < v1.size(); ++i)
    resultado += v1[i] * v2[i];
  return resultado;
}
