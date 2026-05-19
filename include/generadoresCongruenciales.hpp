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
#include <iostream>
#include <vector>

class GeneradoresCongruenciales {
public:
  GeneradoresCongruenciales(unsigned int a, unsigned int b, unsigned int m, unsigned int X0);
  GeneradoresCongruenciales(unsigned int a, unsigned int b, unsigned int m);

  void crearSecuencia();
  void mostrarSecuencia() const;
  bool cumpleTeoremaKnuth() const;
  void comprobarPeriodo(char tipoGenerador);
  void mostrarComprobacionPeriodo() const;

private:
  unsigned int a;
  unsigned int b;
  unsigned int m;
  unsigned int X0 = 0;
  bool periodoMaximo = false;
  std::vector<unsigned int> secuencia;

  unsigned int generador(unsigned int semilla) const;
  bool sonCongruentesFactoresPrimoQ() const;
  bool sonCongruentesFactoresPrimoP() const;
  bool esMCongruente4() const;
  bool mEsPotenciaDe2() const;
};
