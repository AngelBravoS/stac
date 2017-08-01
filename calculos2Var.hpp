#include "calculosNVar.hpp"

class Calculos2Var : public CalculosNVar {

	public:
		//-------- funciones especificas de 2 variables --------
		double sumatoria2Var ( int variableX, int variableY, int exponenteX, int exponenteY );
		double covarianza();
		double coeficienteCorrelacion();
		double distanciaEuclidea();
};
