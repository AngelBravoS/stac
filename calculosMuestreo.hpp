#include "calculosNVar.hpp"
#include "funcMatematicasBasicas.hpp"

class CalculosMuestreo : public CalculosNVar {
		//Obtener = Get
		//Establecer = Set
	public:
		//CalculosMuestreo(int tipoMuestreoElegido, bool datosAgrupados, bool leeArchivo, bool reemplazo, bool igualTamanyo);
		//========  funciones de muestreo ======== 
		void leerVectorArchivo();
		bool getLeeArchivo();
		void setLeeArchivo(bool leeArchivoPublico);		
		bool getDatosEstanAgrupados();
		void setDatosEstanAgrupados ( bool datosAgrupadosPublico );
		int getTipoMuestreo();
		void setTipoMuestreo ( int tipoMuestreoPublico );		
		double getSumatoriaXi();
		void setSumatoriaXi ( double SumatoriaXiPublica );	
		double getSumatoriaXi2();
		void setSumatoriaXi2 ( double SumatoriaXi2Publica );	
		double getMedia();
		void setMedia ( double mediaPublica );

		//========  funciones de muestreo ======== 
		void calculoXi2();
		void calculoXi();
		void leerDatosArchivo();
		void desagrupar();
		//void setDimensionMatriz();
		void crearDatosMuestra();
		void mostrarDatosMuestra();
		
	protected:

		bool datosAgrupados, leeArchivo, reemplazo, igualTamanyo;
		int tipoMuestreoElegido;
		double sumatoriaXi;
		double sumatoriaXi2;
		double media;
		double varianza;
		double cuasiVarianza;
};
