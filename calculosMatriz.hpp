class CalculosMatriz {
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
		//-------- funciones de matrices --------
		void recogerDatosMatriz();
		void crearMatrizVacia();
		void editarMatrizVacia();
		void mostrarMatrizOriginal ();
		void mostrarMatrizCopia ();
		void copiarMatriz();
		double traza();
		double determinante();
		void traspuesta();
		void adjunta();
		void triangular();
		void inversa();
		void gauss();
		void descomposicionLU();
	private:
		unsigned int fila;
		unsigned int columna;
		double **matriz;
		double **copiaDeMatriz;
	};
