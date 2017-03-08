#include <iostream>
#include "matriz.hpp"

using namespace std;

void Matriz::leerArchivo() {
    /*
     int fila, columna;
     fila=getFila();
     columna= getColumna();
     fstream archivo;
     archivo.open ("matriz.dat", ios::in | ios::binary);
     if (archivo.is_open()) {
    	cout << "Fichero leído" << endl;
    	cout << "Número de filas: ";
    	cin >> m;
    	cout << "Número de columnas: ";
    	cin >> n;
    	int matriz[m][n];
    	int i=0, j=0;
    	while (!archivo.eof()) {
    		archivo >> matriz[i][j];
    		j++; //avanza en la fila
    		i+=j/n; //si pasó de N, le suma a 1 a i (siguiente columna)
    		j=j%n; //se asegura que esté entre 0 y N-1
    	}
    	cout << "la matriz es"<< endl;
    	for(int i=0; i<m; i++) {
    		cout << "( ";
    	  for(int j=0; j<n; j++) {
    			cout << matriz[i][j] << " ";
    	  }
    	  cout << ")";
    	  cout << endl;
    	}
    	archivo.close();
    }
     else cout << "Fichero inexistente" << endl;


     int m,n;
     fstream archivo;
     archivo.open ("matriz.dat", ios::in | ios::binary);
     if (archivo.is_open()) {
    	cout << "Fichero leído" << endl;
    	cout << "Número de filas: ";
    	cin >> m;
    	cout << "Número de columnas: ";
    	cin >> n;
    	int matriz[m][n];
    	int i=0, j=0;
    	while (!archivo.eof()) {
    		archivo >> matriz[i][j];
    		j++; //avanza en la fila
    		i+=j/n; //si pasó de N, le suma a 1 a i (siguiente columna)
    		j=j%n; //se asegura que esté entre 0 y N-1
    	}
    	cout << "la matriz es"<< endl;
    	for(int i=0; i<m; i++) {
    		cout << "( ";
    	  for(int j=0; j<n; j++) {
    			cout << matriz[i][j] << " ";
    	  }
    	  cout << ")";
    	  cout << endl;
    	}
    	archivo.close();
    }
     else cout << "Fichero inexistente" << endl;	*/
    }

void Matriz::EscribirArchivo() {
    }

void Matriz::recogerDatosMatriz() {
    int m,n;
    cout << "Número de filas: ";
    cin >> m;
    setFila ( m );
    cout << "Número de columnas: ";
    cin >> n;
    setColumna ( n );
    cout << "la nueva matriz es de " << getFila() << "x" << getColumna() << endl;
    }

void Matriz::crearMatrizVacia() {
    matriz = new int*[getFila()];
    for ( int i = 0; i<getFila(); i++ )     {
        matriz[i] = new int[getColumna()];
        }
    setMatriz ( matriz );
    }

void Matriz::editarMatrizVacia() {
    for ( int i=0; i < getFila(); i++ ) {
        for ( int j=0; j < getColumna(); j++ ) {
            cout << "Elemento " << i+1 << ","<< j+1 << ": ";
            cin >> matriz[i][j];
            }
        }
    cout << endl;
    }

void Matriz::mostrarMatriz() {
    cout << "la matriz es:"<< endl;
    cout << endl;
    for ( int i=0; i < getFila(); i++ ) {
        cout << "( ";
        for ( int j=0; j < getColumna(); j++ ) {
            cout << matriz[i][j] << " ";
            }
        cout << ")";
        cout << endl;
        }
    }

void Matriz::mostrarMatrizResultado() {
    for ( int i=0; i < getFila(); i++ ) {
        cout << "( ";
        for ( int j=0; j < getColumna(); j++ ) {
            cout << matrizResultado[i][j] << " ";
            }
        cout << ")";
        cout << endl;
        }
    }
