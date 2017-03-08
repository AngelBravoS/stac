//---función para el generador congruencial mixto--

unsigned int congruencialMixto (unsigned short int a, unsigned short int b, 
								unsigned int m, unsigned int Xo){
	unsigned int resultado ;
	resultado=a*Xo+b;
	if (resultado > m)
		resultado = resultado % m;
	return resultado;
}

//---función para el generador congruencial multiplicativo---

unsigned int congruencialMultip (unsigned short int a, unsigned int m, 
								unsigned int Xo){
	unsigned int resultado;
	resultado=a*Xo;
	if (resultado > m)
		resultado = resultado % m;
	return resultado;
}
