/*
 * funciones.cpp
 *
 *  Created on: 13 may. 2017
 *      Author: Markel
 */

#include "funciones.h"

namespace std {

funciones::funciones() {
	// TODO Auto-generated constructor stub

}

funciones::~funciones() {
	// TODO Auto-generated destructor stub
}

int funciones::cargarRadares(BaseDeDatos *bd, FILE *radares) {
	int numeroRadares = 0;
	Radar *listaRadares;
	radares = fopen("radares.dat", "rb");
	numeroRadares = fgetc(radares);
	listaRadares = new Radar[numeroRadares];

	fread(listaRadares, sizeof(Radar), numeroRadares, radares);
	int i;
	for (i = 0; i < numeroRadares; i++) {
		bd->insertRadar(listaRadares[i].numeroRadar, listaRadares[i].velocidad,
				listaRadares[i].margen);
	}

	return numeroRadares;
}

int funciones::cargarPasos(BaseDeDatos *bd, FILE *pasos) {
	int numeroPasos = 0;
	Paso *listaPasos;
	pasos = fopen("pasos.dat", "rb");
	numeroPasos = fgetc(pasos);
	listaPasos = new Paso[numeroPasos];

	fread(listaPasos, sizeof(Paso), numeroPasos, pasos);
	int i;
	for (i = 0; i < numeroPasos; i++) {
		bd->insertPaso(listaPasos[i].numeroPaso, listaPasos[i].numeroRadar,
				listaPasos[i].matricula, listaPasos[i].velocidadCoche);
	}

	return numeroPasos;
}

int funciones::cargarUsuarios(BaseDeDatos *bd, FILE *usuarios) {
	int numeroUsuarios;
	Usuario *listaUsuarios;
	usuarios = fopen("usuarios.dat", "rb");
	numeroUsuarios = fgetc(usuarios);
	listaUsuarios = new Usuario[numeroUsuarios];

	fread(listaUsuarios, sizeof(Usuario), numeroUsuarios, usuarios);
	int i;
	for (i = 0; i < numeroUsuarios; i++) {
		//Metodo insertar usuario (Pendiente)
	}

	return numeroUsuarios;

}

void funciones::mostrarRadar(Radar &radar) {
	cout << radar.numeroRadar << endl;

}

void funciones::mostrarPaso(Paso &paso) {
	cout << "Informacion del paso: Numero " << paso.numeroPaso << " el radar : "
			<< paso.numeroRadar << " y la matricula del coche es "
			<< paso.matricula << endl;

}

int funciones::comprobarPaso(int numeroPasos, int numeroRadares,
		BaseDeDatos *bd) {

	Paso *listaPasos = bd->selectArrayPasos(numeroPasos);
	Multa **listaMultas = (Multa**) malloc(sizeof(Multa*) * numeroPasos);
	int contadorMultas = 0;

	for (int i = 0; i < numeroPasos; i++) {
		Radar *e = bd->selectRadar(listaPasos[i].numeroRadar);
//cout << e->numeroRadar << " Tiene una velocidad de: " << e->velocidad << " y un margen " << e->margen << endl;
		if (listaPasos[i].velocidadCoche > e->margen) {
			//Generamos una multa
			Multa *mult = new Multa(contadorMultas,
					listaPasos[i].velocidadCoche, e->velocidad,
					listaPasos[i].matricula, listaPasos[i].numeroRadar);

			listaMultas[contadorMultas] = mult;
			contadorMultas++;
		}

	}

//Una vez hayamos encontrado todas las multas, las cargamos en la BD

	for (int i = 0; i < contadorMultas; i++) {
		bd->insertMulta(listaMultas[i]->getnumeroMulta(),
				listaMultas[i]->getMatricula(),
				listaMultas[i]->getVelocidadCoche(),
				listaMultas[i]->getvelocidadRadar(),
				listaMultas[i]->getImporte(), listaMultas[i]->getPuntos(),
				listaMultas[i]->getnumeroRadar());

	}
	return contadorMultas++;
}

void funciones::mostrarMultas(int numeroMultas, BaseDeDatos *bd) {
	for (int i = 0; i <= numeroMultas; i++) {
		Multa *e = bd->selectMulta(i);
		e->visualizarMulta();

	}
}
}
