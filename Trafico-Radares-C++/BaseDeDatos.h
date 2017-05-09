/*
 * BaseDeDatos.h
 *
 *  Created on: 8 may. 2017
 *      Author: Markel
 */
#include <string.h>
#include "sqlite3.h"
#include <iostream>
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

	int crearTabla();

	void insertPaso();
	void deletePaso();

	void selectPaso();

	BaseDeDatos(char * nombre);
	virtual ~BaseDeDatos();
};

} /* namespace std */

#endif /* BASEDEDATOS_H_ */