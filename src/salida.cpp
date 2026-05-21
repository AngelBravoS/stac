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

#include "salida.hpp"
#include <iostream>

void mostrarVector(Vector &v1) {
  std::cout << "( ";
  for (unsigned int i = 0; i < v1.size(); i++)
    std::cout << v1[i] << " ";
  std::cout << ")" << '\n';
}

void mostrarMatriz(Matriz &m1) {
  std::cout << '\n';
  for (unsigned int i = 0; i < m1.RowCount(); i++) {
    std::cout << "( ";
    for (unsigned int j = 0; j < m1.ColumnCount(); j++)
      std::cout << m1[i][j] << " ";
    std::cout << ")\n";
  }
}

void imprimirResultado(const std::string &descripcion, double valor) {
  std::cout << descripcion << valor << std::endl;
}

static void mostrarModa(Vector &modas) {
  if (modas.size() == 0) {
    std::cout << "Moda = (sin moda)" << std::endl;
  } else if (modas.size() == 1) {
    std::cout << "Moda = " << modas[0] << std::endl;
  } else if (modas.size() == 2) {
    std::cout << "Bimodal = " << modas[0] << ", " << modas[1] << std::endl;
  } else {
    std::cout << "Multimodal (" << modas.size() << ") = ";
    for (unsigned int i = 0; i < modas.size(); i++) {
      if (i > 0)
        std::cout << ", ";
      std::cout << modas[i];
    }
    std::cout << std::endl;
  }
}

void mostrarMedidasTendenciaCentral(Vector &datos) {
  std::cout << "\n    Sumatorias" << std::endl;
  imprimirResultado("∑Xi = ", sumatoria(datos, 1));
  imprimirResultado("∑Xi^2 = ", sumatoria(datos, 2));

  std::cout << "\n    Medidas de tendencia central" << std::endl;
  imprimirResultado("Media aritmética = ", mediaAritmetica(datos));
  imprimirResultado("Media geométrica = ", mediaGeometrica(datos));
  imprimirResultado("Media armónica = ", mediaArmonica(datos));
  imprimirResultado("Media cuadrática = ", mediaCuadratica(datos));
  imprimirResultado("Mediana = ", mediana(datos));
  Vector modas = moda(datos);
  mostrarModa(modas);
}

void mostrarMedidasDispersion(Vector &datos) {
  std::cout << "\n    Medidas de dispersión" << std::endl;
  imprimirResultado("Varianza = ", varianza(datos));
  imprimirResultado("Varianza muestral = ", varianzaMuestral(datos));
  imprimirResultado("Desviación típica = ", desviacionTipica(datos));
  imprimirResultado("Desviación típica muestral = ", desviacionTipicaMuestral(datos));
  imprimirResultado("Coef. variación Pearson = ", coeficienteVarPearson(datos));
  imprimirResultado("Norma = ", norma(datos));

  std::cout << "\n    Medidas de forma" << std::endl;
  imprimirResultado("Coef. asimetría de Fisher = ", coeficienteAsimetriaFisher(datos));
  imprimirResultado("Coeficiente de apuntamiento de Fisher = ", coefApuntFisher(datos));
}

void mostrarMedidasRegresionCorrelacion(Matriz &varXeY, Vector &varX, Vector &varY) {
  imprimirResultado("∑XYi = ", sumatoria2Var(varXeY, 1, 1));
  imprimirResultado("Covarianza de X e Y = ", covarianza(varXeY));

  std::cout << "\n    Regresión" << '\n';
  std::cout << "Rectas de regresión:" << '\n';
  std::cout << "  Recta de Y sobre X: y = " << coeficienteRegresion(varXeY, varX) << "x"
            << " + (" << rectaRegresion(varXeY, varX) + mediaAritmetica(varY) << ")\n";
  std::cout << "  Recta de X sobre Y: x = " << coeficienteRegresion(varXeY, varY) << "y"
            << " + (" << rectaRegresion(varXeY, varY) + mediaAritmetica(varX) << ")\n";

  std::cout << "\n    Correlación" << '\n';
  imprimirResultado("Coeficiente de correlación lineal = ", coeficienteCorrelacion(varXeY));
}

void mostrarCalculos1Matriz(Matriz &matrizA) {
  int opciones;
  do {
    listadOpciones1Matriz();
    std::cin >> opciones;
    std::cout << "Matriz A\n";
    mostrarMatriz(matrizA);
    std::cout << '\n';
    switch (opciones) {
    case 1:
      imprimirResultado("Traza: ", traza(matrizA));
      break;
    case 2:
      imprimirResultado("Determinante: ", determinante(matrizA));
      break;
    case 3: {
      Matriz resultado = traspuesta(matrizA);
      std::cout << "Matriz A traspuesta\n";
      mostrarMatriz(resultado);
      break;
    }
    case 4: {
      Matriz resultado = adjunta(matrizA);
      std::cout << "Matriz A adjunta\n";
      mostrarMatriz(resultado);
      break;
    }
    case 5: {
      Matriz resultado = inversa(matrizA);
      std::cout << "Matriz A inversa\n";
      mostrarMatriz(resultado);
      break;
    }
    case 6: {
      Matriz resultado = gauss(matrizA);
      std::cout << "Matriz A Gauss\n";
      mostrarMatriz(resultado);
      break;
    }
    case 7: {
      Vector resultado = gaussJordan(matrizA);
      std::cout << "Soluciones del sistema de ecuaciones:\n";
      for (unsigned int i = 0; i < matrizA.RowCount(); i++)
        std::cout << "X" << i + 1 << " = " << resultado[i] << "\n";
      break;
    }
    case 8:
      break;
    case 9: {
      Matriz matrizL = descomposicionLU(matrizA, 'L');
      std::cout << "Matriz L\n";
      mostrarMatriz(matrizL);
      Matriz matrizU = descomposicionLU(matrizA, 'U');
      std::cout << "Matriz U\n";
      mostrarMatriz(matrizU);
      break;
    }
    case 10: {
      Matriz resultado = descomposicionCholesky(matrizA);
      mostrarMatriz(resultado);
      break;
    }
    }
    std::cout << '\n';
  } while (opciones != 0);
}

void mostrarCalculos2Matrices(Matriz &matrizA, Matriz &matrizB) {
  char opciones;
  do {
    listadOpciones2Matrices();
    std::cin >> opciones;
    std::cout << "\nMatriz A\n";
    mostrarMatriz(matrizA);
    std::cout << "\nMatriz B\n";
    mostrarMatriz(matrizB);
    std::cout << '\n';
    switch (opciones) {
    case '1': {
      Matriz resultado = matrizA + matrizB;
      mostrarMatriz(resultado);
      break;
    }
    case '2': {
      Matriz resultado = matrizA * matrizB;
      mostrarMatriz(resultado);
      break;
    }
    case '3': {
      Matriz resultado = kronecker(matrizA, matrizB);
      mostrarMatriz(resultado);
      break;
    }
    }
    std::cout << '\n';
  } while (opciones != '0');
}
