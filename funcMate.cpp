//#include <math.h>

//----- Pide un exponente para poder hacer sumatorias de cuadrados, 
// cubos, etc, sin necesitar otro método-----//
/*double sumatoria(int exponente, int n) {
	double sumatoria = 0;
    for (short int i = 0; i < n; i++) {
		sumatoria = sumatoria + Math.pow(vector[indiceVariable][j], exponente);
     }
    return sumatoria;
}*/

double factorial(double n) {
	if (n==0) {
		// Aseguramos que tenga salida siempre
		return 1;                      
	}
	else {
		// Caso general
		return  n*factorial(n-1);
	 }                          
}

double potencia(double numero, unsigned short int  potencia) {
	double temporal = numero;
	if (potencia==0){
		numero = 1;
		}
	else{
		for (unsigned short int x=1; x<potencia; x++) {
			numero=numero*temporal;
		}
	}
	 return numero;
}

double binomio(double a, double b){
	double resultado;
	resultado = factorial(a)/(factorial(b)*factorial(a-b));
	return resultado;
	}

unsigned long long int convierteDoubleEnInt (double doble) {
	unsigned long long int valorEntero = static_cast<unsigned long long int>(doble);
	return valorEntero;
}
