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
	int crearTablaUsuarios();

	int borrarTablaPasos();
	int borrarTablaRadares();
	int borrarTablaMultas();
	int borrarTablaUsuarios();

	int insertPaso(int numeroPaso, int numeroRadar, char* matricula,
			int velocidadCoche);
	int deletePaso(int numeroPaso);

	int insertUsuario(char *dni, char *nombre, char *apellidos, char*direccion,
			char*matricula, int telefono);
	int deleteUsuario();

	int insertRadar(int numeroRadar, int velocidad, int margen);
	int deleteRadar(int numeroRadar);

	int insertMulta(int numeroMulta, char *matricula, int velocidadCoche,
			int velocidadRadar, int importe, int puntos, int numeroRadar);
	int deleteMulta();

	Paso * selectArrayPasos(int numeroPasos);
	Radar *selectRadar(int numeroRadar);
	Multa * selectMulta(int numeroMulta);
	void verMultas(char *matricula);
	Usuario *selectUsuario();
	Usuario * selectArrayUsuarios(int numeroUsuarios);
	void verMayoresMultas();
	int selectImporteTotal();
	int selectPuntosTotal();

	int selectRadarPaso(int numeroPaso);
	int selectRadarMulta(int numeroMulta);
	char* selectUsuarioMulta(int numeroMulta);

	int numeroMultas(int numeroRadar);
	int numeroPasos(int numeroRadar);

	BaseDeDatos(const char * nombre);
	virtual ~BaseDeDatos();
};

} /* namespace std */

#endif /* BASEDEDATOS_H_ */
