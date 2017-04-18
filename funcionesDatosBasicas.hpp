class FuncionesDatosBasicas {
		//Obtener = Get
		//Establecer = Set
	public:
		//-------- setters y getters --------
		unsigned int getFila();
		void setFila ( unsigned int filaPublica );
		unsigned int getColumna();
		void setColumna ( unsigned int columnaPublica );
		double getMatriz();
		void setMatriz ( double **matrizPublica );
		double getMatrizCopia();
		void setMatrizCopia ( double **copiaDeMatrizPublica );
		//-------- trabajo con archivos --------
		void leerArchivo();
		void guardarEnArchivo();
		//-------- funciones de la matriz de datos --------
		void recogerDatosMatriz();
		void crearMatrizVacia();
		void editarMatrizVacia();
		void mostrarMatrizOriginal ();
		void mostrarMatrizCopia ();
		void copiarMatriz();
	protected:
		unsigned int fila;
		unsigned int columna;
		double **matriz;
		double **copiaDeMatriz;
};
