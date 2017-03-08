#include <iostream>
#include "cli.hpp"
#include "inteligenciArtificial.hpp"

using namespace std;

void CLI::menuInteligenciArtificial() {
	unsigned short int a,b,Xo,i;
	unsigned int Xn,m;
	cout << "Escribe x para el generador congruencial mixto." << endl;
	cout << "Escribe m para el generador congruencial multiplicativo." << endl;
	cout << "> ";
	eleccion();
	cout << "valor de a -> ";
	cin >> a;
	cout << endl;
	cout << "valor de Xo -> ";
	cin >> Xo;
	cout << endl;
	cout << "valor de m -> ";
	cin >> m;
	cout << endl;
	switch (getOpcion()) {
		case 'x':
			cout << "valor de b -> ";
			cin >> b;
			cout << endl;
			if (m <= a || m <= b)
				cout << "secuencia no válida (m > a,b).";
			else {
				cout << "Para a = " << a << ", b = " << b << ", m = "
				<< m << ", y Xo = " << Xo << ", el resultado es:" << endl;
				cout << "(" << congruencialMixto(a,b,m,Xo);
				//crea el primer valor X1 para usarlo como referencia
				//mientras no coincida con el siguiente sigue calculando
				Xn = congruencialMixto(a,b,m,Xo); 
				i=1;
				while (Xo != Xn) { 			
					cout << " " << congruencialMixto(a,b,m,Xn);
					Xn = congruencialMixto(a,b,m,Xn);
					i++;
				}
				cout << ")" << endl;
				cout << "El período de la secuencia es "<< i << endl;
			}
		break;
		case 'm':
			cout << "Para a = " << a << ", m = " << m << ", y Xo = " 
			<< Xo << ", el resultado es:" << endl;
			cout << "(" << congruencialMultip(a,m,Xo);
			//crea el primer valor X1 para usarlo como referencia
			//mientras no coincida con el siguiente sigue calculando
			Xn = congruencialMultip(a,m,Xo); 
			i=1;
			while (Xo != Xn) { 			
				cout << " " << congruencialMultip(a,m,Xn);
				Xn = congruencialMultip(a,m,Xn);
				i++;
			}
			cout << ")" << endl;
			cout << "El período de la secuencia es "<< i << endl;
		break;
    }
}
