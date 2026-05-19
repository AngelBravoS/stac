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

#include "generadoresCongruenciales.hpp"

GeneradoresCongruenciales::GeneradoresCongruenciales(unsigned int parametro_a,
                                                     unsigned int parametro_b,
                                                     unsigned int parametro_m,
                                                     unsigned int parametro_X0)
    : a(parametro_a), b(parametro_b), m(parametro_m), X0(parametro_X0) {}

GeneradoresCongruenciales::GeneradoresCongruenciales(unsigned int parametro_a,
                                                     unsigned int parametro_b,
                                                     unsigned int parametro_m)
    : a(parametro_a), b(parametro_b), m(parametro_m) {}

unsigned int GeneradoresCongruenciales::generador(unsigned int semilla) const {
  unsigned int resultado = a * semilla + b;
  if (resultado > m)
    resultado = resultado % m;
  return resultado;
}

void GeneradoresCongruenciales::crearSecuencia() {
  unsigned int Xn = generador(X0);
  secuencia.push_back(Xn);
  while (X0 != Xn) {
    Xn = generador(Xn);
    secuencia.push_back(Xn);
  }
}

void GeneradoresCongruenciales::mostrarSecuencia() const {
  std::cout << "( ";
  for (unsigned int i = 0; i < secuencia.size(); i++)
    std::cout << secuencia[i] << ", ";
  std::cout << ")\n";
  std::cout << "Y su longitud es " << secuencia.size();
  if (m == secuencia.size())
    std::cout << ", por tanto es de período completo.\n";
}

bool GeneradoresCongruenciales::sonCongruentesFactoresPrimoQ() const {
  std::vector<unsigned int> primosDe_m;
  for (unsigned int i = 1; i <= m; i++)
    if (m % i == 0 && esPrimo(i))
      primosDe_m.push_back(i);
  for (unsigned int i = 0; i < primosDe_m.size(); i++)
    if (!sonCongruentes(a, 1, primosDe_m[i]))
      return false;
  return true;
}

bool GeneradoresCongruenciales::sonCongruentesFactoresPrimoP() const {
  std::vector<unsigned int> primosDe_m;
  for (unsigned int i = 1; i <= m; i++)
    if (m % i == 0 && esPrimo(i))
      primosDe_m.push_back(i);
  for (unsigned int i = 0; i < primosDe_m.size(); i++)
    if (!sonCongruentes(static_cast<unsigned int>(pow(a, primosDe_m[i])), 1, m))
      return false;
  return true;
}

bool GeneradoresCongruenciales::esMCongruente4() const {
  if (m % 4 != 0)
    return true;
  return sonCongruentes(a, 1, 4);
}

bool GeneradoresCongruenciales::mEsPotenciaDe2() const {
  return (m != 0) && ((m & (m - 1)) == 0);
}

bool GeneradoresCongruenciales::cumpleTeoremaKnuth() const {
  return sonCoprimos(b, m) && sonCongruentesFactoresPrimoQ() && esMCongruente4();
}

void GeneradoresCongruenciales::comprobarPeriodo(char tipoGenerador) {
  if (tipoGenerador == 'x') {
    periodoMaximo = cumpleTeoremaKnuth();
  } else {
    if (mEsPotenciaDe2()) {
      periodoMaximo = !esMultiplo(a, 2) && !esMultiplo(X0, 2) &&
                      (sonCongruentes(a, 3, 8) || sonCongruentes(a, 5, 8));
    } else {
      periodoMaximo = !sonCongruentesFactoresPrimoP();
    }
  }
}

void GeneradoresCongruenciales::mostrarComprobacionPeriodo() const {
  std::cout << (periodoMaximo ? "El período SI es máximo.\n" : "El período NO es máximo.\n");
}
