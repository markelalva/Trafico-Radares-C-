/*
 * funciones.h
 *
 *  Created on: 13 may. 2017
 *      Author: Markel
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_
#include "Multa.h"
#include "estructuras.h"
#include <iostream>

#include "BaseDeDatos.h"

namespace std {

class funciones {
public:
	funciones();
	void mostrarRadar(Radar &radar);
	void mostrarPaso(Paso &paso);
	void comprobarPaso (int numeroPasos, int numeroRadares, BaseDeDatos *bd);
	virtual ~funciones();
};

} /* namespace std */

#endif /* FUNCIONES_H_ */
