#include "funcDatosBasicas.hpp"
#include "funcMatematicasBasicas.hpp"

class Calculos1Var : public FuncDatosBasicas {
		//Obtener = Get
		//Establecer = Set
	public:
	
		//========  funciones de estadística descriptiva ======== 
		double sumatoria ( short unsigned int exponente );
		double mediaAritmetica();
		double mediaGeometrica() ;
		double mediaArmonica();
		double mediaCuadratica();
		double difRespecMedia ( int exponente );
		double varianza();
		double cuasiVarianza();
		double desviacionTipica();
		double cuasiDesviacionTipica();
		double momentos ( int exponente );
		double coeficientePearson();
		double coeficienteAsimetriaFisher();
		double curtosis();
		double norma();
						
		//========  funciones de muestreo ======== 
		
		
		
		//======== funciones de inferencia ======== 
		//-------- Contrastes en poblaciones normales --------
		//-------- de una muestra. Relativo a la media--------
		double media1MuestraSigmaConocida();
		double media1MuestraSigmaDesconocida();
		//-------- relativo a la varianza --------
		double var1MuestraMuConocida();
		double var1MuestraMuDesconocida();
		//-------- Aplicaciones del test de razón --------
		//-------- de verosimilitudes --------
		//-------- Test de Chi-cuadrado sobre Sigma^2--------
		double testChiMuConocida();
		double testChiMuDesconocida();
		//-------- Test t Student sobre mu --------
		double testStudentVarConocida();
		double testStudentVarDesconocida();
};
