/*
 * funciones.h
 *
 *  Created on: 13 may. 2017
 *      Author: Markel
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_

#include "BaseDeDatos.h"
#include "Multa.h"
#include "estructuras.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>



namespace std {

class funciones {
public:
	funciones();
	int cargarRadares(BaseDeDatos *bd, FILE *radares);
	int cargarUsuarios(BaseDeDatos *bd, FILE *usuarios);
	int cargarPasos(BaseDeDatos *bd, FILE *pasos);
	void mostrarRadar(Radar &radar);
	void mostrarPaso(Paso &paso);
	int comprobarPaso (int numeroPasos, int numeroRadares, BaseDeDatos *bd);
	void mostrarMultas(int numeroMultas, BaseDeDatos *bd);
	virtual ~funciones();
	void radarMasTransitado(int numeroRadares, int numeroPasos, BaseDeDatos *bd);
	void radarMenosTransitado(int numeroRadares, int numeroPasos, BaseDeDatos *bd);
	void radarMasMultas(int numeroRadares, int numeroMultas, BaseDeDatos *bd);
	void radarMenosMultas(int numeroRadares, int numeroMultas, BaseDeDatos *bd);

};

} /* namespace std */

#endif /* FUNCIONES_H_ */
