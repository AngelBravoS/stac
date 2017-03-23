class Vector {
		//Obtener = Get
		//Establecer = Set
	public:
		//-------- setters y getters --------
		unsigned int getElementoVector();
		void setElementoVector ( unsigned int elementoVectorPublico );
		float getVector();
		void setVector ( float *vectorPublico );
		float getVectorResultado();
		void setVectorResultado ( float *vectorPublico );
		//-------- trabajo con archivos --------
		void leerArchivo();
		void guardarEnArchivo();
		//-------- funciones de vectores --------
		void recogerDatosVector();
		void crearVectorVacio();
		void editarVectorVacio();
		void mostrarVector();
		void mostrarVectorResultado();
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
	private:
		unsigned int elementoVector;
		float *vector;
		float *vectorResultado;
	};
