class Vector {
		//Obtener = Get
		//Establecer = Set
	public:
		//-------- setters y getters --------
		int getElementoVector();
		void setElementoVector ( int elementoVectorPublico );
		int getVector();
		void setVector ( int *vectorPublico );
		int getVectorResultado();
		void setVectorResultado ( int *vectorPublico );
		//-------- trabajo con archivos --------
		void leerArchivo();
		void guardarEnArchivo();
		//-------- funciones de matrices --------
		void recogerDatosVector();
		void crearVectorVacio();
		void editarVectorVacio();
		void mostrarVector();
		void mostrarVectorResultado();
	private:
		int elementoVector;
		int *vector;
		int *vectorResultado;
	};
