class FuncDatosBasicas {
		//Obtener = Get
		//Establecer = Set
	public:
		//======== setters y getters ======== 
		unsigned int getLongitudVector();
		void setLongitudVector ( unsigned int longitudVectorPublico );
		double getVector();
		void setVector ( double *vectorPublico );
		double getVectorCopia();
		void setVectorCopia ( double vectorCopiaPublico );
		//======== funciones de vectores ======== 
		void numElementosVector();
		void crearVectorVacio();
		void editarVectorVacio();
		void mostrarVector();
		void copiarvector();
		void mostrarVectorCopia();
		void destructorVector();
		void destructorVectorCopia();		
		
		//======== setters y getters ======== 
		unsigned int getFila();
		void setFila ( unsigned int filaPublica );
		unsigned int getColumna();
		void setColumna ( unsigned int columnaPublica );
		double getMatriz();
		void setMatriz ( double **matrizPublica );
		double getMatrizCopia();
		void setMatrizCopia ( double **copiaDeMatrizPublica );
		//======== trabajo con archivos ======== 
		void leerMatrizArchivo();
		void leerVectorArchivo();
		void guardarEnArchivo();
		//======== funciones de la matriz de datos ======== 
		void setDimensionMatriz();
		void crearMatrizVacia();
		void editarMatrizVacia();
		void mostrarMatrizOriginal ();
		void mostrarMatrizCopia ();
		void copiarMatriz();

	protected:
		
		unsigned int longitudVector;
		double *vector;
		double *vectorCopia;
		
		unsigned int fila;
		unsigned int columna;
		double **matriz;
		double **copiaDeMatriz;
};
