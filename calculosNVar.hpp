class CalculosNVar {
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
		//-------- funciones de vectores --------
		void recogerDatosVector();
		void crearVectorVacio();
		void editarVectorVacio();
		void mostrarVector();
		void mostrarVectorResultado();
		void destructorVector();
		//-------- funciones matemáticas --------
		double sumatoria ( int indiceVariable, short unsigned int exponente );
		double mediaAritmetica ( int indiceVariable );
		double mediaGeometrica ( int indiceVariable ) ;
		double mediaArmonica ( int indiceVariable );
		double mediaCuadratica ( int indiceVariable );
		double difRespecMedia ( int indiceVariable, int exponente );
		double varianza ( int indiceVariable );
		double cuasiVarianza ( int indiceVariable );
		double desviacionTipica ( int indiceVariable );
		double cuasiDesviacionTipica ( int indiceVariable );
		double momentos ( int indiceVariable, int exponente );
		double coeficientePearson ( int indiceVariable );
		double coeficienteAsimetriaFisher ( int indiceVariable );
		double curtosis ( int indiceVariable );
		double covarianza ( int indiceVariable );
	protected:
		unsigned int fila;
		unsigned int columna;
		double **matriz;
		double **copiaDeMatriz;
};
