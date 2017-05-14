#ifndef BASEDEDATOS_H_
#define BASEDEDATOS_H_


#include <string.h>
#include <iostream>
#include "estructuras.h"
#include "BaseDeDatos.h"
#include "sqlite3.h"
#include <stdio.h>
#include "Multa.h"



namespace std {

class BaseDeDatos {
	sqlite3 *db;
	char *nombreBD;

	sqlite3_stmt *stmt;


public:

	int abrirBD();
	int cerrarBD();

	int crearTablaPasos();
	int crearTablaRadares();
	int crearTablaMultas();

	int borrarTablaPasos();
	int borrarTablaRadares();
	int borrarTablaMultas();

	int insertPaso(int numeroPaso, int numeroRadar, char* matricula, int velocidadCoche);
	int deletePaso(int numeroPaso);

	int insertRadar(int numeroRadar, int velocidad, int margen);
	int deleteRadar(int numeroRadar);

	int insertMulta(int numeroMulta ,char *matricula, int importe,int puntos);
	int deleteMulta();

	int selectPaso(int numeroPaso);
	Paso * selectArrayPasos(int numeroPasos);
	Radar *selectRadar(int numeroRadar);
	Multa * selectMulta(int numeroMulta);



	BaseDeDatos(const char * nombre);
	virtual ~BaseDeDatos();
};

} /* namespace std */

#endif /* BASEDEDATOS_H_ */
