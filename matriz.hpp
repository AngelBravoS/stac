class Matriz {
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
		double getMatrizResultado();
		void setMatrizResultado ( double **matrizPublica );
		//-------- trabajo con archivos --------
		void leerArchivo();
		void guardarEnArchivo();
		//-------- funciones de matrices --------
		void recogerDatosMatriz();
		void crearMatrizVacia();
		void editarMatrizVacia();
		void mostrarMatriz();
		void mostrarMatrizResultado();
		double traza();
		double determinante();
		void traspuesta();
		void adjunta();
		void triangular();
		void inversa();
		void gauss();
	private:
		unsigned int fila;
		unsigned int columna;
		double **matriz;
		double **matrizResultado;
	};
