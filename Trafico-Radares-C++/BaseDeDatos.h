/*
 * BaseDeDatos.h
 *
 *  Created on: 8 may. 2017
 *      Author: Markel
 */
#include <string.h>
#include "sqlite3.h"
#include <iostream>
#include "estructuras.h"

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

	int insertMulta(char *matricula,int importe,int puntos);
	int deleteMulta();

	void selectPaso();



	BaseDeDatos(const char * nombre);
	virtual ~BaseDeDatos();
};

} /* namespace std */

#endif /* BASEDEDATOS_H_ */
