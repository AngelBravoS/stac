#include "funcDatosBasicas.hpp"

class CalculosNVar : public FuncDatosBasicas {

	public:
		//========  funciones de estadística descriptiva ======== 
		double sumatoria ( int indiceVariable, short unsigned int exponente );
		double mediaAritmetica ( int indiceVariable );
		double mediaGeometrica ( int indiceVariable ) ;
		double mediaArmonica ( int indiceVariable );
		double mediaCuadratica ( int indiceVariable );
		double difRespecMedia ( int indiceVariable, int exponente );
		double varianza ( int indiceVariable );
		double cuasiVarianza ( int indiceVariable );
		double desviacionTipica ( int indiceVariable );
		double cuasiDesviacionTipica ( int indiceVariable );
		double momentos ( int indiceVariable, int exponente );
		double coeficientePearson ( int indiceVariable );
		double coeficienteAsimetriaFisher ( int indiceVariable );
		double curtosis ( int indiceVariable );
		double covarianza ( int indiceVariable );
		//========  funciones de tablas de contingencia ========
		
		
};
