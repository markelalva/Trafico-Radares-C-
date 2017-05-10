/*
 * BaseDeDatos.cpp
 *
 *  Created on: 8 may. 2017
 *      Author: Markel
 */

#include "BaseDeDatos.h"
#include "sqlite3.h"

namespace std {

BaseDeDatos::BaseDeDatos(char *nombre) {
	// TODO Auto-generated constructor stub
	this->nombreBD = new char[15];
	strcpy(this->nombreBD, nombre);

}

BaseDeDatos::~BaseDeDatos() {
	// TODO Auto-generated destructor stub
	delete[] this->nombreBD;
}

int BaseDeDatos::abrirBD() {
	int result = sqlite3_open(this->nombreBD, &db);
	if (result != SQLITE_OK) {
		cout << "Error opening database" << endl;

	}

	return result;
}

int BaseDeDatos::cerrarBD() {
	int result = sqlite3_close(db);
	if (result != SQLITE_OK) {
		cout << "Error opening database" << endl;

	} else {

		cout << "Database closed" << endl;

	}
	return result;
}

int BaseDeDatos::crearTablaPasos() {
	char* query =
			"create table Pasos( numeroPaso integer primary key not null, numeroRadar integer not null, matricula text not null, velocidadCoche integer not null)";
	char* error = new char[100];
	int result = sqlite3_exec(db, query, NULL, 0, &error);

	if (result != SQLITE_OK) {
		cout << "Error al crear la tabla :    " << error << endl;
	} else {
		cout << "Tabla Pasos creada \n";
	}
	return result;

}

int BaseDeDatos::borrarTablaPasos() {
	char * query;
	char * error;
	query = "drop table Pasos";

	int result = sqlite3_exec(db, query, NULL, 0, &error);

	if (result != SQLITE_OK) {
		cout << "Error al borrar la tabla pasos" << endl;
	} else {
		cout << "Tabla pasos borrada \n";
	}
	return result;
}



int BaseDeDatos::crearTablaRadares() {
	char* query =
			"create table Radares( numeroRadar integer primary key not null, velocidadRadar integer not null)";
	char* error = new char[100];
	int result = sqlite3_exec(db, query, NULL, 0, &error);

	if (result != SQLITE_OK) {
		cout << "Error al crear la tabla Radares " << error << endl;
	} else {
		cout << "Tabla Radares creada" << endl;
	}
	return result;

}

int BaseDeDatos::borrarTablaRadares(){
	char * query;
	char * error;
	query = "drop table Radares";

	int result = sqlite3_exec(db, query, NULL, 0, &error);

	if (result != SQLITE_OK) {
		cout << "Error al borrar la tabla radares" << endl;
	} else {
		cout << "Tabla radares borrada" << endl;
	}
	return result;
}




int BaseDeDatos::insertPaso() {

}

int BaseDeDatos::deletePaso(int numeroPaso) {

}

int BaseDeDatos::insertRadar(int numeroRadar, int velocidad, double margen) {

}

int BaseDeDatos::deleteRadar(int numeroRadar) {

}

}

/* namespace std */
