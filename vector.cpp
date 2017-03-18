#include <iostream>
#include "vector.hpp"

using namespace std;

int Vector::getElementoVector() {
	return elementoVector;
	}

void Vector::setElementoVector ( int elementoVectorPublico ) {
	elementoVector = elementoVectorPublico;
	}

int Vector::getVector() {
	return *vector;
	}

void Vector::setVector ( int *vectorPublico ) {
	*vector = *vectorPublico;
	}

int Vector::getVectorResultado() {
	return *vectorResultado;
	}

void Vector::setVectorResultado ( int *vectorResultadoPublico ) {
	*vectorResultado = *vectorResultadoPublico;
	}

