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
	void mostrarRadar(Radar &radar);
	void mostrarPaso(Paso &paso);
	int comprobarPaso (int numeroPasos, int numeroRadares, BaseDeDatos *bd);
	void mostrarMultas(int numeroMultas, BaseDeDatos *bd);
	virtual ~funciones();

};

} /* namespace std */

#endif /* FUNCIONES_H_ */
