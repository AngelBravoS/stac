#include "calculosNVar.hpp"
#include "funcMatematicasBasicas.hpp"

class CalculosMuestreo : public CalculosNVar {
		//Obtener = Get
		//Establecer = Set
	public:
		//========  funciones de muestreo ======== 
		void leerVectorArchivo();
		bool getSiLeeArchivo();
		void setSiLeeArchivo ( bool eligesArchivoPublico );		
		bool getSiDatosEstanAgrupados();
		void setSiDatosEstanAgrupados ( bool siDatosAgrupadosPublico );
		int getTipoMuestreo();
		void setTipoMuestreo ( int tipoMuestreoPublico );		
		double getSumatoriaXi();
		void setSumatoriaXi ( double SumatoriaXiPublica );	
		double getSumatoriaXi2();
		void setSumatoriaXi2 ( double SumatoriaXi2Publica );	
		double getMedia();
		void setMedia ( double MediaPublica );

		//========  funciones de muestreo ======== 
		void calculoXi2();
		void calculoXi();
		void leerDatosArchivo();
		void desagrupar();
		//void setDimensionMatriz();
		void crearDatosMuestra();
		void mostrarDatosMuestra();
		
	protected:

		bool siDatosAgrupados, siLeeArchivo;
		int tipoMuestreoElegido;
		double sumatoriaXi;
		double sumatoriaXi2;
		double media;
		double varianza;
		double cuasiVarianza;
};
