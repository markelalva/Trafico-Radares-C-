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




void funciones::mostrarRadar(Radar &radar){
	cout << radar.numeroRadar << endl;

}

void funciones::mostrarPaso(Paso &paso){
	cout <<paso.numeroPaso << endl;

}
}
