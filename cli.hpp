// command-line interface (CLI)
class CLI {
        //Obtener = Get
        //Establecer = Set
    public:
        //-------- setters y getters --------
        char getOpcion();
        void setOpcion ( char opcion );
        //-------- funciones de menu --------
        void introduccion();
        void acercaDe();
        void ayuda();
        void eleccion();
        void hasElegido();
        void listadOpcionesPricipales();
        //-------- subfunciones de menu --------
        void menuPrincipal();
		  void menu1Var();
        void menu2Var();
        void menuNVar();
        void menuMatrices();
        void menuSinDatos();
        //-------- funciones especificas de cada submenu --------
        void menuInferencia();
        void menuCombinatoria();
        void menuInteligenciArtificial();
        void menuDistribDiscreta();
    private:
        char opcion;
    };



