#include "calculosNVar.hpp"

class CalculosMatriz : public CalculosNVar {

	public:
		//========  funciones matriciales ======== 
		double traza();
		double determinante();
		void traspuesta();
		void adjunta();
		void triangular();
		void inversa();
		void gauss();
		void descomposicionLU();
		void multiplicarMat();
};
