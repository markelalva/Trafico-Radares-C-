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
		bd->insertUsuario(listaUsuarios[i].dni, listaUsuarios[i].nombre,
				listaUsuarios[i].apellidos, listaUsuarios[i].direccion,
				listaUsuarios[i].matricula, listaUsuarios[i].telefono);
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
	cout <<"Se han generado " << contadorMultas << " multas." << endl;
	return contadorMultas++;
}

void funciones::mostrarMultas(int numeroMultas, BaseDeDatos *bd) {
	for (int i = 0; i < numeroMultas; i++) {
		Multa *e = bd->selectMulta(i);
		e->visualizarMulta();

	}
}

void funciones::radarMasTransitado(int numeroRadares, int numeroPasos,
		BaseDeDatos *bd) {

	int *contadorRadares = new int[numeroRadares - 1];
	//Inicializamos todos los contadores a 0
	for (int i = 0; i < numeroRadares; i++) {
		contadorRadares[i] = 0;
	}

	//Recuperamos de la BD el radar de cada paso
	for (int i = 0; i < numeroPasos; i++) {
		int radar = bd->selectRadarPaso(i);
		contadorRadares[radar]++;
	}

	//Obtenemos cual es el mayor

	int mayor = -1;
	int posicion = -1;

	for (int i = 0; i < numeroRadares; i++) {
		if (contadorRadares[i] > mayor) {
			mayor = contadorRadares[i];
			posicion = i;

		}
	}

	//Ahora mostramos cual es el radar mas transitado

	Radar *e = bd->selectRadar(posicion);

	cout << "El radar mas transitado es " << e->numeroRadar
			<< " que tiene una velocidad de " << e->velocidad << endl;

}

void funciones::radarMenosTransitado(int numeroRadares, int numeroPasos,
		BaseDeDatos *bd) {

	int *contadorRadares = new int[numeroRadares - 1];
	//Inicializamos todos los contadores a 0
	for (int i = 0; i < numeroRadares; i++) {
		contadorRadares[i] = 0;
	}

	//Recuperamos de la BD el radar de cada paso
	for (int i = 0; i < numeroPasos; i++) {
		int radar = bd->selectRadarPaso(i);
		contadorRadares[radar]++;
	}

	//Obtenemos cual es el mayor

	int menor = 100000;
	int posicion = -1;

	for (int i = 0; i < numeroRadares; i++) {
		if (contadorRadares[i] < menor) {
			menor = contadorRadares[i];
			posicion = i;

		}
	}

	//Ahora mostramos cual es el radar mas transitado

	Radar *e = bd->selectRadar(posicion);

	cout << "El radar menos transitado es " << e->numeroRadar
			<< " que tiene una velocidad de " << e->velocidad << endl;

}

void funciones::radarMasMultas(int numeroRadares, int numeroMultas,
		BaseDeDatos *bd) {
	int *contadorRadares = new int[numeroRadares - 1];
	//Inicializamos todos los contadores a 0
	for (int i = 0; i < numeroRadares; i++) {
		contadorRadares[i] = 0;
	}

	for (int i = 0; i < numeroMultas; i++) {
		int radar = bd->selectRadarMulta(i);
		contadorRadares[radar]++;
	}

	//Obtenemos cual es el mayor

	int mayor = -1;
	int posicion = -1;

	for (int i = 0; i < numeroRadares; i++) {
		if (contadorRadares[i] > mayor) {
			mayor = contadorRadares[i];
			posicion = i;

		}
	}

	//Ahora mostramos cual es el radar mas transitado

	Radar *e = bd->selectRadar(posicion);

	cout << "El radar con mas multas es " << e->numeroRadar
			<< " que tiene una velocidad de " << e->velocidad << endl;

}

void funciones::radarMenosMultas(int numeroRadares, int numeroMultas,
		BaseDeDatos *bd) {
	int *contadorRadares = new int[numeroRadares];
	//Inicializamos todos los contadores a 0
	for (int i = 0; i < numeroRadares; i++) {
		contadorRadares[i] = 0;
	}

	for (int i = 0; i < numeroMultas; i++) {
		int radar = bd->selectRadarMulta(i);
		contadorRadares[radar]++;
	}

	//Obtenemos cual es el menor

	int menor = 10000000000;
	int posicion = -1;

	for (int i = 0; i < numeroRadares; i++) {
		if (contadorRadares[i] < menor) {
			menor = contadorRadares[i];
			posicion = i;

		}
	}

	//Ahora mostramos cual es el radar menos transitado

	Radar *e = bd->selectRadar(posicion);

	cout << "El radar con menos multas es " << e->numeroRadar
			<< " que tiene una velocidad de " << e->velocidad << endl;

}

void funciones::usuarioMasMultas(int numeroUsuarios, int numeroMultas,
		BaseDeDatos *bd) {
	Usuario *listaUsuarios = bd->selectArrayUsuarios(numeroUsuarios);

	int *contadorUsuarios = new int[numeroUsuarios];
	for (int i = 0; i < numeroMultas; i++) {
		char *matricula = bd->selectUsuarioMulta(i);
		for (int j = 0; j < numeroUsuarios; j++) {
			if (strcmp(matricula, listaUsuarios[j].matricula) == 0) {
				contadorUsuarios[j]++;

			}
		}
	}

	int mayor = -1;
	int posicion = -1;

	for (int i = 0; i < numeroUsuarios; i++) {
		if (contadorUsuarios[i] > mayor) {
			mayor = contadorUsuarios[i];
			posicion = i;

		}
	}

	cout << "El usuario con mas multas es " << listaUsuarios[posicion].nombre << " con el coche matricula " << listaUsuarios[posicion].matricula <<  endl;

}

void funciones::usuarioMenosMultas(int numeroUsuarios, int numeroMultas,
		BaseDeDatos *bd) {
	Usuario *listaUsuarios = bd->selectArrayUsuarios(numeroUsuarios);

	int *contadorUsuarios = new int[numeroUsuarios];
	for (int i = 0; i < numeroMultas; i++) {
		char *matricula = bd->selectUsuarioMulta(i);
		for (int j = 0; j < numeroUsuarios; j++) {
			if (strcmp(matricula, listaUsuarios[j].matricula) == 0) {
				contadorUsuarios[j]++;

			}
		}
	}

	int menor = 10000000;
	int posicion = -1;

	for (int i = 0; i < numeroUsuarios; i++) {
		if (contadorUsuarios[i] < menor) {
			menor = contadorUsuarios[i];
			posicion = i;

		}
	}

	cout << "El usuario con menos multas es " << listaUsuarios[posicion].nombre << " con el coche matricula " << listaUsuarios[posicion].matricula <<  endl;

}
}
