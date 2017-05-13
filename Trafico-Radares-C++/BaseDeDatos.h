#include <string.h>
#include "sqlite3.h"
#include <iostream>
#include "estructuras.h"
#include "BaseDeDatos.h"

#ifndef BASEDEDATOS_H_
#define BASEDEDATOS_H_

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

	int insertRadar(int numeroRadar, int velocidad, double margen);
	int deleteRadar(int numeroRadar);

	int insertMulta(int numeroMulta,char *matricula,int importe,int puntos);
	int deleteMulta();
	static int BDprint(void * nada, int NumDeColumnas, char ** DatoColumna, char ** NombreColumna);

	int selectPaso(int numeroPaso);
	Paso * selectArrayPasos(int numeroPasos);
	Radar *selectRadar(int numeroRadar);
	int selectMulta(int numeroMulta);



	BaseDeDatos(const char * nombre);
	virtual ~BaseDeDatos();
};

} /* namespace std */

#endif /* BASEDEDATOS_H_ */
