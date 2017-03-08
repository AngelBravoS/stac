#include <iostream>
#include "matriz.hpp"

using namespace std;

int Matriz::getFila() {
    return fila;
    }

void Matriz::setFila ( int filaPublica ) {
    fila = filaPublica;
    }

int Matriz::getColumna() {
    return columna;
    }

void Matriz::setColumna ( int columnaPublica ) {
    columna = columnaPublica;
    }

int Matriz::getMatriz() {
    return **matriz;
    }

void Matriz::setMatriz ( int **matrizPublica ) {
    **matriz = **matrizPublica;
    }

int Matriz::getMatrizResultado() {
    return **matrizResultado;
    }

void Matriz::setMatrizResultado ( int **matrizResultadoPublica ) {
    **matrizResultado = **matrizResultadoPublica;
    }

int Matriz::traza() {
    int traza = 0;
    for ( int i=0; i<getFila(); i++ ) {
        traza = traza + matriz[i][i];
        }
    return traza;
    }

int Matriz::determinante() {
    int determinante = 0;
    switch ( getFila() ) {
        case 1:
            determinante = matriz[0][0];
            break;
        case 2://caso base para la recursividad
            determinante = matriz[0][0] * matriz[1][1] - matriz[0][1] * matriz[1][0];
            break;
        case 3://por sarrus
            determinante = ( matriz[0][0] * matriz[1][1] * matriz[2][2] +
                             matriz[0][2] * matriz[1][0] * matriz[2][1] +
                             matriz[0][1] * matriz[1][2] * matriz[2][0] ) -
                           ( matriz[0][2] * matriz[1][1] * matriz[2][0] +
                             matriz[0][1] * matriz[1][0] * matriz[2][2] +
                             matriz[0][0] * matriz[1][2] * matriz[2][1] );
            break;
        default :
            cout << "El determinante de la matriz A aún no está disponible. " << endl;
            break;
        }
    return determinante;
    //cout << "El determinante de la matriz A es: " << determinante << endl;
    }

void Matriz::traspuesta() {
    matrizResultado = new int*[getFila()];
    for ( int i = 0; i<getFila(); i++ )     {
        matrizResultado[i] = new int[getColumna()];
        }
    for ( int i=0; i < getFila(); i++ ) {
        for ( int j=0; j < getColumna(); j++ ) {
            matrizResultado[i][j]= matriz[j][i];
            }
        }
    setMatrizResultado ( matrizResultado );
    }

void Matriz::adjunta() {
    }

void Matriz::inversa() {
    if ( determinante() != 0 )
        cout << "La matriz tiene inversa" << endl;
    else
        cout << "La matriz no tiene inversa" << endl;
    }

void Matriz::triangular() {
    /*	for(int i=1, i<=n, i++) {
    		if(matriz[i,i]=0){
    			for(j=i+1, j<=n, j++){
    				if(matriz[j,i]!=0){
    					k=j:
    				}

    			}
    		}
    	}
    	*/
    }

void Matriz::gauss() {
    /*int n=getFila();
    matrizResultado = new int*[getFila()];
    for(int i=1;i<=n;i++){
    	if(matriz[i][i]!=0){
    		matrizResultado=1/matriz[i][i];
    		for(int j=1;j<=n+1;j++){
    			matriz[i][j]=matrizResultado*matriz[i][j];
    		}
    		for(int j=1;j<=n;j++){
    			if(j!=i){
    				matrizResultado=-matriz[j][i];
    				for(int k=1;k<=n+1;k++){
    					matriz[j][k]=matriz[j][k]+matrizResultado*matriz[i][k];
    				}
    			}
    		}
    	}
    }*/
    setMatrizResultado ( matrizResultado );
    }
