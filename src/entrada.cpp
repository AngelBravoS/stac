#include "entrada.hpp"

void verificarArchivo() {
    std::fstream archivo;
    archivo.open("datos.dat", std::ios::in | std::ios::binary);
    if (archivo.is_open()) {
        std::cout << "Fichero leído" << '\n';
    }
    else {
        std::cout << "Fichero inexistente" << '\n';
        exit(-1);
    }
    archivo.close();
}

void leerDesdeArchivo(Matriz &m1, unsigned int columnas) {
    std::fstream archivo;
    archivo.open("datos.dat", std::ios::in | std::ios::binary);
    unsigned int n = columnas;
    unsigned int i = 0, j = 0;
    while (!archivo.eof()) {
        archivo >> m1[i][j];
        j++; //avanza en la fila
        i += j / n; //si pasó de N, le suma a 1 a i (siguiente columna)
        j = j % n; //se asegura que esté entre 0 y N-1
    }
    archivo.close();
}

void leerDesdeArchivo(Vector &v1) {
	std::fstream archivo;
	archivo.open("datos.dat", std::ios::in | std::ios::binary);
	for (unsigned int i = 0; i < v1.size(); i++) {
		archivo >> v1[i];
	}
	archivo.close();
}

void leerDatosDesdeTeclado(Vector &datos) {
	textoLeerDesdeTeclado();
	for (unsigned int i = 0; i < datos.size(); i++) {
		std::cin >> datos[i];
	}
	std::cout << std::endl;
}

unsigned int numeroFilas() {
    unsigned int filas;
    std::cout << "Número de filas: ";
    std::cin >> filas;
    return filas;
}

unsigned int numeroColumnas() {
    unsigned int columnas;
    std::cout << "Número de columnas: ";
    std::cin >> columnas;
    return columnas;
}

unsigned int preguntarNumeroElementos() {
	unsigned int col;
	std::cout << "Número de elementos: ";
	std::cin >> col;
	return col;
}

unsigned int preguntarNumeroColumnas(bool agrupados) {
	unsigned int columna;
	if (agrupados == true) {
		std::cout << "Número de datos agrupados que contiene la muestra: ";
	} else {
		std::cout << "Tamaño de la muestra: ";
	}
	std::cin >> columna;
	return columna;
}

Matriz editarMatrizVacia(Matriz &m1) {
    for (unsigned int i = 0; i < m1.RowCount(); i++) {
        for (unsigned int j = 0; j < m1.ColumnCount(); j++) {
            std::cin >> m1[i][j];
        }
    }
    std::cout << '\n';
    return m1;
}

/* Vector editarVectorVacio(Vector &v1) {
   for (unsigned int i = 0; i < m1.RowCount(); i++) {
        for (unsigned int j = 0; j < m1.ColumnCount(); j++) {
            std::cin >> m1[i][j];
        }
    }
    std::cout << '\n';
    return m1;
}*/


bool preguntarDesdeArchivoOTeclado() {
	char opcion;
	bool eligesArchivo;
	std::cout << "¿Leer desde un archivo? s/n: ";
	std::cin >> opcion;
	opcion == 's' ? eligesArchivo = true : eligesArchivo = false;
	return eligesArchivo;
}

bool preguntarSiAgrupados() {
	char respuesta;
	bool agrupados;
	std::cout << "¿Los datos están agrupados? s/n: ";
	std::cin >> respuesta;
	respuesta == 's' ? agrupados = true : agrupados = false;
	return agrupados;
}

bool preguntarSiNExiste() {
	char respuesta;
	bool N;
	std::cout << "¿Valor de N? s/n: ";
	std::cin >> respuesta;
	respuesta == 's' ? N = true : N = false;
	return N;
}

unsigned int preguntarEstimador() {
	unsigned int estimador;
	std::cout << "Selecciona el estimador:" << '\n';
	std::cout << "'1' media" << '\n';
	std::cout << "'2' total" << '\n';
	std::cout << "'3' proporción" << '\n';
	std::cout << "> ";
	std::cin >> estimador;
	return estimador;
}

unsigned int preguntarTipoDeMuestreo() {
	unsigned int respuesta;
	std::cout << "Selecciona el tipo de muestreo:" << '\n';
	std::cout << "'1' muestreo MAS" << '\n';
	std::cout << "'2' muestreo con reemplazo y probabilidades iguales" << '\n';
	std::cout << "'3' muestreo con reemplazo y probabilidades desiguales" << '\n';
	std::cout << "'4' muestreo sin reemplazo y probabilidades desiguales" << '\n';
	std::cout << "> ";
	std::cin >> respuesta;
	return respuesta;
}
/*
void desagruparDesdeTeclado() {
	double xi;
	double totalElementos = 0;

	unsigned int fi;
	unsigned int longitudVectorInicial = longitudVector;
	unsigned int x = 0;
	unsigned int n = 0;

	std::vector<unsigned int> vectorfi;
	std::vector<double> vectorxi;

	for (unsigned int i = 0; i < longitudVector; i++) {
		std::cin >> fi;
		vectorfi.push_back(fi);
	}
	std::cout << '\n';

	for (unsigned int i = 0; i < longitudVector; i++) {
		std::cin >> xi;
		vectorxi.push_back(xi);
	}
	std::cout << '\n';

	for (unsigned int i = 0; i < longitudVector; i++) {
		totalElementos += potencia(vectorfi[i], 1);
	}
	longitudVector = convierteDoubleEnInt(totalElementos);

	for (unsigned int j = 0; j < longitudVectorInicial; j++) {
		n = vectorfi[j];
		for (unsigned int i = 0; i < n; i++) {
			vector.push_back(vectorxi[x]);
		}
		x++;
	}
}

void desagruparDesdeArchivo() {
	std::fstream archivo;
	archivo.open("datos.dat", std::ios::in | std::ios::binary);

	double elem = 0;
	double totalElementos = 0;

	unsigned int longitudVectorInicial = longitudVector;
	unsigned int x = 0;
	unsigned int n = 0;

	std::vector<double> vectorxi;
	std::vector<unsigned int> vectorfi;
	std::vector<double> vectorArchivo;

	while (!archivo.eof()) {
		archivo >> elem;
		vectorArchivo.push_back(elem);
	}
	
	for (unsigned int i = 0; i < longitudVector; i++) {
		vectorfi.push_back(convierteDoubleEnInt(vectorArchivo[i]));
		vectorxi.push_back(vectorArchivo[i+longitudVector]);
	}

	for (unsigned int i = 0; i < longitudVector; i++) {
		totalElementos += potencia(vectorfi[i], 1);
	}
	longitudVector = convierteDoubleEnInt(totalElementos);

	for (unsigned int j = 0; j < longitudVectorInicial; j++) {
		n = vectorfi[j];
		for (unsigned int i = 0; i < n; i++) {
			vector.push_back(vectorxi[x]);
		}
		x++;
	}
}*/
