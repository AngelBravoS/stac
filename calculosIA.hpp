#include "funcDatosBasicas.hpp"
#include "funcMatematicasBasicas.hpp"

class CalculosIA : public FuncDatosBasicas {
		//Obtener = Get
		//Establecer = Set
	public:

		//========  Generadores Congruenciales ========
		unsigned int congruencialMixto(unsigned short int a, unsigned short int b,
		                               unsigned int m, unsigned int X0);
		unsigned int congruencialMultip(unsigned short int a, unsigned int m,
		                                unsigned int X0);

		//========  funciones XXXX ========
		void crearSecuenciaMixto(unsigned short int a, unsigned short int b,
		                         unsigned int m, unsigned int X0);
		void crearSecuenciaMultip(unsigned short int a, unsigned int m, unsigned int X0);
};
