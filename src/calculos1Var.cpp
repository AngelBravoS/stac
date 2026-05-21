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

#include "calculos1Var.hpp"

double sumatoria(Vector &variable, unsigned int exponente) {
  unsigned int n = static_cast<unsigned int>(variable.size());
  double resultado = 0;
  for (unsigned int i = 0; i < n; i++)
    resultado += potencia(variable[i], exponente);
  return resultado;
}

double mediaAritmetica(Vector &variable) {
  return sumatoria(variable, 1) / variable.size();
}

double mediaGeometrica(Vector &variable) {
  unsigned int n = variable.size();
  double resultado = 1;
  for (unsigned int i = 0; i < n; i++)
    resultado *= variable[i];
  return pow(resultado, 1.0 / n);
}

double mediaArmonica(Vector &variable) {
  unsigned int n = variable.size();
  double resultado = 0;
  for (unsigned int i = 0; i < n; i++)
    resultado += 1.0 / variable[i];
  return n / resultado;
}

double mediaCuadratica(Vector &variable) {
  return sqrt(sumatoria(variable, 2) / variable.size());
}

double difRespecMedia(Vector &variable, int exponente) {
  unsigned int n = variable.size();
  double resultado = 0;
  double media = mediaAritmetica(variable);
  for (unsigned int i = 0; i < n; i++)
    resultado += pow(variable[i] - media, exponente);
  return resultado;
}

double mediana(Vector &variable) {
  variable.ordenar();
  unsigned int n = variable.size();
  unsigned int v = n / 2;
  if (n % 2 == 0)
    return (variable[v] + variable[v - 1]) / 2.0;
  return variable[v];
}

Vector moda(Vector &variable) {
  variable.ordenar();
  unsigned int n = variable.size();

  if (n == 0)
    return Vector();

  // Primera pasada: encontrar la frecuencia máxima
  unsigned int maxFrecuencia = 1;
  unsigned int frecuenciaActual = 1;
  for (unsigned int i = 1; i < n; i++) {
    if (variable[i] == variable[i - 1]) {
      frecuenciaActual++;
      if (frecuenciaActual > maxFrecuencia)
        maxFrecuencia = frecuenciaActual;
    } else {
      frecuenciaActual = 1;
    }
  }

  // Si todos los valores son únicos no hay moda
  if (maxFrecuencia == 1)
    return Vector();

  // Segunda pasada: contar cuántos valores alcanzan la frecuencia máxima
  unsigned int numModas = 0;
  frecuenciaActual = 1;
  for (unsigned int i = 1; i < n; i++) {
    if (variable[i] == variable[i - 1]) {
      frecuenciaActual++;
    } else {
      if (frecuenciaActual == maxFrecuencia)
        numModas++;
      frecuenciaActual = 1;
    }
  }
  if (frecuenciaActual == maxFrecuencia)
    numModas++;

  // Tercera pasada: recoger los valores modales
  Vector resultado(numModas);
  unsigned int idx = 0;
  frecuenciaActual = 1;
  for (unsigned int i = 1; i < n; i++) {
    if (variable[i] == variable[i - 1]) {
      frecuenciaActual++;
    } else {
      if (frecuenciaActual == maxFrecuencia)
        resultado[idx++] = variable[i - 1];
      frecuenciaActual = 1;
    }
  }
  if (frecuenciaActual == maxFrecuencia)
    resultado[idx] = variable[n - 1];

  return resultado;
}

double varianza(Vector &variable) {
  return difRespecMedia(variable, 2) / variable.size();
}

double varianzaMuestral(Vector &variable) {
  return difRespecMedia(variable, 2) / (variable.size() - 1);
}

double desviacionTipica(Vector &variable) {
  return sqrt(varianza(variable));
}

double desviacionTipicaMuestral(Vector &variable) {
  return sqrt(varianzaMuestral(variable));
}

double momentosNoCentrados(Vector &variable, int exponente) {
  return difRespecMedia(variable, exponente) / variable.size();
}

double coeficienteVarPearson(Vector &variable) {
  return desviacionTipica(variable) / mediaAritmetica(variable);
}

double coeficienteAsimetriaPearson(Vector &variable) {
  // La fórmula (media - moda) / desv.típica solo es válida para distribuciones
  // unimodales. Si no hay moda o es multimodal se devuelve 0.
  Vector modas = moda(variable);
  if (modas.size() != 1)
    return 0;
  return (mediaAritmetica(variable) - modas[0]) / desviacionTipica(variable);
}

double coeficienteAsimetriaFisher(Vector &variable) {
  double mu = difRespecMedia(variable, 3);
  return mu / momentosNoCentrados(variable, 3);
}

double coefApuntFisher(Vector &variable) {
  double mu = momentosNoCentrados(variable, 4);
  return (mu / potencia(varianza(variable), 2)) - 3;
}

double norma(Vector &variable) {
  return sqrt(sumatoria(variable, 2));
}
