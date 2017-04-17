class Calculos1Var {
		//Obtener = Get
		//Establecer = Set
	public:
		//-------- setters y getters --------
		unsigned int getLongitudVector();
		void setLongitudVector ( unsigned int longitudVectorPublico );
		double getVector();
		void setVector ( double *vectorPublico );
		double getVectorResultado();
		void setVectorResultado ( double vectorPublico );
		//-------- trabajo con archivos --------
		void leerArchivo();
		void guardarEnArchivo();
		//-------- funciones de vectores --------
		void recogerDatosVector();
		void crearVectorVacio();
		void editarVectorVacio();
		void mostrarVector();
		void mostrarVectorResultado();
		void destructorVector();
		//-------- funciones matemáticas --------
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
		
	private:
		unsigned int longitudVector;
		//Declaramos dos punteros en la pila
		double *vector;
		double *vectorResultado;
};
