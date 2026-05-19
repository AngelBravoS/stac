#include "funcMatematicasBasicas.hpp"

// Factorial usando la función gamma estándar
double factorial(unsigned int n) {
    if (n > 170) {
        //std::cerr << "Error: factorial demasiado grande\n";
        return -1;
    }
    return std::tgamma(n + 1);
}

double potencia(double numero, unsigned int  potencia) {
    double temporal = numero;
    if(potencia == 0) {
        numero = 1;
    } else {
        for(unsigned int x = 1; x < potencia; x++) {
            numero *= temporal;
        }
    }
    return numero;
}

double binomio(double n, double k) {
    if (k == 0 || k == n) return 1;
    if (n == 0) return 0;
    return factorial(n) / (factorial(k) * factorial(n - k));
}

double e(){
    return std::exp(1.0);
}

unsigned int gcd(unsigned int a , unsigned int b) {
    if(b==0) return a;
    a%=b;
    return gcd(b,a);
}

bool esMultiplo (unsigned int numero1, unsigned int numero2) {
    if (numero1 % numero2 == 0) {
        return true;
    } else {
        return false;
    }
}

bool esPrimo (unsigned int numero) {
    unsigned int i, contador = 0;
    for (i = 2; i < numero; i++) {
        if (numero % i == 0) {
            contador++;
            break;
        }
    }
    if (contador == 0) {
        return true;

    } else {
        return false;
    }
}

bool sonCoprimos (unsigned int numero1, unsigned int numero2) {
    if (gcd (numero1, numero2) == 1) {
        return true;
    } else {
        return false;
    }
}

bool sonCongruentes (unsigned int numero1, unsigned int numero2, unsigned int numero3) {
    if ( (numero1 - numero2) % numero3 == 0) {
        return true;
    } else {
        return false;
    }
}

double convierteIntEnDouble(unsigned int entero) {
    unsigned int valorDoble = static_cast<unsigned int>(entero);
    return valorDoble;
}

unsigned int convierteDoubleEnInt(double doble) {
    unsigned int valorEntero = static_cast<unsigned int>(doble);
    return valorEntero;
}

unsigned int convierteLongEnInt(long unsigned int unsignedlong) {
    unsigned int valorEntero = static_cast<unsigned int>(unsignedlong);
    return valorEntero;
}

float convierteIntEnFloat(unsigned int entero) {
    float valorFloat = static_cast<float>(entero);
    return valorFloat;
}
