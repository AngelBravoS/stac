#include "funcDatosBasicas.hpp"

class CalculosNVar : public FuncDatosBasicas {

	public:
		//========  getters & setters ======== 
		double getSumatoria();
		void setSumatoria ( double sumatoria );	
		double getVarianza();
		void setVarianza ( double varianzaPublica );	
		//========  funciones de estadística descriptiva ======== 
		double calculoSumatoria ( int indiceVariable, short unsigned int exponente );
		double calculoMediaAritmetica ( int indiceVariable );
		double calculoMediaGeometrica ( int indiceVariable ) ;
		double calculoMediaArmonica ( int indiceVariable );
		double calculoMediaCuadratica ( int indiceVariable );
		double difRespecMedia ( int indiceVariable, int exponente );
		double calculoVarianza ( int indiceVariable );
		double calculoCuasiVarianza ( int indiceVariable );
		double desviacionTipica ( int indiceVariable );
		double cuasiDesviacionTipica ( int indiceVariable );
		double momentos ( int indiceVariable, int exponente );
		double coeficientePearson ( int indiceVariable );
		double coeficienteAsimetriaFisher ( int indiceVariable );
		double curtosis ( int indiceVariable );
		double covarianza ( int indiceVariable );
		//========  funciones de tablas de contingencia ========
		
				
	protected:
		double sumatoria;
		double media;
		double varianza;
		double cuasiVarianza;
};
