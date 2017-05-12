#include <stdio.h>
#include <sys/timeb.h>
#ifndef ESTRUCTURASH
#define ESTRUCTURASH

typedef struct{
    char nombre[15] ; //Maximo 14 caracteres
    char apellidos [25]; //Apellidos
    char direccion [30];
    char matricula[8]; //Matricula del coche, se entiende matricula española 9999XXX
    char dni [10]; //DNI
    int telefono; //Numero de telefono
    char contrasenia[15]; //Máximo 14 caracteres
    int tipo; // 0 UsuarioNormal, 1 Administrador
}Usuario;


typedef struct{
    int numeroRadar;
    char nombreRadar[15];
    int velocidad; //Velocidad de la carretera en la que está el radar
    double margen; //Margen al que saltará el radar
    int activo;  // 0 Desactivado, 1 Activado


}Radar;

typedef struct{
	int numeroPaso;
	int numeroRadar;
	char matricula[8];
	int velocidadCoche;
	struct timeb fecha;
}Paso;


#endif / ESTRUCTURASH */
