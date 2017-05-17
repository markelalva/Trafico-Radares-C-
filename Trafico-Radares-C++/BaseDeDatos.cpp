/*
 * BaseDeDatos.cpp
 *
 *  Created on: 8 may. 2017
 *      Author: Markel
 */

#include "BaseDeDatos.h"

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
	char *query =
			"create table Radares( numeroRadar integer primary key not null, velocidadRadar integer not null, margen int not null)";
	char* error = new char[100];
	int result = sqlite3_exec(db, query, NULL, 0, &error);

	if (result != SQLITE_OK) {
		cout << "Error al crear la tabla Radares " << error << endl;
	} else {
		cout << "Tabla Radares creada" << endl;
	}
	return result;

}

int BaseDeDatos::borrarTablaRadares() {
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

int BaseDeDatos::crearTablaMultas() {
	char *query =
			"create table Multas( numeroMulta integer primary key not null, matricula integer not null, importe integer not null, puntos integer not null)";
	char* error = new char[100];
	int result = sqlite3_exec(db, query, NULL, 0, &error);

	if (result != SQLITE_OK) {
		cout << "Error al crear la tabla Multas " << error << endl;
	} else {
		cout << "Tabla Multas creada" << endl;
	}
	return result;

}

int BaseDeDatos::borrarTablaMultas() {
	char * query;
	char * error;
	query = "drop table Multas";

	int result = sqlite3_exec(db, query, NULL, 0, &error);

	if (result != SQLITE_OK) {
		cout << "Error al borrar la tabla Multas" << endl;
	} else {
		cout << "Tabla Multas borrada" << endl;
	}
	return result;
}

int BaseDeDatos::crearTablaUsuarios() {
	char *query =
			"create table Usuarios( dni text primary key not null, nombre text not null, apellidos text not null, direccion text not null, matricula text not null, telefono integer not null)";
	char* error = new char[100];
	int result = sqlite3_exec(db, query, NULL, 0, &error);

	if (result != SQLITE_OK) {
		cout << "Error al crear la tabla Usuarios " << error << endl;
	} else {
		cout << "Tabla Usuarios creada" << endl;
	}
	return result;

}

int BaseDeDatos::borrarTablaUsuarios() {
	char * query;
	char * error;
	query = "drop table Usuarios";

	int result = sqlite3_exec(db, query, NULL, 0, &error);

	if (result != SQLITE_OK) {
		cout << "Error al borrar la tabla Usuarios" << endl;
	} else {
		cout << "Tabla Usuarios borrada" << endl;
	}
	return result;

}
int BaseDeDatos::insertPaso(int numeroPaso, int numeroRadar, char* matricula,
		int velocidadCoche) {
	char *error = new char[140];
	char *query = new char[140];
	strcpy(query, "insert into Pasos values(");
	//Pasamos el numero de Paso a string

	char *numeroPasoC = new char[4];
	char *coma = new char[1]; //Para la coma
	coma = ",";
	char *apostrofe = new char[1];
	apostrofe = "'";
	sprintf(numeroPasoC, "%i", numeroPaso);
	strcat(query, numeroPasoC);
	strcat(query, coma);
	char *numeroRadarC = new char[3];
	sprintf(numeroRadarC, "%i", numeroRadar);
	strcat(query, numeroRadarC);
	strcat(query, coma);
	strcat(query, apostrofe);
	strcat(query, matricula);
	strcat(query, apostrofe);
	strcat(query, coma);
	char *velocidadCocheC = new char[3];
	sprintf(velocidadCocheC, "%i", velocidadCoche);
	strcat(query, velocidadCocheC);
	char *final = new char[2];
	final = ");";
	strcat(query, final);

	int result = sqlite3_exec(db, query, NULL, 0, &error);

	if (result != SQLITE_OK) {
		cout << "Error al insertar el paso " << error << endl;
	} else {
		//cout << "Paso insertado correctamente" << endl;
	}
	return result;

}

int BaseDeDatos::deletePaso(int numeroPaso) {
	char *query = new char[140];
	char *error = new char[140];
	strcpy(query, "delete from Pasos WHERE numeroPaso = ");
	char *numeroPasoC = new char[3];
	sprintf(numeroPasoC, "%i", numeroPaso);
	strcat(query, numeroPasoC);
	char *final = new char[1];
	final = ";";
	strcat(query, final);
	//Ejecutamos la orden
	int result = sqlite3_exec(db, query, NULL, 0, &error);

	if (result != SQLITE_OK) {
		cout << "Error al borrar" << endl;
	} else {
		cout << "Borrado correcto" << endl;
	}
	return result;

}

int BaseDeDatos::insertRadar(int numeroRadar, int velocidad, int margen) {

	char * error = new char[140];
	char *query = new char[140];
	strcpy(query, "insert into Radares values(");
	char *numeroRadarC = new char[3];
	sprintf(numeroRadarC, "%i", numeroRadar);
	strcat(query, numeroRadarC);
	char *coma = new char[1]; //Para la coma
	coma = ",";
	strcat(query, coma);
	char *velocidadC = new char[3];
	sprintf(velocidadC, "%i", velocidad);
	strcat(query, velocidadC);
	strcat(query, coma);
	char *margenC = new char[3];
	sprintf(margenC, "%d", margen);
	strcat(query, margenC);
	char *final = new char[2];
	final = ");";
	strcat(query, final);

	//Ejecutamos la orden

	int result = sqlite3_exec(db, query, NULL, 0, &error);

	if (result != SQLITE_OK) {
		cout << "Error al insertar " << error << endl;
	} else {
		//cout << "Radar insertado correctamente" << endl;
	}
	return result;

}

int BaseDeDatos::insertMulta(int numeroMulta, char *matricula, int importe,
		int puntos) {
	char * error = new char[140];
	char *query = new char[140];
	strcpy(query, "insert into Multas values(");
	char *numeroMultaC = new char[3];
	sprintf(numeroMultaC, "%i", numeroMulta);
	strcat(query, numeroMultaC);
	char *coma = new char[1]; //Para la coma
	coma = ",";
	strcat(query, coma);
	char *apostrofe = new char[1];
	apostrofe = "'";
	strcat(query, apostrofe);
	strcat(query, matricula);
	strcat(query, apostrofe);
	strcat(query, coma);
	char *importeC = new char[3];
	sprintf(importeC, "%i", importe);
	strcat(query, importeC);
	strcat(query, coma);
	char *puntosC = new char[2];
	sprintf(puntosC, "%i", puntos);
	strcat(query, puntosC);
	char *final = new char[2];
	final = ");";
	strcat(query, final);

	//Ejecutamos la orden

	int result = sqlite3_exec(db, query, NULL, 0, &error);

	if (result != SQLITE_OK) {
		cout << "Error al insertar " << error << endl;
	} else {
		cout << "Multa insertada correctamente" << endl;
	}
	return result;

}
int BaseDeDatos::deleteRadar(int numeroRadar) {

	char *query = new char[140];
	char *error = new char[140];
	strcpy(query, "delete from Radares WHERE numeroRadar = ");
	char *numeroRadarC = new char[3];
	sprintf(numeroRadarC, "%i", numeroRadar);
	strcat(query, numeroRadarC);
	char *final = new char[1];
	final = ";";
	strcat(query, final);

	//Ejecutamos la orden
	int result = sqlite3_exec(db, query, NULL, 0, &error);

	if (result != SQLITE_OK) {
		cout << "Error al borrar" << endl;
	} else {
		cout << "Borrado correcto" << endl;
	}
	return result;

}

int BaseDeDatos::insertUsuario(char *dni, char *nombre, char *apellidos,
	char*direccion, char*matricula, int telefono) {
	char *query = new char[200];
}
int BaseDeDatos::selectPaso(int numeroPaso) {
	char *query = new char[140];
	char *error = new char[140];

	strcpy(query, "SELECT * FROM Pasos where numeroPaso =");
	char *numeroPasoC = new char[4];
	sprintf(numeroPasoC, "%i", numeroPaso);
	strcat(query, numeroPasoC);
	char *final = new char[1];
	final = ";";
	strcat(query, final);

	int result = sqlite3_prepare_v2(db, query, -1, &stmt, NULL);
	if (result != SQLITE_OK) {
		cout << "Error preparing statement (SELECT)" << endl;
		printf("%s\n", sqlite3_errmsg(db));
	}
	int valor1;
	int valor2;
	char *matricula = new char[8];
	do {
		result = sqlite3_step(stmt);
		if (result == SQLITE_ROW) {
			valor1 = sqlite3_column_int(stmt, 0);
			valor2 = sqlite3_column_int(stmt, 1);
			strcpy(matricula, (char*) sqlite3_column_text(stmt, 2));
			cout << matricula << endl;
		}
	} while (result == SQLITE_ROW);
}

Radar *BaseDeDatos::selectRadar(int numeroRadar) {
	char *query = new char[140];
	char *error = new char[140];

	strcpy(query, "SELECT * FROM Radares where numeroRadar =");
	char *numeroRadarC = new char[4];
	sprintf(numeroRadarC, "%i", numeroRadar);
	strcat(query, numeroRadarC);
	char *final = new char[1];
	final = ";";
	strcat(query, final);

	int result = sqlite3_prepare_v2(db, query, -1, &stmt, NULL);
	if (result != SQLITE_OK) {
		cout << "Error preparing statement (SELECT)" << endl;

	}

	int velocidad = 0;
	double velocidadMargen = 0;

	do {
		result = sqlite3_step(stmt);
		if (result == SQLITE_ROW) {
			velocidad = sqlite3_column_int(stmt, 1);
			velocidadMargen = sqlite3_column_int(stmt, 2);
		}
	} while (result == SQLITE_ROW);
	Radar *e = new Radar();
	e->velocidad = velocidad;
	e->numeroRadar = numeroRadar;
	e->margen = velocidadMargen;
	return e;
}

Paso* BaseDeDatos::selectArrayPasos(int numeroPasos) {
	char *query = new char[140];
	char *error = new char[140];

	strcpy(query, "SELECT * FROM Pasos;");

	int result = sqlite3_prepare_v2(db, query, -1, &stmt, NULL);
	if (result != SQLITE_OK) {
		cout << "Error preparing statement (SELECT)" << endl;
	}

	Paso *listaPasos = new Paso[numeroPasos];
	int contador = 0;
	do {
		result = sqlite3_step(stmt);
		if (result == SQLITE_ROW) {
			Paso e;
			e.numeroPaso = sqlite3_column_int(stmt, 0);
			e.numeroRadar = sqlite3_column_int(stmt, 1);
			strcpy(e.matricula, (char*) sqlite3_column_text(stmt, 2));
			e.velocidadCoche = sqlite3_column_int(stmt, 3);
			listaPasos[contador] = e;
			contador++;
		}
	} while (result == SQLITE_ROW);

	return listaPasos;
}

Multa * BaseDeDatos::selectMulta(int numeroMulta) {
	char *query = new char[140];
	//char *error = new char[140];

	strcpy(query, "SELECT * FROM Multas where numeroMulta =");
	char *numeroMultaC = new char[4];
	sprintf(numeroMultaC, "%i", numeroMulta);
	strcat(query, numeroMultaC);
	char *final = new char[1];
	final = ";";
	strcat(query, final);

	int result = sqlite3_prepare_v2(db, query, -1, &stmt, NULL);
	if (result != SQLITE_OK) {
		cout << "Error preparing statement (SELECT)" << endl;
		printf("%s\n", sqlite3_errmsg(db));
	}
	Multa *e = new Multa();
	char *matricula = new char[8];
	do {
		result = sqlite3_step(stmt);
		if (result == SQLITE_ROW) {
			e->setnumeroMulta(sqlite3_column_int(stmt, 0));
			e->setImporte(sqlite3_column_int(stmt, 2));
			e->setPuntos(sqlite3_column_int(stmt, 3));
			e->setMatricula((char*) sqlite3_column_text(stmt, 1));
		}
	} while (result == SQLITE_ROW);
	return e;
}

int BaseDeDatos::selectImporteTotal() {
	char *query = new char[140];
	strcpy(query, "SELECT SUM(IMPORTE) FROM MULTAS;");
	int result = sqlite3_prepare_v2(db, query, -1, &stmt, NULL);

	if (result != SQLITE_OK) {
		cout << "Error preparing statement (SELECT)" << endl;
	}

	int importeTotal = 0;
	do {
		result = sqlite3_step(stmt);
		if (result == SQLITE_ROW) {
			importeTotal = sqlite3_column_int(stmt, 0);
		}
	} while (result == SQLITE_ROW);

	return importeTotal;

}
int BaseDeDatos::selectPuntosTotal(){
char*query = new char[140];
strcpy(query,"SELECT SUM(PUNTOS) FROM MULTAS");

int result = sqlite3_prepare_v2(db, query, -1, &stmt, NULL);
    if (result != SQLITE_OK) {
        cout << "Error preparing statement (SELECT)" << endl;
    }
    int SumaTotal = 0;
    do {
        result = sqlite3_step(stmt);
        if (result == SQLITE_ROW) {
            SumaTotal = sqlite3_column_int(stmt, 0);
        }
    } while (result == SQLITE_ROW);
    return SumaTotal;
}
}
/* namespace std */
