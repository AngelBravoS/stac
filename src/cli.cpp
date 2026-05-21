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

// CLI => Command Line Interface.
#include "cli.hpp"

void CLI::eleccion(unsigned int i) { std::cin >> opciones[i]; }

void CLI::menuPrincipal() {
  do {
    listadOpcionesPrincipales();
    std::cout << "> ";
    eleccion(0);
    switch (opciones[0]) {
    case '1':
      menu1Var();
      break;
    case '2':
      menu2Var();
      break;
    case '3':
      menuNvar();
      break;
    case '4':
      menuAlgebra();
      break;
    case '5':
      menuInferencia();
      break;
    case '6':
      menuSinDatos();
      break;
    case '7':
      ayuda();
      break;
    }
  } while (opciones[0] != '0');
}

void CLI::menu1Var() {
  tamanyo = preguntarNumeroElementos();
  desdeArchivo = preguntarDesdeArchivoOTeclado();
  Vector datos(tamanyo);

  if (desdeArchivo) {
    verificarArchivo();
    leerDesdeArchivo(datos);
  } else {
    leerVectorDesdeTeclado(datos);
  }

  std::cout << "\nVector " << std::endl;
  mostrarVector(datos);

  mostrarMedidasTendenciaCentral(datos);
  mostrarMedidasDispersion(datos);
  std::cout << std::endl;
}

void CLI::menu2Var() {
  unsigned int filas, columnas;
  filas = 2;
  columnas = preguntarNumeroElementos();
  desdeArchivo = preguntarDesdeArchivoOTeclado();

  Matriz varXeY(filas, columnas);
  if (desdeArchivo == true) {
    verificarArchivo();
    leerDesdeArchivo(varXeY);
  } else {
    textoLeerDesdeTeclado();
    editarMatrizVacia(varXeY);
  }

  Vector varX = extraerVariable(varXeY, 0);
  std::cout << '\n';
  std::cout << ("Variable X") << "\n";
  mostrarVector(varX);
  std::cout << '\n';
  mostrarMedidasTendenciaCentral(varX);
  mostrarMedidasDispersion(varX);

  Vector varY = extraerVariable(varXeY, 1);
  std::cout << '\n';
  std::cout << ("Variable Y") << "\n";
  mostrarVector(varY);
  std::cout << '\n';
  mostrarMedidasTendenciaCentral(varY);
  mostrarMedidasDispersion(varY);

  std::cout << '\n';
  mostrarMedidasRegresionCorrelacion(varXeY, varX, varY);
  std::cout << '\n';
}

void CLI::menuNvar() {
  //char opciones;
  unsigned int filas, columnas;
  filas = numeroFilas();
  columnas = numeroColumnas();
  //bool desdeArchivo;
  desdeArchivo = preguntarDesdeArchivoOTeclado();
  Matriz matrizA(filas, columnas);
  if (desdeArchivo == true) {
    verificarArchivo();
    leerDesdeArchivo(matrizA);
  } else {
    std::cout << "Introduce los elementos uno a uno " << "\n"
      << "pulsa intro para escribir la fila siguiente" << "\n"
      << "\n";
    editarMatrizVacia(matrizA);
  }
  std::cout << '\n'
            << ("Matriz ") << "\n";
  mostrarMatriz(matrizA);
  std::cout << '\n';
  //std::cout << sumatoria(matrizA, 1, 1) << '\n';
  std::cout << '\n'
  << ("Cálculos de N variables ") << "\n";
}

void CLI::menuProcesos() {
  /*unsigned int n;
   *	CalculosNVar matrizA (preguntarDesdeArchivoOTeclado(), preguntarNumeroFilas(), preguntarNumeroColumnas());
   *	matrizA.leerMatriz();
   *	std::cout << '\n';
   *	std::cout << "Valor de n: ";
   *	std::cin >> n;
   *	std::cout << "Matriz A" << '\n';
   *	matrizA.mostrarMatriz();
   *	matrizA.matrizTransicionP(n);
   *	std::cout << "Matriz P" << '\n';
   *	//matrizA.mostrarMatrizResuelta();*/
}

void CLI::menuInferencia() {
  tamanyo = preguntarNumeroElementos();
  desdeArchivo = preguntarDesdeArchivoOTeclado();
  Vector vectorA(tamanyo);

  if (desdeArchivo == true) {
    verificarArchivo();
    leerDesdeArchivo(vectorA);
  } else {
    std::cout << "Introduce los elementos uno a uno" << "\n";
    std::cout << "separando con un espacio." << "\n";
    for (unsigned int i = 0; i < vectorA.size(); i++) {
      std::cin >> vectorA[i];
    }
    std::cout << '\n';
  }
  std::cout << '\n';
  std::cout << ("vector ") << "\n";
  mostrarVector(vectorA);
}

void CLI::menuSinDatos() {
  do {
    listadoMenuSinDatos();
    eleccion(0);
    switch (opciones[0]) {
      case '1' :
        menuCombinatoria();
        break;
      case '2' :
        menuSimulacion();
        break;
      case '3' :
        menuColExpo();
        break;
      case '4' :
        menuDistribDiscreta();
        break;
    }
  } while (opciones[0] != '0');
}

void CLI::menuDistribDiscreta() {
  char eleccionNivel2;
  unsigned int n, N, r, k, probabilidad;
  float p;
  do {
    std::cout << "Distribuciones a elegir:" << '\n';
    std::cout << "'1' Bernouilli." << '\n';
    std::cout << "'2' Binomial." << '\n';
    std::cout << "'3' Binomial negativa." << '\n';
    std::cout << "'4' Hipergeométrica." << '\n';
    std::cout << "'5' Poisson." << '\n';
    std::cout << "'6' Geométrica." << '\n';
    std::cout << "'0' Volver al menú principal." << '\n';
    std::cout << "> ";
    std::cin >> eleccionNivel2;
    std::cout << "======================================= " << '\n';
    std::cout << "Valor de x: ";
    std::cin >> probabilidad;
    switch(eleccionNivel2) {
      case '1': //Bernouilli
        std::cout << "Valor de p: ";
        std::cin >> p;
        std::cout << "Distribución Bernuilli X~>B("<< p << ")" << '\n';
        std::cout << "P[X=" << probabilidad << "]" << " = "<<
        bernouilli(p, probabilidad) << '\n';
        break;
      case '2': //Binomial
        std::cout << "Valor de p: ";
        std::cin >> p;
        std::cout << "Valor de n: ";
        std::cin >> n;
        std::cout << "Distribución Binomial X~>B("<< n << ","<<
        p << ")" << '\n';
        std::cout << "P[X=" << probabilidad << "]" << " = "<<
        binomial(n, p, probabilidad) << '\n';
        break;
      case '3': //Binomial negativa
        std::cout << "Valor de p: ";
        std::cin >> p;
        std::cout << "Valor de n: ";
        std::cin >> n;
        std::cout << "Distribución Binomial negativa X~>BN("<< n <<
        "," << p << ")" << '\n';
        std::cout << "P[X=" << probabilidad << "]" << " = "<<
        binomialNegativa(n, p, probabilidad) << '\n';
        break;
      case '4': //Hipergeometrica
        std::cout << "Parámetro N: ";
        std::cin >> N;
        std::cout << "Parámetro n: ";
        std::cin >> n;
        std::cout << "Parámetro r: ";
        std::cin >> r;
        std::cout << "Distribución Hipergeométrica X~>H("<< N <<
        ","<< n << "," << r << ")" << '\n';
        std::cout << "P[X=" << probabilidad << "]" << " = "<<
        hipergeometrica(N, n, r, probabilidad) << '\n';
        break;
      case '5': //Poisson
        std::cout << "Valor de lambda: ";
        std::cin >> p;
        std::cout << "Distribución Poisson X~>P("<< p << ")" << '\n';
        std::cout << "P[X=" << probabilidad << "]" << " = "<<
        poisson(p, probabilidad) << '\n';
        break;
      case '6': //Geometrica
        std::cout << "Valor de p: ";
        std::cin >> p;
        std::cout << "Distribución Geométrica X~>G(" << p << ")" << '\n';
        std::cout << "P[X=" << probabilidad << "]" << " = "<< geometrica(p, probabilidad) << '\n';
        break;
      case '7': //Multinomial
        std::cout << "Número de probabilidades asociadas: ";
        std::cin >> k;
        /*crearMultinomial(k);
         *   f or ( unsign*ed short int i = 0; i < k; i++ ) {
    }
    */
        std::cout << "Distribución Multinomial X~>M(" << p << ")" << '\n';
        std::cout << "P[X=" << probabilidad << "]" << " = "<< geometrica(p, probabilidad) << '\n';
        break;
        break;
    }
    std::cout << "============================================= " << '\n';
    std::cout << '\n';
  } while(eleccionNivel2 != '0');
}

void CLI::menuCombinatoria() {
  unsigned short int m, n, cantidadn;
  double resultado;
  char eleccionNivel2, eleccionNivel3;
  std::cout << "¿(p)ermutaciones, (v)ariaciones o (c)ombinaciones?." << '\n';
  std::cout << "> ";
  std::cin >> eleccionNivel2;
  std::cout << "¿Repetición? (s)í/(n)o" << '\n';
  std::cout << "> ";
  std::cin >> eleccionNivel3;
  switch(eleccionNivel2) {
    case 'p':
      switch(eleccionNivel3) {
        case 's':
          std::cout << "Permutaciones con repetición " << '\n';
          std::cout << "============================ " << '\n';
          std::cout << "" << '\n';
          std::cout << "Valor de m -> ";
          std::cin >> m;
          std::cout << "Cantidad de n diferentes -> ";
          std::cin >> cantidadn;
          resultado = 1;
          for(unsigned short int i = 0; i < cantidadn; i++) {
            std::cout << "Introducir valor de n" << (i + 1) << " " << "=> ";
            std::cin >> n;
            resultado = resultado * factorial(n);
          }
          resultado = int (convierteDoubleEnInt((factorial(m) / resultado)));
          std::cout << "" << '\n';
          std::cout << "              m! " << '\n';
          std::cout << "PRm,n = -------------- = " << resultado << '\n';
          std::cout << "         n1!*n2!..nK! " << '\n';
          std::cout << "" << '\n';
          break;

        case 'n':
          std::cout << "Permutaciones sin repetición " << '\n';
          std::cout << "============================ " << '\n';
          std::cout << "" << '\n';
          std::cout << "Valor de n -> ";
          std::cin >> n;
          resultado = int (convierteDoubleEnInt(permutaciones(n)));
          std::cout << "" << '\n';
          std::cout << "Pn = n! = " << resultado << '\n';
          break;
      }

      break;
        case 'v':
          switch(eleccionNivel3) {
            case 's':
              std::cout << "Variaciones con repetición " << '\n';
              std::cout << "============================ " << '\n';
              std::cout << "" << '\n';
              std::cout << "Valor de m -> ";
              std::cin >> m;
              std::cout << "Valor de n -> ";
              std::cin >> n;
              resultado = int (convierteDoubleEnInt(variacionesRep(m, n)));
              std::cout << "" << '\n';
              std::cout << "         n" << '\n';
              std::cout << "VRm,n = m = " <<  resultado << '\n';;
              break;

            case 'n':
              std::cout << "Variaciones sin repetición " << '\n';
              std::cout << "============================ " << '\n';
              std::cout << "" << '\n';
              std::cout << "valor de m -> ";
              std::cin >> m;
              std::cout << "valor de n -> ";
              std::cin >> n;
              resultado = int (convierteDoubleEnInt(variaciones(m, n)));
              std::cout << "" << '\n';
              std::cout << "           m! " << '\n';
              std::cout << "Vm,n = ---------- = " << resultado << '\n';
              std::cout << "         (m-n)! " << '\n';
              std::cout << "" << '\n';
              break;
          }

          break;
            case 'c':
              switch(eleccionNivel3) {
                case 's':
                  std::cout << "Combinaciones con repetición " << '\n';
                  std::cout << "============================ " << '\n';
                  std::cout << "" << '\n';
                  std::cout << "Valor de m -> ";
                  std::cin >> m;
                  std::cout << "Valor de n -> ";
                  std::cin >> n;
                  resultado = int (convierteDoubleEnInt(combinacionesRep(m, n)));
                  std::cout << "" << '\n';
                  std::cout << "         (m + n-1) " << '\n';
                  std::cout << "CRm,n =  (       ) = " << resultado << '\n';
                  std::cout << "         (   n   ) " << '\n';
                  std::cout << "" << '\n';
                  break;

                case 'n':
                  std::cout << "Combinaciones sin repetición " << '\n';
                  std::cout << "============================ " << '\n';
                  std::cout << "" << '\n';
                  std::cout << "Valor de m -> ";
                  std::cin >> m;
                  std::cout << "Valor de n -> ";
                  std::cin >> n;
                  resultado = int (convierteDoubleEnInt(combinaciones(m, n)));
                  std::cout << "" << '\n';
                  std::cout << "        (m)        m! " << '\n';
                  std::cout << "Cm,n =  ( ) = ---------- = " <<  resultado << '\n';
                  std::cout << "        (n)     n!(m-n)! " << '\n';
                  std::cout << "" << '\n';
                  break;
              }
              break;
  }
}

void CLI::menuSimulacion() {
  unsigned int a, b, m, X0;
  do {
    listadOpcionesSimula();
    eleccion(3);
    switch(opciones[3]) {
      case '1' : {
        listadOpcionestipoGenerador();
        eleccion(4);
        std::cout << "valor de a = ";
        std::cin >> a;
        if(opciones[4] == '1') {
          std::cout << "valor de b = ";
          std::cin >> b;
        } else {
          b = 0;
        }
        std::cout << "valor de m = ";
        std::cin >> m;
        std::cout << "valor de Xo = ";
        std::cin >> X0;
        if((m <= a || m <= b) && opciones[4] == '1') {
          std::cout << "secuencia no válida (m > a,b)." << "\n";
          exit(-1);
        } else {
          std::cout << "La secuencia es:" << '\n';
          GeneradoresCongruenciales gc(a, b, m, X0);
          gc.crearSecuencia();
          gc.mostrarSecuencia();
        }
        break;
      }
      case '2' : {
        listadOpcionestipoGenerador();
        eleccion(4);
        std::cout << "valor de a = ";
        std::cin >> a;
        if(opciones[4] == '1') {
          std::cout << "valor de b = ";
          std::cin >> b;
        } else {
          b = 0;
        }
        std::cout << "valor de m = ";
        std::cin >> m;
        if(opciones[4] == '2') {
          std::cout << "valor de Xo = ";
          std::cin >> X0;
        }
        switch(opciones[4]) {
          case 'x': {
            GeneradoresCongruenciales gc(a, b, m);
            gc.comprobarPeriodo(opciones[4]);
            gc.mostrarComprobacionPeriodo();
            break;
          }
          case 'm': {
            GeneradoresCongruenciales gc(a, b, m, X0);
            gc.comprobarPeriodo(opciones[4]);
            gc.mostrarComprobacionPeriodo();
            break;
          }
        }
        break;
      }
          case '3' : {
            std::cout << "Uniforme = ";
            std::cout << "Bernuilli = ";
            std::cout << "Binomial = ";
            break;
          }
    }
  } while(opciones[3] != '0');
}

void CLI::menuColExpo() {
  unsigned int modeloSeleccionado;
  unsigned int nUsuario, cUsuario = 0;
  double lambdaUsuario, muUsuario;
  listadOpcionesColasExponencial();
  std::cin >> modeloSeleccionado;
  if(modeloSeleccionado != 0) {
    std::cout << "Valor Lambda = ";
    std::cin >> lambdaUsuario;
    std::cout << "Valor Mu = ";
    std::cin >> muUsuario;
    switch(modeloSeleccionado) {
      case 2 :
        std::cout << "Valor k para calcular Pk -0 para ninguno- = ";
        std::cin >> nUsuario;
        break;
      case 3 :
        std::cout << "Valor n para calcular Pn -0 para ninguno- = ";
        std::cin >> nUsuario;
        std::cout << "Valor c = ";
        std::cin >> cUsuario;
        break;
      default :
        std::cout << "Valor n para calcular Pn -0 para ninguno- = ";
        std::cin >> nUsuario;
        break;
    }
    std::cout << "\n";
    resultadosColasExponencial(lambdaUsuario, muUsuario, nUsuario, cUsuario,
                               modeloSeleccionado);
  }
}

void CLI::resultadosColasExponencial(double lambdaUsuario, double
muUsuario, unsigned int nUsuario, unsigned int cUsuario, unsigned int
modeloSeleccionado) {
  std::cout << "	======== Resultados ========" << '\n';
  std::cout << "\n";
  switch(modeloSeleccionado) {
    case 1 : {
      MMI colaMMI(lambdaUsuario, muUsuario, nUsuario);
      std::cout << "Lq (Número medio de clientes en cola) = " << colaMMI.lq() << "\n";
      std::cout << "L'q (Número medio de clientes en cola cuando no está vacía) = " << colaMMI.lq2() << "\n";
      std::cout << "L (Número medio de clientes en el sistema) = " << colaMMI.l() << "\n";
      std::cout << "Wq (Tiempo medio de espera en cola) = " << colaMMI.wq() << "\n";
      //std::cout << "W'q = Tiempo medio de espera en cola cuando no está vacía" << cola.wq2() << "\n";
      std::cout << "W (Tiempo medio de espera en el sistema) = " << colaMMI.w() << "\n";
      std::cout << "P0 (Tiempo del sistema ocioso) = " << colaMMI.p0() << "\n";
      if(nUsuario != 0) {
        std::cout << "Valor P" << nUsuario << " = " << colaMMI.pn() << "\n";
      }
      break;
    }
    case 2 : {
      MMIK colaMMIK(lambdaUsuario, muUsuario, nUsuario);
      std::cout << "Valor P0" << " = " << colaMMIK.p0() << "\n";
      std::cout << "Valor P" << nUsuario << " = " << colaMMIK.pn() << "\n";
      std::cout << "Lq (Número medio de clientes en cola) = " << colaMMIK.lq() << "\n";
      std::cout << "L (Número medio de clientes en el sistema) = " << colaMMIK.l() << "\n";
      std::cout << "Wq (Tiempo medio de espera en cola) = " << colaMMIK.wq() << "\n";
      std::cout << "W (Tiempo medio de espera en el sistema) = " << colaMMIK.w() << "\n";
      break;
    }
    case 3 : {
      MMC colaMMC(lambdaUsuario, muUsuario, nUsuario, cUsuario);
      std::cout << "Valor P0" << " = " << colaMMC.p0() << "\n";
      std::cout << "Valor P" << nUsuario << " = " << colaMMC.pn() << "\n";
      std::cout << "Lq (Número medio de clientes en cola) = " << colaMMC.lq() << "\n";
      std::cout << "L (Número medio de clientes en el sistema) = " << colaMMC.l() << "\n";
      std::cout << "Wq (Tiempo medio de espera en cola) = " << colaMMC.wq() << "\n";
      std::cout << "W (Tiempo medio de espera en el sistema) = " << colaMMC.w() << "\n";
      break;
    }
    case 4 : {
      MMINFINIT colaMMINFINIT(lambdaUsuario, muUsuario, nUsuario);
      std::cout << "Valor P0" << " = " << colaMMINFINIT.p0() << "\n";
      std::cout << "Valor Pn" << " = " << colaMMINFINIT.pn() << "\n";
      std::cout << "Lq (Número medio de clientes en cola) = " << colaMMINFINIT.lq() << "\n";
      std::cout << "L (Número medio de clientes en el sistema) = " << colaMMINFINIT.l() << "\n";
      std::cout << "Wq (Tiempo medio de espera en cola) = " << colaMMINFINIT.wq() << "\n";
      std::cout << "W (Tiempo medio de espera en el sistema) = " << colaMMINFINIT.w() << "\n";
      break;
    }
    case 5 : {
      MGI colaMGI(lambdaUsuario, muUsuario, nUsuario);
      //std::cout << "Lq (Número medio de clientes en cola) = " << colaMGI.lq() << "\n";
      std::cout << "L (Número medio de clientes en el sistema) = " << colaMGI.l() << "\n";
      //std::cout << "Wq (Tiempo medio de espera en cola) = " << colaMGI.wq() << "\n";
      //std::cout << "W (Tiempo medio de espera en el sistema) = " << colaMGI.w() << "\n";
      break;
    }
  }
  std::cout << "\n";
}

void CLI::menuAlgebra() {
  char elegir1o2Matrices;
  do {
    std::cout << "'1' Cálculos con una matriz" << '\n';
    std::cout << "'2' Cálculos con dos matrices" << '\n';
    std::cout << "'0' Salir al menú principal." << '\n';
    std::cout << "> ";
    std::cin >> elegir1o2Matrices;
    if (elegir1o2Matrices == '1') {
      menu1Matriz();
    } else if (elegir1o2Matrices == '2') {
      menu2Matrices();
    }
  } while (elegir1o2Matrices != '0');
}

void CLI::menu1Matriz() {
  Matriz matrizA = crearMatriz();
  std::cout << '\n';
  std::cout << ("Matriz A") << "\n";
  mostrarMatriz(matrizA);
  std::cout << '\n';
  mostrarCalculos1Matriz(matrizA);
}

void CLI::menu2Matrices() {
  std::cout << "Matriz A" << "\n";
  Matriz matrizA = crearMatriz();

  std::cout << "Matriz B" << "\n";
  Matriz matrizB = crearMatriz();

  std::cout << '\n';
  std::cout << ("Matriz A") << "\n";
  mostrarMatriz(matrizA);
  std::cout << '\n';

  std::cout << '\n';
  std::cout << ("Matriz B") << "\n";
  mostrarMatriz(matrizB);
  std::cout << '\n';

  mostrarCalculos2Matrices(matrizA, matrizB);
}
