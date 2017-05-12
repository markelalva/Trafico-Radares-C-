/*
 * BaseDeDatos.cpp
 *
 *  Created on: 8 may. 2017
 *      Author: Markel
 */

#include "BaseDeDatos.h"
#include "sqlite3.h"

namespace std {

BaseDeDatos::BaseDeDatos(const char *nombre) {
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




int BaseDeDatos::insertPaso(int numeroPaso, int numeroRadar, char* matricula, int velocidadCoche){
	string orden;
	char * error;

		//Cargamos en un String porque no sabemos el tamaño que vamos a encesitar
		orden = "insert into Pasos values(" + std::to_string(numeroPaso) + "," + std::to_string(numeroRadar) + ",'" + matricula + "'," + std::to_string(velocidadCoche) +");";
		char *ordenDefinitiva;
		ordenDefinitiva = new char[orden.length() +1];

		//Copiamos el valor

		strcpy(ordenDefinitiva, orden.c_str()); //Necesitamos un char, con el metodo .c_str() lo convertimos a char*

		//Ejecutamos la orden

		int result = sqlite3_exec(db,ordenDefinitiva,NULL,0, &error);

		if (result != SQLITE_OK){
				cout << "Error al insertar el paso " << error << endl;
			}else{
				cout << "Paso insertado correctamente" << endl;
			}
			return result;

}

int BaseDeDatos::deletePaso(int numeroPaso) {

}

int BaseDeDatos::insertRadar(int numeroRadar, int velocidad, double margen) {

	string orden;
	char * error;

	//Cargamos en un String porque no sabemos el tamaño que vamos a encesitar
	orden = "insert into Radares values(" + std::to(numeroRadar) + "," + std::to_string(velocidad) + "," +  std::to_string(margen)+ ");";


	char *ordenDefinitiva;
	ordenDefinitiva = new char[orden.length() +1];

	//Copiamos el valor

	strcpy(ordenDefinitiva, orden.c_str()); //Necesitamos un char, con el metodo .c_str() lo convertimos a char*

	//Ejecutamos la orden

	int result = sqlite3_exec(db,ordenDefinitiva,NULL,0, &error);

	if (result != SQLITE_OK){
			cout << "Error al insertar " << error << endl;
		}else{
			cout << "Radar insertado correctamente" << endl;
		}
		return result;

}

int BaseDeDatos::deleteRadar(int numeroRadar) {

string orden;
orden = "delete from Radares WHERE numeroRadar = " + std::to_string(numeroRadar) +";";
char *ordenDefinitiva;
	ordenDefinitiva = new char[orden.length() +1];

	//Copiamos el valor

	strcpy(ordenDefinitiva, orden.c_str()); //Necesitamos un char, con el metodo .c_str() lo convertimos a char*

	//Ejecutamos la orden


}

}

/* namespace std */
