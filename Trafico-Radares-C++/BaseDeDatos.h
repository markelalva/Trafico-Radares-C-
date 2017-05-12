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
	char *nombreBD;
	sqlite3 *db;
	sqlite3_stmt *stmt;


public:

	int abrirBD();
	int cerrarBD();

	int crearTablaPasos();
	int crearTablaRadares();
	int borrarTablaPasos();
	int borrarTablaRadares();

	int insertPaso(int numeroPaso, int numeroRadar, char* matricula, int velocidadCoche);
	int deletePaso(int numeroPaso);

	int insertRadar(int numeroRadar, int velocidad, double margen);
	int deleteRadar(int numeroRadar);

	void selectPaso();

	void mostrarRadar(Radar &radar);
	void mostrarPaso(Paso &paso);

	BaseDeDatos(const char * nombre);
	virtual ~BaseDeDatos();
};

} /* namespace std */

#endif /* BASEDEDATOS_H_ */
