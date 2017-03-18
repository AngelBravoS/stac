class Matriz {
		//Obtener = Get
		//Establecer = Set
	public:
		//-------- setters y getters --------
		int getFila();
		void setFila ( int filaPublica );
		int getColumna();
		void setColumna ( int columnaPublica );
		int getMatriz();
		void setMatriz ( int **matrizPublica );
		int getMatrizResultado();
		void setMatrizResultado ( int **matrizPublica );
		//-------- trabajo con archivos --------
		void leerArchivo();
		void guardarEnArchivo();
		//-------- funciones de matrices --------
		void recogerDatosMatriz();
		void crearMatrizVacia();
		void editarMatrizVacia();
		void mostrarMatriz();
		void mostrarMatrizResultado();
		int traza();
		int determinante();
		void traspuesta();
		void adjunta();
		void triangular();
		void inversa();
		void gauss();
	private:
		int fila;
		int columna;
		int **matriz;
		int **matrizResultado;
	};
