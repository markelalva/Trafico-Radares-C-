/*
 * funciones.h
 *
 *  Created on: 13 may. 2017
 *      Author: Markel
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_
#include "estructuras.h"
#include <iostream>
#include "Multa.h"

namespace std {

class funciones {
public:
	funciones();
	void mostrarRadar(Radar &radar);
	void mostrarPaso(Paso &paso);
	Multa comprobarPaso (Paso &paso);
	virtual ~funciones();
};

} /* namespace std */

#endif /* FUNCIONES_H_ */
