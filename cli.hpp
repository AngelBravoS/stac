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
        void menUnaVariable();
        void menuDosVariables();
        void menuNVariables();
        void menuMatrices();
        void menuSinDatos();
        //-------- funciones especificas de cada submenu --------
        void menuCombinatoria();
        void menuInteligenciArtificial();
        void menuDistribDiscreta();

        //void menuIntro();
        //void recogerDatosMatriz();
    private:
        char opcion;
    };


