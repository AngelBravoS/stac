#include "calculosNVar.hpp"

class CalculosMatriz : public CalculosNVar {

	public:
		//-------- funciones de matrices --------
		double traza();
		double determinante();
		void traspuesta();
		void adjunta();
		void triangular();
		void inversa();
		void gauss();
		void descomposicionLU();
};
