
#ifndef ESTRUCTURASH
#define ESTRUCTURASH

typedef struct{
    char nombre[15] ; //Maximo 14 caracteres
    char apellidos [25]; //Apellidos
    char direccion [30];
    char matricula[8]; //Matricula del coche, se entiende matricula espa�ola 9999XXX
    char dni [10]; //DNI
    int telefono; //Numero de telefono
    char contrasenia[15]; //M�ximo 14 caracteres
    int tipo; // 0 UsuarioNormal, 1 Administrador
}Usuario;


typedef struct{
    int numeroRadar;
    char nombreRadar[15];
    int velocidad; //Velocidad de la carretera en la que est� el radar
    double margen; //Margen al que saltar� el radar
    int activo;  // 0 Desactivado, 1 Activado


}Radar;

typedef struct{
	int numeroPaso;
	int numeroRadar;
	char matricula[8];
	int velocidadCoche;
}Paso;


#endif / ESTRUCTURASH */
