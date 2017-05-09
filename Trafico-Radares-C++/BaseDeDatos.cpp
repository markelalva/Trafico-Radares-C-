/*
 * BaseDeDatos.cpp
 *
 *  Created on: 8 may. 2017
 *      Author: Markel
 */

#include "BaseDeDatos.h"


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

int  BaseDeDatos::abrirBD(){
	int result = sqlite3_open(this->nombreBD, &db);
	if (result != SQLITE_OK) {
		cout <<"Error opening database" << endl;

	}

	return result;
}

int  BaseDeDatos::cerrarBD(){
	int result = sqlite3_close(db);
	if (result != SQLITE_OK) {
		cout<<"Error opening database"<< endl;

	}
	else{

	cout <<"Database closed" << endl;

	}
	return result;
}

int crearTabla(){
char* orden = "create table Pasos( numeroPaso integer primary key not null, numeroRadar integer not null, matricula text not null, velocidadCoche integer not null)";
char* error;

int result = sqlite3_exec(db,orden,NULL,0, &error);

if (result != SQLITE_OK){
	cout << "Error al crear la tabla :    " << error << endl;
	}else{
		cout << "Tabla creada \n";
	}
	return result;
}



 /* namespace std */
